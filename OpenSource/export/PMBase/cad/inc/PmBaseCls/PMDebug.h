// PMDebug.h: interface for the CPMDebug class.
//
//////////////////////////////////////////////////////////////////////

//#if !defined(AFX_PMDEBUG_H__4ED03374_9C88_459E_9590_669688FF7F70__INCLUDED_)
//#define AFX_PMDEBUG_H__4ED03374_9C88_459E_9590_669688FF7F70__INCLUDED_
//
//#if _MSC_VER > 1000
//#pragma once
//#endif // _MSC_VER > 1000

//void WINAPI DbgLogInfo(const TCHAR *pFormat,...);
//
//#ifdef _PMDEBUG
//    #define DbgLog DbgLogInfo 
//#else
//    #define DbgLog(_x_) 0
//#endif
//
//#define chSTR2(x)	   #x
//#define chSTR(x)	chSTR2(x)
//#define chMSG(desc) message(__FILE__ "(" chSTR(__LINE__) "):" #desc)
//
//#define PMNormal				1		//正常信息  		适用范围：提示信息
//#define PMLowError				10		//低等级错误		适用范围：逻辑错误 没有任何影响
//#define PMNormalError			100		//中级错误 		 适用范围：业务错误 可能会显示不正常，或量不对
//#define PMHighError				1000	//高等级错误		 	适用范围：可能会引起程序崩溃错误
//#define PMVeryHighError			10000	//非常高等级错误 	适用范围：文件错误，不可逆。（用户打开无法解决）

//namespace PMERROR
//{
//	enum ErrorStyle
//	{
//		None = 0
//		,LeftBrace = 1		//错误信息添加左侧括号
//		,RightBrace = 2		//错误信息添加右侧括号
//		,BothBrace = 3		//错误信息添加两端括号
//	};
//	//获取错误输出的位置
//	PMBASECLASSAPI CString GetErrorFilePath();
//	//输出错误
//	PMBASECLASSAPI BOOL PrintInfo(CString strErrorMsg,DWORD error,ErrorStyle style);
//	PMBASECLASSAPI BOOL PrintInfo(CString strErrorMsg,DWORD error);
//
//	PMBASECLASSAPI void SetErrorLogDir(CString strLogDir);
//
//	PMBASECLASSAPI void SetErrorLogFileName(const CString & strFileName);
//}

//#endif // !defined(AFX_PMDEBUG_H__4ED03374_9C88_459E_9590_669688FF7F70__INCLUDED_)
