

#pragma once 

/// 
/// 添加 私有属性功能后
/// 钢筋计算取构件参数，需要根据具体情况取参数
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
	/// 返回的 DataSet 需要删除 
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

	/// 获取的dataset 不需要删除 
	NDataModelDataSet * GetComParmInner( const int iComId , const CString & strHandle ) ;

	/// 
	void	InitMap( const int iComId , const CString & strHandle ) ; 

public:
	int GetComDjxs( const int iComId ,  const CString & strHandle , const double & dDia , const BOOL bVertical = FALSE ) ; 
	int GetComDjxs( const int iComId ,  const CString & strHandle , const CString & strDia , const BOOL bVertical = FALSE ) ;


protected:

	/// 
	/// 默认 comid 也会保留在 map 中，对应的 handle 为空
	/// 
	CStr2DataSetMap m_mapHandle2ComParm ; 

	/// 
	/// 记录有私有属性的主键 ，通过搜索数据库得出 
	/// 
	PmStrSet	m_setPrivateKey ; 
};


#define PmComParmOpr CComParmOpr::Instance() 