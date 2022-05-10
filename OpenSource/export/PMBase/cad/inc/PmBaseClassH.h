// PmBaseClassH.h: interface for the CPmBaseClassH class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMBASECLASSH_H__9275C1AF_0EBC_4696_A5FB_3B57E00ADD03__INCLUDED_)
#define AFX_PMBASECLASSH_H__9275C1AF_0EBC_4696_A5FB_3B57E00ADD03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <PMBaseOprH.h>
#include <KernelBaseClassH.h>

#ifndef PMBASECLASSAPI
#	ifdef _PRJ_BASECLASS
#		define PMBASECLASSAPI __declspec(dllexport)
#	else
#		define PMBASECLASSAPI __declspec(dllimport)
#		pragma comment(lib, "PmBaseClass" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#		pragma message("link PmBaseClass" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#	endif
#endif

///// 外部模块 引入QT library
//#ifdef NDEBUG
//#	pragma comment(lib, "qtmain.lib")
//#	pragma comment(lib, "QtCore4.lib")
//#	pragma comment(lib, "QtGui4.lib")
//#	pragma comment(lib, "QtXml4.lib")
//#else   
//#	pragma comment(lib, "qtmaind.lib")
//#	pragma comment(lib, "QtCored4.lib")
//#	pragma comment(lib, "QtGuid4.lib")
//#	pragma comment(lib, "QtXmld4.lib")
//#endif

/// 外部模块
/// PmCommonFun.cpp 引用了 "MathParserLibH.h"
#include <map>//添加 std::map的 支持
#include <set>
#include <vector>
#include <list>

#include <AFXTEMPL.H>

/// PmMFC files
#include "PmBaseCls/PmSystemInc.h"
//#include "PmBaseCls/ModulVer.h"
#include "PmBaseCls/PmEditCtrl.h"
#include "PmBaseCls/PMRichEditCtrl.h"
#include "PmBaseCls/PmMfcFun.h"
#include "PmBaseCls/PmImageStatic.h"
#include "PmBaseCls/TextButton.h"
#include "PmBaseCls/ImageButton.h"
#include "PmBaseCls/PmMutiTreeCtrl.h"
#include "PmBaseCls/SeException.h"
#include "PmBaseCls/iniFile.h"
#include "PmBaseCls/excel.h"

/// LDKernel files
#include "PmBaseCls/PMDebug.h"
#include "PmBaseCls/CStringBuilder.h"
#include "PmBaseCls/CLarge_StringBuilder.h"
//#include "PmBaseCls/PmRegex.h"

//#include "PmBaseCls/PMMemoryManager.h"

/// PmCommon files
#include "PmBaseCls/MapA2B.h"
#include "PmBaseCls/PmCommonFun.h"
#include "PmBaseCls/doubleless.h"
#include "PmBaseCls\Param.h"
#include "PmBaseCls\Parms.h"
//#include "PmBaseCls\Timing.h"
#include "PmBaseCls\PmStdString.h"

//其它
#include "PmBaseCls\OwnDrawUI.h"
#include "PmBaseCls/WndResizer.h"
#include "PmBaseCls/WndResizerEx.h"

#include "PmBaseCls/PMWinHTTP.h"
//#include "PmBaseCls/OutPutTextTable.h"
#include "PmBaseCls/XMLResolvAdapter.h"
#include "PmBaseCls/PMSafeFileCtrl.h"

/// controls
#include "PmBaseCls/Controls/BtnST.h"
#include "PmBaseCls/Controls/xDib.h"
#include "PmBaseCls/Controls/ShadeButtonST.h"
#include "PmBaseCls/Controls/HeadToolBar.h"
#include "PmBaseCls/Controls/DialogContainer.h"
#include "PmBaseCls/Controls/FindEdit.h"
#include "PmBaseCls/Controls/NoEnableButton.h"
//#include "PmBaseCls/Controls/PropertyButton.h"

