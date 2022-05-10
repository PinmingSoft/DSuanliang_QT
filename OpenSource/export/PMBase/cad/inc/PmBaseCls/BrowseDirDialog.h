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

//从主UI中挪动过来的 浏览按钮;
class PMBASECLASSAPI CBrowseDirDialog  
{
public:
	CBrowseDirDialog();
	virtual ~CBrowseDirDialog();

	int DoBrowse(); 
	CString m_Path; //存放返回的路径信息 
	CString m_InitDir; //初始显示的路径名,默认为桌面 
	CString m_SelDir; //打开对话框后,默认选中的目录名,缺省为根目录 
	CString m_Title; //设置对话框中浏览信息的标题,默认为"打开" 
	int m_ImageIndex; 

};

#endif // !defined(AFX_BROWSEDIRDIALOG_H__3DFA3A7B_26A8_44D6_BBDB_EC578D7CEE34__INCLUDED_)
