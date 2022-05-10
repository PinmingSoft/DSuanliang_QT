#pragma   once 

class KERNELBASECLASS_API CHttpFun
{
public:
	CHttpFun();
    
	~CHttpFun();

	// 文件下载接口
	static int download_file(const char* url, const char outfilename[FILENAME_MAX]);
	// http get 请求
	static int HttpGet(const std::string & strUrl, std::string & strResponse,int nTimeout);

	static int HttpGet(const std::string & strUrl, const std::string & strHeader, std::string & strResponse,int nTimeout);

	static int HttpGet(const CString & strUrl, const CString & strHeader, CString & strResponse,int nTimeout);

	// htpp post 请求
	static int HttpPostJson(const std::string & strUrl, std::string szJson,std::string & strResponse,int nTimeout);

	static int HttpPostParam(const std::string & strUrl,const std::string & strHeader,const std::string & szParam,std::string & strResponse,int nTimeout);
	static int HttpPostParam(const CString & strUrl,const CString & strHeader,const CString & strParam,CString & strResult,int nTimeout);

	static int TestHttp();

protected:

	static int download_fileFun(const char* url, const char outfilename[FILENAME_MAX]);

	static int receive_data(void *contents, int size, int nmemb, void *stream);
       
	// HTTP 下载文件的回掉函数
	static int writedata2file(void *ptr, int size, int nmemb, FILE *stream);    
};

class KERNELBASECLASS_API CExtensionKitFun
{
public:
	// 发送Http请求  Res加密
	static int PMWebEncode(byte * pMingWenInfo,int iMingWenSize,byte * pMiWenInfo,int & iMiWenSize);

	// 发送Http请求  Res解密
	static int PMWebDecode(byte * pMiWenInfo,int iMiWenSize,byte * pMingWenInfo,int & iMingWenSize);
};
