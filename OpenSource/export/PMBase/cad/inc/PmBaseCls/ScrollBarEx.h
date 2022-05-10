#if !defined(AFX_VMCUBASESCROLLBAR_H__EB442742_EC74_4F6F_94FA_7833E431C59A__INCLUDED_)
#define AFX_VMCUBASESCROLLBAR_H__EB442742_EC74_4F6F_94FA_7833E431C59A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScrollBarEx.h : header file
//
//Author: Nobita
//Date: 2010.01.29
//I love Doraemon!!!

/////////////////////////////////////////////////////////////////////////////
// CScrollBarEx window

class PMBASECLASSAPI CScrollBarEx : public CStatic
{
	// Construction
public:
	CScrollBarEx();
	
	// Attributes
public:
	BOOL InitScrollBar(CWnd *pCtrl, UINT nStyle);
	void InitVScrollBmpPath(const CString& strVerticle_Scrollbar_UpArrow,
							const CString& strVerticle_Scrollbar_DownArrow,
							const CString& strVerticle_Scrollbar_Span,
							const CString& strVerticle_Scrollbar_Slider_Top,
							const CString& strVerticle_Scrollbar_Slider_Center,
							const CString& strVerticle_Scrollbar_Slider_Bottom,
							const CString& strVerticle_Scrollbar_Thumb);
	void InitHScrollBmpPath(const CString& strHorizontal_Scrollbar_LeftArrow,
							const CString& strHorizontal_Scrollbar_RightArrow,
							const CString& strHorizontal_Scrollbar_Span,
							const CString& strHorizontal_Scrollbar_Slider_Left,
							const CString& strHorizontal_Scrollbar_Slider_Center,
							const CString& strHorizontal_Scrollbar_Slider_Right,
							const CString& strHorizontal_Scrollbar_Thumb);
	void UpdateScrollBar();
	
	// Operations
public:
	
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollBarEx)
	//}}AFX_VIRTUAL
	
	// Implementation
public:
	virtual ~CScrollBarEx();
	
	// Generated message map functions
protected:
	//{{AFX_MSG(CScrollBarEx)
	afx_msg void OnPaint();
	//}}AFX_MSG
	
	DECLARE_MESSAGE_MAP()
private:
	CWnd* m_pCtrl;
	UINT m_nScrollStyle;
private:
	void DrawVScroll(CDC* pDC);
	void DrawHScroll(CDC* pDC);
	BOOL LoadBmpFile(const CString& strFileName,CBitmap& bitmap);
private:
	// ��ֱ������
	CString m_strVerticle_Scrollbar_UpArrow;		// �ϼ�ͷ
	CString m_strVerticle_Scrollbar_DownArrow;		// �¼�ͷ
	CString m_strVerticle_Scrollbar_Span;			// ������
	CString m_strVerticle_Scrollbar_Slider_Top;		// �����ϲ�
	CString m_strVerticle_Scrollbar_Slider_Center;	// �����м�
	CString m_strVerticle_Scrollbar_Slider_Bottom;	// ����ײ�
	CString m_strVerticle_Scrollbar_Thumb;			// ����Ĵָ

	// ˮƽ������
	CString m_strHorizontal_Scrollbar_LeftArrow;	// ���ͷ
	CString m_strHorizontal_Scrollbar_RightArrow;	// �Ҽ�ͷ
	CString m_strHorizontal_Scrollbar_Span;			// ������
	CString m_strHorizontal_Scrollbar_Slider_Left;	// ������
	CString m_strHorizontal_Scrollbar_Slider_Center;// �����м�
	CString m_strHorizontal_Scrollbar_Slider_Right;	// �����Ҳ�
	CString m_strHorizontal_Scrollbar_Thumb;		// ����Ĵָ
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VMCUBASESCROLLBAR_H__EB442742_EC74_4F6F_94FA_7833E431C59A__INCLUDED_)
