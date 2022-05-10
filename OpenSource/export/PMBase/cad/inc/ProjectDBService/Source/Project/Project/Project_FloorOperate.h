// FloorOperate.h: interface for the CFloorOperate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROJECT_FLOOROPERATE_H__E864B861_D811_4065_904A_F03E4058486D__INCLUDED_)
#define AFX_PROJECT_FLOOROPERATE_H__E864B861_D811_4065_904A_F03E4058486D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/******************************************************************** 
 功能描述：该类 封装一些楼层操作
 参数：
 返 回 值：
 算法：
 注意事项：
 作    者：杨兴耀
 时    间：[2009年3月19日]
*********************************************************************/ 


typedef std::set<int> CPmIntSet ; 
typedef CPmIntSet::iterator	CPmIntSetIter ;
typedef CPmIntSet::const_iterator CPmIntSetConIter ; 


/// 
typedef std::map< int , int > CPmInt2IntMap ;
typedef CPmInt2IntMap::iterator CPmInt2IntMapIter ; 
typedef CPmInt2IntMap::const_iterator CPmInt2IntMapConIter ; 

class PMProjectDBSERVICE CProject_FloorOperate  
{
public:
	CProject_FloorOperate();
	virtual ~CProject_FloorOperate();

public:

	/// extern 模块需要调用该接口
	BOOL AddFloorGjxxInfo_Extern(int nFloorID );

	/// 标高mode界面需要单独调用该接口
	void DelFloorBGMode_Face(int nFloorID);

	void DelFloor(int nFloorID);

	int AddFloor();

	int CopyFloor( int nSrcFloorID );

	//判断DWG文件是否存在
	static BOOL CreateNewDWGFile(const CString strlcmc,CString & strNewDWGName);

public:

	/// 
	/// 更新和楼层相关的数据
	/// 
	void	UpdateInfoWithFloor( CSQLDataSet * pFloorDataSet ) ; 

	/// 界面上单击新增时，调用的接口
	/// 新增和复制公用该接口
	int	AddFloor( CSQLDataSet * pFloorDataSet , const int iSrcFloorId = 1 ) ;

private:
	void	GetFloorIdSet( NDataModelDataSet * pFloorDataSet , CPmIntSet & setFloorId ) ; 

	//新建楼层，新建时复制本project工程的srcFloorid 楼层数据
	void	AddFloor_v2( const int iFloorId , const int iSrcFloorId = 1 ) ; 

	//新建楼层，新建时复制模板的相关楼层数据
	void	AddFloor_Template(  const int iFloorId  , const int iSrcFloorId = 1  ) ;

	void	DelFloor_v2( const int iFloorId ) ; 

	CString GetNewLcmc_v2( NDataModelDataSet * pFloorDataSet );

	int GetNewFloorID_v2( NDataModelDataSet * pFloorDataSet);

	/// add 
	void	AddFloorGjxxInfo_v2( const int iFloorId  , const int iSrcFloorId = 1  ) ; 

	BOOL	AddComFolder_v2( const int iFloorId  , const int iSrcFloorId = 1 );

	BOOL    AddFloorBGMode_v2( const int iFloorId  , const int iSrcFloorId = 1 );

	BOOL	AddFloorLayer_v2(const int iFloorId  , const int iSrcFloorId = 1 );

	BOOL	AddFloorDrawIndex_v2(const int iFloorId  , const int iSrcFloorId = 1 );


	BOOL	AddFloorGJXX_MGDJDataSet_v2(CSQLDataSet * pFloorDJMGInfoTable,int iOldFloorGJXXIndex,int iNewFloorGJXXIndex);

	void	AddComponent_v2( const int iFloorId   ,  CPmInt2IntMap & mapComIdOld2New , const int iSrcFloorId = 1 );

	/// 
	void	AddComParmsSetComId_v2( const CPmInt2IntMap & mapComIdOld2New ) ;

	/// 
	void	AddQddeComId_v2( const CPmInt2IntMap & mapComIdOld2New , CPmInt2IntMap & mapIdOld2New ) ;

	void	AddQddeInfoComId_v2(  const CPmInt2IntMap & mapIdOld2New ) ; 

	void	AddQddeXmtzComId_v2(  const CPmInt2IntMap & mapIdOld2New ) ; 

	void	AddGangJinVector_v2( const CPmInt2IntMap & mapComIdOld2New ) ;

	void	AddComponent_Template( const int iFloorId   ,  CPmInt2IntMap & mapComIdOld2New , const int iSrcFloorId = 1 );


	/// 新建楼层时，从模板复制属性
	void	AddComParmsSetComId_Template( const CPmInt2IntMap & mapComIdOld2New ) ;

