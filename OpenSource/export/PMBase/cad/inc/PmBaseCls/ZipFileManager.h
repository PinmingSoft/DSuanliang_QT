// ZipFileManager.h: interface for the CZipFileManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZIPFILEMANAGER_H__0192FF36_959B_4501_940F_CA018C13C6EB__INCLUDED_)
#define AFX_ZIPFILEMANAGER_H__0192FF36_959B_4501_940F_CA018C13C6EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/******************************************************************** 
 ��������������ѹ���ļ� ���ļ��� ʹ�� ZipArchive��ʵ��
 ������
 �� �� ֵ��
 �㷨��
 ע�����
 ��    �ߣ�����ҵ
 ʱ    �䣺[1/9/2009]
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

//	BOOL m_bHasRunZip;//�Ƿ���ִ��ѹ��
};

#endif // !defined(AFX_ZIPFILEMANAGER_H__0192FF36_959B_4501_940F_CA018C13C6EB__INCLUDED_)
