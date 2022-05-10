// ExternFloorGJXXInfoTable.h: interface for the CExternFloorGJXXInfoTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNFLOORGJXXINFOTABLE_H__6EF97310_6E81_4F7B_BB96_E378201395F8__INCLUDED_)
#define AFX_EXTERNFLOORGJXXINFOTABLE_H__6EF97310_6E81_4F7B_BB96_E378201395F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternFloorDJMGInfoTable : public CExternTableBase
{
protected:

public:

	CExternFloorDJMGInfoTable();
	virtual ~CExternFloorDJMGInfoTable();

	CSQLDataSet * GetDataSet();
};

class PMProjectDBSERVICE CExternFloorGJXXInfoTable : public CExternTableBase  
{
protected:
	
	
public:
	
	CExternFloorGJXXInfoTable();
	virtual ~CExternFloorGJXXInfoTable();
	
	CSQLDataSet * GetDataSet();
};

#endif // !defined(AFX_EXTERNFLOORGJXXINFOTABLE_H__6EF97310_6E81_4F7B_BB96_E378201395F8__INCLUDED_)
