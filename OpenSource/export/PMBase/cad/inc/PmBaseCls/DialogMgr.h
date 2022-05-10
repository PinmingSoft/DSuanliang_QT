////////////////////////////////////////////
//         ___ ____ _________________     //
//        / _/_  _// _______________/     //
//       / _/ / / / /  ___ ___ ____       //
//      /__/ /_/ / / /   // _/_  _/       //
//     _________/ / / / // _/ / /         //
//  __(c) 1998___/ /___//_/  /_/          //
//                                        //
////////////////////////////////////////////
//          all rights reserved           //
////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CDialogMgr
//
// A class for smart layouting of Dialogs (inspired by GridBagLayout from 
// Java(tm)
//
// USAGE: See DialogMgr.html
//
// AUTHOR: Erwin Tratar <tr@et-soft.de>
//
// LEGAL: You may use and modify this code freely as long (1) this copyright 
// notice remains unmodified (2) you submit all changes to the original
// author (3) give credits to the author in your Documentation or AboutBox
// by adding the following line: "Portions copyright ?998 Erwin Tratar/ET-Soft"
// and (4) mark your changes (so I do not get blamed for your bugs)
//
// LEGAL: THIS SOFTWARE COMES WITH ABSOLUTLY NO WARRANTY NEITHER EXPRESSED NOR
// IMPLIED. USE IT AT YOUR OWN RISK. IN NO WAY SHALL THE AUTHER BE LIABLE FOR
// ANY HARM DONE.

#if !defined(AFX_DIALOGMGR_H__56FCA0C2_E00B_11D1_801B_4854E82A1622__INCLUDED_)
#define AFX_DIALOGMGR_H__56FCA0C2_E00B_11D1_801B_4854E82A1622__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogMgr.h : header file
//
#include <afxtempl.h>

//#ifdef CS_HELP
//
//#	include "CSHelpDialog.h"
//		typedef CCSHelpDialog	CBaseDialog;
//		typedef CCSHelpFormView	CBaseFormView;
//		typedef CCSHelpDlgBar	CBaseDialogBar;
//
//#	else
//		typedef CDialog_Common	CPMBaseDialog;
//		typedef CFormView		CBaseFormView;
//#		ifdef __SBARDLG_H__
//			typedef SECDialogBar	CBaseDialogBar;
//#		else
//			typedef CDialogBar		CBaseDialogBar;
//#	endif
//
//#endif


// Support for Stingray OT SECDialogBar instead of CDialogBar

/**
 * Controls whether the Icon is automatically set to IDR_MAINFRAME
 */
#define _AUTO_SET_ICON
 

/**
 * Use this helper in your derived class as usually
 *
 * example: [MyDerivedClass.h]
 *
 * CMyDerivedClass::CMyDerivedClass()
 * {
 *     WITH_LAYOUT();
 * ...
 *
 * FUNCTION: Connects the layout mechanism to your class
 */
#define DECLARE_LAYOUT()												\
virtual void Layout(CRect& rcClient)									\
	{																	\
		if(rcClient.Height() && rcClient.Width()  && m_pRootPane)		\
			m_pRootPane->resizeTo(rcClient);							\
	}

/**
 * This is a NOOP now
 */
#define IMPLEMENT_LAYOUT()

/**
 * This is the default border size between the panes. You
 * may override it in CPane constructor, but it is the
 * fixed border around the root pane
 */
const int nDefaultBorder	= 5;


/**
 * All (but ABSOLUTE) Items must have at least this height/
 * width
 */
const int nMinConstrain		= 5; 


class PMBASECLASSAPI CLayoutMgr
{
public:
	
	enum {
		GREEDY				= 0,		// Will eat up as much as it can
		ABSOLUTE_HORZ		= 1 << 0,	// Horizontal size is absolute
		RELATIVE_HORZ		= 1 << 1,	// Horizontal size in percent
		ABSOLUTE_VERT		= 1 << 2,	// Vertical size is absolute
		RELATIVE_VERT		= 1 << 3,	// Vertical size in percent

		NORESIZE			= ABSOLUTE_HORZ | ABSOLUTE_VERT,

		SIZE_MASK			= NORESIZE,

