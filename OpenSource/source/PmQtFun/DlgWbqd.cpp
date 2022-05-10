#include "StdAfx.h"
#include <QFileDialog>
#include "DlgWbqd.h"
#include "DlgQDDE.h"
#include "DlgWbqd_LoadExcel.h"
#include "Wbqd_LoadExcel_Delegate.h"
#include "WbqdStandardItemModel.h"
#include <QPalette>  
#include <QPixmap>
//#include "qstandarditemmodel.h"


CDlgWbqd::CDlgWbqd(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	//������������
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	WBQD::InitValue();

	//
	m_bFillingXMTZ = false;

	//��ʼ�������ʽ
	//InittreeViewWbqdStyle();
	InitTreeViewWbqdStyle();
	InitXMTZViewStyle();	

	setWindowIcon(QIcon(QObject::tr("suojin.ico")));
	ui.pushButtonRetract->setIcon(QIcon(QObject::tr("suojin.ico")));


	/*static QPixmap pixmap(QObject::tr("C:\Users\pmsbim\Desktop\timg.jpg"));  
	static int width=pixmap.width()/4;  
	static int height=pixmap.height();  
	ui.pushButtonRetract->setIcon(QIcon(pixmap.copy(width,0,width,height)));  
	ui.pushButtonExpend->setIconSize(QSize(width,height));  */

	//
	CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());
	pWbqdModel->ReadWbqdFromDb();

	//
	m_sizeOrign = size();

	//
	m_pDlgQDDE = new CDlgQDDE(pWbqdModel);
	ui.horizontalLayoutMain->addWidget(m_pDlgQDDE);
	m_pDlgQDDE->hide();
	//ui.horizontalLayoutMain->setSizeConstraint(QLayout::SetFixedSize);
	//ui.horizontalLayoutMain->setSpacing(10);
	
	//�����Ӽ�����Ϊ5��[1,2,3,4,5,��1��ʼ��]
	m_iLimit = 5;
}

CDlgWbqd::~CDlgWbqd()
{

}

void CDlgWbqd::InitTreeViewWbqdStyle()
{
	ui.treeViewWbqd->setAlternatingRowColors(true);
	QStringList headers;
	QString strStyle = "QHeaderView::section {background-color: rgb(170, 255, 255)}";
	ui.treeViewWbqd->header()->setStyleSheet(strStyle);
	ui.treeViewWbqd->header()->setDefaultAlignment(Qt::AlignCenter);
	ui.treeViewWbqd->setWordWrap(true);
	ui.treeViewWbqd->setEditTriggers(QAbstractItemView::DoubleClicked);
	CWbqdStandardItemModel * pWbqdModel = new CWbqdStandardItemModel(ui.treeViewWbqd);
	ui.treeViewWbqd->setModel(pWbqdModel);
	//CWbqd_TreeView_Delegate * pTableDelegate = new CWbqd_TreeView_Delegate(ui.treeViewWbqd);
	//ui.treeViewWbqd->setItemDelegate(pTableDelegate);

	//���ñ�ͷ
	CWbqd_LoadExcel_Delegate::GetColumnName(m_listName);
	int nFieldCount = m_listName.size();
	int col = 0;
	for(col = 0;col < nFieldCount;col++)
	{
		QString strColName = m_listName[col];
		QStandardItem * pHead = new QStandardItem(strColName);
		pWbqdModel->setHorizontalHeaderItem(col, pHead);
		if(strColName == WBQD::kJLDW)
			ui.treeViewWbqd->setColumnWidth(col,80);
		else if(strColName == WBQD::kXMBM)
			ui.treeViewWbqd->setColumnWidth(col,120);
		else if(strColName == WBQD::kXMMC
			||strColName == WBQD::kXMTZ)
			ui.treeViewWbqd->setColumnWidth(col,200);

		//
		pWbqdModel->m_mapCol2Name[col] = strColName;
	}

	//�ź����
	//QObject::connect(ui.treeViewWbqd,SIGNAL(clicked(QModelIndex)),this,SLOT(On_treeViewWbqd_Clicked(QModelIndex)));
	QObject::connect(pWbqdModel,SIGNAL(itemChanged(QStandardItem *)),this,SLOT(On_treeViewWbqd_ItemChanged(QStandardItem *)));
	QObject::connect(this,SIGNAL(signal_clicked(WBQD *)),pWbqdModel,SLOT(OnAddDE(WBQD *)));
	//QObject::connect(pWbqdModel,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(On_treeViewWbqd_DataChanged(QModelIndex,QModelIndex)));

	//����Ϊ���ɱ༭״̬
	//ui.treeViewWbqd->setEditTriggers(0);
	//���ö�ѡ
	ui.treeViewWbqd->setSelectionMode(QAbstractItemView::ExtendedSelection); 
	//ȥ������Ƶ���Ԫ����ʱ�����߿�
	ui.treeViewWbqd->setFocusPolicy(Qt::NoFocus);
}

