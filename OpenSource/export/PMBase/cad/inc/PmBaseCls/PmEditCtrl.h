#if !defined(AFX_PMEDITCTRL_H__10D0615E_D0A8_42B3_9084_B35146DB3F31__INCLUDED_)
#define AFX_PMEDITCTRL_H__10D0615E_D0A8_42B3_9084_B35146DB3F31__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PmEditCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPmEditCtrl window

class PMBASECLASSAPI CPmEditCtrl : public CEdit
{
// Construction
public:
	CPmEditCtrl();
	
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPmEditCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPmEditCtrl();

	//拷贝所有内容到剪贴板
	BOOL CopyAll();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPmEditCtrl)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PMEDITCTRL_H__10D0615E_D0A8_42B3_9084_B35146DB3F31__INCLUDED_)
