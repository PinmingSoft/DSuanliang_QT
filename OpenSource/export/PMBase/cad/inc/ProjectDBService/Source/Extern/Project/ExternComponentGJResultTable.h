// ExternComponentGJResultTable.h: interface for the CExternComponentGJResultTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNCOMPONENTGJRESULTTABLE_H__D9FE957F_DDD4_41F1_9EAF_A3F8B9539334__INCLUDED_)
#define AFX_EXTERNCOMPONENTGJRESULTTABLE_H__D9FE957F_DDD4_41F1_9EAF_A3F8B9539334__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternComponentGJResultTable : public CExternTableBase  
{
protected:
	

public:
	void ClearDataSet();

	CExternComponentGJResultTable();
	virtual ~CExternComponentGJResultTable();

	CSQLDataSet * GetDataSet();
	CSQLDataSet * GetDataSet(int iComID);
};

#endif // !defined(AFX_EXTERNCOMPONENTGJRESULTTABLE_H__D9FE957F_DDD4_41F1_9EAF_A3F8B9539334__INCLUDED_)