void CDlgWbqd::InitXMTZViewStyle()
{
	ui.tableViewXMTZ->setAlternatingRowColors(true);
	QString strStyle = "QHeaderView::section {background-color: rgb(170, 255, 255)}";
	ui.tableViewXMTZ->horizontalHeader()->setStyleSheet(strStyle);
	ui.tableViewXMTZ->setWordWrap(true);
	CXMTZStandardItemModel * pXmtzModel = new CXMTZStandardItemModel();
	ui.tableViewXMTZ->setModel(pXmtzModel);

	//
	QStandardItem * pColXmtz = new QStandardItem(QObject::tr("��Ŀ����"));
	pXmtzModel->setHorizontalHeaderItem(0, pColXmtz);
	QStandardItem * pColValue = new QStandardItem(QObject::tr("��ֵ"));
	pXmtzModel->setHorizontalHeaderItem(1, pColValue);

	//
	ui.tableViewXMTZ->setColumnWidth(0,200);
	ui.tableViewXMTZ->setColumnWidth(1,400);
	ui.tableViewXMTZ->setEditTriggers(QAbstractItemView::DoubleClicked);

	//�ź����
	QObject::connect(pXmtzModel,SIGNAL(itemChanged(QStandardItem *)),this,SLOT(On_tableViewXMTZ_ItemChanged(QStandardItem *)));
	//QObject::connect(pXmtzModel,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(On_tableViewXMTZ_DataChanged(QModelIndex,QModelIndex)));
	QObject::connect(pXmtzModel,SIGNAL(pressed(QModelIndex,QModelIndex)),this,SLOT(On_tableViewXMTZ_pressed(QModelIndex)));
	QObject::connect(ui.tableViewXMTZ,SIGNAL(clicked(QModelIndex)),this,SLOT(On_tableViewXMTZ_clicked(QModelIndex)));
	QObject::connect(ui.tableViewXMTZ,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(On_tableViewXMTZ_doubleClicked(QModelIndex)));
	QObject::connect(ui.tableViewXMTZ,SIGNAL(activated(QModelIndex)),this,SLOT(On_tableViewXMTZ_activated(QModelIndex)));
	QObject::connect(ui.tableViewXMTZ,SIGNAL(entered(QModelIndex)),this,SLOT(On_tableViewXMTZ_entered(QModelIndex)));
	QObject::connect(ui.tableViewXMTZ,SIGNAL(viewportEntered()),this,SLOT(On_tableViewXMTZ_viewportEntered()));
}

void CDlgWbqd::On_pushButtonLoadExcel_Clicked()
{
	WBQD * pWbqd = new WBQD;
	emit signal_clicked(pWbqd);

	//
	QString strFilter = "Excel(*.xls *.xlsx)";
	QString strFile = QFileDialog::getOpenFileName(this,QObject::tr("��ѡ��Ҫ������ⲿ�嵥"),".",strFilter);
	if (strFile == "")
	{
		return;
	}

	//
	
	CDlgWbqd_LoadExcel dlgLoadExcel(strFile,this);
	int rc = dlgLoadExcel.exec();
	if (QDialog::Accepted == rc)
	{
		QMap<int,QString> mapCol2Name;
		const CWbqd_LoadExcelItemModel * pContentModel = dlgLoadExcel.GetModelData();
		bool bCover = dlgLoadExcel.IsCover();

		//
		FillData(pContentModel,bCover);
	}
	
}

