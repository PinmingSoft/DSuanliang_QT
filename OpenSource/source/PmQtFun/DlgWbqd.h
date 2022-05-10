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
	//��ʼ���ⲿ�嵥
	void InitTreeViewWbqdStyle();

	//��ʼ����Ŀ����
	void InitXMTZViewStyle();

	//��������
	BOOL DealWithRetract(CWbqdStandardItemModel * pModel,QList<QModelIndex> & indexList);

	//��������
	BOOL DealWithExpend(CWbqdStandardItemModel * pModel,QModelIndex indexCur);

	//���ƴ���
	BOOL DealWithMoveUp(CWbqdStandardItemModel * pModel,QModelIndex indexCur);

	//�ж϶�ѡ���Ƿ���ͬһ�㼶
	BOOL IsSameLevel(const QModelIndexList & indexList) const;

	//��ȡ�ӱ��ڵ㿪ʼ�����������и��ڵ��к�(�������ڵ��к�)
	void GetPathRow(const QModelIndex &index,PmGeIntArray & arrRowPath) const;

	//���ر��ڵ�㼶,�㼶��0��ʼ
	int GetLevel(const QModelIndex &index) const;

	//���������ӽڵ�㼶�����û���ӽڵ㣬�򷵻ر��ڵ�㼶,�㼶��0��ʼ
	int GetMaxLevel(const QModelIndex &index) const;

	//��ȡ�ӽڵ����,�㼶��0��ʼ
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

	//���ڼ�¼ԭ�ȵĳߴ�
	QSize m_sizeOrign;

	//��ͷ��
	QStringList m_listName;

	//�Ƿ����������Ŀ������Ԫ������----��ʱ����Ҫ����itemChanged�ź�
	bool m_bFillingXMTZ;

	//�㼶����---3 ����4�㼶
	int m_iLimit;

};

#endif // PMWBQD_H
