
#pragma once 

/**
 * @brief ���ݿ⣬���������Ĵ���
 *		  һЩ�������������ϴ�ʱ�������ٶ�̫������ ͼֽ�ϵ�ɾ������������ɾ��������ʱ��̫��
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-9-21]
 * @note  ����ʹ�õ���
 */

/// ����int �� PmStrSet �� map 
typedef std::map< int , PmStrSet > PmInt2StrSetMap  ; 
typedef PmInt2StrSetMap::iterator	PmInt2StrSetMapIter ; 
typedef PmInt2StrSetMap::const_iterator PmInt2StrSetMapConIter ; 


/// 
class PMProjectDBSERVICE CPmDataBaseBatchOpr
{
private:
	CPmDataBaseBatchOpr() ; 

public:
	virtual ~CPmDataBaseBatchOpr();
	static CPmDataBaseBatchOpr & Instance() ; 

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// ����ͼֽ��ɾ������ʱ����Ӧɾ������������Ӧ
	/// 
	/// ������ǵ�ǰ¥��
public:

	/// 
	void	AddFloorIdHandle( const int iFloorId , const CString & strHandle ) ; 

	void	AddComIdHandle( const int iComId , const CString & strHandle ) ; 

	/// 
	void	Update() ; 


/**
 * @brief �������ݿ��ȡDATASET 
 * @author ������
 * @version v1.0
 * @date  [2019-11-6]
 * @note
 * @return �ɹ����� TRUE ʧ�ܷ���FALSE
 */
	BOOL	GetDataSetFromDb(const CString strTableName , CSQLDataSet & pDataSet);

private:
	void	Update( const int iFloorId , const PmStrSet & setHandle ) ;

	void	UpdateGraphicResult( const int iFloorId ,  const PmStrSet & setHandle ) ;

	void	UpdatePrivateParm( const int iFloorId , const PmStrSet & setHandle  ) ;

	void	UpdatePrivateQdde( const int iFloorId , const PmStrSet & setHandle ) ;

	/// ��㹹��
	void	UpdateKcEntity( const int iFloorId , const PmStrSet & setHandle ) ;

private:
	CString		FormatHandle( const int iHandleLow , const int iHandleHigh ) ;

private:

	/// 
	PmInt2StrSetMap  m_mapFloorId2HandleSet ; 

};



#define PmDbBatchOpr CPmDataBaseBatchOpr::Instance()