#pragma once
#include <atlimage.h>

typedef enum TRA_BTNSTATE{//��ť״̬
	TRA_BTN_NOR,
	TRA_BTN_HOT,
	TRA_BTN_PRE,
	TRA_BTN_DIS
};

typedef struct _TRATRAPNGINFO_
{
	int nWidth;
	int nHeight;
	CImage*  pImg;
}TRAPNGINFO;


class PMBASECLASSAPI CPngButton : public CButton
{
	// ��׼���캯��
public:
	CPngButton();
	virtual ~CPngButton();

public:
	//���ã����뱳��ͼ
	void Load(UINT IDBkGroup,int width=0, int height=0, const CString& resourceType = _T("PNG"));
	//���ã�����Ӧ����ͼ
	void SetAutoSize(bool bAutoSize);
	//���óߴ�,�����Ͻǵ�Ϊ��׼��
	void SetSize(int nWidth,int nHeight);
	//���Ʊ߽�
	void SetDrawBorder(bool bDrawBorder);
protected:
	//�ػ�
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
protected:
	//{{AFX_MSG(CPngButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	TRAPNGINFO		m_btninfoNor;				//Normalʱ��ͼƬ
	TRAPNGINFO		m_btninfoHot;				//Hotʱ��ͼƬ
	TRAPNGINFO		m_btninfoPre;				//Pressʱ��ͼƬ
	TRAPNGINFO		m_btninfoDis;				//Disableʱ��ͼƬ
	bool			m_bHot;						//�Ƿ�ΪHot
	bool			m_bPress;					//�Ƿ���
	bool			m_bAutoSize;				//�Զ���Ӧ
private:
	//��ͼ
	void DrawBK(HDC dc, CImage* img,TRA_BTNSTATE btnstate);
	//д��
	void DrawBtnText(HDC dc, const CString& strText, int nMove, TRA_BTNSTATE btnstate);
	//�ͷ�ͼƬ
	void ReleaseImg();
	//�ı䰴ť���
	virtual void PreSubclassWindow();
};