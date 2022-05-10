#pragma once

//引出的头宏定义
#ifdef PRJ_EXCELOPR
#define PMEXCELOPRDLLEXPIMPORT __declspec(dllexport)
#else
#define PMEXCELOPRDLLEXPIMPORT __declspec(dllimport)
//	#ifdef PM_FOR_R15
//		#pragma comment(lib,"LDLogiKernel15.lib")
//	#elif defined(PM_FOR_R16)
//		#pragma comment(lib,"LDLogiKernel16.lib")
//	#elif defined(PM_FOR_R17)
//		#pragma comment(lib,"LDLogiKernel17.lib")
//	#else
//		#pragma comment(lib,"LDLogiKernel18.lib")
//	#endif
#	pragma comment(lib, "PMExcelOpr"PM_FOR_VERSION _PMLIB_PLATFORM".lib")
#	pragma message("link PMExcelOpr"PM_FOR_VERSION _PMLIB_PLATFORM".lib")
#endif

#include "PMExcelOpr\ExcelOpr.h"