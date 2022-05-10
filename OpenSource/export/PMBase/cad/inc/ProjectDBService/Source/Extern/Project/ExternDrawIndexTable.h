// ExternDrawIndexTable.h: interface for the CExternDrawIndexTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNDRAWINDEXTABLE_H__59715826_04D0_4757_8CC3_147B1A820584__INCLUDED_)
#define AFX_EXTERNDRAWINDEXTABLE_H__59715826_04D0_4757_8CC3_147B1A820584__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternDrawIndexTable : public CExternTableBase  
{
protected:
	
public:
	
	CExternDrawIndexTable();
	virtual ~CExternDrawIndexTable();
	
	CSQLDataSet * GetDataSet();
};

#endif // !defined(AFX_EXTERNDRAWINDEXTABLE_H__59715826_04D0_4757_8CC3_147B1A820584__INCLUDED_)
