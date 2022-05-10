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
	  功能描述：注册 关闭cad函数
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2011:4:22   13:58]
	*****************************************************************/
	void RegCloseAppFun(CloseAppFun_T pCatchFun);
	void UnRegCloseAppFun();
	
	/****************************************************************
	  功能描述：注册 在异常时 打印工程信息函数
		参数：输出到的 文件名
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2011:5:5   9:40]
	*****************************************************************/
	void RegCreateInfoFile_ProjectInfoFun(CreateInfoFile_ProjectInfoFun_T pFun);
	void UnRegCreateInfoFile_ProjectInfoFun();

	int ExceptFun(LPEXCEPTION_POINTERS lpExceptionInfo,ErrorCatchFun_T pCatchFun);

	CString GetSoftVersion();

	////////////////////////////////////////////
	/// 王建业 [2011:5:5   9:35]
	/// 说明:
	/// 打印分割线
	BOOL CreateInfoFile_SplitInfo(CFile * pFile);

	////////////////////////////////////////////
	/// 王建业 [2011:5:5   9:35]
	/// 说明:
	/// 打印空行
	BOOL CreateInfoFile_EmptyLine(CFile * pFile);

	////////////////////////////////////////////
	/// 王建业 [2011:5:5   9:35]
	/// 说明:
	/// 打印 指定字符 会进行编码转换
	BOOL CreateInfoFile_WriteInfo(CFile * pFile,CString strInfo);

	BOOL CreateSystemInfoFile(CString strFilePath);
	
	BOOL CreateScreenPic(CString strFilePath);

	BOOL ZipFiles(CString strZipFilePath,CStringArray & strFilePathArr);

	BOOL HasRun();
protected:
	

	BOOL CDC2JPEG_File(CDC* pDC, CString strFilePath);

	int CPMTryCatch::GetEncoderClsid(const WCHAR* format, CLSID* pClsid);


	////////////////////////////////////////////
	/// 王建业 [2011:5:5   9:36]
	/// 说明:
	/// 获取 硬盘大小
	BOOL GetHardDiskInfo(LONGLONG & fAllSize,LONGLONG & fFreeSize);

	////////////////////////////////////////////
	/// 王建业 [2011:5:5   9:36]
	/// 说明:
	/// 生成计算机信息
	BOOL CreateInfoFile_ComputerInfo(CFile * pFile);

	////////////////////////////////////////////
	/// 王建业 [2011:5:5   9:36]
	/// 说明:
	/// 生成操作系统信息
	BOOL CreateInfoFile_SystemInfo(CFile * pFile);

	////////////////////////////////////////////
	/// 王建业 [2011:5:5   9:36]
	/// 说明:
	/// 应用程序信息
	BOOL CreateInfoFile_ProgramInfo(CFile * pFile);

	////////////////////////////////////////////
	/// 王建业 [2011:5:5   9:36]
	/// 说明:
	/// 生成 加载模块信息
	BOOL CreateInfoFile_ModuleInfo(CString strFilePath);

	////////////////////////////////////////////
	/// 王建业 [2011:5:5   9:37]
	/// 说明:
	/// 生成 所有进程信息
	BOOL CreateInfoFile_ProcessInfo(CString strFilePath);

	static CPMTryCatch * m_pInstance;

	CLSID m_jpgClsid;

	CloseAppFun_T m_pCloseAppFun;
	CreateInfoFile_ProjectInfoFun_T m_pCreate_ProjectInfoFun;
private:
	static BOOL m_bHasRun;//是否已经运行
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
