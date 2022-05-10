// XMLResolvAdapter.h: interface for the CXMLResolvAdapter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMLRESOLVADAPTER_H__00FF838E_7C2F_47C8_9950_7F177FE81542__INCLUDED_)
#define AFX_XMLRESOLVADAPTER_H__00FF838E_7C2F_47C8_9950_7F177FE81542__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PMBASECLASSAPI CXMLResolvAdapter
{
public:
	CXMLResolvAdapter();
	virtual ~CXMLResolvAdapter();

private:
	LPVOID m_pXMLAnaly;

public:
	BOOL LoadXML( const CString & strXmlFile );

	BOOL LoadXmlContent( const CString & strXmlContent ) ; 

	/// 
	BOOL MoveToFirstChild() ;   /// 跳到下一级节点

	BOOL MoveToParentNode() ;	/// 调到父节点

	/// 
	BOOL MoveToPrevSiblingNode();		/// 前面一个兄弟节点

	BOOL MoveToNextSiblingNode();		/// 调到兄弟节点


	BOOL GetNodeAttri(const CString & strNodeName, CString & strNodeValue);

	BOOL GetNodeName( CString & strNodeName ) ; 
};

class PMBASECLASSAPI CPmXmlNode
{
public:
	CPmXmlNode() ;
	~CPmXmlNode() ; 

public:
	/// 
	void	SetData( const LPVOID pNodeData ) ; 
	LPVOID	GetData( ) const ;

//	void	ReleaseData() ; 
private:
	LPVOID m_pNodeData ; 
};

/// 对CPmXmlNodeListWrapper的一个封装
class PMBASECLASSAPI CPmXmlNodeList 
{
public:
	CPmXmlNodeList() ; 
	~CPmXmlNodeList() ;

public:
	void Start();  
	LPVOID Next();  
	BOOL IsValid();  
	int Count() const ;  

	CPmXmlNode GetAt( const int iIndex ) ;

public:
	/// 
	void	SetData( const LPVOID pData ) ; 

	LPVOID	GetData() const ; 


protected:
		
	LPVOID	m_pListData ;

	LPVOID	m_pNodeData ;
};

/// 指针的 list 
typedef std::vector<LPVOID> LpvoidList ; 

class PMBASECLASSAPI CPmXmlParserOpr
{
public:
	CPmXmlParserOpr() ; 
	~CPmXmlParserOpr() ;

public:
	static void	Start() ;

	static void	Release() ; 

public:

	static BOOL	LoadFile( const CString & strXmlFile , CPmXmlNode & rootNode ) ; 

	static BOOL	LoadContent( const CString & strContent , CPmXmlNode & rootNode  ) ; 


	/// node 
public:

	/// 
	static BOOL		GetNode( const CPmXmlNode & curNode , const CString & strNodeName , CPmXmlNodeList & listNode ) ;

	/// 获取属性
	static BOOL		GetNodeAttri( const CPmXmlNode & curNode , const CString & strAttrName, CString & strNodeValue);

	/// 
	/// 跳到下一级节点
	BOOL		MoveToFirstChild( const CPmXmlNode & curNode , const CString & strNodeName , CPmXmlNode & fistChildNode ) ;  

	/// 
	BOOL		MoveToFirstChild( const CPmXmlNode & curNode , CPmXmlNode  & fistChildNode ) ;  

	/// 跳到父节点
	BOOL		MoveToParentNode( const CPmXmlNode & curNode , CPmXmlNode & parentNode ) ;	

	/// 前面一个兄弟节点
	BOOL		MoveToPrevSiblingNode( const CPmXmlNode & curNode , CPmXmlNode & prevSiblingNode  );		

	/// 后面一个兄弟节点
	BOOL		MoveToNextSiblingNode(const CPmXmlNode & curNode , CPmXmlNode & nextSiblingNode  );		

	/// 获取NodeName 
	BOOL		GetNodeName( const CPmXmlNode & curNode , CString & strNodeName ) ;


	/// list + index 
public:
	/// 
	static BOOL		GetNode( const CPmXmlNodeList & listSrcNode , const int iIndex ,  const CString & strNodeName , CPmXmlNodeList & listDesNode ) ; 

	/// 
	static BOOL		GetNodeAttri( const CPmXmlNodeList & listNode , const int iIndex , const CString & strAttrName, CString & strNodeValue);


private:
	static	LPVOID m_pXmlParser  ; 

};


#endif // !defined(AFX_XMLRESOLVADAPTER_H__00FF838E_7C2F_47C8_9950_7F177FE81542__INCLUDED_)
