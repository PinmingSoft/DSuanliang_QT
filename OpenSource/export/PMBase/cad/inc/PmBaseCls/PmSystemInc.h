// PmSystemInc.h: interface for the CPmSystemInc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMSYSTEMINC_H__05B05720_546E_4F4F_A24B_FA24BF0BD3A7__INCLUDED_)
#define AFX_PMSYSTEMINC_H__05B05720_546E_4F4F_A24B_FA24BF0BD3A7__INCLUDED_
// ***************************************************************
//  PmSystemInc   version:  1.0   ? date: 02/20/2009
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2009 - All Rights Reserved
//  作者:clz
// ***************************************************************
// 文件说明:跟cad无关的系统头文件,如果需要一定的封装的话放在这里
//			
//			目的：隔离系统头文件变化
// ***************************************************************

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _ttof
	#ifdef _UNICODE
		#if _MSC_VER >= 1300
			#define _ttof _wtof
		#else
			#pragma message("当前编译器版本目前不支持_wtof")
		#endif
	#else
		#define _ttof atof
	#endif
#endif

//定义一个无效的输出
#define  PrintErrorMessage 	TRACE


#endif // !defined(AFX_PMSYSTEMINC_H__05B05720_546E_4F4F_A24B_FA24BF0BD3A7__INCLUDED_)
