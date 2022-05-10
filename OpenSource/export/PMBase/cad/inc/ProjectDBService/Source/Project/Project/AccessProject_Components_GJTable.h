#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_Components_GJTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_Components_GJTable)

	CProject_Components_GJTable();
	virtual ~CProject_Components_GJTable();

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

		static int id_Idx ;					
		static int comname_Idx ;				//构件名称	
		static int floorid_Idx ;				//楼层ID
		static int folderid_Idx ;			//构件夹ID
		static int comtype_Idx ;				//构件类别	
		static int volume_Idx ;				//此构件的数量
		static int comparms_Idx ;			//构件属性
		static int inputdata_Idx ;			//平法表格数据
		static int showid_Idx ;				
		static int sumvolume_Idx ;		

		/// idx 递增的辅助变量
		/// idx 需要在函数 InitFieldStr 外 ，初始化为有意义的值
		/// 且赋值的顺序应该和 InitFieldStr中添加的顺序一样
		static int idx_step ; 
	};

	struct PMProjectDBSERVICE CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_Components_GJTable :
	public CPMSLAccessTable
{
	typedef enum EComSortMode 
	{
		csm_Null     = 0,
		csm_ID       = 1,			//按ID来排序
		csm_ShowID   = csm_ID << 1,	//按showid来排序
		csm_FloorID  = csm_ID << 2,	//按FloorID来排序
		csm_FolderID = csm_ID << 3  //按FolderID来排序
	}ComSortMode;	

	typedef CArray<EComSortMode, EComSortMode> ComSortModeArr;

public:
	CAccessProject_Components_GJTable(void);

	virtual ~CAccessProject_Components_GJTable(void);

	void ModifyOneRow(int iComID,int iNewFloorID, const CString & strNewFoldID);

	int CopyOneRow(int nComID,int iFloorID, CString strFoldID);

	/// 
	BOOL GetMaxComId( int & iMaxComId ) ;

	/**
	* @brief  获取 指定 楼层 构件夹 对应的 ComID 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [23/7/2012]
	*/
	void GetComID(const CUIntArray &arr_floor, 
		const CUIntArray &arr_comfolder, 
		CUIntArray &arr_comid );
	/**
	 * @brief 获取全部的ComID
	 *
	 *        
	 * @author 郑琪崇
	 * @version v1.0
	 * @date  2016年1月29日   19:02
	 * @note  
	 */
	void GetComID( CUIntArray &arr_comid );

	/**
	* @brief  按ComID 获取 对应的 记录集
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [20/7/2012]
	*/
	BOOL GetTableCtrl_ComID(int iComID,CPMSQLTableCtrl *& pSQLTableCtrl);

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

	/// 
	void				DelOwnCom( const int iComId ) ;
	void				DelOwnCom( const CUIntArray & aryComId );
	void				DelOneFloor( const int iFloor);
	//在构件列表中插入一条指定类别的构件
	int					Insert( const int comType);
	int					Insert( const int iFloorID,const CString & strFoldID, const CString & ComName, const int & iComType, const int iVolume ,const int iSumVolume);
	
	/**
	* @brief   获取 DataSet
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/6/2012]
	*/
	BOOL GetDataSet_FloorComType(int iFloorID,int iComType,CSQLDataSet *& pComponentDataSet);

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


	////////////////////////////////////////////////////////////////
	/// at 2011年1月24日  18:32  by yxy
	/// 改为静态函数 
	//取得构件的输入的DataSet 参数为构件类别，本函数产生一个空的框架
	static NDataModelDataSet * GetInputDataSetByType(int comType);//返回的指针需要delete

	/// 获取保存的参数的DataSet 
	static NDataModelDataSet * GetComParmsDataSet() ; 

	//取得输入数据的DataSet 如果是新建的构件，可以先插入一条记录以后进行取得
	NDataModelDataSet * GetInputDataSet(const int iComId );//返回的指针需要delete
	//取得计算结果的值，格式为 DataSet数据集
	NDataModelDataSet * GetCalResultDataSet(const int iComId );//返回的指针需要delete
	//取得存储控件设置参数信息的表
	NDataModelDataSet * GetComParmsDataSet(const int iComId );//返回的指针需要delete
//	CParms *             GetComponentParms(const int iComId );
	//设置输入数据集到记录
	void				SetInputDataSet(const int iComId , NDataModelDataSet *pDataSet);
	//设置输入到结果区的记录
	void				SetCalResultDataSet(const int iComId , NDataModelDataSet *pDataSet);
	//设置输入到控件参数信息的记录
	void				SetComParmsDataSet(const int iComId , NDataModelDataSet *pDataSet);

	//设置 showid
	BOOL				SetShowID(const int iComId,int iShowID);

	//设置 comname
	BOOL				SetComName(const int iComId,const CString & strComName);

	//设置 comVolume
	BOOL				SetComVolume(const int iComId,float fComVolume);

	//设置 comSumVolume
	BOOL				SetComSumVolume(const int iComId,float fComSumVolume);

	/// 设置comtype
	BOOL				SetComType( const int iComId , const int iComType ) ; 

	/// 设置ComFolder
	BOOL				SetComFolder( const int iComId , const int iComFolderId ) ;

	/// 
	BOOL			SetComParms( const int iComId , const LPVOID pBuffer , const LONG lSize ) ;
	BOOL			SetInputData( const int iComId , const LPVOID pBuffer , const LONG lSize ) ;

private:

	BOOL				GetComParms(const int iComId ,LPVOID & pBuffer,LONG & lSize);
	BOOL				GetInputData(const int iComId ,LPVOID & pBuffer,LONG & lSize);


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
	BOOL			GetTable_MaxID(int & iMaxID);

public:

	//取得构件类别
	int					GetComType( const int iComID );
	int					GetFloorID(const int iComID );
	int					GetComSumVolume(const int iComID );	
/// 仔细阅读老的代码发现就是获取构件名称，所以屏蔽，使用GetComName 代替
///	CString				GetComFoldName(const int iComID );
	CString				GetComVolume(const int iComID );
	CString				GetComName(const int iComID );
	CString				GetComFolderID(const int iComID );

	/**
	* @brief  通过条件 获取 DataSet 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [20/7/2012]
	*/
	NDataModelDataSet * GetDataSet(const CStringArray &strFieldArr, const CStringArray & strValueArr);

	/// 根据ComID 获取Dataset
	NDataModelDataSet * GetDataSet( const int iComId ) ; 

	/**
	* @brief  获取所有 记录集 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [20/7/2012]
	*/
	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetRowCount( int & iRowCount ) ;
	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;

private:

	/// 获取列的数据
	CString			GetColAsString( const int iComId ,const CString & strColName ) ;
	
	/// 
	int				GetColAsInterger( const int iComId , const CString & strColName ) ;

	/// 
	BOOL			GetColAsBlob( const int iComId , const CString & strColName , LPVOID & pBuffer,LONG & lSize ) ;


	BOOL	SetColValue( const int iComId , const CString & strColName , const CString & strColValue ) ;


public:
	//固定的SQL 集合
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetDataSet1 ;
		static PMTSTRING m_strGetDataSet1 ; 

		/// 
		static const int m_iSetComParms ;
		static PMTSTRING m_strSetComParms ; 

		/// 
		static const int m_iInputData ;
		static PMTSTRING m_strInputData ; 

		/// 
		static const int m_iDelOwnCom ;
		static PMTSTRING m_strDelOwnCom ; 

		/// 
		static const int m_iDelOneFloor ;
		static PMTSTRING m_strDelOneFloor ; 

		/// 
		static const int m_iInsert ; 
		static PMTSTRING m_strInsert ; 

		/// 
		static const int m_iUpdateShowID_ComID ; 
		static PMTSTRING m_strUpdateShowID_ComID ; 

		/// 
		static const int m_iUpdateComName_ComID ; 
		static PMTSTRING m_strUpdateComName_ComID ; 

		/// 
		static const int m_iUpdateVolume_ComID ; 
		static PMTSTRING m_strUpdateVolume_ComID ;

		/// 
		static const int m_iUpdateSumVolume_ComID ; 
		static PMTSTRING m_strUpdateSumVolume_ComID ;

		/// 
		static const int m_iSetColValue ;
		static PMTSTRING m_strSetColValue ; 
	} ;
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

