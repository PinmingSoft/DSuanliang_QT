// ExternComFolderTable.h: interface for the CExternComFolderTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNCOMFOLDERTABLE_H__26AB6A72_B1E4_4625_B2AE_28B6E809B3A6__INCLUDED_)
#define AFX_EXTERNCOMFOLDERTABLE_H__26AB6A72_B1E4_4625_B2AE_28B6E809B3A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternComFolderTable : public CExternTableBase 
{

public:
	
	CExternComFolderTable();
	virtual ~CExternComFolderTable();

public:

	CSQLDataSet * GetDataSet();

	CSQLDataSet * GetNotRepeatComFolder( ) ;

	/// 
};

#endif // !defined(AFX_EXTERNCOMFOLDERTABLE_H__26AB6A72_B1E4_4625_B2AE_28B6E809B3A6__INCLUDED_)