	/// 
	void	AddQddeComId_Template( const CPmInt2IntMap & mapComIdOld2New , CPmInt2IntMap & mapIdOld2New ) ;

	void	AddQddeInfoComId_Template(  const CPmInt2IntMap & mapIdOld2New ) ; 

	void	AddQddeXmtzComId_Template(  const CPmInt2IntMap & mapIdOld2New ) ; 

	void	AddGangJinVector_Template( const CPmInt2IntMap & mapComIdOld2New ) ;


	/// del 
	void	DelFloorBGMode_v2( const int iFloorId ) ; 
	void	DelComFolder_v2( const int iFloorId ) ; 
	void	DelFloorGjxxInfo_v2( const int iFloorId ) ; 
	void	DelFloorLayer_v2( const int iFloorId ) ; 
	void	DelDrawIndex_v2( const int iFloorId ) ; 
	void	DelComponent_v2( const int iFloorId , CPmIntSet & setComId ) ; 
	void	DelOwnGanJinVector_v2( const CPmIntSet & setComId ) ; 
	void	DelEditOtherItem_v2( const int iFloorId ) ; 

	/// 
	void	DelComParmsSetHandle_v2( const CPmIntSet & setComId ) ; 

	void	DelComParmsSetComId_v2( const CPmIntSet & setComId  ) ; 

	/// 
	void	DelQddeComId_v2( const CPmIntSet & setComId , CPmIntSet & setQdId ) ; 

	void	DelQddeInfoComId_v2( const CPmIntSet & setQdId ) ;

	void	DelQddeXmtzComId_v2( const CPmIntSet & setQdId ) ;


	/// 
	void	DelQddeHandle_v2( const CPmIntSet & setComId , CPmIntSet & setQdId ) ; 

	void	DelQddeInfoHandle_v2( const CPmIntSet & setQdId ) ;

	void	DelQddeXmtzHandle_v2( const CPmIntSet & setQdId ) ;

	void	DelKcEntity_v2(const int iFloorID);

	/// 处理数据的同步，
	void	SynFloorInfo( const CPmIntSet & setNewFloorId ) ; 

protected:
	void	Set2Ary( const CPmIntSet & setComId , CUIntArray & aryComId ) ;


private:

	/// 添加构件
	void AddComponent( int nFloorID );
	/// 复制构件
	void CopyComponent( int nSrcFloorID , int nTargetFloorID ) ;
	/// 删除构件
	void DelComponent( int nFloorID ) ; 

	int CopyOneRowData_Floor( int nSrcFloorID );
	void CopyFloorBGMode( int nSrcFloorID, int nTargeitFloorID );
	BOOL CopyComFolder(int nSrcFloorID, int nTargeitFloorID);
	BOOL CopyFloorGjxxInfo( int nSrcFloorID , int nTargeitFloorID );

	BOOL AddComFolder(int nFloorID);
	BOOL AddFloorBGMode(int nFloorID);
	BOOL AddFloorLayer(int nFloorID);
	BOOL AddFloorDrawIndex(int nFloorID);
	BOOL AddFloorGJXX_MGDJDataSet(CSQLDataSet * pFloorDJMGInfoTable,int iOldFloorGJXXIndex,int iNewFloorGJXXIndex);
	BOOL AddFloorGjxxInfo(int nFloorID );

	void DelOneRow_Floor(int nFloor);
	void DelFloorDjxs(int nDjxsID);
	void DelFloorGjxxInfo(int nFloorID);
	void DelComFolder(int nFloorID);
	void DelFloorLayer(int nFloorID);
	void DelDrawIndex(int nFloorID);

	void DelFloorBGMode(int nFloorID);

	int GetNewFloorID();
	int AddOneRowData_Floor();
	CString GetNewLcmc();


	/// 删除DataSet 
	void	DeleteDataSet( ) ;

	/// 更新DataSet
	void	UpdateDataSet( ) ; 

private:
	void	InitOrgXmtz() ; 
	void	InitOrgXmtz_Template();
	void	DeleteOrgXmtz() ;

private:
	CSQLDataSet * m_pFloorInfoDataSet ;
	CSQLDataSet * m_pFloorGJXXDataSet ;
	CSQLDataSet * m_pFloorDJMGInfoTable ;
	CSQLDataSet * m_pComFolderDataSet ;
	CSQLDataSet * m_pFloorBGDataSet ;
	CSQLDataSet * m_pLayerDataSet ;
	CSQLDataSet * m_pDrawIndexDataSet ;
	CSQLDataSet * m_pComponentDataSet ;
	CSQLDataSet * m_pkcEntityDataSet;

