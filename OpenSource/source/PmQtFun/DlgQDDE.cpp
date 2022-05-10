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
	
	//ui.pushButton_Search_DE->setFocus();    //����Ĭ�Ͻ���
	//ui.pushButton_Search_DE->setShortcut( QKeySequence::InsertParagraphSeparator );  //���ÿ�ݼ�Ϊ���̵ġ��س�����
	//ui.pushButton_Search_DE->setShortcut(Qt::Key_Enter);  //���ÿ�ݼ�Ϊenter��
	//ui.pushButton_Search_DE->setShortcut(Qt::Key_Return); //���ÿ�ݼ�ΪС�����ϵ�enter��
	
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
		UIFunction::PMMessageBox(_T("����� ����ʧ��!"));
	}

	m_pModelDE = new QStandardItemModel(ui.treeView_DE_Top);
	m_pModelDE->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit("�����½�"));

	//�������ݿ��е�����ѡ�����ڵ�
	SelectData(pDataSet_DE,_T("chapter"),_T("chaptername"),m_pModelDE);

	//����Ϊ���ɱ༭״̬
	ui.treeView_DE_Top->setEditTriggers(0);
	ui.treeView_DE_Top->setModel(m_pModelDE);

}

void CDlgQDDE::InitTreeQD()
{
	CAccessQDData_RuleIndex_mTable qdDataRuleTable;
	NDataModelDataSet * pDataSetQD = qdDataRuleTable.GetDataSet();

	if(NULL == pDataSetQD)
	{
		//UIFunction::PMMessageBox(_T("�嵥�� ����ʧ��!"));
		ui.tabWidget->removeTab(0);
		return;
	}
	m_pModelQD = new QStandardItemModel(ui.treeView_QD_Top);
	m_pModelQD->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit("�嵥�½�"));
	
	//�������ݿ��е�����ѡ�����ڵ�
	SelectData(pDataSetQD,_T("nodeid"),_T("nodename"),m_pModelQD);

	//��ťĬ��ѡ�ж���
	ui.radioButtonQD_DE->setChecked(TRUE);
	ui.radioButtonQD_QD->setChecked(FALSE);

	//����Ϊ���ɱ༭״̬
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

//��ӵ�����ͼ�ĵ�һ���ڵ�
void CDlgQDDE::AddNode(CString strChapterName,CString strChapter,QStandardItemModel * m_pModel,QStandardItem *&itemChildren )
{
 
	itemChildren = new QStandardItem(CStringToQString(strChapterName));
	//���ӱ��������������
	itemChildren->setData(QVariant(CStringToQString(strChapter)),Qt::UserRole + 1);

	m_pModel->appendRow(itemChildren);
}

//��ӵ�����ͼ��һ��֮����ӽڵ�
void CDlgQDDE::AddNode(CString strChapterName,CString strChapter,QStandardItem *&itemParent,QStandardItem *&itemChildren)
{

	itemChildren = new QStandardItem(CStringToQString(strChapterName));
	//���ӱ��������������
	itemChildren->setData(QVariant(CStringToQString(strChapter)),Qt::UserRole + 1);
	itemParent->appendRow(itemChildren);
	 
}

//��������������¼�---��ȡ�����ڵ�Ķ�����Ϣ
void CDlgQDDE::On_ClickedTree_View_DE(const QModelIndex &index)
{
	//QString strName = ui.treeView_DE_Top->model()->itemData(index).values()[0].toString();

	//ȡ������data----��������������ϸ��Ϣ
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
	
	//����Ϊ���ɱ༭״̬
	ui.listView_DE_Bottom->setEditTriggers(0);
	ui.listView_DE_Bottom->setModel(m_pModelListDE);
	
}

