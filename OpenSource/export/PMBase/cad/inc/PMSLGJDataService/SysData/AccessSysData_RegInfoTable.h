

#pragma  once 


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
class PmSLGJDataServiceAPI CSysRegInfoTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysRegInfoTable)

	CSysRegInfoTable();
	~CSysRegInfoTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString ID ;
		static const CString RegName ;		/// 名称前后添加$符号，如 $2B25$
		static const CString RegInfo ;		/// 原子的正则表达式，不带括号的。
		static const CString RegInfoKH ;	/// 原子的正则表达式，带括号的。
		static const CString Type ;			
		/// 表达式的类型.目前两位，如 10 表示是原子表达式，不是钢筋表达式
		/// 第一位是否是原子表达式 1:原子表达式。2:复杂表达式。
		/// 第二位是否是钢筋表达式1：钢筋表达式，0 ：不是钢筋的表达式

		static int ID_Idx ;
		static int RegName_Idx ;		
		static int RegInfo_Idx ;		
		static int RegInfoKH_Idx ;	
		static int Type_Idx ;	


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


class PmSLGJDataServiceAPI CAccessSysData_RegInfoTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_RegInfoTable(void);
	virtual ~CAccessSysData_RegInfoTable(void);

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
	} ;
};
