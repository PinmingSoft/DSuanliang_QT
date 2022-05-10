//   HttpClient.h:   interface   for   the   CHttpClient   class.   
//   
//////////////////////////////////////////////////////////////////////   

#if   !defined(AFX_HTTPCLIENT_H__EA769DCB_AAB9_47CD_BD87_FBD6913592C5__INCLUDED_)   
#define   AFX_HTTPCLIENT_H__EA769DCB_AAB9_47CD_BD87_FBD6913592C5__INCLUDED_   

#if   _MSC_VER   >   1000   
#pragma   once   
#endif   //   _MSC_VER   >   1000   

class KERNELBASECLASS_API  CHttpClient       
{   
public:   
	void   addParam(CString   name,CString   value);   
//	BOOL   doPost(CString   href,CString & strResult); 
	void SetHttpAuth(const CString & strAuth);

	BOOL   doPost_NetRockey(BOOL bPost,CString   href,CString & strResult); 

	//UTF-8
	BOOL   doPost_NetRockey(BOOL bPost,CString   href,std::string & strResult); 
	void  SetBody(const CString & strBody);
	void SetBody(const std::string &strbody);
	
	CString   doGet(CString   href);   
	CHttpClient();   
	virtual   ~CHttpClient();   

private:
	CString		m_strAuth;
	CString   CONTENT;   
	int   CL;   
	CStringList   values;   
	CStringList   names;   
	std::string strcontent;
};   

#endif   //   !defined(AFX_HTTPCLIENT_H__EA769DCB_AAB9_47CD_BD87_FBD6913592C5__INCLUDED_)   