void CDlgWbqd::On_pushButtonUseQD_Clicked()
{
	if(m_pDlgQDDE->isHidden())
	{
		QSize sizeThis = size();
		QSize sizeQDDE = m_pDlgQDDE->size();
		//		
		m_pDlgQDDE->show();
		resize(QSize(sizeThis.width()+sizeQDDE.width(),sizeThis.height()));
	}
	else
	{
		QSize sizeThis = size();
		QSize sizeQDDE = m_pDlgQDDE->size();

		//
		m_pDlgQDDE->hide();
		resize(QSize(sizeThis.width()-sizeQDDE.width(),sizeThis.height()));
	}
}

void CDlgWbqd::FillData(const CWbqd_LoadExcelItemModel * pContentModel,bool bCover)
{
	bool bFillTree = true;
	{
		CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());
		//����ʱɾ��ԭ�е�
		if (bCover)
		{
			int nRowCount = pWbqdModel->rowCount();
			pWbqdModel->removeRows(0,nRowCount);
		}

		//
		pWbqdModel->CopyDataFrom(pContentModel);

		//������״�㼶��ϵ
		if(bFillTree)
		{
			pWbqdModel->BuildTreeRelation();
		}

		//׷��ʱ�ϲ�ͬһ����Ŀ����ڵ�---����ԭ��
		if (false == bCover)
		{
			pWbqdModel->MergeSameXM();
		}
	}
}

void CDlgWbqd::On_pushButtonAdd_Clicked()
{
	CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());
	pWbqdModel->InsertAfterSelected(ui.treeViewWbqd);
}

void CDlgWbqd::On_pushButtonDelete_Clicked()
{
	CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());
	pWbqdModel->DeleteRowsSelected(ui.treeViewWbqd);
}

void CDlgWbqd::On_treeViewWbqd_Clicked(const QModelIndex & index)
{
	CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());
	int nColumnXMTZ = pWbqdModel->GetColumn(WBQD::kXMTZ);
	if (-1 == nColumnXMTZ)
	{
		return;
	}

	//
	
	//��ȡ��Ŀ������
	if (nColumnXMTZ >= 0)
	{
		QModelIndex indexParent = index.parent();
		QString strXMTZ;
		if(indexParent.isValid())
		{
			QModelIndex indexXMTZ = indexParent.child(index.row(),nColumnXMTZ);
			strXMTZ = indexXMTZ.data().toString();
		}
		else
		{
			strXMTZ = pWbqdModel->item(index.row(),nColumnXMTZ)->text();
		}

		//������Ŀ����
		m_bFillingXMTZ = true;
		CXMTZStandardItemModel * pXmtzModel = static_cast<CXMTZStandardItemModel *>(ui.tableViewXMTZ->model());
		pXmtzModel->SetXMTZ(strXMTZ);
		m_bFillingXMTZ = false;
	}
}

void CDlgWbqd::On_treeViewWbqd_DoubleClicked(const QModelIndex & index)
{

}

void CDlgWbqd::On_treeViewWbqd_ItemChanged(QStandardItem * item)
{
	QModelIndex indexXMTZ ;
	/*QStandardItem * pItem = pWbqdModel->itemFromIndex(indexXMTZ);
	if(pItem)
		pItem->setText(strXMTZ);*/
}

void CDlgWbqd::On_tableViewXMTZ_ItemChanged(QStandardItem * item)
{
	CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());
	if (m_bFillingXMTZ)
	{
		return;
	}

	//��ȡ��Ŀ������
	int nColumnXMTZ = pWbqdModel->GetColumn(WBQD::kXMTZ);
	if (nColumnXMTZ < 0)
		return;

	//
	QItemSelectionModel * pSelectionModel = ui.treeViewWbqd->selectionModel();

	//��ȡ��Ŀ������
	if (pSelectionModel->hasSelection())
	{
		//��ȡ��Ŀ����
		CXMTZStandardItemModel * pXmtzModel = static_cast<CXMTZStandardItemModel *>(ui.tableViewXMTZ->model());
		QString strXMTZ = pXmtzModel->GetXMTZ();

		//������Ŀ����
		QModelIndex indexCur = ui.treeViewWbqd->currentIndex();
		QModelIndex parentCur = indexCur.parent();
		if (parentCur.isValid())
		{
			QModelIndex indexXMTZ = pWbqdModel->index(indexCur.row(),nColumnXMTZ,parentCur);
			QStandardItem * pItem = pWbqdModel->itemFromIndex(indexXMTZ);
			if(pItem)
				pItem->setText(strXMTZ);
		}
		else
		{
			QStandardItem * pItem = pWbqdModel->item(indexCur.row(),nColumnXMTZ);
			if(pItem)
				pItem->setText(strXMTZ);
		}
	}
}

