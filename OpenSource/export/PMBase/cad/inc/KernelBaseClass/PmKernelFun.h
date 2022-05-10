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
		  ���������� ���Doubleֵ�Ƿ�Ϸ�
			������
			�� �� ֵ��
			�㷨��
			ע�����
			��    �ߣ�����ҵ
			ʱ    �䣺[2011:8:12   13:38]
		*****************************************************************/
		KERNELBASECLASS_API BOOL CheckDoubleIsNormal(double dValue);

		/****************************************************************
		  ������������ȡ����ϵͳ�汾
			������
			�� �� ֵ��
			�㷨��
			ע�����
			��    �ߣ�����ҵ
			ʱ    �䣺[2011:4:20   15:40]
		*****************************************************************/
		KERNELBASECLASS_API BOOL GetWindowsSystemVersion(CString & strWindowsSysVer);

		/****************************************************************
		  �����������ж��Ƿ��� ���ڵ� ����ϵͳ
			������
			�� �� ֵ��
			�㷨��
			ע�����
			��    �ߣ�����ҵ
			ʱ    �䣺[2011:4:20   15:40]
		*****************************************************************/
		KERNELBASECLASS_API BOOL CheckIsOldSystemVersion();

		/******************************************************************** 
		������������Acsii�ַ��� תΪUnicode�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:58
		*********************************************************************/ 
		KERNELBASECLASS_API LPWSTR PM_A2W(LPCSTR pAInfo);

		/******************************************************************** 
		������������Unicode�ַ��� תΪAcsii�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:58
		*********************************************************************/ 
		KERNELBASECLASS_API LPSTR PM_W2A(LPCWSTR pWInfo);

		/******************************************************************** 
		������������������Unicode��Acsii�ַ��� תΪUnicode�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPWSTR PM_T2W(LPCTSTR pTInfo);

		/******************************************************************** 
		������������������Unicode��Acsii�ַ��� תΪAcsii�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPSTR PM_T2A(LPCTSTR pTInfo);

		/******************************************************************** 
		������������Acsii�ַ��� ���ݻ���תΪ ������Unicode��Acsii�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPTSTR PM_A2T(LPCSTR pAInfo);

		/******************************************************************** 
		������������Unicode�ַ��� ���ݻ���תΪ ������Unicode��Acsii�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPTSTR PM_W2T(LPCWSTR pWInfo);

		/******************************************************************** 
		������������Acsii�ַ��� ת��ΪUtf8�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPSTR PM_A2UTF8(LPCSTR pAInfo);

		/******************************************************************** 
		������������Unicode�ַ��� ת��ΪUtf8�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPSTR PM_W2UTF8(const LPCWSTR pWInfo);

		/******************************************************************** 
		������������Utf8�ַ��� ת��ΪAcsii�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPSTR PM_UTF82A(LPCSTR pUInfo);


		/******************************************************************** 
		������������Utf8�ַ��� ת��ΪUnicode�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:03
		*********************************************************************/ 
		KERNELBASECLASS_API LPWSTR PM_UTF82W(const LPCSTR pUInfo);

		/******************************************************************** 
		�����������Ƚ��ַ���
		������
		�� �� ֵ��
		�㷨��
		ע������������Ļ�������ʹ��PMCompareString��İ汾
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:9:25]   16:47
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL PMCompareStringFun(const CString & strString1,const CString & strString2);

		/******************************************************************** 
		 �������������ַ������ݱ��浽���а���
		 ������
		 �� �� ֵ��
		 �㷨��
		 ע�����
		 ��    �ߣ�����ҵ
		 ʱ    �䣺[29/7/2010]
		*********************************************************************/ 
		KERNELBASECLASS_API void ClipboardSave(HWND hwnd,CString &text);

		/******************************************************************** 
		 ���������������а��������ַ�������
		 ������
		 �� �� ֵ��
		 �㷨��
		 ע�����
		 ��    �ߣ�����ҵ
		 ʱ    �䣺[29/7/2010]
		*********************************************************************/ 
		KERNELBASECLASS_API void ClipboardLoad(HWND hwnd,CString &text);

		/******************************************************************** 
		 ������������CDC�� ���� �ַ��� ��������Ļ�еĿ�ȡ��߶�
		 ������
		 �� �� ֵ��
		 �㷨��
		 ע�����
		 ��    �ߣ�����ҵ
		 ʱ    �䣺[22/7/2010]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL GetStringWith_Height(CDC * pDC,const CString & strInfo,int & iWidth,int & iHeight);

		/******************************************************************** 
		 �������������ַ���ѹ��ָ���ļ���
		 ������
		 �� �� ֵ��
		 �㷨��
		 ע�����
		 ��    �ߣ�����ҵ
		 ʱ    �䣺[28/4/2010]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL AppendCString2File(const CString & strFilePath,const CString & strAppendInfo);
		
		/******************************************************************** 
		 ����������	�ȶԸ�����
		 ������const double src1,const double src2,const double dMinValue������ֵ
		 �� �� ֵ��
		 �㷨��
		 ע�����0:��� -1��С�� 1������
		 ��    �ߣ�����ҵ
		 ʱ    �䣺[21/9/2009]
		*********************************************************************/ 
		KERNELBASECLASS_API int CompareDbl(const double src1,const double src2,const double dMinValue);

		/******************************************************************** 
		 ��������������delim����ַ���strValue��װ��aryStr���������
		 ������
		 �� �� ֵ��
		 �㷨��
		 ע�����
		 ��    �ߣ�����ҵ
		 ʱ    �䣺[9/4/2009]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL Split(const CString &strValue,const CString &delim, CStringArray & aryStr);
		KERNELBASECLASS_API BOOL Split(const CString &strValue,const CString &delim, std::vector<CString>& aryStr);

		// �ַ����и� �� Vector��
		KERNELBASECLASS_API bool stringSplit2Vector(const std::string& s, const std::string& delim, std::vector<std::string> & stringList);

		/******************************************************************** 
		������������charת��ΪHex
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[17/11/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API int CharToHex(TCHAR c);

		/******************************************************************** 
		������������CStringת��ΪHex
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[17/11/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API DWORD CStringToHex(const CString & strValue);

		/******************************************************************** 
		������������ȡ�ļ� 
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[28/11/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL File2CString(const CString & filename,CString& buf);

		bool isutf8(CHAR *str) ;

		/// ֧�ָ���ĸ�ʽ��
		KERNELBASECLASS_API BOOL File2CStringMore(const CString & filename,CString& buf);

		//�ָ� �ļ��� Ŀ¼
		KERNELBASECLASS_API CString SplitFileDir(const CString & strFilePath);

		//�ָ� �ļ��� ����
		KERNELBASECLASS_API CString SplitFileName(const CString & strFilePath);

		//�ָ� �ļ��� ��չ��
		KERNELBASECLASS_API CString SplitFileExt(const CString & strFilePath);

		/******************************************************************** 
		������������ȡ����·��
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[18/10/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API CString GetAppPath();

		/// ����·�� E:\source\export\ddll
		KERNELBASECLASS_API CString	GetAppPath_v2() ; 

		/**
		* @brief   ɨ��һ���ļ��� ��ȡһ���ļ����͵� �����ļ���,����չ���ġ�
		*
		*          
		* @note  : strFolderPath�����Դ����ˣ��磺_T("C:\\����ģ���\\*.pmcd");\n
		*			strFileArray:�е��ļ����ƣ�����չ��
		* @param : const CString & strFolderPath:Ҫɨ����ļ���·��\n
		*			CStringArray &strFileArray:�����ļ����е��ļ�����
		* @defenc: 
		* @return: TRUE:ִ�гɹ�\n
		*			FALSE:ִ��ʧ��
		* @author: ����ҵ
		* @date  : [15/9/2011]
		*/
		KERNELBASECLASS_API BOOL ScanFolder_HasExtendName(const CString & strFolderPath, CStringArray &strFileArray);

		/**
		* @brief   ɨ��һ���ļ��� ��ȡһ���ļ����͵� �����ļ���,������չ����
		*
		*          
		* @note  : strFolderPath�����Դ����ˣ��磺_T("C:\\����ģ���\\*.pmcd");\n
		*			strFileArray:�е��ļ����ƣ�������չ��
		* @param : const CString & strFolderPath:Ҫɨ����ļ���·��\n
		*			CStringArray &strFileArray:�����ļ����е��ļ�����
		* @defenc: 
		* @return: TRUE:ִ�гɹ�\n
		*			FALSE:ִ��ʧ��
		* @author: ����ҵ
		* @date  : [15/9/2011]
		*/
		KERNELBASECLASS_API BOOL ScanFolder_NoExtendName(const CString & strFolderPath, CStringArray &strFileArray);

		//����ַ���
		KERNELBASECLASS_API void SplitCString(const CString & source, CStringArray& dest, TCHAR division);
		KERNELBASECLASS_API void SplitCString(const CString & source, CStringArray& dest, const CString & strDivision);

		KERNELBASECLASS_API void SplitCString(const CString & source, std::vector<pmstring>& dest, TCHAR division);
		KERNELBASECLASS_API void SplitCString(const CString & source, std::vector<pmstring>& dest, const CString & strDivision);

		//������ʱ�ļ�
		KERNELBASECLASS_API BOOL SaveFileContent(const CString & fileName,const CString & content);

		/******************************************************************** 
		�����������������ļ�
		������strFromFileName��ԭ�ļ���ַ strToFileName��Ŀ���ַ iMode:����ģʽ
		�� �� ֵ���Ƿ�ɹ�
		�㷨��
		ע�����iMode:0������ʱ������ 1 ����ʱ��������  2������ʱ�������µ��ļ���
		��    �ߣ�����ҵ
		ʱ    �䣺[18/3/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL RenameFile(const CString & strOldFileName,CString & strNewFileName,int iMode);

		//����ļ�״̬
		KERNELBASECLASS_API BOOL CheckFile(const CString & strFileName);

		/******************************************************************** 
		���������������ļ�
		������strFromFileName��ԭ�ļ���ַ strToFileName��Ŀ���ַ iMode:����ģʽ
		�� �� ֵ���Ƿ�ɹ�
		�㷨��
		ע�����iMode:0������ʱ������ 1 ����ʱ��������  2������ʱ�������µ��ļ���
		��    �ߣ�����ҵ
		ʱ    �䣺[18/3/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL CopySimFile(const CString & strFromFileName,CString & strToFileName,int iMode);

		/******************************************************************** 
		���������������ļ��еĿ��� Ŀ���ļ��в�����ʱ�����ļ���
		������strFromFolder��Դ�ļ��� strToFolder��Ŀ���ļ���
		�� �� ֵ��
		�㷨��
		ע�����iMode:0������ʱ������ 1 ����ʱ��������  2������ʱ�������µ��ļ���
		��    �ߣ�����ҵ
		ʱ    �䣺[8/4/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL CopyFolder(const CString & strFromFolder,const CString & strToFolder,int iMode);

		/******************************************************************** 
		����������double To CString ����С�����0
		������dValue��ת��ֵ iprecision:�������� 
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[14/4/2008]
		*********************************************************************/
		KERNELBASECLASS_API CString DoubleToString(double dValue,int iprecision);

		/******************************************************************** 
		������������ȡָ����·����.Ini�ļ�
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[17/4/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL ReadIniFileInfo(const CString & strAppName,const CString & strKeyName, CString &strKeyValue,const CString & strFilePath);
		KERNELBASECLASS_API BOOL ReadIniFileInfo(const CString & strAppName,const CString & strKeyName, CString &strKeyValue,const CString & strFilePath,int filesize);

		/******************************************************************** 
		����������д��ָ����·����.Ini�ļ�
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[17/4/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL WriteIniFileInfo(const CString & strAppName,const CString & strKeyName,const CString & strKeyValue,const CString & strFilePath);

		KERNELBASECLASS_API CString GetSysDataPath(HINSTANCE _hdllInstance);
		KERNELBASECLASS_API CString GetAppPath(HINSTANCE _hdllInstance);
		KERNELBASECLASS_API CString GetFilePath(HINSTANCE _hdllInstance);
		KERNELBASECLASS_API CString GetSysDataPath();
		KERNELBASECLASS_API CString GetFilePath();
		KERNELBASECLASS_API CString GetSoft_SysDataPath();

		KERNELBASECLASS_API BOOL DownLoadFile(const CString & strUrl,const CString & strFilePath);

		//�ж� ����id �Ƿ����
		KERNELBASECLASS_API BOOL CheckProcessRunMode(DWORD dwProcessId);

		//GZIPѹ��
		/* data ԭ���� ndata ԭ���ݳ��� zdata ѹ�������� nzdata ѹ���󳤶� */
		KERNELBASECLASS_API int gzcompress(unsigned char *data, unsigned long ndata,unsigned char *zdata, unsigned long *nzdata);

		//GZIP��ѹ
		/* zdata ���� nzdata ԭ���ݳ��� data ��ѹ������ ndata ��ѹ�󳤶� */
		KERNELBASECLASS_API int gzdecompress(unsigned char *zdata, unsigned long nzdata,unsigned char *data, unsigned long *ndata);

		/******************************************************************** 
		��������������ϵͳ��Ϣ�ļ�
		������    Ҫ������ļ�·��
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[17/4/2008]
		*********************************************************************/ 
		KERNELBASECLASS_API BOOL CreateSystemInfoFile(const CString & strFilePath,const CString & strSoftVer);

		// ��ȡ Ӳ����Ϣ
		KERNELBASECLASS_API BOOL GetHardDiskInfo(LONGLONG & fAllSize,LONGLONG & fFreeSize);

		// ��ӡ��Ϣ
		KERNELBASECLASS_API BOOL CreateInfoFile_WriteInfo(CFile * pFile,CString strInfo);

		// ��ӡ�ָ���
		KERNELBASECLASS_API BOOL CreateInfoFile_SplitInfo(CFile * pFile);

		// ��ӡ����
		KERNELBASECLASS_API BOOL CreateInfoFile_EmptyLine(CFile * pFile);

		///ע�ͣ�����ҫ [2009��12��24��]                                  
		///�жϡ�value���Ƿ��ڡ�arr����
		///���Ƽ��� �ú��� ������ 
		/// PmCommonFun.h  �е� Find ���� ����
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
������������Ϊ �ڴ� ����� ���� �ӿ�
������
�� �� ֵ��
�㷨���� ��Ҫ��ʱ�� ���� �� ������ �ͷ� ָ�� ����� �ڴ�
���� Խ�� �� �ڴ� ѹ�� Խ��
ע�����
��    �ߣ�����ҵ
ʱ    �䣺[2011:3:25   17:47]
*****************************************************************/
class KERNELBASECLASS_API CPMMemoryCache
{
public:

