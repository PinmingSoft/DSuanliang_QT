#pragma once


#include "HeaderColor.h"
#include "map"
using namespace  std;
struct ITEM_DATA 
{
	//二维列的区域
	CRect cenRect;
	int nCenSelected;//二维列勾选框的三态标记
	int nCenImage;
	
	//三维列的区域
	CRect rect3D;
	int n3DSelected;//三维列勾选框的三态标记
	int n3DImage;
	BOOL bDraw3D;//是否绘制三维列图标
	
	//最后一列区域
	CRect lastRect;
	int nLastSelected;
	int nLastImage;
	int iDrawName;//是否绘制最后一列的勾选图标
	BOOL bIsZW;//是否是轴网

	//第一列的区域
	CRect firstRect;
	ITEM_DATA()
	{
		nCenSelected = 0;
		nCenImage = 0;
		cenRect.top=0;
		cenRect.bottom=0;
		cenRect.left=0;
		cenRect.right=0;

		n3DSelected=0;
		n3DImage=0;
		rect3D.top=0;
		rect3D.bottom=0;
		rect3D.left=0;
		rect3D.right=0;
		bDraw3D = TRUE;

		nLastSelected = 0;
		nLastImage = 0;
		lastRect.top=0;
		lastRect.bottom=0;
		lastRect.left=0;
		lastRect.right=0;

		iDrawName = 0;
		bIsZW = FALSE;
		firstRect.top=0;
		firstRect.bottom=0;
		firstRect.left=0;
		firstRect.right=0;

	}
};
class PMBASECLASSAPI CListTree : public CTreeCtrl
{
//DATA:
protected:
	CImageList	m_ImageList;	//图片
	BOOL		m_bSetMuti;     //是否已经设置好三态树
	BOOL		m_bNeedMutiChoose;//是否需要CheckBox

private:
	HTREEITEM	m_PreSelItem;		//前一个选中的Item
	int			m_nMutiSelectCount;	//表示多选物体的个数，从Item往上找为负数，从Item往下找为正数,不包括Item

	HTREEITEM	m_PreSel3DItem;		//操作三维列，前一个选中的Item，shift多选时标记
	int         m_n3DSelectCount;   //表示多选物体的个数，shift多选，三维列的数目
// Construction
	
public:
	CListTree();

	enum ESelectStatus
	{
		ess_NoneSel = 0,	//没选
		ess_AllSel = 1,     //全部选中
		ess_SubSel = 2,     //子节点有被选中
	};
	enum ClickStatus
	{
		colFirst =0,   //点击类型列
		col2D = 1,	  //点击二维列图标
		col3D = 2,    //点击二维图标
		colName = 3,  //点击名称图标
		colNULL = 4,  //点击的不是以上位置
	};

//	
// Attributes
public:	
	
	 //功能描述：用来设置三态树的图片
	void SetMutiTreeState();

	//功能描述：选中所有的节点（根据bSelected来决定）
	void SelectAllItems(BOOL bSelected = TRUE);
	void SelectAll3DItems(BOOL bSelected = TRUE);
	void SelectAllLastItems(BOOL bSelected = TRUE);

	 //判断一个节点是否被选中
	BOOL IsItemSelect(HTREEITEM hItem) const;
	BOOL IsItem3DSelect(HTREEITEM hItem) const;
	BOOL IsItemLastSelect(HTREEITEM hItem) const;

	//得到三态树节点的状态
    //返 回 值：ss :0 表示没被选中，1 表示选中， 2 表示该节点的子节点有被选中
	ESelectStatus GetTreeItemState(HTREEITEM hItem) const;
	ESelectStatus GetTree3DState(HTREEITEM hItem) const;
	ESelectStatus GetTreeLastState(HTREEITEM hItem) const;

	
	//升级父节点状态 ----如果原来为ess_NoneSel，则升为ess_SubSel,如果是其他状态，则返回
	void UpgradeParentCheckState(HTREEITEM hItem,BOOL b3D=FALSE);
	void UpgradeParentLastCheckState(HTREEITEM hItem);
protected:

	void DoChooseMulti(HTREEITEM hItem,int & itemCountSel,BOOL b3D=FALSE);

	//遍历子节点
	void TravelChild(HTREEITEM hItem, int state,BOOL b3D=FALSE);
	void TravelLastChild(HTREEITEM hItem, int state);
	//遍历父兄节点
	void TravelSiblingAndParent(HTREEITEM hItem, int state,BOOL b3D=FALSE);	
	void TravelSiblingAndParentLast(HTREEITEM hItem, int state);	

public:
	BOOL SetItemSelect(HTREEITEM hItem,BOOL bSelected,BOOL b3D=FALSE);
	BOOL SetItemSelectLast(HTREEITEM hItem,BOOL bSelected);

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
	//三维列操作时候的shift多选
	void Get3DItemsChooseShift(HTREEITEM hItemCurrent,CArray<HTREEITEM ,HTREEITEM> & chooseTreeItemArr) const;

