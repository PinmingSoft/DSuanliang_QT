

#pragma once 


#include "AccessSysDataTable.h"

/**
 * @brief 
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-4]
 * @note  
 */
class PmSLGJDataServiceAPI CSysMacrosTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysMacrosTable)

	CSysMacrosTable();
	~CSysMacrosTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString key_ch ;
		static const CString key_en ;
		static const CString content ;
		static const CString description ;

		static int key_ch_Idx ;
		static int key_en_Idx ;
		static int content_Idx ;
		static int description_Idx ;

		/// idx 递增的辅助变量
		/// idx 需要在函数 InitFieldStr 外 ，初始化为有意义的值
		/// 且赋值的顺序应该和 InitFieldStr中添加的顺序一样
		static int idx_step ; 
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const CString table_name_v2 ;
		static const int cur_version ; 
	};
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
class PmSLGJDataServiceAPI CSysMacrosV2Table : public CSysMacrosTable
{
public:
	DECLARE_DYNCREATE(CSysMacrosV2Table)

	CSysMacrosV2Table();
	~CSysMacrosV2Table() ;

public:
	virtual int InitFieldStr();

} ; 

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 

class PmSLGJDataServiceAPI CAccessSysData_MacrosTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_MacrosTable(void);
	virtual ~CAccessSysData_MacrosTable(void);

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

	/// 获取脚本的内容
	BOOL GetMacroContent( const CString & sPath,CString & sContent );

	BOOL SetMacroContent( const CString & sPath,const CString & sContent );

	BOOL GetDataSet_MacroPath(const CString & strPath,CSQLDataSet *& pSQLDataSet);

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


public:
	//固定的SQL 集合
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetDataSet_Key_Ch ; 
		static PMTSTRING m_strGetDataSet_Key_Ch ; 

		/// 
		static const int m_iGetMacroContent ; 
		static PMTSTRING m_strGetMacroContent ; 
	} ;
};




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 

class PmSLGJDataServiceAPI CAccessSysData_MacrosV2Table : public CAccessSysDataTable 
{
public:
	CAccessSysData_MacrosV2Table(void);
	virtual ~CAccessSysData_MacrosV2Table(void);

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

	/// 获取脚本的内容
	BOOL GetMacroContent( const CString & sPath,CString & sContent );

	BOOL SetMacroContent( const CString & sPath,const CString & sContent );

	BOOL GetDataSet_MacroPath(const CString & strPath,CSQLDataSet *& pSQLDataSet);

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


public:
	//固定的SQL 集合
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetDataSet_Key_Ch ; 
		static PMTSTRING m_strGetDataSet_Key_Ch ; 

		/// 
		static const int m_iGetMacroContent ; 
		static PMTSTRING m_strGetMacroContent ; 
	} ;
};
