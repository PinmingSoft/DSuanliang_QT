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
 * @brief MFC�Ի���Ļ���
 *
 *        �ڲ���װ����Ҫ���������λس����رնԻ��� ���ܡ�
 *			04/15/2010������Ի�����Դ �Զ��л�����
 *					(��ʱ ������)ԭ�������������⣺
 *							1�������޸ĺ󣬶������ĶԻ��򣬴�����������ˣ���Ϊ���Ĺ��� ���ڱ�ģ���� ִ�У�
 *								�ڶԻ������� ��ʹ����һģ��� dllInstance��
 *							2��Ӱ��� �Ի��� ̫�࣬����û���װ�������
 * @author ����ҵ
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
	* @brief   �����ӿؼ���С��ʹ�������Ի���һ������.�Ի����OnSize�ڲ����� 
	*
	*			
	* @note  : 
	* @param : nID Ϊ�ؼ�id
	* @param : cx Ϊ���Ի����width
	* @param : cy Ϊ���Ի����height
	* @param : dRadioLeft Ϊԭʼ�Ŀؼ�x���������Ի����width�ı���
	* @param : dRadioTop Ϊԭʼ�Ŀؼ�y���������Ի����height�ı���
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

//	HINSTANCE m_hdllInstance;//���� �Ի������ڵ� DLL�� ʵ�������ڶԻ���� ��Դ�л���
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_COMMON_H__B3EBFC06_6F02_44F5_A0AF_8D7EF8BB2A7B__INCLUDED_)
