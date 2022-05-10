#ifndef __SEEXCEPTION_H__
#define __SEEXCEPTION_H__


// #ifdef _DEBUG_WAS_DEFINED//_DEBUG
// 	#define  INSTALL_SEHCONVERT		((void)0)
// 	#define  UNINSTALL_SEHCONVERT	((void)0)
// #else
	//一般主线程中使用
	#define INSTALL_SEHCONVERT	\
			{\
			 if(_OldFanc == NULL) _OldFanc = _set_se_translator(SeTranslator);\
			}

	#define UNINSTALL_SEHCONVERT \
			{\
				if(_OldFanc != NULL) {\
					_set_se_translator(_OldFanc);\
					_OldFanc= NULL; }\
			}
//#endif

#ifdef _DEBUG
#define _DEBUG_ZLL_WAS_DEFINED
#undef _DEBUG
#pragma message ("		连接MFC、STD、run-timing用Release")
#endif

#include <EH.H>

#ifdef _DEBUG_ZLL_WAS_DEFINED
#define _DEBUG
#undef _DEBUG_ZLL_WAS_DEFINED
#endif



class PMBASECLASSAPI CSeException : public CException
{
	DECLARE_DYNAMIC(CSeException)
public:    
	CSeException(UINT nSeCode, _EXCEPTION_POINTERS* pExcPointers);
	CSeException(CSeException & CseExc);

    UINT	GetSeCode(void);
	_EXCEPTION_POINTERS* GetSePointers(void);
	PVOID	GetExceptionAddress(void);

	void	Delete(void);
	int		ReportError(UINT nType = MB_OK, UINT nIDHelp = 0);
	BOOL	GetErrorMessage(CString & CsErrDescr, PUINT pnHelpContext = NULL);
	BOOL	GetErrorMessage(LPTSTR lpszError, UINT nMaxError, PUINT pnHelpContext = NULL);
private:
	UINT m_nSeCode;
	_EXCEPTION_POINTERS* m_pExcPointers;
};

extern PMBASECLASSAPI _se_translator_function  _OldFanc;
//对于其他的线程，可以直接进行设置
PMBASECLASSAPI void	SeTranslator(UINT nSeCode, _EXCEPTION_POINTERS* pExcPointers);

#endif //__SEEXCEPTION_H__
