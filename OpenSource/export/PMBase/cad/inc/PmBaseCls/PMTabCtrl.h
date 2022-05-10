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
	 功能描述：设置Tab的当前显示
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[5/2/2009]
	*********************************************************************/ 
	BOOL SetCurTabSel(int iNum);

// 	/******************************************************************** 
// 	 功能描述：在执行完InitTabCtrl后 获取最大的tab中的对话框 大小 
// 	 参数：
// 	 返 回 值：
// 	 算法：
// 	 注意事项：为使容器对话框 可以知道如何
// 	 作    者：王建业
// 	 时    间：[5/2/2009]
// 	*********************************************************************/ 
// 	void GetTabCtrlSize(CRect & rect);
	
	/******************************************************************** 
	 功能描述：进行 TabCtrl中的对话框进行调整 使Tab适应最大的Tab
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[5/2/2009]
	*********************************************************************/ 
	void InitTabCtrl();

	/******************************************************************** 
	 功能描述：添加Tab页
	 参数：
	 返 回 值：添加到的位置 -1 失败
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[5/2/2009]
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
