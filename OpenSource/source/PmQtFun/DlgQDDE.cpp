#include "StdAfx.h"
#include "DlgQDDE.h"
#include <afxcoll.h>
#include <QMessageBox>

CDlgQDDE::CDlgQDDE(QStandardItemModel * pModelQDDE,QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	InitTreeDE();
	InitTreeQD();
	ui.comboBox_DE->setEditable(TRUE);
	ui.comboBox_QD->setEditable(TRUE);
	qstrListBoxQD.clear();
	qstrListBoxDE.clear();

	//
	m_pParentQDDE = pModelQDDE;
	QObject::connect(this,SIGNAL(signal_AddDE(const WBQD*)),pModelQDDE,SLOT(OnAddDE(const WBQD*)),Qt::DirectConnection);;
	QObject::connect(this,SIGNAL(signal_AddQD(const WBQD*)),pModelQDDE,SLOT(OnAddQD(const WBQD*)),Qt::DirectConnection);;
	
	//ui.pushButton_Search_DE->setFocus();    //设置默认焦点
	//ui.pushButton_Search_DE->setShortcut( QKeySequence::InsertParagraphSeparator );  //设置快捷键为键盘的“回车”键
	//ui.pushButton_Search_DE->setShortcut(Qt::Key_Enter);  //设置快捷键为enter键
	//ui.pushButton_Search_DE->setShortcut(Qt::Key_Return); //设置快捷键为小键盘上的enter键
	
}

CDlgQDDE::~CDlgQDDE()
{

}

void CDlgQDDE::InitTreeDE()
{
	CAccessDEData_ChapterTable deChapterTable;
	NDataModelDataSet * pDataSet_DE = deChapterTable.GetDataSet();

	if(NULL == pDataSet_DE)
	{
		UIFunction::PMMessageBox(_T("定额库 加载失败!"));
	}

	m_pModelDE = new QStandardItemModel(ui.treeView_DE_Top);
	m_pModelDE->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit("定额章节"));

	//整理数据库中的数据选择插入节点
	SelectData(pDataSet_DE,_T("chapter"),_T("chaptername"),m_pModelDE);

	//设置为不可编辑状态
	ui.treeView_DE_Top->setEditTriggers(0);
	ui.treeView_DE_Top->setModel(m_pModelDE);

}

void CDlgQDDE::InitTreeQD()
{
	CAccessQDData_RuleIndex_mTable qdDataRuleTable;
	NDataModelDataSet * pDataSetQD = qdDataRuleTable.GetDataSet();

	if(NULL == pDataSetQD)
	{
		//UIFunction::PMMessageBox(_T("清单库 加载失败!"));
		ui.tabWidget->removeTab(0);
		return;
	}
	m_pModelQD = new QStandardItemModel(ui.treeView_QD_Top);
	m_pModelQD->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit("清单章节"));
	
	//整理数据库中的数据选择插入节点
	SelectData(pDataSetQD,_T("nodeid"),_T("nodename"),m_pModelQD);

	//按钮默认选中定额
	ui.radioButtonQD_DE->setChecked(TRUE);
	ui.radioButtonQD_QD->setChecked(FALSE);

	//设置为不可编辑状态
	ui.treeView_QD_Top->setEditTriggers(0);
	ui.treeView_QD_Top->setModel(m_pModelQD);
	
}


void CDlgQDDE::SelectData(NDataModelDataSet * pSQLDataSet,CString strId,CString strName,QStandardItemModel * &m_pModel)
{
	CString strChapterpre;	
	CString strChapter;
	CString strChapterName;
	
	QStandardItem* item1,*item2,*item3,*item4;
	
	int iLayer = 0;
	for (int i =0 ;i < pSQLDataSet->GetRowCount();i++)
	{	
		strChapter =  pSQLDataSet->GetAsString(strId,i+1);
		strChapterName = pSQLDataSet->GetAsString(strName,i+1);

		if (strChapterpre.GetLength() == NULL || strChapterpre.GetLength() < strChapter.GetLength())
		{
			iLayer++;
		}			
		if(strChapterpre.GetLength() > strChapter.GetLength())
		{
			int iLength=0;
			iLength = strChapterpre.GetLength() - strChapter.GetLength();
			switch (iLength)
			{
			case 2:
			case 3:
				iLayer = iLayer-1;
				break;
			case 4:
			case 5:
				iLayer = iLayer-2;
				break;
			case 7:
				iLayer = iLayer-3;
				break;
			default:
				continue;
			}	
		}
		if (iLayer == 1)
			AddNode(strChapterName,strChapter,m_pModel,item1);
		else if(iLayer == 2)
			AddNode(strChapterName,strChapter,item1,item2);	
		else if(iLayer == 3)
			AddNode(strChapterName,strChapter,item2,item3);	
		else if (iLayer == 4)
			AddNode(strChapterName,strChapter,item3,item4);

		strChapterpre = strChapter;
	}
}

