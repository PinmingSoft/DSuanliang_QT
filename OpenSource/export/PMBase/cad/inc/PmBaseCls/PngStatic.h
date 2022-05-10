#pragma once
#include <atlimage.h>

class PMBASECLASSAPI CPngStatic : public CStatic
{
	// 标准构造函数
public:
	CPngStatic();
	virtual ~CPngStatic();

typedef struct _TRATRAPNGINFO_
{
	int nWidth;
	int nHeight;
	CImage*  pImg;
}TRAPNGINFO;

public:
	//作用：载入背景图
	void Load(UINT IDBkGroup,int width=0, int height=0, const CString& resourceType = _T("PNG"));
	//作用：自适应背景图
	void SetAutoSize(bool bAutoSize);
protected:
	//重绘
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
protected:
	//{{AFX_MSG(CPngStatic)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	TRAPNGINFO		m_btninfoNor;				//Normal时的图片
	bool			m_bHot;						//是否为Hot
	bool			m_bPress;					//是否按下
	bool			m_bAutoSize;				//自动适应
private:
	//绘图
	void DrawBK(HDC dc, CImage* img);
	//写字
	void DrawBtnText(HDC dc, const CString& strText, int nMove);
	//改变按钮风格
	virtual void PreSubclassWindow();
};