// PMWinHTTP.h: interface for the CWinHTTP class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMWINHTTP_H__4EE5665B_6804_449C_9A6D_5D55A554B603__INCLUDED_)
#define AFX_PMWINHTTP_H__4EE5665B_6804_449C_9A6D_5D55A554B603__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include <winhttp.h>
typedef void(*DownLoadCallback)(int ContentSize, int CUR_LEN);
enum GetDataFormat{gdtXML,gdtDT,gdtGet1Value}; //xml格式或者是指定定界符的文本文件格式

class KERNELBASECLASS_API CPMWinHTTP  
{
	typedef struct _URL_INFO
	{
		WCHAR szScheme[512];
		WCHAR szHostName[512];
		WCHAR szUserName[512];
		WCHAR szPassword[512];
		WCHAR szUrlPath[512];
		WCHAR szExtraInfo[512];
	}URL_INFO, *PURL_INFO;
public:

	//将文件和其他部分的form数据提交到服务器
	BOOL PostMultipartDataToHTTP(CString &sResult,CString sURL,CStringArray &arrayNames,CStringArray &arrayValues,CString sFileName,BOOL bTransUTF8 = FALSE);

	BOOL PostMultipartDataToHTTP(CString &sResult,CString sURL,CStringArray &arrayNames,CStringArray &arrayValues,CString sUploadName,CString sFileName,BOOL bTransUTF8 = FALSE);

	BOOL	GetDataFromHTTP(CString sURL,CString sSQL,BYTE *& pReBuffer,long & lReBufferSize);

	BOOL    GetDataFromHTTP(CString &sResult,CString sURL,CString sSQL,BOOL bTransUTF8 = TRUE);
	
	BOOL    PostDataToHTTP(CString &sResult,CString sURL,CString sHeader,CString sData,BOOL bTransUTF8 = FALSE);

	BOOL    PostDataToHTTP_Buffer(BYTE *& pBuffer,int & iBufferSize,CString sURL,CString sHeader,CString sData);

	//
	BOOL PostDataToHTTP(CString & sResult,CString sUrl,const CStringArray & strKeyArr,const CStringArray & strValueArr,const CUIntArray & bIsFileArr);

	BOOL PostYGJDataToHTTP(CString &sResult, CString sURL, CStringArray &arrayNames,CStringArray &arrayValues,CString sFileName);
	BOOL PostYGJImageToHTTP(CString &sResult, CString sURL, CStringArray &arrayNames,CStringArray &arrayValues,CString sFileName);

	BOOL DownloadFile(CString strUrl, CString strFileName, DownLoadCallback Func);

	CPMWinHTTP();
	virtual ~CPMWinHTTP();
    CString GetWinHTTPLastError()
	{
		return m_sError;
	}
	void OnError(CString sError)
	{
		m_sError = sError;
	}

	static char * UnicodeToUTF8(const CString & strInfo) ; 

	static void UTF82T( const CString & strUtf8 , CString & strT ) ;
protected:

	void	ConvertUtf82T( const CString & strUtf8 , CString & strT ) ;
	
	CString GetCookie();
	void SetCookie(CString sCookie);
	//从指定的网址检索数据并存放到指定的文件中
	BOOL SaveFileMultipartDataFromHTTP(CString sURL,CString sSQL,CString sFileName);
	
	BOOL GetMultipartDataFromHTTP(CString sURL,CString sSQL, LPSTR *Buf, int *size);
	BOOL File2Mem(LPBYTE *pMem, LPCTSTR filename, long *chars);
	//注意本函数仅仅能够支持2000以上，不能支持win98
	//BOOL    Unicode2UTF8(BSTR sUnitcode,CString &sUTF8);
	//BOOL    UTF82ACP(CString &sUTF8, CString &sACP);
	CString URLEncode(LPCTSTR lpszURL);
	CString URLDecode(LPCTSTR lpszURL);	


	BOOL BuildMultipartDataContent(CStringArray &arrayNames,CStringArray &arrayValues,CString sFileName);
	BOOL BuildMultipartDataContent(CStringArray &arrayNames,CStringArray &arrayValues,CString sUploadName,CString sFileName);
	BOOL BuildYGJDataContent(CStringArray &arrayNames,CStringArray &arrayValues,CString sFileName);
	
	CString m_sError;

	char *m_pMultipartDataContentBuff;
	//LPSTR pszOutBuffer;
	long m_iLength;
	CString m_sboundary;
	CString m_Cookies;
};

#endif // !defined(AFX_WINHTTP_H__4EE5665B_6804_449C_9A6D_5D55A554B603__INCLUDED_)