		ALIGN_LEFT			= 1 << 4,   // following only for NORESIZE
		ALIGN_RIGHT			= 1 << 5,
		ALIGN_TOP			= 1 << 6,
		ALIGN_BOTTOM		= 1 << 7,

		ALIGN_HCENTER		= ALIGN_LEFT    | ALIGN_RIGHT,	
		ALIGN_VCENTER		= ALIGN_TOP     | ALIGN_BOTTOM,

		ALIGN_CENTER		= ALIGN_HCENTER | ALIGN_VCENTER,

		ALIGN_FILL_HORZ		= 1 << 8,
		ALIGN_FILL_VERT		= 1 << 9,
		ALIGN_FILL			= ALIGN_FILL_HORZ | ALIGN_FILL_VERT,
	
		TRACKER_LEFT		= 1 << 10,
		TRACKER_RIGHT		= 1 << 11,
		TRACKER_TOP			= 1 << 12,
		TRACKER_BOTTOM		= 1 << 13,
	};

	enum layOrientation {
		HORIZONTAL,
		VERTICAL
	};

	/**
	 * This is the base class for all kind of panes. 
	 */
	class PMBASECLASSAPI CPaneBase {
	public:
        //重新设置大小和高度值
		virtual void  ReUpdatePos(){};
		/**
		 * Informs the caller how much of the given space this pane would
		 * like to receive in horizontal direction
		 */
		virtual int		getConstrainHorz(int sizeParent) = 0;


		/**
		 * Informs the caller how much of the given space this pane would
		 * like to receive in vertical direction
		 */
		virtual int		getConstrainVert(int sizeParent) = 0;

		/**
		 * Informs the caller how much of the given space this pane
		 * minimally need. This would be an absolute Value if 
		 * the mode contains ABSOLUTE_HORZ, else nMinConstrain
		 */
		virtual int		getMinConstrainHorz() = 0;
		/**
		 * Informs the caller if there is an restriction for maximum
		 * space this pane needs. Return -1 for unrestricted (GREEDY
		 * or RELATIVE)
		 */
		virtual int		getMaxConstrainHorz() = 0;

		/**
		 * Informs the caller how much of the given space this pane
		 * minimally need. This would be an absolute Value if 
		 * the mode contains ABSOLUTE_VERT, else nMinConstrain
		 */
		virtual int		getMinConstrainVert() = 0;

		/**
		 * Informs the caller if there is an restriction for maximum
		 * space this pane needs. Return -1 for unrestricted (GREEDY
		 * or RELATIVE)
		 */
		virtual int		getMaxConstrainVert() = 0;

		/**
		 * This will do the actual resize operation after the
		 * caller computed a new area for this pane
		 */
		virtual bool	resizeTo(CRect& rcNewArea) = 0;

		/**
		 * Constructor needed pointer to LayoutManager
		 */
		CPaneBase( CLayoutMgr* pMgr )		{ m_pMgr = pMgr; };

		/**
		 * Virtual destructor needed in Container operations
		 */
		virtual ~CPaneBase() {};

		/**
		 * Returs the Resize Mode of this pane
		 */
		DWORD	modeResize() { return m_modeResize; };

	protected:
		/**
		 * How this Item will be resized, a combination of the flags above
		 */
		DWORD	m_modeResize;

		/**
		 * A pointer to the holding LayoutManager derivate
		 */
		CLayoutMgr*		m_pMgr;
	};


	/**
	 * CPaneItem represents a single control
	 */
	class PMBASECLASSAPI CPaneItem : public CPaneBase {
	public:
		/**
		 * Creates a new CPaneItem from an Control. If sizeX or sizeY are 0
		 * and modeResize is ABSOLUTE will copy the current dimensions of
		 * the control to m_sizeX/Y. So the appearance does not change
		 * from the Dialog Editor
		 */
		CPaneItem( CWnd* pWnd, CLayoutMgr* pMgr, DWORD modeResize = GREEDY, int sizeX=0, int sizeY=0, int sizeXMin=0, int sizeYMin=0);

		/**
		 * If your control is not mapped you can name it by its ChildID. Pass
		 * the pMgr to receive the CWnd* of nID. 
		 * The rest as stated above
		 */
		CPaneItem( UINT nID, CLayoutMgr* pMgr, DWORD modeResize = GREEDY, int sizeX=0, int sizeY=0, int sizeXMin=0, int sizeYMin=0);

