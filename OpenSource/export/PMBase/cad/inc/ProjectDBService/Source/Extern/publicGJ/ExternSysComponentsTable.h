// ExternSysComponentsTable.h: interface for the CExternSysComponentsTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNSYSCOMPONENTSTABLE_H__0A1A52F5_4842_433A_ADA0_BBA4916C907A__INCLUDED_)
#define AFX_EXTERNSYSCOMPONENTSTABLE_H__0A1A52F5_4842_433A_ADA0_BBA4916C907A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternSysComponentsTable : public CExternTableBase
{
protected:	

public:

	CExternSysComponentsTable();
	virtual ~CExternSysComponentsTable();

	CSQLDataSet * GetDataSet();

};

#endif // !defined(AFX_EXTERNSYSCOMPONENTSTABLE_H__0A1A52F5_4842_433A_ADA0_BBA4916C907A__INCLUDED_)
