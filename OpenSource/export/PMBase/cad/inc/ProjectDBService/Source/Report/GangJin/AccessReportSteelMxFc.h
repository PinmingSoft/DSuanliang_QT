

#pragma once 

/**
 * @brief 
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2015��7��21��]
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
/// ��ϸ����������
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

	/// ������е�����
	virtual void	ClearTable() ; 

	/// �Ѿ��������˵�����
	virtual BOOL	HasData() ; 

public:
	static const int m_iVersion ; 

};