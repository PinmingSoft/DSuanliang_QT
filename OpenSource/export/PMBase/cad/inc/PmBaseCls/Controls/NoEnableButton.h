#pragma once
//����ť�ؼ� Ĭ���û�ʱ��������Ӱ ����ͨ��setUseEnable��������
//TURE ʹ���ûұ��� FALSE ��ʹ��

#include "BtnST.h"
// CNoEnableButton

class PMBASECLASSAPI CNoEnableButton : public CButtonST
{
	DECLARE_DYNAMIC(CNoEnableButton)

public:
	CNoEnableButton();
	virtual ~CNoEnableButton();

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);

	//�����Ƿ�ʹ��ϵͳ�����ûұ���
	void SetUseEnable(BOOL bUseEnable);

	//���ñ߿���ɫ
	void SetFrameColor(COLORREF clr);

	//��ȡ�߿���ɫ
	COLORREF GetFrameColor(){return m_FrameColor;};
protected:

	//�Ƿ�ʹ��ϵͳ�����������ûұ�ʶ
	BOOL		m_bUseEnable;
	COLORREF	m_FrameColor;
	DECLARE_MESSAGE_MAP()
};


