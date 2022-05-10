#pragma once
#include <qitemdelegate.h>

class WBQD
{
public:
	//
	WBQD(){}
	WBQD(const WBQD & src){*this = src;}
	void operator=(const WBQD & src)
	{
		m_strXMBM = src.m_strXMBM;
		m_strXMMC = src.m_strXMMC;
		m_strXMTZ = src.m_strXMTZ;
		m_strJLDW = src.m_strJLDW;
		m_strCKGCL = src.m_strCKGCL;
		m_strCKDJ = src.m_strCKDJ;
		m_strCKHJ = src.m_strCKHJ;
	}
	static QString kXMBM;	//项目编码
	static QString kXMMC;	//项目名称
	static QString kXMTZ;	//项目特征
	static QString kJLDW;	//计量单位
	static QString kCKGCL;//参考工程量
	static QString kCKDJ;	//参考合价
	static QString kCKHJ;	//参考单价

	static void InitValue();

	//是否是外部清单的字段
	static bool IsWBQDField(const QString & field);
	static bool IsXMMCAndXMTZ(const QString & field);

	//外部清单的值
	QString m_strXMBM;	//项目编码
	QString m_strXMMC;	//项目名称
	QString m_strXMTZ;	//项目特征
	QString m_strJLDW;	//计量单位
	QString m_strCKGCL;	//参考工程量
	QString m_strCKDJ;	//参考合价
	QString m_strCKHJ;	//参考单价


};

class CWbqd_LoadExcel_Delegate : public QItemDelegate
{
	Q_OBJECT
public:

	//
	static void GetColumnName(QStringList & nameList);

	//
	CWbqd_LoadExcel_Delegate(QTableView *table) { m_pTable = table; }
	~CWbqd_LoadExcel_Delegate() {}
	virtual QWidget *    createEditor ( QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
	virtual void    setEditorData ( QWidget * editor, const QModelIndex & index ) const;
	virtual void    setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const;
private:
	QTableView *m_pTable;
};

class CWbqd_TreeView_Delegate : public QItemDelegate
{
	Q_OBJECT
public:
	//
	CWbqd_TreeView_Delegate(QTreeView * treeView) { m_pTable = treeView; }
	~CWbqd_TreeView_Delegate() {}
	virtual QWidget *    createEditor ( QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
	virtual void    setEditorData ( QWidget * editor, const QModelIndex & index ) const;
	virtual void    setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const;
private:
	QTreeView * m_pTable;
};
