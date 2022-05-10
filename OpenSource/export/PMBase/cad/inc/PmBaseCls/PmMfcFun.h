// PmMfcFun.h: interface for the CPmMfcFun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMMFCFUN_H__84F82B80_E1E4_4D99_A3A4_BACA67B99494__INCLUDED_)
#define AFX_PMMFCFUN_H__84F82B80_E1E4_4D99_A3A4_BACA67B99494__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define PMCompareString(string1,string2)	(string1.GetLength() == string2.GetLength() && string1 == string2)

namespace PmMfc
{
	namespace Fun
	{
		class PMBASECLASSAPI Mfc_ResourceOverride
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
		PMBASECLASSAPI BOOL CheckDoubleIsNormal(double dValue);

		/****************************************************************
		  ������������ȡ����ϵͳ�汾
			������
			�� �� ֵ��
			�㷨��
			ע�����
			��    �ߣ�����ҵ
			ʱ    �䣺[2011:4:20   15:40]
		*****************************************************************/
		PMBASECLASSAPI BOOL GetWindowsSystemVersion(CString & strWindowsSysVer);

		/****************************************************************
		  �����������ж��Ƿ��� ���ڵ� ����ϵͳ
			������
			�� �� ֵ��
			�㷨��
			ע�����
			��    �ߣ�zyj
			ʱ    �䣺[2015:4:23]
		*****************************************************************/
		PMBASECLASSAPI BOOL CheckIsOldSystemVersion();

		/******************************************************************** 
		������������Acsii�ַ��� תΪUnicode�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:58
		*********************************************************************/ 
		PMBASECLASSAPI LPWSTR PM_A2W(LPCSTR pAInfo);

		/******************************************************************** 
		������������Unicode�ַ��� תΪAcsii�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:58
		*********************************************************************/ 
		PMBASECLASSAPI LPSTR PM_W2A(LPCWSTR pWInfo);

		/******************************************************************** 
		������������������Unicode��Acsii�ַ��� תΪUnicode�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:03
		*********************************************************************/ 
		PMBASECLASSAPI LPWSTR PM_T2W(LPCTSTR pTInfo);

		/******************************************************************** 
		������������������Unicode��Acsii�ַ��� תΪAcsii�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:03
		*********************************************************************/ 
		PMBASECLASSAPI LPSTR PM_T2A(LPCTSTR pTInfo);

		/******************************************************************** 
		������������Acsii�ַ��� ���ݻ���תΪ ������Unicode��Acsii�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:03
		*********************************************************************/ 
		PMBASECLASSAPI LPTSTR PM_A2T(LPCSTR pAInfo);

		/******************************************************************** 
		������������Unicode�ַ��� ���ݻ���תΪ ������Unicode��Acsii�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:10:21]   11:03
		*********************************************************************/ 
		PMBASECLASSAPI LPTSTR PM_W2T(LPCWSTR pWInfo);

		/******************************************************************** 
		�����������Ƚ��ַ���
		������
		�� �� ֵ��
		�㷨��
		ע������������Ļ�������ʹ��PMCompareString��İ汾
		��    �ߣ�����ҵ
		ʱ    �䣺[2010:9:25]   16:47
		*********************************************************************/ 
		PMBASECLASSAPI BOOL PMCompareStringFun(const CString & strString1,const CString & strString2);

		/******************************************************************** 
		 �������������ַ������ݱ��浽���а���
		 ������
		 �� �� ֵ��
		 �㷨��
		 ע�����
		 ��    �ߣ�����ҵ
		 ʱ    �䣺[29/7/2010]
		*********************************************************************/ 
		PMBASECLASSAPI void ClipboardSave(HWND hwnd,CString &text);

		/******************************************************************** 
		 ���������������а��������ַ�������
		 ������
		 �� �� ֵ��
		 �㷨��
		 ע�����
		 ��    �ߣ�����ҵ
		 ʱ    �䣺[29/7/2010]
		*********************************************************************/ 
		PMBASECLASSAPI void ClipboardLoad(HWND hwnd,CString &text);

		/******************************************************************** 
		 ������������CDC�� ���� �ַ��� ��������Ļ�еĿ�ȡ��߶�
		 ������
		 �� �� ֵ��
		 �㷨��
		 ע�����
		 ��    �ߣ�����ҵ
		 ʱ    �䣺[22/7/2010]
		*********************************************************************/ 
		PMBASECLASSAPI BOOL GetStringWith_Height(CDC * pDC,const CString & strInfo,int & iWidth,int & iHeight);

