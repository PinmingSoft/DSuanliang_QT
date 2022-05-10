

#pragma once 


#include "AccessSysDataTable.h"

/**
 * @brief 
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CSysFaceHelpInfoTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysFaceHelpInfoTable)

	CSysFaceHelpInfoTable();
	~CSysFaceHelpInfoTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id ;
		static const CString comtype ;
		static const CString colname ;
		static const CString chname ;
		static const CString value ;
		static const CString exp ;

		static int id_Idx ;
		static int comtype_Idx ;
		static int colname_Idx ;
		static int chname_Idx ;
		static int value_Idx ;
		static int exp_Idx ;

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


class PmSLGJDataServiceAPI CAccessSysData_FaceHelpInfoTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_FaceHelpInfoTable(void);
	virtual ~CAccessSysData_FaceHelpInfoTable(void);

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

	NDataModelDataSet * GetDataSet( const int iComType , const CString & strColName ) ;

	NDataModelDataSet * GetDataSet( const int iComType  ) ;

	/// 
	/// 获取空的DataSet 
	CSysFaceHelpInfoTable * GetEmptyDataSet();

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
		static const int m_iGetDataSet_ComType ; 
		static PMTSTRING m_strGetDataSet_ComType ; 

		///
		static const int m_iGetDataSet_ComType_ParamName ; 
		static PMTSTRING m_strGetDataSet_ComType_ParamName ; 
	} ;
};
