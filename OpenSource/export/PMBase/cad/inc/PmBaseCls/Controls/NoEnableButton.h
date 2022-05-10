#pragma once
//本按钮控件 默认置灰时无文字重影 可以通过setUseEnable进行设置
//TURE 使用置灰表现 FALSE 不使用

#include "BtnST.h"
// CNoEnableButton

class PMBASECLASSAPI CNoEnableButton : public CButtonST
{
	DECLARE_DYNAMIC(CNoEnableButton)

public:
	CNoEnableButton();
	virtual ~CNoEnableButton();

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);

	//设置是否使用系统自用置灰表现
	void SetUseEnable(BOOL bUseEnable);

	//设置边框颜色
	void SetFrameColor(COLORREF clr);

	//获取边框颜色
	COLORREF GetFrameColor(){return m_FrameColor;};
protected:

	//是否使用系统不可用文字置灰标识
	BOOL		m_bUseEnable;
	COLORREF	m_FrameColor;
	DECLARE_MESSAGE_MAP()
};


