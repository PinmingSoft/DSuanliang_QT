
#pragma once


/**
 * @brief 定义一些基础的宏
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-11-20]
 * @note  
 */
#include "PmArxVersion.h"

#ifdef _WIN64
#	define PM_GWL_USERDATA			GWLP_USERDATA
#	define PM_GWL_WNDPROC			GWLP_WNDPROC
#	define PM_DWL_DLGPROC			DWLP_DLGPROC 
#	define PM_GWL_WNDPROC			GWLP_WNDPROC
#	define PM_DWL_USER				DWLP_USER
#	define PM_GCL_HBRBACKGROUND		GCLP_HBRBACKGROUND
#	define PM_GWL_HINSTANCE			GWLP_HINSTANCE
#   define PM_GCLP_HCURSOR          GCLP_HCURSOR
#else
#	define PM_GWL_USERDATA			GWL_USERDATA
#	define PM_GWL_WNDPROC			GWL_WNDPROC
#	define PM_DWL_DLGPROC			DWL_DLGPROC 
#	define PM_GWL_WNDPROC			GWL_WNDPROC
#	define PM_DWL_USER				DWL_USER
#	define PM_GCL_HBRBACKGROUND		GCL_HBRBACKGROUND
#	define PM_GWL_HINSTANCE			GWL_HINSTANCE
#   define PM_GCLP_HCURSOR          GCL_HCURSOR

#endif

#ifdef PM_FOR_R16
#	define PM_OnNcHitTest_Cpp(className)	UINT className::OnNcHitTest
#	define PM_OnNcHitTest_H					UINT OnNcHitTest
#else
#	define PM_OnNcHitTest_Cpp(className)	LRESULT className::OnNcHitTest
#	define PM_OnNcHitTest_H					LRESULT OnNcHitTest
#endif