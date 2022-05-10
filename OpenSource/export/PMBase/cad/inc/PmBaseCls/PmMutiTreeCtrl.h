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
// 文件说明： 三态树；通过改变图片的形式来实现
//
// 注意说明： 用到这个树的时候，不能打开树的check框
// ***************************************************************


class PMBASECLASSAPI CPmMutiTreeCtrl : public CTreeCtrl
{
//DATA:
protected:
	CImageList	m_ImageList;	//图片
	BOOL		m_bSetMuti;     //是否已经设置好三态树
	BOOL		m_bNeedMutiChoose;//是否需要CheckBox

private:
	HTREEITEM	m_PreSelItem;		//前一个选中的Item
	int			m_nMutiSelectCount;	//表示多选物体的个数，从Item往上找为负数，从Item往下找为正数,不包括Item
// Construction
	
public:
	CPmMutiTreeCtrl();

	enum ESelectStatus
	{
		ess_NoneSel = 0,	//没选
		ess_AllSel = 1,     //全部选中
		ess_SubSel = 2,     //子节点有被选中
	};

//	
// Attributes
public:	
	/******************************************************************** 
	 功能描述：用来设置三态树的图片
	 参    数：
	 返 回 值：
	 算    法：
	 注意事项：只有当m_bSetMuti为假的时候，才进行设置
	 作    者：zll
	 时    间：12/08/2008
	*********************************************************************/ 
	void SetMutiTreeState();

	/******************************************************************** 
	 功能描述：选中所有的节点（根据bSelected来决定）
	 参    数：bSelected 为真的时，全选； 反之，全不选
	 返 回 值：
	 算    法：
	 注意事项：
	 作    者：zll
	 时    间：12/08/2008
	*********************************************************************/ 
	void SelectAllItems(BOOL bSelected = TRUE);

	/**
	* @brief   判断一个节点是否被选中
	*
	*			全选或者部分被选中，则认为被选中，否则被认为没选中
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [12/17/2015]
	*/
	BOOL IsItemSelect(HTREEITEM hItem) const;

	/******************************************************************** 
	 功能描述：重载InsertItem函数
	 参    数：hParentItem父节点，lpszItem新的节点名称， dataItem节点数据
	 返 回 值：新的节点的Item
	 算    法：
	 注意事项：
	 作    者：zll
	 时    间：12/08/2008
	*********************************************************************/ 
	HTREEITEM InsertOwnItem(HTREEITEM hParentItem,  CString strItemName, DWORD_PTR dataItem);

	/******************************************************************** 
	 功能描述：得到三态树节点的状态
	 参    数：ss为返回值
	 返 回 值：ss :0 表示没被选中，1 表示选中， 2 表示该节点的子节点有被选中
	 算    法：
	 注意事项：
	 作    者：zll
	 时    间：12/08/2008
	*********************************************************************/ 
/*	BOOL GetMutiTreeItemState(HTREEITEM hItem, ESelectStatus &ss);*/
	ESelectStatus GetMutiTreeItemState(HTREEITEM hItem) const;
	BOOL SetMutiTreeItemState(HTREEITEM hItem, ESelectStatus ItemState);

	/**
	* @brief   升级父节点状态 ----如果原来为ess_NoneSel，则升为ess_SubSel,如果是其他状态，则返回
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
// 		ess_Size = 3       //state状态个数
// 	};
	
	/**
	* @brief 多选操作
	*
	*          
	* @note  : 
	* @param : itemCountSel 表示多选的个数，如果>0 表示从hItem往下找, <0 表示从hItem往上找
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [5/30/2019]
	*/
	void DoChooseMulti(HTREEITEM hItem,int & itemCountSel);

	//遍历子节点
	void TravelChild(HTREEITEM hItem, int state);
	//遍历父兄节点
	void TravelSiblingAndParent(HTREEITEM hItem, int state);	

public:
	BOOL SetItemSelect(HTREEITEM hItem,BOOL bSelected);

	/**
	* @brief  获取shift多选结果，当DoChooseMulti结束后马上执行才有效
	*
	*          chooseTreeItemArr第一个元素一定是hItemCurrent,下面的元素可能是向上搜索或者向下搜索的结果
	* @note  : 
	* @param : hItemCurrent 表示多选结束时，当前鼠标所在的节点
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [5/30/2019]
	*/
	void GetItemsChooseShift(HTREEITEM hItemCurrent,CArray<HTREEITEM ,HTREEITEM> & chooseTreeItemArr) const;

	/**
	* @brief 仅对子节点统一设置一个状态，不刷新父节点的状态
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
