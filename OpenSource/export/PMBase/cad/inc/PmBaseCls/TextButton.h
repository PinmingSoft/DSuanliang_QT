#pragma once
#include "afxwin.h"

class PMBASECLASSAPI CTextButton : public CButton
{
	DECLARE_DYNAMIC(CTextButton)

public:
	CTextButton();
	virtual ~CTextButton();

	void SetBkClr(COLORREF clr) { m_bkClr = clr; }
	void SetMainNormalClr(COLORREF clr) { m_mainNormalClr = clr; }
	void SetMainHoverClr(COLORREF clr) { m_mainHoverClr = clr; }
	void SetMainActiveClr(COLORREF clr) { m_mainActiveClr = clr; }
	void SetMainEdgeClr(COLORREF clr) { m_mainEdgeClr = clr; }
	void SetTextNormalClr(COLORREF clr) { m_textNormalClr = clr; }
	void SetTextHoverClr(COLORREF clr) { m_textHoverClr = clr; }
	void SetTextActiveClr(COLORREF clr) { m_textActiveClr = clr; }
	void SetCheckTagClr(COLORREF clr) { m_checkTagClr = clr; }
	void SetCheckTagBkClr(COLORREF clr) { m_checkTagBkClr = clr; }

	int GetCheck() const;
	void SetCheck(int nCheck);

	COLORREF GetBkClr() { return m_bkClr; }
	COLORREF GetMainNormalClr() { return m_mainNormalClr; }
	COLORREF GetMainHoverClr() { return m_mainHoverClr; }
	COLORREF GetMainActiveClr() { return m_mainActiveClr; }
	COLORREF GetMainEdgeClr() { return m_mainEdgeClr; }
	COLORREF GetTextNormalClr() { return m_textNormalClr; }
	COLORREF GetTextHoverClr() { return m_textHoverClr; }
	COLORREF GetTextActiveClr() { return m_textActiveClr; }
	COLORREF GetCheckTagClr() { return m_checkTagClr; }
	COLORREF GetCheckTagBkClr() { return m_checkTagBkClr; }

protected:

	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);

	void PreSubclassWindow();
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	virtual void DrawPushButton(CDC* pDC, const CRect& rect, UINT state);
	virtual void DrawCheckBox(CDC* pDC, const CRect& rect, UINT state);
	virtual void DrawRadioButton(CDC* pDC, const CRect& rect, UINT state);
	virtual void DrawTag(CDC* pDC, const CRect& rect, UINT state);
	virtual void DrawText(CDC* pDC, const CRect& rect, UINT state);
	CRect GetTagRect(CDC* pDC, const CRect& rect);

protected:
	COLORREF m_bkClr;
	COLORREF m_mainNormalClr;
	COLORREF m_mainHoverClr;
	COLORREF m_mainActiveClr;
	COLORREF m_mainEdgeClr;
	COLORREF m_textNormalClr;
	COLORREF m_textHoverClr;
	COLORREF m_textActiveClr;
	COLORREF m_checkTagClr;
	COLORREF m_checkTagBkClr;

protected:
	DWORD m_style;
	BOOL m_bCheck;
	BOOL m_bHover;
};