

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
class PmSLGJDataServiceAPI CSysSteelDiagram_ParamsTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysSteelDiagram_ParamsTable)

	CSysSteelDiagram_ParamsTable();
	~CSysSteelDiagram_ParamsTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString sdid;
		static const CString parmName;
		static const CString ParmType;
		static const CString ParmValue;
		static const CString ScriptParm;

		static int id_Idx ;
		static int sdid_Idx ;
		static int parmName_Idx ;
		static int ParmType_Idx ;
		static int ParmValue_Idx ;
		static int ScriptParm_Idx ;

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


class PmSLGJDataServiceAPI CAccessSysData_SteelDiagram_ParamsTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_SteelDiagram_ParamsTable(void);
	virtual ~CAccessSysData_SteelDiagram_ParamsTable(void);

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

	NDataModelDataSet * GetEmptyDataSet() ;

	NDataModelDataSet * Get_SteelJTParms_DataSet( const int iSteelID);

	CString GetSteeldiagramParms( const int nDiagramID );

	void GetSteeldiagramParms( const int nDiagramID , CStringArray & aryParms ) ;

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
		static const int m_iGet_SteelJTParms_DataSet ;
		static PMTSTRING m_strGet_SteelJTParms_DataSet ; 

		/// 
		static const int m_iGetSteeldiagramParms ;
		static PMTSTRING m_strGetSteeldiagramParms ; 
	} ;
};