		/**
		 * see CPaneBase
		 */
		virtual int getConstrainHorz(int sizeParent);
		virtual int getConstrainVert(int sizeParent);
		virtual int getMinConstrainHorz();
		virtual int getMinConstrainVert();
		virtual int	getMaxConstrainHorz();
		virtual int	getMaxConstrainVert();
		virtual bool resizeTo(CRect& rcNewArea);

		bool	isDummy()				{ return (m_hwndCtrl == 0);	}

		//重新设置大小和高度值
		virtual void  ReUpdatePos();
	private:

		/**
		 * The horizontal size of the control (see m_modeResize)
		 */
		int				m_sizeX;
		int				m_sizeXMin;

		/**
		 * The vertical size of the control (see m_modeResize)
		 */
		int				m_sizeY;
		int				m_sizeYMin;

		/**
		 * Child Control pointer
		 */
		HWND			m_hwndCtrl;
	};


	/**
	 * This class encapsulates a Subpane (and indeed the root Pane too)
	 * it is a container of CPaneBase* which it will recursivly resize
	 */
	class PMBASECLASSAPI CPane : public CPaneBase {
	public:

		//重新设置大小和高度值
		virtual void  ReUpdatePos()
		{
			for (int i = 0 ; i < m_paneItems.GetSize() ; i++)
			{
				m_paneItems[i]->ReUpdatePos();
			}
		}

		/**
		 * Tell the pane in which direction it is positioned. A HORIZONTAL pane
		 * arranges it's subpanes from left to right, a VERTICAL from top to bottom
		 */
		CPane( CLayoutMgr* pMgr, layOrientation orientation, int sizeBorder = nDefaultBorder, int sizeExtraBorder = 0 );

		/**
		 * If your control is not mapped you can name it by its ChildID. Pass
		 * the pMgr to receive the CWnd* of nID. 
		 * The rest as stated above
		 */
		bool addItem( UINT nID, DWORD modeResize = GREEDY, int sizeX=0, int sizeY=0, int sizeXMin=0, int sizeYMin=0);

		/**
		 * Creates a new CPaneItem from an Control. If sizeX or sizeY are 0
		 * and modeResize is ABSOLUTE will copy the current dimensions of
		 * the control to m_sizeX/Y. So the appearance does not change
		 * from the Dialog Editor
		 */
		bool addItem( CWnd* pWnd, DWORD modeResize = GREEDY, int sizeX=0, int sizeY=0, int sizeXMin=0, int sizeYMin=0);


		/**
		 * Add a whitespace Item (paneNull) of variable size with
		 * a minimum size of 0
		 */
		bool addGrowing();

		/**
		 * Add a whitespace Item (paneNull) of fixed size based on the
		 * current layout (as in the dialog template). Based on the layout
		 * of the pane vertical or horizontal spacing is considered
		 *
		 * First argument is the left (top) item for a HORIZONTAL (VERTICAL) pane
		 */
		bool addItemSpaceBetween( CWnd* pWndFirst, CWnd* pWndSecond );
		bool addItemSpaceBetween( UINT nIDFirst, UINT nIDSecond );


		/**
		 * Add a whitespace Item (paneNull) of fixed size based on the
		 * size of another item
		 */
		bool addItemSpaceLike( CWnd* pWnd );
		bool addItemSpaceLike( UINT nID );

		/**
		 * Add a SubPane to the pane, appending at the end. You may specify the resize
		 * mode for both directions. If you add modes for the secondary direction
		 * (i.e. *_VERT for a HORIZONTAL pane) then sizeSecondary is used as it's
		 * size. If you do not specify sizeSecondary and the mode is ABSOLUTE_VERT
		 * it will be computed as the maximum Height of all SubPanes (the same is
		 * true for VERTICAL panes and subpanes with *_HORZ)
		 */
		bool addPane( CPane* pSubpane, DWORD modeResize, int sizeSecondary = 0);

		/**
		 * Add an item to the pane, appending at the end. You may specify the resize
		 * mode for both directions. If you add modes for the secondary direction
		 * (i.e. *_VERT for a HORIZONTAL pane) then sizeSecondary is used as it's
		 * size. If you do not specify sizeSecondary and the mode is ABSOLUTE_VERT
		 * it will be computed as the maximum Height of all SubPanes (the same is
		 * true for VERTICAL panes and subpanes with *_HORZ)
		 */
		bool addPane( CPaneBase* pItem );

