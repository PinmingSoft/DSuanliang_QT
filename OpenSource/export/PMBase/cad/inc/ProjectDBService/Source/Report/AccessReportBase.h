
#pragma once 

/**
 * @brief 报表数据库的基类
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2015年3月26日]
 * @note  
 */

#define DYNAMIC_CREATE_REPORTTABLE( CLASS_NAME ,TABLE_NAME) \
	virtual CSQLDataSet * GetEmptyDataSet() const; \
	virtual CSQLDataSet * GetDataSet() const ;\
	virtual CString GetTableName() const ; \
	virtual	void	ClearTable() const ;


#define DYNAMIC_IMPLEMENT_REPORTTABLE(CLASS_NAME ,TABLE_NAME ) \
	CSQLDataSet * CLASS_NAME::GetEmptyDataSet() const {\
	TABLE_NAME * pDataSet = PMNew(TABLE_NAME) ; \
	pDataSet->InitFieldStr() ; \
	pDataSet->SetSqlBaseCtrl(m_pDbBaseCtrl->GetSQLBaseCtrl() ); \
	return pDataSet ;\
	}\
	CSQLDataSet * CLASS_NAME::GetDataSet() const {\
	if(NULL == m_pDbBaseCtrl) \
		return NULL;\
	TABLE_NAME * pDataSet = PMNew(TABLE_NAME);\
	pDataSet->InitFieldStr(); \
	if(!m_pDbBaseCtrl->GetDataSet(pDataSet)){\
		PMDelete(pDataSet);\
		return NULL;\
	} \
	return pDataSet;\
	}\
	CString CLASS_NAME::GetTableName() const {\
	TABLE_NAME * pDataSet = PMNew(TABLE_NAME) ; \
	pDataSet->InitFieldStr() ; \
	CString strTableName = pDataSet->GetTableName() ; \
	PMDelete( pDataSet ) ;\
	return strTableName ; \
	} \
	void	CLASS_NAME::ClearTable() const {\
	CString strTableName = GetTableName() ; \
	CString strDelete ;\
	strDelete.Format( _T("delete from %s") , strTableName ) ;\
	m_pDbBaseCtrl->ExecuteSQL( strDelete ) ; \
	} 


#define HASDATA(TABLENAME) \
	{\
	int iCount = 0; \
	pDbCtrl->GetTable_RowCount( TABLENAME , iCount ) ; \
	if ( iCount < 1 ) \
	{\
		return FALSE ; \
	}\
	}

#include "ReportDataFieldDef.h"

class  PMProjectDBSERVICE CReportTable : public CSQLDataSet
{
public:
	CReportTable() ;
	~CReportTable() ;

	virtual int InitFieldStr()
	{
		return 0 ; 
	}

public:
	
};

class  PMProjectDBSERVICE CAccessReportTable : public CPMSLAccessTable
{
public:
	DYNAMIC_CREATE_REPORTTABLE( CAccessReportTable , CReportTable ) ;
public:
	CAccessReportTable() ;

	~CAccessReportTable() ;

	/**
	* @brief   尝试 升级表结构
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/6/2012]
	*/
	virtual BOOL TryUpdateTableField() 
	{
		return TRUE ;
	}
};



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 表操作类的基类
class PMProjectDBSERVICE CReportTableOprBase 
{
public:
	CReportTableOprBase() ; 
	virtual ~CReportTableOprBase() ; 

public:
	virtual void	CreateTable() = 0 ; 

	/// 清楚所有的数据
	virtual void	ClearTable() = 0 ; 

	/// 已经有生成了的数据
	virtual BOOL	HasData() = 0 ; 

protected:
	BOOL  IsTableExsit( const CString & strTableName )  ;

	BOOL DoCreateSQLTable( CSQLDataSet * pTableDataSet ) ;

};