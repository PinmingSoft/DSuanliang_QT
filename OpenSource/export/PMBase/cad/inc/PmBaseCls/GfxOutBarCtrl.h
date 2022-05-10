// Copyright (c) Iuri Apollonio 1998
// Use & modify as you want & need, and leave those 3 lines.
// http://www.codeguru.com

#if !defined(AFX_GFXOUTBARCTRL_H__28FA2CA4_11B7_11D2_8437_0000B43382FE__INCLUDED_)
#define AFX_GFXOUTBARCTRL_H__28FA2CA4_11B7_11D2_8437_0000B43382FE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// GfxOutBarCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGfxOutBarCtrl window

#include <afxcoll.h>

#define WM_OUTBAR_NOTIFY		WM_USER + 1
#define NM_OB_ITEMCLICK			1
#define NM_OB_ONLABELENDEDIT	2
#define NM_OB_ONGROUPENDEDIT	3
#define NM_OB_DRAGITEM			4
#define NM_FOLDERCHANGE			5

#define NM_OB_ITEMRBCLICK		6//右键点击item
#define NM_OB_ITEMMENU			7//

struct OUTBAR_INFO 
{
	int				index;
	const TCHAR *	cText;
	int				iDragFrom;
	int				iDragTo;
};

class PMBASECLASSAPI CGfxOutBarCtrl : public CWnd
{
// Construction
	DECLARE_DYNCREATE(CGfxOutBarCtrl)
public:
	CGfxOutBarCtrl();

	enum {  fSmallIcon = 1 << 0, fLargeIcon = 1 << 1, fEditGroups = 1 << 2, fEditItems = 1 << 3,
			fRemoveGroups = 1 << 4, fRemoveItems = 1 << 5, fAddGroups = 1 << 6, 
			fDragItems = 1 << 7, fAnimation = 1 << 8, fSelHighlight = 1 << 9 };

	enum { ircIcon = 1, ircLabel = 2, ircAll = 3 };

// Attributes
public:
	
	int			iFolderHeight;

	static COLORREF	cr3dFace;
	static COLORREF	crLightBorder;
	static COLORREF	crHilightBorder;
	static COLORREF	crShadowBorder;
	static COLORREF	crDkShadowBorder;

	static COLORREF		crBackGroundColor;
	static COLORREF		crBackGroundColor1;

	static COLORREF		crTextColor;
	static COLORREF		crTextDisableColor;	//不允许选中时的颜色
	static int			xSmallIconLabelOffset;
	static int			yLargeIconLabelOffset;
	static int			ySmallIconSpacing;
	static int			yLargeIconSpacing;

	static int			xLeftMargin;
	static int			yTopMargin;

	bool		bUpArrow, bDownArrow, bUpPressed, bDownPressed;
	CRect		rcUpArrow, rcDownArrow;
	bool		bLooping;

	int			iHitInternal1, iHitInternal2;

	long		lAnimationTickCount;

	int			iLastSel, iSelAnimTiming;
	int			iSelAnimCount;


	DWORD		dwFlags;

	CPtrArray	arFolder;

	int			iLastFolderHighlighted;
	int			iLastSelectedFolder;
	int			iFirstItem;

	int			iLastItemHighlighted;
	bool		bPressedHighlight;

	int			iLastDragItemDraw, iLastDragItemDrawType;

	class PMBASECLASSAPI CBarItemTest
	{
	public:
		
		CBarItemTest(const TCHAR * name, const int image, DWORD exData);
		virtual  ~CBarItemTest();
		int				iImageIndex;
		TCHAR *			cItem;
		DWORD			dwData;
	};

	class CBarFolder
	{
	public:
		CBarFolder(const TCHAR * name, DWORD exData);
		virtual  ~CBarFolder();
		int GetItemCount();
		int InsertItem(int index, const TCHAR * text, const int image, const DWORD exData);

		//是否允许选中
		BOOL IsEnable() const{return m_bEnable;}
		void SetEnable(BOOL bEnable){m_bEnable = bEnable;}

		TCHAR *			cName;
		DWORD			dwData;
		CImageList *	pLargeImageList;
		CImageList *	pSmallImageList;
		CPtrArray		arItems;
		CWnd *			pChild;

	private:
		BOOL m_bEnable;
	};

	int iSelFolder;

	CImageList *	pLargeImageList;
	CImageList *	pSmallImageList;

	HCURSOR			hHandCursor;
	HCURSOR			hDragCursor;
	HCURSOR			hNoDragCursor;

