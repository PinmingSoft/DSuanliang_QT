

#pragma once 

/**
 * @brief 构件参数控制类
 *
 *        
 * @author 杨兴耀
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

	//获取默认参数值
	static CString GetDefaultValue(int comtype,int nSubComtype,CString parmName);
	//获取参数的默认 used_bz 属性
	static const CSubComtypeParms * GetDefaultParm(int comtype);

public:
	/**
	* @brief   批量获取构件当前使用的参数
	*
	*			
	* @note  : 
	* @param : bForceReplaceComParms 表示如果已存在参数，是否强制重新从数据库读取数据
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [9/3/2019]
	*/
	static BOOL GetComParms(const CUIntArray & arrComId,const CUIntArray & arrComtype,const CUIntArray & arrFloorId,BOOL bForceReplaceComParms,std::map<int,CSLComponentManager::CComponentInfo*> & mapComponent);
	static BOOL GetComParmsOld(const CUIntArray & arrComId,const CUIntArray & arrComtype,const CUIntArray & arrFloorId,std::map<int,CSLComponentManager::CComponentInfo*> & mapComponent);
	
	//获取 comparmsset_base 表默认数据并转为 map结构 qc30527
	static BOOL GetComParmsBase();

	/**
	* @brief   获取comtype与参数的匹配
	*
	*			注意：CParm 的 InsertExpress 值中存入了parmtype的值，以便外部使用
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [9/9/2019]
	*/
	static BOOL GetComtypeParms(std::map<int,CSubComtypeParms *> & mapComtype2Parms,const CUIntArray & arrParmtype);

	/**
	* @brief  获取 数据库参数 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [28/5/2013]
	*/
	static BOOL GetComParmsSetComID(const int iComId,CUIntArray & iParmTypeArr,CCalComParmsInfoArr & comParmsInfoArr);

	/**
		* @brief 获取一个构件类型的所有参数
		*
		*          
		* @note  : 
		* @param : 
		* @defenc: 
		* @return: 
		* @author: 杨兴耀
		* @date  : 2013年8月29日   13:48
	*/
	static NDataModelDataSet * GetComParmsSetComType( const int iComType , const CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Project) ;

public:
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 综合接口
	/**
	* @brief   获取构件参数
	* @author: 杨兴耀
	* @date  : [2013-5-20]
	*/
	static NDataModelDataSet * GetComParmsSet( const int iComId , const CString & strHandle = _T("") , const CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Project ) ;

	/// 
	/// 谅解外部的数据源的时候，需要传入comtype
	/// 
	static NDataModelDataSet * GetComParmsSetExtern( const int iExternComId , const int iExternComType , const CString & strHandle = _T("") , const CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Extern ) ;

	/**
	* @brief   设置构件参数 
	* @author: 杨兴耀
	* @date  : [2013-5-20]
	*/
	static void	SetComParmsSet( const int iComId , const NDataModelDataSet * pDataSet , const CString & strHandle = _T("")  ) ; 

	/**
	* @brief   删除私有属性的设置 
	* @author: 杨兴耀
	* @date  : [2013-5-20]
	*/
	static void	Delete( const int iComId , const CString & strHandle ) ;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// comid 
public:
	/**
	* @brief   获取comid级别的构件参数
	* @author: 杨兴耀
	* @date  : [2013-5-20]
	*/
	static NDataModelDataSet * GetComParmsSetComId( const int iComId  , const int iComType ,const CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Project ) ; 

	/**
	* @brief   丛数据库批量读取所有dataset数据
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
	* @brief   设置构件参数  ---- comid 级别
	* @author: 杨兴耀
	* @date  : [2013-5-20]
	*/
	static void	SetComParmsSetComId( const int iComId , const NDataModelDataSet * pDataSet ) ; 

	/// 备注的设置
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
	* @brief   获取 ComParmsDataSet 的结构 comid级别
	* @author: 杨兴耀
	* @date  : [2013-5-20]
	*/
	static NDataModelDataSet	*	GetComParmsDataSetComId() ; 

public:

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// handle 

	/**
	* @brief   获取handle级别的构件参数
	* @author: 杨兴耀
	* @date  : [2013-5-20]
	*/
	static NDataModelDataSet * GetComParmsSetHandle( const int iComId ,  const int iComType , const CString & strHandle , const CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Project ) ; 
	static NDataModelDataSet * GetComParmsSetHandle( const int iComId  , const CString & strHandle , const CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Project ) ; 
	
	/**
	* @brief   设置构件参数  ---- handle 级别
	* @author: 杨兴耀
	* @date  : [2013-5-20]
	*/
	static void	SetComParmsSetHandle( const int iComId , const CString & strHandle  , const NDataModelDataSet * pDataSet ) ; 

protected:
	//原始的 comparmsset_base 表备份
	static std::map<int,CSubComtypeParms *> m_mapComtye2Parms;

	/// 
	static CString		GetFinalParmValue( const CString & strParmValueHandle  , const CString & strParmValueComId , const CString & strParmValue ) ;

	/// 
	static CString		GetFinalInvalidMsg( const CString & strInvalidMsgHandle  , const CString & strInvalidMsgComId , const CString & strInvalidMsg ) ;

	/// 
	static int			GetComponentTypeHandle( const int iComId , const CString & strHandle ) ;

	static void			InsertComParmsRow(int comid, NDataModelDataSet * pComParmDataSet, CPMSQLTableCtrl * pSqlTableCtrl );

	/**
	* @brief   获取 ComParmsDataSet 的结构 handle级别
	* @author: 杨兴耀
	* @date  : [2013-5-20]
	*/
	static NDataModelDataSet	*	GetComParmsDataSetHandle() ; 

	/// 静态变量 ，外面直接引用
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
/// 控制构件参数是否使用缓冲 
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

	/// 标识是否使用缓冲
	BOOL		m_bUseCache ; 

	/// comid  --- > pComParmDataSet 
	PmInt2DataSetMap m_mapComId2Parm ; 

	/// comid + handle --- > pComParmDataSet 
	PmStr2DataSetMap	m_mapComHandle2Parm ; 
};




