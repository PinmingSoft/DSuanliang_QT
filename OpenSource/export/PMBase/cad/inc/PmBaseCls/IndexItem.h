// IndexItem.h: interface for the IndexItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INDEXITEM_H__3B71242B_6DBC_42F9_A48F_46E97FBA929A__INCLUDED_)
#define AFX_INDEXITEM_H__3B71242B_6DBC_42F9_A48F_46E97FBA929A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RegionItem.h"

typedef struct PMBASECLASSAPI _indexItem  
{
	double      _indexValue;
    PRegionItem _pRegionItem;
	BYTE        _flag;
} IndexItem,* PIndexitem;


#endif // !defined(AFX_INDEXITEM_H__3B71242B_6DBC_42F9_A48F_46E97FBA929A__INCLUDED_)
