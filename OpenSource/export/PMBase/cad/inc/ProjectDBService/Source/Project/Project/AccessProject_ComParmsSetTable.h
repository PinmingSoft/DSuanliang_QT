#pragma once
//#include "..\accesstable.h"
//#include "AccessProject_ComParmsSet_TotalTable.h"
#include "AccessProject_ProjectInfoTable.h"

class PMProjectDBSERVICE CProject_ComParmsSetTable : public CSQLDataSet
{
	DECLARE_DYNCREATE(CProject_ComParmsSetTable)

	CProject_ComParmsSetTable();
	virtual ~CProject_ComParmsSetTable();

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

class PMProjectDBSERVICE CAccessProject_ComParmsSetTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_ComParmsSetTable(void);
	virtual ~CAccessProject_ComParmsSetTable(void);

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

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	BOOL SaveDataSet_DefDataSet(ProjectInfoMacro::GangJinMode gangJinMode,NDataModelDataSet * pComParmDataSet);

	/**
	* @brief  按照构件类型，参数名称 获取对应行的信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/7/2012]
	*/
	BOOL GetTableCtrl_ComTypeSubComTypeGangJinModeParmName(int iComType,int iSubComType,\
		ProjectInfoMacro::GangJinMode gangJinMode,const CString & strParmName,\
		CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/10/2012]
	*/
	BOOL GetParmValueInvalidMsg_ComTypeSubComTypeParmName(int iComType,int iSubComType,const CString & strParmName,\
		CString & strParmValue,CString & strInvalidMsg);

	/**
	* @brief  按照构件类型，参数名称 获取对应行的信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/7/2012]
	*/
	BOOL GetDataSet_ComTypeSubComTypeGangJinModeParmName(int iComType,int iSubComType,\
		ProjectInfoMacro::GangJinMode gangJinMode,const CString & strParmName,\
		CSQLDataSet *& pSQLDataSet);

	BOOL	DeleteAll( ) ;

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		///select * from ComParmset where gangjinMode=? and comType =? and subcomtype=? and ParmName=?
		static const int m_iSelectAllInfo_GangJinModeComTypeSubComTypeParmName;
		static PMTSTRING m_strSelectAllInfo_GangJinModeComTypeSubComTypeParmName;

		///delete from comparmset where gangjinMode=?
		static const int m_iDelete_GangJinMode;
		static PMTSTRING m_strDelete_GangJinMode;
		
		///delete from comparmset 
		static const int m_iDelete ;
		static PMTSTRING m_strDelete ;
	};
};