//添加到树形图的第一级节点
void CDlgQDDE::AddNode(CString strChapterName,CString strChapter,QStandardItemModel * m_pModel,QStandardItem *&itemChildren )
{
 
	itemChildren = new QStandardItem(CStringToQString(strChapterName));
	//增加标记数据用于搜索
	itemChildren->setData(QVariant(CStringToQString(strChapter)),Qt::UserRole + 1);

	m_pModel->appendRow(itemChildren);
}

//添加到树形图的一级之后的子节点
void CDlgQDDE::AddNode(CString strChapterName,CString strChapter,QStandardItem *&itemParent,QStandardItem *&itemChildren)
{

	itemChildren = new QStandardItem(CStringToQString(strChapterName));
	//增加标记数据用于搜索
	itemChildren->setData(QVariant(CStringToQString(strChapter)),Qt::UserRole + 1);
	itemParent->appendRow(itemChildren);
	 
}

//点击定额树触发事件---获取此树节点的定额信息
void CDlgQDDE::On_ClickedTree_View_DE(const QModelIndex &index)
{
	//QString strName = ui.treeView_DE_Top->model()->itemData(index).values()[0].toString();

	//取附带的data----用于搜索定额详细信息
	QVariant data = index.data(Qt::UserRole+1);
	QString qstr = data.toString();

	QStandardItemModel *m_pModelListDE = new QStandardItemModel(ui.listView_DE_Bottom);

	CAccessDEData_RationTable deRationTable;
	CPMSQLTableCtrl * pSQLTableCtrl = NULL;
	if(!deRationTable.GetTableCtrl_Chapter(QStringToCString(qstr),pSQLTableCtrl))
		return;

	while (pSQLTableCtrl->TableNextRow())
	{
		int iID = 0;
		pSQLTableCtrl->GetAsInterger(CDERationTable::CFieldInfo::id,iID);

		CString strName;
		pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::subname,strName);

		CString strCha;
		pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::denumber,strCha);

		CString strUnit;
		pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::unit,strUnit);
		strName = _T("[") + strCha + _T("]	") + strName;
		QStandardItem * itemChild;
		InsertTreeItem(m_pModelListDE,itemChild,iID,strName,strUnit);
	}
	
	//设置为不可编辑状态
	ui.listView_DE_Bottom->setEditTriggers(0);
	ui.listView_DE_Bottom->setModel(m_pModelListDE);
	
}

//点击清单树触发事件
void CDlgQDDE::On_ClickedTree_View_QD(const QModelIndex &index)
{
	//QString strName = ui.treeView->model()->itemData(index).values()[0].toString();

	//取附带的data----用于搜索清单详细信息
	QVariant data = index.data(Qt::UserRole+1);
	QString qstr = data.toString();

	m_pModel_List_QD = new QStandardItemModel(ui.treeView_QD_Bottom);

	CAccessQDData_BillTable qdDataBillTable;
	CPMSQLTableCtrl * pSQLTableCtrl = NULL;

	if(!qdDataBillTable.GetTableCtrl_QDNumber(QStringToCString(qstr),pSQLTableCtrl))
		return;
	if(!pSQLTableCtrl->TableNextRow())
	{
		PMDelete(pSQLTableCtrl);
		return;
	}
	CString strChapter = _T("");
	pSQLTableCtrl->GetAsString(CQDBillTable::CFieldInfo::dechapter,strChapter);
	PMDelete(pSQLTableCtrl);

	if(strChapter != _T(""))
		BuildQDListTree(strChapter);

	//按钮设置为选中定额
	ui.radioButtonQD_DE->setChecked(TRUE);
	ui.radioButtonQD_QD->setChecked(FALSE);

	//设置为不可编辑状态
	ui.treeView_QD_Bottom->setEditTriggers(0);
	ui.treeView_QD_Bottom->setModel(m_pModel_List_QD);
	//表头隐藏
	ui.treeView_QD_Bottom->setHeaderHidden(TRUE);
	//展开所有节点
	ui.treeView_QD_Bottom->expandAll();
	//设置水平滚动条自适应
	ui.treeView_QD_Bottom->resizeColumnToContents(0); 
	
}

