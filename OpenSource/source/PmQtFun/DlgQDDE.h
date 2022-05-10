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


	////添加到树形图的一级节点
	void AddNode(CString strChapterName,CString strChapter,QStandardItemModel * m_pModel,QStandardItem *&itemChildren);
	//添加到树形图的一级之后的子节点
	void AddNode(CString strChapterName,CString strChapter,QStandardItem *&itemParent,QStandardItem *&itemChildren);
	//整理数据选择节点
	void SelectData(NDataModelDataSet * pSQLDataSet,CString strId,CString strName,QStandardItemModel * &m_pModel);

public slots:
	//点击定额树触发事件
	void On_ClickedTree_View_DE(const QModelIndex &index);
	//点击清单树触发事件
	void On_ClickedTree_View_QD(const QModelIndex &index);
	//双击清单树触发事件
	void On_DoubleClickedTree_View_QD(const QModelIndex &index);
	//双击定额列表触发事件
	void On_DoubleClickedList_View_DE(const QModelIndex &index);
	//双击清单列表触发事件
	void On_DoubleClickedList_View_QD(const QModelIndex &index);
	//搜索定额/清单
	void OnBtnDe();
	void OnBtnQd();
	//点击定额/清单圆点按钮触发事件
	void On_ClickedRadioButton_DE();
	void On_ClickedRadioButton_QD();

	//节点折叠或者展开-----触发设置自适应水平滚动条
	void On_ClickedTree_Node();

	//组合框中选择一个项目时触发事件----用于自动搜索
	void On_ActiveComBox_QD();
	void On_ActiveComBox_DE();

signals:
	void signal_AddQD(const WBQD *);
	void signal_AddDE(const WBQD *);

public:
	
	//将清单/定额详细信息插入根树中
	void InsertTreeItem(QStandardItemModel *& m_pModel,QStandardItem *& itemChild,int iID,CString strName, CString strUnit);
	void InsertTreeItem(QStandardItem *& itemParent,QStandardItem *& itemChild,int iID,CString strName,CString strUnit);

	//点击清单树节点后，建立详细信息列表树
	void BuildQDListTree(CString strValue);

	//分割
	void CompositorChapterArray(CString strValue, CStringArray &strChapterArray);

	//添加最小子节点
	void InsertXhlItem(QStandardItem * itemParent,CStringArray & aryXhl);
	void InsertXhlItem(QStandardItemModel * &itemParent,CStringArray & aryXhl);

	//搜索定额/清单
	void SelectDe(QString strText,QTreeView * treeView);
	void SelectQd(QString strText,QTreeView * treeView);

	//添加清单/定额规则
	void AddQDRule(CString strXMTZ,CString strID,CString strName,CString strUnit);
	void AddDERule(CString strID,CString strName,CString strUnit);



public:
	//字符串转换
	CString QStringToCString(QString qstr);
	QString CStringToQString(CString cstr);

	//分割字符串
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
