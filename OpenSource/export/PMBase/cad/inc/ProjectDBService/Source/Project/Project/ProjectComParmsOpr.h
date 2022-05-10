

#pragma once 

/**
 * @brief ��������������
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2013-5-20]
 * @note  
 */

//#include "..\DataBaseAndTableName.h"
#include "Project_ComParmsCache.h"
class PMProjectDBSERVICE CProjectComParmsOpr 
{

public:
	CProjectComParmsOpr() ; 
	~CProjectComParmsOpr() ;

public:
	static void Release() {pmcommon::ReleaseMem(m_mapComtye2Parms);}
	static void	SynComParmDataSet(const NDataModelDataSet * pSrcDataSet , NDataModelDataSet * pDesDataSet ) ;

	//��ȡĬ�ϲ���ֵ
	static CString GetDefaultValue(int comtype,int nSubComtype,CString parmName);
	//��ȡ������Ĭ�� used_bz ����
	static const CSubComtypeParms * GetDefaultParm(int comtype);

public:
	/**
	* @brief   ������ȡ������ǰʹ�õĲ���
	*
	*			
	* @note  : 
	* @param : bForceReplaceComParms ��ʾ����Ѵ��ڲ������Ƿ�ǿ�����´����ݿ��ȡ����
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [9/3/2019]
	*/
	static BOOL GetComParms(const CUIntArray & arrComId,const CUIntArray & arrComtype,const CUIntArray & arrFloorId,BOOL bForceReplaceComParms,std::map<int,CSLComponentManager::CComponentInfo*> & mapComponent);
	static BOOL GetComParmsOld(const CUIntArray & arrComId,const CUIntArray & arrComtype,const CUIntArray & arrFloorId,std::map<int,CSLComponentManager::CComponentInfo*> & mapComponent);
	
	//��ȡ comparmsset_base ��Ĭ�����ݲ�תΪ map�ṹ qc30527
	static BOOL GetComParmsBase();

	/**
	* @brief   ��ȡcomtype�������ƥ��
	*
	*			ע�⣺CParm �� InsertExpress ֵ�д�����parmtype��ֵ���Ա��ⲿʹ��
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [9/9/2019]
	*/
	static BOOL GetComtypeParms(std::map<int,CSubComtypeParms *> & mapComtype2Parms,const CUIntArray & arrParmtype);

	/**
	* @brief  ��ȡ ���ݿ���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [28/5/2013]
	*/
	static BOOL GetComParmsSetComID(const int iComId,CUIntArray & iParmTypeArr,CCalComParmsInfoArr & comParmsInfoArr);

	/**
		* @brief ��ȡһ���������͵����в���
		*
		*          
		* @note  : 
		* @param : 
		* @defenc: 
		* @return: 
		* @author: ����ҫ
		* @date  : 2013��8��29��   13:48
	*/
	static NDataModelDataSet * GetComParmsSetComType( const int iComType , const CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Project) ;

public:
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// �ۺϽӿ�
	/**
	* @brief   ��ȡ��������
	* @author: ����ҫ
	* @date  : [2013-5-20]
	*/
	static NDataModelDataSet * GetComParmsSet( const int iComId , const CString & strHandle = _T("") , const CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Project ) ;

	/// 
	/// �½��ⲿ������Դ��ʱ����Ҫ����comtype
	/// 
	static NDataModelDataSet * GetComParmsSetExtern( const int iExternComId , const int iExternComType , const CString & strHandle = _T("") , const CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Extern ) ;

	/**
	* @brief   ���ù������� 
	* @author: ����ҫ
	* @date  : [2013-5-20]
	*/
	static void	SetComParmsSet( const int iComId , const NDataModelDataSet * pDataSet , const CString & strHandle = _T("")  ) ; 

	/**
	* @brief   ɾ��˽�����Ե����� 
	* @author: ����ҫ
	* @date  : [2013-5-20]
	*/
	static void	Delete( const int iComId , const CString & strHandle ) ;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// comid 
public:
	/**
	* @brief   ��ȡcomid����Ĺ�������
	* @author: ����ҫ
	* @date  : [2013-5-20]
	*/
	static NDataModelDataSet * GetComParmsSetComId( const int iComId  , const int iComType ,const CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Project ) ; 

	/**
	* @brief   �����ݿ�������ȡ����dataset����
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/26/2020]
	*/
	static BOOL GetComParmsAllFromDb(std::map<int, NDataModelDataSet *> & mapComParms ,const CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Project);
	
