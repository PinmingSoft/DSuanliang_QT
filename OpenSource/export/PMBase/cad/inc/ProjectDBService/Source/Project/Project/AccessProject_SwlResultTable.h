#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CAccessProject_SwlResultTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_SwlResultTable(void);

	~CAccessProject_SwlResultTable(void);

	virtual BOOL TryUpdateTableField();

	/**
	* @brief  获取计算结果 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/7/2012]
	*/
	BOOL GetCalResult(int iComID,const CString & strHandle,CString & strResult);

	/**
	* @brief  获取计算结果 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/7/2012]
	*/
	BOOL GetCalResult_TableCtrl(int iComID,CPMSQLTableCtrl *& pSQLTableCtrl);

	//删除 所有记录
	BOOL DeleteAllRow();

	CSQLDataSet * GetDataSet();

	CSQLDataSet * GetEmptyDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	BOOL GetTable_MaxID(int & iMaxID);

	/**
	* @brief  删除指定的楼层 与 构件类型的记录 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [20/7/2012]
	*/
	BOOL DelResultFloor_ComType(CUIntArray &iFloorIDArr, CUIntArray &iComTypeArr);

	//删除结果，按楼层与句柄
	void DelResultFloor_Handle(int floorid,const CStringArray & handls);

	void DeleteDirtyData();


	BOOL GetTableCtrl_FloorComType(int iFloorID,int iComType,CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetDataSet_FloorComType(int iFloorID,int iComType,CSQLDataSet *& pSQLDataSet);

	/// 获取某个楼层所有的计算结果中的句柄
	void GetHandleAtFloor(int iFloorID,CStringArray & arrHandle);

	/// 
	BOOL GetTableCtrl_ForReport( const CString & strFloorIds , const CString & strComTypes , const CString & strOrderBy ,  CPMSQLTableCtrl *& pSqliteTableCtrl ) ;

	/// 
	BOOL GetTableCtrlForReportJmInfo(  const CString & strFloorIds , const CString & strComTypes , 
		const CString & strGroupBy , const CString & strOrderBy ,  
		CPMSQLTableCtrl *& pSqliteTableCtrl ) ;

public:
	BOOL DelKcResult( const CUIntArray & aryFloorId )  ;


public:

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		/// 
		static const int			m_iSelectResult_ComID;
		static const PmTString		m_strSelectResult_ComID;//通过 Handle 获取 计算结果

		/// 
		static const int			m_iSelectResult_ComTypeFloor;
		static const PmTString		m_strSelectResult_ComTypeFloor;

		/// 
		static const int			m_iSelectReult_ForReport ; 
		static const PMTSTRING		m_strSelectReult_ForReport ;

		/// 需要连接 gjjminfo 表
		static const int			m_iSelectResultForReportJmInfo ;
		static const PmTString		m_strSelectResultForReportJmInfo ; 


	};
};
