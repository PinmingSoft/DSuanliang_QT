#ifndef PMWBQD_H
#define PMWBQD_H

#include <QWidget>
#include <QDialog>
#include "DlgQDDE.h"
#include "ui_DlgWbqd.h"
#include "WbqdStandardItemModel.h"
#include "Wbqd_LoadExcel_Delegate.h"



class CDlgWbqd : public QDialog
{
	Q_OBJECT

public:
	CDlgWbqd(QWidget *parent = 0);
	~CDlgWbqd();

public slots:
	void On_pushButtonLoadExcel_Clicked();
	void On_pushButtonUseQD_Clicked();
	void On_pushButtonAdd_Clicked();
	void On_pushButtonDelete_Clicked();
	void On_treeViewWbqd_Clicked(const QModelIndex & index);
	void On_treeViewWbqd_DoubleClicked(const QModelIndex & index);
	void On_treeViewWbqd_ItemChanged(QStandardItem * item);
	void On_tableViewXMTZ_ItemChanged(QStandardItem * item);
	//void On_tableViewXMTZ_DataChanged(const QModelIndex & leftTop,const QModelIndex & rightBottom);
	void On_tableViewXMTZ_pressed(const QModelIndex &index);
	void On_tableViewXMTZ_clicked(const QModelIndex &index);
	void On_tableViewXMTZ_doubleClicked(const QModelIndex &index);
	void On_tableViewXMTZ_activated(const QModelIndex &index);
	void On_tableViewXMTZ_entered(const QModelIndex &index);
	void On_tableViewXMTZ_viewportEntered();
	void On_pushButtonRetract_Clicked();
	void On_pushButtonExpend_Clicked();
	void On_pushButtonMoveUp_Clicked();

protected:
	//初始化外部清单
	void InitTreeViewWbqdStyle();

	//初始化项目特征
	void InitXMTZViewStyle();

	//缩进处理
	BOOL DealWithRetract(CWbqdStandardItemModel * pModel,QList<QModelIndex> & indexList);

	//缩出处理
	BOOL DealWithExpend(CWbqdStandardItemModel * pModel,QModelIndex indexCur);

	//上移处理
	BOOL DealWithMoveUp(CWbqdStandardItemModel * pModel,QModelIndex indexCur);

	//判断多选的是否是同一层级
	BOOL IsSameLevel(const QModelIndexList & indexList) const;

	//获取从本节点开始往上数的所有父节点行号(包括本节点行号)
	void GetPathRow(const QModelIndex &index,PmGeIntArray & arrRowPath) const;

	//返回本节点层级,层级从0开始
	int GetLevel(const QModelIndex &index) const;

	//返回最大的子节点层级，如果没有子节点，则返回本节点层级,层级从0开始
	int GetMaxLevel(const QModelIndex &index) const;

	//获取子节点层数,层级从0开始
	int GetChildLevelCount(const QModelIndex &index) const;

	//
	void FillData(const CWbqd_LoadExcelItemModel * pContentModel,bool bCover);

signals:
	void signal_clicked(WBQD *);

private:
	void closeEvent ( QCloseEvent * e );

private:
	Ui::CDlgWbqd ui;
	CDlgQDDE * m_pDlgQDDE;

	//用于记录原先的尺寸
	QSize m_sizeOrign;

	//表头名
	QStringList m_listName;

	//是否正在填充项目特征单元格数据----此时不需要触发itemChanged信号
	bool m_bFillingXMTZ;

	//层级限制---3 留出4层级
	int m_iLimit;

};

#endif // PMWBQD_H
