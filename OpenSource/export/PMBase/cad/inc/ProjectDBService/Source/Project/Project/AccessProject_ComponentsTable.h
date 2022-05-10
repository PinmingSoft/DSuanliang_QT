#pragma once
////#include "..\accesstable.h"


class PMProjectDBSERVICE CProject_QDDE_XMAttTable : public CPM_StorageDataSet  
{
public:
	DECLARE_DYNCREATE(CProject_QDDE_XMAttTable)

	CProject_QDDE_XMAttTable();
	virtual ~CProject_QDDE_XMAttTable();
	virtual int InitFieldStr();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString ID ;
		static const CString QDNumber ;
		static const CString parmdisplayname ;
		static const CString ParmValue ;
		static const CString ListData ;
		static const CString CheckReg ;
		static const CString InputMode ;
		static const CString Output1 ; 
	};

	
};

class PMProjectDBSERVICE CProject_QDDE_FJCCTable : public CPM_StorageDataSet  
{
public:
	DECLARE_DYNCREATE(CProject_QDDE_FJCCTable)

	CProject_QDDE_FJCCTable();
	virtual ~CProject_QDDE_FJCCTable();
	virtual int InitFieldStr();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id ;
		static const CString ComType ;
		static const CString parmdisplayname ;
		static const CString ParmValue ;
		static const CString ListData ;
		static const CString InputMode ;
		static const CString CheckReg ;
	};
};

class PMProjectDBSERVICE CProject_ComponentsTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ComponentsTable)

	CProject_ComponentsTable();
	virtual ~CProject_ComponentsTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					
		static const CString comname;					
		static const CString floorid;				
		static const CString comtype;				
		static const CString volume;					//此构件的数量
		static const CString comparms;				//构件属性
		static const CString qddedata;					//清单数据
		static const CString vectorparms;				//配筋图参数
		static const CString showid;				
		static const CString bz;						//描述
		static const CString editmode;				//是否修改
		static const CString publicGj;				//公共构件
//		static const CString inputdataset;			//平法表格数据

		static const CString table_name;				//表名
	};

	struct PMProjectDBSERVICE CTableData
	{
		/// 锚头个数使用的一些常量
		static const CString strJxmtfs ; /// 机械锚头方式

		static const CString strYcthmj ; /// 末端一侧贴焊锚筋
		static const CString strYcthmj_Zhu ;
		static const CString strYcthmj_Liang ; 

		static const CString strLcthmj ; /// 末端两侧贴焊锚筋
		static const CString strLcthmj_Zhu ;
		static const CString strLcthmj_Liang ; 

		static const CString strGbcksh ; /// 末端与钢板穿孔塞焊
		static const CString strGbcksh_Zhu ;
		static const CString strGbcksh_Liang ; 

		static const CString strDlsmt ; /// 末端带螺栓锚头
		static const CString strDlsmt_Zhu ;
		static const CString strDlsmt_Liang ; 

	};

	virtual BOOL GetCreateIndexSQL(CStringArray & strFieldNameArr,CString & strIndexName);

	virtual int InitFieldStr();
};


class PMProjectDBSERVICE CAccessProject_ComponentsTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_ComponentsTable(void);

	//bTemplateDb 表示是否是模板数据库
	CAccessProject_ComponentsTable(BOOL bTemplateDb);

