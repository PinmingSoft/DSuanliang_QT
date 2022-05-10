#pragma once
//#include "..\accesstable.h"
#include "AccessProject_ProjectInfoTable.h"

class PMProjectDBSERVICE CProject_ComParmsSet_TotalTable : public CSQLDataSet
{
	DECLARE_DYNCREATE(CProject_ComParmsSet_TotalTable)

	CProject_ComParmsSet_TotalTable();
	virtual ~CProject_ComParmsSet_TotalTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString	parmid;
		static int				parmid_Index;

		static const CString	gangjin_mode;
		static int				gangjin_mode_Index;

		static const CString	comtype;
		static int				comtype_Index;

		static const CString	subcomtype;
		static int				subcomtype_Index;

		static const CString	parmname;
		static int				parmname_Index;

		static const CString	parmvalue;
		static int				parmvalue_Index;

		static const CString	invalidmsg;
		static int				invalidmsg_Index;

	//	static CString table_name;
	};

	struct PMProjectDBSERVICE CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

//构件总参数 数据库
class PMProjectDBSERVICE CAccessProject_ComParmsSet_TotalTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_ComParmsSet_TotalTable(void);
	virtual ~CAccessProject_ComParmsSet_TotalTable(void);

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

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	BOOL SaveDataSet_DefDataSet(ProjectInfoMacro::GangJinMode gangJinMode,NDataModelDataSet * pComParmDataSet);

	BOOL	GetParamValue( const CString & strParamName , const int iGangJinMode , CString & strParamValue ) ; 

	BOOL GetTableCtrl_ComTypeSubComTypeGangJinModeParmName(int iComType,int iSubComType,\
				ProjectInfoMacro::GangJinMode gangJinMode,const CString & strParmName,\
				CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetDataSet_ComTypeSubComTypeGangJinModeParmName(int iComType,int iSubComType,\
				ProjectInfoMacro::GangJinMode gangJinMode,const CString & strParmName,\
				CSQLDataSet *& pSQLDataSet);

	
	BOOL	DeleteAll( ) ;

protected:
	BOOL	GetTableCtrl_ParamName_GangJinMode( const CString & strParamName , const int iGangJinMode ,  CPMSQLTableCtrl *& pTableCtrl ) ;
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
		static const int m_iGetTableCtrl_ParamName_GangJinMode ;
		static PMTSTRING m_strGetTableCtrl_ParamName_GangJinMode ;

		///select * from ComParmset where gangjinMode=? and comType =? and subcomtype=? and ParmName=?
		static const int m_iSelectAllInfo_GangJinModeComTypeSubComTypeParmName;
		static PMTSTRING m_strSelectAllInfo_GangJinModeComTypeSubComTypeParmName;

		///delete from comparmset where gangjinMode=?
		static const int m_iDelete_GangJinMode;
		static PMTSTRING m_strDelete_GangJinMode;

		///delete from comparmset_total
		static const int m_iDelete ;
		static PMTSTRING m_strDelete ;
		
	} ;
};
