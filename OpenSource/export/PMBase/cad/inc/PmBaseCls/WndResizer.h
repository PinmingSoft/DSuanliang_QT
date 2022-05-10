#if !defined(_WNDRESIZER_H_)
#define _WNDRESIZER_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define ANCHOR_LEFT                   1
#define ANCHOR_TOP                    2
#define ANCHOR_RIGHT                  4
#define ANCHOR_BOTTOM                 8
#define ANCHOR_HORIZONTALLY_CENTERED  16
#define ANCHOR_VERTICALLY_CENTERED    32
#define ANCHOR_PRIORITY_RIGHT         64   // by defualt, left has higher priority
#define ANCHOR_PRIORITY_BOTTOM        128  // by defualt, top has higher priority
#define ANCHOR_VERTICALLY             (ANCHOR_TOP | ANCHOR_BOTTOM)
#define ANCHOR_HORIZONTALLY           (ANCHOR_LEFT | ANCHOR_RIGHT)
#define ANCHOR_ALL                    (ANCHOR_VERTICALLY | ANCHOR_HORIZONTALLY)

static const int SPLITTER_MIN_WIDTH = 1; // for vertical, it is the height

#define DWLP_MSGRESULT  0
#define DWLP_DLGPROC    DWLP_MSGRESULT + sizeof(LRESULT)
#define DWLP_USER       DWLP_DLGPROC + sizeof(DLGPROC)
#define GET_X_LPARAM(lp)                        ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp)                        ((int)(short)HIWORD(lp))

class PMBASECLASSAPI CWndResizer 
{
public:
	CWndResizer(void);
	~CWndResizer(void);
public:
	
	class CPanel;
	typedef CList<CPanel *, CPanel *> CPanelList;
	typedef enum tagPanelType 
	{
		// panel hasen't been identified yet
		NONE, 
			// top most level panel. the client area of the window that is used when called the Hook method.
			// all other panels are direct or indicrect child of this one.
			ROOT, 
			// a panel (could be inside another panel). can contain other panel or UI control
			PANEL, 
			// the area of the splitter panel where mouse pointer changes to a resizeable arrow
			SPLITTER,
			// a horizontal splitter container panel
			SPLITTER_CONTAINER_H,
			// a vertical splitter contianer panel
			SPLITTER_CONTAINER_V, 
			// left or right ( or top or bottom ) panel of a splitter container
			SPLITTER_PANEL,
			// a panel that contains a child window (of the hooked window). cannot contain other panel inside this
			UI_CONTROL
	} PanelType;
	
	class CPanel : public CRect
	{
	public:
		CPanel();
		CPanel(const CRect * prc);
		~CPanel();
		PanelType Type;
		virtual void OnResized();
		virtual BOOL AddChild(CPanel * prc);
		UINT Anchor;
		CString Name;
		CPanel * Parent;
		CPanelList Children;
		int LeftEdge;
		int TopEdge;
		int RightEdge;
		int BottomEdge; 
		CSize MinSize;
		CSize MaxSize;
		BOOL SetMinSize(CSize & size);
		BOOL SetMaxSize(CSize & size);
		void Init();
	};
	
	class CSplitterContainer : public CPanel
	{
	public:
		CSplitterContainer(CPanel * pLeftPanel, CPanel * pRightPanel, PanelType type);
		~CSplitterContainer();
		virtual void OnResized();
		virtual BOOL AddChild(CPanel * prc);
		void RepositionSplitter(int leftOfSpliter /* or topOfSpliter if vertical */);
		
		static PanelType GetSplitterType(const CRect * prcA, const CRect * prcB);
		
	private:
		double m_nRatio;
		int m_nSplitterSize; // for horizontal, it is the splitter width, otherwise it is the splitter height
		
		void UpdateSplitArea();
		int GetSplitterSize(CPanel * pLeftPanel, CPanel * pRightPanel, PanelType type);
		void ResizeImmidiateChildrenOnly();
		void UpdateRatio();
	};
	
	class CUIPanel : public CPanel
	{
	public:
		CUIPanel(CWnd * pWnd, const CRect * prc, UINT uID);
		CUIPanel(CWnd * pWnd, const CRect * prc, CWnd * pUIWnd);
		~CUIPanel();
		virtual void OnResized();
		UINT m_uID;
		CWnd * m_pUIWnd;
		BOOL m_bUseMode;//TRUE:使用m_uID FALSE：使用m_pUIWnd
	private:
		CWnd * m_pWnd;
	};
	
