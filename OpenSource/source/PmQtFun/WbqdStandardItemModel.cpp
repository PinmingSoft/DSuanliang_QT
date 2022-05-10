#include "StdAfx.h"
#include "WbqdStandardItemModel.h"
#include "Wbqd_LoadExcel_Delegate.h"
#include "pmqtfun.h"
#include <QStack>
#include <QVariant>

///////////////////////////////////////////////////////////////////////////////////////////////////////
//CWbqdStandardItemModel
///////////////////////////////////////////////////////////////////////////////////////////////////////
CWbqd_LoadExcelItemModel::CWbqd_LoadExcelItemModel(QAbstractItemView *parent):QStandardItemModel(parent)
{
}

CWbqd_LoadExcelItemModel::~CWbqd_LoadExcelItemModel(void)
{
}

//重新检测行的合理性，合理的勾选上
bool CWbqd_LoadExcelItemModel::CheckRow(int row,bool bChecked)
{
	//第一行为列名，不允许勾选
	if(0 == row)
		return false;

	//
	bool bLegal = IsRowLegal(this,row);
	if(bChecked)
	{
		if(bLegal)
		{
			this->item(row, 0)->setCheckState(Qt::Checked);
			return true;
		}
		else
		{
			//
			this->item(row, 0)->setCheckState(Qt::Unchecked);
			return false;
		}
	}
	else
	{
		this->item(row, 0)->setCheckState(Qt::Unchecked);
	}

	//
	return true;
}

void CWbqd_LoadExcelItemModel::CheckRows(bool bChecked)
{
	for(int row = 0;row < this->rowCount();row++)
	{
		CheckRow(row,bChecked);
	}
}

bool CWbqd_LoadExcelItemModel::IsRowLegal(QStandardItemModel * pContentModel,int row) const
{
	bool bOk = false;
	if(IsRowLegal_QD(pContentModel,row))
		bOk = true;
	else if(IsRowLegal_DE(pContentModel,row))
		bOk = true;
	else if(IsRowLegal_Chapter(pContentModel,row))
		bOk = true;
	return bOk;
}

//重新检测行的合理性
bool CWbqd_LoadExcelItemModel::IsRowLegal_QD(QStandardItemModel * pContentModel,int row) const
{
	bool bXMBMLegal = false;
	bool bXMMCLegal = false;
	bool bJLDWLegal = false;
	for(int col = 1;col < pContentModel->columnCount();col++)
	{
		QMap<int,QString>::const_iterator iter = m_mapCol2Name.find(col);
		if (iter != m_mapCol2Name.end())
		{
			QString strColName = iter.value();
			QString strValue = pContentModel->item(row,col)->text();
			if(strColName == WBQD::kXMBM)
			{
				QRegExp rx("^[0-9]+$");
				bXMBMLegal = rx.exactMatch(strValue);
				if(false == bXMBMLegal)
					break;

			}
			else if(strColName == WBQD::kXMMC)
			{
				bXMMCLegal = !strValue.isEmpty();
				if(false == bXMMCLegal)
					break;
			}
			else if(strColName == WBQD::kJLDW)
			{
				bJLDWLegal = !strValue.isEmpty();
				if(false == bJLDWLegal)
					break;
			}
		}
	}

	//
	return bXMBMLegal&&bXMMCLegal&&bJLDWLegal;
}

bool CWbqd_LoadExcelItemModel::IsRowLegal_DE(QStandardItemModel * pContentModel,int row) const
{
	bool bXMMCLegal = false;
	bool bJLDWLegal = false;
	for(int col = 1;col < pContentModel->columnCount();col++)
	{
		QMap<int,QString>::const_iterator iter = m_mapCol2Name.find(col);
		if (iter != m_mapCol2Name.end())
		{
			QString strColName = iter.value();
			QString strValue = pContentModel->item(row,col)->text();
			if(strColName == WBQD::kXMMC)
			{
				bXMMCLegal = !strValue.isEmpty();
				if(false == bXMMCLegal)
					break;
			}
			else if(strColName == WBQD::kJLDW)
			{
				bJLDWLegal = !strValue.isEmpty();
				if(false == bJLDWLegal)
					break;
			}
		}
	}

	//
	return bXMMCLegal&&bJLDWLegal;
}

bool CWbqd_LoadExcelItemModel::IsRowLegal_Chapter(QStandardItemModel * pContentModel,int row) const
{
	bool bXMMCLegal = false;
	for(int col = 1;col < pContentModel->columnCount();col++)
	{
		QMap<int,QString>::const_iterator iter = m_mapCol2Name.find(col);
		if (iter != m_mapCol2Name.end())
		{
			QString strColName = iter.value();
			QString strValue = pContentModel->item(row,col)->text();
			if(strColName == WBQD::kXMMC)
			{
				bXMMCLegal = !strValue.isEmpty();
				if(bXMMCLegal)
					break;
			}
		}
	}

	//
	return bXMMCLegal;
}

bool CWbqd_LoadExcelItemModel::HasColumn(QString colName) const
{
	int nCol = GetColumn(colName);
	return -1==nCol?false:true;
}

