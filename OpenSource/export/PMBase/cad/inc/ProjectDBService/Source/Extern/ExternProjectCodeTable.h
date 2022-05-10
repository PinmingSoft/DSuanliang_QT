// ExternProjectCodeTable.h: interface for the CExternProjectCodeTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNPROJECTCODETABLE_H__57044E6A_A396_49A8_85CA_671152894AE9__INCLUDED_)
#define AFX_EXTERNPROJECTCODETABLE_H__57044E6A_A396_49A8_85CA_671152894AE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ExternManager.h"
class PMProjectDBSERVICE CExternProjectCodeTable : public CExternTableBase
{
protected:

public:
	
	CExternProjectCodeTable();
	virtual ~CExternProjectCodeTable();

	BOOL GetProjectCode(CString & strVersion) ; 

	CSQLDataSet * GetDataSet();

};

#endif // !defined(AFX_EXTERNPROJECTCODETABLE_H__57044E6A_A396_49A8_85CA_671152894AE9__INCLUDED_)
