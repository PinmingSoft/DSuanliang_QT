#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_OwnGangjinVectorTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_OwnGangjinVectorTable)

	CProject_OwnGangjinVectorTable();
	virtual ~CProject_OwnGangjinVectorTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;
		static const CString gangjinvectorgraph;        //钢筋图信息

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_OwnGangjinVectorTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_OwnGangjinVectorTable(void);
	CAccessProject_OwnGangjinVectorTable(BOOL bTemplateDb);

	virtual ~CAccessProject_OwnGangjinVectorTable(void);

	virtual BOOL TryUpdateTableField();

	static PmTString GetSQL(const int iSQLIndex);

	/**
	* @brief  获取 自定义 钢筋 Buffer 
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	BOOL GetOwnGangjinVector(int iComID,LPVOID & pBuffer,long & lBufferSize);

	/**
	* @brief  修改 自定义钢筋 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	BOOL SetOwnGangJinVector(int iComID,LPVOID pBuffer,long lBufferSize);

	/**
	* @brief  删除 自定义钢筋 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	BOOL RemoveOwnGangJinVector(int iComID);

	BOOL RemoveOwnGangJinVector(const CUIntArray & iComIDArr);
	
	
	CSQLDataSet * GetDataSet();

	struct PMProjectDBSERVICE SQLInfo
	{
		static const int		m_iSelectOwnGangJin_Sql;
		static const PmTString	m_strSelectOwnGangJin_Sql;

		static const int		m_iUpdateOwnGangJin_Sql;
		static const PmTString	m_strUpdateOwnGangJin_Sql;

		static const int		m_iInsertOwnGangJin_Sql;
		static const PmTString	m_strInsertOwnGangJin_Sql;

		static const int		m_iDeleteOwnGangJin_Sql;
		static const PmTString	m_strDeleteOwnGangJin_Sql;
	};
};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 
class PMProjectDBSERVICE CProject_CustomizeSteelDiagramTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_CustomizeSteelDiagramTable)

	CProject_CustomizeSteelDiagramTable();
	virtual ~CProject_CustomizeSteelDiagramTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString log_id ; /// > 100000
		static const CString id;
		static const CString steeldata;       
		static const CString formula ;       
		static const CString formulaparms ;  
		static const CString height ;
		static const CString msg ;

		static const int	iLogIdBase ; 

		static const CString table_name;
	};

	virtual int InitFieldStr();
};



class PMProjectDBSERVICE CAccessProject_CustomizeSteelDiagramTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_CustomizeSteelDiagramTable(void);

	virtual ~CAccessProject_CustomizeSteelDiagramTable(void);

public:

	static	BOOL	IsCustomizeId( const int iSteelLogId ) ; 

	virtual BOOL TryUpdateTableField();

	static PmTString GetSQL(const int iSQLIndex);

	CSQLDataSet * GetDataSet() ;

	CSQLDataSet * GetDataSet( const CString strSteelId ) ;
	/**
	* @brief   插入一行 ，返回id 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-12-19]
	*/
	CString		InsertRow() ;

	CString		InsertRow( int & iInsertLogId ) ;

	/// 
	BOOL		GetSteelData( const CString & strSteelId ,LPVOID & pSteelBuffer ,long & lBufferSize ) ;

	/// 
	BOOL		SetSteelData(  const CString & strSteelId , const LPVOID & pSteelBuffer ,const long  lBufferSize) ;

	/// 
	BOOL		GetSteelHeight( const CString & strSteelId , int & iHeight ) ; 

	/// 
	BOOL		SetSteelHeight( const CString & strSteelId , const int iHeight ) ;

	/// 
	BOOL		GetFormula( const CString & strSteelId , CString & strFormula ) ;

	/// 
	BOOL		SetFormula( const CString & strSteelId , const CString & strFormula ) ;

	/// 
	BOOL		GetFormulaParams( const CString & strSteelId , CPM_TranStringDataSet *& pSteelParms ) ;

	/// 
	BOOL		SetFormulaParams( const CString & strSteelId , CPM_TranStringDataSet * pSteelParms ) ;

	/// 
	BOOL		SetFormulaParams( const CString & strSteelId , const LPVOID & pSteelBuffer ,const long  lBufferSize ) ;


	CPM_TranStringDataSet * GetSteelParamDataSet() ; 


	///
	BOOL		DeleteSteelById(const CString & strId);


	///
	CString		GetFormulaParamsByLogId(int nLogId);


	///	批量插入
	bool		InsertRows(CArray<CMemFile*,CMemFile*&> & Files,
							CStringArray & aryFormular,
							CArray<NDataModelDataSet*, NDataModelDataSet*&> & aryDataSet,
							/*out*/CStringArray & aryIds);

	///	通过id获取logId
	BOOL		GetSteelIdByLogId(int nLogId, CString & strId);

	/// 
	BOOL			GetLogId( const CString & strId , int & iLogId ) ;

protected:
	
	BOOL		GetTableCtrl_SteelId( const CString & strSteelId , CPMSQLTableCtrl *& pSQLTableCtrl ) ;

public:
	struct PMProjectDBSERVICE SQLInfo
	{
		/// insert into customizesteeldiagram(log_id , id) values(? , ?) 
		static const int m_iInsertRow ; 
		static const PmTString m_strInsertRow ; 

		
		/// select * from customizesteeldiagram where id = ? 
		static const int m_iGetTableCtrl_SteelId ;
		static const PmTString m_strGetTableCtrl_SteelId ;

		static const int m_iGetTableCtrl_LogId;
		static const PmTString m_strGetTableCtrl_LogId;
	} ;


} ;