//void CDlgWbqd::On_tableViewXMTZ_DataChanged(const QModelIndex & leftTop,const QModelIndex & rightBottom)
//{
//	CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());
//
//	//��ȡ��Ŀ������
//	int nColumnXMTZ = pWbqdModel->GetColumn(WBQD::kXMTZ);
//	if (nColumnXMTZ < 0)
//		return;
//}
//---------
void CDlgWbqd::On_pushButtonRetract_Clicked()
{

	CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());

	//��ȡѡ����
	QModelIndexList indexList = ui.treeViewWbqd->selectionModel()->selectedRows();

	//�ж�ѡ�е����Ƿ���ͬһ��
	if(IsSameLevel(indexList) == FALSE)
	{
		QMessageBox::information(this,QObject::tr("��ʾ"),QObject::tr("ѡ�е����У����ڲ���ͬһ��"),QMessageBox::Ok); 
		return;
	}
	BOOL bMultiSelect = FALSE;
	BOOL bOk = FALSE;
	int iNum = indexList.length();
	if(iNum > 1)
		bMultiSelect = TRUE;

	//
	int nCount = indexList.length();
	if(0 == nCount)
		return;

	//��ȡ�ӽڵ����
	int rowCount = 0;
	if(indexList[0].parent().row() != -1)
	{
		QModelIndex indexParent = indexList[0].parent();
		rowCount = pWbqdModel->rowCount(indexParent);
	}
	else
	{
		rowCount = pWbqdModel->rowCount();
	}

	//
	QModelIndex indexCur;
	int rowInsert = rowCount;
	for(int i = 0;i < nCount;i++)
	{
		QModelIndex modelIndex = indexList[i];
		QModelIndex indexCur;
		if(modelIndex.parent().row() != -1)
		{
			indexCur = modelIndex.parent().child(modelIndex.row(),0);
		}
		else
		{
			indexCur = pWbqdModel->index(modelIndex.row(),0);		
		}
			
		//����㼶��������
		if(GetMaxLevel(indexCur) >= m_iLimit-1)
		{
			QMessageBox::information(this,QObject::tr("��ʾ"),QObject::tr("�޷��������Ѵﵽ���Ĳ㼶"),QMessageBox::Ok); 
			return;
		}
	}

	//
	bOk = DealWithRetract(pWbqdModel,indexList);
	if(FALSE == bOk)
	{
		QMessageBox::information(this,QObject::tr("��ʾ"),QObject::tr("�޷�����"),QMessageBox::Ok); 
	}	
}

//�����ж�
bool compareRow(const QModelIndex & modelIndex1, const QModelIndex & modelIndex2)
{
	if (modelIndex1.row() < modelIndex2.row())
	{
		return true;
	}
	return false;
}

