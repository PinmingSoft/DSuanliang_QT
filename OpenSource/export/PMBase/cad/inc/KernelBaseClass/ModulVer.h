////////////////////////////////////////////////////////////////
// 1998 Microsoft Systems Journal
//
// If this code works, it was written by Paul DiLascia.
// If not, I don't know who wrote it.
//
#ifndef __MODULEVER_H
#define __MODULEVER_H

#ifdef _DEBUG
#define _DEBUG_ZLL_WAS_DEFINED
#undef _DEBUG
#pragma message ("		����MFC��STD��run-timing��Release")
#endif

#include "Shlwapi.h"
// tell linker to link with version.lib for VerQueryValue, etc.
#pragma comment(linker, "/defaultlib:version.lib")

#ifdef _DEBUG_ZLL_WAS_DEFINED
#define _DEBUG
#undef _DEBUG_ZLL_WAS_DEFINED
#endif

/*
#ifndef DLLVERSIONINFO
// following is from shlwapi.h, in November 1997 release of the Windows SDK

typedef struct PMBASECLASSAPI _DllVersionInfo
{
        DWORD cbSize;
        DWORD dwMajorVersion;                   // Major version
        DWORD dwMinorVersion;                   // Minor version
        DWORD dwBuildNumber;                    // Build number
        DWORD dwPlatformID;                     // DLLVER_PLATFORM_*
} DLLVERSIONINFO;

// Platform IDs for DLLVERSIONINFO
#define DLLVER_PLATFORM_WINDOWS         0x00000001      // Windows 95
#define DLLVER_PLATFORM_NT              0x00000002      // Windows NT

#endif // DLLVERSIONINFO*/




//////////////////
// CModuleVersion version info about a module.
// To use:
//
// CModuleVersion ver
// if (ver.GetFileVersionInfo("_T("mymodule))) {
//		// info is in ver, you can call GetValue to get variable info like
//		CString s = ver.GetValue(_T("CompanyName"));
// }
//
// You can also call the static fn DllGetVersion to get DLLVERSIONINFO.
//

class KERNELBASECLASS_API CModuleVersion : public VS_FIXEDFILEINFO 
{
	
protected:
	BYTE* m_pVersionInfo;	// all version info

	struct TRANSLATION {
		WORD langID;			// language ID
		WORD charset;			// character set (code page)
	} m_translation;

public:
	CModuleVersion();
	virtual ~CModuleVersion();

	//��Ҫ�õ��汾�ŵ�ģ��·��,�������ȵ��øú���,�ɹ����ٵ��� GetValue
	BOOL		GetFileVersionInfo(LPCTSTR modulename);

	//�ؼ���
	static const CString strCompanyName;		//= _T("CompanyName");
	static const CString strFileDescription;	//= _T("FileDescription");
	static const CString strFileVersion;		//= _T("FileVersion");
	static const CString strInternalName;		//= _T("InternalName");
	static const CString strLegalCopyright;	//= _T("LegalCopyright");
	static const CString strOriginalFilename;	//= _T("OriginalFilename");
	static const CString strProductName;		//= _T("ProductName");
	static const CString strProductVersion;	//= _T("ProductVersion");

	//ͨ���ؼ��ֵõ�����ֵ
	CString	GetValue(LPCTSTR lpKeyName);
//���汾��.�Ӱ汾��[�����汾��[.����汾��]]
	//FileVersion: �õ��汾��Ϣ,�ַ���(1.0.0.1)
	BOOL GetVersion(CString &strVersion);

	//�õ��ֱ��Ӧ��intֵ 1,  0, 0, 1
	BOOL GetVersion(int &v1, int &v2, int &v3, int &v4);

	//���dll�������DllGetVersion����,����ʹ�øú����õ��汾��Ϣ�Ľṹ��
	static BOOL DllGetVersion(LPCTSTR modulename, DLLVERSIONINFO& dvi);

	static CString GetFullSoftVersion(const CString & strAppFilePath);
};

#endif
