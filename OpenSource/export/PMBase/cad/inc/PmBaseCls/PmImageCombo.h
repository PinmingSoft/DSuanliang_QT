#pragma once
#include "atlimage.h"
#include "PmTooltip.h"

/**
 * @brief  :实现了有背景色与图片的自定义combobox
 *
 *          
 * @author :zfy
 * @version:v1.0
 * @date   :[11/27/2017]
 * @note   :
 */
using namespace ATL;
namespace Gdiplus
{
	class Image;
};
class PMBASECLASSAPI CPmImageCombo : public CComboBox
{
	DECLARE_DYNAMIC(CPmImageCombo)

public:
	CPmImageCombo();
	virtual ~CPmImageCombo();

	//设置静止状态下的图片
	void SetNormalImg(const CString& strFilePath);
	//设置移动鼠标到上面后的图片
	void SetHoverImg(const CString& strFilePath);
	//设置活动状态下的图片
	void SetActiveImg(const CString& strFilePath);
	//设置disable状态下的图片
	void SetDisabledImg(const CString& strFilePath);

	//使用tooltip
	void SetToolTip(const CString& strText);

	//设置背景色,用于综合环境颜色用
	void SetColor(COLORREF color);
	COLORREF GetColor();

protected:
	DECLARE_MESSAGE_MAP()
protected:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void CPmImageCombo::MeasureItem(LPMEASUREITEMSTRUCT lpmis);
	void TransparentPNG(CImage *png);
	void DrawItemColor(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void DrawItemImage(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void CPmImageCombo::DrawItemImage(HDC hdc);
	void DrawItemText(LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();

private :
	BOOL m_bHover;
	virtual void PreSubclassWindow();
protected:
	CImage*	m_pNormalImage;	//常态
	CImage*	m_pHoverImage;	//hover
	CImage*	m_pActiveImage;	//按下
	CImage* m_pDisabledImage;	//禁用

	CPmToolTip  * m_pToolTip;	//	在与gdi+对象配合应作为指针，否则崩溃
	CString m_strToolTip;
	COLORREF m_color;
};