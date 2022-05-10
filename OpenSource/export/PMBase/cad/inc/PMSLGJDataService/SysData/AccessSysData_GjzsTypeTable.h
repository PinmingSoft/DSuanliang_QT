

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
class PmSLGJDataServiceAPI CSysGjzsTypeTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysGjzsTypeTable)

	CSysGjzsTypeTable();
	~CSysGjzsTypeTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString GJType;
		static const CString sideType;
		static const CString zs;
		static const CString ZSType;
		static const CString VectorDiagramID;

		static int GJType_Idx ;
		static int sideType_Idx ;
		static int zs_Idx ;
		static int ZSType_Idx ;
		static int VectorDiagramID_Idx ;

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


class PmSLGJDataServiceAPI CAccessSysData_GjzsTypeTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_GjzsTypeTable(void);
	virtual ~CAccessSysData_GjzsTypeTable(void);

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
	NDataModelDataSet * Get_GJZSType_DataSet();

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
