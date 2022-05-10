
#pragma once 

/**
 * @brief 和工程相关的 信息
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2015年3月26日]
 * @note  
 */

#include "AccessReportBase.h"

//////////////////////////////////////////////////////////////////////////
class  PMProjectDBSERVICE CReportProjectInfoTable : public CReportTable
{
public:
	CReportProjectInfoTable() ;
	~CReportProjectInfoTable() ;

public:
	/// 
	virtual int InitFieldStr()  ;

public:

};

//////////////////////////////////////////////////////////////////////////
class PMProjectDBSERVICE CAccessReportProjectInfoTable : public CAccessReportTable
{
public:
	DYNAMIC_CREATE_REPORTTABLE( CAccessReportProjectInfoTable , CReportProjectInfoTable ) 
public:
	CAccessReportProjectInfoTable() ;
	virtual ~CAccessReportProjectInfoTable() ; 

};