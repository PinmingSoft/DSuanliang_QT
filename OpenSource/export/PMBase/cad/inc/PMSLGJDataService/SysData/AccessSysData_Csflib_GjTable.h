

#pragma once 



#include "AccessSysDataTable.h "

/**
 * @brief 
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CSysCsflib_GjTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysCsflib_GjTable)

	CSysCsflib_GjTable();
	~CSysCsflib_GjTable() ;

public:
	virtual int InitFieldStr();

public:

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString libcode;
		static const CString comtype;
		static const CString parmName;
		static const CString des ;

		static int libcode_Idx ;
		static int comtype_Idx ;
		static int parmName_Idx ;
		static int des_Idx ;

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


class PmSLGJDataServiceAPI CAccessSysData_Csflib_GjTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_Csflib_GjTable(void);
	virtual ~CAccessSysData_Csflib_GjTable(void);

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
	///
	///  dataset 需要外围维护，可以使用列的index来操作读写数据
	/// 
	NDataModelDataSet * GetLibDataSet( const int comType, const CString & parmName) ;


	///
	///
	///  dataset 需要外围维护，可以使用列的index来操作读写数据
	/// 
	CSysCsflib_GjTable * GetEmptyDataSet();

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
		static const int m_iGetLibDataSet ;
		static PMTSTRING m_strGetLibDataSet ;
	};
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

class PmSLGJDataServiceAPI CSysDataCsflibGjOpr
{
public:
	CSysDataCsflibGjOpr() ;
	~CSysDataCsflibGjOpr() ; 

public:

	static NDataModelDataSet * GetLibDataSet( const int comType, const CString & parmName) ;
};
