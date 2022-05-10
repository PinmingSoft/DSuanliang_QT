#pragma once
#include "qstandarditemmodel.h"
#include "Wbqd_LoadExcel_Delegate.h"
/**
 * @brief  :外部清单导入excel对话框表格的model
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

	//获取列名匹配关系
	bool HasColumn(QString colName) const;
	int GetColumn(QString colName) const;

	//重新检测行的合理性
	bool IsRowLegal(QStandardItemModel * pContentModel,int row) const;

	//重新检测行的合理性，合理的勾选上
	void CheckRows(bool bChecked);
	bool CheckRow(int row,bool bCheck);

	//列与列名的匹配
	QMap<int,QString> m_mapCol2Name;

private:
	//
	bool IsRowLegal_QD(QStandardItemModel * pContentModel,int row) const;
	bool IsRowLegal_DE(QStandardItemModel * pContentModel,int row) const;
	bool IsRowLegal_Chapter(QStandardItemModel * pContentModel,int row) const;
};

/**
* @brief   外部清单的表格的model
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
		UnKnownType //未知类型
		,Chapter	//章
		,matter1	//节1
		,matter2	//节1.1
		,matter3	//节1.1.1
		,QD			//清单
		,DE			//定额
	};

	//获取列名匹配关系
	//void GetMapCol2Name(QMap<int,QString> & mapCol2Name) const;
	bool HasColumn(QString colName) const;
	int GetColumn(QString colName) const;

	//按column匹配关系拷贝数据
	void CopyDataFrom(const CWbqd_LoadExcelItemModel * pData);

	//建立树形节点层级关系
	void BuildTreeRelation();

	//插入新行
	void InsertAfterSelected(QAbstractItemView * pTableView);

	//删除
	void DeleteRowsSelected(QAbstractItemView * pTableView);

	//判断多选删除时是否是同一级
	BOOL IsSameLevel(QModelIndexList indexList);

	//分解出项目特征
	QStringList GetXMTZ(int row) const;
	static QStringList GetXMTZ(QString xmtzContent);

	//合并相同编码+名称的节点
	void MergeSameXM();

	//保存外部清单到数据库
	void SaveWbqdToDb();
	void SaveWbqdToDb_Level(CSQLDataSet * pDs,const int & parentId,QStandardItem * pItemCur,int levelItemCur);

	//从数据库
	void ReadWbqdFromDb();

	//添加第一列左对齐--背景色
	QVariant data(const QModelIndex &index, int role) const;

	//重新判断某节点的类型与其子节点的类型----缩进缩出导致的
	void ReJudgeNodeType(QStandardItem * pItem);

	//列与列名的匹配
	QMap<int,QString> m_mapCol2Name;
private:
	//层级限制 目前限制为3
	int m_iLimit;

public slots:
	void OnAddQD(const WBQD *);
	void OnAddDE(const WBQD *);

protected:
	//是否是清单行----严格
	bool IsRow_QD(int row) const;
	bool IsRow_QD(QStandardItem * pItemXMMC,QStandardItem * pItemXMBM,QStandardItem * pItemJLDW) const;
	//是否是定额行----严格
	bool IsRow_DE(int row) const;
	bool IsRow_DE(QStandardItem * pItemXMMC,QStandardItem * pItemXMBM,QStandardItem * pItemJLDW) const;
	//是否是章节----严格
	bool IsRow_Chapter(int row) const;
	bool IsRow_Chapter(QStandardItem * pItemXMMC,QStandardItem * pItemXMBM,QStandardItem * pItemJLDW) const;

protected:
	//按树状方式,在parent的下面追加一行
	QStandardItem * AppendNewRow(QStandardItem * pParent
		,const QString & xmmc
		,const QString & xmbm
		,const QString & xmtz
		,const QString & jldw);
	//按树状方式,在parent下的某一行插入
	QStandardItem * InsertNewRow(QStandardItem * pParent
		,int rowAt
		,const QString & xmmc
		,const QString & xmbm
		,const QString & xmtz
		,const QString & jldw);

	//插入新行----按表格(非树状)方式插入一行
	int InsertTableNewRow(int rowAt);

	//判断每个行的类型
	CWbqdStandardItemModel::ItemQDType JudgeItemQDType(int row) const;
	CWbqdStandardItemModel::ItemQDType JudgeItemQDType(QStandardItem * pItemXMMC,QStandardItem * pItemXMBM,QStandardItem * pItemJLDW) const;


	//设置清单类型
	void SetItemQDType(int row);
	void SetItemQDType(int row,CWbqdStandardItemModel::ItemQDType typ);
	void SetItemQDType(QStandardItem * pItem,CWbqdStandardItemModel::ItemQDType typ);
	void SetItemQDType(QStandardItem * pItemParent,int row);
	void SetItemQDType(QStandardItem * pItem);

	//获取已有项的清单定额类型
	CWbqdStandardItemModel::ItemQDType GetItemQDType(QStandardItem * pItem) const;
};

/// 项目特征，项目名称拆分
class CXMMC_XMTZAnalyse
{
public:
	CXMMC_XMTZAnalyse();

	/**
	* @brief   对xmmc_Xmtz进行拆分
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

/// 项目特征字符串拆分
class CXMTZAnalyse
{
public:
	CXMTZAnalyse(){};

	/**
	* @brief   把外部excel的项目特征进行分解，合成正确格式的项目特征字符串
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

	//生成项目特征的表-----用于写入数据库用
	CQDAttTable * GetTable() const;

private:
	//项目名称
	QString m_strXMMC;
	//项目特征
	QStringList m_listXMTZ;
	//项目特征值
	QStringList m_listValue;
};

/// 项目特征的model
class CXMTZStandardItemModel :public QStandardItemModel
{
public:
	CXMTZStandardItemModel(void){};
	~CXMTZStandardItemModel(void){};

	/**
	* @brief   把外部excel的项目特征进行分解，合成正确格式的项目特征字符串
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
	//原始的项目特征
	QString m_strXMTZOrign;
};