

#pragma once 

/**
 * @brief �ֽ�� ��ͼ��� 
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2015��7��28��]
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
