#pragma once

/**
* @brief	�Զ���tooltip
*
*          
* @note  : ĳЩ��ģ̬�Ի����޷���ȡ���������£������ڿؼ���������tooltip
* @param : ��Ҫ��ӵ��tooltip�Ĵ����ﴦ��������� �Ƴ���Ϣ
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

	//����tooltip
	void Create(CWnd* pOwner);

	//��ʾ ����
	void ShowToolTip(CPoint pos, const CString& strText);
	void HideToolTip();

private:
	HWND m_hToolTip;	//tooltip���
	TOOLINFO  m_toolItem;	//tooltip��
};