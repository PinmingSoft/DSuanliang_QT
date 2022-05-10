#pragma once


// CFindEdit

class PMBASECLASSAPI CFindEdit : public CEdit
{
	DECLARE_DYNAMIC(CFindEdit)

public:
	CFindEdit();
	virtual ~CFindEdit();
private:
	BOOL m_bTracking;
	BOOL m_bHover;
	BOOL m_bFocus;
	HBRUSH m_BorderInBrush;
	HBRUSH m_BorderOutBrush;
// 	HBRUSH m_ClientBrush;
// 	HBRUSH m_hOrderBrush;
// 	HBRUSH m_HotOrderBrush1;
// 	HBRUSH m_HotOrderBrush2;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnNcPaint();
	afx_msg void OnPaint();

	void SetBorderInColor( COLORREF clr );
	void SetBorderOutColor( COLORREF clr );

private:
	//绘制非客户区边框
	void DrawBorder();
};


 