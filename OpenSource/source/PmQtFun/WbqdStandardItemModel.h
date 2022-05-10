#pragma once
#include "qstandarditemmodel.h"
#include "Wbqd_LoadExcel_Delegate.h"
/**
 * @brief  :�ⲿ�嵥����excel�Ի������model
 *
 *          
 *			
 *			
 * @author :zfy
 * @version:v1.0
 * @date   :[7/5/2019]
 * @note   :
 */
class CWbqd_LoadExcelItemModel :public QStandardItemModel
{
	Q_OBJECT
public:
	CWbqd_LoadExcelItemModel(QAbstractItemView *parent=0);
	~CWbqd_LoadExcelItemModel(void);

	//��ȡ����ƥ���ϵ
	bool HasColumn(QString colName) const;
	int GetColumn(QString colName) const;

	//���¼���еĺ�����
	bool IsRowLegal(QStandardItemModel * pContentModel,int row) const;

	//���¼���еĺ����ԣ�����Ĺ�ѡ��
	void CheckRows(bool bChecked);
	bool CheckRow(int row,bool bCheck);

	//����������ƥ��
	QMap<int,QString> m_mapCol2Name;

private:
	//
	bool IsRowLegal_QD(QStandardItemModel * pContentModel,int row) const;
	bool IsRowLegal_DE(QStandardItemModel * pContentModel,int row) const;
	bool IsRowLegal_Chapter(QStandardItemModel * pContentModel,int row) const;
};

/**
* @brief   �ⲿ�嵥�ı���model
*
*			
* @note  : 
* @param : 
* @return: TRUE/FALSE
* @author: zfy
* @date  : [8/19/2019]
*/
class CWbqdStandardItemModel :public QStandardItemModel
{
	Q_OBJECT
public:
	CWbqdStandardItemModel(QAbstractItemView *parent=0);
	~CWbqdStandardItemModel(void);

	enum ItemQDType
	{
		UnKnownType //δ֪����
		,Chapter	//��
		,matter1	//��1
		,matter2	//��1.1
		,matter3	//��1.1.1
		,QD			//�嵥
		,DE			//����
	};

	//��ȡ����ƥ���ϵ
	//void GetMapCol2Name(QMap<int,QString> & mapCol2Name) const;
	bool HasColumn(QString colName) const;
	int GetColumn(QString colName) const;

	//��columnƥ���ϵ��������
	void CopyDataFrom(const CWbqd_LoadExcelItemModel * pData);

	//�������νڵ�㼶��ϵ
	void BuildTreeRelation();

	//��������
	void InsertAfterSelected(QAbstractItemView * pTableView);

	//ɾ��
	void DeleteRowsSelected(QAbstractItemView * pTableView);

	//�ж϶�ѡɾ��ʱ�Ƿ���ͬһ��
	BOOL IsSameLevel(QModelIndexList indexList);

	//�ֽ����Ŀ����
	QStringList GetXMTZ(int row) const;
	static QStringList GetXMTZ(QString xmtzContent);

	//�ϲ���ͬ����+���ƵĽڵ�
	void MergeSameXM();

	//�����ⲿ�嵥�����ݿ�
	void SaveWbqdToDb();
	void SaveWbqdToDb_Level(CSQLDataSet * pDs,const int & parentId,QStandardItem * pItemCur,int levelItemCur);

	//�����ݿ�
	void ReadWbqdFromDb();

	//��ӵ�һ�������--����ɫ
	QVariant data(const QModelIndex &index, int role) const;

	//�����ж�ĳ�ڵ�����������ӽڵ������----�����������µ�
	void ReJudgeNodeType(QStandardItem * pItem);

