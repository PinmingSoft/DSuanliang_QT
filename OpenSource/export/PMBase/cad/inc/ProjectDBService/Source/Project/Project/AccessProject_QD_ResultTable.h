#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CProjectQD_ResultTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProjectQD_ResultTable)

	CProjectQD_ResultTable();
	virtual ~CProjectQD_ResultTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;
		static const CString comtype;
		static const CString name;
		static const CString deid;
		static const CString dename;
		static const CString decode;
		static const CString unit;
		static const CString quantity;
		static const CString sections;
		static const CString formulas;
		static const CString editmode;
		static const CString rationrow;     //定额对应在 Ration表中对应的 行号

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_QD_ResultTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_QD_ResultTable(void);

	virtual ~CAccessProject_QD_ResultTable(void);

	virtual BOOL TryUpdateTableField();

	/**
	* @brief  返回所有记录  
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

	//删除 所有记录
	BOOL DeleteAllRow();
};
