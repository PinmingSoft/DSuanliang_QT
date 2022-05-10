#pragma once
#include "PmTooltip.h"
/**
* @brief	λͼ��ť
*
*          
* @note  :  
* @param : 
* @defenc: 
* @return: 
* @author: pzh
* @date  : 
*/
namespace Gdiplus
{
	class Image;
};
class PMBASECLASSAPI CImageButton : public CButton
{
	DECLARE_DYNAMIC(CImageButton)

public:
	CImageButton();
	virtual ~CImageButton();

	void SetNormalImg(const CString& strFilePath);
	void SetHoverImg(const CString& strFilePath);
	void SetActiveImg(const CString& strFilePath);
	void SetDisabledImg(const CString& strFilePath);

	//ʹ��tooltip
	void SetToolTip(const CString& strText);

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
private :
	BOOL m_bHover;
	virtual void PreSubclassWindow();
protected:
	Gdiplus::Image*	m_pNormalImage;	//��̬
	Gdiplus::Image*	m_pHoverImage;	//hover
	Gdiplus::Image*	m_pActiveImage;	//����
	Gdiplus::Image* m_pDisabledImage;	//����

	CPmToolTip  * m_pToolTip;	//	����gdi+�������Ӧ��Ϊָ�룬�������
	CString m_strToolTip;
};


/**
* @brief	��ɫ��ť
*
*          
* @note  :  
* @param : 
* @defenc: 
* @return: 
* @author: pzh
* @date  : 
*/
class PMBASECLASSAPI CColorButton : public CButton
{
	DECLARE_DYNAMIC(CColorButton)

public:
	CColorButton();
	virtual ~CColorButton();

	void SetColor(COLORREF color);
	COLORREF GetColor();
	virtual void PreSubclassWindow();
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

protected:
	DECLARE_MESSAGE_MAP()

	COLORREF m_color;
};

class PMBASECLASSAPI CSimColorButton : public CColorButton
{
	DECLARE_DYNAMIC(CSimColorButton)

public:
	CSimColorButton();
	virtual ~CSimColorButton();

	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
protected:
	DECLARE_MESSAGE_MAP()

};