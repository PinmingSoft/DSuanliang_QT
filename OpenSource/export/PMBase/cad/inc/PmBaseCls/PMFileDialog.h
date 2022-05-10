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
	CString m_strExt;//�ļ���չ��
	BOOL m_bEnableCancel;//TRUE����FALSE���Ƿ�����ȡ����

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
	CString m_strFolderPath;//�����ļ���ʱ���ļ�·��
	CString m_strSelFolderName;//ѡ�е��ļ�������
	BOOL m_bCoverFolder;//TRUE:��ʾ�����ļ��У�FALSE������ʾ
	CString m_strCoverFolderMsg;//��ʾ���֣�
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
		BOOL bOpenMode;//TRUE����ģʽ��FALSE�����Ϊ
		BOOL bCoverFolder;//TRUE:��ʾ�����ļ��У�FALSE������ʾ
		CString strCoverFolderMsg;//��ʾ����
		CString strCaption;//��������
		CString strDefDir;//Ĭ���ļ���λ��
		LPCTSTR strFilter;// = "Ʒ���ֽ������û��ļ�(*.ld)\0*.ld\0"
		CString strExt;//".ld"
		CString strlimitName;//���Ƶ����� Name|Name1|Name3.exe
		BOOL bEnableCancel;//TRUE����FALSE���Ƿ�����ȡ����
		///ע�ͣ�����ҫ [2009��9��22��]                                  
		///
		CString strFileName ; ///Ĭ���ļ���

		HWND hParent;		//������
	}FileDialogInfo;
	CPMFileDialogEx();
	virtual ~CPMFileDialogEx();

	/******************************************************************** 
	 ������������ȡ�ļ�·��
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[3/4/2008]
	*********************************************************************/ 
	BOOL GetFilePath(FileDialogInfo filedialogInfo,CString & strProjectPath,BOOL bIsCreateDir = TRUE);

	/******************************************************************** 
	 ������������ȡ�ļ�����
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[3/4/2008]
	*********************************************************************/ 	
	BOOL GetFileTitle(CString & strFileTitle);

	/******************************************************************** 
	 ������������ȡ�ļ���չ��
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[3/4/2008]
	*********************************************************************/ 
	BOOL GetFileExt(CString & strFileExt);

	int GetSelComboIndex()
	{
		return iSelFilterType;
	};

private:
	CString m_strFilePath;
	CString m_strFileTitle;//û����չ��
	CString m_strFileExt;
	CString m_StrSelText;//��ȡѡ��combox����
	int iSelFilterType;
};

#endif // !defined(AFX_PMFILEDIALOG_H__3E4CBD30_C897_4C04_8F81_E075CA848129__INCLUDED_)
