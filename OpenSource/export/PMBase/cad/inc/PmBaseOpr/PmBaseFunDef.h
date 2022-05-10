
#pragma once


/**
 * @brief 定义一些基础的Win32 与X64函数 包装
 *
 *        
 * @author 王建业
 * @version v1.0
 * @date  [2012-11-20]
 * @note  
 */

#ifdef _WIN64
#	define pm_ttoi			_ttoi64
#else
#	define pm_ttoi			_ttoi
#endif

#define pm_ttoi32			_ttoi
#define pm_ttoi64			_ttoi64

#ifndef _ttof
#	ifdef _UNICODE
#		if _MSC_VER >= 1300
#			define _ttof _wtof
#		else
#			pragma message("当前编译器版本目前不支持_wtof")
#		endif
#	else
#		define _ttof atof
#	endif
#endif

#ifndef PI
#define PI 3.1415926535897932384626433832795
#endif