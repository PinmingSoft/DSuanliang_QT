// ExternVectorGraph_GJTable.h: interface for the CExternVectorGraph_GJTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNVECTORGRAPH_GJTABLE_H__7E80D66B_C466_4A5E_8AA8_131751F74C1A__INCLUDED_)
#define AFX_EXTERNVECTORGRAPH_GJTABLE_H__7E80D66B_C466_4A5E_8AA8_131751F74C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "../ExternManager.h"

class PMProjectDBSERVICE CExternVectorGraph_GJTable : public CExternTableBase   
{
protected:
	
	
public:
	
	CExternVectorGraph_GJTable();
	virtual ~CExternVectorGraph_GJTable();
	CSQLDataSet * GetDataSet();
	
};

#endif // !defined(AFX_EXTERNVECTORGRAPH_GJTABLE_H__7E80D66B_C466_4A5E_8AA8_131751F74C1A__INCLUDED_)
