#pragma once


#include "HeaderColor.h"
#include "map"
using namespace  std;
struct ITEM_DATA 
{
	//��ά�е�����
	CRect cenRect;
	int nCenSelected;//��ά�й�ѡ�����̬���
	int nCenImage;
	
	//��ά�е�����
	CRect rect3D;
	int n3DSelected;//��ά�й�ѡ�����̬���
	int n3DImage;
	BOOL bDraw3D;//�Ƿ������ά��ͼ��
	
	//���һ������
	CRect lastRect;
	int nLastSelected;
	int nLastImage;
	int iDrawName;//�Ƿ�������һ�еĹ�ѡͼ��
	BOOL bIsZW;//�Ƿ�������

	//��һ�е�����
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
	CImageList	m_ImageList;	//ͼƬ
	BOOL		m_bSetMuti;     //�Ƿ��Ѿ����ú���̬��
	BOOL		m_bNeedMutiChoose;//�Ƿ���ҪCheckBox

private:
	HTREEITEM	m_PreSelItem;		//ǰһ��ѡ�е�Item
	int			m_nMutiSelectCount;	//��ʾ��ѡ����ĸ�������Item������Ϊ��������Item������Ϊ����,������Item

	HTREEITEM	m_PreSel3DItem;		//������ά�У�ǰһ��ѡ�е�Item��shift��ѡʱ���
	int         m_n3DSelectCount;   //��ʾ��ѡ����ĸ�����shift��ѡ����ά�е���Ŀ
// Construction
	
public:
	CListTree();

	enum ESelectStatus
	{
		ess_NoneSel = 0,	//ûѡ
		ess_AllSel = 1,     //ȫ��ѡ��
		ess_SubSel = 2,     //�ӽڵ��б�ѡ��
	};
	enum ClickStatus
	{
		colFirst =0,   //���������
		col2D = 1,	  //�����ά��ͼ��
		col3D = 2,    //�����άͼ��
		colName = 3,  //�������ͼ��
		colNULL = 4,  //����Ĳ�������λ��
	};

//	
// Attributes
public:	
	
	 //��������������������̬����ͼƬ
	void SetMutiTreeState();

	//����������ѡ�����еĽڵ㣨����bSelected��������
	void SelectAllItems(BOOL bSelected = TRUE);
	void SelectAll3DItems(BOOL bSelected = TRUE);
	void SelectAllLastItems(BOOL bSelected = TRUE);

	 //�ж�һ���ڵ��Ƿ�ѡ��
	BOOL IsItemSelect(HTREEITEM hItem) const;
	BOOL IsItem3DSelect(HTREEITEM hItem) const;
	BOOL IsItemLastSelect(HTREEITEM hItem) const;

	//�õ���̬���ڵ��״̬
    //�� �� ֵ��ss :0 ��ʾû��ѡ�У�1 ��ʾѡ�У� 2 ��ʾ�ýڵ���ӽڵ��б�ѡ��
	ESelectStatus GetTreeItemState(HTREEITEM hItem) const;
	ESelectStatus GetTree3DState(HTREEITEM hItem) const;
	ESelectStatus GetTreeLastState(HTREEITEM hItem) const;

	
	//�������ڵ�״̬ ----���ԭ��Ϊess_NoneSel������Ϊess_SubSel,���������״̬���򷵻�
	void UpgradeParentCheckState(HTREEITEM hItem,BOOL b3D=FALSE);
	void UpgradeParentLastCheckState(HTREEITEM hItem);
protected:

	void DoChooseMulti(HTREEITEM hItem,int & itemCountSel,BOOL b3D=FALSE);

	//�����ӽڵ�
	void TravelChild(HTREEITEM hItem, int state,BOOL b3D=FALSE);
	void TravelLastChild(HTREEITEM hItem, int state);
	//�������ֽڵ�
	void TravelSiblingAndParent(HTREEITEM hItem, int state,BOOL b3D=FALSE);	
	void TravelSiblingAndParentLast(HTREEITEM hItem, int state);	

public:
	BOOL SetItemSelect(HTREEITEM hItem,BOOL bSelected,BOOL b3D=FALSE);
	BOOL SetItemSelectLast(HTREEITEM hItem,BOOL bSelected);

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
	//��ά�в���ʱ���shift��ѡ
	void Get3DItemsChooseShift(HTREEITEM hItemCurrent,CArray<HTREEITEM ,HTREEITEM> & chooseTreeItemArr) const;

