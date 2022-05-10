//add by wjy
/////////////////////
#ifndef __ExternDataServiceH
#define __ExternDataServiceH

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//#ifdef PRJ_PMProjectDBSERVICE
//	#define PMProjectDBSERVICE __declspec(dllexport)
//#else
//	#define PMProjectDBSERVICE __declspec(dllimport)
//	#if defined(PM_FOR_R15)
//		#pragma comment(lib,"ExternDataService15.lib")
//		#pragma message("link ExternDataService15.lib")
//	#elif defined(PM_FOR_R16)
//		#pragma comment(lib,"ExternDataService16.lib")
//		#pragma message("link ExternDataService16.lib")
//	#elif defined(PM_FOR_R17)
//		#pragma comment(lib,"ExternDataService17.lib")
//		#pragma message("link ExternDataService17.lib")
//	#elif defined(PM_FOR_R18)
//	#pragma comment(lib,"ExternDataService18.lib")
//	#pragma message("link ExternDataService18.lib")
//	#endif
//#endif

#include <PMSLGJDataServiceH.h>

#ifndef PMProjectDBSERVICE
#	ifdef PRJ_PMProjectDBSERVICE
#		define PMProjectDBSERVICE __declspec(dllexport)
#	else
#		define PMProjectDBSERVICE __declspec(dllimport)
#		pragma comment(lib, "ProjectDBService" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#		pragma message("link ProjectDBService" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#	endif
#endif



#include <ProjectDBService/Source/Extern/PublicGJ/ExternSysComponent_QDDETable.h>
#include <ProjectDBService/Source/Extern/PublicGJ/ExternSysComponentsTable.h>
#include <ProjectDBService/Source/Extern/PublicGJ/ExternSysVectorGraphTable.h>
#include <ProjectDBService/Source/Extern/PublicGJ/ExternSysVectorGraphGraphicsTable.h>
#include <ProjectDBService/Source/Extern/PublicGJ/ExternSysProjectCodeTable.h>

#include <ProjectDBService/Source/Extern/Project/ExternFloorTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternComponentsTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternComponentsGJTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternVectorGraphTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternResultTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternComponentGJResultTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternGraphicsResultTable.h>
#include <ProjectDBService/Source/Extern/Project/Extern3DGraphicsResultTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternEditOtherItemTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternRoomTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternLayerInfoTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternProjectInfoTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternQDXMAttTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternComFolderTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternComParmsSet_GJTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternComParmsSet_TotalTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternComParmsSetTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternDrawIndexTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternFloorBGModeTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternFloorDJXSTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternFloorGJXXInfoTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternVectorGraph_GJTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternSpecificGravityTable.h>
#include <ProjectDBService/Source/Extern/Project/ExternVectorGraphGraphicsTable.h>

#include <ProjectDBService/Source/Extern/Project/ExternComponentQDDETable.h >
#include <ProjectDBService/Source/Extern/Project/ExternPrivateOpr.h >
 
#include <ProjectDBService/Source/Extern/ExternProjectCodeTable.h>
#include <ProjectDBService/Source/Extern/ExternManager.h>
#include <ProjectDBService/Source/Extern/RepairDataBase.h>


#include <ProjectDBService/Source/Project/Project_ManageVectorGraph.h>
#include <ProjectDBService/Source/Project/TransSlTqd2GjTqd.h  >
#include <ProjectDBService/Source/Project/ParmAccess.h  >
#include <ProjectDBService/Source/Project/PmDataBaseBatchOpr.h>
#include <ProjectDBService/Source/Project/ProjectVar.h>
#include <ProjectDBService/Source/Project/ProjectGdtz.h>
#include <ProjectDBService/Source/Project/WorkSegInfo.h>
#include <ProjectDBService/Source/Project/PcWallInfo.h>
#include <ProjectDBService/Source/Project/SWLRule.h>
#include <ProjectDBService/Source/Project/CmdDesTable.h>
#include <ProjectDBService/Source/Project/BGSelect.h>

