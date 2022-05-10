// PMRichEditCtrl.h: interface for the CPMRichEditCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMRICHEDITCTRL_H__C2AD946C_99BE_4B3A_AE59_E8AC7827373A__INCLUDED_)
#define AFX_PMRICHEDITCTRL_H__C2AD946C_99BE_4B3A_AE59_E8AC7827373A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PMBASECLASSAPI CPMRichEditCtrl : public CRichEditCtrl
{
// Construction
public:
	CPMRichEditCtrl();
	
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPMRichEditCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	LRESULT GetOptions();
	BOOL GetReadOnly();
	virtual ~CPMRichEditCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPMRichEditCtrl)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg void OnCopy() { Copy(); }
	afx_msg void OnCut() { Cut(); }
	afx_msg void OnPaste() { Paste(); }
	afx_msg void OnSelectall() { SetSel(0, -1); }
	afx_msg void OnUndo() { Undo(); }

	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_PMRICHEDITCTRL_H__C2AD946C_99BE_4B3A_AE59_E8AC7827373A__INCLUDED_)