	CPen *			pBlackPen;

// Operations
public:
	enum { htNothing = -1, htFolder, htItem, htUpScroll, htDownScroll};

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGfxOutBarCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawAnimItem(const int xoffset, const int yoffset, const int index);
	void SetAnimSelHighlight(const int iTime);
	DWORD GetFolderData(int iFolder = -1);
	CWnd * GetFolderChild(int iFolder = -1);
	int AddFolderBar(const TCHAR * pFolder, CWnd * pSon, const DWORD exData = 0);

	//设置是否folder允许被选中
	void DisableFolder(const CArray<DWORD,DWORD> & arrFolderDataDisable);

	/**
	* @brief 仅arrFolderDataEnable允许选中，其他都不允许选中
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [3/13/2019]
	*/
	void EnableBarFolderOnly(const CArray<DWORD,DWORD> & arrFolderDataEnable);

	//允许所有folder被选中
	void EnableFolderAll();

	//
	CString GetItemText(const int index);
	void SetAnimationTickCount(const long value) { lAnimationTickCount = value; };
	long GetAnimationTickCount() { return lAnimationTickCount; };

	void AnimateFolderScroll(const int iFrom, const int iTo);
	int GetDragItemRect(const int index, CRect &rect);
	void DrawDragArrow(CDC * pDC, const int iFrom, const int iTo);
	void SetItemImage(const int index, const int iImage);
	void SetItemData(const int index, const DWORD dwData);
	int  GetItemImage(const int index) const;
	DWORD GetItemData(const int index) const;
	bool IsValidItem(const int index) const;
	void RemoveItem(const int index);

	BOOL RemoveAllItem_FolderID(const int iFolderID);

	void SetItemText(const int index, const TCHAR * text);
	void StartItemEdit(const int index);
	void SetFolderText(const int index, const TCHAR * text);
	void StartGroupEdit(const int index);
	void GetLabelRect(const int iFolder, const int iIndex, CRect &rect);
	void GetIconRect(const int iFolder, const int iIndex, CRect &rect);
	void HighlightItem(const int index, const bool bPressed = false);
	void GetVisibleRange(const int iFolder, int &first, int &last);
	void DrawItem(CDC * pDC, const int iFolder, CRect rc, const int index, const bool bOnlyImage = false);
	CImageList * GetFolderImageList(const int index, const bool bSmall) const;
	CSize GetItemSize(const int iFolder, const int index, const int type);
	void PaintItems(CDC * pDC, const int iFolder, CRect rc);
	CImageList * GetImageList(CImageList * pImageList, int nImageList);
	CImageList * SetFolderImageList(const int folder, CImageList * pImageList, int nImageList);
	CImageList * SetImageList(CImageList * pImageList, int nImageList);
	int GetCountPerPage() const;
	void RemoveFolder(const int index);
	int GetSelFolder() const;
	int GetFolderCount() const;
	void SetSelFolder(const int index);
	int GetItemCount() const;
	int InsertItem(const int folder, const int index, const TCHAR * text, const int image = -1, const DWORD exData = 0);
	void HighlightFolder(const int index);
	int HitTestEx(const CPoint &point, int &index);
	void GetInsideRect(CRect &rect) const;
	int AddFolder(const TCHAR * cFolderName, const DWORD exData);
	void GetItemRect(const int iFolder, const int iIndex, CRect &rect);
	bool GetFolderRect(const int iIndex, CRect &rect) const;
	void ModifyFlag(const DWORD &dwRemove, const DWORD &dwAdd, const UINT redraw = 0);
	DWORD GetFlag() const;
	void SetSmallIconView(const bool bSet);
	bool IsSmallIconView() const;
	BOOL Create(DWORD dwStyle, const RECT& rect, CWnd * pParentWnd, UINT nID, const DWORD dwFlag = fDragItems|fEditGroups|fEditItems|fRemoveGroups|fRemoveItems|fAddGroups|fAnimation|fSelHighlight);
	virtual ~CGfxOutBarCtrl();

	LOGFONT m_Fontlf;

	// Generated message map functions
protected:


	void DrawFolder(CDC * pDC, const int iIdx, CRect rect, const bool bSelected);
	//{{AFX_MSG(CGfxOutBarCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg LRESULT OnEndLabelEdit(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GFXOUTBARCTRL_H__28FA2CA4_11B7_11D2_8437_0000B43382FE__INCLUDED_)
