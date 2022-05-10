// ExternGraphicsResultTable.h: interface for the CExternGraphicsResultTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNGRAPHICSRESULTTABLE_H__CE111FA5_C7A5_4B1B_824C_77A803194CDA__INCLUDED_)
#define AFX_EXTERNGRAPHICSRESULTTABLE_H__CE111FA5_C7A5_4B1B_824C_77A803194CDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternGraphicsResultTable : public CExternTableBase 
{
protected:

public:

	BOOL Import2Project(int iFloorID);

	void ClearDataSet();

	CExternGraphicsResultTable();
	virtual ~CExternGraphicsResultTable();

	int InitFieldStr();

	CSQLDataSet * GetDataSet();
	NDbDataSet * GetDataSet(int iFloorID, int iComID);

	CSQLDataSet * GetDataSet( const CUIntArray & aryFloor , const CUIntArray  & aryComType ) ; 

	BOOL SaveDataSet();

};

#endif // !defined(AFX_EXTERNGRAPHICSRESULTTABLE_H__CE111FA5_C7A5_4B1B_824C_77A803194CDA__INCLUDED_)
