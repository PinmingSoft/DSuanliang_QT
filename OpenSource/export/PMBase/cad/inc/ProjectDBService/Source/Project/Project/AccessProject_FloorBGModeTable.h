#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_FloorBGModeTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_FloorBGModeTable)

	CProject_FloorBGModeTable();
	virtual ~CProject_FloorBGModeTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;			
		static const CString floorid;						//楼层ID
		static const CString comtype;						//构件类型
		static const CString comname;						//构件名称
		static const CString bgmode;						//高模式 0：楼层标高 1：工程标高

		static const CString table_name;					//表名
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_FloorBGModeTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_FloorBGModeTable(void);
	virtual ~CAccessProject_FloorBGModeTable(void);

	virtual BOOL TryUpdateTableField();

	virtual BOOL TryUpdateTableContent() ;

	/**
	* @brief  将标高信息 保存到 主表中 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [24/7/2012]
	*/
	void SetFloorBGMode(int nFloorID, NDataModelDataSet *pDataSet);

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
	* @brief 获取 最大的 ID值  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL GetTable_MaxID(int & iMaxID);

	/******************************************************************** 
	 功能描述：获取指定楼层 构件类型 的标高模式
	 参数：
	 返 回 值：
	 算法：
	 注意事项：iBGMode： 0 楼层标高 1 工程标高
	 作    者：王建业
	 时    间：[9/9/2008]
	*********************************************************************/ 
	BOOL GetFloor_ComTypeBGMode(int iFloorID, int iComType, int &iBGMode);

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	BOOL GetRowCount( int & iRowCount ) ;

	static PMTSTRING GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		const static int		m_iSelectBGMode_FloorComType;
		const static PMTSTRING	m_strSelectBGMode_FloorComType;
	};
};
