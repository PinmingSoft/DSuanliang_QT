// BoundInItem.h: interface for the CBoundInItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOUNDINITEM_H__F288415C_1098_4E1D_BFC8_1D5072892347__INCLUDED_)
#define AFX_BOUNDINITEM_H__F288415C_1098_4E1D_BFC8_1D5072892347__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>

typedef struct _boundInItem  
{
  REGIONID    _objectID;
  std::vector<REGIONID> _boundIns;
} BoundInItem,* PBoundInItem;

#endif // !defined(AFX_BOUNDINITEM_H__F288415C_1098_4E1D_BFC8_1D5072892347__INCLUDED_)