	public:
		
		CString IdToName(UINT uID);
		CString WndToName(CWnd * pWnd);

		BOOL SetAnchor(LPCTSTR panelName, UINT anchor);
		BOOL SetAnchor(UINT panelID, UINT anchor);

		/******************************************************************** 
		功能描述：SetAnchor可以用 Wnd指针 创建 Panel
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2011:1:8]   9:11
		*********************************************************************/ 
		BOOL SetAnchor(CWnd * pUIWnd, UINT anchor);

		UINT GetAnchor(LPCTSTR panelName);
		UINT GetAnchor(UINT panelID);
		
		BOOL SetParent(LPCTSTR panelName, LPCTSTR parentName);
		BOOL SetParent(UINT panelID, LPCTSTR parentName);
		BOOL SetParent(CWnd * pUIWnd, LPCTSTR parentName);

		BOOL SetParent(LPCTSTR panelName, UINT parentID);
		BOOL SetParent(UINT panelID, UINT parentID);
		CString GetParent(LPCTSTR panelName);
		CString GetParent(UINT panelID);
		
		BOOL SetMinimumSize(LPCTSTR panelName, CSize & size);
		BOOL SetMinimumSize(UINT panelID, CSize & size);
		CSize GetMinimumSize(LPCTSTR panelName) ;
		CSize GetMinimumSize(UINT panelID) ;
		
		BOOL SetMaximumSize(LPCTSTR panelName, CSize & size);
		BOOL SetMaximumSize(UINT panelID, CSize & size);
		CSize GetMaximumSize(LPCTSTR panelName) ;
		CSize GetMaximumSize(UINT panelID) ;
		
		
		void SetShowResizeGrip(BOOL show = TRUE);
		BOOL GetShowResizeGrip();
		BOOL Hook(CWnd * pWnd);
		BOOL Unhook();
		
		BOOL CreatePanel(LPCTSTR panelName, const CRect * prcPanel);
		
		BOOL CreateSplitterPanel(LPCTSTR panelName, LPCTSTR panelNameA, LPCTSTR panelNameB);    
		BOOL CreateSplitterPanel(LPCTSTR panelName, LPCTSTR panelNameA, UINT panelIDB);  
		BOOL CreateSplitterPanel(LPCTSTR panelName, UINT panelIDA, UINT panelIDB);  
		BOOL CreateSplitterPanel(LPCTSTR panelName, UINT panelIDA, LPCTSTR panelNameB);  
		
		BOOL InvokeOnResized();
		
	private:
		
		BOOL m_bShowResizeGrip;
		
		CWnd * m_pHookedWnd;
		CPanel root;
		CPanel * pCaptured;
		HCURSOR hOldCursor;
		int splitterOffset;  
		
		void OnPaint();
		void OnSize(UINT nType, int cx, int cy);
		void OnSizing(UINT fwSide, LPRECT pRect);
		void OnDestroy();
		void OnLButtonDown(UINT nFlags, CPoint point);
		void OnMouseMove(UINT nFlags, CPoint point);
		void OnLButtonUp(UINT nFlags, CPoint point);
		
		CWndResizer::CPanel * FindContainerByName(CWndResizer::CPanel * pRoot, LPCTSTR name);
		CWndResizer::CPanel * FindSplitterFromPoint(CWndResizer::CPanel * pRoot, CPoint point);
		
		UINT GetValidAnchor(UINT requestedAnchor);
		BOOL RemoveFromHierarchy(CPanel * pPanel);
		CWndResizer::CUIPanel * CreateUIPanel(UINT uID);

		/******************************************************************** 
		功能描述：CreateUIPanel 可以用 Wnd指针 创建 Panel
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2011:1:8]   9:11
		*********************************************************************/ 
		CWndResizer::CUIPanel * CreateUIPanel(CWnd * pUIWnd);

		CWndResizer::CUIPanel * GetUIPanel(UINT uID);
		
		void UpdateSplitterOffset(CPoint ptCurr);
		
		WNDPROC m_pfnWndProc;
		LONG_PTR m_pPrevUserData;
		static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		
};

#endif

   
