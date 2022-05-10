#include "StdAfx.h"
#include <QStandardItemModel.h>
#include "DlgWbqd_LoadExcel.h"
#include "CreateTableFromExcel.h"
#include "Wbqd_LoadExcel_Delegate.h"
#include "pmqtfun.h"

CDlgWbqd_LoadExcel::CDlgWbqd_LoadExcel(QString excelFile,QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//
	m_strExcelFile = excelFile;

	//初始化表格样式
	ui.tableViewContent->setAlternatingRowColors(true);
	QStringList headers;
	QString strStyle = "QHeaderView::section {background-color: rgb(170, 255, 255)}";
	ui.tableViewContent->horizontalHeader()->setStyleSheet(strStyle);
	CWbqd_LoadExcelItemModel * pContentModel = new CWbqd_LoadExcelItemModel();
	ui.tableViewContent->setModel(pContentModel);
	CWbqd_LoadExcel_Delegate * pTableDelegate = new CWbqd_LoadExcel_Delegate(ui.tableViewContent);
	ui.tableViewContent->setItemDelegate(pTableDelegate);

	//导入excel
	Init();

	//手工添加消息
	QObject::connect(pContentModel,SIGNAL(itemChanged(QStandardItem *)),this,SLOT(On_tableViewContent_DataChanged(QStandardItem *)));
	QObject::connect(ui.pushButtonCancel,SIGNAL(clicked()()),this,SLOT(reject()));
}

CDlgWbqd_LoadExcel::~CDlgWbqd_LoadExcel()
{
	std::map<CString,NDataModelDataSet *>::const_iterator iter = m_mapSheetToContents.begin();
	for (;iter != m_mapSheetToContents.end();iter++)
	{
		NDataModelDataSet * pDs = iter->second;
		PMDelete(pDs);
	}
	m_mapSheetToContents.clear();
}

void CDlgWbqd_LoadExcel::Init()
{
	//读取excel
	PMTSTRING str = QStringTo(m_strExcelFile);
#if PMVCCUR_VER >= PMVC2008_VER
	bool bOk = CCreateTableFromExcel::LoadFromNPOI(str.c_str(),m_mapSheetToContents);
#else
	bool bOk = CCreateTableFromExcel::LoadFromExcel(str.c_str(),m_mapSheetToContents);
	if (false == bOk)
	{
		bOk = CCreateTableFromExcel::LoadFromWps(str.c_str(),m_mapSheetToContents);
	}
#endif

	//写入sheet表名
	QStringList arrSheeName;
	std::map<CString,NDataModelDataSet *>::const_iterator iter = m_mapSheetToContents.begin();
	for (;iter != m_mapSheetToContents.end();iter++)
	{
		PMTSTRING strSheetName = iter->first;
		arrSheeName << QStringFrom(strSheetName);
	}
	//
	ui.comboBoxSheet->addItems(arrSheeName);

	//由于上面的comboBoxSheet-。addItems 会自动触发On_ComboBoxSheet_CurrentIndexChanged填充表格，所以下面代码不用写了
	//写入表格内容
	//if (m_mapSheetToContents.size() > 0 && arrSheeName.size() > 0)
	//{
	//	QString strSheet = arrSheeName[0];

	//	//
	//	m_bFillSheet = true;
	//	ui.tableViewContent->setUpdatesEnabled(false);
	//	FillSheetContent(strSheet);
	//	ui.tableViewContent->setUpdatesEnabled(true);
	//	m_bFillSheet = false;
	//}
}

const CWbqd_LoadExcelItemModel * CDlgWbqd_LoadExcel::GetModelData() const
{
	CWbqd_LoadExcelItemModel * pContentModel = (CWbqd_LoadExcelItemModel *)ui.tableViewContent->model();
	return pContentModel;
}

//是否覆盖
bool CDlgWbqd_LoadExcel::IsCover() const
{
	return ui.radioButtonCover->isChecked();
}

