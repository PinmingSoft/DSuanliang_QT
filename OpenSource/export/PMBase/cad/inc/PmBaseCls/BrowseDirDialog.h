// BrowseDirDialog.h: interface for the CBrowseDirDialog class.
//
//
//
//
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BROWSEDIRDIALOG_H__3DFA3A7B_26A8_44D6_BBDB_EC578D7CEE34__INCLUDED_)
#define AFX_BROWSEDIRDIALOG_H__3DFA3A7B_26A8_44D6_BBDB_EC578D7CEE34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//����UI��Ų�������� �����ť;
class PMBASECLASSAPI CBrowseDirDialog  
{
public:
	CBrowseDirDialog();
	virtual ~CBrowseDirDialog();

	int DoBrowse(); 
	CString m_Path; //��ŷ��ص�·����Ϣ 
	CString m_InitDir; //��ʼ��ʾ��·����,Ĭ��Ϊ���� 
	CString m_SelDir; //�򿪶Ի����,Ĭ��ѡ�е�Ŀ¼��,ȱʡΪ��Ŀ¼ 
	CString m_Title; //���öԻ����������Ϣ�ı���,Ĭ��Ϊ"��" 
	int m_ImageIndex; 

};

#endif // !defined(AFX_BROWSEDIRDIALOG_H__3DFA3A7B_26A8_44D6_BBDB_EC578D7CEE34__INCLUDED_)