void CDlgWbqd::On_pushButtonExpend_Clicked()
{
	CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());

	BOOL bOk = FALSE;
	AcArray<int> rowArr;

	//��ȡ����ѡ����
	QModelIndexList indexList = ui.treeViewWbqd->selectionModel()->selectedRows();
	std::sort(indexList.begin(),indexList.end());

	//�ж�ѡ�е����Ƿ���ͬһ��
	if(IsSameLevel(indexList) == FALSE)
	{
		QMessageBox::information(this,QObject::tr("��ʾ"),QObject::tr("ѡ�е����У����ڲ���ͬһ��"),QMessageBox::Ok); 
		return;
	}
	//
	for (int i = indexList.length() - 1;i >= 0;i--)
	{
		int row = indexList.at(i).row();

		QModelIndex indexCur = indexList.at(i).parent().child(row,0);

		//��������
		bOk = DealWithExpend(pWbqdModel,indexCur);
		if(FALSE == bOk)
		{
			QMessageBox::information(this,QObject::tr("��ʾ"),QObject::tr("�޷�����"),QMessageBox::Ok); 
		}
	}
					
}
void CDlgWbqd::On_pushButtonMoveUp_Clicked()
{
	CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());

	AcArray<int> rowArr;
	BOOL bOk = FALSE;
	//��ȡ����ѡ����
	QModelIndexList indexList = ui.treeViewWbqd->selectionModel()->selectedRows();
	int iNum = indexList.length();
	if(iNum == 0)
	{
		return;
	}
	QModelIndex indexCur = indexList[0];

	if(iNum > 1 || indexCur.row() == 0)
	{
		QMessageBox::information(this,QObject::tr("��ʾ"),QObject::tr("�޷�����"),QMessageBox::Ok); 
		return;
	}

	//��ȡ����д洦�ڵڼ��㼶
	bOk = DealWithMoveUp(pWbqdModel,indexCur);
	if(FALSE == bOk)
	{
		QMessageBox::information(this,QObject::tr("��ʾ"),QObject::tr("�޷�����"),QMessageBox::Ok); 
	}

}

BOOL CDlgWbqd::DealWithMoveUp(CWbqdStandardItemModel * pModel,QModelIndex indexCur)
{
	int nCurRow = indexCur.row();
	if(nCurRow == 0)
	{
		return FALSE;
	}

	//����ڵ��ϵȻ�����²���
	BOOL bOk = FALSE;
	QModelIndex indexParent = indexCur.parent();
	if (indexParent.isValid() == false)
	{
		QList<QStandardItem*> rowCells = pModel->takeRow(nCurRow);
		if(rowCells.size() > 0)
		{
			//���²���
			pModel->insertRow(nCurRow - 1,rowCells);
			QModelIndex indexSelectTopLeft = pModel->item(nCurRow - 1,0)->index();
			QModelIndex indexSelectBottomRight = pModel->item(nCurRow - 1,pModel->columnCount() - 1)->index();
			QItemSelection itemSelection;
			itemSelection.select(indexSelectTopLeft,indexSelectBottomRight);
			ui.treeViewWbqd->selectionModel()->clearSelection();
			ui.treeViewWbqd->selectionModel()->select(itemSelection,QItemSelectionModel::Select);

			//
			bOk = TRUE;
		}
	}
	else
	{
		QStandardItem * pItemParent = pModel->itemFromIndex(indexParent);
		if (pItemParent)
		{
			//�����ϵ
			QList<QStandardItem*> rowCells = pItemParent->takeRow(nCurRow);
			if(rowCells.size() > 0)
			{
				//���²���
				pItemParent->insertRow(nCurRow - 1,rowCells);

				//��ѡ
				QModelIndex indexSelectTopLeft = pItemParent->child(nCurRow - 1,0)->index();
				QModelIndex indexSelectBottomRight = pItemParent->child(nCurRow - 1,pModel->columnCount() - 1)->index();
				QItemSelection itemSelection;
				itemSelection.select(indexSelectTopLeft,indexSelectBottomRight);
				ui.treeViewWbqd->selectionModel()->clearSelection();
				ui.treeViewWbqd->selectionModel()->select(itemSelection,QItemSelectionModel::Select|QItemSelectionModel::Rows);
				bOk = TRUE;
			}
		}
	}

	return bOk;
}

