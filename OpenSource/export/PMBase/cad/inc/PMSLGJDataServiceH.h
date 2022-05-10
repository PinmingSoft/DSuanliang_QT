#ifndef PMSLGJDataServiceH_H__
#define PMSLGJDataServiceH_H__

//#ifdef PRJ_PmSLGJDataService
//#	define PmSLGJDataServiceAPI __declspec(dllexport)
//#else
//#	define PmSLGJDataServiceAPI __declspec(dllimport)
//#	if defined(PM_FOR_R15)
//#		pragma comment(lib,"PMSLGJDataService15.lib")
//#		pragma message("link PMSLGJDataService15.lib")
//#	elif defined(PM_FOR_R16)
//#		pragma comment(lib,"PMSLGJDataService16.lib")
//#		pragma message("link PMSLGJDataService16.lib")
//#	elif defined(PM_FOR_R17)
//#		pragma comment(lib,"PMSLGJDataService17.lib")
//#		pragma message("link PMSLGJDataService17.lib")
//#	elif defined(PM_FOR_R18)
//#		pragma comment(lib,"PMSLGJDataService18.lib")
//#		pragma message("link PMSLGJDataService18.lib")
//#	endif
//#endif

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// Íâ²¿Ä£¿é
#include <PmBaseClassH.h>
#include <DataSetH.h>
#include <PM_LogicDataOprH.h>


	#ifndef PmSLGJDataServiceAPI
#	ifdef PRJ_PmSLGJDataService
#		define PmSLGJDataServiceAPI __declspec(dllexport)
#	else
#		define PmSLGJDataServiceAPI __declspec(dllimport)
#		pragma comment(lib, "PMSLGJDataService" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#		pragma message("link PMSLGJDataService" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#	endif
#endif


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
#include <PMSLGJDataService/AccessTable.h>
#include <PMSLGJDataService/ConnectManager.h>
#include <PMSLGJDataService/DataBaseAndTableName.h>
#include <PMSLGJDataService/PmSlGjDataService_Common.h>
#include <PMSLGJDataService/PmSpecialDataSetOperate.h>
//#include <PMSLGJDataService/Project_ManageVectorGraph.h>
#include <PMSLGJDataService/CommonTableDefine.h >
//#include <PMSLGJDataService/TransSlTqd2GjTqd.h  >
#include <PMSLGJDataService/GjParam.h>
#include <PMSLGJDataService/PmSpecialDataSet.h>
#include <PMSLGJDataService/DataSetFun.h>
//#include <PMSLGJDataService/PmComParamsOpr.h >
//#include <PMSLGJDataService/ParmAccess.h  >
//#include <PMSLGJDataService/PmDataBaseBatchOpr.h>




#include <PMSLGJDataService/SysData/AccessSysData_CheckRegTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_ComParamsSet.h>
#include <PMSLGJDataService/SysData/AccessSysData_ComParamsSet_Gdtz.h>
#include <PMSLGJDataService/SysData/AccessSysData_ComParamsSet_Total.h>
#include <PMSLGJDataService/SysData/AccessSysData_Csflib_GjTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_CsflibTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_Csfvectordiagram_GjTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_CsfvectordiagramTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_FaceHelpInfo_GjTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_FaceHelpInfoTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_GjFormula_GjTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_GjFormulaTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_GjSetupTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_GjSetUpVectorDiagramTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_GjzsTypeTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_Graph_MapTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_Hjdface_InfoTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_InitMgTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_MacrosTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_RegInfoTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_SpecialVariableTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_SteelDiagram_LibTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_SteelDiagram_ParamsTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_SteelDiagramTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_VectorGraph_GjTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_VectorGraph_GraphicsTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_VectorGraphTable.h>
#include <PMSLGJDataService/SysData/AccessSysDataTable.h>
#include <PMSLGJDataService/SysData/AccessSysData_ComParamsSet_Gj.h>
#include <PMSLGJDataService/SysData/AccessSysData_FloorBgMode.h>
#include <PMSLGJDataService/SysData/AccessSysData_FloorLayerInfo.h>



#include <PMSLGJDataService/YZBTj/AccessYZBTj_Attribute_MidSouthTable.h>
#include <PMSLGJDataService/YZBTj/AccessYZBTj_Attribute_RecentUsedTable.h>
#include <PMSLGJDataService/YZBTj/AccessYZBTj_Attribute_UserDefinedTable.h>
#include <PMSLGJDataService/YZBTj/AccessYZBTj_Zjbh_MidSouthTable.h>

#include <PMSLGJDataService/BZCTTj/AccessBZCTTj_ContentTable.h>
#include <PMSLGJDataService/BZCTTj/AccessBZCTTj_JiangSuTable.h>
#include <PMSLGJDataService/BZCTTj/AccessBZCTTj_ZheJiangTable.h>

#include <PMSLGJDataService/DEData/AccessDEData_ChapterTable.h>
#include <PMSLGJDataService/DEData/AccessDEData_ProjectCodeTable.h>
#include <PMSLGJDataService/DEData/AccessDEData_RationTable.h>

#include <PMSLGJDataService/QDData/AccessQDData_BillTable.h>
#include <PMSLGJDataService/QDData/AccessQDData_DefaultQdValueTable.h>
#include <PMSLGJDataService/QDData/AccessQDData_ProjectCodeTable.h>
#include <PMSLGJDataService/QDData/AccessQDData_QDAttTable.h>
#include <PMSLGJDataService/QDData/AccessQDData_RuleIndex_mTable.h>



// #include <PMSLGJDataService/PublicGj/AccessPublicGj_Component_QDDETable.h>
// #include <PMSLGJDataService/PublicGj/AccessPublicGj_ComponentsTable.h>
// #include <PMSLGJDataService/PublicGj/AccessPublicGj_GraphMapTable.h>
// #include <PMSLGJDataService/PublicGj/AccessPublicGj_OwnGanjinVectorTable.h>
// #include <PMSLGJDataService/PublicGj/AccessPublicGj_VectorGraphGraphicsTable.h>
// #include <PMSLGJDataService/PublicGj/AccessPublicGj_VectorGraphTable.h>
// #include <PMSLGJDataService/PublicGj/AccessPublicGj_SysGangJinTable.h>
#endif //PMSLGJDataServiceH_H
