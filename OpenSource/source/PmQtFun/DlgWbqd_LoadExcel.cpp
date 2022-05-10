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

	//��ʼ�������ʽ
	ui.tableViewContent->setAlternatingRowColors(true);
	QStringList headers;
	QString strStyle = "QHeaderView::section {background-color: rgb(170, 255, 255)}";
	ui.tableViewContent->horizontalHeader()->setStyleSheet(strStyle);
	CWbqd_LoadExcelItemModel * pContentModel = new CWbqd_LoadExcelItemModel();
	ui.tableViewContent->setModel(pContentModel);
	CWbqd_LoadExcel_Delegate * pTableDelegate = new CWbqd_LoadExcel_Delegate(ui.tableViewContent);
	ui.tableViewContent->setItemDelegate(pTableDelegate);

	//����excel
	Init();

	//�ֹ������Ϣ
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
	//��ȡexcel
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

	//д��sheet����
	QStringList arrSheeName;
	std::map<CString,NDataModelDataSet *>::const_iterator iter = m_mapSheetToContents.begin();
	for (;iter != m_mapSheetToContents.end();iter++)
	{
		PMTSTRING strSheetName = iter->first;
		arrSheeName << QStringFrom(strSheetName);
	}
	//
	ui.comboBoxSheet->addItems(arrSheeName);

	//���������comboBoxSheet-��addItems ���Զ�����On_ComboBoxSheet_CurrentIndexChanged���������������벻��д��
	//д��������
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

//�Ƿ񸲸�
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

	//���ñ�ͷ
	int col = 0;
	for(col = 0;col < nFieldCount+1;col++)
	{
		QString strColName = QString::number(col);
		pContentModel->setHorizontalHeaderItem(col, new QStandardItem(strColName));
	}
	ui.tableViewContent->setColumnWidth(0,30);

	//��������
	for( int row = 0; row < pDataset->GetRowCount(); row++ )
	{
		//ui.tableViewContent->insertRow(row);
		pContentModel->setItem(row, 0, new QStandardItem(""));
		pContentModel->item(row, 0)->setCheckable(true);			//Ĭ��ȫѡ
		for(int col = 0;col < nFieldCount;col++)
		{
			PMTSTRING strValue = pDataset->GetAsString(col,row+1);	//dataset�Ǵ�1��ʼȡ����
			QString strCellValue = QStringFrom(strValue);
			pContentModel->setItem(row, col+1, new QStandardItem(strCellValue));
			pContentModel->item(row, col+1)->setTextAlignment(Qt::AlignCenter);
		}
	}

	//���Ծ�����һ�е����ݣ�ȥ���س�
	CorrectHeadText(pContentModel);

	//���Է�����Ŀ����������Ŀ�����У�����������������Ǻϲ���һ���
	SplitColumn_XMMCAndXMTZ(pContentModel);

	//���õ�һ�е���ɫ����������������ƥ���ϵ
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

	//����еĺ����Բ�������Ӧ�Ĺ�ѡ
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

	//��Ŀ��������Ŀ����
	if (nColXMMC_XMTZ >= 0)
	{
		if(QMessageBox::Yes == QMessageBox::question(this,QObject::tr("�ⲿ�嵥����"),QObject::tr("���� ��Ŀ��������Ŀ���� Ϊͬһ�У��Ƿ����"),QMessageBox::Yes|QMessageBox::No))
		{
			QString strColName = QString::number(pContentModel->rowCount()+1);
			pContentModel->setHorizontalHeaderItem(col, new QStandardItem(strColName));

			//������Ŀ������
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
				
				//��Ŀ����
				pContentModel->item(row,nColXMMC_XMTZ)->setText(strXMMC);

				//��Ŀ����
				pItemXMTZ = new QStandardItem(strXMTZ);
				listNewColumn.append(pItemXMTZ);
			}

			//������Ŀ������
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
			QString strErrorInfo = QObject::tr("ȱ�ٱ�ͷ:");
			bool bHasXMMC = pContentModel->HasColumn(WBQD::kXMMC);	if(false == bHasXMMC) strErrorInfo += WBQD::kXMMC + ";";
			bool bHasXMBM = pContentModel->HasColumn(WBQD::kXMBM);  if(false == bHasXMBM) strErrorInfo += WBQD::kXMBM + ";";
			bool bHasJLDW = pContentModel->HasColumn(WBQD::kJLDW);  if(false == bHasJLDW) strErrorInfo += WBQD::kJLDW + ";";
			
			if(bHasXMBM && bHasXMMC && bHasJLDW)
			{
				bool bChecked = (Qt::Checked == pContentModel->item(0,0)->checkState()?true:false);
				//���¼������������
				pContentModel->CheckRows(bChecked);
			}
			else
			{
				QMessageBox::about(this,QObject::tr("�ⲿ�嵥"),strErrorInfo);
			}
		}
	}
	else
	{
		bool bChecked = (Qt::Checked == pContentModel->item(nRow,0)->checkState()?true:false);

		//���¼�Ȿ��
		bool bOk = pContentModel->CheckRow(nRow,bChecked);
		if (false == bOk)
		{
			QMessageBox::about(this,"",QObject::tr("�������ݲ��������ܱ�ѡ�У���ȡ����ѡ"));
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
	QMessageBox::about(this,QObject::tr("�ⲿ�嵥"),QObject::tr("Ӧ�óɹ�!"));
	QDialog::accept();
}