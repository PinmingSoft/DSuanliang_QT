

#pragma once 

/**
 * @brief 钢筋级别 的图像表 
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2015年7月28日]
 * @note  
 */


#include "..\AccessReportBase.h"


class  PMProjectDBSERVICE CReportGjjbTable : public CSQLDataSet
{
public:
	CReportGjjbTable() ;
	~CReportGjjbTable() ;

	virtual int InitFieldStr() ;

public:

};


//////////////////////////////////////////////////////////////////////////
class PMProjectDBSERVICE CAccessReportGjjbTable : public CAccessReportTable
{
public:
	DYNAMIC_CREATE_REPORTTABLE( CAccessReportGjjbTable , CReportGjjbTable ) ;

public:
	CAccessReportGjjbTable() ;
	virtual ~CAccessReportGjjbTable() ; 

};
