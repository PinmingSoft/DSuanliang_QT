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
//#define PMNormal				1		//������Ϣ  		���÷�Χ����ʾ��Ϣ
//#define PMLowError				10		//�͵ȼ�����		���÷�Χ���߼����� û���κ�Ӱ��
//#define PMNormalError			100		//�м����� 		 ���÷�Χ��ҵ����� ���ܻ���ʾ����������������
//#define PMHighError				1000	//�ߵȼ�����		 	���÷�Χ�����ܻ���������������
//#define PMVeryHighError			10000	//�ǳ��ߵȼ����� 	���÷�Χ���ļ����󣬲����档���û����޷������

//namespace PMERROR
//{
//	enum ErrorStyle
//	{
//		None = 0
//		,LeftBrace = 1		//������Ϣ����������
//		,RightBrace = 2		//������Ϣ����Ҳ�����
//		,BothBrace = 3		//������Ϣ�����������
//	};
//	//��ȡ���������λ��
//	PMBASECLASSAPI CString GetErrorFilePath();
//	//�������
//	PMBASECLASSAPI BOOL PrintInfo(CString strErrorMsg,DWORD error,ErrorStyle style);
//	PMBASECLASSAPI BOOL PrintInfo(CString strErrorMsg,DWORD error);
//
//	PMBASECLASSAPI void SetErrorLogDir(CString strLogDir);
//
//	PMBASECLASSAPI void SetErrorLogFileName(const CString & strFileName);
//}

//#endif // !defined(AFX_PMDEBUG_H__4ED03374_9C88_459E_9590_669688FF7F70__INCLUDED_)
