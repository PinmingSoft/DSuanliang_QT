#if !defined(AFX_PMTABCTRL_H__BAF6C29E_F4B9_4A64_9563_13505376DD5B__INCLUDED_)
#define AFX_PMTABCTRL_H__BAF6C29E_F4B9_4A64_9563_13505376DD5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PMTabCtrl.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CPMTabCtrl window

class PMBASECLASSAPI CPMTabCtrl : public CTabCtrl
{
// Construction
public:
	CPMTabCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPMTabCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetSize();

	/******************************************************************** 
	 ��������������Tab�ĵ�ǰ��ʾ
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[5/2/2009]
	*********************************************************************/ 
	BOOL SetCurTabSel(int iNum);

// 	/******************************************************************** 
// 	 ������������ִ����InitTabCtrl�� ��ȡ����tab�еĶԻ��� ��С 
// 	 ������
// 	 �� �� ֵ��
// 	 �㷨��
// 	 ע�����Ϊʹ�����Ի��� ����֪�����
// 	 ��    �ߣ�����ҵ
// 	 ʱ    �䣺[5/2/2009]
// 	*********************************************************************/ 
// 	void GetTabCtrlSize(CRect & rect);
	
	/******************************************************************** 
	 �������������� TabCtrl�еĶԻ�����е��� ʹTab��Ӧ����Tab
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[5/2/2009]
	*********************************************************************/ 
	void InitTabCtrl();

	/******************************************************************** 
	 �������������Tabҳ
	 ������
	 �� �� ֵ����ӵ���λ�� -1 ʧ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[5/2/2009]
	*********************************************************************/ 
	int AddPageTab(CDialog_Common * pDialog,CString strTitle);
	virtual ~CPMTabCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPMTabCtrl)
	afx_msg void OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

	CArray<CDialog_Common*,CDialog_Common*&> m_dialogPageArr;
	CStringArray m_tabtitleArr;
	CRect m_rSettingsRect;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PMTABCTRL_H__BAF6C29E_F4B9_4A64_9563_13505376DD5B__INCLUDED_)
