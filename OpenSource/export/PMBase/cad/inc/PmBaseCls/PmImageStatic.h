#pragma once
#include "afxwin.h"

class PMBASECLASSAPI CPmImageStatic : public CStatic
{
public:

	CPmImageStatic();
	virtual ~CPmImageStatic();

	DECLARE_DYNAMIC(CPmImageStatic)

	void GetPicInfo(int & iPicHeight,int & iPicWidth);
	void SetImagePath(const CString & sImagePath,COLORREF bakCol = RGB(255,255,255));
	const CString& GetImagePath()const;
	void SetColor(COLORREF Col);
	COLORREF GetColor()const;

	DECLARE_MESSAGE_MAP()

	virtual void PreSubclassWindow(); 

	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);


protected:

	int m_iPicHeight;
	int m_iPicWidth;
	//CBitmap * m_pImageBitmap;
	CDC m_memdc;
	BOOL m_bHasInit;
	CString m_strImagePath;
	COLORREF m_clr;
	COLORREF m_bakClr;
};


class PMBASECLASSAPI CPmColorStatic : public CStatic
{
public:

	CPmColorStatic();
	virtual ~CPmColorStatic();

	DECLARE_DYNAMIC(CPmColorStatic)

	void SetColorInfo(const CString & sColorInfo);

	DECLARE_MESSAGE_MAP()

	virtual void PreSubclassWindow(); 

	afx_msg void OnPaint();

protected:

	//CBitmap * m_pImageBitmap;
	CDC m_memdc;
	DWORD m_RBG;
	BOOL m_bHasInit;
};