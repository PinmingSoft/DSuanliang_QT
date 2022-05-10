#if !defined(AFX_DIALOG_COMMON_H__B3EBFC06_6F02_44F5_A0AF_8D7EF8BB2A7B__INCLUDED_)
#define AFX_DIALOG_COMMON_H__B3EBFC06_6F02_44F5_A0AF_8D7EF8BB2A7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog_Common.h : header file
//
//#include "../StdArx.h"
/////////////////////////////////////////////////////////////////////////////
// CDialog_Common dialog
/**
 * @brief MFC对话框的基类
 *
 *        内部包装的主要操作，屏蔽回车键关闭对话框 功能。
 *			04/15/2010：加入对话框资源 自动切换功能
 *					(暂时 先屏蔽)原因遇到如下问题：
 *							1、这样修改后，对引出的对话框，处理就有问题了，因为他的构造 不在本模块中 执行，
 *								在对话框构造中 会使用另一模块的 dllInstance。
 *							2、影响的 对话框 太多，心里没有谱啊。。。
 * @author 王建业
 * @version v1.0
 * @date  04/15/2010
 * @note  
 */

class KERNELBASECLASS_API CDialog_Common : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Common)
// Construction
public:
	CDialog_Common(UINT nID,CWnd* pParent = NULL/*,HINSTANCE hdllInstance = _hdllInstance*/);   // standard constructor

	virtual void SetSize(){};
	
	virtual BOOL OnParentOK(){return FALSE;};
// Dialog Data
	//{{AFX_DATA(CDialog_Common)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_Common)
	//}}AFX_VIRTUAL

	//virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	//virtual BOOL Create(UINT nIDTemplate, CWnd* pParentWnd = NULL);

	//virtual INT_PTR DoModal();

// Implementation
protected:
	/**
	* @brief   重置子控件大小，使其与主对话框一起缩放.对话框的OnSize内部调用 
	*
	*			
	* @note  : 
	* @param : nID 为控件id
	* @param : cx 为主对话框的width
	* @param : cy 为主对话框的height
	* @param : dRadioLeft 为原始的控件x坐标与主对话框的width的比率
	* @param : dRadioTop 为原始的控件y坐标与主对话框的height的比率
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [1/2/2018]
	*/
	void ChangeSize(UINT nID
		, int cx
		, int cy
		, double dRadioLeft
		, double dRadioRight
		, double dRadioTop
		, double dRadioBottom) const;

	// Generated message map functions
	//{{AFX_MSG(CDialog_Common)
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg HBRUSH OnCtlColor(CDC *pDC,CWnd *pWnd,UINT nCtlColor);
	//}}AFX_MSG
private:
	DECLARE_MESSAGE_MAP()

	BOOL m_bEnableClose;

//	HINSTANCE m_hdllInstance;//保存 对话框所在的 DLL的 实例（用于对话框的 资源切换）
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_COMMON_H__B3EBFC06_6F02_44F5_A0AF_8D7EF8BB2A7B__INCLUDED_)
