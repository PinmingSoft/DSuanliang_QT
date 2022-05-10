

#pragma once 

/**
 * @brief  ˽��������ر�Ĳ��� 
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  2013��11��8��   9:26
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
/// ˽�����Թ���������
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
	* @brief ����ʵ�������嵥����˽�����Թ�������Ϣ/ �����ݿ��������µļ�¼
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
	/// ��� CPrivateInfoMap �е�ָ��
	/// ���������ݿ�
	/// 
	static BOOL DelPrivateComInfo( const CPrivateInfoMap & mapPrivateInfo ) ;

private:
	static	void	ReplaceComIdHandle( CSQLDataSet * pDataSet , const int iComId , const CString & strHandle ) ;

	/**
	* @brief �������Ե�˽������
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
	* @brief �����嵥����˽�����Թ�������Ϣ/ �����ݿ��������µļ�¼
	*
	*          
	* @note  : 
	* @param : bPrivateAttrToOtherChapter :��ʾ˽�����Կ���ʱ���Ƿ����Ϊ�����½ڡ������̵���ʱ������嵥�������Ŀ�깤�̵��嵥����ⲻһ�£������Ϊ�����½�
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : 2013��11��1��   8:30
	*/
	static BOOL CopyQDDEPrivateComInfo( const CPrivateInfoMap & mapPrivateInfo , CPmDataBase::DataBaseName dataBaseName,BOOL bPrivateAttrToOtherChapter);

	/**
	* @brief ����ʵ����˽������
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
