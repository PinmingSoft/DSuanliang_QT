// FloorOperate.h: interface for the CFloorOperate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROJECT_FLOOROPERATE_H__E864B861_D811_4065_904A_F03E4058486D__INCLUDED_)
#define AFX_PROJECT_FLOOROPERATE_H__E864B861_D811_4065_904A_F03E4058486D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/******************************************************************** 
 �������������� ��װһЩ¥�����
 ������
 �� �� ֵ��
 �㷨��
 ע�����
 ��    �ߣ�����ҫ
 ʱ    �䣺[2009��3��19��]
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

	/// extern ģ����Ҫ���øýӿ�
	BOOL AddFloorGjxxInfo_Extern(int nFloorID );

	/// ���mode������Ҫ�������øýӿ�
	void DelFloorBGMode_Face(int nFloorID);

	void DelFloor(int nFloorID);

	int AddFloor();

	int CopyFloor( int nSrcFloorID );

	//�ж�DWG�ļ��Ƿ����
	static BOOL CreateNewDWGFile(const CString strlcmc,CString & strNewDWGName);

public:

	/// 
	/// ���º�¥����ص�����
	/// 
	void	UpdateInfoWithFloor( CSQLDataSet * pFloorDataSet ) ; 

	/// �����ϵ�������ʱ�����õĽӿ�
	/// �����͸��ƹ��øýӿ�
	int	AddFloor( CSQLDataSet * pFloorDataSet , const int iSrcFloorId = 1 ) ;

private:
	void	GetFloorIdSet( NDataModelDataSet * pFloorDataSet , CPmIntSet & setFloorId ) ; 

	//�½�¥�㣬�½�ʱ���Ʊ�project���̵�srcFloorid ¥������
	void	AddFloor_v2( const int iFloorId , const int iSrcFloorId = 1 ) ; 

	//�½�¥�㣬�½�ʱ����ģ������¥������
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


	/// �½�¥��ʱ����ģ�帴������
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

	/// �������ݵ�ͬ����
	void	SynFloorInfo( const CPmIntSet & setNewFloorId ) ; 

protected:
	void	Set2Ary( const CPmIntSet & setComId , CUIntArray & aryComId ) ;


private:

	/// ��ӹ���
	void AddComponent( int nFloorID );
	/// ���ƹ���
	void CopyComponent( int nSrcFloorID , int nTargetFloorID ) ;
	/// ɾ������
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


	/// ɾ��DataSet 
	void	DeleteDataSet( ) ;

	/// ����DataSet
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
	/// ����ҫ [2014��5��23��]
	/// ˵��: qc:15274 . �Ѿ��ܴ�Ĺ������½�¥������
	/// 
	NDataModelDataSet * m_pXmtzDataSet ;
	NDataModelDataSet * m_pXmtzDataSetTemplate;

	/// 
	/// qdid ��Ӧ m_pXmtzDataSet �е���ʼ�к�
	/// 
	CPmInt2IntMap	m_mapQdid2Row ; 
	CPmInt2IntMap	m_mapQdid2RowTemplate;

//////////////////////////////////////////////////////////////////////////
	/// ����
	/// 
	CSQLDataSet * m_pComParmComId ; 

	/// 
	CSQLDataSet * m_pComParmHandle ; 

//////////////////////////////////////////////////////////////////////////
	/// �嵥����
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
	//ע��¥����Ϣʹ��
	/**
	* @brief  ע��¥������ 
	*
	*          
	* @note  : 
	* @param : const CStringArray & strDSlcmcArr�����ϲ���¥�����ƶ���(˳�� 1��->����)
	*		   const CStringArray & strDXLcmcArr�����²���¥�����ƶ���(˳�� 0��->-1��)
	*			CUIntArray & iDSFloorIDArr��ʶ��֮����ϲ���¥��ID
	*			CUIntArray & iDXFloorIDArr��ʶ��֮�� ���²���¥��ID
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [5/12/2012]
	*/
	BOOL Reg_FloorLcmc(const CStringArray & strDSlcmcArr,const CStringArray & strDXLcmcArr,\
		CUIntArray & iDSFloorIDArr,CUIntArray & iDXFloorIDArr);
	
	/**
	* @brief   ����¥����Ϣ
	*
	*          
	* @note  : 
	* @param : int iFloorID:¥��ID
	*			double dLdmbg��¥�����ߣ�mm��
	*			const CString & strTQD����ǿ��
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/12/2012]
	*/
	BOOL Reg_FloorInfo(int iFloorID,int iLdmbg,int iCG,const CString & strTQD);

	/**
	* @brief  ���ù����� ��ǿ�� 
	*
	*          
	* @note  : 
	* @param : int iFloorID:¥��ID
	*			int iComtype:��������
	*			const CString & strTQD����ǿ��
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/12/2012]
	*/
	BOOL Reg_SetFloorGJXX_TQD(int iFloorID,int iComtype,const CString & strTQD);

	BOOL ReSumFloorLADMBG();

	BOOL FinishRegFloorInfo();

protected:
	/// �������þ������͵� ��ǿ��
	BOOL	ChangeWithTqd( NDataModelDataSet * pFloorGjxxDataSet , const int iRow ) ;

	/// ����¥�����ǿ�ȣ�����Ҫ������ �ṹ����
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