void CDlgQDDE::BuildQDListTree(CString strValue)
{
		
	CString strDeKuName;
	{
		CAccessProject_ProjectInfoTable projectInfoTable;
		projectInfoTable.GetProjectDEBaseName(strDeKuName);
	}

	CAccessQDData_ProjectCodeTable qdDataProjectTable;
	if(!qdDataProjectTable.CheckNeedXHL_DE( strDeKuName ))
		return;
	
	//7-10~7-20,7-44;////情况2
	CStringArray str1Array;
	str1Array.RemoveAll();
	SplitCString(strValue,str1Array,_T(';'));

	int iSize = str1Array.GetSize();
	for(int i = 0;i < iSize;i++)
	{
		CStringArray str2Array;
		SplitCString(str1Array.GetAt(i),str2Array,_T('$'));

		int iArraySize = str2Array.GetSize();
		if (iArraySize > 2)
		{
			UIFunction::PMMessageBox(_T("章节编号出错,") + strValue);
			return;
		}	
		CStringArray str3Array;
		if (iArraySize == 2)
		{	
			QStandardItem *item1;
			InsertTreeItem(m_pModel_List_QD,item1,0,str2Array.GetAt(0),_T(""));
			/// 
			CString strItemValue = str2Array.GetAt(1) ;

			if ( -1 != strItemValue.Find( _T("||")) )
			{
				CStringArray aryValue4 ;
				SplitCString( strItemValue , aryValue4 , _T("||") ) ;

				int j = 0 ; 
				for ( ; j < aryValue4.GetSize() ; ++j )
				{
					/// 
					CString strValue4 = aryValue4.GetAt(j) ; 
					/// 
					CStringArray aryValue5 ;
					SplitCString( strValue4 , aryValue5 , _T("##") ) ;

					/// 
					if ( aryValue5.GetSize() != 2 )
					{
						continue; 
					}
					///	
					QStandardItem *item2;				
					InsertTreeItem(item1,item2,0,aryValue5.GetAt(0),_T(""));
				 
					str3Array.RemoveAll() ; 
					CompositorChapterArray(aryValue5.GetAt(1),str3Array);
					InsertXhlItem( item2 , str3Array ) ;
				}
			}
			else 
			{
				str3Array.RemoveAll() ; 
				CompositorChapterArray(str2Array.GetAt(1),str3Array);
				InsertXhlItem( item1 , str3Array ) ;
			}			
		}
		else
		{
			str3Array.RemoveAll() ;
			CompositorChapterArray(str2Array.GetAt(0),str3Array);
			InsertXhlItem( m_pModel_List_QD,str3Array );
		}
	}	
}

