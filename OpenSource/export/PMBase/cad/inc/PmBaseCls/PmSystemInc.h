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
//  ����:clz
// ***************************************************************
// �ļ�˵��:��cad�޹ص�ϵͳͷ�ļ�,�����Ҫһ���ķ�װ�Ļ���������
//			
//			Ŀ�ģ�����ϵͳͷ�ļ��仯
// ***************************************************************

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _ttof
	#ifdef _UNICODE
		#if _MSC_VER >= 1300
			#define _ttof _wtof
		#else
			#pragma message("��ǰ�������汾Ŀǰ��֧��_wtof")
		#endif
	#else
		#define _ttof atof
	#endif
#endif

//����һ����Ч�����
#define  PrintErrorMessage 	TRACE


#endif // !defined(AFX_PMSYSTEMINC_H__05B05720_546E_4F4F_A24B_FA24BF0BD3A7__INCLUDED_)
