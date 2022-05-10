#if !defined(AFX_PROPEXCEPTION_H__C8FECC4B_BD87_4E5C_A016_D4B78FD7674A__INCLUDED_)
#define AFX_PROPEXCEPTION_H__C8FECC4B_BD87_4E5C_A016_D4B78FD7674A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PropException.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropException window

class PMBASECLASSAPI CPropException :public CException
{
	DECLARE_DYNAMIC(CPropException)
public:
	CPropException();
	CPropException(CString errorInfo,UINT nMessageID = 0);

// Attributes
protected:
	CString m_strErrorInfo;
	UINT	m_messageId;
// Operations
public:
	//个人认为GetErrorMessage的接口不好，于是用GetErrorInfo
	void GetErrorMessage(CString & info) const;
	virtual BOOL GetErrorMessage(LPTSTR lpszError, UINT nMaxError, PUINT pnHelpContext = NULL);
	virtual int ReportError(UINT nType = MB_OK, UINT nMessageID = 0);
	void Delete(void);
// Implementation
public:
	virtual ~CPropException();

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPEXCEPTION_H__C8FECC4B_BD87_4E5C_A016_D4B78FD7674A__INCLUDED_)