	/**
	* @brief   ���ù�������  ---- comid ����
	* @author: ����ҫ
	* @date  : [2013-5-20]
	*/
	static void	SetComParmsSetComId( const int iComId , const NDataModelDataSet * pDataSet ) ; 

	/// ��ע������
	static void	SaveComParmsSetBz( const int iComId );

protected:
	
	/// 
	static CString		GetFinalParmValue( const CString & strParmValueComId , const CString & strParmValue ) ;

	/// 
	static CString		GetFinalInvalidMsg(  const CString & strInvalidMsgComId , const CString & strInvalidMsg ) ;

public:
	static int		GetComponentTypeComId( const int iComId ) ; 
	static void		GetComponentTypeComId( const CUIntArray & arrComId,const CUIntArray & arrComtype,std::map<int,int> & mapComid2ComponentType);

protected:

	/**
	* @brief   ��ȡ ComParmsDataSet �Ľṹ comid����
	* @author: ����ҫ
	* @date  : [2013-5-20]
	*/
	static NDataModelDataSet	*	GetComParmsDataSetComId() ; 

public:

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// handle 

	/**
	* @brief   ��ȡhandle����Ĺ�������
	* @author: ����ҫ
	* @date  : [2013-5-20]
	*/
	static NDataModelDataSet * GetComParmsSetHandle( const int iComId ,  const int iComType , const CString & strHandle , const CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Project ) ; 
	static NDataModelDataSet * GetComParmsSetHandle( const int iComId  , const CString & strHandle , const CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Project ) ; 
	
	/**
	* @brief   ���ù�������  ---- handle ����
	* @author: ����ҫ
	* @date  : [2013-5-20]
	*/
	static void	SetComParmsSetHandle( const int iComId , const CString & strHandle  , const NDataModelDataSet * pDataSet ) ; 

protected:
	//ԭʼ�� comparmsset_base ����
	static std::map<int,CSubComtypeParms *> m_mapComtye2Parms;

	/// 
	static CString		GetFinalParmValue( const CString & strParmValueHandle  , const CString & strParmValueComId , const CString & strParmValue ) ;

	/// 
	static CString		GetFinalInvalidMsg( const CString & strInvalidMsgHandle  , const CString & strInvalidMsgComId , const CString & strInvalidMsg ) ;

	/// 
	static int			GetComponentTypeHandle( const int iComId , const CString & strHandle ) ;

	static void			InsertComParmsRow(int comid, NDataModelDataSet * pComParmDataSet, CPMSQLTableCtrl * pSqlTableCtrl );

	/**
	* @brief   ��ȡ ComParmsDataSet �Ľṹ handle����
	* @author: ����ҫ
	* @date  : [2013-5-20]
	*/
	static NDataModelDataSet	*	GetComParmsDataSetHandle() ; 

	/// ��̬���� ������ֱ������
public:
	
	/// 
	static const	CString  m_strParmValueBase ;
	static const	CString  m_strParmValueHandle ; 
	static const	CString	 m_strParmValueComId ; 

	/// 
	static const	CString	 m_strInvalidMsgBase ; 
	static const	CString  m_strInvalidMsgHandle ; 
	static const	CString	 m_strInvalidMsgComId ; 

	/// 
	static const	CString  m_strPmEmpty ; 

};



typedef std::map< int , NDataModelDataSet * > PmInt2DataSetMap ; 
typedef PmInt2DataSetMap::iterator PmInt2DataSetMapIter ; 
typedef PmInt2DataSetMap::const_iterator PmInt2DataSetMapConIter ; 

typedef std::map< CString , NDataModelDataSet * > PmStr2DataSetMap ;
typedef PmStr2DataSetMap::iterator PmStr2DataSetMapIter ; 
typedef PmStr2DataSetMap::const_iterator PmStr2DataSetMapConIter ; 


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ���ƹ��������Ƿ�ʹ�û��� 
///
class PMProjectDBSERVICE CProjectComParmsCacheOpr
{
public:
	CProjectComParmsCacheOpr() ;
	virtual ~CProjectComParmsCacheOpr() ; 

public:
	BOOL		UseCache() const 
	{
		return m_bUseCache ; 
	}

	void		SetUseCache( const BOOL bUseCache )  
	{
		m_bUseCache = bUseCache ;
	}

public:


protected:

	/// ��ʶ�Ƿ�ʹ�û���
	BOOL		m_bUseCache ; 

	/// comid  --- > pComParmDataSet 
	PmInt2DataSetMap m_mapComId2Parm ; 

	/// comid + handle --- > pComParmDataSet 
	PmStr2DataSetMap	m_mapComHandle2Parm ; 
};




