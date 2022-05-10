#pragma once

//#include "..\accesstable.h"

////////////////////////////////////////////
/// 王建业 [2013:7:3   11:20]
/// 说明:
/// 选择 跨层相关 函数实现
/// int :当前楼层ID int : 楼层ID double:起始相对标高，double:终止相对标高
typedef BOOL(*SelectRelation_Info_CheckKcEntityInfo)(int,int ,double ,double);

class PMProjectDBSERVICE CProject_KcEntityTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_KcEntityTable)

	CProject_KcEntityTable();
	virtual ~CProject_KcEntityTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString floorid;
		static int	 floorid_Index;

		static const CString handlelow;			//句柄低位
		static int		handlelow_Index;

		static const CString handlehigh;		//句柄高位
		static int			handlehigh_Index;

		static const CString comtype;			//构件类型
		static int			comtype_Index;

		static const CString topbg;				//最高点标高
		static int			topbg_Index;

		static const CString bottombg;				//最低点标高
		static int			bottombg_Index;

		static const CString entitydata;				//实体信息	
		static int			entitydata_Index;

		static const CString subent;				//子实体信息	
		static int			subent_Index;

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_KcEntityTable : public CPMSLAccessTable
{
public:
	CAccessProject_KcEntityTable(void);
	~CAccessProject_KcEntityTable(void);


	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	/// 获取整表，并附带entitydata 列二进制长度
	CProject_KcEntityTable * GetDataSetWithEntityDataSize(CUIntArray & arrEntityDataSize) const;

	/**
	* @brief 返回 当前工程 所有跨层构件信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/9/2013]
	*/
	BOOL		GetTableCtrl(   CPMSQLTableCtrl *& pTableCtrl );

	/// 
	/// 
	/// 
	/// 专用接口
	/// 
	BOOL		GetTableCtrl( const int iFloorId ,  CPMSQLTableCtrl *& pTableCtrl ) ;

	/// 
	BOOL		Delete( const CUIntArray & aryQddeId ) ;

	/**
	* @brief  插入信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/5/2013]
	*/
	BOOL InsertInfo(int iFloorID,int ihandlehigh,int ihandlelow,int iComType,const double & dTopBg,\
		const double & dBottomBG,const LPVOID & pEntInfo,long lEntInfoSize,const LPVOID & pSubEntInfo,long lSubEntSize);

	BOOL DeleteInfo(int iFloorID);
	BOOL DeleteInfo(int iFloorID,int ihandlehigh,int ihandlelow);

	/**
	* @brief 获取数据  
	*
	*          
	* @note  : 这个函数 比较耗时
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/5/2013]
	*/
	BOOL SelectInfo(int iFloorID,int ihandlehigh,int ihandlelow,CProject_KcEntityTable *& pKcEntityTable);
	BOOL SelectInfo(int iFloorID,CProject_KcEntityTable *& pKcEntityTable);

	BOOL SelectRelation_Info(int iFloorID,CProject_KcEntityTable *& pKcEntityTable);

	BOOL SelectRelation_Info(int iFloorID,CProject_KcEntityTable *& pKcEntityTable,SelectRelation_Info_CheckKcEntityInfo pCheckFun);

	BOOL Modify_BG(int iFloorID,int iHandlehigh,int iHandleLow,const double & dTopBG,const double & dBottomBG);

	BOOL Modify_Info(int iFloorID,int iHandlehigh,int iHandleLow,const double & dTopBG,\
		const double & dBottomBG,const LPVOID & pEntInfo,long lEntInfoSize,const LPVOID & pSubEntInfo,long lSubEntSize);

	BOOL	DeleteAllKcEntity();

	static PmTString GetSQL(const int iSQLIndex);

	/**
	* @brief  将mm翻译为数据保存的 标高 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/5/2013]
	*/
	static int Trans2SaveBG(const double & dBG);

	/**
	* @brief 将数据中的标高 进行 翻译，成MM   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/5/2013]
	*/
	static double Trans2OutInfo(int iBG);

	struct SQLInfo
	{
		/// insert into kcentity (floorid , handlelow,handlehigh,comtype,topbg,bottombg,entitydata,subent) values(? , ?,? , ?,? , ?,? , ?) 
		static const int m_iInsertKcEntityInfo;
		static PMTSTRING m_strInsertKcEntityInfo;

		///delete from kcentity where floorid=? and handlelow=? and handlehigh=?
		static const int m_iDelete_KcEntityInfo;
		static PMTSTRING m_strDelete_KcEntityInfo;

		//select * from kcentity where floorid=? and handlelow=? and handlehigh=?
		static const int m_iSelect_KcEntityInfo;
		static PMTSTRING m_strSelect_KcEntityInfo;

		//update kcentity set topbg=? , bottombg=? where floorid=? and handlelow=? and handlehigh=?
		static const int		m_iUpdate_KcEntityInfo_BG;
		static PmTString m_strUpdate_KcEntityInfo_BG;

		//update kcentity set topbg=? , bottombg=? , entInfo=?,subEntInfo=? where floorid=? and handlelow=? and handlehigh=?
		static const int		m_iUpdate_KcEntityInfo_Info;
		static PmTString m_strUpdate_KcEntityInfo_Info;
		
		//delete from table
		static const int		m_iDelete_AllKcEntityInfo;
		static PmTString	m_strDelete_AllKcEntityInfo;

		//delete from table where floorid=?
		static const int		m_iDelete_FloorKcEntityInfo;
		static PmTString	m_strDelete_FloorKcEntityInfo;
	};

protected:

	static BOOL TransDataSet2OutInfo(CProject_KcEntityTable * pKcEntityTable);
};