void CDlgQDDE::CompositorChapterArray(CString strValue, CStringArray &strChapterArray)
{//2-10~2-20,3-10
	if (strValue == _T(""))
		return;
	CStringArray str1Array,str2Array;
	//先将','分离
	SplitCString(strValue,str1Array,_T(','));

	int i1ArraySize = str1Array.GetSize();
	for (int i = 0;i < i1ArraySize;i++)
	{	
		//将'~'连续章节分离
		str2Array.RemoveAll();
		SplitCString(str1Array.GetAt(i),str2Array,_T('~'));
		if(str2Array.GetSize() == 2)
		{
			CString strMin = str2Array.GetAt(0);
			CStringArray str3Array;
			SplitCString(strMin,str3Array,_T('-'));
		
			int iMin = _ttoi(str3Array.GetAt(str3Array.GetSize() - 1));

			str3Array.RemoveAll();

			CString strMax = str2Array.GetAt(1);

			SplitCString(strMax,str3Array,_T('-'));
		
			int iMax = _ttoi(str3Array.GetAt(str3Array.GetSize() - 1));

			if(str3Array.GetSize() == 1)
			{
				CString strTemValue = str3Array.GetAt(str3Array.GetSize() - 1);
				for (int j = iMin;j <= iMax;j++)
				{
					CString strChapterValue;
					strChapterValue.Format(_T("%d"),j);
					for (;strTemValue.GetLength() > strChapterValue.GetLength();)
					{
						strChapterValue = _T("0") + strChapterValue;
					}
					strChapterArray.Add(strChapterValue);
				}
			}
			else
			{
				CString strChapter = _T("");
				int j = 0;
				for (j = 0;j < str3Array.GetSize() - 1;j++)
				{
					strChapter += str3Array.GetAt(j);
					if(j < str3Array.GetSize() - 2)
						strChapter += _T("-");
				}
				if(strChapter.GetLength())
					strChapter += _T("-");
				for (j = iMin;j <= iMax;j++)
				{
					CString strChapterValue;
					strChapterValue.Format(_T("%s%d"),strChapter,j);
					strChapterArray.Add(strChapterValue);
				}
			}
		}
		else
			strChapterArray.Add(str2Array.GetAt(0));
	}
}


void CDlgQDDE::InsertXhlItem(QStandardItem * itemParent,CStringArray & aryXhl)
{
	CPMSQLTableCtrl * pDERationTableCtrl = NULL;
	CAccessDEData_RationTable deRationTable;
	if(!deRationTable.GetTableCtrl_DeNumber(aryXhl,pDERationTableCtrl))
		return;
	while(pDERationTableCtrl->TableNextRow())
	{
		CString strChapter;
		pDERationTableCtrl->GetAsString(CDERationTable::CFieldInfo::denumber,strChapter);
		CString strName;
		pDERationTableCtrl->GetAsString(CDERationTable::CFieldInfo::subname,strName);
		CString strUnit;
		pDERationTableCtrl->GetAsString(CDERationTable::CFieldInfo::unit,strUnit);
		int iID = 0;
		pDERationTableCtrl->GetAsInterger(CDERationTable::CFieldInfo::id,iID);
		strName = _T("[") + strChapter + _T("]") + strName;
		QStandardItem * itemChild;
		InsertTreeItem(itemParent,itemChild,iID,strName,strUnit);
	}
	PMDelete(pDERationTableCtrl);
}

void CDlgQDDE::InsertXhlItem(QStandardItemModel * &itemParent,CStringArray & aryXhl)
{
	CPMSQLTableCtrl * pDERationTableCtrl = NULL;
	CAccessDEData_RationTable deRationTable;
	if(!deRationTable.GetTableCtrl_DeNumber(aryXhl,pDERationTableCtrl))
		return;
	while(pDERationTableCtrl->TableNextRow())
	{
		CString strChapter;
		pDERationTableCtrl->GetAsString(CDERationTable::CFieldInfo::denumber,strChapter);
		CString strName;
		pDERationTableCtrl->GetAsString(CDERationTable::CFieldInfo::subname,strName);
		CString strUnit;
		pDERationTableCtrl->GetAsString(CDERationTable::CFieldInfo::unit,strUnit);
		int iID = 0;
		pDERationTableCtrl->GetAsInterger(CDERationTable::CFieldInfo::id,iID);
		strName = _T("[") + strChapter + _T("]") + strName;
		QStandardItem * itemChild;
		InsertTreeItem(itemParent,itemChild,iID,strName,strUnit);
	}
	PMDelete(pDERationTableCtrl);
}


