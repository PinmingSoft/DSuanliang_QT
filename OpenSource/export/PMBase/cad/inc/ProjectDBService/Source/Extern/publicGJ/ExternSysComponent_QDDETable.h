// ExternSysComponent_QDDETable.h: interface for the CExternSysComponent_QDDETable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNSYSCOMPONENT_QDDETABLE_H__85866734_815A_48B2_94BE_1B999DED7799__INCLUDED_)
#define AFX_EXTERNSYSCOMPONENT_QDDETABLE_H__85866734_815A_48B2_94BE_1B999DED7799__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"

class PMProjectDBSERVICE CExternSysComponent_QDDETable : public CExternTableBase
{
protected:

public:
	BOOL GetQDDE_ComID(int iComID,CString & strQDDE);

	CExternSysComponent_QDDETable();
	virtual ~CExternSysComponent_QDDETable();

	CSQLDataSet * GetDataSet();
};

#endif // !defined(AFX_EXTERNSYSCOMPONENT_QDDETABLE_H__85866734_815A_48B2_94BE_1B999DED7799__INCLUDED_)