class PMProjectDBSERVICE CProjectComponentsGjOpr
{
public:
	CProjectComponentsGjOpr() ;
	~CProjectComponentsGjOpr() ;

public:
	static int					GetComType( const int iComID );
	static int					GetFloorID(const int iComID );
	static int					GetComSumVolume(const int iComID );	
	static CString				GetComVolume(const int iComID );
	static CString				GetComName(const int iComID );
	static CString				GetComFolderID(const int iComID );
	static CString				GetComFoldName(const int iComID );

	//取得输入数据的DataSet 如果是新建的构件，可以先插入一条记录以后进行取得
	static NDataModelDataSet * GetInputDataSet(const int iComId );//返回的指针需要delete
	//取得计算结果的值，格式为 DataSet数据集
	static NDataModelDataSet * GetCalResultDataSet(const int iComId );//返回的指针需要delete
	//取得存储控件设置参数信息的表
	static NDataModelDataSet * GetComParmsDataSet(const int iComId );//返回的指针需要delete
//	static CParms *             GetComponentParms(const int iComId );
	//设置输入数据集到记录
	static void				SetInputDataSet(const int iComId , NDataModelDataSet *pDataSet);
	//设置输入到结果区的记录
	static void				SetCalResultDataSet(const int iComId , NDataModelDataSet *pDataSet);
	//设置输入到控件参数信息的记录
	static void				SetComParmsDataSet(const int iComId , NDataModelDataSet *pDataSet);

	static void				DelOwnCom( const int iComId ) ;
	static void				DelOwnCom( const CUIntArray & aryComId );
	static void				DelOneFloor( const int iFloor);
	//在构件列表中插入一条指定类别的构件
	static int					Insert( const int comType);
	static int					Insert( const int iFloorID,const CString & strFoldID, const CString & ComName, const int & iComType, const int iVolume ,const int iSumVolume);

	static BOOL GetRowCount( int & iRowCount ) ;

	static NDataModelDataSet * GetDataSet(const CStringArray &strFieldArr, const CStringArray & strValueArr) ;
	static NDataModelDataSet * GetDataSet() ; 


	/// 设置comtype
	static BOOL				SetComType( const int iComId , const int iComType ) ; 

	/// 设置ComFolder
	static BOOL				SetComFolder( const int iComId , const int iComFolderId ) ;

	//设置 comname
	static BOOL				SetComName(const int iComId,const CString & strComName);


};
