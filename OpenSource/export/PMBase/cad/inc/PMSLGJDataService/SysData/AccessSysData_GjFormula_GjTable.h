
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
class PmSLGJDataServiceAPI CSysGjFormula_GjTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysGjFormula_GjTable)

	CSysGjFormula_GjTable();
	~CSysGjFormula_GjTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString ID ;
		static const CString GanJinMode;
		static const CString GJJSFS ;
		static const CString GJZS ;
		static const CString GJBH ;
		static const CString ZJSL ;
		static const CString BBCD ;
		static const CString HBCD ;
		static const CString GJZCD ;

		static int ID_Idx ;
		static int GanJinMode_Idx ;
		static int GJJSFS_Idx ;
		static int GJZS_Idx ;
		static int GJBH_Idx ;
		static int ZJSL_Idx ;
		static int BBCD_Idx ;
		static int HBCD_Idx ;
		static int GJZCD_Idx ;

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


class PmSLGJDataServiceAPI CAccessSysData_GjFormula_GjTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_GjFormula_GjTable(void);
	virtual ~CAccessSysData_GjFormula_GjTable(void);

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
