// PmMfcFun.h: interface for the CPmMfcFun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMKERNELFUN_H__84F82B80_E1E4_4D99_A3A4_BACA67B99494__INCLUDED_)
#define AFX_PMKERNELFUN_H__84F82B80_E1E4_4D99_A3A4_BACA67B99494__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define PMCompareString(string1,string2)	(string1.GetLength() == string2.GetLength() && string1 == string2)

#ifdef _UNICODE
typedef std::wstring pmstring;
#else
typedef std::string pmstring;
#endif // _UNICODE

class KERNELBASECLASS_API CPM_CRITICAL_SECTION
{
public:
	CPM_CRITICAL_SECTION(CRITICAL_SECTION * pSection);
	virtual ~CPM_CRITICAL_SECTION(void);

	void PMEnterCriticalSection();

	void PMLeaveCriticalSection();

protected:

	CRITICAL_SECTION * m_pSection;
};

namespace PmKernel
{
	namespace Fun
	{
		class KERNELBASECLASS_API Mfc_ResourceOverride
		{
		public:
			Mfc_ResourceOverride(HINSTANCE _dllhInstance)
			{
				m_OldInstance = AfxGetResourceHandle();
				AfxSetResourceHandle(_dllhInstance); 
			}
			~Mfc_ResourceOverride()
			{
				AfxSetResourceHandle(m_OldInstance); 
			}
		protected:
			HINSTANCE m_OldInstance;
		};

		enum
		{
			eEncoding_UnKnown ,
			eEncoding_ASCII ,
			eEncoding_UTF8 ,
			eEnCoding_UNICODE 
		};

		/****************************************************************
		  功能描述： 检查Double值是否合法
			参数：
			返 回 值：
			算法：
			注意事项：
			作    者：王建业
			时    间：[2011:8:12   13:38]
		*****************************************************************/
		KERNELBASECLASS_API BOOL CheckDoubleIsNormal(double dValue);

		/****************************************************************
		  功能描述：获取操作系统版本
			参数：
			返 回 值：
			算法：
			注意事项：
			作    者：王建业
			时    间：[2011:4:20   15:40]
		*****************************************************************/
		KERNELBASECLASS_API BOOL GetWindowsSystemVersion(CString & strWindowsSysVer);

		/****************************************************************
		  功能描述：判断是否是 早期的 操作系统
			参数：
			返 回 值：
			算法：
			注意事项：
			作    者：王建业
			时    间：[2011:4:20   15:40]
		*****************************************************************/
		KERNELBASECLASS_API BOOL CheckIsOldSystemVersion();

		/******************************************************************** 
		功能描述：将Acsii字符串 转为Unicode字符串
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2010:10:21]   11:58
		*********************************************************************/ 
		KERNELBASECLASS_API LPWSTR PM_A2W(LPCSTR pAInfo);

		/******************************************************************** 
		功能描述：将Unicode字符串 转为Acsii字符串
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2010:10:21]   11:58
		*********************************************************************/ 
		KERNELBASECLASS_API LPSTR PM_W2A(LPCWSTR pWInfo);

		/******************************************************************** 
		功能描述：将可能是Unicode或Acsii字符串 转为Unicode字符串
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPWSTR PM_T2W(LPCTSTR pTInfo);

		/******************************************************************** 
		功能描述：将可能是Unicode或Acsii字符串 转为Acsii字符串
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPSTR PM_T2A(LPCTSTR pTInfo);

		/******************************************************************** 
		功能描述：将Acsii字符串 根据环境转为 可能是Unicode或Acsii字符串
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPTSTR PM_A2T(LPCSTR pAInfo);

		/******************************************************************** 
		功能描述：将Unicode字符串 根据环境转为 可能是Unicode或Acsii字符串
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPTSTR PM_W2T(LPCWSTR pWInfo);

		/******************************************************************** 
		功能描述：将Acsii字符串 转化为Utf8字符串
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPSTR PM_A2UTF8(LPCSTR pAInfo);

		/******************************************************************** 
		功能描述：将Unicode字符串 转化为Utf8字符串
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPSTR PM_W2UTF8(const LPCWSTR pWInfo);

		/******************************************************************** 
		功能描述：将Utf8字符串 转化为Acsii字符串
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPSTR PM_UTF82A(LPCSTR pUInfo);


		/******************************************************************** 
		功能描述：将Utf8字符串 转化为Unicode字符串
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPWSTR PM_UTF82W(const LPCSTR pUInfo);

		/******************************************************************** 
		功能描述：比较字符串
		参数：
		返 回 值：
		算法：
		注意事项：如果允许的话，尽量使用PMCompareString宏的版本
		作    者：王建业
		时    间：[2010:9:25]   16:47
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL PMCompareStringFun(const CString & strString1,const CString & strString2);

		/******************************************************************** 
		 功能描述：将字符串数据保存到剪切板中
		 参数：
		 返 回 值：
		 算法：
		 注意事项：
		 作    者：王建业
		 时    间：[29/7/2010]
		*********************************************************************/ 
		KERNELBASECLASS_API void ClipboardSave(HWND hwnd,CString &text);

