#ifndef __KernelBaseClassH__
#define __KernelBaseClassH__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <PmArxVersion.h>

#ifdef PRJ_KernelBaseClass
#	define KERNELBASECLASS_API __declspec(dllexport)
#else
#	ifdef _PmLib
#		define KERNELBASECLASS_API __declspec(dllexport)
#		pragma comment(lib, "KernelBaseClass" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#		pragma message("link Static KernelBaseClass" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#	else
#		define KERNELBASECLASS_API __declspec(dllimport)
#		pragma comment(lib, "KernelBaseClass" PM_FOR_VERSION _PMLIB_PLATFORM".lib")
#		pragma message("link KernelBaseClass" PM_FOR_VERSION _PMLIB_PLATFORM".lib")
#	endif
#endif

#include <string>
#include <vector>

#include <KernelBaseClass\PMDataEncodeFun.h>

#include <KernelBaseClass\PmKernelFun.h>
#include <KernelBaseClass\PMWinHTTP.h>
#include <KernelBaseClass\PMDebug.h>
#include <KernelBaseClass\HttpClient.h>
#include <KernelBaseClass\HttpFun.h>

#include <KernelBaseClass\RockeyManager\RockeyUIOpr.h>
//#include <KernelBaseClass\RockeyManager\PMRockeyManager.h>

#include <KernelBaseClass\UILogic\Dialog_Common.h>
#include <KernelBaseClass/Json/json.h>
//#include <KernelBaseClass\SensorsData\CommunManager.h>
#include <KernelBaseClass\SensorsData\SensorsDataOpr.h>
#include <KernelBaseClass\ZipFileManager.h>
#include <KernelBaseClass\ZipArchiveManager.h>
#include <kernelBaseClass\TimerQueueTimer.h>
#include <kernelBaseClass\OutPutTextTable.h>
#include <kernelBaseClass\ModulVer.h>
#include <kernelBaseClass\CollectDWGInfo2Server.h>

#endif 