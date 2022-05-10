

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
class PmSLGJDataServiceAPI CSysGjSetUpTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysGjSetUpTable)

	CSysGjSetUpTable();
	~CSysGjSetUpTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString gjtype;
		static const CString combinedzs;
		static const CString combinedType;
		static const CString VertorDiagramID;

		static int id_Idx ;
		static int gjtype_Idx ;
		static int combinedzs_Idx ;
		static int combinedType_Idx ;
		static int VertorDiagramID_Idx ;

		/// idx 递增的辅助变量
		/// idx 需要在函数 InitFieldStr 外 ，初始化为有意义的值
		/// 且赋值的顺序应该和 InitFieldStr中添加的顺序一样
		static int idx_step ; 
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};
};


class PmSLGJDataServiceAPI CAccessSysData_GjSetUpTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_GjSetUpTable(void);
	virtual ~CAccessSysData_GjSetUpTable(void);

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

	/// 
	NDataModelDataSet * Get_GJSetup_DataSet() ;

	///注释：杨兴耀 [2009年12月4日]                                  
	///根据 肢数获取 组合类型
	CString GetCombinedType( const CString & combinedzs );

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
		static const int m_iGetCombinedType ; 
		static PMTSTRING	m_strGetCombinedType ; 
	} ;
};
