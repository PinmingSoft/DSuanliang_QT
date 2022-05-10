#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CDERationTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CDERationTable)

	CDERationTable();
	virtual ~CDERationTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString denumber;		//定额子目号
		static const CString subname;			//子目名称
		static const CString extendflag;		//扩充定额标志。
		static const CString unit;			//单位，字串
		static const CString chapter;			//章节编码

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CAccessDEData_RationTable :
	public CPMSLAccessTable
{
public:
	CAccessDEData_RationTable(void);

	virtual ~CAccessDEData_RationTable(void);

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	NDataModelDataSet * GetEmptyDataSet() ;

	BOOL SaveDataSet(CSQLDataSet * pRationTable);

	/**
	* @brief 获取所有行记录集  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [24/7/2012]
	*/
	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief  通过 denumber 获取 记录集 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/7/2012]
	*/
	BOOL GetTableCtrl_DeNumber(const CString & strDENUmber,CPMSQLTableCtrl *& pTemSQLTableCtrl);

	BOOL GetTableCtrl_ID(int iID,CPMSQLTableCtrl *& pTemSQLTableCtrl);

	BOOL GetID_DeNumber(const CString & strDENumber,int & iDEID);

	BOOL GetTableCtrl_DeNumber(const CStringArray & strDENumberArr,CPMSQLTableCtrl *& pTemSQLTableCtrl);

	BOOL GetTableCtrl_Chapter(const CString & strChapter,CPMSQLTableCtrl *& pTemSQLTableCtrl);

	BOOL SreachName_DeNum_TableCtrl(const CString strSreachInfo,CPMSQLTableCtrl *& pTemSQLTableCtrl);

	static PmTString GetSQL(const int iSQLIndex);

	struct PmSLGJDataServiceAPI SQLInfo
	{
		static const int		m_iSelectAllInfo_DENumber;
		static const PmTString	m_strSelectAllInfo_DENumber;//获取所有信息 指定的定额编号

		static const int		m_iSelectAllInfo_nameOrdenum;
		static const PmTString	m_strSelectAllInfo_nameOrdenum;//获取所有信息 模糊搜索

		static const int		m_iSelectAllInfo_chapter;
		static const PmTString	m_strSelectAllInfo_chapter;//获取所有信息 章节编号

		static const int		m_iSelectAllInfo_id;
		static const PmTString	m_strSelectAllInfo_id;//获取所有信息 章节编号
	};
};
