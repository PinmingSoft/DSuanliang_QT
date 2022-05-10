#pragma once


// CHeaderColor
class PMBASECLASSAPI CHeaderColor : public CHeaderCtrl
{
	DECLARE_DYNAMIC(CHeaderColor)

public:
	CHeaderColor();
	virtual ~CHeaderColor();

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg LRESULT OnLayout( WPARAM wParam, LPARAM lParam );
public:
	void setBgColor(COLORREF bKColor,COLORREF fontColor,COLORREF lineColor);
	//获得列表高度
	int GetHeight();
	void setRationHeight(double ratioHeight);
	CStringArray m_HChar;
	CString m_Format; //表示对齐类型的整型数组,0表示左对齐，1表示中间对齐，2表示右对齐
private:
	double m_ratioHeight;//重置列表高度的比率
	int m_nHeight;//列表高度
	COLORREF m_Bkcolor;
	COLORREF m_fontColor;
	COLORREF m_linecolor;
	void DrawItem(CRect ClientRect,CDC* dc);
};