//��������
BOOL CDlgWbqd::DealWithRetract(CWbqdStandardItemModel * pModel,QModelIndexList & indexList)
{
	std::sort(indexList.begin(),indexList.end());
	if(indexList.size() == 0)
		return FALSE;
	QModelIndex indexCur = indexList[0];
	int nCurRow = indexCur.row();
	if(nCurRow == 0)
	{
		return FALSE;
	}

	//����ڵ��ϵȻ�����²���
	typedef QList<QStandardItem*> QStandardItemList;

	//��ȡ��һ���ڵ�ǰ��һ���ڵ�----������Ϊ���нڵ�ĸ���
	QStandardItem * pItemPre = NULL;
	QModelIndex indexParent = indexCur.parent();
	if (indexParent.isValid() == false)
	{
		pItemPre = pModel->item(nCurRow-1,0);
	}
	else
	{
		QStandardItem * pItemParent = pModel->itemFromIndex(indexParent);
		if (pItemParent)
		{
			//���²���
			pItemPre = pItemParent->child(nCurRow-1,0);
		}
	}
	if (NULL == pItemPre)
	{
		return FALSE;
	}

	//�ڵ�ڵ����������¼������Ľڵ�
	QStack<QStandardItemList *> stackStandardItemList;
	for (int i = indexList.size() - 1;i >= 0;i--)
	{
		QModelIndex modelIndex = indexList[i];
		if (indexParent.isValid() == false)
		{
			//�����ϵ
			QStandardItemList * pRowCells = PMNew(QStandardItemList);
			*pRowCells = pModel->takeRow(modelIndex.row());
			stackStandardItemList.push(pRowCells);
		}
		else
		{
			QStandardItem * pItemParent = pModel->itemFromIndex(indexParent);
			if (pItemParent)
			{
				//�����ϵ
				QStandardItemList * pRowCells = PMNew(QStandardItemList);
				*pRowCells = pItemParent->takeRow(modelIndex.row());
				stackStandardItemList.push(pRowCells);
			}
		}
	}

	//׷�ӵ��½ڵ���,���½�����ϵ
	while(stackStandardItemList.empty() == false)
	{
		QStandardItemList * pRowCells = stackStandardItemList.pop();
		if(pRowCells->size() > 0)
		{
			//���²���
			pItemPre->appendRow(*pRowCells);

			//���µ������ڵ�ĸ���nodetype
			pModel->ReJudgeNodeType(pItemPre->child(pItemPre->rowCount()-1,0));
		}

		//
		PMDelete(pRowCells);
	}

	//
	return TRUE;
}

//��������
BOOL CDlgWbqd::DealWithExpend(CWbqdStandardItemModel * pModel,QModelIndex indexCur)
{
	int nCurRow = indexCur.row();
	QModelIndex indexParent = indexCur.parent();
	if (indexParent.isValid() == false)
	{
		return FALSE;
	}

	//����ڵ��ϵ
	BOOL bOk = FALSE;
	QStandardItem * pItemParent = pModel->itemFromIndex(indexParent);
	if (NULL == pItemParent)
		return FALSE;
	//�����ϵ
	QList<QStandardItem*> rowCells = pItemParent->takeRow(nCurRow);

	//���²���
	QModelIndex indexParentParent = indexParent.parent();
	if (indexParentParent.isValid() == false)
	{
		pModel->insertRow(indexParent.row()+1,rowCells);
		bOk = TRUE;
	}
	else
	{
		QStandardItem * pItemParentParent = pModel->itemFromIndex(indexParentParent);
		pItemParentParent->insertRow(indexParent.row()+1,rowCells);
		bOk = TRUE;
	}

	//
	return bOk;
}

BOOL CDlgWbqd::IsSameLevel(const QModelIndexList & indexList) const
{
	CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());
	if(indexList.length() == 0)
		return TRUE;

	//
	int iConutPre = -1;
	for(int i = 0;i < indexList.length();i++)
	{
		QModelIndex indexCur = indexList[i];
		AcArray<int> rowArr;
		rowArr.append(indexCur.row());

		//��ȡ����д洦�ڵڼ��㼶
		for(int i = 0;i < m_iLimit;i++)
		{
			QModelIndex indexConut = indexCur.parent();
			rowArr.append(indexConut.row());
			if(indexConut.row() == -1)
			{
				break;
			}	
			indexCur = indexConut;
		}

		//
		int iCount = rowArr.length();
		if(iConutPre == -1)
		{
			iConutPre = iCount;
		}
		else if(iConutPre != iCount)
		{
			return FALSE;
		}
	}
	return TRUE;
	
}