	//�����ӽڵ�ͳһ����һ��״̬����ˢ�¸��ڵ��״̬
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
	map<HTREEITEM,ITEM_DATA*> m_mapItemData;          //ĳһ��ľ��<--->ĳһ���Ӧ���ı���Icon
	CImageList m_pIconList;                         //�����ǰ�����չͼƬICON
	void DrawItemText(CDC * pDC,HTREEITEM pItem,CRect Rect);
	enum ExpandStatus
	{
		ess_NoneExpand = 0,	//ûѡ ����ǰ��+��
		ess_Expand = 1,     //�����չ�����ǰ�����
	};
protected:
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
public:
	void SetExpendTreeImg();//������ǰ�����չͼƬ
	//������
	void InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat=0, int nWidth=-1, int nSubItem=-1);
	void UpdateColumns();
	void ChangeHeadColumns();
	
	void SetHeaderHeight(int cyHeader);
	int GetHeaderHeight();
	CHeaderColor& GetHeaderCtrl() { return m_Header; }

	//�����ػ������
	HTREEITEM InsertItemMuti(const HTREEITEM & hParentItem, const HTREEITEM &hInsertAfter , CString strName,DWORD_PTR dValue,int iCenImg,int i3DImg,int iLastImg);
    BOOL GetItemCenImg(HTREEITEM hItem, int& nImage, int& nSelectedImage) const;//��ȡ��ά��ͼ����̬���
	BOOL SetItemCenImg(HTREEITEM hItem, int nImage,int nSelectedImage);
	BOOL SetCenRect(HTREEITEM hItem, CRect cenRect);//��ȡ��ά������
	BOOL GetCenRect(HTREEITEM hItem, CRect &cenRect) const;

	//��ά��
	BOOL Set3DRect(HTREEITEM hItem, CRect rect3D);
	BOOL Get3DRect(HTREEITEM hItem, CRect &rect3D) const;
	BOOL SetItem3DImg(HTREEITEM hItem, int nImage,int nSelectedImage);
	BOOL GetItem3DImg(HTREEITEM hItem, int& nImage, int& nSelectedImage) const;

	//����У����ƣ�
	BOOL GetLastRect(HTREEITEM hItem, CRect &lastRect) const;
	BOOL SetLastRect(HTREEITEM hItem, CRect lastRect);
	BOOL SetItemLastImg(HTREEITEM hItem, int nImage,int nSelectedImage);
	BOOL GetItemLastImg(HTREEITEM hItem, int& nImage, int& nSelectedImage) const;

	//�Ƿ����������ͼ��
	BOOL SetNameEffect(HTREEITEM hItem,int iDrawName);
	BOOL GetNameEffect(HTREEITEM hItem,int &iDrawName)const;
	//�Ƿ������ά��ͼ��
	BOOL Set3DEffect(HTREEITEM hItem,BOOL bDraw3D);
	BOOL Get3DEffect(HTREEITEM hItem,BOOL &bDraw3D)const;

	BOOL GetFirstRect(HTREEITEM hItem, CRect &firstRect) const;//��ȡ����������
	BOOL SetFirstRect(HTREEITEM hItem, CRect firstRect);

	//���������ǰ���⣬���ñ���ɫ
	void SetBgColor(COLORREF& clr,COLORREF& fontClr,COLORREF& LineClr);
	void SetHeaderBKColor(COLORREF bKColor,COLORREF fontColor,COLORREF lineColor); 
	//���ص��������һ�� ,1��ά�У�2��ά�У�3������
	ClickStatus GetHitColum(HTREEITEM hItem,CPoint point)const;
private:

	CHeaderColor m_Header;
	enum{MAX_COLUMN_COUNT=4}; // �������
	int m_arrColWidths[MAX_COLUMN_COUNT];
	int m_cyHeader;
	COLORREF m_BKclr;//������ɫ
	COLORREF m_fontClr;//������ɫ
	COLORREF m_LineClr;//�������ɫ

	void DrawItem(CRect ClientRect,CDC* pDC);
	void DrawBackGround(CRect ClientRect,CDC* pDC);
	void DrawLine(CRect forRect,CRect cenRect,CRect rect3D,CRect LastRect,CDC* pDC,CPen* edgePen);
};

