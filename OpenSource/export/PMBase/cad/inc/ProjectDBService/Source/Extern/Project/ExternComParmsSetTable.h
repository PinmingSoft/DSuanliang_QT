// ExternComParmsSetTable.h: interface for the CExternComParmsSetTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNCOMPARMSSETTABLE_H__11727DE4_A40A_44CE_8640_98C524212D5D__INCLUDED_)
#define AFX_EXTERNCOMPARMSSETTABLE_H__11727DE4_A40A_44CE_8640_98C524212D5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternComParmsSetTable : public CExternTableBase 
{
protected:
	
	
public:
	
	CExternComParmsSetTable();
	virtual ~CExternComParmsSetTable();
	
	CSQLDataSet * GetDataSet();
};

#endif // !defined(AFX_EXTERNCOMPARMSSETTABLE_H__11727DE4_A40A_44CE_8640_98C524212D5D__INCLUDED_)
