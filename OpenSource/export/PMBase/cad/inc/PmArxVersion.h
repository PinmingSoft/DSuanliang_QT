
#if !defined(AFX_PMBASEPUBCLS_H__984EEEEE_6DB5_401C_951B_99__INCLUDED_)
#define AFX_PMBASEPUBCLS_H__984EEEEE_6DB5_401C_951B_99__INCLUDED_

////////////////////////////////////////////
/// 王建业 [2011:9:1   15:46]
/// 说明:
/// 此处定义 系统的 全局宏

///定义编译器版本编号宏
/*如：
#if PMVCCUR_VER > PMVC60_VER 
	代表里面的代码 只在 版本 高度 Vc6.0才启用。
#endif
*/

#define PMVC60_VER		1200 // vc60

#define PMVC2002_VER	1300 // vc2002

#define PMVC2005_VER	1400 // vc2005

#define PMVC2008_VER	1500 // vc2008

#define PMVC2010_VER	1600 // vc2010

#define PMVC2012_VER	1700 // vc2012

#define PMVC2015_VER	1900 // vc2015

#define PMVC2017_VER	1910 // vc2017 2017的版本是会变的，1913、1915都有可能

#define PMVC2019_VER	1920 // vc2019 2019的版本可能是会变的

#define PMVCCUR_VER		_MSC_VER

#if _MSC_VER == PMVC60_VER	// vc60
#	ifndef PM_FOR_R15
#		define PM_FOR_R15		15
#		define PM_FOR_VERSION	"15"
#		define PM_FOR_VERSION_TSTR	_T("15")
#	endif
#elif _MSC_VER == PMVC2002_VER	// vc2002
#	ifndef PM_FOR_R16
#		define PM_FOR_R16		16
#		define PM_FOR_VERSION	"16"
#		define PM_FOR_VERSION_TSTR	_T("16")
#	endif
#elif _MSC_VER == PMVC2005_VER	// vc2005
#	ifndef PM_FOR_R17
#		define PM_FOR_R17		17
#		define PM_FOR_VERSION	"17"
#		define PM_FOR_VERSION_TSTR	_T("17")
#		define PM_FOR_CADVERSION	"cad2008"
#	endif
#elif _MSC_VER == PMVC2008_VER	// vc2008
#	ifndef PM_FOR_R18
#		define PM_FOR_R18		18
#		define PM_FOR_VERSION	"18"
#		define PM_FOR_VERSION_TSTR	_T("18")
#		define PM_FOR_CADVERSION	"cad2012"
#	endif
#elif _MSC_VER == PMVC2010_VER	// vc2010
#	ifndef PM_FOR_R19
#		ifdef _IS_ZWCAD
#			define PM_FOR_R20		"zw_19"
#			define PM_FOR_VERSION	"zw_19"
#			define PM_FOR_VERSION_TSTR	_T("zw_19")
#			define PM_FOR_CADVERSION	"zw2019"
#		else
#			define PM_FOR_R19		19
#			define PM_FOR_VERSION	"19"
#			define PM_FOR_VERSION_TSTR	_T("19")
#			define PM_FOR_CADVERSION	"cad2014"
#		endif
#	endif
#elif _MSC_VER == PMVC2012_VER	// vc2012
#	ifndef PM_FOR_R20
#		define PM_FOR_R20		20
#		define PM_FOR_VERSION	"20"
#		define PM_FOR_VERSION_TSTR	_T("20")
#		define PM_FOR_CADVERSION	"cad2016"
#	endif
#elif _MSC_VER == PMVC2015_VER	// vc2015
#  if _ADESK_VER == 2017
#	ifndef PM_FOR_R21			// 2017系列
#		define PM_FOR_R21		21
#		define PM_FOR_VERSION	"21"
#		define PM_FOR_VERSION_TSTR	_T("21")
#		define PM_FOR_CADVERSION	"cad2017"
#	endif
#  elif _ADESK_VER == 2018		// 2018系列
#	ifndef PM_FOR_R22
#		define PM_FOR_R22		22
#		define PM_FOR_VERSION	"22"
#		define PM_FOR_VERSION_TSTR	_T("22")
#		define PM_FOR_CADVERSION	"cad2018"
#	endif
#  else
#	ifndef PM_FOR_R21			// 默认2017系列
#		define PM_FOR_R21		21
#		define PM_FOR_VERSION	"21"
#		define PM_FOR_VERSION_TSTR	_T("21")
#		define PM_FOR_CADVERSION	"cad2017"
#	endif
#  endif
#elif _MSC_VER >= PMVC2017_VER	// vc2017\2019
# if _MSC_VER < PMVC2019_VER	// vs2017
#  if _ADESK_VER == 2019
#	ifndef PM_FOR_R23			// 2019系列
#		define PM_FOR_R23		23
#		define PM_FOR_VERSION	"23"
#		define PM_FOR_VERSION_TSTR	_T("23")
#		define PM_FOR_CADVERSION	"cad2019"
#	endif
#  elif _ADESK_VER == 2020		// 2020系列(暂定)
#	ifndef PM_FOR_R23
#		define PM_FOR_R23		23
#		define PM_FOR_VERSION	"23"
#		define PM_FOR_VERSION_TSTR	_T("23")
#		define PM_FOR_CADVERSION	"cad2020"
#	endif
#  else
#	ifndef PM_FOR_R23			// 默认2019系列
#		define PM_FOR_R23		23
#		define PM_FOR_VERSION	"23"
#		define PM_FOR_VERSION_TSTR	_T("23")
#		define PM_FOR_CADVERSION	"cad2019"
#	endif
#  endif
# else
#  if _ADESK_VER == 2021
#	ifndef PM_FOR_R24			// 2021系列
#		define PM_FOR_R24		24
#		define PM_FOR_VERSION	"24"
#		define PM_FOR_VERSION_TSTR	_T("24")
#		define PM_FOR_CADVERSION	"cad2021"
#	endif
#  else
#	ifndef PM_FOR_R24			// 2021后系列
#		define PM_FOR_R24		24
#		define PM_FOR_VERSION	"24"
#		define PM_FOR_VERSION_TSTR	_T("24")
#		define PM_FOR_CADVERSION	"cad2022"
#	endif
#  endif
# endif
#endif

#if defined(_WIN64)
#	define _PMLIB_PLATFORM "_x64"
#	define _PMLIB_PLATFORM_TSTR	_T("_x64")
#else
#	define _PMLIB_PLATFORM ""
#	define _PMLIB_PLATFORM_TSTR	_T("")
#endif

#ifdef PM_FOR_R15
#pragma message ("PM_FOR_R15  <<has be>> defined!!")
#pragma message ("目标平台---<<AutoCad2002>>")
#endif

#ifdef PM_FOR_R16
#pragma message ("PM_FOR_R16  <<has be>> defined!!")
#pragma message ("目标平台---<<AutoCad2004--AutoCad2006>>")
#endif

#ifdef PM_FOR_R17
#pragma message ("PM_FOR_R17  <<has be>> defined!!")
#pragma message ("目标平台---<<AutoCad2007--AutoCad2009>>")
#endif

//#pragma message ("注意:编译工程为测试工程!")
//
//#ifndef _TESTVERSION
//#	define _TESTVERSION
//#endif
//
#ifndef _TESTMEMORY
#	define _TESTMEMORY
#endif
//
#ifndef _TESTTIME
#	define _TESTTIME
#endif

//#pragma message ("注意:编译工程为正式工程!")

#pragma message ("算量 <<1.1>>")
#endif
