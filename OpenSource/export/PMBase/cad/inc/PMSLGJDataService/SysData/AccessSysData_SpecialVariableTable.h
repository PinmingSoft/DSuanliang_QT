

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
class PmSLGJDataServiceAPI CSysSpecialVariableTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysSpecialVariableTable)

	CSysSpecialVariableTable();
	~CSysSpecialVariableTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString comtype ; 
		static const CString variables ; 

		static int comtype_Idx ; 
		static int variables_Idx ; 

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


class PmSLGJDataServiceAPI CAccessSysData_SpecialVariableTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_SpecialVariableTable(void);
	virtual ~CAccessSysData_SpecialVariableTable(void);

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

	////////////////////////////////////////////////////////////////
	/// at 2011年2月17日  15:20  by yxy
	/// 获取变量的字符串
	CString  GetVariables( const int & nComType ) ; 

	/// 获取变量的 DataSet 
	NDataModelDataSet * GetVariableDataSet( const int & nComType ) ; 

	///
	void	GetVariables( const int &nComType , CStringArray & ary_variable ) ; 

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
	NDataModelDataSet * GetDataSet() ; 

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
		static const int m_iGetVariables ; 
		static PMTSTRING m_strGetVariables ; 
	} ;
};
