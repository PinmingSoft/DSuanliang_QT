// PMFileDialog.h: interface for the CPMFileDialog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMFILEDIALOG_H__3E4CBD30_C897_4C04_8F81_E075CA848129__INCLUDED_)
#define AFX_PMFILEDIALOG_H__3E4CBD30_C897_4C04_8F81_E075CA848129__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPMFileDialog : public CFileDialog
{
	DECLARE_DYNAMIC(CPMFileDialog)

public:
	CString m_strExt;//文件扩展名
	BOOL m_bEnableCancel;//TRUE：，FALSE：是否屏蔽取消键

	int FindFolder_CurFold(CListCtrl* plc,CString strFileText);

	const CString & GetPMFolderPath()
	{
		return m_strFolderPath;
	}

	void SetPMFolderPath(const CString & strFolderPath)
	{
		m_strFolderPath = strFolderPath;
	}

	const CString & GetPMFolderName()
	{
		return m_strSelFolderName;
	}

	void SetPMFolderName(const CString & strFolderName)
	{
		m_strSelFolderName = strFolderName;
	}

	const CString & GetPMCoverFolderMsg()
	{
		return m_strCoverFolderMsg;
	}

	BOOL GetPMCoverFolderMode()
	{
		return m_bCoverFolder;
	}

	void SetPMCoverFolderMsg(const CString & strCoverFolderMsg)
	{
		m_strCoverFolderMsg = strCoverFolderMsg;
		m_bCoverFolder = TRUE;
	}



	static WNDPROC m_wndProc;
	virtual void OnInitDone( );

	CPMFileDialog(BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL);

protected:
	CString m_strFolderPath;//覆盖文件夹时，文件路径
	CString m_strSelFolderName;//选中的文件夹名称
	BOOL m_bCoverFolder;//TRUE:提示覆盖文件夹；FALSE：不提示
	CString m_strCoverFolderMsg;//提示文字；
	//CString m_SelComboText;

	//{{AFX_MSG(CPMFileDialog)
	virtual BOOL OnInitDialog();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class PMBASECLASSAPI CPMFileDialogEx 
{
public:
	typedef struct FileDialogInfo
	{
		FileDialogInfo()
		{
			bOpenMode = TRUE;
			bCoverFolder = FALSE;
			strCoverFolderMsg = _T("");
			strCaption = _T("");
			strDefDir = _T("");
			strExt = _T("");
			strlimitName = _T("");
			bEnableCancel = TRUE;
			strFileName = _T("") ;
			hParent = NULL;
		}
		BOOL bOpenMode;//TRUE：打开模式，FALSE：另存为
		BOOL bCoverFolder;//TRUE:提示覆盖文件夹；FALSE：不提示
		CString strCoverFolderMsg;//提示文字
		CString strCaption;//标题名称
		CString strDefDir;//默认文件夹位置
		LPCTSTR strFilter;// = "品茗钢筋算量用户文件(*.ld)\0*.ld\0"
		CString strExt;//".ld"
		CString strlimitName;//限制的名称 Name|Name1|Name3.exe
		BOOL bEnableCancel;//TRUE：，FALSE：是否屏蔽取消键
		///注释：杨兴耀 [2009年9月22日]                                  
		///
		CString strFileName ; ///默认文件名

		HWND hParent;		//父窗口
	}FileDialogInfo;
	CPMFileDialogEx();
	virtual ~CPMFileDialogEx();

	/******************************************************************** 
	 功能描述：获取文件路径
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[3/4/2008]
	*********************************************************************/ 
	BOOL GetFilePath(FileDialogInfo filedialogInfo,CString & strProjectPath,BOOL bIsCreateDir = TRUE);

	/******************************************************************** 
	 功能描述：获取文件名称
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[3/4/2008]
	*********************************************************************/ 	
	BOOL GetFileTitle(CString & strFileTitle);

	/******************************************************************** 
	 功能描述：获取文件扩展名
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[3/4/2008]
	*********************************************************************/ 
	BOOL GetFileExt(CString & strFileExt);

	int GetSelComboIndex()
	{
		return iSelFilterType;
	};

private:
	CString m_strFilePath;
	CString m_strFileTitle;//没有扩展名
	CString m_strFileExt;
	CString m_StrSelText;//获取选中combox文字
	int iSelFilterType;
};

#endif // !defined(AFX_PMFILEDIALOG_H__3E4CBD30_C897_4C04_8F81_E075CA848129__INCLUDED_)
