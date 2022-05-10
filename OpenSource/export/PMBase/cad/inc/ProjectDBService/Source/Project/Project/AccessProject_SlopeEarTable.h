
#pragma once
/**
 * @brief 添加对CAccessProject_SlopeEarTable数据库表的操作
 *
 *        
 * @author 郑琪崇
 * @version v1.0
 * @date  2016年3月17日   9:10
 * @note  
 */

class PMProjectDBSERVICE CAccessProject_SlopeEarTable :
	public CPMSLAccessTable
{
public: 
	CAccessProject_SlopeEarTable(void);

	virtual ~CAccessProject_SlopeEarTable(void);

	virtual BOOL TryUpdateTableField();


public:
	CSQLDataSet * GetDataSet() ;

	CPM_StorageDataSet * GetStorageDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	static PMTSTRING	GetSql( const int iType ) ;

	void GetParmValue( const CString & strParmname, CString & strParmValue );
public:
	//固定的SQL 集合
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 
	} ;

protected:
	//固定的SQL 集合
	static PmTString m_strSelectFptf_SQL;//获取 comparm buffer的sql；
};