		virtual int		getConstrainHorz(int sizeParent);
		virtual int		getConstrainVert(int sizeParent);
		virtual int		getMinConstrainHorz();
		virtual int		getMinConstrainVert();
		virtual int		getMaxConstrainHorz();
		virtual int		getMaxConstrainVert();
		virtual bool	resizeTo(CRect& rcNewArea);

		/**
		 * The destructor takes care of destroying all Subpanes and items
		 */
		virtual ~CPane();

		/**
		 * Access to the orientation of this pane
		 */
		layOrientation	getOrientation() { return m_Orientation; };

	protected:
		/**
		 * The orientation of the pane. Keep in mind that all subpanes
		 * must have the complementary orientation, i.e. a VERTICAL
		 * pane must have all HORIZONTAL SubPanes (or normal Items
		 * of course)
		 */
		layOrientation					m_Orientation;

		/**
		 * This array holds the pointers to the Items/SubPanes
		 */
		CArray<CPaneBase*,CPaneBase*>	m_paneItems;

		/**
		 * The secondary constrain
		 */
		int				m_sizeSecondary;

		/** 
		 * Size of gap between childs
		 */
		int				m_sizeBorder;
		int				m_sizeExtraBorder;
	};


	/**
	 * This class encapsulates a Subpane which is a Tab
	 * it will use calls to AdjustRect to position it's
	 * childs
	 */
	class PMBASECLASSAPI CPaneTab : public CPane
	{
	public:
		/**
		 * Tell the pane in which direction it is positioned. A HORIZONTAL pane
		 * arranges it's subpanes from left to right, a VERTICAL from top to bottom
		 */
		CPaneTab( CTabCtrl* pTab, CLayoutMgr* pMgr, layOrientation orientation, int sizeBorder = nDefaultBorder, int sizeExtraBorder = 0 );

		virtual int		getConstrainHorz(int sizeParent);
		virtual int		getConstrainVert(int sizeParent);
		virtual int		getMinConstrainHorz();
		virtual int		getMinConstrainVert();
		virtual int		getMaxConstrainHorz();
		virtual int		getMaxConstrainVert();
		virtual bool	resizeTo(CRect& rcNewArea);

	private:
		CTabCtrl* m_pTab;
	};

	/**
	 * This class encapsulates a Subpane which is a Static
	 * it will use calls to AdjustRect to position it's
	 * childs
	 */
	class PMBASECLASSAPI CPaneCtrl : public CPane
	{
	public:
		/**
		 * Tell the pane in which direction it is positioned. A HORIZONTAL pane
		 * arranges it's subpanes from left to right, a VERTICAL from top to bottom
		 */
		CPaneCtrl( CWnd* pCtrl, CLayoutMgr* pMgr, layOrientation orientation, int sizeBorder = nDefaultBorder, int sizeExtraBorder = 0, int sizeTopExtra = 0);
		CPaneCtrl( UINT nID, CLayoutMgr* pMgr, layOrientation orientation, int sizeBorder = nDefaultBorder, int sizeExtraBorder = 0, int sizeTopExtra = 0 );

		virtual int		getConstrainHorz(int sizeParent);
		virtual int		getConstrainVert(int sizeParent);
		virtual int		getMinConstrainHorz();
		virtual int		getMinConstrainVert();
		virtual int		getMaxConstrainHorz();
		virtual int		getMaxConstrainVert();
		virtual bool	resizeTo(CRect& rcNewArea);

	private:
		HWND			m_hwndCtrl;
		int				m_sizeTopExtra;
	};

			//重新设置大小和高度值
	void  ReUpdatePos()
	{
		m_pRootPane->ReUpdatePos();
	}

	CLayoutMgr(CWnd* pWnd)	{ m_pWnd = pWnd; m_sizeRootBorders = CSize(5,5); };
	virtual CRect GetRect() { CRect r; m_pWnd->GetClientRect(r); return r; };
	CWnd*	m_pWnd;
	CWnd*	GetWnd()		{ return m_pWnd; };
	void	setRootBorders(int cx, int cy)	{ m_sizeRootBorders = CSize(cx,cy); };