		/******************************************************************** 
		 �������������ַ���ѹ��ָ���ļ���
		 ������
		 �� �� ֵ��
		 �㷨��
		 ע�����
		 ��    �ߣ�����ҵ
		 ʱ    �䣺[28/4/2010]
		*********************************************************************/ 
		PMBASECLASSAPI BOOL AppendCString2File(const CString & strFilePath,const CString & strAppendInfo);
		
		/******************************************************************** 
		 ����������	�ȶԸ�����
		 ������const double src1,const double src2,const double dMinValue������ֵ
		 �� �� ֵ��
		 �㷨��
		 ע�����0:��� -1��С�� 1������
		 ��    �ߣ�����ҵ
		 ʱ    �䣺[21/9/2009]
		*********************************************************************/ 
		PMBASECLASSAPI int CompareDbl(const double src1,const double src2,const double dMinValue);

		/******************************************************************** 
		 ��������������delim����ַ���strValue��װ��aryStr���������
		 ������
		 �� �� ֵ��
		 �㷨��
		 ע�����
		 ��    �ߣ�����ҵ
		 ʱ    �䣺[9/4/2009]
		*********************************************************************/ 
		PMBASECLASSAPI BOOL Split(const CString &strValue,const CString &delim, CStringArray & aryStr);

		/******************************************************************** 
		������������charת��ΪHex
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[17/11/2008]
		*********************************************************************/ 
		PMBASECLASSAPI int CharToHex(TCHAR c);

		/******************************************************************** 
		������������CStringת��ΪHex
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[17/11/2008]
		*********************************************************************/ 
		PMBASECLASSAPI DWORD CStringToHex(const CString & strValue);

		/******************************************************************** 
		������������RGB��ɫת��ΪHex�ַ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�pzh
		ʱ    �䣺[29/01/2018]
		*********************************************************************/ 
		PMBASECLASSAPI CString RGBToHEX(COLORREF);

		/******************************************************************** 
		������������ȡ�ļ� 
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[28/11/2008]
		*********************************************************************/ 
		PMBASECLASSAPI BOOL File2CString(const CString & filename,CString& buf);

		/// ֧�ָ���ĸ�ʽ��
		PMBASECLASSAPI BOOL File2CStringMore(const CString & filename,CString& buf);

		/// 
		PMBASECLASSAPI bool isutf8(CHAR *str) ; 

		//�ָ� �ļ��� Ŀ¼
		PMBASECLASSAPI CString SplitFileDir(const CString & strFilePath);

		//�ָ� �ļ��� ����
		PMBASECLASSAPI CString SplitFileName(const CString & strFilePath);

		/******************************************************************** 
		������������ȡ����·��
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[18/10/2008]
		*********************************************************************/ 
		PMBASECLASSAPI CString GetAppPath();

		/// ����·�� E:\source\export\ddll
		PMBASECLASSAPI CString	GetAppPath_v2() ; 

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
		PMBASECLASSAPI BOOL ScanFolder_HasExtendName(const CString & strFolderPath, CStringArray &strFileArray);

		/**
		* @brief  ���� ɨ��һ���ļ��� ��ȡһ���ļ����͵� �����ļ���,����չ���ġ�
		*
		*          
		* @note  : strFolderPath�����Դ����ˣ��磺_T("C:\\����ģ���\\*.pmcd");\n
		*			strFileArray:�е��ļ����ƣ�����չ��
		*			bSearchChild �Ƿ� �������ļ���
		* @param : const CString & strFolderPath:Ҫɨ����ļ���·��\n
		*			CStringArray &strFileArray:�����ļ����е��ļ�����
		* @defenc: 
		* @return: TRUE:ִ�гɹ�\n
		*			FALSE:ִ��ʧ��
		* @author: ����ҵ
		* @date  : [15/9/2011]
		*/
		PMBASECLASSAPI BOOL ScanFolder_HasExtendName(const CString & strFolderPath, CStringArray &strFileArray,BOOL bSearchChild);

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
		PMBASECLASSAPI BOOL ScanFolder_NoExtendName(const CString & strFolderPath, CStringArray &strFileArray);

		//����ַ���
		PMBASECLASSAPI void SplitCString(const CString & source, CStringArray& dest, TCHAR division);
		PMBASECLASSAPI void SplitCString(const CString & source, CStringArray& dest, const CString & strDivision);

		//������ʱ�ļ�
		PMBASECLASSAPI BOOL SaveFileContent(const CString & fileName,const CString & content);