void CDlgWbqd_LoadExcel::On_ComboBoxSheet_CurrentIndexChanged(QString curSel)
{
	m_bFillSheet = true;
	ui.tableViewContent->setUpdatesEnabled(false);
	FillSheetContent(curSel);
	ui.tableViewContent->setUpdatesEnabled(true);
	m_bFillSheet = false;
}

void CDlgWbqd_LoadExcel::FillSheetContent(QString sheetName)
{
	CWbqd_LoadExcelItemModel * pContentModel = (CWbqd_LoadExcelItemModel *)ui.tableViewContent->model();
	pContentModel->clear();
	PMTSTRING str = QStringTo(sheetName);
	std::map<CString,NDataModelDataSet *>::const_iterator iter = m_mapSheetToContents.find(str.c_str());
	if (iter == m_mapSheetToContents.end())
		return;

	//
	NDataModelDataSet * pDataset = iter->second;
	int nFieldCount = pDataset->GetFieldCount();

	//设置表头
	int col = 0;
	for(col = 0;col < nFieldCount+1;col++)
	{
		QString strColName = QString::number(col);
		pContentModel->setHorizontalHeaderItem(col, new QStandardItem(strColName));
	}
	ui.tableViewContent->setColumnWidth(0,30);

	//设置内容
	for( int row = 0; row < pDataset->GetRowCount(); row++ )
	{
		//ui.tableViewContent->insertRow(row);
		pContentModel->setItem(row, 0, new QStandardItem(""));
		pContentModel->item(row, 0)->setCheckable(true);			//默认全选
		for(int col = 0;col < nFieldCount;col++)
		{
			PMTSTRING strValue = pDataset->GetAsString(col,row+1);	//dataset是从1开始取数的
			QString strCellValue = QStringFrom(strValue);
			pContentModel->setItem(row, col+1, new QStandardItem(strCellValue));
			pContentModel->item(row, col+1)->setTextAlignment(Qt::AlignCenter);
		}
	}

	//尝试纠正第一行的数据，去除回车
	CorrectHeadText(pContentModel);

	//尝试分离项目名称列与项目特征列，经常情况下这两列是合并在一起的
	SplitColumn_XMMCAndXMTZ(pContentModel);

	//设置第一行的颜色并建立列与列名的匹配关系
	if(pContentModel->rowCount() > 1)
	{
		for(col = 0;col < nFieldCount;col++)
		{
			QString str = pContentModel->item(0,col)->text();
			pContentModel->item(0, col+1)->setBackground(QColor(10, 153, 179));
			if(WBQD::IsWBQDField(str))
			{
				pContentModel->m_mapCol2Name[col] = str;
			}
		}
	}

	//检测行的合理性并进行相应的勾选
	pContentModel->CheckRows(true);
}

void CDlgWbqd_LoadExcel::CorrectHeadText(CWbqd_LoadExcelItemModel * pContentModel)
{
	if(0 == pContentModel->rowCount())
		return;

	//
	int nColumnCount = pContentModel->columnCount();
	int nColXMMC_XMTZ = -1;
	int col = 0;
	for (col = 0;col < nColumnCount;col++)
	{
		QStandardItem * pItem = pContentModel->item(0,col);
		if (pItem)
		{
			QString str = pItem->text();
			str.replace("\n","");
			PmQtFun::TrimEnter(str);
			if (WBQD::IsWBQDField(str))
			{
				pContentModel->item(0,col)->setText(str);
			}
		}
	}
}

