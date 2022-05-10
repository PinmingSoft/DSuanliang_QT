#pragma once
//#include "..\accesstable.h"


class PMProjectDBSERVICE CAccessProject_FloorDJXSTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_FloorDJXSTable(void);

	virtual ~CAccessProject_FloorDJXSTable(void);

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
	virtual BOOL TryUpdateTableField();

	BOOL GetDJXS_Buffer(int nComType, BOOL bSx ,LPVOID & pBuffer,ULONG & lBufferSize);

	BOOL GetDJXS_Str( const int iComType , const BOOL bSx , CString & strDjxs ) ;

	BOOL GetDJXS_Str_Gj( const int iComType , const BOOL bSx , CString & strDjxs ) ;


	NDataModelDataSet * GetDataSet( const int iComType , BOOL bSx = FALSE ) ;

	CSQLDataSet * GetEmptyDataSet();

	void	ClearTable() ; 

	/// 构件法获取搭接形式
	NDataModelDataSet * GetDataSet_Gj( const int iComType , BOOL bSx = FALSE ) ;

	static CString GetDJXSListDta();

	static CPM_StorageDataSet * GetMiniDataSet();

	BOOL GetDJXS_ZJValue( const int iFloorID, const int iComType,const CString & strZJ,CString & strDJValue);

public:
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

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);
	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;



protected:

	CPM_StorageDataSet * GetJcData();
	CPM_StorageDataSet * GetQtData(int nComType);
	CPM_StorageDataSet * GetBanData();
	CPM_StorageDataSet * GetZhuData();
	CPM_StorageDataSet * GetQiangData(BOOL bSx);
	CPM_StorageDataSet * GetAnZhuData();

	CPM_StorageDataSet * GetDataSet(const CString & strColName);

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
	static PmTString m_strSelectDJXS_SQL;//获取 comparm buffer的sql；


};



/**
* @brief   封装一些临时对象的定义操作 (充当 新老Access的 适配器)
*
*          
* @note  : 不需要每一个用到的地方都去定义一个临时对象 ， 有一些参数类型的转化可以在该类中实现
*
* @author: 杨兴耀
* @date  : [2012-7-17]
*/

class PMProjectDBSERVICE CProjectFloorDjxsOpr
{
public:
	CProjectFloorDjxsOpr() ;
	~CProjectFloorDjxsOpr() ; 

public:
	static BOOL GetDJXS_ZJValue( const int iFloorID, const int iComType,const CString & strZJ,CString & strDJValue);

	static NDataModelDataSet * GetDataSet( const int iComType , BOOL bSx = FALSE ) ;
};