public:
	virtual ~CAccessProject_ComponentsTable(void);

	/**
	* @brief   构件名称的合理性检测,合理返回TRUE，不合理返回FALSE
	*
	*			目前 不合理的 字符为 ; | \ /
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [5/28/2020]
	*/
	static BOOL CheckComName(CString componentName,CString & errorInfo);

	/**
	* @brief   获取合理的构件名称，如果发现不合理字符，将被替换为 replaceSymbol；如果本身就合理，就返回本身
	*
	*			目前 不合理的 字符为 ; | \ /
	* @note  : 
	* @param : 
	* @return: 返回合理的名称，如果本身就合理，就返回本身
	* @author: zfy
	* @date  : [5/28/2020]
	*/
	static CString GetCorrentComName(CString componentName,CString replaceSymbol=_T("_"));

	/**
	* @brief 获取 构件类型 列表  
	*
	*          
	* @note  : 输出格式 ComName\ComID;ComName\ComID;
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [18/7/2012]
	*/
	CString GetComsListData(int nFloorID,int nComType);

	/**
	* @brief 获取 构件类型 列表  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [18/7/2012]
	*/
	BOOL GetComsListData(int nFloorID,int nComType,CUIntArray & iComIDArr,CStringArray & strComNameArr);

	/**
	* @brief   获取所有ncomtype 的comid与comName
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/9/2016]
	*/
	BOOL GetComsListData(int nComType,CUIntArray & iComIDArr,CStringArray & strComNameArr);

	/**
	* @brief   判断某个comid是否是公共构件
	*
	*			失败也认为是非公共构件
	* @note  : 
	* @param : 
	* @return: TRUE : 公共构件，FALSE：非公共构件
	* @author: zfy
	* @date  : [8/14/2018]
	*/
	BOOL IsPublicGj(int iComID);

	/**
	* @brief   设置为公共构件
	*
	*			
	* @note  : 
	* @param : bPublicGj 为TRUE,则设置为公共构件，为FALSE,则取消公共构件
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/14/2018]
	*/
	BOOL SetPublicGj(int comid,BOOL bPublicGj);
	BOOL SetPublicGj(int comtype,CString comname,BOOL bPublicGj);
	BOOL SetPublicGj(const CUIntArray & arrComid,BOOL bPublicGj);

	/**
	* @brief   获取某个类型某个名称的所有层的公共构件comid
	*
	*			
	* @note  : 
	* @param : nComType 表示该公共构件类型
	* @param : gjName 表示该公共构件名称
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/13/2018]
	*/
	BOOL GetPublicGj(int nComType,CString gjName,CUIntArray & iComIDArr);

	/**
	* @brief   获取所有层的公共构件comid,comtype,comname
	*
	*			
	* @note  : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/13/2018]
	*/
	BOOL GetPublicGj(CUIntArray & iComIDArr,CUIntArray & iComtypeArr,CStringArray & arrName);

	/**
	* @brief 通过 ComType  队列 获取 ComIDArr 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [25/7/2012]
	*/
	BOOL GetComIDArr_ComTypeArr(CUIntArray & iComTypeArr,CUIntArray & iComIDArr);

	/**
	* @brief 插入构件  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [10/7/2012]
	*/
	BOOL InsertGJ(int iComType,int iFloorID,const CString & strComName,int & iNewComID);

	/**
	* @brief 复制一个构件  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 返回 ComID
	* @author: 王建业
	* @date  : [25/7/2012]
	*/
	int CopyRow(int iComID,int iComType,int iFloorID,CString & strComName);

	BOOL SaveDataSet(NDataModelDataSet *pDataSet, int iFloorID, int iComType);

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);


	/**
	* @brief  获取FloorGJXX表 内容，DataSet需要删除 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [10/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	/**
	* @brief   按comtype大类别获取数据，主要用于树状控件显示用
	*
	*			当为 砼墙、砖墙时额外显示0墙
	*			当为 土方大开挖时额外显示 地下室范围
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [5/12/2020]
	*/
	CSQLDataSet * GetDataSetForGrid_ComtypeDL(int floorid,int comtypeDL);

	/**
	* @brief   按comtype小类别获取数据，主要用于树状控件显示用
	*
	*			当为 砼墙、砖墙时额外显示0墙
	*			当为 土方大开挖时额外显示 地下室范围
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [5/12/2020]
	*/
	CSQLDataSet * GetDataSetForGrid_Comtype(int floorid,int comtypeXL);

	/**
	* @brief  获取 指定楼层 指定ComType 对应的 ComID队列 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [23/7/2012]
	*/
	BOOL GetComponent_ComIDArr(const CUIntArray & arr_floor ,const CUIntArray & arr_comtype ,CUIntArray & iComIDArr);

	BOOL GetComponentMapComidToComType(std::map<int,int> & mapComidToComType);

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
	* @brief 获取 构件的基本信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/7/2012]
	*/
	BOOL GetComponentsBaseInfo(int iComID,int & iComType,int & iFloorID,CString & strComName,BOOL & bPublicGj,CString & strBz);
	BOOL GetAllComBaseInfo(CUIntArray & iComIDArr
		,CUIntArray & iComtypeArr
		,CUIntArray & iFlooridArr
		,CStringArray & arrName
		,CUIntArray & arrPublicGj
		,CStringArray & arrBz
		,CArray<CProject_VectorParmsTable *> & arrVectorParm);

	/**
	* @brief 获取 参数表 buffer信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/7/2012]
	*/
	BOOL GetComParmBuffer_Table(int iComID,CPMSQLTableCtrl *& pTableCtrl);

	BOOL SetComParmBuffer(int iComID,LPVOID pComParmBuffer,long lComParmBuffer);

	/**
	* @brief  获取配筋图DataSet信息 
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	BOOL GetVectorParmDataSet(int iComID,CProject_VectorParmsTable *& pVectorDataSet);
	/// MAP非空，是已主键全部设置好去实现的
	void GetVectorParmDataSet(std::map<int, CProject_VectorParmsTable *>& vector_datasets);

	/**
	* @brief  获取配筋图DataSet 指定的 Value
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	BOOL GetVectorParmValue(int iComID,const CString & strParmName,CString & strParmValue);
	 
	/**
	* @brief  设置配筋图 Buffer信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	BOOL SetVectorParm_Buffer(int iComID,void * pVectorParmBuffer,long lVectorParmBufferSize);

	/**
	* @brief  获取SQL语句 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	static PmTString GetSQL(const int iSQLIndex);

	/**
	* @brief   获取指定行 表内容 ，需要删除 
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

	BOOL GetTable_MaxID(int & iMaxID);

	/**
	* @brief 删除指定楼层的 构件 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL DelComponentInfo_Floor(int iFloorID);

	/**
	* @brief 获取所有构件的 ID 队列   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL GetAllComIDArr(CUIntArray & iComIDArr);

	/**
	* @brief   获取所有comtype
	*
	*			已剔除重复，但没有排序
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [10/9/2018]
	*/
	BOOL GetAllComtypeArr(CUIntArray & iComtypeArr);

	/**
	* @brief  返回构件表中 所有 数据，记录集 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	/******************************************************************** 
	 功能描述：通过构件名查找构件ID
	 参数：strComName：构件名，iComType：构件类型，iComID：返回的构件ID，iFloorID：楼层编号
	 返 回 值：是否成功
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[28/1/2008]
	*********************************************************************/ 
	BOOL FindComponent_ComName(const CString & strComName, int iComType, int &iComID, int iFloorID);

	/**
	* @brief  获取 指定的ComID的 DataSet 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [14/7/2012]
	*/
	BOOL GetDataSet_ComID(int iComID,CSQLDataSet *& pComponentDataSet);

	/**
	* @brief  获取 指定的ComID的 记录集 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [14/7/2012]
	*/
	BOOL GetTableCtrl_ComID(int iComID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief  获取 构件 备注
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [14/7/2012]
	*/
	BOOL GetComponentBz(int iComID,CString & strBz);

	/**
	* @brief  设置 构件 备注
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [14/7/2012]
	*/
	BOOL SetComponentBz(int iComID,const CString & strBz);

	BOOL	GetShowId( const int iComId , int & iShowId ) ;
	int		GetShowId( const int iComId ) ;

	/**
	* @brief  获取 DataSet
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [14/7/2012]
	*/
	BOOL GetDataSet_FloorComType(int iFloorID,int iComType,CSQLDataSet *& pComponentDataSet);

	/**
	* @brief 获取  楼层/构建类型 中的的一个构件。 
	*
	*          
	* @note  : 
	* @param : iComId 找到了返回找到的comid ，没找到返回-1
	* @defenc: 
	* @return: 没有找到构件返回FALSE. 找到了返回TRUE
	* @author: 杨兴耀
	* @date  : [2014年3月19日]
	*/
	BOOL GetComIdFloorComType( const int iFloorId , const int iComType , int & iComId ) ;
	/**
	* @brief 获取 指定FloorID ComType ,下对应的 ComName 列表  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/7/2012]
	*/
	BOOL GetComNameArr_FloorComType(int iFloorID,int iComType,CStringArray & strComNameArr);

	/**
	* @brief 获取 指定FloorID ComType ,下对应的记录集
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/7/2012]
	*/
	BOOL GetTableCtrl_FloorComType(int iFloorID,int iComType,CPMSQLTableCtrl *& pComponentTableCtrl);

	BOOL GetTableCtrl_ComTypeArr(const CUIntArray & iComTypeArr,CPMSQLTableCtrl *& pComponentTableCtrl);

	/**
	* @brief   获取公共构件
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/14/2018]
	*/
	BOOL GetTableCtrl_PublicGj(CPMSQLTableCtrl *& pComponentTableCtrl);
	BOOL GetTableCtrl_PublicGj(const CUIntArray & iComTypeArr
		,CString gjName
		,CPMSQLTableCtrl *& pComponentTableCtrl);

	/**
	* @brief 判断 当前 楼层 是否有 这个名称的 构件
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/7/2012]
	*/

	BOOL HasSameName_Floor( const int iFloorID,const CString & strComName);

	BOOL HasSameName_Floor_ComType( const int iFloorId , const int iComType ,const CString & strComName);

	/**
	* @brief  获取 清单 定额的 DataSet
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [14/7/2012]
	*/
	BOOL GetQDDEDataSet(int iComID,NDataModelDataSet *& pQDDEDataSet);

	BOOL SetQDDEDataSet(int iComID,NDataModelDataSet * pQDDEDataSet);

	/**
	* @brief 删除时只是将comid信息移动至componentsdel表
	*
	*        
	* @author hn
	* @version v1.0
	* @date  9/27/2016
	* @note  
	*/
	BOOL DelComponent_IDNew(int iComID);
	BOOL DelComponent_IDArrNew(const CUIntArray & iComIDArr);

	BOOL DelComponent_ID(int iComID);
	BOOL DelComponent_IDArr(const CUIntArray & iComIDArr);


	//获取 相同名称 DataSet
	NDataModelDataSet * GetSameNameDataSet();

	BOOL GetRowCount( int & iRowCount ) ;

	/**
	* @brief   获取机械锚固的形式
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-8-20]
	*/
	BOOL	GetJxmgXs( const int iComId , CString & strJxmgxs ) ;

	BOOL	GetJxMgVectorId( const int iComId , CString & strVectorId ) ; 

	/**
		* @brief 获取不重复的构件类型
		*
		*          
		* @note  : 
		* @param : 
		* @defenc: 
		* @return: 
		* @author: 杨兴耀
		* @date  : 2013年8月2日   15:57
	*/
	BOOL	GetComType( CUIntArray & aryComType ) ; 
	
	
	//设置指定构件类型
	BOOL	SetComType( int iComID, int iComType );
	/**
	* @brief   获取机械锚固的长度
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-8-20]
	*/
	BOOL	GetJxmgLen( const int iComId , CString & strJxmgLen ) ;
	/**
	* @brief 将删除的记录先copy到compoentsdel表中保存，然后删除componentsdel表中信息
	*
	*        
	* @author hn
	* @version v1.0
	* @date  9/29/2016
	* @note  
	*/
	BOOL CopyDeleteComIdToComponentsdel(int iComID);
	/**
	* @brief 将componentsdel中的comid的记录copy到components表中，isExit表示componentsdel中是否存在此comid
	*
	*        
	* @author hn
	* @version v1.0
	* @date  10/8/2016
	* @note  
	*/
	BOOL SetDataSet_ComID_del( int iComID,CSQLDataSet *& pComponentdelDataSet, BOOL &isExsit );
	//固定的SQL 集合
	struct PMProjectDBSERVICE SQLInfo
	{
		static const int		m_iSelectComParmBuffer_SQL;
		static const PmTString m_strSelectComParmBuffer_SQL;//获取 comparm buffer的sql；

		static const int		m_iSelectVectorParmBuffer_SQL;
		static const PmTString m_strSelectVectorParmBuffer_SQL;//获取 vectorparm buffer的sql；

		static const int		m_iSelectComponentInfoBuffer_SQL;
		static const PmTString m_strSelectComponentInfoBuffer_SQL;//获取 构件基本信息 buffer的sql；

		static const int		m_iUpdateVectorParmBuffer_SQL;
		static const PmTString m_strUpdateVectorParmBuffer_SQL;//设置VectorParm Buffer的Sql

		static const int		m_iInsertInfo_SQL;
		static const PmTString m_strInsertInfo_SQL;//插入记录 sql

		static const int		m_iDeleteFloorComponent_SQL;
		static const PmTString m_strDeleteFloorComponent_SQL;//删除指定楼层的构件

		static const int		m_iSelectAllTable_SQL;
		static const PmTString m_strSelectAllTable_SQL;//获取 表中所有数据

		static const int		m_iSelectComID_ComTypeComNameFloor_Sql;
		static const PmTString	m_strSelectComID_ComTypeComNameFloor_Sql;//通过 comtype comName floorid 搜索ComID_Sql

		static const int			m_iSelectAllInfo_ComID_Sql;
		static const PmTString	m_strSelectAllInfo_ComID_Sql;//选择所有信息 通过comID sql

		static const int		m_iUpdateBz_ComID_Sql;
		static const PmTString	m_strUpdateBz_ComID_Sql;//通过ComID 更新 Bz

		static const int		m_iUpdatePublicGj_ComID_Sql;
		static const PmTString	m_strUpdatePublicGj_ComID_Sql;//通过ComID 更新 PublicGj

		static const int		m_iUpdateQDDEData_ComID_Sql;
		static const PmTString	m_strUpdateQDDEData_ComID_Sql;//通过ComID 更新 清单定额

		static const int		m_iSelectAllInfo_FloorIDComName;
		static const PmTString	m_strSelectAllInfo_FloorIDComName;

		//select * from component where floorid = ? and comtype=? and comname=?
		static const int		m_iSelectAllInfo_Floor_ComType_ComName ;
		static const PmTString  m_strSelectAllInfo_Floor_ComType_ComName ;

		static const int		m_iDeleteInfo_ComID;
		static const PmTString	m_strDeleteInfo_ComID;

		//update components set comparm=? where id=?
		static const int		m_iUpdateComParmBuffer_SQL;
		static const PmTString m_strUpdateComParmBuffer_SQL;//设置ComParm Buffer的Sql	

		static const int		m_iSelectVectorParmBuffer_ComID_All_SQL;
		static const PmTString  m_strSelectVectorParmBuffer_ComID_All_SQL;//获取 vectorparm buffer的sql；
	};
};


