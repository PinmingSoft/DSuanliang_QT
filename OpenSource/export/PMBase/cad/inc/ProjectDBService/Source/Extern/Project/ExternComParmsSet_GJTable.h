// ExternComParmsSet_GJTable.h: interface for the CExternComParmsSet_GJTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNCOMPARMSSET_GJTABLE_H__62812A14_DB7E_4C5F_B834_C7559723EB09__INCLUDED_)
#define AFX_EXTERNCOMPARMSSET_GJTABLE_H__62812A14_DB7E_4C5F_B834_C7559723EB09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternComParmsSet_GJTable : public CExternTableBase  
{
protected:
	
	
public:
	
	CExternComParmsSet_GJTable();
	virtual ~CExternComParmsSet_GJTable();
	
	CSQLDataSet * GetDataSet();
	
};

#endif // !defined(AFX_EXTERNCOMPARMSSET_GJTABLE_H__62812A14_DB7E_4C5F_B834_C7559723EB09__INCLUDED_)
