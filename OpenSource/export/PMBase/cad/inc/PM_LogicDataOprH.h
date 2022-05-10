#ifndef PM_LogicDataOpr_20080114_H
#define PM_LogicDataOpr_20080114_H

#include <PMbaseClassH.h>
#include <datasetH.h>

#ifdef PRJ_PM_LogicDataOpr
#	define PMLogicDataOprAPI __declspec(dllexport)
#else
#	define PMLogicDataOprAPI __declspec(dllimport)
#	pragma comment(lib, "PM_LogicDataOpr" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#	pragma message("link PM_LogicDataOpr" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#endif

#include <PM_LogicDataOpr\PM_UIFunction.h>
#include <PM_LogicDataOpr\CalUnitManager.h>
#include <PM_LogicDataOpr\ParmInfoBase.h>
#include <PM_LogicDataOpr\SteelDataDefine.h>
#include <PM_LogicDataOpr\SteelDataContainer.h>
#include <PM_LogicDataOpr\CommonDataTableDefine.h>
#include <PM_LogicDataOpr\GridFaceManager.h>
#include <PM_LogicDataOpr\QDDE_FJCC_Controler.h>
#include <PM_LogicDataOpr\QDDE_AddJSGZ_Controler.h>
#include <PM_LogicDataOpr\QDDE_JSGZ_Controler.h>
#include <PM_LogicDataOpr\QDDE_FJCCManager.h>
#include <PM_logicDataOpr\SWL_QDDE_FJCC_Controler.h>
#include <PM_LogicDataOpr\QDDE_AddJSGZManager.h>
#include <PM_LogicDataOpr\QDDE_JSGZManager.h>
#include <PM_LogicDataOpr\QDDE_SWL_Controler.h>
#include <PM_LogicDataOpr\QDDE_SWLManager.h>
#include <PM_LogicDataOpr\QDDE_SWLDataSet.h>
#include <PM_LogicDataOpr\PMSolidVectorGraphicOpr.h>
#include <PM_LogicDataOpr\PMVectorGraphicOpr.h>
#include <PM_LogicDataOpr\RuleDesc_Manager.h>
#include <PM_LogicDataOpr\CommonDataStructDefine.h>
#include <PM_LogicDataOpr\PmConfig.h>
#include <PM_LogicDataOpr\ProgressDlg_Control.h>
#include <PM_LogicDataOpr\PMRegeditControl.h>
#include <PM_LogicDataOpr\PM_LogicDataOpr_CallBack.h>
//#include <PM_LogicDataOpr\JsParserOpr.h>
#include <PM_LogicDataOpr\SoftShowInfoOpr.h>
#include <PM_LogicDataOpr\DbSqlConstName.h>
#include <PM_LogicDataOpr/JsParserOpr.h>
#include <PM_LogicDataOpr/PMLogicGraphic.h>
//#include <PM_LogicDataOpr/PMHStreamStruct.h>
//#include <PM_LogicDataOpr/PMHStreamGeo.h>

#endif