	enum CacheMode
	{
		LowLevel = 1,//�͵ȼ�
		NormalLevel = 2,//��ͨ����
		HighLevel = 3,//�߼���
		VeryHighLevel = 4//����
	};

	CPMMemoryCache();
	virtual ~CPMMemoryCache();

	/****************************************************************
	������������ȡ ����� �ȼ�
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2011:3:25   18:09]
	*****************************************************************/
	CPMMemoryCache::CacheMode GetMemoryCacheMode();

	/****************************************************************
	���������������ͷ� �ڴ� ����
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2011:3:25   17:47]
	*****************************************************************/
	virtual int ReleaseCache() = 0;

protected:

	CacheMode m_PMMemoryCacheMode;//�ڴ滺��� ����
};


class KERNELBASECLASS_API CCallBackFun_Interface
{
public:
	CCallBackFun_Interface(){}
	virtual ~CCallBackFun_Interface(){}

	//typedef int (*gzcompress_CallBack)(unsigned char *data, unsigned long ndata,unsigned char *zdata, unsigned long *nzdata);
	//static void RegGZCompressFun(gzcompress_CallBack pCallBack);
	//static void UnRegGZCompressFun();

	//GZIPѹ��
	/* data ԭ���� ndata ԭ���ݳ��� zdata ѹ�������� nzdata ѹ���󳤶� */
	static int DoGZcompress(unsigned char *data, unsigned long ndata,unsigned char *zdata, unsigned long *nzdata);

	//GZIP��ѹ
	/* zdata ���� nzdata ԭ���ݳ��� data ��ѹ������ ndata ��ѹ�󳤶� */
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
	���������������ڴ���� 
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2011:3:25   18:00]
	*****************************************************************/
	BOOL AddMemoryCache(CPMMemoryCache * pMemoryCache);

	/****************************************************************
	�����������ӹ����� ���Ƴ� ����ָ��
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2011:3:25   18:00]
	*****************************************************************/
	BOOL RemoveMemoryCache(CPMMemoryCache * pMemoryCache);

	/****************************************************************
	���������������ڴ� ʹ�� ��� �ͷ� ����
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2011:3:25   18:02]
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
