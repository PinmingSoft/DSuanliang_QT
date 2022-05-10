#pragma once

#define FloatCtrlBar_TopSplit		24
#define FloatCtrlBar_BottomSplit	26
#define FloatCtrlBar_WndBottomSplit	32

class PMBASECLASSAPI COwnDrawUI
{
public:
	COwnDrawUI(void);
	~COwnDrawUI(void);

	enum HeadDrawMode
	{
		HeadDraw_Normal = 0,
		HeadDraw_Sel = 1,
		HeadDraw_Down = 2
	};
	/**
	* @brief  用于自绘列头 
	*
	*          
	* @note  : 目前使用渐进色绘制
	*			int iHeadMode：0：正常 1：选中 2：点击
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [15/8/2012]
	*/
	static BOOL DrawOwnHead_FillRect(CDC * pDC,const CRect & rect,HeadDrawMode headMode);

	/**
	* @brief   填充渐进色 区域
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [10/9/2012]
	*/
	static BOOL DrawLinearRect(CDC * pDC,const CRect & rect,HeadDrawMode headMode);

	/**
	* @brief 将Png图片转为 bmp文件的 H句柄  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/9/2012]
	*/
	static HBITMAP COwnDrawUI::Png2HBmp(const CString & strFilePath);

	/**
	* @brief  用于自绘树控件的 按钮
	*
	*          
	* @note  : 目前使用渐进色绘制
	*			BOOL bHasPlus：True被展开 False 没有展开
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [15/8/2012]
	*/
	static BOOL DrawOwnTreeButten_FillRect(CDC * pDC,const CRect & rect,BOOL bHasPlus);


	/**
	* @brief 增加 颜色设置接口
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: pzh
	* @date  : [10/12/2016]
	*/
	static COLORREF SetHeadColorTopLine(COLORREF clr);
	static COLORREF GetHeadColorTopLine();
	static COLORREF SetHeadColorTop(COLORREF clr);
	static COLORREF	GetHeadColorTop();
	static COLORREF SetHeadColorBottom(COLORREF clr);
	static COLORREF GetHeadColorBottom();
	static COLORREF SetHeadColorBottomLine(COLORREF clr);
	static COLORREF GetHeadColorBottomLine();

	static COLORREF SetHeadSelColorTopLine(COLORREF clr);
	static COLORREF GetHeadSelColorTopLine();
	static COLORREF SetHeadSelColorTop(COLORREF clr);
	static COLORREF GetHeadSelColorTop();
	static COLORREF SetHeadSelColorBottom(COLORREF clr);
	static COLORREF GetHeadSelColorBottom();
	static COLORREF SetHeadSelColorBottomLine(COLORREF clr);
	static COLORREF GetHeadSelColorBottomLine();

	static COLORREF SetHeadDownColorTopLine(COLORREF clr);
	static COLORREF GetHeadDownColorTopLine();
	static COLORREF SetHeadDownColorTop(COLORREF clr);
	static COLORREF GetHeadDownColorTop();
	static COLORREF SetHeadDownColorBottom(COLORREF clr);
	static COLORREF GetHeadDownColorBottom();
	static COLORREF SetHeadDownColorBottomLine(COLORREF clr);
	static COLORREF GetHeadDownColorBottomLine();

	static COLORREF SetTreeBufferLineColor(COLORREF clr);
	static COLORREF GetTreeBufferLineColor();

	static COLORREF SetHasChangeColColor(COLORREF clr);
	static COLORREF GetHasChangeColColor();
	static COLORREF SetNoChangeColColor(COLORREF clr);
	static COLORREF GetNoChangeColColor();

//protected:
	static COLORREF m_OwnheadColorTopLine;//顶部线
	static COLORREF m_OwnheadColorTop;//顶部渐变色
	static COLORREF m_OwnheadColorBottom;//底部渐变色
	static COLORREF m_OwnheadColorBottomLine;//底部线

	static COLORREF m_OwnheadSelColorTopLine;//顶部线
	static COLORREF m_OwnheadSelColorTop;//顶部渐变色
	static COLORREF m_OwnheadSelColorBottom;//底部渐变色
	static COLORREF m_OwnheadSelColorBottomLine;//底部线

	static COLORREF m_OwnheadDownColorTopLine;//顶部线
	static COLORREF m_OwnheadDownColorTop;//顶部渐变色
	static COLORREF m_OwnheadDownColorBottom;//底部渐变色
	static COLORREF m_OwnheadDownColorBottomLine;//底部线

	static COLORREF m_TreeBufferLineColor;//树按钮的 颜色

	static COLORREF m_HasChangColColor;//发生变化的行颜色
	static COLORREF m_NoChangeColClr;//没有发生变化行颜色

protected:

	static BOOL DrawLinearRect_Fun(CDC * pDC,const CRect & rect,HeadDrawMode headMode);

};
