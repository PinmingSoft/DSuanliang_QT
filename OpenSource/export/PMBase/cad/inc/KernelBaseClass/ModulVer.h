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
#pragma message ("		连接MFC、STD、run-timing用Release")
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

	//需要得到版本号的模块路径,必须首先调用该函数,成功后再调用 GetValue
	BOOL		GetFileVersionInfo(LPCTSTR modulename);

	//关键字
	static const CString strCompanyName;		//= _T("CompanyName");
	static const CString strFileDescription;	//= _T("FileDescription");
	static const CString strFileVersion;		//= _T("FileVersion");
	static const CString strInternalName;		//= _T("InternalName");
	static const CString strLegalCopyright;	//= _T("LegalCopyright");
	static const CString strOriginalFilename;	//= _T("OriginalFilename");
	static const CString strProductName;		//= _T("ProductName");
	static const CString strProductVersion;	//= _T("ProductVersion");

	//通过关键字得到其他值
	CString	GetValue(LPCTSTR lpKeyName);
//主版本号.子版本号[修正版本号[.编译版本号]]
	//FileVersion: 得到版本信息,字符串(1.0.0.1)
	BOOL GetVersion(CString &strVersion);

	//得到分别对应的int值 1,  0, 0, 1
	BOOL GetVersion(int &v1, int &v2, int &v3, int &v4);

	//如果dll中输出了DllGetVersion函数,可以使用该函数得到版本信息的结构体
	static BOOL DllGetVersion(LPCTSTR modulename, DLLVERSIONINFO& dvi);

	static CString GetFullSoftVersion(const CString & strAppFilePath);
};

#endif
