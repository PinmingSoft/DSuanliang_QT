

#pragma once 

/// 
/// ��� ˽�����Թ��ܺ�
/// �ֽ����ȡ������������Ҫ���ݾ������ȡ����
/// 

typedef std::map< CString , NDataModelDataSet * > CStr2DataSetMap ; 
typedef CStr2DataSetMap::iterator CStr2DataSetMapIter ; 
typedef CStr2DataSetMap::const_iterator CStr2DataSetMapConIter ; 


class PMProjectDBSERVICE CComParmOpr
{
private:
	CComParmOpr() ; 
public:
	~CComParmOpr() ; 
	static CComParmOpr & Instance() ;  

public:
	/// 
	void	Init() ; 

	/// 
	void	Release() ;
	
public:
	/// ���ص� DataSet ��Ҫɾ�� 
	BOOL GetComParm( const int iComId , NDataModelDataSet *& pComParm ) ;
	
	///
	BOOL GetComParm( const int iComId , const CString  & strHandle , NDataModelDataSet *& pComParm ) ; 

	/// 
	BOOL GetComAttribute( const int iComId, const CString & strHandle , const int iParmType,const CString & sAttributeKey,CString &sValue) ;

	/// 
	BOOL GetComAttribute( const int iComId , const CString & strHandle , const CString & sAttributeKey , CString &sValue ) ;

	/// 
	BOOL GetComAttributeInv( const int iComId , const CString & strHandle , const CString & sAttributeKey , CString &sInv ) ;

	/// 
	BOOL GetComAttribute( const int iComId , const int iParmType,const CString & sAttributeKey,CString &sValue);
	
	/// 
	BOOL GetComAttribute( const int iComId , const CString & sAttributeKey,CString &sValue);

public:
	/// 
	BOOL IsPrivate( const int iComId , const CString & strHandle ) ;

protected:

	/// ��ȡ��dataset ����Ҫɾ�� 
	NDataModelDataSet * GetComParmInner( const int iComId , const CString & strHandle ) ;

	/// 
	void	InitMap( const int iComId , const CString & strHandle ) ; 

public:
	int GetComDjxs( const int iComId ,  const CString & strHandle , const double & dDia , const BOOL bVertical = FALSE ) ; 
	int GetComDjxs( const int iComId ,  const CString & strHandle , const CString & strDia , const BOOL bVertical = FALSE ) ;


protected:

	/// 
	/// Ĭ�� comid Ҳ�ᱣ���� map �У���Ӧ�� handle Ϊ��
	/// 
	CStr2DataSetMap m_mapHandle2ComParm ; 

	/// 
	/// ��¼��˽�����Ե����� ��ͨ���������ݿ�ó� 
	/// 
	PmStrSet	m_setPrivateKey ; 
};


#define PmComParmOpr CComParmOpr::Instance() 