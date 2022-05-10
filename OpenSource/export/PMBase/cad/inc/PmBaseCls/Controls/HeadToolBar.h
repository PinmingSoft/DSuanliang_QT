#if !defined(AFX_HEADTOOLBAR_H__D1935A0C_51A0_4D3A_AFED_BBFD47CE4EA6__INCLUDED_)
#define AFX_HEADTOOLBAR_H__D1935A0C_51A0_4D3A_AFED_BBFD47CE4EA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HeadToolBar.h : header file
//

#include "ShadeButtonST.h"

/////////////////////////////////////////////////////////////////////////////
// CHeadToolBar window

class PMBASECLASSAPI CHeadToolBar : public CStatic
{
// Construction
public:
	CHeadToolBar();

// Attributes
public:
	BOOL Initialize();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHeadToolBar)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHeadToolBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CHeadToolBar)
	// afx_msg void OnNcPaint();
	//afx_msg void OnPaint();
	afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonNew();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUp();
	afx_msg void OnButtonDown();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

	void MoveButtons();
	void DrawText(CDC* pDC, CRect& rcClient);
	void SendCommand(UINT nCmdID);

protected:
	bool m_bShowUpDownButtons;     // Controls whether of not the up.down buttons are shown.
	bool m_bShowNewDeleteButtons;     // Controls whether of not the up.down buttons are shown.
	bool          m_bEnableEdit;   // True if editing is enabled.
	CRect         m_arClipRect[4]; // Array of toolbar button sizes.
	CShadeButtonST     m_arButton[4];   // Array of toolbar buttons.
	// CXTIconHandle m_arIcon[4];     // Array of toolbar button icons.
	CToolTipCtrl  m_tooltip;       // Tooltip control for edit buttons.
};

#define HEADTOOL_BTN_NEW WM_USER+9211
#define HEADTOOL_BTN_DELETE WM_USER+9212
#define HEADTOOL_BTN_UP WM_USER+9213
#define HEADTOOL_BTN_DOWN WM_USER+9214

#ifndef _countof
#define _countof(array) (sizeof(array)/sizeof(array[0]))
#endif

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HEADTOOLBAR_H__D1935A0C_51A0_4D3A_AFED_BBFD47CE4EA6__INCLUDED_)