		/******************************************************************** 
		 功能描述：将剪切板数据以字符串读出
		 参数：
		 返 回 值：
		 算法：
		 注意事项：
		 作    者：王建业
		 时    间：[29/7/2010]
		*********************************************************************/ 
		KERNELBASECLASS_API void ClipboardLoad(HWND hwnd,CString &text);

		/******************************************************************** 
		 功能描述：从CDC中 运算 字符串 绘制在屏幕中的宽度、高度
		 参数：
		 返 回 值：
		 算法：
		 注意事项：
		 作    者：王建业
		 时    间：[22/7/2010]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL GetStringWith_Height(CDC * pDC,const CString & strInfo,int & iWidth,int & iHeight);

		/******************************************************************** 
		 功能描述：将字符串压入指定文件中
		 参数：
		 返 回 值：
		 算法：
		 注意事项：
		 作    者：王建业
		 时    间：[28/4/2010]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL AppendCString2File(const CString & strFilePath,const CString & strAppendInfo);
		
		/******************************************************************** 
		 功能描述：	比对浮点数
		 参数：const double src1,const double src2,const double dMinValue：公差值
		 返 回 值：
		 算法：
		 注意事项：0:相等 -1：小于 1：大于
		 作    者：王建业
		 时    间：[21/9/2009]
		*********************************************************************/ 
		KERNELBASECLASS_API int CompareDbl(const double src1,const double src2,const double dMinValue);

		/******************************************************************** 
		 功能描述：根据delim拆分字符串strValue，装入aryStr，返回真假
		 参数：
		 返 回 值：
		 算法：
		 注意事项：
		 作    者：王建业
		 时    间：[9/4/2009]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL Split(const CString &strValue,const CString &delim, CStringArray & aryStr);
		KERNELBASECLASS_API BOOL Split(const CString &strValue,const CString &delim, std::vector<CString>& aryStr);

		// 字符串切割 到 Vector中
		KERNELBASECLASS_API bool stringSplit2Vector(const std::string& s, const std::string& delim, std::vector<std::string> & stringList);

		/******************************************************************** 
		功能描述：将char转换为Hex
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[17/11/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API int CharToHex(TCHAR c);

		/******************************************************************** 
		功能描述：将CString转换为Hex
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[17/11/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API DWORD CStringToHex(const CString & strValue);

		/******************************************************************** 
		功能描述：读取文件 
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[28/11/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL File2CString(const CString & filename,CString& buf);

		bool isutf8(CHAR *str) ;

		/// 支持更多的格式，
		KERNELBASECLASS_API BOOL File2CStringMore(const CString & filename,CString& buf);

		//分割 文件的 目录
		KERNELBASECLASS_API CString SplitFileDir(const CString & strFilePath);

		//分割 文件的 名称
		KERNELBASECLASS_API CString SplitFileName(const CString & strFilePath);

		//分割 文件的 扩展名
		KERNELBASECLASS_API CString SplitFileExt(const CString & strFilePath);

		/******************************************************************** 
		功能描述：获取程序路径
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[18/10/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API CString GetAppPath();

		/// 返回路径 E:\source\export\ddll
		KERNELBASECLASS_API CString	GetAppPath_v2() ; 

		/**
		* @brief   扫描一个文件夹 获取一种文件类型的 所有文件名,带扩展名的。
		*
		*          
		* @note  : strFolderPath：可以带过滤，如：_T("C:\\工程模板库\\*.pmcd");\n
		*			strFileArray:中的文件名称，带扩展名
		* @param : const CString & strFolderPath:要扫描的文件夹路径\n
		*			CStringArray &strFileArray:返回文件夹中的文件名称
		* @defenc: 
		* @return: TRUE:执行成功\n
		*			FALSE:执行失败
		* @author: 王建业
		* @date  : [15/9/2011]
		*/
		KERNELBASECLASS_API BOOL ScanFolder_HasExtendName(const CString & strFolderPath, CStringArray &strFileArray);

		/**
		* @brief   扫描一个文件夹 获取一种文件类型的 所有文件名,不带扩展名。
		*
		*          
		* @note  : strFolderPath：可以带过滤，如：_T("C:\\工程模板库\\*.pmcd");\n
		*			strFileArray:中的文件名称，不带扩展名
		* @param : const CString & strFolderPath:要扫描的文件夹路径\n
		*			CStringArray &strFileArray:返回文件夹中的文件名称
		* @defenc: 
		* @return: TRUE:执行成功\n
		*			FALSE:执行失败
		* @author: 王建业
		* @date  : [15/9/2011]
		*/
		KERNELBASECLASS_API BOOL ScanFolder_NoExtendName(const CString & strFolderPath, CStringArray &strFileArray);