		//���ļ�·����ȡ�ļ���
		PMBASECLASSAPI CString GetFileNameFromPath(CString strFilePathName);

		/**
		* @brief   �ж��ļ��Ƿ����
		*
		*			
		* @note  : 
		* @param : nAccessMode 0:Existence only 2: Write permission  4��Read permission 6��Read and write permission
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [1/23/2018]
		*/
		PMBASECLASSAPI BOOL IsFileExist(CString filepathname,int nAccessMode=4);

		/******************************************************************** 
		�����������������ļ�
		������strFromFileName��ԭ�ļ���ַ strToFileName��Ŀ���ַ iMode:����ģʽ
		�� �� ֵ���Ƿ�ɹ�
		�㷨��
		ע�����iMode:0������ʱ������ 1 ����ʱ��������  2������ʱ�������µ��ļ���
		��    �ߣ�����ҵ
		ʱ    �䣺[18/3/2008]
		*********************************************************************/ 
		PMBASECLASSAPI BOOL RenameFile(const CString & strOldFileName,CString & strNewFileName,int iMode);

		//����ļ�״̬
		PMBASECLASSAPI BOOL CheckFile(const CString & strFileName);

		//����ļ��Ƿ��д
		PMBASECLASSAPI BOOL CheckFileWriteEnable(const CString & strFileName);

		/******************************************************************** 
		���������������ļ�
		������strFromFileName��ԭ�ļ���ַ strToFileName��Ŀ���ַ iMode:����ģʽ
		�� �� ֵ���Ƿ�ɹ�
		�㷨��
		ע�����iMode:0������ʱ������ 1 ����ʱ��������  2������ʱ�������µ��ļ���
		��    �ߣ�����ҵ
		ʱ    �䣺[18/3/2008]
		*********************************************************************/ 
		PMBASECLASSAPI BOOL CopySimFile(const CString & strFromFileName,CString & strToFileName,int iMode);

		/******************************************************************** 
		���������������ļ��еĿ��� Ŀ���ļ��в�����ʱ�����ļ���
		������strFromFolder��Դ�ļ��� strToFolder��Ŀ���ļ���
		�� �� ֵ��
		�㷨��
		ע�����iMode:0������ʱ������ 1 ����ʱ��������  2������ʱ�������µ��ļ���
		��    �ߣ�����ҵ
		ʱ    �䣺[8/4/2008]
		*********************************************************************/ 
		PMBASECLASSAPI BOOL CopyFolder(const CString & strFromFolder,const CString & strToFolder,int iMode);

		/******************************************************************** 
		����������double To CString ����С�����0
		������dValue��ת��ֵ iprecision:�������� 
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[14/4/2008]
		*********************************************************************/
		PMBASECLASSAPI CString DoubleToString(double dValue,int iprecision);

		/******************************************************************** 
		������������ȡָ����·����.Ini�ļ�
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[17/4/2008]
		*********************************************************************/ 
		PMBASECLASSAPI BOOL ReadIniFileInfo(const CString & strAppName,const CString & strKeyName, CString &strKeyValue,const CString & strFilePath);

		/******************************************************************** 
		����������д��ָ����·����.Ini�ļ�
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[17/4/2008]
		*********************************************************************/ 
		PMBASECLASSAPI BOOL WriteIniFileInfo(const CString & strAppName,const CString & strKeyName,const CString & strKeyValue,const CString & strFilePath);

		PMBASECLASSAPI CString GetSysDataPath(HINSTANCE _hdllInstance);
		PMBASECLASSAPI CString GetAppPath(HINSTANCE _hdllInstance);
		PMBASECLASSAPI CString GetFilePath(HINSTANCE _hdllInstance);
		PMBASECLASSAPI CString GetSysDataPath();
		PMBASECLASSAPI CString GetFilePath();
		PMBASECLASSAPI CString GetSoft_SysDataPath();

		//��ȡ�ļ��汾��
		PMBASECLASSAPI CString GetFileVersion(const CString & pathFileName);

		//GZIPѹ��
		/* data ԭ���� ndata ԭ���ݳ��� zdata ѹ�������� nzdata ѹ���󳤶� */
		PMBASECLASSAPI int gzcompress(unsigned char *data, unsigned long ndata,unsigned char *zdata, unsigned long *nzdata);

		//GZIP��ѹ
		/* zdata ���� nzdata ԭ���ݳ��� data ��ѹ������ ndata ��ѹ�󳤶� */
		PMBASECLASSAPI int gzdecompress(unsigned char *zdata, unsigned long nzdata,unsigned char *data, unsigned long *ndata);

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

