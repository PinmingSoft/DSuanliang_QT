// PMTryCatch.h: interface for the CPMTryCatch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMTRYCATCH_H__FF03C0B4_198E_421D_9415_1495EE7525FE__INCLUDED_)
#define AFX_PMTRYCATCH_H__FF03C0B4_198E_421D_9415_1495EE7525FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PMBASECLASSAPI CPMTryCatch  
{
public:
	CPMTryCatch();
	virtual ~CPMTryCatch();

	static CPMTryCatch * Instance()
	{
		if(NULL == m_pInstance)
		{
			m_pInstance = new CPMTryCatch();
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
	typedef void(*ErrorCatchFun_T)();

	typedef void(*CloseAppFun_T)();

	typedef CString(*CreateInfoFile_ProjectInfoFun_T)(void);

	/****************************************************************
	  ����������ע�� �ر�cad����
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2011:4:22   13:58]
	*****************************************************************/
	void RegCloseAppFun(CloseAppFun_T pCatchFun);
	void UnRegCloseAppFun();
	
	/****************************************************************
	  ����������ע�� ���쳣ʱ ��ӡ������Ϣ����
		������������� �ļ���
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2011:5:5   9:40]
	*****************************************************************/
	void RegCreateInfoFile_ProjectInfoFun(CreateInfoFile_ProjectInfoFun_T pFun);
	void UnRegCreateInfoFile_ProjectInfoFun();

	int ExceptFun(LPEXCEPTION_POINTERS lpExceptionInfo,ErrorCatchFun_T pCatchFun);

	CString GetSoftVersion();

	////////////////////////////////////////////
	/// ����ҵ [2011:5:5   9:35]
	/// ˵��:
	/// ��ӡ�ָ���
	BOOL CreateInfoFile_SplitInfo(CFile * pFile);

	////////////////////////////////////////////
	/// ����ҵ [2011:5:5   9:35]
	/// ˵��:
	/// ��ӡ����
	BOOL CreateInfoFile_EmptyLine(CFile * pFile);

	////////////////////////////////////////////
	/// ����ҵ [2011:5:5   9:35]
	/// ˵��:
	/// ��ӡ ָ���ַ� ����б���ת��
	BOOL CreateInfoFile_WriteInfo(CFile * pFile,CString strInfo);

	BOOL CreateSystemInfoFile(CString strFilePath);
	
	BOOL CreateScreenPic(CString strFilePath);

	BOOL ZipFiles(CString strZipFilePath,CStringArray & strFilePathArr);

	BOOL HasRun();
protected:
	

	BOOL CDC2JPEG_File(CDC* pDC, CString strFilePath);

	int CPMTryCatch::GetEncoderClsid(const WCHAR* format, CLSID* pClsid);


	////////////////////////////////////////////
	/// ����ҵ [2011:5:5   9:36]
	/// ˵��:
	/// ��ȡ Ӳ�̴�С
	BOOL GetHardDiskInfo(LONGLONG & fAllSize,LONGLONG & fFreeSize);

	////////////////////////////////////////////
	/// ����ҵ [2011:5:5   9:36]
	/// ˵��:
	/// ���ɼ������Ϣ
	BOOL CreateInfoFile_ComputerInfo(CFile * pFile);

	////////////////////////////////////////////
	/// ����ҵ [2011:5:5   9:36]
	/// ˵��:
	/// ���ɲ���ϵͳ��Ϣ
	BOOL CreateInfoFile_SystemInfo(CFile * pFile);

	////////////////////////////////////////////
	/// ����ҵ [2011:5:5   9:36]
	/// ˵��:
	/// Ӧ�ó�����Ϣ
	BOOL CreateInfoFile_ProgramInfo(CFile * pFile);

	////////////////////////////////////////////
	/// ����ҵ [2011:5:5   9:36]
	/// ˵��:
	/// ���� ����ģ����Ϣ
	BOOL CreateInfoFile_ModuleInfo(CString strFilePath);

	////////////////////////////////////////////
	/// ����ҵ [2011:5:5   9:37]
	/// ˵��:
	/// ���� ���н�����Ϣ
	BOOL CreateInfoFile_ProcessInfo(CString strFilePath);

	static CPMTryCatch * m_pInstance;

	CLSID m_jpgClsid;

	CloseAppFun_T m_pCloseAppFun;
	CreateInfoFile_ProjectInfoFun_T m_pCreate_ProjectInfoFun;
private:
	static BOOL m_bHasRun;//�Ƿ��Ѿ�����
};


#define PMNoThrowTryBegin	__try\
							{\

#define PMNoThrowTryEnd		}\
							__except(1){
							
#define PMNoThrowTryFinish		}

#ifdef NDEBUG
#define PMDepthTryBegin __try\
						{CPMTryCatch::Instance();\

#define PMDepthTryEnd_Fun(callBackFun)	}\
										__except(CPMTryCatch::Instance()->ExceptFun(GetExceptionInformation(),callBackFun)){\
									}

#define PMDepthTryEnd				}\
										__except(CPMTryCatch::Instance()->ExceptFun(GetExceptionInformation(),NULL)){\
									}
#else

#define PMDepthTryBegin			
#define PMDepthTryEnd_Fun(callBackFun)
#define PMDepthTryEnd

#endif
#endif // !defined(AFX_PMTRYCATCH_H__FF03C0B4_198E_421D_9415_1495EE7525FE__INCLUDED_)
