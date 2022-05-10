// ExternFloorTable.h: interface for the CExternFloorTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNFLOORTABLE_H__269F9957_9908_4C02_97C8_E5753BD52CA5__INCLUDED_)
#define AFX_EXTERNFLOORTABLE_H__269F9957_9908_4C02_97C8_E5753BD52CA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"

class PMProjectDBSERVICE CExternFloorTable : public CExternTableBase
{
protected:

public:

	BOOL GetFloorDwgName(int iFloorID,CString & strDWGName);

	BOOL GetFloorName(int iFloorID,CString & strFloorName);

	CExternFloorTable();
	virtual ~CExternFloorTable();

	CSQLDataSet * GetDataSet();
};

#endif // !defined(AFX_EXTERNFLOORTABLE_H__269F9957_9908_4C02_97C8_E5753BD52CA5__INCLUDED_)