void CDlgQDDE::OnBtnDe()
{
	QString qstrText = ui.comboBox_DE->currentText();

	if ( qstrText.isEmpty())
	{
		return ;
	}
	BOOL bValue = TRUE;
	for(int i = 0;i < qstrListBoxDE.length();i++)
	{
		if (qstrListBoxDE.at(i).compare(qstrText) == 0)
		{
			bValue = FALSE;
		}
		QString ssss = qstrListBoxDE.at(i);
	}
	if(qstrListBoxDE.empty() == TRUE|| bValue)
	{
		qstrListBoxDE.push_back(qstrText);
		if(!bEnter)
		{
			ui.comboBox_DE->addItem(qstrText);
		}	
	}

	QStandardItemModel *m_pModel = new QStandardItemModel(ui.listView_DE_Bottom);

	QStandardItem *itemChild;

	CPMSQLTableCtrl * pSQLTableCtrl = NULL;
	CAccessDEData_RationTable deRationTable;
	if(!deRationTable.GetAllRow_TableCtrl(pSQLTableCtrl))
		return;

	CString strChapter = _T("");

	while(pSQLTableCtrl->TableNextRow())
	{
		CString strNodeID;
		pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::chapter,strNodeID);
		CString strName;
		pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::subname,strName);
		CString strCha;
		pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::denumber,strCha);

		strChapter = QStringToCString(qstrText);

		if ( strCha.Find(strChapter) != -1 || strName.Find(strChapter) != -1 )
		{
			int iID = 0;
			pSQLTableCtrl->GetAsInterger(CDERationTable::CFieldInfo::id,iID);

			CString strUnit;
			pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::unit,strUnit);

			strName = _T("[") + strCha + _T("]	") + strName;
			InsertTreeItem(m_pModel,itemChild,iID,strName,strUnit);
		}
	}
	PMDelete( pSQLTableCtrl ) ;
	bEnter = FALSE;
	ui.listView_DE_Bottom->setEditTriggers(0);
	ui.listView_DE_Bottom->setModel(m_pModel);
}

	
void CDlgQDDE::OnBtnQd()
{
	QString qstrText = ui.comboBox_QD->currentText();
	if(ui.radioButtonQD_QD->isChecked() == FALSE)
	{
		SelectDe(qstrText,ui.treeView_QD_Bottom);
	}
	else
	{
		SelectQd(qstrText,ui.treeView_QD_Bottom);
	}
	
}

void CDlgQDDE::SelectDe(QString strText,QTreeView * treeView)
{
	if ( strText.isEmpty())
	{
		return ;
	}

	BOOL bValue = TRUE;
	for(int i = 0;i < qstrListBoxQD.length();i++)
	{
		if (qstrListBoxQD.at(i).compare(strText) == 0)
		{
			bValue = FALSE;
		}
	}
	if(qstrListBoxQD.empty() == TRUE|| bValue)
	{
		qstrListBoxQD.push_back(strText);
		if(!bEnter)
		{
			ui.comboBox_QD->addItem(strText);
		}	
	}

	QStandardItemModel *m_pModel = new QStandardItemModel(treeView);
	QStandardItem *itemChild;

	CPMSQLTableCtrl * pSQLTableCtrl = NULL;
	CAccessDEData_RationTable deRationTable;
	if(!deRationTable.GetAllRow_TableCtrl(pSQLTableCtrl))
		return;

	CString strChapter = _T("");

	while(pSQLTableCtrl->TableNextRow())
	{
		CString strNodeID;
		pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::chapter,strNodeID);
		CString strName;
		pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::subname,strName);
		CString strCha;
		pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::denumber,strCha);

		CString str = QStringToCString(strText);
		str.TrimLeft();
		str.TrimRight();

		if ( strCha.Find(str) != -1 || strName.Find(str) != -1 )
		{
			int iID = 0;
			pSQLTableCtrl->GetAsInterger(CDERationTable::CFieldInfo::id,iID);

			CString strUnit;
			pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::unit,strUnit);

			strName = _T("[") + strCha + _T("]	") + strName;
			InsertTreeItem(m_pModel,itemChild,iID,strName,strUnit);
		}
	}
	PMDelete( pSQLTableCtrl ) ;

	//设置为不可编辑
	treeView->setEditTriggers(0);
	treeView->setModel(m_pModel);
	//设置表头隐藏
	treeView->setHeaderHidden(TRUE);
	//设置横向滚动条
	treeView->resizeColumnToContents(0);
	
		
}

