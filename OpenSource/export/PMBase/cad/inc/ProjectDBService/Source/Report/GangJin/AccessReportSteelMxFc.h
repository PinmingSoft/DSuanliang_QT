

#pragma once 

/**
 * @brief 
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2015年7月21日]
 * @note  
 */


#include "..\AccessReportBase.h"


class  PMProjectDBSERVICE CReportSteelMxFcTable : public CSQLDataSet
{
public:
	CReportSteelMxFcTable() ;
	~CReportSteelMxFcTable() ;

	virtual int InitFieldStr() ;

public:

};


//////////////////////////////////////////////////////////////////////////
class PMProjectDBSERVICE CAccessReportSteelMxFcTable : public CAccessReportTable
{
public:
	DYNAMIC_CREATE_REPORTTABLE( CAccessReportSteelMxFcTable , CReportSteelMxFcTable ) ;

public:
	CAccessReportSteelMxFcTable() ;
	virtual ~CAccessReportSteelMxFcTable() ; 

};




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///
/// 明细表的整体操作
/// 
class PMProjectDBSERVICE CReportSteelMxFcOpr : public CReportTableOprBase
{
public:
	CReportSteelMxFcOpr() ; 
	virtual ~CReportSteelMxFcOpr() ; 

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