/// XListCtrl
#include "PmBaseCls/XListCtrl/DropWnd.h"
#include "PmBaseCls/XListCtrl/DropScrollBar.h"
#include "PmBaseCls/XListCtrl/DropListBox.h"
#include "PmBaseCls/XListCtrl/AdvComboEdit.h"
#include "PmBaseCls/XListCtrl/XComboList.h"
#include "PmBaseCls/XListCtrl/XHeaderCtrl.h"
#include "PmBaseCls/XListCtrl/AdvComboBox.h"
#include "PmBaseCls/XListCtrl/XCombo.h"
#include "PmBaseCls/XListCtrl/XEdit.h"
#include "PmBaseCls/XListCtrl/XListCtrl.h"

#include "PmBaseCls/SaveData_Storage.h"
#include "PmBaseCls/Trigon.h"
#include "PmBaseCls/PM_RITICAL_SECTION.h"
#include "PmBaseCls/PmArchiveBase.h"

//DataEncode
#include "PmBaseCls/PMDataEncodeFun.h"
#include "PmBaseCls/PMTryCatch.h"
//#include "PmBaseCls/ZipFileManager.h"


#include <PmBaseCls/BrowseDirDialog.h>
#include <PmBaseCls/ControlToolTipControl.h>
#include <PmBaseCls/UiFunCommon.h>
#include <PmBaseCls/PMTabCtrl.h>
#include <PmBaseCls/SplitterControl.h>
#include <PmBaseCls/GfxOutBarCtrl.h>
//#include <PmBaseCls/CJFlatComboBox.h>
//#include <PmBaseCls/HyperLink.h>
//#include <PmBaseCls/ThemeHelperST.h>
//#include <PmBaseCls/XPStyleButtonST.h>
#include <PmBaseCls/DialogMgr.h>
#include <PmBaseCls/PropException.h>

#include "PmBaseCls\RegionItem.h"
#include "PmBaseCls\IndexItem.h"
#include "PmBaseCls\BoundIntersect.h"
#include "PmBaseCls\RegionIntersect.h"
#include "PmBaseCls\PMTickCount.h"
#include "PmBaseCls\ImageButton.h"
#include "PmBaseCls\PmTooltip.h"
#include "PmBaseCls\PmImageButton.h"
#include "PmBaseCls\PmImageCombo.h"
#include "PmBaseCls\PngButton.h"
#include "PmBaseCls\PngStatic.h"
#include "PmBaseCls\PmColorTabCtrl.h"
#include "PmBaseCls\PmGradientProgressCtrl.h"
#include "PmBaseCls\PmHeaderCtrlCl.h"
#include "PmBaseCls\PmListCtrlCl.h"
#include "PmBaseCls\PmListCtrl.h "
#include "PmBaseCls\PMFileDialog.h"
#include "PmBaseCls\Rang.h"
#include "PmBaseCls\CXml\Xml.h"
#include "PmBaseCls\CXml\XmlNode.h"
#include "PmBaseCls\CXml\XmlNodes.h"
#include "PmBaseCls\CXml\Xsl.h"
#include "PmBaseCls\ListTree.h"
#include "PmBaseCls\HeaderColor.h"
#include "PmBaseCls\ScrollBarEx.h"

// 计算和二维操作的一些宏定义
//#define PT_DS2GE(ads) PmGePoint3d(ads[X],ads[Y],ads[Z])
//#define PT3DTOPT2D(pt) PmGePoint2d((pt).x,(pt).y)
//#define PT2DTOPT3D(pt) PmGePoint3d((pt).x,(pt).y,0)
//#define VCT3DTOVCT2D(vct) PmGeVector2d((vct).x,(vct).y)
//#define VCT2DTOVCT3D(vct) PmGeVector3d((vct).x,(vct).y,0)
//#define PERP(vct) PmGeVector3d(-(vct).y,(vct).x,0)			//往(0,0,1)转的垂直方向

#ifndef PI
#define PI 3.1415926535897932384626433832795
#endif

const double PaI = 3.1415926535897932384626433832795;

#ifndef TWOPI
#define TWOPI  6.28318530717958647692528676655901
#endif

#ifndef PI2
#define PI2 1.57079632679489661923132169163975
#endif

//度转弧度
#ifndef DTOR
#define DTOR(D) (D / 180.0 * PI)
#endif
//弧度转度
#ifndef RTOD
#define RTOD(D) (D / PI * 180.0)
#endif

#endif // !defined(AFX_PMBASECLASSH_H__9275C1AF_0EBC_4696_A5FB_3B57E00ADD03__INCLUDED_)
