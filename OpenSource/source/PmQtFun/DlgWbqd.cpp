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
	
	//处理中文乱码
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	WBQD::InitValue();

	//
	m_bFillingXMTZ = false;

	//初始化表格样式
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
	
	//设置子级限制为5级[1,2,3,4,5,从1开始数]
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

	//设置表头
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

	//信号与槽
	//QObject::connect(ui.treeViewWbqd,SIGNAL(clicked(QModelIndex)),this,SLOT(On_treeViewWbqd_Clicked(QModelIndex)));
	QObject::connect(pWbqdModel,SIGNAL(itemChanged(QStandardItem *)),this,SLOT(On_treeViewWbqd_ItemChanged(QStandardItem *)));
	QObject::connect(this,SIGNAL(signal_clicked(WBQD *)),pWbqdModel,SLOT(OnAddDE(WBQD *)));
	//QObject::connect(pWbqdModel,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(On_treeViewWbqd_DataChanged(QModelIndex,QModelIndex)));

	//设置为不可编辑状态
	//ui.treeViewWbqd->setEditTriggers(0);
	//设置多选
	ui.treeViewWbqd->setSelectionMode(QAbstractItemView::ExtendedSelection); 
	//去掉鼠标移到单元格上时的虚线框
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
	QStandardItem * pColXmtz = new QStandardItem(QObject::tr("项目特征"));
	pXmtzModel->setHorizontalHeaderItem(0, pColXmtz);
	QStandardItem * pColValue = new QStandardItem(QObject::tr("数值"));
	pXmtzModel->setHorizontalHeaderItem(1, pColValue);

	//
	ui.tableViewXMTZ->setColumnWidth(0,200);
	ui.tableViewXMTZ->setColumnWidth(1,400);
	ui.tableViewXMTZ->setEditTriggers(QAbstractItemView::DoubleClicked);

	//信号与槽
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
	QString strFile = QFileDialog::getOpenFileName(this,QObject::tr("请选择要导入的外部清单"),".",strFilter);
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
		//覆盖时删除原有的
		if (bCover)
		{
			int nRowCount = pWbqdModel->rowCount();
			pWbqdModel->removeRows(0,nRowCount);
		}

		//
		pWbqdModel->CopyDataFrom(pContentModel);

		//建立树状层级关系
		if(bFillTree)
		{
			pWbqdModel->BuildTreeRelation();
		}

		//追加时合并同一个项目编码节点---保留原先
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
	
	//获取项目特征列
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

		//设置项目特征
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

	//获取项目特征列
	int nColumnXMTZ = pWbqdModel->GetColumn(WBQD::kXMTZ);
	if (nColumnXMTZ < 0)
		return;

	//
	QItemSelectionModel * pSelectionModel = ui.treeViewWbqd->selectionModel();

	//获取项目特征列
	if (pSelectionModel->hasSelection())
	{
		//获取项目特征
		CXMTZStandardItemModel * pXmtzModel = static_cast<CXMTZStandardItemModel *>(ui.tableViewXMTZ->model());
		QString strXMTZ = pXmtzModel->GetXMTZ();

		//重置项目特征
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
//	//获取项目特征列
//	int nColumnXMTZ = pWbqdModel->GetColumn(WBQD::kXMTZ);
//	if (nColumnXMTZ < 0)
//		return;
//}
//---------
void CDlgWbqd::On_pushButtonRetract_Clicked()
{

	CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());

	//获取选中行
	QModelIndexList indexList = ui.treeViewWbqd->selectionModel()->selectedRows();

	//判断选中的行是否是同一级
	if(IsSameLevel(indexList) == FALSE)
	{
		QMessageBox::information(this,QObject::tr("提示"),QObject::tr("选中的行中，存在不是同一级"),QMessageBox::Ok); 
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

	//获取子节点个数
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
			
		//如果层级数不符合
		if(GetMaxLevel(indexCur) >= m_iLimit-1)
		{
			QMessageBox::information(this,QObject::tr("提示"),QObject::tr("无法缩进，已达到最大的层级"),QMessageBox::Ok); 
			return;
		}
	}

	//
	bOk = DealWithRetract(pWbqdModel,indexList);
	if(FALSE == bOk)
	{
		QMessageBox::information(this,QObject::tr("提示"),QObject::tr("无法缩进"),QMessageBox::Ok); 
	}	
}

//排列判断
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

	//获取所有选中行
	QModelIndexList indexList = ui.treeViewWbqd->selectionModel()->selectedRows();
	std::sort(indexList.begin(),indexList.end());

	//判断选中的行是否是同一级
	if(IsSameLevel(indexList) == FALSE)
	{
		QMessageBox::information(this,QObject::tr("提示"),QObject::tr("选中的行中，存在不是同一级"),QMessageBox::Ok); 
		return;
	}
	//
	for (int i = indexList.length() - 1;i >= 0;i--)
	{
		int row = indexList.at(i).row();

		QModelIndex indexCur = indexList.at(i).parent().child(row,0);

		//处理缩出
		bOk = DealWithExpend(pWbqdModel,indexCur);
		if(FALSE == bOk)
		{
			QMessageBox::information(this,QObject::tr("提示"),QObject::tr("无法缩出"),QMessageBox::Ok); 
		}
	}
					
}
void CDlgWbqd::On_pushButtonMoveUp_Clicked()
{
	CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());

	AcArray<int> rowArr;
	BOOL bOk = FALSE;
	//获取所有选中行
	QModelIndexList indexList = ui.treeViewWbqd->selectionModel()->selectedRows();
	int iNum = indexList.length();
	if(iNum == 0)
	{
		return;
	}
	QModelIndex indexCur = indexList[0];

	if(iNum > 1 || indexCur.row() == 0)
	{
		QMessageBox::information(this,QObject::tr("提示"),QObject::tr("无法上移"),QMessageBox::Ok); 
		return;
	}

	//获取点击行存处于第几层级
	bOk = DealWithMoveUp(pWbqdModel,indexCur);
	if(FALSE == bOk)
	{
		QMessageBox::information(this,QObject::tr("提示"),QObject::tr("无法上移"),QMessageBox::Ok); 
	}

}

