#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_QDXMAttTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_QDXMAttTable)

	CProject_QDXMAttTable();
	virtual ~CProject_QDXMAttTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;
		static const CString qdnumber;
		static const CString parmdisplayname;
		static const CString parmvalue;
		static const CString listdata;
		static const CString checkreg;
		static const CString inputmode;	

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_QDXMAttTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_QDXMAttTable(void);

	virtual ~CAccessProject_QDXMAttTable(void);

	virtual BOOL TryUpdateTableField();

	/**
	* @brief 获取表格所有数据   
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	static PmTString GetSQL(const int iSQLIndex);

	BOOL GetTableCtrl_QDNumber(const CString & strQDNumber,CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetDataSet_QDNumber(const CString & strQDNumber,CSQLDataSet *& pSQLDataSet);

	BOOL SaveQDXMTZDataSet(CString strQDID, NDataModelDataSet *pSaveDataSet);

	NDataModelDataSet * GetQDXMTZ_Dataset(CString strQDID);

	//删除 所有记录
	BOOL DeleteAllRow();

	struct SQLInfo
	{
		static const int		m_iSelectInfo_QDNumber;
		static const PmTString	m_strSelectInfo_QDNumber;
	};

};