	/**
	 * Pass this for a pseudo Pane with no content
	 */
	static CWnd*	paneNull;

	/**
	 * Loads the current position and size from the registry using a supplied
	 * key. Will be loaded with AfxGetApp()->WriteProfileXXX(). You may
	 * specify a subfolder (e.g. Load( _T("MyDialog\\Layout") ); ). Will
	 * load the following keys:
	 *
	 * - lpstrRegKey+"SizeX";
	 * - lpstrRegKey+"SizeY";
	 * - lpstrRegKey+"PosX";
	 * - lpstrRegKey+"PosY";
	 *
	 * Is automatically called during OnActivate() if key specified in
	 * constructor.
	 */
	bool Load(LPCTSTR lpstrRegKey);

	/**
	 * Store the current position and size to the registry using a supplied
	 * key. Will be stored with AfxGetApp()->WriteProfileXXX(). You may
	 * specify a subfolder (e.g. Save( _T("MyDialog\\Layout") ); ). Will
	 * create the following keys:
	 *
	 * - lpstrRegKey+"SizeX";
	 * - lpstrRegKey+"SizeY";
	 * - lpstrRegKey+"PosX";
	 * - lpstrRegKey+"PosY";
	 *
	 * Is automatically called during DestroyWindow() if key specified in
	 * constructor.
	 */
	bool Save(LPCTSTR lpstrRegKey);

	/**
	 * Updates the layout after you specify the new
	 * layout
	 */
	void UpdateLayout();

	/**
	 * Does the actual Layout, called from OnSize()
	 * Default implementation does nothing, use
	 * IMPLEMENT_LAYOUT in your derived class (see above)
	 */
	virtual void Layout(CRect& rcClient);


	/**
	 * This holds the root pane. Fill in InitDialog()
	 */
	CPane* m_pRootPane;

	/**
	 * Key in Registry where to store Size
	 */
	CString m_strRegStore;

	/**
	 * Borders around root
	 */
	CSize	m_sizeRootBorders;
};

/**
 * Base class for the Layout function. Derive your own class
 * from this or derive it from CDialog and modify _all_
 * references to CDialog to CDialogMgr
 */
class PMBASECLASSAPI CDialogMgr : public CDialog_Common, protected CLayoutMgr
{
	DECLARE_DYNAMIC(CDialogMgr)
// Construction
public:
	CDialogMgr(UINT nID, CWnd* pParent = NULL, LPCTSTR strName = NULL, bool bGripper = true);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogMgr)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogMgr)
	public:
	virtual BOOL DestroyWindow();
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDialogMgr)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	virtual CRect GetRect();
	CStatic		m_wndSizeIcon;		// the icon control
	CBitmap		m_bmSizeIcon;		// the bitmap
	bool		m_bGripper;
};


class PMBASECLASSAPI CFormViewMgr : public CFormView, public CLayoutMgr
{
// Construction
	DECLARE_DYNAMIC(CFormViewMgr)
public:
	CFormViewMgr(UINT nID, LPCTSTR strName = NULL);   // standard constructor
	virtual ~CFormViewMgr();

// Dialog Data
	//{{AFX_DATA(CDialogMgr)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogMgr)
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDialogMgr)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/**
 * Base class for the Layout function. Derive your own class
 * from this or derive it from SECDialogBar/CDialogBar and 
 * modify _all_  references to SECDialogBar/CDialogBar to 
 * CDialogBarMgr
 */
class PMBASECLASSAPI CDialogBarMgr : public CDialogBar, protected CLayoutMgr
{
// Construction
public:
#ifdef CS_HELP
	CDialogBarMgr(UINT nID);
#else
	CDialogBarMgr();
#endif

// Dialog Data
	//{{AFX_DATA(CDialogBarMgr)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogBarMgr)
	virtual CSize CalcDynamicLayout(int nLength, DWORD dwMode);
	//}}AFX_VIRTUAL

	/**
	 * Override this to define Layout
	 */
	virtual BOOL Initialize() { return false; };

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDialogBarMgr)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	virtual CRect GetRect();
	bool	m_bInitialized;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGMGR_H__56FCA0C2_E00B_11D1_801B_4854E82A1622__INCLUDED_)
