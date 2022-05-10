// RegionItem.h: interface for the RegionItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REGIONITEM_H__9316AF41_8F4A_4104_8571_D6B0B965A4D2__INCLUDED_)
#define AFX_REGIONITEM_H__9316AF41_8F4A_4104_8571_D6B0B965A4D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
//using namespace std;
#if PMVCCUR_VER < PMVC2005_VER
	typedef long REGIONID;
#else
	typedef PmInt REGIONID;
#endif

/**
 * @brief  :可以用于objectid的int值,指针对象
 *
 *          不能用于句柄的高低位组合成的64位整数
 * @author :zfy
 * @version:v1.0
 * @date   :[8/6/2014]
 * @note   :
 */
typedef struct PMBASECLASSAPI _regionItem  
{
	REGIONID    _objectID;
	double _points[4];
    TCHAR   _flag;
    //vector<REGIONID> _list;
	_regionItem()
	{
		_objectID = -1;
	}
} RegionItem,* PRegionItem;

#endif // !defined(AFX_REGIONITEM_H__9316AF41_8F4A_4104_8571_D6B0B965A4D2__INCLUDED_)
