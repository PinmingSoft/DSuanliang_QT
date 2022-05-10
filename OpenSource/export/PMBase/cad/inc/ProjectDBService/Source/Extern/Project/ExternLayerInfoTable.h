// ExternLayerInfoTable.h: interface for the CExternLayerInfoTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNLAYERINFOTABLE_H__B552DA38_05C5_460C_9E17_518ADD341038__INCLUDED_)
#define AFX_EXTERNLAYERINFOTABLE_H__B552DA38_05C5_460C_9E17_518ADD341038__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternLayerInfoTable : public CExternTableBase
{
protected:
	
public:

	CExternLayerInfoTable();
	virtual ~CExternLayerInfoTable();

	CSQLDataSet * GetDataSet();
};

#endif // !defined(AFX_EXTERNLAYERINFOTABLE_H__B552DA38_05C5_460C_9E17_518ADD341038__INCLUDED_)
