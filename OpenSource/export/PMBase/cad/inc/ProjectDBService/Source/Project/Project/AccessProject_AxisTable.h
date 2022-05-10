#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_AxisTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_AxisTable)

	CProject_AxisTable();
	virtual ~CProject_AxisTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;
		static const CString type;						//轴网类型
		static const CString name;						//轴网名
		static const CString axisxml;						//轴网xml串-----详细信息

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

//轴网数据库访问
class PMProjectDBSERVICE CAccessProject_AxisTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_AxisTable(void);

	virtual ~CAccessProject_AxisTable(void);

	virtual BOOL TryUpdateTableField();

	/**
	* @brief   获取整表的数据，不推荐使用，
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-7-12]
	*/
	CSQLDataSet * GetDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet *& pSQLDataSet);
	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;


public:
	//固定的SQL 集合
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 
	} ;
};