void CDlgQDDE::SelectQd(QString strText,QTreeView * treeView)
{
	if ( strText.isEmpty())
	{
		return ;
	}

	BOOL bValue = TRUE;
	for(int i = 0;i < qstrListBoxQD.length();i++)
	{
		if (qstrListBoxQD.at(i).compare(strText) == 0)
		{
			bValue = FALSE;
		}
	}
	if(qstrListBoxQD.empty() == TRUE|| bValue)
	{
		qstrListBoxQD.push_back(strText);
		if(!bEnter)
		{
			ui.comboBox_QD->addItem(strText);
		}	
	}

	QStandardItemModel *m_pModel = new QStandardItemModel(treeView);
	QStandardItem *itemChild;

	CAccessQDData_RuleIndex_mTable ruleIndexTable ;
	CSQLDataSet  * pRuleIndexTable = ruleIndexTable.GetDataSet() ; 
	/// 
	if ( NULL == pRuleIndexTable )
	{
		return ;
	}
	/// 循环每一行，插入匹配的清单
	int iRowCount = pRuleIndexTable->GetRowCount() ; 

	/// 
	int i = 1 ; 
	for ( ; i <= iRowCount ; ++ i )
	{
		//获取清单的ID
		CString strQdid = pRuleIndexTable->GetAsString( CQDRuleIndex_mTable::CFieldInfo::qdid , i ) ;
		/// 获取节点名
		CString strNodeName = pRuleIndexTable->GetAsString( CQDRuleIndex_mTable::CFieldInfo::nodename , i ) ;
		if ( strQdid.IsEmpty() || strNodeName.IsEmpty() )
		{
			continue ; 
		}

		if ( strQdid.Find( QStringToCString(strText)) != -1 
			|| strNodeName.Find(QStringToCString(strText)) != -1 )
		{
			/// 获取节点ID
			int iId = pRuleIndexTable->GetAsInteger( CQDRuleIndex_mTable::CFieldInfo::id , i ) ;
			/// 获取单位
			CString strUnit= pRuleIndexTable->GetAsString( CQDRuleIndex_mTable::CFieldInfo::unit , i ) ;

			//获取nodeID
			CString strNodeID = pRuleIndexTable->GetAsString(CQDRuleIndex_mTable::CFieldInfo::nodeid, i);

			/// 插入清单
			AddNode(strNodeName,strNodeID,m_pModel,itemChild);
		}			
	} 
	PMDelete( pRuleIndexTable );

	//设置为不可编辑
	treeView->setEditTriggers(0);
	treeView->setModel(m_pModel);
	//设置表头隐藏
	treeView->setHeaderHidden(TRUE);
	//设置横向滚动条
	treeView->resizeColumnToContents(0);

}

void CDlgQDDE::On_ClickedRadioButton_DE()
{
	ui.treeView_QD_Bottom->setModel(NULL);

}
void CDlgQDDE::On_ClickedRadioButton_QD()
{
	ui.treeView_QD_Bottom->setModel(NULL);
}

