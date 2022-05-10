#ifndef DLGQDDE_H
#define DLGQDDE_H

#include <QDialog>
#include "ui_DlgQDDE.h"
#include "Wbqd_LoadExcel_Delegate.h"
#include "WbqdStandardItemModel.h"

class CDlgQDDE : public QDialog
{
	Q_OBJECT

public:
	CDlgQDDE(QStandardItemModel * pModelQDDE,QWidget *parent = 0);
	~CDlgQDDE();

private:
	Ui::CDlgQDDE ui;

	
	void InitTreeDE();
	void InitTreeQD();


	////��ӵ�����ͼ��һ���ڵ�
	void AddNode(CString strChapterName,CString strChapter,QStandardItemModel * m_pModel,QStandardItem *&itemChildren);
	//��ӵ�����ͼ��һ��֮����ӽڵ�
	void AddNode(CString strChapterName,CString strChapter,QStandardItem *&itemParent,QStandardItem *&itemChildren);
	//��������ѡ��ڵ�
	void SelectData(NDataModelDataSet * pSQLDataSet,CString strId,CString strName,QStandardItemModel * &m_pModel);

public slots:
	//��������������¼�
	void On_ClickedTree_View_DE(const QModelIndex &index);
	//����嵥�������¼�
	void On_ClickedTree_View_QD(const QModelIndex &index);
	//˫���嵥�������¼�
	void On_DoubleClickedTree_View_QD(const QModelIndex &index);
	//˫�������б����¼�
	void On_DoubleClickedList_View_DE(const QModelIndex &index);
	//˫���嵥�б����¼�
	void On_DoubleClickedList_View_QD(const QModelIndex &index);
	//��������/�嵥
	void OnBtnDe();
	void OnBtnQd();
	//�������/�嵥Բ�㰴ť�����¼�
	void On_ClickedRadioButton_DE();
	void On_ClickedRadioButton_QD();

	//�ڵ��۵�����չ��-----������������Ӧˮƽ������
	void On_ClickedTree_Node();

	//��Ͽ���ѡ��һ����Ŀʱ�����¼�----�����Զ�����
	void On_ActiveComBox_QD();
	void On_ActiveComBox_DE();

signals:
	void signal_AddQD(const WBQD *);
	void signal_AddDE(const WBQD *);

public:
	
	//���嵥/������ϸ��Ϣ���������
	void InsertTreeItem(QStandardItemModel *& m_pModel,QStandardItem *& itemChild,int iID,CString strName, CString strUnit);
	void InsertTreeItem(QStandardItem *& itemParent,QStandardItem *& itemChild,int iID,CString strName,CString strUnit);

	//����嵥���ڵ�󣬽�����ϸ��Ϣ�б���
	void BuildQDListTree(CString strValue);

	//�ָ�
	void CompositorChapterArray(CString strValue, CStringArray &strChapterArray);

	//�����С�ӽڵ�
	void InsertXhlItem(QStandardItem * itemParent,CStringArray & aryXhl);
	void InsertXhlItem(QStandardItemModel * &itemParent,CStringArray & aryXhl);

	//��������/�嵥
	void SelectDe(QString strText,QTreeView * treeView);
	void SelectQd(QString strText,QTreeView * treeView);

	//����嵥/�������
	void AddQDRule(CString strXMTZ,CString strID,CString strName,CString strUnit);
	void AddDERule(CString strID,CString strName,CString strUnit);



public:
	//�ַ���ת��
	CString QStringToCString(QString qstr);
	QString CStringToQString(CString cstr);

	//�ָ��ַ���
	void SplitCString(const CString & source, CStringArray& dest,TCHAR division);
	void SplitCString(const CString & source, CStringArray& dest,const CString & strDivision);

private:
	QStandardItemModel * m_pParentQDDE;
	QStandardItemModel * m_pModelDE;
	QStandardItemModel * m_pModelQD;
	QStandardItemModel * m_pModel_List_QD;
	QStringList qstrListBoxQD;
	QStringList qstrListBoxDE;
	BOOL bEnter;
	

};

#endif // DLGQDDE_H
