#if !defined(AFX_DIALOGCONTAINER_H__4D8E80D0_1281_4138_B31E_58CEE621C681__INCLUDED_)
#define AFX_DIALOGCONTAINER_H__4D8E80D0_1281_4138_B31E_58CEE621C681__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogContainer.h : header file
//

/**
 * @brief ����һ���Ի���Ŀؼ����԰ѶԻ�����Ϊһ���ӿؼ�����
 *
 *            ��ϸ����
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
	* @brief  �������öԻ����λ�ã�����ʾ���� 
	*
	*          
	* @note  : �������˶Ի���֮��Ӧ��ִ��һ�β���ʹ�Ի�����ʾ
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
	* @brief   ���öԻ���ؼ����Ի���Ӧ����ʹ��ָ�룬���Ѿ������ã����ฺ���ͷ����ڴ�
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

	/// �Ƴ��Ի���ֻ���Ի�����ΪNULL���Ƴ��߸����ͷŶԻ���
	CDialog* RemoveDialog();
	
	/// �ͷŶԻ���
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

/// ����OnOK\OnCancel�ĶԻ����࣬��ֹ���û����˻س���escʱ���Ի�����ʧ������CDialogContainerû����ʾ�Ի���
/// ���õ�CDialogContainer�ϵĶԻ������Ӵ���̳У������Լ�����OnOK\OnCancel
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
