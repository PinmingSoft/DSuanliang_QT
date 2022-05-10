// ExternFloorBGModeTable.h: interface for the CExternFloorBGModeTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNFLOORBGMODETABLE_H__4E84228C_5845_468A_874A_10CCBB84DDBE__INCLUDED_)
#define AFX_EXTERNFLOORBGMODETABLE_H__4E84228C_5845_468A_874A_10CCBB84DDBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternFloorBGModeTable : public CExternTableBase   
{
protected:
	
	
public:
	
	CExternFloorBGModeTable();
	virtual ~CExternFloorBGModeTable();

	CSQLDataSet * GetDataSet();
	
};

#endif // !defined(AFX_EXTERNFLOORBGMODETABLE_H__4E84228C_5845_468A_874A_10CCBB84DDBE__INCLUDED_)