//双击清单树触发事件----预留出接口
void CDlgQDDE::On_DoubleClickedTree_View_QD(const QModelIndex &index)
{
	
	//取附带的data----用于搜索定额信息
	QVariant data = index.data(Qt::UserRole+1);
	QString strID = data.toString();
	if(strID.length() < 9)
		return;

	CAccessQDData_QDAttTable qdxmAttTable;
	CSQLDataSet * pSQLdataSet = NULL;

	//获取项目特征
	if(!qdxmAttTable.GetDataSet_QDNumber(QStringToCString(strID),pSQLdataSet))
		return;
	//UIFunction::TraceDataSet_HTML( pSQLdataSet , _T("d:\\DataSet_TZ_1.html") ) ;

	int row = pSQLdataSet->GetRowCount();
	if(row == 0)
		return;
	CString strXMTZ =_T("");
	for(int i = 1;i <=row ; i++)
	{
		CString strName;
		strName = pSQLdataSet->GetAsString(CProject_QDXMAttTable::CFieldInfo::parmdisplayname,i);
		if(strXMTZ == _T(""))
		{
			strXMTZ = strName;
		}
		else
		{
			strXMTZ += _T("\n") + strName;
		}
		
	}
	//获取 编号/名称/单位
	CAccessQDData_RuleIndex_mTable qdDataRuleTable;
	CPMSQLTableCtrl * pSQLTableCtrl = NULL;
	qdDataRuleTable.GetTableCtrl_NodeID(QStringToCString(strID),pSQLTableCtrl);
	if(pSQLTableCtrl == NULL)
		return;

	CString strName;
	CString strUnit;

	while(pSQLTableCtrl->TableNextRow())
	{		
		pSQLTableCtrl->GetAsString(CQDRuleIndex_mTable::CFieldInfo::nodename,strName);
		pSQLTableCtrl->GetAsString(CQDRuleIndex_mTable::CFieldInfo::unit,strUnit);

		CStringArray strArr;
		int idxFind = strName.FindOneOf(_T(" "));
		if (idxFind >= 0)
		{
			CString strBM = strName.Mid(0,idxFind);	strBM.Trim();
			CString strMC = strName.Mid(idxFind);	strMC.Trim();
			AddQDRule(strXMTZ,strBM,strMC,strUnit);
		}
	}

	//按钮设置为选中定额
	ui.radioButtonQD_DE->setChecked(TRUE);
	ui.radioButtonQD_QD->setChecked(FALSE);

	PMDelete(pSQLdataSet);
	PMDelete(pSQLTableCtrl);
}

//双击定额列表触发事件-----预留出接口
void CDlgQDDE::On_DoubleClickedList_View_DE(const QModelIndex &index)
{

	//取附带的data----用于搜索定额信息
	QVariant data = index.data(Qt::UserRole+1);
	int iID = data.toInt();

	//获取编号/名称/单位
	CPMSQLTableCtrl * pSQLTableCtrl = NULL;
	CAccessDEData_RationTable deDataRationTable;
	if(!deDataRationTable.GetTableCtrl_ID(iID,pSQLTableCtrl))
		return ;

	if(pSQLTableCtrl->TableNextRow())
	{
		CString strDENumber;
		pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::denumber,strDENumber);

		CString strName;
		pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::subname,strName);

		CString strUnit;
		pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::unit,strUnit);

		//
		AddDERule(strDENumber,strName,strUnit);
	}
	PMDelete(pSQLTableCtrl);

}

//双击清单列表触发事件
void CDlgQDDE::On_DoubleClickedList_View_QD(const QModelIndex &index)
{
	//取附带的data----用于搜索定额信息
	QVariant data = index.data(Qt::UserRole+1);
	
	if(ui.radioButtonQD_QD->isChecked() == FALSE)
	{
		int iID = data.toInt();
		//获取编号/名称/单位
		CPMSQLTableCtrl * pSQLTableCtrl = NULL;
		CAccessDEData_RationTable deDataRationTable;
		if(!deDataRationTable.GetTableCtrl_ID(iID,pSQLTableCtrl))
			return ;

		if(pSQLTableCtrl->TableNextRow())
		{
			CString strDENumber;
			pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::denumber,strDENumber);

			CString strName;
			pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::subname,strName);

			CString strUnit;
			pSQLTableCtrl->GetAsString(CDERationTable::CFieldInfo::unit,strUnit);
			AddDERule(strDENumber,strName,strUnit);
		}

		PMDelete(pSQLTableCtrl);
	}
	else
	{
		On_DoubleClickedTree_View_QD(index);
		ui.radioButtonQD_QD->setChecked(TRUE);
		ui.radioButtonQD_DE->setChecked(FALSE);
	}
		
}

void CDlgQDDE::AddQDRule(CString strXMTZ,CString strDENumber,CString strName,CString strUnit)
{
	WBQD wbqd;
	wbqd.m_strXMBM = CStringToQString(strDENumber);
	wbqd.m_strXMMC = CStringToQString(strName);
	wbqd.m_strJLDW = CStringToQString(strUnit);
	wbqd.m_strXMTZ = CStringToQString(strXMTZ);

	//
	emit signal_AddQD(&wbqd);
}