/**
* @brief   封装一些临时对象的定义操作 (充当 新老Access的 适配器)
*
*          
* @note  : 不需要每一个用到的地方都去定义一个临时对象 ， 有一些参数类型的转化可以在该类中实现
*
* @author: 杨兴耀
* @date  : [2012-7-17]
*/

class PMProjectDBSERVICE CProjectComponentsOpr
{
public:
	CProjectComponentsOpr() ;
	~CProjectComponentsOpr() ;

public:
	static BOOL SetComponentBz(int iComID,const CString & strBz);

	static BOOL GetComponentBz(int iComID,CString & strBz);

	static BOOL GetVectorParmValue(int iComID,const CString & strParmName,CString & strParmValue);

	static BOOL GetVectorParmDataSet(int iComID,CProject_VectorParmsTable *& pVectorDataSet);

	//获取参数 "vectorid" 并转为整数，该参数仅9.9之前版本使用，之后版本的vectorid 参数已经无效
	static int GetVectorID_SL( const int & nComID);

	//
	static int	GetVectorID_Gj( const int & nComID ) ;
	static void	SetVectorID_Gj( const int & nComID , const int & nVectorID_Gj ) ; 

	static BOOL GetQDDEDataSet(int iComID,NDataModelDataSet *& pQDDEDataSet);

