// ZipArchiveManager.h: interface for the CZipArchiveManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZIPARCHIVEMANAGER_H__8923C6D5_1C0F_4989_B507_26DCB7DC9087__INCLUDED_)
#define AFX_ZIPARCHIVEMANAGER_H__8923C6D5_1C0F_4989_B507_26DCB7DC9087__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if defined (ZIP_HAS_DLL)
#    if defined (ZIP_BUILD_DLL)
#      define ZIP_API __declspec (dllexport)
#    else
#      define ZIP_API  __declspec (dllimport)
#	endif
#else
#  define ZIP_API
#endif     /* ZIP_HAS_DLL */

class KERNELBASECLASS_API CZipArchiveManager  
{
public:
	
	BOOL ZipFile(LPCTSTR strZipFilePath, LPCTSTR strFile,LPCTSTR strFileTitle,BOOL bAppend);
	
	BOOL ExtractZipFile(LPCTSTR strZipFile,LPCTSTR strZipToPath);

	BOOL ExtractZipFiles(LPCTSTR strZipFile,LPCTSTR strZipToPath,CStringArray & strZipFileNameArr);

	/******************************************************************** 
	 功能描述：压缩文件夹
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[2/9/2009]
	*********************************************************************/ 
	BOOL ZipFolder(LPCTSTR strZipFilePath, LPCTSTR strFoldPath,LPCTSTR & strErrString);
	
	CZipArchiveManager();
	virtual ~CZipArchiveManager();

};

#endif // !defined(AFX_ZIPARCHIVEMANAGER_H__8923C6D5_1C0F_4989_B507_26DCB7DC9087__INCLUDED_)
