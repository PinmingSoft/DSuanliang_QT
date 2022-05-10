

#pragma once 

////#include "..\accesstable.h"


class PMProjectDBSERVICE CAccessProject_TtymjTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_TtymjTable(void);

	~CAccessProject_TtymjTable(void);

public:
	virtual BOOL TryUpdateTableField();

	

	/**
	* @brief   获取版本号
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-7-3]
	*/
	static	int	GetCurVersion() ;

	NDataModelDataSet * GetEmptyDataSet() ;

	BOOL SaveDataSet( CSQLDataSet * pDataSet ) ;

	int Insert( 
		NDataModelDataSet * pDataSet ,
		const int iId ,
		const int nComType ,
		const CString & strShowName ,
		const CString & strTtymj 
		) ;

	/**
	* @brief   获取整表的数据，不推荐使用，
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-7-12]
	*/
	CSQLDataSet * GetDataSet() ; 

	int		GetMaxId() ;

	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;


public:
	//固定的SQL 集合
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 
	} ;

};
