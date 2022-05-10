// ExternSpecificGravityTable.h: interface for the CExternSpecificGravityTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNSPECIFICGRAVITYTABLE_H__8F62606E_FEBB_4CED_B6AE_EB9DDA05E136__INCLUDED_)
#define AFX_EXTERNSPECIFICGRAVITYTABLE_H__8F62606E_FEBB_4CED_B6AE_EB9DDA05E136__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../ExternManager.h"

class PMProjectDBSERVICE CExternSpecificGravityTable : public CExternTableBase   
{
protected:
	CExternSpecificGravityTable();
	virtual ~CExternSpecificGravityTable();
	
public:
	
	CSQLDataSet * GetDataSet();
};

#endif // !defined(AFX_EXTERNSPECIFICGRAVITYTABLE_H__8F62606E_FEBB_4CED_B6AE_EB9DDA05E136__INCLUDED_)
