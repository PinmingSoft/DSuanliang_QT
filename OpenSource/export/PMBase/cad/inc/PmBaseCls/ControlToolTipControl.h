// ControlToolTipControl.h: interface for the CControlToolTipControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROLTOOLTIPCONTROL_H__7CC9A9D8_7EA8_4B53_AB30_3C5B5C89D0EA__INCLUDED_)
#define AFX_CONTROLTOOLTIPCONTROL_H__7CC9A9D8_7EA8_4B53_AB30_3C5B5C89D0EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PMBASECLASSAPI CControlToolTipControl  
{
public:
	CControlToolTipControl();
	virtual ~CControlToolTipControl();
	void SetTooltipText(LPCTSTR lpszText, BOOL bActivate = TRUE);
	virtual CWnd* GetToolTipParentWnd() = 0;
protected:
	void InitToolTip();
	CToolTipCtrl m_ToolTip;			// Tooltip
};

#endif // !defined(AFX_CONTROLTOOLTIPCONTROL_H__7CC9A9D8_7EA8_4B53_AB30_3C5B5C89D0EA__INCLUDED_)
