//*******************************************************************************
// COPYRIGHT NOTES
// ---------------
// This is a part of the DataSet Library
// Copyright (C) 1998-2000 
// All rights reserved.
//
// 
// Add By zhangym 2003.6.12
// 
//*******************************************************************************
// dataset.h

#ifndef __DATASETH_H
#define __DATASETH_H

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
//

/// 
/// 本模块需要依赖的头文件
/// 
#include <map>
#include <vector>
#include <PmArxVersion.h>
#include <PMBaseOprH.h >

#ifndef DATASETDLLEXPORT
#	ifdef _PRJ_DATASET
#		define DATASETDLLEXPORT __declspec(dllexport)
#	else
#		define DATASETDLLEXPORT __declspec(dllimport)
#		pragma comment(lib, "dataset" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#		pragma message("link dataset" PM_FOR_VERSION _PMLIB_PLATFORM ".lib")
#	endif
#endif


/// 本模块导出的头文件
#include ".\dataset\dataset\NDataField.h"
#include ".\dataset\dataset\NDataFields.h"
#include ".\dataset\dataset\NDataModelDataSet.h"
#include ".\dataset\dataset\NDataModelDataSetBuffer.h"
#include ".\dataset\dataset\NDateTimeField.h"
#include ".\dataset\dataset\NFloatField.h"
#include ".\dataset\dataset\NIntegerField.h"
#include ".\dataset\dataset\NNumericField.h"
#include ".\dataset\dataset\NStringField.h"
#include ".\dataset\dataset\NDataModelDataSet_Clone.h"
#include ".\dataset\dataset\NDataModelDataSet_ShareData.h"
#include ".\dataset\dataset\PM_StorageDataSet.h"
#include ".\dataset\dataset\PM_SharebufferDataSet.h"
#include ".\dataset\dataset\PM_LargeFileDataSet.h"
//#include ".\dataset\dataset\PM_LinkDataSet.h"
#include ".\dataset\dataset\PMSQLBaseCtrl.h"
#include ".\dataset\dataset\SQLDataSet.h"
#include ".\dataset\dataset\PM_TranStringDataSet.h"

#include ".\dataset\dataset\NDbDataSet.h"
//
///// comdb
/// comdb
#include ".\dataset\comdb\CComDB.h "
#include ".\dataset\comdb\DBFactory.h "



/// SQLiteCtrl
#include <dataset\SQLiteCtrl\sqlite3.h>
#include <dataset\SQLiteCtrl\SqliteDBBase.h>
#include <dataset\Timing_V2.h>
#include <dataset\CmdTiming.h>

#endif // __DATASETH_H
