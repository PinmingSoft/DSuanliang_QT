

#pragma once 

/**
 * @brief 钢筋明细表 相关联的表
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2015年3月27日]
 * @note  
 */

#include "..\AccessReportBase.h"

class  PMProjectDBSERVICE CReportSteelMxFloorTable : public CSQLDataSet
{
public:
	CReportSteelMxFloorTable() ;
	~CReportSteelMxFloorTable() ;

	virtual int InitFieldStr() ;

public:

};


//////////////////////////////////////////////////////////////////////////
class PMProjectDBSERVICE CAccessReportSteelMxFloorTable : public CAccessReportTable
{
public:
	DYNAMIC_CREATE_REPORTTABLE( CAccessReportSteelMxFloorTable , CReportSteelMxFloorTable ) ;

public:
	CAccessReportSteelMxFloorTable() ;
	virtual ~CAccessReportSteelMxFloorTable() ; 

};


///
class  PMProjectDBSERVICE CReportSteelMxComponentsTable : public CSQLDataSet
{
public:
	CReportSteelMxComponentsTable() ;
	~CReportSteelMxComponentsTable() ;

	virtual int InitFieldStr() ;

public:

};

//////////////////////////////////////////////////////////////////////////
class PMProjectDBSERVICE CAccessReportSteelMxComponentsTable : public CAccessReportTable
{
public:
	DYNAMIC_CREATE_REPORTTABLE( CAccessReportSteelMxComponentsTable , CReportSteelMxComponentsTable ) ;

public:
	CAccessReportSteelMxComponentsTable() ;
	virtual ~CAccessReportSteelMxComponentsTable() ; 

};



///
class  PMProjectDBSERVICE CReportSteelMxResultTable : public CSQLDataSet
{
public:
	CReportSteelMxResultTable() ;
	~CReportSteelMxResultTable() ;

	virtual int InitFieldStr() ;

public:

};

//////////////////////////////////////////////////////////////////////////
class PMProjectDBSERVICE CAccessReportSteelMxResultTable : public CAccessReportTable
{
public:
	DYNAMIC_CREATE_REPORTTABLE( CAccessReportSteelMxResultTable , CReportSteelMxResultTable ) ;

public:
	CAccessReportSteelMxResultTable() ;
	virtual ~CAccessReportSteelMxResultTable() ; 

};

///
class  PMProjectDBSERVICE CReportSteelMxJtContentTable : public CSQLDataSet
{
public:
	CReportSteelMxJtContentTable() ;
	~CReportSteelMxJtContentTable() ;

	virtual int InitFieldStr() ;

public:

};

//////////////////////////////////////////////////////////////////////////
class PMProjectDBSERVICE CAccessReportSteelMxJtContentTable : public CAccessReportTable
{
public:
	DYNAMIC_CREATE_REPORTTABLE( CAccessReportSteelMxJtContentTable , CReportSteelMxJtContentTable ) ;

public:
	CAccessReportSteelMxJtContentTable() ;
	virtual ~CAccessReportSteelMxJtContentTable() ; 

};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///
/// 明细表的整体操作
/// 
class PMProjectDBSERVICE CReportSteelMxTableOpr :public CReportTableOprBase
{
public:
	CReportSteelMxTableOpr() ; 
	virtual ~CReportSteelMxTableOpr() ; 

	static int GetVersion() 
	{
		return m_iVersion ;
	}

public:
	virtual void	CreateTable() ; 

	/// 清楚所有的数据
	virtual void	ClearTable() ; 

	/// 已经有生成了的数据
	virtual BOOL	HasData() ; 

public:
	static const int m_iVersion ; 

};