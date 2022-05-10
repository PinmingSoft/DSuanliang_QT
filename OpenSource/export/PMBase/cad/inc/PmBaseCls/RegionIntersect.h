// RegionIntersect.h: interface for the CRegionIntersect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REGIONINTERSECT_H__CB531EFF_9194_4100_999F_A9EB6AB61C1B__INCLUDED_)
#define AFX_REGIONINTERSECT_H__CB531EFF_9194_4100_999F_A9EB6AB61C1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RegionItem.h"
#include <map>
#include <string>
#include "IntersectIndex.h"
#include "BoundInItem.h"

typedef void (_stdcall *ClearSimMem_CallBak)(REGIONID regionId);
class PMBASECLASSAPI CRegionIntersect  
{
public:
	//void GetInBound(vector<BoundInItem> &boundInItems);
	REGIONID number;
	void Clear();

	bool ClearMem(ClearSimMem_CallBak simMemFun);

	CRegionIntersect();
	
	virtual ~CRegionIntersect();
	void AddRegion(REGIONID objectID,double* points);
	void RemoveRgion(REGIONID objectID);
	void ModifyRegion(REGIONID objectID,double* points);
	//取得和points范围内的所有可能相交的ids，objectid用于排除与当前ID一样的值
	void GetIntersects(double* points,REGIONID objectid,std::vector<REGIONID> &resultArray);
	void Sort();
protected:
	std::map<REGIONID,PRegionItem> m_RegionItems;
	CIntersectIndex      m_IntersectIndexs[4];
	std::vector<PRegionItem>  m_vectorRegionItems;
	BOOL m_sortdirty;
};

#endif // !defined(AFX_REGIONINTERSECT_H__CB531EFF_9194_4100_999F_A9EB6AB61C1B__INCLUDED_)
