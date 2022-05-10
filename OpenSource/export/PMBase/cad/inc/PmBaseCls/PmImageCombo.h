#pragma once
#include "atlimage.h"
#include "PmTooltip.h"

/**
 * @brief  :ʵ�����б���ɫ��ͼƬ���Զ���combobox
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

	//���þ�ֹ״̬�µ�ͼƬ
	void SetNormalImg(const CString& strFilePath);
	//�����ƶ���굽������ͼƬ
	void SetHoverImg(const CString& strFilePath);
	//���û״̬�µ�ͼƬ
	void SetActiveImg(const CString& strFilePath);
	//����disable״̬�µ�ͼƬ
	void SetDisabledImg(const CString& strFilePath);

	//ʹ��tooltip
	void SetToolTip(const CString& strText);

	//���ñ���ɫ,�����ۺϻ�����ɫ��
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
	CImage*	m_pNormalImage;	//��̬
	CImage*	m_pHoverImage;	//hover
	CImage*	m_pActiveImage;	//����
	CImage* m_pDisabledImage;	//����

	CPmToolTip  * m_pToolTip;	//	����gdi+�������Ӧ��Ϊָ�룬�������
	CString m_strToolTip;
	COLORREF m_color;
};