	static BOOL SetQDDEDataSet(int iComID,NDataModelDataSet * pQDDEDataSet);

	static BOOL GetRowCount( int & iRowCount ) ;

	/// 
	static BOOL HasSameName_Floor( const int iFloorID,const CString & strComName);

	/// 
	static BOOL HasSameName_Floor_ComType( const int iFloorId , const int iComType , const CString & strComName ) ;

	static BOOL GetComponent_ComIDArr(const CUIntArray & arr_floor ,const CUIntArray & arr_comtype ,CUIntArray & iComIDArr);

	static BOOL GetComponent_ComIDArr(const int iFloorId ,const int iComType ,CUIntArray & iComIDArr);

	static BOOL	GetShowId( const int iComId , int & iShowId ) ;
	static int		GetShowId( const int iComId ) ;

	static BOOL	GetJxmgXs( const int iComId , CString & strJxmgxs ) ;

	static BOOL GetJxMgVectorId( const int iComId , CString & strVectorId ) ;

	static BOOL	GetJxmgLen( const int iComId , CString & strJxmgLen ) ; 

	/**
	* @brief 检查是否有   iFloorId ，iComType 中的构件在 aryComId  中。 没有的话，新建一个构件
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 返回 是否为新建的构件
	* @author: 杨兴耀
	* @date  : [2014年4月30日]
	*/
	static BOOL	CheckHasComType( const CUIntArray & aryComId , const int iFloorId , const int iComType ,  int & iRetComId ) ; 

	static BOOL NeedInsert( const int iComType ) ;

	/**
	* @brief 制定comtype新建构件时的 构件名称  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2014年4月30日]
	*/
	static CString GetComName( const int iComType ) ;

	/**
	* @brief 一层只有一个 地下室范围 构件   ,找到了返回 icomid 没有找到，新建一个地下室范围
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2014年5月31日]
	*/
	static BOOL  CheckDxsfwCom( const int iFloorId , int & iComId ) ;
};
