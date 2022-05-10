#pragma once

/**
* @brief	自定义tooltip
*
*          
* @note  : 某些非模态对话框无法获取焦点的情况下，可以在控件里包含这个tooltip
* @param : 需要在拥有tooltip的窗口里处理鼠标移入 移出消息
* @defenc: 
* @return: 
* @author: pzh
* @date  : 
*/

class PMBASECLASSAPI CPmToolTip
{
public:
	CPmToolTip();
	~CPmToolTip();

	//创建tooltip
	void Create(CWnd* pOwner);

	//显示 隐藏
	void ShowToolTip(CPoint pos, const CString& strText);
	void HideToolTip();

private:
	HWND m_hToolTip;	//tooltip句柄
	TOOLINFO  m_toolItem;	//tooltip项
};