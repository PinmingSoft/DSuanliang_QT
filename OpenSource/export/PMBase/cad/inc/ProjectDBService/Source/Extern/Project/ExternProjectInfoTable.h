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
	* @brief ��ȡ�嵥ģʽ
	*
	*        
	* @author ֣����
	* @version v1.0
	* @date  2015��10��15��   18:23
	* @note  
	*/
	BOOL GetProjectQDMode(CString & strQdMode);

	/**
	* @brief  ��ȡ������ ָ���������� ��Ӧֵ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	BOOL GetProjectInfo_ParmValue(const CString & strParmName,CString & strParmValue);
	//��ȡ �û� �嵥 ���� ��Ϣ
	BOOL GetDefaultValueOfQDDE(BOOL &bQDMode,CString &strQDName,CString &strDEName);
};

#endif // !defined(AFX_EXTERNPROJECTINFOTABLE_H__1A594347_991E_413B_BD75_7AC8FEA60A35__INCLUDED_)
