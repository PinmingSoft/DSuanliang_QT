
#pragma once


#include "AccessSysDataTable.h "
//#include "..\project\AccessProject_ProjectInfoTable.h"

/**
 * @brief 构件参数总表
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CAccessSysData_ComParamsSetTable :
	public CAccessSysDataTable
{
public:
	CAccessSysData_ComParamsSetTable(void);
	virtual ~CAccessSysData_ComParamsSetTable(void);

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

	//BOOL GetParmValue_ComTypeSubComTypeParmName(int iComType,int iSubComType,\
	//	const CString & strParmName,\
	//	CString & strParmValue);

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
	* @brief   获取所有参数信息
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [3/7/2012]
	*/
	BOOL GetSQLDataSetTable(CPMSQLTableCtrl *& pTableCtrl);

	CString GetDisplayName( const int iComType , const CString & strParmName ) ;
	int GetInputMode( const int iComType , const CString & strParmName ) ;
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

	/**
	* @brief   获取包括对应钢筋mode的全部计算设置
	*		   原方法仅取Comparmsset表中数据
	*		   现调整为从Comparmsset_XXG中获取数据
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王荣强
	* @date  : [2016-11-21]
	*/
	NDataModelDataSet * GetDataSet_JSSZ(ProjectInfoMacro::GangJinMode gangjinMode, const int iComType);

 	//NDataModelDataSet * GetDataSet_JSSZ(ProjectInfoMacro::GangJinMode gangjinMode,int iComType);
 
 	BOOL CheckValueHasChange(ProjectInfoMacro::GangJinMode gangjinMode,int iComType,int iSubComType,const CString & strParmName,const CString & strParmValue);

	/**
	* @brief   判断计算设置是否改动
	*		   原方法仅取Comparmsset表中数据
	*		   现调整为从Comparmsset和Comparmsset_XXG中获取数据
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王荣强
	* @date  : [2016-12-26]
	*/
	BOOL CheckValueHasChangeNew(ProjectInfoMacro::GangJinMode gangjinMode,int iComType,int iSubComType,const CString & strParmName,const CString & strParmValue);
 
 	BOOL GetTableCtrl_ComTypeParmName(ProjectInfoMacro::GangJinMode gangjinMode,int iComType,\
 		int iSubComType,const CString & strParmName,CPMSQLTableCtrl *& pTableCtrl);
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
		static const int m_iGetDisplayName ; 
		static PMTSTRING m_strGetDisplayName ; 

		/// 
		static const int m_iGetInputMode ; 
		static PMTSTRING m_strGetInputMode ; 

		///select * from ComParmset where gangjinMode=? and comType =? and subcomtype=? and ParmName=?
		static const int m_iSelectAllInfo_GangJinModeComTypeSubComTypeParmName;
		static PMTSTRING m_strSelectAllInfo_GangJinModeComTypeSubComTypeParmName;

		///select * from ComParmSet where gangjinMode=? and comtype=? and parmType=?
		static const int m_iGetDataSet_ComTypeGangJinMode;
		static PMTSTRING m_strGetDataSet_ComTypeGangJinMode;
	} ;

private:
	
	/**
	* @brief   在当前数据中插入钢筋的计算设置
	*
	* @note  : 不清空原数组
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王荣强
	* @date  : [2016-11-21]
	*/
	void AppendGangJinJssz(ProjectInfoMacro::GangJinMode gangjinMode, int iComType, NDataModelDataSet *pDataSet);
};


