#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_CustomSteelComponentsTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_CustomSteelComponentsTable)

	CProject_CustomSteelComponentsTable();
	virtual ~CProject_CustomSteelComponentsTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					
		static const CString comname;				//构件名称	
		static const CString floorid;				//楼层ID
		static const CString folderid;			//构件夹ID
		static const CString comtype;				//构件类别	
		static const CString volume;				//此构件的数量
		static const CString comparms;			//构件属性
		static const CString inputdata;			//平法表格数据
		static const CString showid;				
		static const CString sumvolume;		

		static const CString table_name;			//表名
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_CustomSteelComponents :
	public CPMSLAccessTable
{
public:
	CAccessProject_CustomSteelComponents(void);

	virtual ~CAccessProject_CustomSteelComponents(void);

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

	BOOL GetTableCtrl_ComID(int iComID,CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetDataSet_ComID(int iComID,CSQLDataSet *& pSQLDataSet);

	BOOL GetTableCtrl_ComTypeFloor(int iFloorID,int iComType,CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetTableCtrl( CPMSQLTableCtrl *& pSQLTableCtrl ) ;

	CString GetComName(int iComID);

	void SetComName( int nComID ,const CString & strComName );

	int GetComType(int iComID);

	int InsertCom( CString strComName , 
		int nComType ,
		int nFloorID ) ;

	void DeleteCom( int nComID ) ;

	static PmTString GetSQL(const int iSQLIndex);

	/// 
	CSQLDataSet * GetDataSet();

	/**
	* @brief 获取ID的 最大值  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	BOOL GetMaxID(int & iMaxID);

	struct SQLInfo
	{
		//select * from customsteelComponents where comid=?;
		static const int		m_iSelectAllInfo_ComID;
		static const PmTString	m_strSelectAllInfo_ComID;

		//select * from customsteelComponents where floor=? and comtype=?
		static const int		m_iSelectAllInfo_ComTyeFloor;
		static const PmTString	m_strSelectAllInfo_ComTypeFloor;

		//delete from customsteelComponents where id=?;
		static const int		m_iDeleteInfo_ComID;
		static const PmTString	m_strDeleteInfo_ComID;

		/// select * from customsteelComponents 
		static const int		m_iGetDataSet ;
		static const PMTSTRING	m_strGetDataSet ; 
	};
};