		//拆分字符串
		KERNELBASECLASS_API void SplitCString(const CString & source, CStringArray& dest, TCHAR division);
		KERNELBASECLASS_API void SplitCString(const CString & source, CStringArray& dest, const CString & strDivision);

		KERNELBASECLASS_API void SplitCString(const CString & source, std::vector<pmstring>& dest, TCHAR division);
		KERNELBASECLASS_API void SplitCString(const CString & source, std::vector<pmstring>& dest, const CString & strDivision);

		//保存零时文件
		KERNELBASECLASS_API BOOL SaveFileContent(const CString & fileName,const CString & content);

		/******************************************************************** 
		功能描述：重命名文件
		参数：strFromFileName：原文件地址 strToFileName：目标地址 iMode:复制模式
		返 回 值：是否成功
		算法：
		注意事项：iMode:0：重名时，覆盖 1 重名时，不覆盖  2：重名时，生成新的文件名
		作    者：王建业
		时    间：[18/3/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL RenameFile(const CString & strOldFileName,CString & strNewFileName,int iMode);

		//检查文件状态
		KERNELBASECLASS_API BOOL CheckFile(const CString & strFileName);

		/******************************************************************** 
		功能描述：复制文件
		参数：strFromFileName：原文件地址 strToFileName：目标地址 iMode:复制模式
		返 回 值：是否成功
		算法：
		注意事项：iMode:0：重名时，覆盖 1 重名时，不复制  2：重名时，生成新的文件名
		作    者：王建业
		时    间：[18/3/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL CopySimFile(const CString & strFromFileName,CString & strToFileName,int iMode);

		/******************************************************************** 
		功能描述：进行文件夹的拷贝 目标文件夹不存在时创建文件夹
		参数：strFromFolder：源文件夹 strToFolder：目标文件夹
		返 回 值：
		算法：
		注意事项：iMode:0：重名时，覆盖 1 重名时，不复制  2：重名时，生成新的文件名
		作    者：王建业
		时    间：[8/4/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL CopyFolder(const CString & strFromFolder,const CString & strToFolder,int iMode);

		/******************************************************************** 
		功能描述：double To CString 忽略小数后的0
		参数：dValue：转换值 iprecision:保留精度 
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[14/4/2008]
		*********************************************************************/
		KERNELBASECLASS_API CString DoubleToString(double dValue,int iprecision);

		/******************************************************************** 
		功能描述：读取指定的路径的.Ini文件
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[17/4/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL ReadIniFileInfo(const CString & strAppName,const CString & strKeyName, CString &strKeyValue,const CString & strFilePath);
		KERNELBASECLASS_API BOOL ReadIniFileInfo(const CString & strAppName,const CString & strKeyName, CString &strKeyValue,const CString & strFilePath,int filesize);

		/******************************************************************** 
		功能描述：写入指定的路径的.Ini文件
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[17/4/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL WriteIniFileInfo(const CString & strAppName,const CString & strKeyName,const CString & strKeyValue,const CString & strFilePath);

		KERNELBASECLASS_API CString GetSysDataPath(HINSTANCE _hdllInstance);
		KERNELBASECLASS_API CString GetAppPath(HINSTANCE _hdllInstance);
		KERNELBASECLASS_API CString GetFilePath(HINSTANCE _hdllInstance);
		KERNELBASECLASS_API CString GetSysDataPath();
		KERNELBASECLASS_API CString GetFilePath();
		KERNELBASECLASS_API CString GetSoft_SysDataPath();

		KERNELBASECLASS_API BOOL DownLoadFile(const CString & strUrl,const CString & strFilePath);

		//判断 进程id 是否存在
		KERNELBASECLASS_API BOOL CheckProcessRunMode(DWORD dwProcessId);

		//GZIP压缩
		/* data 原数据 ndata 原数据长度 zdata 压缩后数据 nzdata 压缩后长度 */
		KERNELBASECLASS_API int gzcompress(unsigned char *data, unsigned long ndata,unsigned char *zdata, unsigned long *nzdata);

		//GZIP解压
		/* zdata 数据 nzdata 原数据长度 data 解压后数据 ndata 解压后长度 */
		KERNELBASECLASS_API int gzdecompress(unsigned char *zdata, unsigned long nzdata,unsigned char *data, unsigned long *ndata);

