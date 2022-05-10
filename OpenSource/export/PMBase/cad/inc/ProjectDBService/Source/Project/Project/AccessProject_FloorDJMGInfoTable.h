#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_FloorDJMGInfoTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_FloorDJMGInfoTable)

	CProject_FloorDJMGInfoTable();
	virtual ~CProject_FloorDJMGInfoTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;
		static const CString floorgjxxid;	
		static const CString gangjinmode;
		static const CString gjindex;	
		static const CString zjinfo;
		static const CString mgz;
		static const CString djz;

		static const CString table_name;
	};

	//钢筋符号常量说明
	struct PMProjectDBSERVICE CGJIndex
	{
		const static CString strA;
		const static CString strB;
		const static CString strC;
		const static CString strD;
		const static CString strE;
		const static CString strF;
		const static CString strG;
	};

	//钢筋常量说明
	enum PMProjectDBSERVICE GJZJ
	{
		AllZJ = 0,
		low25ZJ = 20,
		high25ZJ = 30
	};

	virtual BOOL GetCreateIndexSQL(CStringArray & strFieldNameArr,CString & strIndexName);

	virtual int InitFieldStr();
};


class PMProjectDBSERVICE CAccessProject_FloorDJMGInfoTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_FloorDJMGInfoTable(void);

	virtual ~CAccessProject_FloorDJMGInfoTable(void);

	/**
	* @brief 获取 钢筋 直径 显示  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [24/7/2012]
	*/
	static CString GetFloorDJMG_ChangeGJZJ(int iGJMode,int iGJZJ);

	/**
	* @brief  获取 钢筋显示名称 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [24/7/2012]
	*/
	static CString GetFloorDJMG_ChangeGJName(int iGJMode,CString strGJName);

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
	CSQLDataSet * GetFloorGJXXID_DataSet(int iFloorGJXXID);

	CSQLDataSet * GetDataSet( const int iFloorGjxxId , const int iGangJinMode ) ;

	CSQLDataSet * GetDataSet();

	NDataModelDataSet * GetDataSet( const CUIntArray & aryFloorGjxxId , const int iGangJinMode ) ; 

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	//保存 锚固搭接信息  只给 工程设置使用
	//03G 11G数据格式不同，需要index
	BOOL SaveMGDJDataSet(NDataModelDataSet * pMGDJDataSet,int index);

	/**
	* @brief 删除指定 FloorGJXXID的 锚固搭接值  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL DeleteInfo_FloorGJXX(int iFloorGJXXID);

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

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		const static PmTString m_strDelete_FloorGJXXID_Sql;//通过FloorGJXX 删除锚固搭接
		const static int				m_iDelete_FloorGJXXID_Sql;

		///
		const static int		m_iGetDataSet_Gjxx_GjMode ;
		const static PMTSTRING	m_strGetDataSet_Gjxx_GjMode ;

		/// 
		const static int		m_iGetDataSet_ArrGjxx_GjMode ;
		static PMTSTRING	m_strGetDataSet_ArrGjxx_GjMode ;


	};
};