	//仅对子节点统一设置一个状态，不刷新父节点的状态
	void SetChildItemSelectOnly(HTREEITEM hItemParent,BOOL bSelected);
	//void SetChildItemSelectOnlyLast(HTREEITEM hItemParent,BOOL bSelected);
	
	virtual ~CListTree();
protected:
	//{{AFX_MSG(CPmMutiTreeCtrl)
		// NOTE - the ClassWizard will add and remove member functions here.
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	map<HTREEITEM,ITEM_DATA*> m_mapItemData;          //某一项的句柄<--->某一项对应的文本和Icon
	CImageList m_pIconList;                         //存放树前面的扩展图片ICON
	void DrawItemText(CDC * pDC,HTREEITEM pItem,CRect Rect);
	enum ExpandStatus
	{
		ess_NoneExpand = 0,	//没选 ，树前面+号
		ess_Expand = 1,     //点击扩展子项，树前面减号
	};
protected:
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
public:
	void SetExpendTreeImg();//设置树前面的扩展图片
	//插入例
	void InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat=0, int nWidth=-1, int nSubItem=-1);
	void UpdateColumns();
	void ChangeHeadColumns();
	
	void SetHeaderHeight(int cyHeader);
	int GetHeaderHeight();
	CHeaderColor& GetHeaderCtrl() { return m_Header; }

	//插入重绘风格的树
	HTREEITEM InsertItemMuti(const HTREEITEM & hParentItem, const HTREEITEM &hInsertAfter , CString strName,DWORD_PTR dValue,int iCenImg,int i3DImg,int iLastImg);
    BOOL GetItemCenImg(HTREEITEM hItem, int& nImage, int& nSelectedImage) const;//获取二维列图标三态标记
	BOOL SetItemCenImg(HTREEITEM hItem, int nImage,int nSelectedImage);
	BOOL SetCenRect(HTREEITEM hItem, CRect cenRect);//获取二维列区域
	BOOL GetCenRect(HTREEITEM hItem, CRect &cenRect) const;

	//三维列
	BOOL Set3DRect(HTREEITEM hItem, CRect rect3D);
	BOOL Get3DRect(HTREEITEM hItem, CRect &rect3D) const;
	BOOL SetItem3DImg(HTREEITEM hItem, int nImage,int nSelectedImage);
	BOOL GetItem3DImg(HTREEITEM hItem, int& nImage, int& nSelectedImage) const;

	//最后列（名称）
	BOOL GetLastRect(HTREEITEM hItem, CRect &lastRect) const;
	BOOL SetLastRect(HTREEITEM hItem, CRect lastRect);
	BOOL SetItemLastImg(HTREEITEM hItem, int nImage,int nSelectedImage);
	BOOL GetItemLastImg(HTREEITEM hItem, int& nImage, int& nSelectedImage) const;

	//是否绘制名称列图标
	BOOL SetNameEffect(HTREEITEM hItem,int iDrawName);
	BOOL GetNameEffect(HTREEITEM hItem,int &iDrawName)const;
	//是否绘制三维列图标
	BOOL Set3DEffect(HTREEITEM hItem,BOOL bDraw3D);
	BOOL Get3DEffect(HTREEITEM hItem,BOOL &bDraw3D)const;

	BOOL GetFirstRect(HTREEITEM hItem, CRect &firstRect) const;//获取类型列区域
	BOOL SetFirstRect(HTREEITEM hItem, CRect firstRect);

	//根据软件当前主题，设置背景色
	void SetBgColor(COLORREF& clr,COLORREF& fontClr,COLORREF& LineClr);
	void SetHeaderBKColor(COLORREF bKColor,COLORREF fontColor,COLORREF lineColor); 
	//返回点击的是哪一列 ,1二维列，2三维列，3名称列
	ClickStatus GetHitColum(HTREEITEM hItem,CPoint point)const;
private:

	CHeaderColor m_Header;
	enum{MAX_COLUMN_COUNT=4}; // 最大行数
	int m_arrColWidths[MAX_COLUMN_COUNT];
	int m_cyHeader;
	COLORREF m_BKclr;//背景颜色
	COLORREF m_fontClr;//字体颜色
	COLORREF m_LineClr;//表格线颜色

	void DrawItem(CRect ClientRect,CDC* pDC);
	void DrawBackGround(CRect ClientRect,CDC* pDC);
	void DrawLine(CRect forRect,CRect cenRect,CRect rect3D,CRect LastRect,CDC* pDC,CPen* edgePen);
};

