// ExternResultTable.h: interface for the CExternResultTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNRESULTTABLE_H__70CB2FDF_705A_498D_AB49_3C0C8C38F571__INCLUDED_)
#define AFX_EXTERNRESULTTABLE_H__70CB2FDF_705A_498D_AB49_3C0C8C38F571__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"

class PMProjectDBSERVICE CExternResultTable : public CExternTableBase 
{
protected:
	

public:

	CExternResultTable();
	virtual ~CExternResultTable();

	BOOL Import2Project(int iFloorID);

	void ClearDataSet();

	CSQLDataSet * GetDataSet();
	NDbDataSet * GetDataSet(int iFloorID, int iComType, int iComID);

	CSQLDataSet * GetDataSet( const CUIntArray & aryFloor , const CUIntArray  & aryComType ) ;

};

class PMProjectDBSERVICE CExternSWLResultTable : public CExternResultTable 
{
protected:


public:

	CExternSWLResultTable();
	virtual ~CExternSWLResultTable();


	CSQLDataSet * GetDataSet();

	CSQLDataSet * GetDataSet( const CUIntArray & aryFloor , const CUIntArray  & aryComType ) ;

};

#endif // !defined(AFX_EXTERNRESULTTABLE_H__70CB2FDF_705A_498D_AB49_3C0C8C38F571__INCLUDED_)
