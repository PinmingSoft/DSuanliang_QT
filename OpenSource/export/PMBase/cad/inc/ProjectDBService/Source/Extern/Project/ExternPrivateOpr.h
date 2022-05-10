

#pragma once 

/**
 * @brief  私有属性相关表的操作 
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  2013年11月8日   9:26
 * @note  
 */

#include "..\ExternManager.h"

class PMProjectDBSERVICE CExternComParmsSetHandleTable : public CExternTableBase 
{
public:

	CExternComParmsSetHandleTable();
	virtual ~CExternComParmsSetHandleTable();

	CSQLDataSet * GetDataSet();

	CSQLDataSet * GetDataSet( const int iComId , const CString & strHandle ) ;
};


class PMProjectDBSERVICE CExternComponentQddeHandleTable : public CExternTableBase 
{
public:

	CExternComponentQddeHandleTable();
	virtual ~CExternComponentQddeHandleTable();

	/// 
	// CSQLDataSet * GetDataSet();

	BOOL GetComID_QDDEDataSet(int iComID,const CString & strHandle,CProject_QDDE_UITable *& pQDDETable) ;

private:
	BOOL GetQDDEDataSet_Info(int iInsertRow,CProject_QDDE_UITable * pQDDEDataSet,int iQDComIDTableID) ;
	BOOL GetQDDEDataSet_XMTZ(int iInsertRow,CProject_QDDE_UITable * pQDDEDataSet,int iQDComIDTableID) ;

};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 私有属性构件操作类
/// 
class PMProjectDBSERVICE CPrivateComOpr
{
public:
	CPrivateComOpr() ; 
	~CPrivateComOpr() ; 

public:
	struct  PMProjectDBSERVICE CPrivateComInfo
	{
		/// 
		int		m_iComId ; 
		CString m_strHandle ; 

	public:

		/// 
		CPrivateComInfo()
		{

		}

		/// 
		CPrivateComInfo( const CPrivateComInfo & other )
		{
			m_iComId = other.m_iComId ; 
			m_strHandle = other.m_strHandle ;
		}

		/// 
		bool operator < (const CPrivateComInfo & other )const
		{
			if ( m_iComId < other.m_iComId )
			{
				return true ;
			}

			if ( m_iComId == other.m_iComId 
				&& m_strHandle.Compare( other.m_strHandle ) < 0 )
			{
				return true ;
			}

			if ( m_iComId == other.m_iComId 
				&& m_strHandle.Compare( other.m_strHandle ) == 0 )
			{
				return true ;
			}

			return false ; 
		}

		/// 
		CPrivateComInfo::~CPrivateComInfo()
		{

		}
	};

	typedef std::vector< CPrivateComInfo * > CPrivateComInfoList ;
	typedef CPrivateComInfoList::iterator CPrivateComInfoListIter ; 
	typedef CPrivateComInfoList::const_iterator CPrivateComInfoListConIter ; 

	typedef std::map< CPrivateComInfo , CPrivateComInfoList * > CPrivateInfoMap ; 
	typedef CPrivateInfoMap::iterator CPrivateInfoMapIter ; 
	typedef CPrivateInfoMap::const_iterator CPrivateInfoMapConIter ; 

public:
	/**
	* @brief 复制实物量与清单定额私有属性构件的信息/ 在数据库中生成新的记录
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [4/19/2019]
	*/
	static void CopyPrivateComInfo( const CPrivateInfoMap & mapPrivateInfo , CPmDataBase::DataBaseName dataBaseName = CPmDataBase::Project,BOOL bQDDEToOtherChapter=FALSE) ;

	/// 
	/// 清除 CPrivateInfoMap 中的指针
	/// 不操作数据库
	/// 
	static BOOL DelPrivateComInfo( const CPrivateInfoMap & mapPrivateInfo ) ;

private:
	static	void	ReplaceComIdHandle( CSQLDataSet * pDataSet , const int iComId , const CString & strHandle ) ;

	/**
	* @brief 复制属性的私有属性
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [4/19/2019]
	*/
	static BOOL CopyAttributePrivateComInfo( const CPrivateInfoMap & mapPrivateInfo , CPmDataBase::DataBaseName dataBaseName);

	/**
	* @brief 复制清单定额私有属性构件的信息/ 在数据库中生成新的记录
	*
	*          
	* @note  : 
	* @param : bPrivateAttrToOtherChapter :表示私有属性拷贝时，是否归属为其他章节。当工程导入时，如果清单定额库与目标工程的清单定额库不一致，则归属为其他章节
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : 2013年11月1日   8:30
	*/
	static BOOL CopyQDDEPrivateComInfo( const CPrivateInfoMap & mapPrivateInfo , CPmDataBase::DataBaseName dataBaseName,BOOL bPrivateAttrToOtherChapter);

	/**
	* @brief 复制实物量私有属性
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [4/19/2019]
	*/
	static BOOL CopySWLPrivateComInfo( const CPrivateInfoMap & mapPrivateInfo , CPmDataBase::DataBaseName dataBaseName);
};
