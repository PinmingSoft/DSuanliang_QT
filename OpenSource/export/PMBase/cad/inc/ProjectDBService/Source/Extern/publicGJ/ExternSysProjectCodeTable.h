// ExternSysProjectCodeTable.h: interface for the CExternSysProjectCodeTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNSYSPROJECTCODETABLE_H__742653EB_7DCB_4049_BC59_1BD97D25AEB9__INCLUDED_)
#define AFX_EXTERNSYSPROJECTCODETABLE_H__742653EB_7DCB_4049_BC59_1BD97D25AEB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternSysProjectCodeTable  : public CExternTableBase
{
protected:
	CExternSysProjectCodeTable();
	virtual ~CExternSysProjectCodeTable();

public:

	CSQLDataSet * GetDataSet();

	BOOL GetProjectVersion(CString & strVersion) ; 
	BOOL SetProjectVersion(CString strVersion) ;

public:

	 
};

#endif // !defined(AFX_EXTERNSYSPROJECTCODETABLE_H__742653EB_7DCB_4049_BC59_1BD97D25AEB9__INCLUDED_)