	//����������ƥ��
	QMap<int,QString> m_mapCol2Name;
private:
	//�㼶���� Ŀǰ����Ϊ3
	int m_iLimit;

public slots:
	void OnAddQD(const WBQD *);
	void OnAddDE(const WBQD *);

protected:
	//�Ƿ����嵥��----�ϸ�
	bool IsRow_QD(int row) const;
	bool IsRow_QD(QStandardItem * pItemXMMC,QStandardItem * pItemXMBM,QStandardItem * pItemJLDW) const;
	//�Ƿ��Ƕ�����----�ϸ�
	bool IsRow_DE(int row) const;
	bool IsRow_DE(QStandardItem * pItemXMMC,QStandardItem * pItemXMBM,QStandardItem * pItemJLDW) const;
	//�Ƿ����½�----�ϸ�
	bool IsRow_Chapter(int row) const;
	bool IsRow_Chapter(QStandardItem * pItemXMMC,QStandardItem * pItemXMBM,QStandardItem * pItemJLDW) const;

protected:
	//����״��ʽ,��parent������׷��һ��
	QStandardItem * AppendNewRow(QStandardItem * pParent
		,const QString & xmmc
		,const QString & xmbm
		,const QString & xmtz
		,const QString & jldw);
	//����״��ʽ,��parent�µ�ĳһ�в���
	QStandardItem * InsertNewRow(QStandardItem * pParent
		,int rowAt
		,const QString & xmmc
		,const QString & xmbm
		,const QString & xmtz
		,const QString & jldw);

	//��������----�����(����״)��ʽ����һ��
	int InsertTableNewRow(int rowAt);

	//�ж�ÿ���е�����
	CWbqdStandardItemModel::ItemQDType JudgeItemQDType(int row) const;
	CWbqdStandardItemModel::ItemQDType JudgeItemQDType(QStandardItem * pItemXMMC,QStandardItem * pItemXMBM,QStandardItem * pItemJLDW) const;


	//�����嵥����
	void SetItemQDType(int row);
	void SetItemQDType(int row,CWbqdStandardItemModel::ItemQDType typ);
	void SetItemQDType(QStandardItem * pItem,CWbqdStandardItemModel::ItemQDType typ);
	void SetItemQDType(QStandardItem * pItemParent,int row);
	void SetItemQDType(QStandardItem * pItem);

	//��ȡ��������嵥��������
	CWbqdStandardItemModel::ItemQDType GetItemQDType(QStandardItem * pItem) const;
};

/// ��Ŀ��������Ŀ���Ʋ��
class CXMMC_XMTZAnalyse
{
public:
	CXMMC_XMTZAnalyse();

	/**
	* @brief   ��xmmc_Xmtz���в��
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/8/2019]
	*/
	static void SplitXMMC_XMTZ(const QString xmmc_Xmtz,QString & xmmc,QString & xmtz);
};

/// ��Ŀ�����ַ������
class CXMTZAnalyse
{
public:
	CXMTZAnalyse(){};

	/**
	* @brief   ���ⲿexcel����Ŀ�������зֽ⣬�ϳ���ȷ��ʽ����Ŀ�����ַ���
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/5/2019]
	*/
	void SetXMTZ(const QString & xmtz);
	QString GetXMTZ() const;
	void GetXMTZ(QStringList & listXMTZ,QStringList & listValue) const;

	//������Ŀ�����ı�-----����д�����ݿ���
	CQDAttTable * GetTable() const;

private:
	//��Ŀ����
	QString m_strXMMC;
	//��Ŀ����
	QStringList m_listXMTZ;
	//��Ŀ����ֵ
	QStringList m_listValue;
};

/// ��Ŀ������model
class CXMTZStandardItemModel :public QStandardItemModel
{
public:
	CXMTZStandardItemModel(void){};
	~CXMTZStandardItemModel(void){};

	/**
	* @brief   ���ⲿexcel����Ŀ�������зֽ⣬�ϳ���ȷ��ʽ����Ŀ�����ַ���
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/5/2019]
	*/
	void SetXMTZ(const QString & xmtz);
	QString GetXMTZ() const;

private:
	//ԭʼ����Ŀ����
	QString m_strXMTZOrign;
};