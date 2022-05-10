// ExternSysVectorGraphGraphicsTable.h: interface for the CExternSysVectorGraphGraphicsTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNSYSVECTORGRAPHGRAPHICSTABLE_H__AB3EBE28_013F_4F1C_A057_3F39BEF8F6ED__INCLUDED_)
#define AFX_EXTERNSYSVECTORGRAPHGRAPHICSTABLE_H__AB3EBE28_013F_4F1C_A057_3F39BEF8F6ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternSysVectorGraphGraphicsTable : public CExternTableBase 
{

protected:
	

public:

	CExternSysVectorGraphGraphicsTable();
	virtual ~CExternSysVectorGraphGraphicsTable();

	CSQLDataSet * GetDataSet();

};

#endif // !defined(AFX_EXTERNSYSVECTORGRAPHGRAPHICSTABLE_H__AB3EBE28_013F_4F1C_A057_3F39BEF8F6ED__INCLUDED_)
