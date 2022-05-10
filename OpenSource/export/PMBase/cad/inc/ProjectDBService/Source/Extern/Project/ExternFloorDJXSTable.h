// ExternFloorDJXSTable.h: interface for the CExternFloorDJXSTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNFLOORDJXSTABLE_H__ABF43077_CDDB_48F8_842B_BB8C837ABD3C__INCLUDED_)
#define AFX_EXTERNFLOORDJXSTABLE_H__ABF43077_CDDB_48F8_842B_BB8C837ABD3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternFloorDJXSTable : public CExternTableBase
{
protected:
	
	
public:
	
	CExternFloorDJXSTable();
	virtual ~CExternFloorDJXSTable();
	
	CSQLDataSet * GetDataSet();
};

#endif // !defined(AFX_EXTERNFLOORDJXSTABLE_H__ABF43077_CDDB_48F8_842B_BB8C837ABD3C__INCLUDED_)
