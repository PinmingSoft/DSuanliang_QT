#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CQDBillTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CQDBillTable)

	CQDBillTable();
	virtual ~CQDBillTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString qdnumber;
		static const CString name;
		static const CString unit;
		static const CString nodeid;
		static const CString extendflag;
		static const CString sdid;
		static const CString dechapter;
		
		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CAccessQDData_BillTable :
	public CPMSLAccessTable
{
public:
	CAccessQDData_BillTable(void);

	virtual ~CAccessQDData_BillTable(void);
	
	virtual BOOL TryUpdateTableField();

	/**
	* @brief  获取所有 内容  
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	NDataModelDataSet * GetEmptyDataSet() ; 

	/**
	* @brief  获取指定 清单 的 记录集
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	BOOL GetTableCtrl_QDNumber(const CString & strQDNumber,CPMSQLTableCtrl *& pSQLTableCtrl);

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		const static int		m_iSelectAllInfo_QDNumber;
		const static PmTString	m_strSelectAllInfo_QDNumber;
	};

};