	CSQLDataSet * m_pEditOtherItem ;

	CSQLDataSet * m_pGanJinVectorDataSet ; 

	////////////////////////////////////////////
	/// 杨兴耀 [2014年5月23日]
	/// 说明: qc:15274 . 已经很大的工程中新建楼层会很慢
	/// 
	NDataModelDataSet * m_pXmtzDataSet ;
	NDataModelDataSet * m_pXmtzDataSetTemplate;

	/// 
	/// qdid 对应 m_pXmtzDataSet 中的起始行号
	/// 
	CPmInt2IntMap	m_mapQdid2Row ; 
	CPmInt2IntMap	m_mapQdid2RowTemplate;

//////////////////////////////////////////////////////////////////////////
	/// 参数
	/// 
	CSQLDataSet * m_pComParmComId ; 

	/// 
	CSQLDataSet * m_pComParmHandle ; 

//////////////////////////////////////////////////////////////////////////
	/// 清单定额
	/// 
	CSQLDataSet * m_pQdDeComId ;

	/// 
	CSQLDataSet * m_pQddeInfoComId ; 

	/// 
	CSQLDataSet * m_pQddeXmtzComId ; 

//////////////////////////////////////////////////////////////////////////
	/// 
	/// 
	CSQLDataSet * m_pQdDeHandle ;

	/// 
	CSQLDataSet * m_pQddeInfoHandle ; 

	/// 
	CSQLDataSet * m_pQddeXmtzHandle ; 


};

class PMProjectDBSERVICE CProject_RegFloorInfoOpr
{
public:
	CProject_RegFloorInfoOpr();
	virtual ~CProject_RegFloorInfoOpr();

	struct PMProjectDBSERVICE CFloorInfo
	{
		int m_iID;
		CString  m_strFloorName;
		float m_fcg;
		float m_fldmbg;
	};

	//////////////////////////////////////////////////////////////////////////
	//注册楼层信息使用
	/**
	* @brief  注册楼层名称 
	*
	*          
	* @note  : 
	* @param : const CStringArray & strDSlcmcArr：地上部分楼层名称队列(顺序 1层->顶层)
	*		   const CStringArray & strDXLcmcArr：地下部分楼层名称队列(顺序 0层->-1层)
	*			CUIntArray & iDSFloorIDArr：识别之后地上部分楼层ID
	*			CUIntArray & iDXFloorIDArr：识别之后 地下部分楼层ID
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [5/12/2012]
	*/
	BOOL Reg_FloorLcmc(const CStringArray & strDSlcmcArr,const CStringArray & strDXLcmcArr,\
		CUIntArray & iDSFloorIDArr,CUIntArray & iDXFloorIDArr);
	
	/**
	* @brief   设置楼层信息
	*
	*          
	* @note  : 
	* @param : int iFloorID:楼层ID
	*			double dLdmbg：楼地面标高（mm）
	*			const CString & strTQD：砼强度
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/12/2012]
	*/
	BOOL Reg_FloorInfo(int iFloorID,int iLdmbg,int iCG,const CString & strTQD);

	/**
	* @brief  设置构件的 砼强度 
	*
	*          
	* @note  : 
	* @param : int iFloorID:楼层ID
	*			int iComtype:构件类型
	*			const CString & strTQD：砼强度
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/12/2012]
	*/
	BOOL Reg_SetFloorGJXX_TQD(int iFloorID,int iComtype,const CString & strTQD);

	BOOL ReSumFloorLADMBG();

	BOOL FinishRegFloorInfo();

protected:
	/// 单独设置具体类型的 砼强度
	BOOL	ChangeWithTqd( NDataModelDataSet * pFloorGjxxDataSet , const int iRow ) ;

	/// 设置楼层的砼强度，后需要联动到 结构特征
	BOOL	ChangeWithTqd() ; 

protected:

	BOOL InsertObArray(CArray<CFloorInfo*,CFloorInfo*&> & temObjFloorInfoArr,CFloorInfo *pinfo);

	CProject_FloorOperate m_Project_FloorOpr;

	CArray<CFloorInfo*,CFloorInfo*&> m_ObjFloorInfoArr;
	CSQLDataSet * m_pFloorSQLDataSet;
	CSQLDataSet * m_pFloorGJXXSQLDataSet;
	CSQLDataSet * m_pFloorMgDjDataSet ;

	PmInt2CStrMap m_mapFloor2Tqd ; 
};

#endif // !defined(AFX_PROJECT_FLOOROPERATE_H__E864B861_D811_4065_904A_F03E4058486D__INCLUDED_)
