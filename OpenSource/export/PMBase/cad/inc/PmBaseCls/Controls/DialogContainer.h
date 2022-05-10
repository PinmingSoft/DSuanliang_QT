#if !defined(AFX_DIALOGCONTAINER_H__4D8E80D0_1281_4138_B31E_58CEE621C681__INCLUDED_)
#define AFX_DIALOGCONTAINER_H__4D8E80D0_1281_4138_B31E_58CEE621C681__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogContainer.h : header file
//

/**
 * @brief 放置一个对话框的控件，以把对话框作为一个子控件处理
 *
 *            详细描述
 * @author lvxm
 * @version v1.0
 * @date  04/15/2010
 * @note  
 */

/////////////////////////////////////////////////////////////////////////////
// CDialogContainer window

class PMBASECLASSAPI CDialogContainer : public CStatic
{
// Construction
public:
	CDialogContainer();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogContainer)
	//}}AFX_VIRTUAL

// Implementation
public:

	/**
	* @brief  重新设置对话框的位置，并显示出来 
	*
	*          
	* @note  : 在设置了对话框之后应该执行一次才能使对话框显示
	* @param : 
	* @defenc: 
	* @return: 
	* @retval: 
	*        - 
	* @retval: 
	*        - 
	* @author: lvxm
	* @date  : [15/9/2011]
	*/
	void RecalLayout();

	/**
	* @brief   设置对话框控件，对话框应该是使用指针，并已经创建好，本类负责释放其内存
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @retval: 
	*        - 
	* @retval: 
	*        - 
	* @author: lvxm
	* @date  : [15/9/2011]
	*/
	void SetDialog(CDialog* pDlg);

	CDialog* GetDialog() const;

	/// 移除对话框，只将对话框设为NULL，移除者负责释放对话框
	CDialog* RemoveDialog();
	
	/// 释放对话框
	void Release();

	virtual ~CDialogContainer();

	// Generated message map functions
protected:
	virtual void PreSubclassWindow();
	//{{AFX_MSG(CDialogContainer)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	CDialog* m_pDialog;
};

/// 重载OnOK\OnCancel的对话框类，防止被用户按了回车或esc时，对话框消失而导致CDialogContainer没法显示对话框
/// 放置到CDialogContainer上的对话框尽量从此类继承，或者自己重载OnOK\OnCancel
class PMBASECLASSAPI COkCancelDialog : public CDialog  
{
public:
	COkCancelDialog();
	virtual ~COkCancelDialog();

	COkCancelDialog(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	COkCancelDialog(UINT nIDTemplate, CWnd* pParentWnd = NULL);

protected:
	virtual void OnOK();
	virtual void OnCancel();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGCONTAINER_H__4D8E80D0_1281_4138_B31E_58CEE621C681__INCLUDED_)
