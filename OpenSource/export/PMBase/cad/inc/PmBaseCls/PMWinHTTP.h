// PMWinHTTP.h: interface for the CWinHTTP class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMWINHTTP_H__4EE5665B_6804_449C_9A6D_5D55A554B603__INCLUDED_)
#define AFX_PMWINHTTP_H__4EE5665B_6804_449C_9A6D_5D55A554B603__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include <winhttp.h>

enum GetDataFormat{gdtXML,gdtDT,gdtGet1Value}; //xml��ʽ������ָ����������ı��ļ���ʽ

//class PMBASECLASSAPI CPMWinHTTP  
//{
//public:
//
//	//���ļ����������ֵ�form�����ύ��������
//	BOOL PostMultipartDataToHTTP(CString &sResult,CString sURL,CStringArray &arrayNames,CStringArray &arrayValues,CString sFileName);
//
//	BOOL	GetDataFromHTTP(CString sURL,CString sSQL,BYTE *& pReBuffer,long & lReBufferSize);
//
//	BOOL    GetDataFromHTTP(CString &sResult,CString sURL,CString sSQL);
//	
//	BOOL    PostDataToHTTP(CString &sResult,CString sURL,CString sHeader,CString sData);
//
//	BOOL    PostDataToHTTP_Buffer(BYTE *& pBuffer,int & iBufferSize,CString sURL,CString sHeader,CString sData);
//
//	CPMWinHTTP();
//	virtual ~CPMWinHTTP();
//    CString GetWinHTTPLastError()
//	{
//		return m_sError;
//	}
//	void OnError(CString sError)
//	{
//		m_sError = sError;
//	}
//
//	static char * UnicodeToUTF8(const CString & strInfo) ; 
//protected:
//
//	void	ConvertUtf82T( const CString & strUtf8 , CString & strT ) ;
//	
//	CString GetCookie();
//	void SetCookie(CString sCookie);
//	//��ָ������ַ�������ݲ���ŵ�ָ�����ļ���
//	BOOL SaveFileMultipartDataFromHTTP(CString sURL,CString sSQL,CString sFileName);
//	
//	BOOL GetMultipartDataFromHTTP(CString sURL,CString sSQL, LPSTR *Buf, int *size);
//	BOOL File2Mem(LPBYTE *pMem, LPCTSTR filename, long *chars);
//	//ע�Ȿ���������ܹ�֧��2000���ϣ�����֧��win98
//	//BOOL    Unicode2UTF8(BSTR sUnitcode,CString &sUTF8);
//	//BOOL    UTF82ACP(CString &sUTF8, CString &sACP);
//	CString URLEncode(LPCTSTR lpszURL);
//	CString URLDecode(LPCTSTR lpszURL);	
//	
//	BOOL BuildMultipartDataContent(CStringArray &arrayNames,CStringArray &arrayValues,CString sFileName);
//	CString m_sError;
//
//	char *m_pMultipartDataContentBuff;
//	long m_iLength;
//	CString m_sboundary;
//	CString m_Cookies;
//};

#endif // !defined(AFX_WINHTTP_H__4EE5665B_6804_449C_9A6D_5D55A554B603__INCLUDED_)