void CDlgWbqd::GetPathRow(const QModelIndex &index,PmGeIntArray & arrRowPath) const
{
	arrRowPath.setLogicalLength(0);
	arrRowPath.append(index.row());

	//��ȡ����д洦�ڵڼ��㼶
	QModelIndex indexCur = index;
	for(int i = 0;i < m_iLimit;i++)
	{
		QModelIndex indexParent = indexCur.parent();
		if(indexParent.isValid())
		{
			arrRowPath.append(indexParent.row());
			indexCur = indexParent;
		}	
		else
		{
			break;
		}
	}
}

//���ر��ڵ�㼶
int CDlgWbqd::GetLevel(const QModelIndex &index) const
{
	if(index.isValid() == false)
		return -1;

	//
	int nLevel = 0;

	//��ȡ����д洦�ڵڼ��㼶
	QModelIndex indexCur = index;
	for(int i = 0;i < m_iLimit;i++)
	{
		QModelIndex indexParent = indexCur.parent();
		if(indexParent.isValid())
		{
			nLevel++;
			indexCur = indexParent;
		}	
		else
		{
			break;
		}
	}
	//
	return nLevel;
}

//���������ӽڵ�㼶�����û���ӽڵ㣬�򷵻ر��ڵ�㼶
int CDlgWbqd::GetMaxLevel(const QModelIndex &index) const
{
	if(index.isValid() == false)
		return -1;
	//
	int nLevel = GetLevel(index);
	nLevel += GetChildLevelCount(index);
	return nLevel - 1;
}

int CDlgWbqd::GetChildLevelCount(const QModelIndex &index) const
{
	int nMaxLevel = 0;

	//
	int nRowCur = 0;
	QModelIndex indexCur = index;
	QStack<QModelIndex> stackItems;
	stackItems.push(index);
	do
	{
		indexCur = stackItems.top();
		QModelIndex indexChild = indexCur.child(nRowCur,0);
		if (indexChild.isValid())
		{
			//�����ӽڵ�
			nRowCur = 0;
			stackItems.push(indexChild);
			indexCur = indexChild;
		}
		else
		{
			//��ǰΪҶ�ڵ�
			if(nMaxLevel < stackItems.size())
				nMaxLevel = stackItems.size();

			//�����ֵܽڵ�
			int nRow = indexCur.row();
			nRowCur = nRow+1;
			stackItems.pop();
		}
	}while(stackItems.empty() == false);

	//
	return nMaxLevel;
}

//---------
void CDlgWbqd::On_tableViewXMTZ_pressed(const QModelIndex &index)
{
	TRACE("On_tableViewXMTZ_pressed");
}
void CDlgWbqd::On_tableViewXMTZ_clicked(const QModelIndex &index)
{
	TRACE("CDlgWbqd::On_tableViewXMTZ_clicked");
}
void CDlgWbqd::On_tableViewXMTZ_doubleClicked(const QModelIndex &index)
{
	TRACE("CDlgWbqd::On_tableViewXMTZ_doubleClicked");
}

void CDlgWbqd::On_tableViewXMTZ_activated(const QModelIndex &index)
{
	TRACE("CDlgWbqd::On_tableViewXMTZ_activated");
}
void CDlgWbqd::On_tableViewXMTZ_entered(const QModelIndex &index)
{
	TRACE("CDlgWbqd::On_tableViewXMTZ_entered");
}
void CDlgWbqd::On_tableViewXMTZ_viewportEntered()
{
	TRACE("CDlgWbqd::On_tableViewXMTZ_viewportEntered");
}

void CDlgWbqd::closeEvent ( QCloseEvent * e )
{
	int rc =  QMessageBox::question(this,	tr("�ⲿ�嵥"),	tr("�Ƿ񱣴�"),	QObject::tr("��"),QObject::tr("��"),QObject::tr("�ݲ��˳�"));
	if(0 == rc)
	{
		CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());
		pWbqdModel->SaveWbqdToDb();
	}
	
	if(2 == rc)
		e->ignore();	//���˳�
	else
		e->accept();	//���Ὣ�¼����ݸ�����ĸ����
}