#include <ProjectDBService/Source/Project/Project/AccessProject_AxisTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_CalRule_SgdLbTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ComFolderTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ComParmsSet_TotalTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ComParmsSetTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ComponentResultTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_Components_GJTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ComponentsTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ComponentsDelTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_CustomSteelComponents.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_CustomSteelResultTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_DrawIndexTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_EditOtherItemTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_QD_WBTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_FloorBGModeTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_FloorDJMGInfoTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_FloorDJXSTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_SlopeEarTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_FloorGJXXInfoTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_FloorTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_GJJMInfoTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_GJ_SWL_ExtraValue_Table.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_SwlGJJMInfoTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_GraphicsResultTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_GraphicsResultV2Table.h>
//#include <ProjectDBService/Source/Project/Project/AccessProject_GraphMapTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_LayerInfoTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_LiangBanZsTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_OwnGanjinVectorTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ProjectCodeTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ProjectInfoTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_QD_ResultTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_QDXMAttTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ResultTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_SgdResultTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_SwlResultTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_SgdSwlResultTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_RoomTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_SwlRoomTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_SpecificGravityTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_VectorGraph_GjTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_VectorGraphGraphicsTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_VectorGraphTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_QtgjTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ComParmsSet_GjTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_KcEntityTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_FloorEntityTable.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ComponentQDDETable.h>
//#include <ProjectDBService/Source/Project/Project/AccessProject_ComponentQDDE_Handle.h>
#include <ProjectDBService/Source/Project/Project/Project_FloorOperate.h>
#include <ProjectDBService/Source/Project/Project/Project_ComParmsCache.h >
#include <ProjectDBService/Source/Project/Project/PMVectorGraphicCtrl.h>
#include <ProjectDBService/Source/Project/Project/ComponentsContainer.h>
#include <ProjectDBService/Source/Project/Project/ApplayFloorGjxxToParms.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ComParmSet_Base.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ComParmSet_ComId.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ComParmSet_Handle.h>
#include <ProjectDBService/Source/Project/Project/ProjectComParmsOpr.h> 
#include <ProjectDBService/Source/Project/Project/ProjectGlobleParmOpr.h>
#include <ProjectDBService/Source/Project/Project/ProjectSteelProDef.h>
#include <ProjectDBService/Source/Project/Project/Connect_Project.h>
#include <ProjectDBService/Source/Project/Project/VectorAcceptEditText.h>
#include <ProjectDBService/Source/Project/Project/ComParmOpr.h>
#include <ProjectDBService/Source/Project/Project/AccessProject_ComponentSWL_Handle.h>
#include "ProjectDBService/Source/Project/Project/FloorCC.h"
#include "ProjectDBService/Source/Project/Project/PmComParmsDataSet.h"
#include "ProjectDBService/Source/Project/Project/CalComponentBG.h"
#include "ProjectDBService/Source/Project/Project/AccessProject_TtymjResultTable.h"
#include "ProjectDBService/Source/Project/Project/AccessProject_TtymjTable.h"

//这个.h因为调用了ProjectComParmsOpr.h，所以放在这儿
#include <ProjectDBService/Source/Project/PmComParamsOpr.h >

#include <ProjectDBService/Source/Project/PublicGj/AccessPublicGj_Component_QDDETable.h>
#include <ProjectDBService/Source/Project/PublicGj/AccessPublicGj_ComponentsTable.h>
#include <ProjectDBService/Source/Project/PublicGj/AccessPublicGj_GraphMapTable.h>
#include <ProjectDBService/Source/Project/PublicGj/AccessPublicGj_OwnGanjinVectorTable.h>
#include <ProjectDBService/Source/Project/PublicGj/AccessPublicGj_VectorGraphTable.h>
#include <ProjectDBService/Source/Project/PublicGj/AccessPublicGj_SysGangJinTable.h>
#include <ProjectDBService/Source/Project/PublicGj/AccessPublicGj_VectorGraphGraphicsTable.h>


#include <ProjectDBService/Source/Report/ReportDataFieldDef.h>
#include <ProjectDBService/Source/Report/AccessReportBase.h>
#include <ProjectDBService/Source/Report/AccessReportProjectInfo.h>
#include <ProjectDBService/Source/Report/ReportTableOprSwitch.h>
#include <ProjectDBService/Source/Report/GangJin/AccessReportGjjb.h>
#include <ProjectDBService/Source/Report/GangJin/AccessReportSteelMx.h>
#include <ProjectDBService/Source/Report/GangJin/AccessReportSteelMxFc.h>

#include <ProjectDBService/UIColorConfig.h>

#endif // __ExternDataServiceH