int CWbqd_LoadExcelItemModel::GetColumn(QString colName) const
{
	int nColHas = -1;
	QMap<int,QString>::const_iterator iter = m_mapCol2Name.begin();
	for (;iter != m_mapCol2Name.end();iter++)
	{
		QString strColName = iter.value();
		if(strColName == colName)
		{
			nColHas = iter.key();
			break;
		}
	}

	//
	return nColHas;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//CWbqdStandardItemModel
///////////////////////////////////////////////////////////////////////////////////////////////////////
CWbqdStandardItemModel::CWbqdStandardItemModel(QAbstractItemView *parent):QStandardItemModel(parent)
{
	m_iLimit = 3;
}

CWbqdStandardItemModel::~CWbqdStandardItemModel(void)
{
}


//获取列名匹配关系
//void CWbqdStandardItemModel::GetMapCol2Name(QMap<int,QString> & mapCol2Name) const
//{
//	mapCol2Name.clear();
//	mapCol2Name = m_mapCol2Name;
//}

bool CWbqdStandardItemModel::HasColumn(QString colName) const
{
	int nCol = GetColumn(colName);
	return -1==nCol?false:true;
}

int CWbqdStandardItemModel::GetColumn(QString colName) const
{
	int nColHas = -1;
	QMap<int,QString>::const_iterator iter = m_mapCol2Name.begin();
	for (;iter != m_mapCol2Name.end();iter++)
	{
		QString strColName = iter.value();
		if(strColName == colName)
		{
			nColHas = iter.key();
			break;
		}
	}

	//
	return nColHas;
}

void CWbqdStandardItemModel::OnAddQD(const WBQD * pWBQD)
{
	QAbstractItemView * pTableView = static_cast<QAbstractItemView *>(parent());
	if (NULL == pTableView)
	{
		return;
	}
	QModelIndex indexCurrent = pTableView->currentIndex();
	if (indexCurrent.isValid() == false)
	{
		QMessageBox::about(pTableView,QObject::tr("外部清单"),QObject::tr("缺少对应章节"));
		return;
	}
	QModelIndex indexCurrentSib0 = indexCurrent.sibling(indexCurrent.row(),0);
	QStandardItem * pCurrentItem = itemFromIndex(indexCurrent);
	QStandardItem * pCurrentSibItem0 = itemFromIndex(indexCurrentSib0);
	QStandardItem * pParentItem = pCurrentItem->parent();
	int typCurrent = 0;
	if (pCurrentSibItem0)
	{
		typCurrent = pCurrentSibItem0->data(Qt::UserRole+ 1).toInt();
	}
	else
		return;

	//插入一行
	bool bOk = false;
	if(Chapter == typCurrent)
	{
		bOk = true;
		QStandardItem * pItemNew = AppendNewRow(pCurrentSibItem0,pWBQD->m_strXMMC,pWBQD->m_strXMBM,pWBQD->m_strXMTZ,pWBQD->m_strJLDW);
		SetItemQDType(pItemNew);
	}
	else if(QD == typCurrent)
	{
		if(pParentItem)
		{
			bOk = true;
			QStandardItem * pItemNew = InsertNewRow(pParentItem,indexCurrent.row()+1,pWBQD->m_strXMMC,pWBQD->m_strXMBM,pWBQD->m_strXMTZ,pWBQD->m_strJLDW);
			SetItemQDType(pItemNew);
		}
		else
		{
			bOk = true;
			QStandardItem * pItemNew = InsertNewRow(NULL,indexCurrent.row()+1,pWBQD->m_strXMMC,pWBQD->m_strXMBM,pWBQD->m_strXMTZ,pWBQD->m_strJLDW);
			SetItemQDType(pItemNew);
		}
	}
	else if(DE == typCurrent)
	{
		if(pParentItem)
		{
			bOk = true;
			QStandardItem * pItemNew = InsertNewRow(pParentItem,pParentItem->row()+1,pWBQD->m_strXMMC,pWBQD->m_strXMBM,pWBQD->m_strXMTZ,pWBQD->m_strJLDW);
			SetItemQDType(pItemNew);
		}
	}
	else
	{
		QMessageBox::about(pTableView,"",QObject::tr("请选择清单要对应的章节或者要插入的清单节点位置"));
	}
}

void CWbqdStandardItemModel::OnAddDE(const WBQD * pWBQD)
{
	QAbstractItemView * pTableView = static_cast<QAbstractItemView *>(parent());
	if (NULL == pTableView)
	{
		return;
	}
	QModelIndex indexCurrent = pTableView->currentIndex();
	if (indexCurrent.isValid() == false)
	{
		QMessageBox::about(pTableView,QObject::tr("外部清单"),QObject::tr("缺少对应章节"));
		return;
	}
	QModelIndex indexCurrentSib0 = indexCurrent.sibling(indexCurrent.row(),0);
	QStandardItem * pCurrentItem = itemFromIndex(indexCurrent);
	QStandardItem * pCurrentSibItem0 = itemFromIndex(indexCurrentSib0);
	QStandardItem * pParentItem = pCurrentItem->parent();
	int typCurrent = 0;
	if (pCurrentSibItem0)
	{
		typCurrent = pCurrentSibItem0->data(Qt::UserRole+ 1).toInt();
	}
	else
		return;

	//插入一行
	bool bOk = false;
	if(QD == typCurrent)
	{
		bOk = true;
		QStandardItem * pItemNew = AppendNewRow(pCurrentSibItem0,pWBQD->m_strXMMC,pWBQD->m_strXMBM,pWBQD->m_strXMTZ,pWBQD->m_strJLDW);
		SetItemQDType(pItemNew);
	}
	else
	{
		if(pParentItem)
		{
			bOk = true;
			QStandardItem * pItemNew = InsertNewRow(pParentItem,indexCurrent.row()+1,pWBQD->m_strXMMC,pWBQD->m_strXMBM,pWBQD->m_strXMTZ,pWBQD->m_strJLDW);
			SetItemQDType(pItemNew);
		}
		else
		{
			bOk = true;
			QStandardItem * pItemNew = InsertNewRow(NULL,indexCurrent.row()+1,pWBQD->m_strXMMC,pWBQD->m_strXMBM,pWBQD->m_strXMTZ,pWBQD->m_strJLDW);
			SetItemQDType(pItemNew);
		}
	}
}

bool CWbqdStandardItemModel::IsRow_QD(int row) const
{
	int nColXMMC = GetColumn(WBQD::kXMMC);	
	int nColXMBM = GetColumn(WBQD::kXMBM);
	int nColJLDW = GetColumn(WBQD::kJLDW);
	if(-1 == nColXMMC||-1 == nColXMBM||-1 == nColJLDW)
		return false;

	//
	return IsRow_QD(item(row,nColXMMC),item(row,nColXMBM),item(row,nColJLDW));
}

bool CWbqdStandardItemModel::IsRow_QD(QStandardItem * pItemXMMC,QStandardItem * pItemXMBM,QStandardItem * pItemJLDW) const
{
	bool bDe = true;

	//
	QString strXMMC = pItemXMMC->text();
	QString strXMBM = pItemXMBM->text();
	QString strJLDW = pItemJLDW->text();

	if(strXMMC == QObject::tr("装饰"))
		int ttt = 0;
	//如果名称/单位列为空，则不可能为章节
	if(strXMMC.isEmpty() || strJLDW.isEmpty())
	{
		bDe = false;
	}
	//如果定额编号存在，则
	else if(strXMBM.isEmpty() == false)
	{
		QRegExp rx("^[0-9A-Z]+$");
		bool bMatch = rx.exactMatch(strXMBM);
		if(false == bMatch)
			bDe = false;
	}

	//
	return bDe;
}

bool CWbqdStandardItemModel::IsRow_DE(int row) const
{
	int nColXMMC = GetColumn(WBQD::kXMMC);	
	int nColXMBM = GetColumn(WBQD::kXMBM);
	int nColJLDW = GetColumn(WBQD::kJLDW);
	if(-1 == nColXMMC||-1 == nColXMBM||-1 == nColJLDW)
		return false;

	//
	return IsRow_DE(item(row,nColXMMC),item(row,nColXMBM),item(row,nColJLDW));
}

bool CWbqdStandardItemModel::IsRow_DE(QStandardItem * pItemXMMC,QStandardItem * pItemXMBM,QStandardItem * pItemJLDW) const
{
	bool bDe = true;
	//
	QString strXMMC = pItemXMMC->text();
	QString strXMBM = pItemXMBM->text();
	QString strJLDW = pItemJLDW->text();

	//如果名称/单位列为空，则不可能为章节
	if(strXMMC.isEmpty() || strJLDW.isEmpty())
	{
		bDe = false;
	}
	//如果定额编号存在，则
	else if(strXMBM.isEmpty() == false)
	{
		QRegExp rx("^[0-9]+-[0-9]+$");
		bool bMatch = rx.exactMatch(strXMBM);
		if(false == bMatch)
			bDe = false;
	}

	//
	return bDe;
}

bool CWbqdStandardItemModel::IsRow_Chapter(int row) const
{
	int nColXMMC = GetColumn(WBQD::kXMMC);	
	int nColXMBM = GetColumn(WBQD::kXMBM);
	int nColJLDW = GetColumn(WBQD::kJLDW);
	if(-1 == nColXMMC||-1 == nColXMBM||-1 == nColJLDW)
		return false;

	//
	return IsRow_Chapter(item(row,nColXMMC),item(row,nColXMBM),item(row,nColJLDW));
}

bool CWbqdStandardItemModel::IsRow_Chapter(QStandardItem * pItemXMMC,QStandardItem * pItemXMBM,QStandardItem * pItemJLDW) const
{
	bool bChapter = true;
	QString strXMMC = pItemXMMC->text();
	QString strXMBM = pItemXMBM->text();
	QString strJLDW = pItemJLDW->text();

	//如果名称列为空，则不可能为章节
	if(strXMMC.isEmpty())
	{
		bChapter = false;
	}
	//如果编码列或者计量单位列非空，则不可能为章节
	else if(strXMBM.size() >=4 || strJLDW.isEmpty() == false)
	{
		bChapter = false;
	}

	//
	return bChapter;
}

void CWbqdStandardItemModel::CopyDataFrom(const CWbqd_LoadExcelItemModel * pDataFrom)
{
	//建立列的匹配关系---按名称匹配
	QMap<int,int> mapColumn;
	QMap<int,QString>::const_iterator iter = m_mapCol2Name.begin();
	for (;iter != m_mapCol2Name.end();iter++)
	{
		int nColThis = iter.key();
		QString strColNameThis = iter.value();
		
		//
		QMap<int,QString>::const_iterator iterFrom = pDataFrom->m_mapCol2Name.begin();
		for (;iterFrom != pDataFrom->m_mapCol2Name.end();iterFrom++)
		{
			QString strColNameFrom = iterFrom.value();
			if(strColNameFrom == strColNameThis)
			{
				mapColumn.insert(nColThis,iterFrom.key());
				break;
			}
		}
	}


	//写入表格数据
	int nRowThisCur = rowCount();
	for (int rowFrom = 0;rowFrom < pDataFrom->rowCount();rowFrom++)
	{
		//获取勾选的行或者没有勾选框的行
		if(Qt::Unchecked == pDataFrom->item(rowFrom,0)->checkState()
			&& true == pDataFrom->item(rowFrom,0)->isCheckable())
			continue;

		//
		int rowNew = InsertTableNewRow(nRowThisCur);
		QMap<int,int>::const_iterator iter = mapColumn.begin();
		for (;iter != mapColumn.end();iter++)
		{
			int nColThis = iter.key();
			int nColFrom = iter.value();
			QStandardItem * pItemFrom = pDataFrom->item(rowFrom,nColFrom);
			QString strValue = pItemFrom->text();
			PmQtFun::TrimEnter(strValue);

			//插入数据
			item(rowNew, nColThis)->setText(strValue);
			if(m_mapCol2Name[nColThis] == WBQD::kXMMC
				||m_mapCol2Name[nColThis] == WBQD::kXMTZ)
			{
				item(rowNew, nColThis)->setTextAlignment(Qt::AlignLeft);

			}
		}
		nRowThisCur++;
	}
}

/**
* @brief   重建各节点的父子关系
*
*			算法步骤1：L1,L2,L3_1,L3_2,由于此时有两个L3,L3_1被弹出，于是堆栈变为(L1,L2,L3_2)
*			算法步骤2：L1,L2,L3_2,L4,L2_1 由于此时发现L2_1,于是L4,L3_2,L2相继被弹出，于是堆栈变为(L1,L2_1)
* @note  : 
* @param : 
* @return: TRUE/FALSE
* @author: zfy
* @date  : [7/12/2019]
*/
void PopUntilParent(QStack<QStandardItem *> & stackParent,const QStandardItem * itemSrc)
{
	while(stackParent.isEmpty() == false)
	{
		QStandardItem * pParent = stackParent.top();
		int nLevelDes = pParent->data(Qt::UserRole+1).toInt();
		int nLevelSrc = itemSrc->data(Qt::UserRole+1).toInt();
		if (nLevelDes >= nLevelSrc)
		{
			stackParent.pop();
			continue;
		}
		else
		{
			break;
		}
	}
}

CWbqdStandardItemModel::ItemQDType CWbqdStandardItemModel::JudgeItemQDType(int row) const
{
	CWbqdStandardItemModel::ItemQDType typ = UnKnownType;
	int nCol = GetColumn(WBQD::kXMBM);
	if (nCol >= 0)
	{
		if(IsRow_QD(row))
			typ = CWbqdStandardItemModel::QD;
		else if(IsRow_DE(row))
			typ = CWbqdStandardItemModel::DE;
		else if(IsRow_Chapter(row))
			typ = CWbqdStandardItemModel::Chapter;
	}

	//
	return typ;
}

void CWbqdStandardItemModel::ReJudgeNodeType(QStandardItem * pItem)
{
	QStandardItem * pParentItem = pItem->parent();
	if (NULL == pParentItem)
	{
		SetItemQDType(pItem,CWbqdStandardItemModel::Chapter);
	}
	else
	{
		int nColXMMC = GetColumn(WBQD::kXMMC);	
		int nColXMBM = GetColumn(WBQD::kXMBM);
		int nColJLDW = GetColumn(WBQD::kJLDW);
		if(-1 == nColXMMC||-1 == nColXMBM||-1 == nColJLDW)
			return;

		//
		QStandardItem * pItemXMMC = pParentItem->child(pItem->row(),nColXMMC);
		QStandardItem * pItemXMBM = pParentItem->child(pItem->row(),nColXMBM);
		QStandardItem * pItemJLDW = pParentItem->child(pItem->row(),nColJLDW);
		CWbqdStandardItemModel::ItemQDType typ = JudgeItemQDType(pItemXMMC,pItemXMBM,pItemJLDW);
		SetItemQDType(pItem,typ);
	}
}

CWbqdStandardItemModel::ItemQDType CWbqdStandardItemModel::JudgeItemQDType(QStandardItem * pItemXMMC,QStandardItem * pItemXMBM,QStandardItem * pItemJLDW) const
{
	CWbqdStandardItemModel::ItemQDType typ = UnKnownType;
	int nCol = GetColumn(WBQD::kXMBM);
	if (nCol >= 0)
	{
		if(IsRow_QD(pItemXMMC,pItemXMBM,pItemJLDW))
			typ = CWbqdStandardItemModel::QD;
		else if(IsRow_DE(pItemXMMC,pItemXMBM,pItemJLDW))
			typ = CWbqdStandardItemModel::DE;
		else if(IsRow_Chapter(pItemXMMC,pItemXMBM,pItemJLDW))
		{
			//QStandardItem * pItemParent = pItemXMMC->parent();
			//if(NULL == pItemParent)
			typ = CWbqdStandardItemModel::Chapter;
		}
	}

	//
	return typ;
}

void CWbqdStandardItemModel::SetItemQDType(int row)
{
	CWbqdStandardItemModel::ItemQDType typ = JudgeItemQDType(row);
	SetItemQDType(row,typ);
}

void CWbqdStandardItemModel::SetItemQDType(int row,CWbqdStandardItemModel::ItemQDType typ)
{
	QStandardItem * pItem = item(row,0);
	pItem->setData(typ,Qt::UserRole+1);
}

void CWbqdStandardItemModel::SetItemQDType(QStandardItem * pItem,CWbqdStandardItemModel::ItemQDType typ)
{
	pItem->setData(typ,Qt::UserRole+1);
}

void CWbqdStandardItemModel::SetItemQDType(QStandardItem * pItem)
{
	int nColXMBM = GetColumn(WBQD::kXMBM);
	int nColXMMC = GetColumn(WBQD::kXMMC);
	int nColXMTZ = GetColumn(WBQD::kXMTZ);
	int nColJLDW = GetColumn(WBQD::kJLDW);

	//
	int row = pItem->row();

	//
	QModelIndex index = pItem->index();
	QModelIndex indexXMMC = index.sibling(row,nColXMMC);	QStandardItem * pXMMC = itemFromIndex(indexXMMC);
	QModelIndex indexXMBM = index.sibling(row,nColXMBM);	QStandardItem * pXMBM = itemFromIndex(indexXMBM);
	QModelIndex indexJLDW = index.sibling(row,nColJLDW);	QStandardItem * pJLDW  = itemFromIndex(indexJLDW);

	//
	CWbqdStandardItemModel::ItemQDType typ = JudgeItemQDType(pXMMC,pXMBM,pJLDW);

	//
	pItem->setData(typ,Qt::UserRole+1);
}

void CWbqdStandardItemModel::SetItemQDType(QStandardItem * pItemParent,int row)
{
	int nColXMBM = GetColumn(WBQD::kXMBM);
	int nColXMMC = GetColumn(WBQD::kXMMC);
	int nColXMTZ = GetColumn(WBQD::kXMTZ);
	int nColJLDW = GetColumn(WBQD::kJLDW);
	
	//
	QStandardItem * pXMMC = pItemParent->child(row,nColXMMC);
	QStandardItem * pXMBM = pItemParent->child(row,nColXMBM);
	QStandardItem * pJLDW = pItemParent->child(row,nColJLDW);

	//
	QStandardItem * pItem = pItemParent->child(row,0);
	CWbqdStandardItemModel::ItemQDType typ = JudgeItemQDType(pXMMC,pXMBM,pJLDW);
	//if(UnKnownType == typ)
	//	typ = typPre;
	pItem->setData(typ,Qt::UserRole+1);
}

CWbqdStandardItemModel::ItemQDType CWbqdStandardItemModel::GetItemQDType(QStandardItem * pItem) const
{
	if(pItem->row() == 0)
	{
		QVariant var = pItem->data(Qt::UserRole+1);
		return (CWbqdStandardItemModel::ItemQDType)var.toInt();
	}
	else
	{
		QModelIndex index = pItem->index();
		int row = pItem->row();

		//
		QModelIndex indexSibing0 = index.sibling(row,0);
		QStandardItem * pItem0 = itemFromIndex(indexSibing0);
		QVariant var = pItem0->data(Qt::UserRole+1);
		return (CWbqdStandardItemModel::ItemQDType)var.toInt();	
	}

	//
	return CWbqdStandardItemModel::UnKnownType;
}

void CWbqdStandardItemModel::BuildTreeRelation()
{
	//分析层级关系
	CWbqdStandardItemModel::ItemQDType  typPre = UnKnownType;
	for (int row = 0;row < rowCount();row++)
	{
		QStandardItem * pItem = item(row,0);
		CWbqdStandardItemModel::ItemQDType typ = JudgeItemQDType(row);
		if(UnKnownType == typ)
			typ = typPre;
		pItem->setData(typ,Qt::UserRole+1);
	}

	//
	int nColXMMC = GetColumn(WBQD::kXMMC);
	//
	QStack<QStandardItem *> stackParent;
	for (int row = 0;row < rowCount();row++)
	{
		QStandardItem * pItem = item(row,0);
		PopUntilParent(stackParent,item(row,0));
		int typ = pItem->data(Qt::UserRole+1).toInt();

		//
		if (stackParent.isEmpty() == false)
		{
			QStandardItem * pParent = stackParent.top();
			QString strTmp = pParent->text();
			int typParent = pParent->data(Qt::UserRole+1).toInt();
			
			//解除row行 与 父节点关系
			QList<QStandardItem*> rowCells = takeRow(row);
			//qc:takeRow已经将那一行删除了，不可以在RemoveRow 会造成行的丢失
			//removeRow(row);
			row--;

			//重建只节点关系
			if(rowCells.size() > 0)
			{
				pParent->appendRow(rowCells);
			}
		}

		//
		if(typ != UnKnownType)
			stackParent.push(pItem);
	}
}

//
void CWbqdStandardItemModel::MergeSameXM()
{

}

int CWbqdStandardItemModel::InsertTableNewRow(int rowAt)
{
	//
	insertRow(rowAt);
	for(int col = 0;col < columnCount();col++)
	{
		setItem(rowAt, col, new QStandardItem(""));
		item(rowAt, col)->setTextAlignment(Qt::AlignCenter);
	}

	//
	return rowAt;
}

QStandardItem * CWbqdStandardItemModel::AppendNewRow(QStandardItem * pParent
													 ,const QString & xmmc
													 ,const QString & xmbm
													 ,const QString & xmtz
													 ,const QString & jldw)
{

	int nColXMBM = GetColumn(WBQD::kXMBM);
	int nColXMMC = GetColumn(WBQD::kXMMC);
	int nColXMTZ = GetColumn(WBQD::kXMTZ);
	int nColJLDW = GetColumn(WBQD::kJLDW);

	//
	QList<QStandardItem *> listItem;
	for(int col = 0;col < columnCount();col++)
	{
		QStandardItem * pItemNew = new QStandardItem("");
		pItemNew->setTextAlignment(Qt::AlignCenter);

		//
		if(col == nColXMBM)
			pItemNew->setText(xmbm);
		else if(col == nColXMMC)
		{
			pItemNew->setText(xmmc);
		}
		else if(col == nColXMTZ)
		{
			pItemNew->setText(xmtz);
		}
		else if(col == nColJLDW)
			pItemNew->setText(jldw);

		//
		listItem.append(pItemNew);
	}
	if (listItem.size() == 0)
	{
		return NULL;
	}

	//
	if(pParent)
		pParent->appendRow(listItem);
	else
		appendRow(listItem);

	//
	return listItem[0];
}

QStandardItem * CWbqdStandardItemModel::InsertNewRow(QStandardItem * pParent
													 ,int rowAt
													 ,const QString & xmmc
													 ,const QString & xmbm
													 ,const QString & xmtz
													 ,const QString & jldw)
{

	int nColXMBM = GetColumn(WBQD::kXMBM);
	int nColXMMC = GetColumn(WBQD::kXMMC);
	int nColXMTZ = GetColumn(WBQD::kXMTZ);
	int nColJLDW = GetColumn(WBQD::kJLDW);

	//
	QList<QStandardItem *> listItem;
	for(int col = 0;col < columnCount();col++)
	{
		QStandardItem * pItemNew = new QStandardItem("");
		pItemNew->setTextAlignment(Qt::AlignCenter);

		//
		if(col == nColXMBM)
			pItemNew->setText(xmbm);
		else if(col == nColXMMC)
		{
			pItemNew->setText(xmmc);
		}
		else if(col == nColXMTZ)
		{
			pItemNew->setText(xmtz);
		}
		else if(col == nColJLDW)
			pItemNew->setText(jldw);

		//
		listItem.append(pItemNew);
	}
	if (listItem.size() == 0)
	{
		return NULL;
	}

	//
	if(pParent)
		pParent->insertRow(rowAt,listItem);
	else
		insertRow(rowAt,listItem);

	//
	return listItem[0];
}


//插入新行
void CWbqdStandardItemModel::InsertAfterSelected(QAbstractItemView * pTableView)
{
	QItemSelectionModel * pSelectionModel = pTableView->selectionModel();

	//插入选中的行中最后一行之后
	int rowLast = rowCount();
	if(pSelectionModel->hasSelection())
	{
		QModelIndex indexCur = pTableView->currentIndex();
		QModelIndex indexParent = indexCur.parent();

		//插入到current节点的父节点下，位置位于current节点后面
		int nRowNext = indexCur.row()+1;
		QStandardItem * pItemParent = itemFromIndex(indexParent);

		//解决选中章节后增加行会崩溃的问题
		if(pItemParent == NULL)
		{
			//插入节点
			int row = InsertTableNewRow(nRowNext);

			//分析层级关系
			SetItemQDType(row,CWbqdStandardItemModel::Chapter);	
		}
		else
		{
			QStandardItem * pItemNew = InsertNewRow(pItemParent,nRowNext,"","","","");

			//分析层级关系
			CWbqdStandardItemModel::ItemQDType typParent = GetItemQDType(pItemParent);
			if(CWbqdStandardItemModel::Chapter == typParent)
				SetItemQDType(pItemNew,CWbqdStandardItemModel::QD);
			else
				SetItemQDType(pItemNew,CWbqdStandardItemModel::DE);
		}
		
	}
	else
	{
		//插入节点
		int row = InsertTableNewRow(rowLast);

		//分析层级关系
		SetItemQDType(row,CWbqdStandardItemModel::Chapter);		
	}
}

//删除
void CWbqdStandardItemModel::DeleteRowsSelected(QAbstractItemView * pTableView)
{
	QItemSelectionModel * pSelectionModel = pTableView->selectionModel();

	//插入选中的行中最后一行之后
	int rowLast = rowCount();
	if(pSelectionModel->hasSelection())
	{
		//获取所有选中行
		QModelIndexList indexList = pTableView->selectionModel()->selectedRows();
		if(indexList.length() > 1)
		{
			if(FALSE == IsSameLevel(indexList))
			{
				return;
			}
			for(int i = 0;i < indexList.length();i++)
			{
				QModelIndex indexCur = indexList[i];
				int rowCount = indexCur.row();			
				
				QModelIndex indexParent = indexCur.parent();
				removeRow(rowCount-i,indexParent);
			}
			
		}
		else
		{
			QModelIndex indexCur = pTableView->currentIndex();
			QModelIndex indexParent = indexCur.parent();
			removeRow(indexCur.row(),indexParent);
		}

	}
}

QStringList CWbqdStandardItemModel::GetXMTZ(int row) const
{
	int nColXMTZ = GetColumn(WBQD::kXMTZ);
	QString str;
	if (nColXMTZ >= 0)
	{
		str = item(row,nColXMTZ)->text();
	}

	//
	QStringList listXMTZ = GetXMTZ(str);
	return listXMTZ;
}

QStringList CWbqdStandardItemModel::GetXMTZ(QString xmtzContent)
{
	//
	QStringList listXMTZ = xmtzContent.split("\n");
	return listXMTZ;
}

void CWbqdStandardItemModel::SaveWbqdToDb_Level(CSQLDataSet * pDs,const int & parentId,QStandardItem * pItemCur,int levelItemCur)
{
	//
	int nColXMBM = GetColumn(WBQD::kXMBM);
	int nColXMMC = GetColumn(WBQD::kXMMC);
	int nColXMTZ = GetColumn(WBQD::kXMTZ);
	int nColJLDW = GetColumn(WBQD::kJLDW);

	CString strXMTZTag = _T("项目特征");
	//
	QModelIndex indexCur = pItemCur->index();
	PMTSTRING strTmp;
	
	//项目名称
	QModelIndex indexXMMC = index(indexCur.row(),nColXMMC,indexCur.parent());
	QStandardItem * pItemXMMC = itemFromIndex(indexXMMC);
	QString qstrXMMC = pItemXMMC->text();	strTmp = QStringTo(qstrXMMC);
	CString strXMMC = strTmp.c_str();

	//项目编码
	QModelIndex indexXMBM = index(indexCur.row(),nColXMBM,indexCur.parent());
	QStandardItem * pItemXMBM = itemFromIndex(indexXMBM);
	QString qstrXMBM = pItemXMBM->text();	strTmp = QStringTo(qstrXMBM);
	CString strXMBM = strTmp.c_str();

	//项目特征
	QModelIndex indexXMTZ = index(indexCur.row(),nColXMTZ,indexCur.parent());
	QStandardItem * pItemXMTZ = itemFromIndex(indexXMTZ);
	QString qstrXMTZ = pItemXMTZ->text();	strTmp = QStringTo(qstrXMTZ);
	CString strXMTZ = strTmp.c_str();

	//计量单位
	QModelIndex indexJLDW = index(indexCur.row(),nColJLDW,indexCur.parent());
	QStandardItem * pItemJLDW = itemFromIndex(indexJLDW);
	QString qstrJLDW = pItemJLDW->text();	strTmp = QStringTo(qstrJLDW);
	CString strJLDW = strTmp.c_str();

	//新增行并设置关键列内容
	int nRowNew = pDs->InsertRow(0);
	int nId = pDs->GetRowCount();
	CString strId = pmcommon::CStr(nId);
	pDs->SetAsString(CProject_QD_WBTable::CFieldInfo::qdde_id,nRowNew,strId);
	CString strValue = pmcommon::CStr(parentId);
	pDs->SetAsString(CProject_QD_WBTable::CFieldInfo::qdde_parent,nRowNew,strValue);
	//strValue = pmcommon::CStr(levelItemCur);
	//int typCurrent = pItemCur->data(Qt::UserRole+1).toInt();
	//QC;28358,由于类型很容易被破坏，重新判断类型
	int typCurrent = JudgeItemQDType(pItemXMMC,pItemXMBM,pItemJLDW);
	strValue = pmcommon::CStr(typCurrent);
	pDs->SetAsString(CProject_QD_WBTable::CFieldInfo::qdde_level,nRowNew,strValue);
	pDs->SetAsString(CProject_QD_WBTable::CFieldInfo::qdde_name,nRowNew,strXMMC);
	pDs->SetAsString(CProject_QD_WBTable::CFieldInfo::qdde_code,nRowNew,strXMBM);
	pDs->SetAsString(CProject_QD_WBTable::CFieldInfo::qdde_unit,nRowNew,strJLDW);
	if (strXMTZ.IsEmpty() == false)
	{
		pDs->SetAsString(CProject_QD_WBTable::CFieldInfo::qdde_attr,nRowNew,strXMTZTag);
		pDs->SetAsString(CProject_QD_WBTable::CFieldInfo::qdde_att_content,nRowNew,strXMTZ);
	}

	//遍历子类
	for (int row = 0;row < pItemCur->rowCount();row++)
	{
		QStandardItem * pItemChild = pItemCur->child(row,0);
		if (pItemChild)
		{
			SaveWbqdToDb_Level(pDs,nId,pItemChild,levelItemCur + 1);
		}
	}
}

void CWbqdStandardItemModel::SaveWbqdToDb()
{
	CAccessProject_QD_WBTable wbqdTable;
	wbqdTable.DeleteAllRow();

	//
	int nColXMBM = GetColumn(WBQD::kXMBM);
	int nColXMMC = GetColumn(WBQD::kXMMC);
	int nColXMTZ = GetColumn(WBQD::kXMTZ);
	int nColJLDW = GetColumn(WBQD::kJLDW);

	//保存外部清单
	int nLevelCur = 0;
	CSQLDataSet * pDs = wbqdTable.GetEmptyDataSet();
	for (int i = 0;i < rowCount();i++)
	{
		SaveWbqdToDb_Level(pDs,NULL,item(i,0),nLevelCur);
	}

	//
	pDs->DoSqlUpdate();
}

void CWbqdStandardItemModel::ReadWbqdFromDb()
{
	CAccessProject_QD_WBTable wbqdTable;
	CSQLDataSet * pDs = wbqdTable.GetDataSet();

	//
	QStandardItem * pItemParent = NULL;
	std::map<int,QStandardItem *> mapId2Item;
	for (int row = 1;row <= pDs->GetRowCount();row++)
	{
		CString strId = pDs->GetAsString(CProject_QD_WBTable::CFieldInfo::qdde_id,row);
		int nId = _ttoi(strId);
		CString strParentId = pDs->GetAsString(CProject_QD_WBTable::CFieldInfo::qdde_parent,row);
		int nParentId = _ttoi(strParentId);
		CString strLevel = pDs->GetAsString(CProject_QD_WBTable::CFieldInfo::qdde_level,row);
		int nLevel = _ttoi(strLevel);
		PMTSTRING strXMMC = pDs->GetAsString(CProject_QD_WBTable::CFieldInfo::qdde_name,row);
		PMTSTRING strXMBM = pDs->GetAsString(CProject_QD_WBTable::CFieldInfo::qdde_code,row);
		PMTSTRING strJLDW = pDs->GetAsString(CProject_QD_WBTable::CFieldInfo::qdde_unit,row);
		PMTSTRING strXMTZ = pDs->GetAsString(CProject_QD_WBTable::CFieldInfo::qdde_att_content,row);

		//
		QString qstrXMMC = QStringFrom(strXMMC);
		QString qstrXMBM = QStringFrom(strXMBM);
		QString qstrJLDW = QStringFrom(strJLDW);
		QString qstrXMTZ = QStringFrom(strXMTZ);
		std::map<int,QStandardItem *>::iterator iter = mapId2Item.find(nParentId);

		//
		QStandardItem * pItemNew = NULL;
		if (iter != mapId2Item.end())
		{
			QStandardItem * pParent = iter->second;
			pItemNew = AppendNewRow(pParent,qstrXMMC,qstrXMBM,qstrXMTZ,qstrJLDW);

		}
		else
		{
			pItemNew = AppendNewRow(NULL,qstrXMMC,qstrXMBM,qstrXMTZ,qstrJLDW);
		}

		//
		if (NULL != pItemNew)
		{
			pItemNew->setData(nLevel,Qt::UserRole+1);
			mapId2Item.insert(std::make_pair(nId,pItemNew));
		}
	}
	//
	PMDelete(pDs);
}

QVariant CWbqdStandardItemModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QStandardItemModel::data(index,role);
	
	CWbqdStandardItemModel *item = static_cast<CWbqdStandardItemModel*>(index.internalPointer());
	if (role == Qt::DisplayRole)
	{
		QStandardItem * item = CWbqdStandardItemModel::itemFromIndex(index); 
		return	item->text();
		
	}
	else if( role == Qt::TextAlignmentRole )
	{
		QString colName = m_mapCol2Name[index.column()];
		if( index.column() == 0 || WBQD::kXMMC == colName || WBQD::kXMTZ == colName)
		{
			//第1列左对齐
			return QVariant(Qt::AlignVCenter | Qt::AlignLeft);
		}
		else
		{
			//其他列居中对齐
			return QVariant(Qt::AlignCenter);
		}
	}
	else if(role == Qt::BackgroundRole)
	{
		if(index.parent().row() == -1)
		{
			return QVariant(QColor("#F4A460"));//沙棕色
		}
		else if (index.parent().parent().row() == -1)
		{
			return QVariant(QColor("#FFDEAD"));//纳瓦霍白
		}
		else if(index.parent().parent().parent().row() == -1)
		{
			return QVariant(QColor("#EEE8AA"));//灰秋麒麟
		}
		else if(index.parent().parent().parent().parent().row() == -1)
		{
			return QVariant(QColor("#FFFFBB"));//
		}
		else 
		{
			return QVariant(QColor("#FFFFF0"));//象牙色
		}
	}
	//else
	//{
	//	QString str = QString::number(role);
	//	QMessageBox::about(NULL,"aaaa",str);
	//}

	//
	return QStandardItemModel::data(index,role);
}

