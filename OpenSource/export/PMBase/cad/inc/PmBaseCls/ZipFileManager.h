// ZipFileManager.h: interface for the CZipFileManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZIPFILEMANAGER_H__0192FF36_959B_4501_940F_CA018C13C6EB__INCLUDED_)
#define AFX_ZIPFILEMANAGER_H__0192FF36_959B_4501_940F_CA018C13C6EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/******************************************************************** 
 功能描述：用于压缩文件 及文件夹 使用 ZipArchive库实现
 参数：
 返 回 值：
 算法：
 注意事项：
 作    者：王建业
 时    间：[1/9/2009]
*********************************************************************/ 
class CZipArchive;

class PMBASECLASSAPI CZipFileManager  
{
public:
	BOOL ExtractZipFile(CString strZipFilePath,CString strZip2Path);

	BOOL ExtractZipFiles(CString strZipFile,CString strZipToPath,CStringArray & strZipFileNameArr);
	
	BOOL ZipFiles(CString strZipPath,CStringArray & strFilePathArr,BOOL bNeedPosDlg,BOOL bNeedShowErr = TRUE);
	BOOL ZipFolder(CString strZipPath,CString strFolderPath,BOOL bNeedPosDlg);
	CZipFileManager();
	virtual ~CZipFileManager();
	
protected:

//	BOOL m_bHasRunZip;//是否已执行压缩
};

#endif // !defined(AFX_ZIPFILEMANAGER_H__0192FF36_959B_4501_940F_CA018C13C6EB__INCLUDED_)
