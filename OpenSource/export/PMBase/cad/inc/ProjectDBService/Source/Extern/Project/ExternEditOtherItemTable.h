// ExternEditOtherItemTable.h: interface for the CExternEditOtherItemTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNEDITOTHERITEMTABLE_H__2BE7453B_C2C0_4414_9E54_5E35D77EB90C__INCLUDED_)
#define AFX_EXTERNEDITOTHERITEMTABLE_H__2BE7453B_C2C0_4414_9E54_5E35D77EB90C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternEditOtherItemTable : public CExternTableBase
{
protected:

public:

	BOOL Import2Project(int iFloorID);
	void ClearDataSet();

	CExternEditOtherItemTable();
	virtual ~CExternEditOtherItemTable();

	CSQLDataSet * GetDataSet();
};

#endif // !defined(AFX_EXTERNEDITOTHERITEMTABLE_H__2BE7453B_C2C0_4414_9E54_5E35D77EB90C__INCLUDED_)