		/******************************************************************** 
		���������������ļ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ����ٻ�
		ʱ    �䣺[11/07/2017]
		*********************************************************************/ 
		PMBASECLASSAPI BOOL CreateFolder(const CString& strFolder);

		/********************************************************************
		����������ɾ�����ļ��м��ļ���ѭ��
		
		*********************************************************************/
		PMBASECLASSAPI BOOL DeleteFolder(const CString & strFromFolder);

		/// �����ļ�Ϊֻ��
		PMBASECLASSAPI void SetFileReadOnly(const CString & filePathName);

		/// �жϵ�ǰ�Ƿ��Ǵ�д״̬
		PMBASECLASSAPI BOOL IsCapsLock();

		/**
		* @brief   �򿪻��߹رմ�д��
		*
		*			�����ڷ�ֹCAD����
		* @note  : 
		* @param : bState = FALSEʱ�رմ�д��,TRUEʱ�򿪴�д��
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [9/23/2019]
		*/
		PMBASECLASSAPI void SetCapsLock(BOOL bState);
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
//class PMBASECLASSAPI CPMMemoryCache
//{
//public:
//
//	enum CacheMode
//	{
//		LowLevel = 1,//�͵ȼ�
//		NormalLevel = 2,//��ͨ����
//		HighLevel = 3,//�߼���
//		VeryHighLevel = 4//����
//	};
//
//	CPMMemoryCache();
//	virtual ~CPMMemoryCache();
//
//	/****************************************************************
//	������������ȡ ����� �ȼ�
//	������
//	�� �� ֵ��
//	�㷨��
//	ע�����
//	��    �ߣ�����ҵ
//	ʱ    �䣺[2011:3:25   18:09]
//	*****************************************************************/
//	CPMMemoryCache::CacheMode GetMemoryCacheMode();
//
//	/****************************************************************
//	���������������ͷ� �ڴ� ����
//	������
//	�� �� ֵ��
//	�㷨��
//	ע�����
//	��    �ߣ�����ҵ
//	ʱ    �䣺[2011:3:25   17:47]
//	*****************************************************************/
//	virtual int ReleaseCache() = 0;
//
//protected:
//
//	CacheMode m_PMMemoryCacheMode;//�ڴ滺��� ����
//};


//class PMBASECLASSAPI CPMMemoryCacheManager
//{
//public:
//	static CPMMemoryCacheManager * Instance()
//	{
//		if(NULL == m_pInstance)
//		{
//			m_pInstance = new CPMMemoryCacheManager;	
//		}
//		return m_pInstance;
//	}
//
//	static void Release()
//	{
//		if(NULL != m_pInstance)
//		{
//			delete m_pInstance;
//			m_pInstance = NULL;
//		}
//	}
//
//	/****************************************************************
//	���������������ڴ���� 
//	������
//	�� �� ֵ��
//	�㷨��
//	ע�����
//	��    �ߣ�����ҵ
//	ʱ    �䣺[2011:3:25   18:00]
//	*****************************************************************/
//	BOOL AddMemoryCache(CPMMemoryCache * pMemoryCache);
//
//	/****************************************************************
//	�����������ӹ����� ���Ƴ� ����ָ��
//	������
//	�� �� ֵ��
//	�㷨��
//	ע�����
//	��    �ߣ�����ҵ
//	ʱ    �䣺[2011:3:25   18:00]
//	*****************************************************************/
//	BOOL RemoveMemoryCache(CPMMemoryCache * pMemoryCache);
//
//	/****************************************************************
//	���������������ڴ� ʹ�� ��� �ͷ� ����
//	������
//	�� �� ֵ��
//	�㷨��
//	ע�����
//	��    �ߣ�����ҵ
//	ʱ    �䣺[2011:3:25   18:02]
//	*****************************************************************/
//	BOOL ClearUpMemoryCache();
//
//	void ClearLevelMemoryCache(CPMMemoryCache::CacheMode memoryCacheMode);
//
//private:
//
//	CPMMemoryCacheManager();
//	virtual ~CPMMemoryCacheManager();
//
//	CArray<CPMMemoryCache*,CPMMemoryCache*&> m_PMMemoryCacheArr;
//	static CPMMemoryCacheManager * m_pInstance;
//};

#endif // !defined(AFX_PMMFCFUN_H__84F82B80_E1E4_4D99_A3A4_BACA67B99494__INCLUDED_)
