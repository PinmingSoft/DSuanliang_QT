#pragma once

#ifdef PRJ_PM_QTFUN
#	define PMQTFUNAPI __declspec(dllexport)
#else
#	define PMQTFUNAPI __declspec(dllimport)
#pragma comment(lib, "PmQtFun" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#pragma message("link PmQtFun" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#endif

//#include "pmqtfun_global.h"
#include "PmQtExport.h"
#include "PmQtCmd.h"