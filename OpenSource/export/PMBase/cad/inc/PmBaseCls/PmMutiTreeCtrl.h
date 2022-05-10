#if !defined(AFX_PMMUTITREECTRL_H__55FD3769_7D85_440F_8669_71247A89C714__INCLUDED_)
#define AFX_PMMUTITREECTRL_H__55FD3769_7D85_440F_8669_71247A89C714__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PmMutiTreeCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPmMutiTreeCtrl window
// ***************************************************************
//  PmMutiTreeCtrl   version:  1.0   ? date: 12/05/2008
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2008 - All Rights Reserved
// ***************************************************************
// �ļ�˵���� ��̬����ͨ���ı�ͼƬ����ʽ��ʵ��
//
// ע��˵���� �õ��������ʱ�򣬲��ܴ�����check��
// ***************************************************************


class PMBASECLASSAPI CPmMutiTreeCtrl : public CTreeCtrl
{
//DATA:
protected:
	CImageList	m_ImageList;	//ͼƬ
	BOOL		m_bSetMuti;     //�Ƿ��Ѿ����ú���̬��
	BOOL		m_bNeedMutiChoose;//�Ƿ���ҪCheckBox

private:
	HTREEITEM	m_PreSelItem;		//ǰһ��ѡ�е�Item
	int			m_nMutiSelectCount;	//��ʾ��ѡ����ĸ�������Item������Ϊ��������Item������Ϊ����,������Item
// Construction
	
public:
	CPmMutiTreeCtrl();

	enum ESelectStatus
	{
		ess_NoneSel = 0,	//ûѡ
		ess_AllSel = 1,     //ȫ��ѡ��
		ess_SubSel = 2,     //�ӽڵ��б�ѡ��
	};

//	
// Attributes
public:	
	/******************************************************************** 
	 ��������������������̬����ͼƬ
	 ��    ����
	 �� �� ֵ��
	 ��    ����
	 ע�����ֻ�е�m_bSetMutiΪ�ٵ�ʱ�򣬲Ž�������
	 ��    �ߣ�zll
	 ʱ    �䣺12/08/2008
	*********************************************************************/ 
	void SetMutiTreeState();

	/******************************************************************** 
	 ����������ѡ�����еĽڵ㣨����bSelected��������
	 ��    ����bSelected Ϊ���ʱ��ȫѡ�� ��֮��ȫ��ѡ
	 �� �� ֵ��
	 ��    ����
	 ע�����
	 ��    �ߣ�zll
	 ʱ    �䣺12/08/2008
	*********************************************************************/ 
	void SelectAllItems(BOOL bSelected = TRUE);

	/**
	* @brief   �ж�һ���ڵ��Ƿ�ѡ��
	*
	*			ȫѡ���߲��ֱ�ѡ�У�����Ϊ��ѡ�У�������Ϊûѡ��
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [12/17/2015]
	*/
	BOOL IsItemSelect(HTREEITEM hItem) const;

	/******************************************************************** 
	 ��������������InsertItem����
	 ��    ����hParentItem���ڵ㣬lpszItem�µĽڵ����ƣ� dataItem�ڵ�����
	 �� �� ֵ���µĽڵ��Item
	 ��    ����
	 ע�����
	 ��    �ߣ�zll
	 ʱ    �䣺12/08/2008
	*********************************************************************/ 
	HTREEITEM InsertOwnItem(HTREEITEM hParentItem,  CString strItemName, DWORD_PTR dataItem);

	/******************************************************************** 
	 �����������õ���̬���ڵ��״̬
	 ��    ����ssΪ����ֵ
	 �� �� ֵ��ss :0 ��ʾû��ѡ�У�1 ��ʾѡ�У� 2 ��ʾ�ýڵ���ӽڵ��б�ѡ��
	 ��    ����
	 ע�����
	 ��    �ߣ�zll
	 ʱ    �䣺12/08/2008
	*********************************************************************/ 
/*	BOOL GetMutiTreeItemState(HTREEITEM hItem, ESelectStatus &ss);*/
	ESelectStatus GetMutiTreeItemState(HTREEITEM hItem) const;
	BOOL SetMutiTreeItemState(HTREEITEM hItem, ESelectStatus ItemState);

	/**
	* @brief   �������ڵ�״̬ ----���ԭ��Ϊess_NoneSel������Ϊess_SubSel,���������״̬���򷵻�
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/20/2019]
	*/
	void UpgradeParentCheckState(HTREEITEM hItem);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPmMutiTreeCtrl)
	//}}AFX_VIRTUAL

// Implementation
	
protected:
	
// 	enum {
// 		ess_Size = 3       //state״̬����
// 	};
	
	/**
	* @brief ��ѡ����
	*
	*          
	* @note  : 
	* @param : itemCountSel ��ʾ��ѡ�ĸ��������>0 ��ʾ��hItem������, <0 ��ʾ��hItem������
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [5/30/2019]
	*/
	void DoChooseMulti(HTREEITEM hItem,int & itemCountSel);

	//�����ӽڵ�
	void TravelChild(HTREEITEM hItem, int state);
	//�������ֽڵ�
	void TravelSiblingAndParent(HTREEITEM hItem, int state);	

public:
	BOOL SetItemSelect(HTREEITEM hItem,BOOL bSelected);

	/**
	* @brief  ��ȡshift��ѡ�������DoChooseMulti����������ִ�в���Ч
	*
	*          chooseTreeItemArr��һ��Ԫ��һ����hItemCurrent,�����Ԫ�ؿ��������������������������Ľ��
	* @note  : 
	* @param : hItemCurrent ��ʾ��ѡ����ʱ����ǰ������ڵĽڵ�
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [5/30/2019]
	*/
	void GetItemsChooseShift(HTREEITEM hItemCurrent,CArray<HTREEITEM ,HTREEITEM> & chooseTreeItemArr) const;

	/**
	* @brief �����ӽڵ�ͳһ����һ��״̬����ˢ�¸��ڵ��״̬
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [5/16/2019]
	*/
	void SetChildItemSelectOnly(HTREEITEM hItemParent,BOOL bSelected);
	
	virtual ~CPmMutiTreeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPmMutiTreeCtrl)
		// NOTE - the ClassWizard will add and remove member functions here.
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PMMUTITREECTRL_H__55FD3769_7D85_440F_8669_71247A89C714__INCLUDED_)
