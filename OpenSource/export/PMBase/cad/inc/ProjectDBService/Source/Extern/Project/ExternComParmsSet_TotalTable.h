// ExternComParmsSet_TotalTable.h: interface for the CExternComParmsSet_TotalTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNCOMPARMSSET_TOTALTABLE_H__762899A6_43EE_4BBA_B11F_66923E7EF104__INCLUDED_)
#define AFX_EXTERNCOMPARMSSET_TOTALTABLE_H__762899A6_43EE_4BBA_B11F_66923E7EF104__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternComParmsSet_TotalTable : public CExternTableBase   
{
protected:
	
	
public:
	
	CExternComParmsSet_TotalTable();
	virtual ~CExternComParmsSet_TotalTable();
	
	CSQLDataSet * GetDataSet();
	
};

#endif // !defined(AFX_EXTERNCOMPARMSSET_TOTALTABLE_H__762899A6_43EE_4BBA_B11F_66923E7EF104__INCLUDED_)