BOOL CWbqdStandardItemModel::IsSameLevel(QModelIndexList indexList)
{
	if(indexList.length() == 0)
		return TRUE;

	int iConutPre = -1;
	for(int i = 0;i < indexList.length();i++)
	{
		QModelIndex indexCur = indexList[i];
		AcArray<int> rowArr;
		rowArr.append(indexCur.row());
		//获取点击行存处于第几层级
		for(int i =0;i < m_iLimit ;i++)
		{
			QModelIndex indexConut = indexCur.parent();
			rowArr.append(indexConut.row());
			if(indexConut.row() == -1)
			{
				break;
			}	
			indexCur = indexConut;
		}
		int iCont = rowArr.length();
		if(iConutPre == -1)
		{
			iConutPre = iCont;
		}
		else if(iConutPre != iCont)
		{
			return FALSE;
		}
	}
	return TRUE;

}

void CXMMC_XMTZAnalyse::SplitXMMC_XMTZ(const QString xmmc_Xmtz,QString & xmmc,QString & xmtz)
{
	QString strXmmc_Xmtz = xmmc_Xmtz;
	PmQtFun::TrimEnter(strXmmc_Xmtz);
	int idx = strXmmc_Xmtz.indexOf("\n");
	if (idx > 0)
	{
		xmmc = strXmmc_Xmtz.mid(0,idx);
		xmtz = strXmmc_Xmtz.mid(idx+1);
	}
	else
	{
		xmmc = xmmc_Xmtz;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//CXMTZAnalyse 类:项目特征字符串分析与组合
//////////////////////////////////////////////////////////////////////////////////////////////
void CXMTZAnalyse::SetXMTZ(const QString & xmtz)
{
	m_listXMTZ.clear();
	m_listValue.clear();

	//
	QString strXMTZ_Full = xmtz;
	PmQtFun::TrimEnter(strXMTZ_Full);
	QStringList listRow = strXMTZ_Full.split("\n");
	if (listRow.size() == 0)
	{
		return;
	}
	//

	//项目特征内部拆分
	QString strChrReplaced = QObject::tr("：");
	for(int i = 0;i < listRow.size();i++)
	{
		QString strValue = listRow[i];
		PmQtFun::TrimEnter(strValue);
		QString strReplace = strValue.replace(strChrReplaced,":");
		int idxFind = strValue.indexOf(":");
		if (idxFind >= 0)
		{
			QString strXMTZName = strValue.mid(0,idxFind);
			QString strXMTZValue = strValue.mid(idxFind+1);
			//
			m_listXMTZ.append(strXMTZName);
			m_listValue.append(strXMTZValue);
		}
		else
		{
			m_listXMTZ.append(strValue);
			m_listValue.append("");
		}
	}
}

QString CXMTZAnalyse::GetXMTZ() const
{
	QString strXMTZAll;
	for(int i = 0;i < m_listXMTZ.size();i++)
	{
		QString strXMTZName = m_listXMTZ[i];
		QString strValue = m_listValue[i];
		
		//
		if(0 == i)
			strXMTZAll = strXMTZName + ":" + strValue;
		else
			strXMTZAll += "\n" + strXMTZName + ":" + strValue;
	}

	//
	return strXMTZAll;
}

void CXMTZAnalyse::GetXMTZ(QStringList & listXMTZ,QStringList & listValue) const
{
	listXMTZ.clear();
	listValue.clear();

	//
	listXMTZ = m_listXMTZ;
	listValue = m_listValue;
}

//生成项目特征的表-----用于写入数据库用
CQDAttTable * CXMTZAnalyse::GetTable() const
{
	return NULL;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//CXMTZStandardItemModel 类:项目特征模型
//////////////////////////////////////////////////////////////////////////////////////////////
void CXMTZStandardItemModel::SetXMTZ(const QString & xmtz)
{
	this->removeRows(0,rowCount());
	m_strXMTZOrign = xmtz;

	//
	CXMTZAnalyse analyser;
	analyser.SetXMTZ(xmtz);
	QStringList listXMTZ,listValue;
	analyser.GetXMTZ(listXMTZ,listValue);

	//设置项目特征表格
	for (int row = 0;row < listXMTZ.size();row++)
	{
		QString strXMTZName = listXMTZ[row];
		QString strValue = listValue[row];

		//
		setItem(row,0,new QStandardItem(strXMTZName));
		setItem(row,1,new QStandardItem(strValue));
		//item(row, 0)->setTextAlignment(Qt::AlignCenter);
		//item(row, 1)->setTextAlignment(Qt::AlignCenter);
	}
}

QString CXMTZStandardItemModel::GetXMTZ() const
{
	if(columnCount() < 2)
		return m_strXMTZOrign;

	//
	bool bOk = true;
	QString strXMTZAll;
	for (int row = 0;row < rowCount();row++)
	{
		if(item(row,0) && item(row,1))
		{
			QString strXMTZName = item(row,0)->text();
			QString strValue = item(row,1)->text();

			//
			if(0 == row)
				strXMTZAll = strXMTZName + ":" + strValue;
			else
				strXMTZAll += "\n" + strXMTZName + ":" + strValue;
		}
		else
		{
			bOk = false;
			break;
		}
	}

	if(false == bOk)
		return m_strXMTZOrign;
	//
	return strXMTZAll;
}