//����嵥�������¼�
void CDlgQDDE::On_ClickedTree_View_QD(const QModelIndex &index)
{
	//QString strName = ui.treeView->model()->itemData(index).values()[0].toString();

	//ȡ������data----���������嵥��ϸ��Ϣ
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

	//��ť����Ϊѡ�ж���
	ui.radioButtonQD_DE->setChecked(TRUE);
	ui.radioButtonQD_QD->setChecked(FALSE);

	//����Ϊ���ɱ༭״̬
	ui.treeView_QD_Bottom->setEditTriggers(0);
	ui.treeView_QD_Bottom->setModel(m_pModel_List_QD);
	//��ͷ����
	ui.treeView_QD_Bottom->setHeaderHidden(TRUE);
	//չ�����нڵ�
	ui.treeView_QD_Bottom->expandAll();
	//����ˮƽ����������Ӧ
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
	
	//7-10~7-20,7-44;////���2
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
			UIFunction::PMMessageBox(_T("�½ڱ�ų���,") + strValue);
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
	//�Ƚ�','����
	SplitCString(strValue,str1Array,_T(','));

	int i1ArraySize = str1Array.GetSize();
	for (int i = 0;i < i1ArraySize;i++)
	{	
		//��'~'�����½ڷ���
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

	//����Ϊ���ɱ༭
	treeView->setEditTriggers(0);
	treeView->setModel(m_pModel);
	//���ñ�ͷ����
	treeView->setHeaderHidden(TRUE);
	//���ú��������
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
	/// ѭ��ÿһ�У�����ƥ����嵥
	int iRowCount = pRuleIndexTable->GetRowCount() ; 

	/// 
	int i = 1 ; 
	for ( ; i <= iRowCount ; ++ i )
	{
		//��ȡ�嵥��ID
		CString strQdid = pRuleIndexTable->GetAsString( CQDRuleIndex_mTable::CFieldInfo::qdid , i ) ;
		/// ��ȡ�ڵ���
		CString strNodeName = pRuleIndexTable->GetAsString( CQDRuleIndex_mTable::CFieldInfo::nodename , i ) ;
		if ( strQdid.IsEmpty() || strNodeName.IsEmpty() )
		{
			continue ; 
		}

		if ( strQdid.Find( QStringToCString(strText)) != -1 
			|| strNodeName.Find(QStringToCString(strText)) != -1 )
		{
			/// ��ȡ�ڵ�ID
			int iId = pRuleIndexTable->GetAsInteger( CQDRuleIndex_mTable::CFieldInfo::id , i ) ;
			/// ��ȡ��λ
			CString strUnit= pRuleIndexTable->GetAsString( CQDRuleIndex_mTable::CFieldInfo::unit , i ) ;

			//��ȡnodeID
			CString strNodeID = pRuleIndexTable->GetAsString(CQDRuleIndex_mTable::CFieldInfo::nodeid, i);

			/// �����嵥
			AddNode(strNodeName,strNodeID,m_pModel,itemChild);
		}			
	} 
	PMDelete( pRuleIndexTable );

	//����Ϊ���ɱ༭
	treeView->setEditTriggers(0);
	treeView->setModel(m_pModel);
	//���ñ�ͷ����
	treeView->setHeaderHidden(TRUE);
	//���ú��������
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

//˫���嵥�������¼�----Ԥ�����ӿ�
void CDlgQDDE::On_DoubleClickedTree_View_QD(const QModelIndex &index)
{
	
	//ȡ������data----��������������Ϣ
	QVariant data = index.data(Qt::UserRole+1);
	QString strID = data.toString();
	if(strID.length() < 9)
		return;

	CAccessQDData_QDAttTable qdxmAttTable;
	CSQLDataSet * pSQLdataSet = NULL;

	//��ȡ��Ŀ����
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
	//��ȡ ���/����/��λ
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

	//��ť����Ϊѡ�ж���
	ui.radioButtonQD_DE->setChecked(TRUE);
	ui.radioButtonQD_QD->setChecked(FALSE);

	PMDelete(pSQLdataSet);
	PMDelete(pSQLTableCtrl);
}

//˫�������б����¼�-----Ԥ�����ӿ�
void CDlgQDDE::On_DoubleClickedList_View_DE(const QModelIndex &index)
{

	//ȡ������data----��������������Ϣ
	QVariant data = index.data(Qt::UserRole+1);
	int iID = data.toInt();

	//��ȡ���/����/��λ
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

//˫���嵥�б����¼�
void CDlgQDDE::On_DoubleClickedList_View_QD(const QModelIndex &index)
{
	//ȡ������data----��������������Ϣ
	QVariant data = index.data(Qt::UserRole+1);
	
	if(ui.radioButtonQD_QD->isChecked() == FALSE)
	{
		int iID = data.toInt();
		//��ȡ���/����/��λ
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


//�ڵ��۵�����չ��-----������������Ӧˮƽ������
void CDlgQDDE::On_ClickedTree_Node()
{  
	ui.treeView_QD_Bottom->resizeColumnToContents(0);
	ui.treeView_QD_Top->resizeColumnToContents(0);
}

//ѡ����Ͽ�����Ŀ�Զ������嵥
void CDlgQDDE::On_ActiveComBox_QD()
{
	bEnter = TRUE;
	OnBtnQd();
}

//ѡ����Ͽ�����Ŀ�Զ���������
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

	//���ӱ��������������
	itemChild->setData(QVariant(iID),Qt::UserRole + 1);
	itemChild->setData(QVariant(CStringToQString(strUnit)),Qt::UserRole + 2);
	m_pModel->appendRow(itemChild);
}

void CDlgQDDE::InsertTreeItem(QStandardItem *& itemParent,QStandardItem *& itemChild,int iID,CString strName,CString strUnit)
{
	strName += _T("\\") + strUnit;
	QString qstr = CStringToQString(strName);
	itemChild = new QStandardItem(qstr);

	//���ӱ��������������
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
	if (finddivision == -1) //û���ҵ�
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
	//�������һ�����
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
	if (finddivision == -1) //û���ҵ�
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
	//�������һ�����
	if (source.GetLength() >0 && oldFind>=0 && source.GetLength() > (oldFind))
	{
		dest.Add(source.Mid(oldFind,source.GetLength() - oldFind));
	}
}

	