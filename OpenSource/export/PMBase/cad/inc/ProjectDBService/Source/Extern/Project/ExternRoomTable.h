// ExternRoomTable.h: interface for the CExternRoomTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNROOMTABLE_H__E00EAF00_3685_476F_8C6C_A936F5A2ABEC__INCLUDED_)
#define AFX_EXTERNROOMTABLE_H__E00EAF00_3685_476F_8C6C_A936F5A2ABEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../ExternManager.h"
class PMProjectDBSERVICE CExternRoomTable : public CExternTableBase 
{
protected:

	BOOL ReSetComID_Str(int iFloorID, int iComType, CString & strNewComId);

	BOOL GetNewComId(int iFloorID, int iComType, CString strComName, int &iNewComId);

public:
	
	CExternRoomTable();
	virtual ~CExternRoomTable();

	void ClearDataSet();

	BOOL Import2Project(int iFloorID);

	CSQLDataSet * GetDataSet();

};

#endif // !defined(AFX_EXTERNROOMTABLE_H__E00EAF00_3685_476F_8C6C_A936F5A2ABEC__INCLUDED_)
