// ExternProjectInfoTable.h: interface for the CExternProjectInfoTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNPROJECTINFOTABLE_H__1A594347_991E_413B_BD75_7AC8FEA60A35__INCLUDED_)
#define AFX_EXTERNPROJECTINFOTABLE_H__1A594347_991E_413B_BD75_7AC8FEA60A35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../ExternManager.h"
class PMProjectDBSERVICE CExternProjectInfoTable : public CExternTableBase
{
protected:
	
public:

	CExternProjectInfoTable();
	virtual ~CExternProjectInfoTable();

	CSQLDataSet * GetDataSet();

	/**
	* @brief 获取清单模式
	*
	*        
	* @author 郑琪崇
	* @version v1.0
	* @date  2015年10月15日   18:23
	* @note  
	*/
	BOOL GetProjectQDMode(CString & strQdMode);

	/**
	* @brief  获取参数中 指定参数名的 对应值 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	BOOL GetProjectInfo_ParmValue(const CString & strParmName,CString & strParmValue);
	//获取 用户 清单 定额 信息
	BOOL GetDefaultValueOfQDDE(BOOL &bQDMode,CString &strQDName,CString &strDEName);
};

#endif // !defined(AFX_EXTERNPROJECTINFOTABLE_H__1A594347_991E_413B_BD75_7AC8FEA60A35__INCLUDED_)