BOOL CDlgWbqd::DealWithMoveUp(CWbqdStandardItemModel * pModel,QModelIndex indexCur)
{
	int nCurRow = indexCur.row();
	if(nCurRow == 0)
	{
		return FALSE;
	}

	//解除节点关系然后重新插入
	BOOL bOk = FALSE;
	QModelIndex indexParent = indexCur.parent();
	if (indexParent.isValid() == false)
	{
		QList<QStandardItem*> rowCells = pModel->takeRow(nCurRow);
		if(rowCells.size() > 0)
		{
			//重新插入
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
			//解除关系
			QList<QStandardItem*> rowCells = pItemParent->takeRow(nCurRow);
			if(rowCells.size() > 0)
			{
				//重新插入
				pItemParent->insertRow(nCurRow - 1,rowCells);

				//重选
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

//缩进处理
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

	//解除节点关系然后重新插入
	typedef QList<QStandardItem*> QStandardItemList;

	//获取第一个节点前的一个节点----用于作为所有节点的父类
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
			//重新插入
			pItemPre = pItemParent->child(nCurRow-1,0);
		}
	}
	if (NULL == pItemPre)
	{
		return FALSE;
	}

	//节点节点关联，并记录被解除的节点
	QStack<QStandardItemList *> stackStandardItemList;
	for (int i = indexList.size() - 1;i >= 0;i--)
	{
		QModelIndex modelIndex = indexList[i];
		if (indexParent.isValid() == false)
		{
			//解除关系
			QStandardItemList * pRowCells = PMNew(QStandardItemList);
			*pRowCells = pModel->takeRow(modelIndex.row());
			stackStandardItemList.push(pRowCells);
		}
		else
		{
			QStandardItem * pItemParent = pModel->itemFromIndex(indexParent);
			if (pItemParent)
			{
				//解除关系
				QStandardItemList * pRowCells = PMNew(QStandardItemList);
				*pRowCells = pItemParent->takeRow(modelIndex.row());
				stackStandardItemList.push(pRowCells);
			}
		}
	}

	//追加到新节点下,重新建立关系
	while(stackStandardItemList.empty() == false)
	{
		QStandardItemList * pRowCells = stackStandardItemList.pop();
		if(pRowCells->size() > 0)
		{
			//重新插入
			pItemPre->appendRow(*pRowCells);

			//重新调整各节点的附属nodetype
			pModel->ReJudgeNodeType(pItemPre->child(pItemPre->rowCount()-1,0));
		}

		//
		PMDelete(pRowCells);
	}

	//
	return TRUE;
}

//缩出处理
BOOL CDlgWbqd::DealWithExpend(CWbqdStandardItemModel * pModel,QModelIndex indexCur)
{
	int nCurRow = indexCur.row();
	QModelIndex indexParent = indexCur.parent();
	if (indexParent.isValid() == false)
	{
		return FALSE;
	}

	//解除节点关系
	BOOL bOk = FALSE;
	QStandardItem * pItemParent = pModel->itemFromIndex(indexParent);
	if (NULL == pItemParent)
		return FALSE;
	//解除关系
	QList<QStandardItem*> rowCells = pItemParent->takeRow(nCurRow);

	//重新插入
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

		//获取点击行存处于第几层级
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

	//获取点击行存处于第几层级
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

//返回本节点层级
int CDlgWbqd::GetLevel(const QModelIndex &index) const
{
	if(index.isValid() == false)
		return -1;

	//
	int nLevel = 0;

	//获取点击行存处于第几层级
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

//返回最大的子节点层级，如果没有子节点，则返回本节点层级
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
			//进入子节点
			nRowCur = 0;
			stackItems.push(indexChild);
			indexCur = indexChild;
		}
		else
		{
			//当前为叶节点
			if(nMaxLevel < stackItems.size())
				nMaxLevel = stackItems.size();

			//搜索兄弟节点
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
	int rc =  QMessageBox::question(this,	tr("外部清单"),	tr("是否保存"),	QObject::tr("是"),QObject::tr("否"),QObject::tr("暂不退出"));
	if(0 == rc)
	{
		CWbqdStandardItemModel * pWbqdModel = static_cast<CWbqdStandardItemModel *>(ui.treeViewWbqd->model());
		pWbqdModel->SaveWbqdToDb();
	}
	
	if(2 == rc)
		e->ignore();	//不退出
	else
		e->accept();	//不会将事件传递给组件的父组件
}