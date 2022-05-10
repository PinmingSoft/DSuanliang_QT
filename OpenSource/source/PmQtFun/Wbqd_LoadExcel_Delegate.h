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
	static QString kXMBM;	//��Ŀ����
	static QString kXMMC;	//��Ŀ����
	static QString kXMTZ;	//��Ŀ����
	static QString kJLDW;	//������λ
	static QString kCKGCL;//�ο�������
	static QString kCKDJ;	//�ο��ϼ�
	static QString kCKHJ;	//�ο�����

	static void InitValue();

	//�Ƿ����ⲿ�嵥���ֶ�
	static bool IsWBQDField(const QString & field);
	static bool IsXMMCAndXMTZ(const QString & field);

	//�ⲿ�嵥��ֵ
	QString m_strXMBM;	//��Ŀ����
	QString m_strXMMC;	//��Ŀ����
	QString m_strXMTZ;	//��Ŀ����
	QString m_strJLDW;	//������λ
	QString m_strCKGCL;	//�ο�������
	QString m_strCKDJ;	//�ο��ϼ�
	QString m_strCKHJ;	//�ο�����


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
