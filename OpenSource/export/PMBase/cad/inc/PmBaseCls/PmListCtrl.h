#pragma once
// CPmListCtrl

class PMBASECLASSAPI CPmListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CPmListCtrl)

public:
	CPmListCtrl();
	virtual ~CPmListCtrl();

	//设置行高
	void SetRowHeight(int nRowHeight);

	//设置checkbox大小
	void SetSize_CheckBox(int nSizeCheckBox){m_nSize_CheckBox = nSizeCheckBox;}

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();

	//
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);

private:
	// 行高
	int m_nRowHeight;

	// checkbox大小
	int m_nSize_CheckBox;
};


