#pragma once
// CPmListCtrl

class PMBASECLASSAPI CPmListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CPmListCtrl)

public:
	CPmListCtrl();
	virtual ~CPmListCtrl();

	//�����и�
	void SetRowHeight(int nRowHeight);

	//����checkbox��С
	void SetSize_CheckBox(int nSizeCheckBox){m_nSize_CheckBox = nSizeCheckBox;}

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();

	//
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);

private:
	// �и�
	int m_nRowHeight;

	// checkbox��С
	int m_nSize_CheckBox;
};


