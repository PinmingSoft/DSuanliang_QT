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
	//����б�߶�
	int GetHeight();
	void setRationHeight(double ratioHeight);
	CStringArray m_HChar;
	CString m_Format; //��ʾ�������͵���������,0��ʾ����룬1��ʾ�м���룬2��ʾ�Ҷ���
private:
	double m_ratioHeight;//�����б�߶ȵı���
	int m_nHeight;//�б�߶�
	COLORREF m_Bkcolor;
	COLORREF m_fontColor;
	COLORREF m_linecolor;
	void DrawItem(CRect ClientRect,CDC* dc);
};





