
#pragma once 

/**
 * @brief �͹�����ص� ��Ϣ
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2015��3��26��]
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