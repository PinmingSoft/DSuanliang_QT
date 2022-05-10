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
	* @brief  �����Ի���ͷ 
	*
	*          
	* @note  : Ŀǰʹ�ý���ɫ����
	*			int iHeadMode��0������ 1��ѡ�� 2�����
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [15/8/2012]
	*/
	static BOOL DrawOwnHead_FillRect(CDC * pDC,const CRect & rect,HeadDrawMode headMode);

	/**
	* @brief   ��佥��ɫ ����
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [10/9/2012]
	*/
	static BOOL DrawLinearRect(CDC * pDC,const CRect & rect,HeadDrawMode headMode);

	/**
	* @brief ��PngͼƬתΪ bmp�ļ��� H���  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/9/2012]
	*/
	static HBITMAP COwnDrawUI::Png2HBmp(const CString & strFilePath);

	/**
	* @brief  �����Ի����ؼ��� ��ť
	*
	*          
	* @note  : Ŀǰʹ�ý���ɫ����
	*			BOOL bHasPlus��True��չ�� False û��չ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [15/8/2012]
	*/
	static BOOL DrawOwnTreeButten_FillRect(CDC * pDC,const CRect & rect,BOOL bHasPlus);


	/**
	* @brief ���� ��ɫ���ýӿ�
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
	static COLORREF m_OwnheadColorTopLine;//������
	static COLORREF m_OwnheadColorTop;//��������ɫ
	static COLORREF m_OwnheadColorBottom;//�ײ�����ɫ
	static COLORREF m_OwnheadColorBottomLine;//�ײ���

	static COLORREF m_OwnheadSelColorTopLine;//������
	static COLORREF m_OwnheadSelColorTop;//��������ɫ
	static COLORREF m_OwnheadSelColorBottom;//�ײ�����ɫ
	static COLORREF m_OwnheadSelColorBottomLine;//�ײ���

	static COLORREF m_OwnheadDownColorTopLine;//������
	static COLORREF m_OwnheadDownColorTop;//��������ɫ
	static COLORREF m_OwnheadDownColorBottom;//�ײ�����ɫ
	static COLORREF m_OwnheadDownColorBottomLine;//�ײ���

	static COLORREF m_TreeBufferLineColor;//����ť�� ��ɫ

	static COLORREF m_HasChangColColor;//�����仯������ɫ
	static COLORREF m_NoChangeColClr;//û�з����仯����ɫ

protected:

	static BOOL DrawLinearRect_Fun(CDC * pDC,const CRect & rect,HeadDrawMode headMode);

};
