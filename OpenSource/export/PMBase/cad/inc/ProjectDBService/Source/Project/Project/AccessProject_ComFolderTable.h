#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_ComFolderTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ComFolderTable)

	CProject_ComFolderTable();
	virtual ~CProject_ComFolderTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString comfolderid;					//文件夹ID
		static const CString floorid;						//楼层ID
		static const CString allowownercom;				//是否允许拥有构件
		static const CString parentid;					//父构件文件夹ID
		static const CString foldername;					//构件文件夹名称
		static const CString imageindex;					//显示图标INdex
		static const CString selectedindex;				//选中图标Index
		static const CString comtype;						//构件类型
		static const CString allowadduserfolder;			//是否允许自定义文件夹
		static const CString initcreate;					//是否显示
		static const CString volume;						//此构件夹的数量
		static const CString showid;						//显示顺序


		static const CString table_name;			//表名
	};

	virtual int InitFieldStr();
};

//构件法 构件夹 数据库访问
class PMProjectDBSERVICE CAccessProject_ComFolderTable:
	public CPMSLAccessTable
{
public:
	CAccessProject_ComFolderTable(void);
	virtual ~CAccessProject_ComFolderTable(void);


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
	* @brief  获取指定行 表内容 ，需要删除  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	CSQLDataSet * GetFloorID_DataSet(int iFloorID);

	/**
	* @brief  获取指定ComFloder Folder ,的 Volume
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL GetComFolder_Volume(const CString & strComFolderID,int iFloorID,int & iVolume);

	/**
	* @brief  获取指定ComFloder Folder ,对应 记录集
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL GetTableCtrl_ComFolderFloorID(const CString & strComFolderID,int iFloorID,CPMSQLTableCtrl *& pSQLTableCtrl);
	BOOL GetDataSet_ComFolderFloorID(const CString & strComFolderID,int iFloorID,CSQLDataSet *& pSQLDataSet);

	/**
	* @brief  删除 指定楼层 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL DeleteFloor(int iFloorID);

	/**
	* @brief  获取Folder表 DataSet 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	CSQLDataSet * GetEmptyDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	/******************************************************************** 
	功能描述：获取所有的 构件夹 不重复(不分层)
	参数：
	返 回 值：返回的 DataSet 需要删除
	算法：
	注意事项：Repeat 写错了 
	作    者：杨兴耀
	时    间：[2009年4月28日]
	*********************************************************************/ 
	NDataModelDataSet * GetNotNepeatDataSet();

	BOOL GetRowCount( int & iRowCount ) ;

	CString GetComFolderName( const CString & strComFolderID  ) ;


	int InsertOneRow(
		int nFloorID , 
		int nAllowOwnerCom , 
		int nParentID , 
		const CString & strFolderName , 
		int nImageIndex ,
		int nSelectedIndex , 
		int nComType ,
		int nAllowAddUserFolder , 
		int nInitCreate ,
		int nVolume
		);


	BOOL GetMaxComFolderID(int & iMaxComFolderID) ;

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		/// 
		const static int		m_iDelete_FloorIDSQL;
		const static PmTString m_strDelete_FloorIDSQL;//通过楼层ID删除SQL

		/// 
		static const int		m_iGetNotNepeatDataSet ;
		static PMTSTRING		m_strGetNotNepeatDataSet ;

		/// 
		static const int		m_iSelectAllInfo_ComFolderFloor ;
		static PMTSTRING		m_strSelectAllInfo_ComFolderFloor ;

		/// 
		static const int		m_iGetComFoderName ; 
		static PMTSTRING		m_strGetComFolderName ; 
	};
};
