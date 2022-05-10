//add by wjy
/////////////////////
#ifndef __PMBaseOprH
#define __PMBaseOprH

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// #ifndef PRJ_PMUI_DRAWERBAR
//    #define PRJ_PMUI_DRAWERBAR
// #endif
#include <PmArxVersion.h>
#include <AFXTEMPL.H>

#ifdef _PRJ_BaseClassOpr
#	define PMBASECLASSOPRAPI __declspec(dllexport)
#else
#	ifdef _PmLib
#		define PMBASECLASSOPRAPI __declspec(dllexport)
#		pragma comment(lib, "PmBaseOpr" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#		pragma message("link Static PmBaseOpr" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#	else
#		define PMBASECLASSOPRAPI __declspec(dllimport)
#		pragma comment(lib, "PmBaseOpr" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#		pragma message("link PmBaseOpr" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#	endif
#endif

#include <PMBaseOpr/Timing.h>
#include <PMBaseOpr/PMMemoryManager.h>
#include <PMBaseOpr/PmBaseMacroDef.h>
#include <PmBaseOpr/PMBaseFunDef.h>
#include "PmBaseOpr/PmBaseVarTypeDef.h"
#include "PmBaseOpr/PmCast.h"
#include "PmbaseOpr/PMBaseCommonFun.h"
#include "PmbaseOpr/PmArray.h"
#include "PmbaseOpr/PMSharePtr.h"
#include "PmBaseOpr/XMLMarkup.h"


#include <PMBaseOpr\Source\COXParser\ugstrop.h>
#include <PMBaseOpr\Source\COXParser\OXQuickString.h>
#include <PMBaseOpr\Source\COXParser\OXDllExt.h>
#include <PMBaseOpr\Source\COXParser\OXHashTable.h>
#include <PMBaseOpr\Source\COXParser\OXParser.h>


#endif 