void CDlgWbqd_LoadExcel::SplitColumn_XMMCAndXMTZ(CWbqd_LoadExcelItemModel * pContentModel)
{
	int nColumnCount = pContentModel->columnCount();
	int nColXMMC_XMTZ = -1;
	int col = 0;
	for (col = 0;col < nColumnCount;col++)
	{
		QStandardItem * pItem = pContentModel->item(0,col);
		if (pItem)
		{
			QString str = pItem->text();
			str.replace("\n","");
			if(WBQD::IsXMMCAndXMTZ(str))
			{
				nColXMMC_XMTZ = col;
				break;
			}
		}
	}

	//项目特征、项目名称
	if (nColXMMC_XMTZ >= 0)
	{
		if(QMessageBox::Yes == QMessageBox::question(this,QObject::tr("外部清单导入"),QObject::tr("发现 项目名称与项目特征 为同一列，是否分离"),QMessageBox::Yes|QMessageBox::No))
		{
			QString strColName = QString::number(pContentModel->rowCount()+1);
			pContentModel->setHorizontalHeaderItem(col, new QStandardItem(strColName));

			//设置项目名称列
			pContentModel->item(0,nColXMMC_XMTZ)->setText(WBQD::kXMMC);

			//
			QList<QStandardItem *> listNewColumn;
			QStandardItem * pItemXMTZ = new QStandardItem(WBQD::kXMTZ);
			listNewColumn.append(pItemXMTZ);
			for (int row = 1;row < pContentModel->rowCount();row++)
			{
				QString strValue = pContentModel->item(row,nColXMMC_XMTZ)->text();
				QString strXMMC,strXMTZ;
				CXMMC_XMTZAnalyse::SplitXMMC_XMTZ(strValue,strXMMC,strXMTZ);
				
				//项目名称
				pContentModel->item(row,nColXMMC_XMTZ)->setText(strXMMC);

				//项目特征
				pItemXMTZ = new QStandardItem(strXMTZ);
				listNewColumn.append(pItemXMTZ);
			}

			//设置项目特征列
			pContentModel->insertColumn(nColXMMC_XMTZ+1,listNewColumn);
		}
	}
}

void CDlgWbqd_LoadExcel::On_tableViewContent_DataChanged(QStandardItem * item)
{
	CWbqd_LoadExcelItemModel * pContentModel = (CWbqd_LoadExcelItemModel *)ui.tableViewContent->model();
	if(m_bFillSheet)
		return;

	//
	int nRow = item->row();
	int nColumn = item->column();
	QStringList listColumnName;
	CWbqd_LoadExcel_Delegate::GetColumnName(listColumnName);
	if(0 == item->row())
	{
		QString str = item->text();
		if(listColumnName.contains(str))
		{
			pContentModel->m_mapCol2Name[nColumn] = str;
		}

		//
		if(0 == item->column())
		{
			QString strErrorInfo = QObject::tr("缺少表头:");
			bool bHasXMMC = pContentModel->HasColumn(WBQD::kXMMC);	if(false == bHasXMMC) strErrorInfo += WBQD::kXMMC + ";";
			bool bHasXMBM = pContentModel->HasColumn(WBQD::kXMBM);  if(false == bHasXMBM) strErrorInfo += WBQD::kXMBM + ";";
			bool bHasJLDW = pContentModel->HasColumn(WBQD::kJLDW);  if(false == bHasJLDW) strErrorInfo += WBQD::kJLDW + ";";
			
			if(bHasXMBM && bHasXMMC && bHasJLDW)
			{
				bool bChecked = (Qt::Checked == pContentModel->item(0,0)->checkState()?true:false);
				//重新检测所有内容行
				pContentModel->CheckRows(bChecked);
			}
			else
			{
				QMessageBox::about(this,QObject::tr("外部清单"),strErrorInfo);
			}
		}
	}
	else
	{
		bool bChecked = (Qt::Checked == pContentModel->item(nRow,0)->checkState()?true:false);

		//重新检测本行
		bool bOk = pContentModel->CheckRow(nRow,bChecked);
		if (false == bOk)
		{
			QMessageBox::about(this,"",QObject::tr("本行数据不合理，不能被选中，已取消勾选"));
		}
	}
}

void CDlgWbqd_LoadExcel::accept()
{
	QDialog::accept();
}

void CDlgWbqd_LoadExcel::reject()
{
	QDialog::reject();
}

void CDlgWbqd_LoadExcel::On_pushButtonSave_Clicked()
{
	QMessageBox::about(this,QObject::tr("外部清单"),QObject::tr("应用成功!"));
	QDialog::accept();
}