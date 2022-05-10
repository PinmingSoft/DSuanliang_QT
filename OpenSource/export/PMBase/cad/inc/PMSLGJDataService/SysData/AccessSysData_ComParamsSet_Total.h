

#pragma once 



#include "AccessSysData_ComParamsSet.h"

/**
 * @brief comparamsset_total
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CSysComParamsSet_TotalTable : public CSysComParamsSetTable
{
public:
	DECLARE_DYNCREATE(CSysComParamsSet_TotalTable)

	CSysComParamsSet_TotalTable() ; 
	~CSysComParamsSet_TotalTable() ;

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CAccessSysData_ComParamsSet_TatalTable :
	public CAccessSysDataTable
{
public:

	CAccessSysData_ComParamsSet_TatalTable(void);
	virtual ~CAccessSysData_ComParamsSet_TatalTable(void);

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
	* @brief  获取 所有 Total 记录 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [5/7/2012]
	*/
	BOOL GetSQLDataSetTable(CPMSQLTableCtrl *& pTableCtrl);

	/**
	* @brief 获取锚固 搭接 所有参数名称 队列  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/11/2011]
	*/
	void GetMgDj( CStringArray & arr_mgdj ) ;

protected:

	/**
	* @brief   获取锚固 搭接 所有参数名称 队列，不包括 搭接信息
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/11/2011]
	*/
	void GetMgDj_NotIncludeDjxs( CStringArray & arr_mgdj ) ;

public:

	/// 获取钢丝网片的DataSet 
	NDataModelDataSet * GetWpDataSet() ; 
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

protected:

	/// 内部会区分03G 11G 
	BOOL	GetTableCtrl(  CPMSQLTableCtrl *& pTableCtrl , const int iComType = -1 ) ;

// public:
// 	BOOL	GetTableCtrlGangJinMode(  CPMSQLTableCtrl *& pTableCtrl , const int iGangJinMode , const int iComType = -1 ) ;

public:
	BOOL	GetTableCtrlGangJinMode(  CPMSQLTableCtrl *& pTableCtrl , const int iGangJinMode , const int iComType = -1 ) ;

	/// 
	BOOL	GetTableCtrl_ParmName( const CString & strParmName , const int iGangJinMode , CPMSQLTableCtrl *& pTableCtrl ) ;

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
		static const int m_iGetWpDataSet ; 
		static PMTSTRING m_strGetWpDataSet ; 

		static const int m_iSelectAllInfo_GangJinModeComTypeSubComTypeParmName;
		static PMTSTRING m_strSelectAllInfo_GangJinModeComTypeSubComTypeParmName;

		/// select * from comparmset_total where gangjinmode in (? , -1 ) and comtype = ? 
		static const int m_iGetTableCtrl ;
		static PMTSTRING m_strGetTableCtrl ; 

		/// select * from comparmset_total where gangjinmode in (? , -1 ) and parmname = ? 
		static const int m_iGetTableCtrl_ParmName ;
		static PMTSTRING m_strGetTableCtrl_ParmName ; 
	} ;
};
