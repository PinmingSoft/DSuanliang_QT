#pragma once
#include <atlimage.h>

class PMBASECLASSAPI CPngStatic : public CStatic
{
	// ��׼���캯��
public:
	CPngStatic();
	virtual ~CPngStatic();

typedef struct _TRATRAPNGINFO_
{
	int nWidth;
	int nHeight;
	CImage*  pImg;
}TRAPNGINFO;

public:
	//���ã����뱳��ͼ
	void Load(UINT IDBkGroup,int width=0, int height=0, const CString& resourceType = _T("PNG"));
	//���ã�����Ӧ����ͼ
	void SetAutoSize(bool bAutoSize);
protected:
	//�ػ�
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
protected:
	//{{AFX_MSG(CPngStatic)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	TRAPNGINFO		m_btninfoNor;				//Normalʱ��ͼƬ
	bool			m_bHot;						//�Ƿ�ΪHot
	bool			m_bPress;					//�Ƿ���
	bool			m_bAutoSize;				//�Զ���Ӧ
private:
	//��ͼ
	void DrawBK(HDC dc, CImage* img);
	//д��
	void DrawBtnText(HDC dc, const CString& strText, int nMove);
	//�ı䰴ť���
	virtual void PreSubclassWindow();
};