		/******************************************************************** 
		功能描述：创建系统信息文件
		参数：    要保存的文件路径
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[17/4/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL CreateSystemInfoFile(const CString & strFilePath,const CString & strSoftVer);

		// 获取 硬盘信息
		KERNELBASECLASS_API BOOL GetHardDiskInfo(LONGLONG & fAllSize,LONGLONG & fFreeSize);

		// 打印信息
		KERNELBASECLASS_API BOOL CreateInfoFile_WriteInfo(CFile * pFile,CString strInfo);

		// 打印分割线
		KERNELBASECLASS_API BOOL CreateInfoFile_SplitInfo(CFile * pFile);

		// 打印空行
		KERNELBASECLASS_API BOOL CreateInfoFile_EmptyLine(CFile * pFile);

		///注释：杨兴耀 [2009年12月24日]                                  
		///判断　value　是否在　arr　中
		///不推荐用 该函数 可以用 
		/// PmCommonFun.h  中的 Find 函数 代替
		template <typename type_value, typename TArray> 
		BOOL IsContain(type_value value, TArray &arr) 
		{
			for (int i = 0 ; i < arr.GetSize(); i ++)
			{
				type_value tem = arr.GetAt(i);
				if ( tem == value )
				{
					return TRUE ;
				}
			}
			return FALSE ;
		}

	}
}


/****************************************************************
功能描述：做为 内存 缓存的 基础 接口
参数：
返 回 值：
算法：在 需要的时候 可以 被 管理类 释放 指定 级别的 内存
级别 越高 对 内存 压力 越大。
注意事项：
作    者：王建业
时    间：[2011:3:25   17:47]
*****************************************************************/
class KERNELBASECLASS_API CPMMemoryCache
{
public:

	enum CacheMode
	{
		LowLevel = 1,//低等级
		NormalLevel = 2,//普通级别
		HighLevel = 3,//高级别
		VeryHighLevel = 4//严重
	};

	CPMMemoryCache();
	virtual ~CPMMemoryCache();

	/****************************************************************
	功能描述：获取 缓存的 等级
	参数：
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[2011:3:25   18:09]
	*****************************************************************/
	CPMMemoryCache::CacheMode GetMemoryCacheMode();

	/****************************************************************
	功能描述：用于释放 内存 缓冲
	参数：
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[2011:3:25   17:47]
	*****************************************************************/
	virtual int ReleaseCache() = 0;

protected:

	CacheMode m_PMMemoryCacheMode;//内存缓存的 级别
};


class KERNELBASECLASS_API CCallBackFun_Interface
{
public:
	CCallBackFun_Interface(){}
	virtual ~CCallBackFun_Interface(){}

	//typedef int (*gzcompress_CallBack)(unsigned char *data, unsigned long ndata,unsigned char *zdata, unsigned long *nzdata);
	//static void RegGZCompressFun(gzcompress_CallBack pCallBack);
	//static void UnRegGZCompressFun();

	//GZIP压缩
	/* data 原数据 ndata 原数据长度 zdata 压缩后数据 nzdata 压缩后长度 */
	static int DoGZcompress(unsigned char *data, unsigned long ndata,unsigned char *zdata, unsigned long *nzdata);

	//GZIP解压
	/* zdata 数据 nzdata 原数据长度 data 解压后数据 ndata 解压后长度 */
//	PMBASECLASSAPI int gzdecompress(unsigned char *zdata, unsigned long nzdata,unsigned char *data, unsigned long *ndata);

protected:
	//static gzcompress_CallBack s_pGZCompressCallBack;
};


class KERNELBASECLASS_API CPMMemoryCacheManager
{
public:
	static CPMMemoryCacheManager * Instance()
	{
		if(NULL == m_pInstance)
		{
			m_pInstance = new CPMMemoryCacheManager;	
		}
		return m_pInstance;
	}

	static void Release()
	{
		if(NULL != m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}

	/****************************************************************
	功能描述：加入内存管理 
	参数：
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[2011:3:25   18:00]
	*****************************************************************/
	BOOL AddMemoryCache(CPMMemoryCache * pMemoryCache);

	/****************************************************************
	功能描述：从管理类 中移出 缓存指针
	参数：
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[2011:3:25   18:00]
	*****************************************************************/
	BOOL RemoveMemoryCache(CPMMemoryCache * pMemoryCache);

	/****************************************************************
	功能描述：根据内存 使用 情况 释放 缓存
	参数：
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[2011:3:25   18:02]
	*****************************************************************/
	BOOL ClearUpMemoryCache();

	void ClearLevelMemoryCache(CPMMemoryCache::CacheMode memoryCacheMode);

private:

	CPMMemoryCacheManager();
	virtual ~CPMMemoryCacheManager();

	CArray<CPMMemoryCache*,CPMMemoryCache*&> m_PMMemoryCacheArr;
	static CPMMemoryCacheManager * m_pInstance;
};

#endif // !defined(AFX_PMKERNELFUN_H__84F82B80_E1E4_4D99_A3A4_BACA67B99494__INCLUDED_)
