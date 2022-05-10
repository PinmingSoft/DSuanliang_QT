#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_LayerInfoTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_LayerInfoTable)

	CProject_LayerInfoTable();
	virtual ~CProject_LayerInfoTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;						//编号
		static const CString floorid;					//楼层ID
		static const CString comtype;					//构件编号
		static const CString layer;					//层名称
		static const CString color;					//层颜色
		static const CString showindex;				//绘制顺序
		static const CString showcolor;				//三维显示颜色
		static const CString layerinfo;				//层显示信息
		static const CString alllayername;			//所有层名
		static const CString showsize;				//显示大小
		static const CString controlmode;				//控制模式 1 控制层 0 不控制层

		static const CString table_name;				//图层表
	};

	virtual int InitFieldStr();
};


class PMProjectDBSERVICE CAccessProject_LayerInfoTable :
	public CPMSLAccessTable
{
public:

	class PMProjectDBSERVICE CLayerInfo
	{
	public:
		CString m_strLayerInfo;
		int m_iComType;

	public:
		CLayerInfo()
		{
			m_iComType = -1 ; 
		}

		CLayerInfo( const CLayerInfo & other )
		{
			m_iComType = other.m_iComType ; 
			m_strLayerInfo = other.m_strLayerInfo ; 
		}

		~CLayerInfo()
		{

		}
	};

	/// 
	typedef std::map<CString ,CLayerInfo > PmStr2LayerInfoMap ; 
	typedef PmStr2LayerInfoMap::iterator PmStr2LayerInfoMapIter ; 
	typedef PmStr2LayerInfoMap::const_iterator PmStr2LayerInfoMapConIter ; 

	CAccessProject_LayerInfoTable(void);
	virtual ~CAccessProject_LayerInfoTable(void);

	virtual BOOL TryUpdateTableField();

	/// 升级表格的内容
	virtual BOOL TryUpdateTableContent() ; 

	/**
	* @brief  获取三维层 名称
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL Get3DLayerName(int iComType,CString & strLayerName);

	/**
	* @brief  获取获取 需要显示 ComType的 队列
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL GetComTypeShowSizeArr(int iFloorID,CArray<int,int&> & iNeedShowComTypeArr);

	BOOL SetComTypeShowSize(int iFloorID, int iComType, BOOL bNeedShow);

	/**
	* @brief  获取指定层的 信息
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL GetLayerInfo(CString strLayerName,CAccessProject_LayerInfoTable::CLayerInfo & layerinfo);
	void GetLayerInfo(std::map<CString, CAccessProject_LayerInfoTable::CLayerInfo *> & layerInfos, const int floorId = -1000 );
	
	/// 
	BOOL GetLayerInfo( CAccessProject_LayerInfoTable::PmStr2LayerInfoMap & mapLayerName2Info , const int iFloorId = -1000 ) ; 

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

	//获取 楼层ID 的 记录集
	BOOL GetTableCtrl_FloorID(int iFloorID,CPMSQLTableCtrl *& pSQLTableCtrl);

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

	/**
	* @brief  获取图层信息 
	*
	*          
	* @note  : 
	* @param : int iComType:构件类型
	*			CString &strLayerName：主层名称
	*			int &iColor：二维颜色
	*			int &iLayerInfo：层信息
	*			CString &strAllLayerName：所有图层名称
	*			int &iControlMode：控制类型
	*			int iFloorID：获取的层ID（-1000：取当前层）
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [16/7/2012]
	*/
	BOOL GetLayerInfo(int iComType, CString &strLayerName, int &iColor, int &iLayerInfo, CString &strAllLayerName, int &iControlMode,int iFloorID = TemFloor);

	////////////////////////////////////////////////////////////////
	/// at 2011年3月30日  14:38  by yxy
	/******************************************************************** 
	该函数获取 一个大类下的所有层信息 如 100 下的所有 101,102,103 DL 为大类的缩写
	*********************************************************************/ 
	BOOL	GetLayerNameDL( const int  nFloorID , const int nComTypeDL , CStringArray & aryLayerName ) ; 

	BOOL	GetLayerName( const int iComType,CString & strLayerName,int iFloorID = TemFloor );

	/******************************************************************** 
	功能描述：获取构件显示信息
	参数：
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[25/12/2007]
	*********************************************************************/ 
	BOOL GetGJShowInfo(  const int iComType, int & iLayerInfo, int iFloorID = TemFloor);

	BOOL SetGJShowInfo(  const int iComType, int iLayerInfo, int iFloorID = TemFloor);

	/**
	* @brief   设置图层的颜色,
	*
	*          
	* @note  : 
	* @param : pDataSet 需要包含列 comtype 和 color字段
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-8-2]
	*/
	void	SetLayerColor( NDataModelDataSet * pDataSet ) ;

	void	SetLayerColor( const int iComType , const int iColor ) ;

	void	SetLayerShowColor( const int iComType , const int iShowColor ) ;

	/**
	* @brief 检测 图层名称 是否 是品茗的
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL CheckLayer(const CString & strLayerName);

	BOOL GetTableCtrl_FloorComType(int iFloorID,int iComType,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief 获取三维 图层 颜色
	*
	*          
	* @note  : 
	* @param :
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL GetShowColor(int iComType, int & iShowColor,int iFloorID = TemFloor);

	/**
	* @brief 获取三维 图层 颜色
	*
	*          
	* @note  : 
	* @param :
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL Get3DColor( const int iComId , int & iShowColor ) ;

	/**
	* @brief 获取二维 图层 颜色
	*
	*          
	* @note  : 
	* @param : iFloorID 必须 指定
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL Get2DColor( const int iComType ,const int iFloorID,int & iColor);

	/**
	* @brief 获取三维 图层 颜色
	*
	*          
	* @note  : 
	* @param : iFloorID 必须 指定
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL Get3DColor( const int iComType ,const int iFloorID,int & iColor);

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	BOOL GetRowCount( int & iRowCount ) ;

	static PmTString GetSQL(const int iSQLIndex);

protected:
	BOOL	UpdateColor_ComType( const int iComType , const int iColor ) ;
	
	BOOL	UpdateShowColor_ComType( const int iComType , const int iShowColor ) ;

public:

	struct SQLInfo
	{
		static const int			m_iSelectLayerInfo_FloorComTypeSql;
		static const PmTString		m_strSelectLayerInfo_FloorComTypeSql;//通过楼层ID comType 获取所有的图层信息

		static const int			m_iGetLayerNameDL ;
		static const PMTSTRING		m_strGetLayerNameDL ;					/// 通过  nFloorID , nComTypeDL 获取图层名称

		static const int			m_iGetLayerName ;
		static const PMTSTRING		m_strGetLayerName ;						/// 通过  nFloorID , nComType  获取图层名称

		static const int			m_iGetGjShowInfo ;
		static const PMTSTRING		m_strGetGjShowInfo ;					/// 获取构件显示信息 

		static const int			m_iSelectComType_LayerName;
		static const PMTSTRING		m_strSelectComType_LayerName;			//通过获取comtype 

		static const int			m_iSelectAllInfo_FloorIDSql;
		static const PMTSTRING		m_strSelectAllInfo_FloorIDSql;

		//update LayerInfo set LayerInfo=? where floorid=? and comtype=? 
		static const int			m_iUpdateLayerInfo_FloorComTypeSql;
		static const PMTSTRING		m_strUpdateLayerInfo_FloorComTypeSql; //通过 nFloorID nComType 设置 LayerInfo(显示状态)

		/// 
		static const int			m_iUpdateColor_ComType ;
		static PMTSTRING			m_strUpdateColor_ComType ; 

		/// 
		static const int			m_iUpdateShowColor_ComType ; 
		static PMTSTRING			m_strUpdateShowColor_ComType ; 

		static const int			m_iSelectComType_LayerName_All;
		static const PMTSTRING		m_strSelectComType_LayerName_All;
	};
};



/**
* @brief   封装一些临时对象的定义操作
*
*          
* @note  : 不需要每一个用到的地方都去定义一个临时对象 ， 有一些参数类型的转化可以在该类中实现
*
* @author: 杨兴耀
* @date  : [2012-7-17]
*/

class PMProjectDBSERVICE CProjectLayerInfoOpr
{
public:
	static CProjectLayerInfoOpr * GetInstance()
	{
		if (NULL == m_pInstance)
		{
			m_pInstance = PMNew(CProjectLayerInfoOpr);
		}
		return m_pInstance;
	}
	static void Release(){PMDelete(m_pInstance);}

	//图层信息
	class PMProjectDBSERVICE CGJLayerInfo
	{
	public:

		CGJLayerInfo();
		virtual ~CGJLayerInfo();

		int m_iComType;				//构件类型
		CString m_str2dLayerName;	//二维图层名称
		CString m_str3dLayerName;	//三维图层名称
		std::set<CString> m_setLayerAll;	//所有图层----主要是轴网可能有多个图层

		int m_i2DColor;				//二维图层颜色
		int m_i3DColor;				//三维图层颜色

		int m_nLayerInfo;			//layerInfo字段
	};

public:
	//获取 layerInfo信息
	BOOL	GetLayerInfo( const int iComType, int & iLayerInfo,  const int iFloorID = TemFloor) const;

	//获取 二维图层名称
	BOOL	GetLayerName( const int iComType, CString & strLayerName, int iFloorID = TemFloor ) const;
	//获取 三维图层名称
	BOOL	Get3DLayerName( const int iComType, CString & strLayerName, int iFloorID = TemFloor ) const;
	//获取 二维图层颜色
	BOOL	GetLayerColor( const int iComType, int & color, int iFloorID = TemFloor) const;
	//获取 三维图层颜色
	BOOL	Get3DLayerColor( const int iComType, int & color, int iFloorID = TemFloor) const;
	//通过图层名，查找对应的图层信息
	BOOL	GetLayerComtype(const CString & strLayerName,int & layerComtype) const;

	// 获取comtype 与图层名的匹配
	void	GetLayerName(std::map<int,CString> & mapComtype2LayerName) const;

	// 获取comtype 与3D图层名的匹配
	void	Get3DLayerName(std::map<int,CString> & mapComtype2LayerName) const;

	// 检测图层是否存在
	BOOL	CheckLayer(const CString & strLayerName) const;

	// 批量调整所有图层颜色信息
	void	SetLayerColor( NDataModelDataSet * pDataSet ) ;

	//设置二维图层颜色
	void	SetLayerColor( const int iComType , const int iColor ) ;

	// 设置三维图层颜色
	void	SetLayerShowColor( const int iComType , const int iShowColor ) ;

	//重新读取所有图层信息
	void LoadLayerAll();

protected:
	//查找合理的图层，如果找不到，返回 TemFloor 默认图层信息
	const CProjectLayerInfoOpr::CGJLayerInfo * FindLayerWithDefault(const int iComType, const int iFloorID) const;

	//查找layerInfo对象
	const CProjectLayerInfoOpr::CGJLayerInfo * CProjectLayerInfoOpr::FindLayer(const int iComType, const int iFloorID) const;
	CProjectLayerInfoOpr::CGJLayerInfo * CProjectLayerInfoOpr::FindLayer(const int iComType, const int iFloorID) ;

	//获取主键值floorid)*10000
	int GetKey(int floorid,int comtype) const
	{
		return 10000*(floorid>0?floorid:-floorid)+comtype;
	}
	//通过键值获取floorid与comtype
	void GetFloorId(int nKey,int & floorid,int & comtype) const
	{
		floorid=nKey/10000;
		comtype=nKey%10000;
		floorid=(floorid==-TemFloor?TemFloor:floorid);
	}

private:
	static CProjectLayerInfoOpr * m_pInstance;

	//正规楼层存储的图层数据
	std::map<int ,CGJLayerInfo*> m_mapLayerInfoFloor;

	//-1000的楼层存储的图层数据
	std::map<int ,CGJLayerInfo *> m_mapLayerInfoBase;

	//
	CProjectLayerInfoOpr() ;
	~CProjectLayerInfoOpr() ; 
};

class PMProjectDBSERVICE CProject_CheckLayerCache
{
public:
	CProject_CheckLayerCache();
	virtual ~CProject_CheckLayerCache();

	/**
	* @brief 获取 图层信息
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL GetLayerInfo(const CString strLayerInfo,CAccessProject_LayerInfoTable::CLayerInfo & temLayerInfo);

protected:
	typedef std::map<CString,CAccessProject_LayerInfoTable::CLayerInfo *> LayerNameMapLayerInfo_T;
	LayerNameMapLayerInfo_T m_MapLayerInfo;
};