void CDlgQDDE::AddDERule(CString strDENumber,CString strName,CString strUnit)
{
	WBQD wbqd;
	wbqd.m_strXMBM = CStringToQString(strDENumber);
	wbqd.m_strXMMC = CStringToQString(strName);
	wbqd.m_strJLDW = CStringToQString(strUnit);

	//
	emit signal_AddDE(&wbqd);
}


//节点折叠或者展开-----触发设置自适应水平滚动条
void CDlgQDDE::On_ClickedTree_Node()
{  
	ui.treeView_QD_Bottom->resizeColumnToContents(0);
	ui.treeView_QD_Top->resizeColumnToContents(0);
}

//选择组合框内项目自动搜索清单
void CDlgQDDE::On_ActiveComBox_QD()
{
	bEnter = TRUE;
	OnBtnQd();
}

//选择组合框内项目自动搜索定额
void CDlgQDDE::On_ActiveComBox_DE()
{
	bEnter = TRUE;
	OnBtnDe();
	
}

void CDlgQDDE::InsertTreeItem(QStandardItemModel *& m_pModel,QStandardItem *& itemChild ,int iID,CString strName,CString strUnit)
{
	strName += _T("\\") + strUnit;
	QString qstr = CStringToQString(strName);
	itemChild = new QStandardItem(qstr);

	//增加标记数据用于搜索
	itemChild->setData(QVariant(iID),Qt::UserRole + 1);
	itemChild->setData(QVariant(CStringToQString(strUnit)),Qt::UserRole + 2);
	m_pModel->appendRow(itemChild);
}

void CDlgQDDE::InsertTreeItem(QStandardItem *& itemParent,QStandardItem *& itemChild,int iID,CString strName,CString strUnit)
{
	strName += _T("\\") + strUnit;
	QString qstr = CStringToQString(strName);
	itemChild = new QStandardItem(qstr);

	//增加标记数据用于搜索
	itemChild->setData(QVariant(iID),Qt::UserRole + 1);
	itemChild->setData(QVariant(CStringToQString(strUnit)),Qt::UserRole + 2);
	itemParent->appendRow(itemChild);
}

CString CDlgQDDE::QStringToCString(QString qstr)
{
    USES_CONVERSION;
	QByteArray arry = qstr.toLocal8Bit();
	char *ch= arry.data();
	CString cstr = A2T(ch);  

	return cstr;
}

QString CDlgQDDE::CStringToQString(CString cstr)
{
	USES_CONVERSION;
	char* str;
	str = T2A(cstr.GetBuffer(0));
	cstr.ReleaseBuffer(); 
	QString qstr = QString::fromLocal8Bit(str);

	return qstr;
}

void CDlgQDDE::SplitCString(const CString & source, CStringArray& dest,TCHAR division)
{
	dest.RemoveAll();
	int finddivision = source.Find(division);
	if (finddivision == -1) //没有找到
	{
		dest.Add(source);
		return;
	}
	int oldFind = 0;
	while (finddivision >= 0)
	{
		dest.Add(source.Mid(oldFind,finddivision - oldFind));
		oldFind = finddivision + 1;
		finddivision = source.Find(division,oldFind);
	}
	//处理最后一种情况
	if (source.GetLength() >0 && oldFind>=0 && source.GetLength() > (oldFind))
	{
		dest.Add(source.Mid(oldFind,source.GetLength() - oldFind));
	}
}

void CDlgQDDE::SplitCString(const CString & source, CStringArray& dest,const CString & strDivision)
{
	int iDivLength = strDivision.GetLength();
	dest.RemoveAll();
	int finddivision = source.Find(strDivision);
	if (finddivision == -1) //没有找到
	{
		dest.Add(source);
		return;
	}
	int oldFind = 0;
	while (finddivision >= 0)
	{
		dest.Add(source.Mid(oldFind,finddivision - oldFind));
		oldFind = finddivision + iDivLength;
		finddivision = source.Find(strDivision,oldFind);
	}
	//处理最后一种情况
	if (source.GetLength() >0 && oldFind>=0 && source.GetLength() > (oldFind))
	{
		dest.Add(source.Mid(oldFind,source.GetLength() - oldFind));
	}
}

	