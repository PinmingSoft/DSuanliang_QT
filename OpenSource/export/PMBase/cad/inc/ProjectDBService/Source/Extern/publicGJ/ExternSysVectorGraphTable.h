// ExternSysVectorGraphTable.h: interface for the CExternSysVectorGraphTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNSYSVECTORGRAPHTABLE_H__74ACCE9D_F8C6_4ECE_B11D_3DD04C0B3155__INCLUDED_)
#define AFX_EXTERNSYSVECTORGRAPHTABLE_H__74ACCE9D_F8C6_4ECE_B11D_3DD04C0B3155__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternSysVectorGraphTable : public CExternTableBase 
{
protected:
	
public:

	CExternSysVectorGraphTable();
	virtual ~CExternSysVectorGraphTable();

	CSQLDataSet * GetDataSet();

};

#endif // !defined(AFX_EXTERNSYSVECTORGRAPHTABLE_H__74ACCE9D_F8C6_4ECE_B11D_3DD04C0B3155__INCLUDED_)
