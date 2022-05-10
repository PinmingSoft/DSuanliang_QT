// BoundIntersect.h: interface for the CBoundIntersect class.
//  用于计算外包
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOUNDINTERSECT_H__87EE6F71_674C_42D7_902C_7419D6700858__INCLUDED_)
#define AFX_BOUNDINTERSECT_H__87EE6F71_674C_42D7_902C_7419D6700858__INCLUDED_


#include "RegionItem.h"
#include <map>
#include <string>
#include "IntersectIndex.h"
#include "BoundInItem.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PMBASECLASSAPI CBoundIntersect  
{
public:
	CBoundIntersect();
	virtual ~CBoundIntersect();

	// 设置精度
	static void setTol(double dTol);
	static double getTol();

	/**
	* @brief   获取互相框选结果
	*
	*          详细描述
	* @note  : 
	* @param : 
	* @return: 
	* @author: dwg
	* @history:zfy 添加注释 [7/11/2014]
	* @date  : [7/11/2014]
	*/
	void GetInBound(std::vector<BoundInItem*> &boundInItems);
	void GetInBound(std::vector<BoundInItem> &boundInItems);

	/// 本函数仅适用于上面的两个参数的GetInBound
	void AddRegion(REGIONID objectID,double* points);

	/**
	* @brief   获取互相框选结果
	*
	*          要求des 元素与 src元素不重复
	* @note  : 
	* @param : boundInItemsDes  :des 框选 src的 结果
	* @param : boundInItemsSrc  :src 框选 des的 结果
	* @return: 
	* @author: dwg
	* @history:zfy 添加注释 [7/11/2014]
	* @date  : [7/11/2014]
	*/
	void GetInBound(std::vector<BoundInItem> &boundInItemsDes,std::vector<BoundInItem> &boundInItemsSrc);
	/// bIsSrc为是否在boundInItemsSrc队列，本函数仅适用于上面的两个参数的GetInBound
	void AddRegion(REGIONID objectID,double* points,BOOL bIsSrc);

	//
	void RemoveRgion(REGIONID objectID);
	void ModifyRegion(REGIONID objectID,double* points);

	void Clear();

	//
	void Sort();
	
	CIntersectIndex * GetIntersectIndex(){return & m_xindex;}

	static void FreeMem_BoundVector(std::vector<BoundInItem*> &boundInItems);

protected:
//	void SearchInBound(STboundSet &boundDesSet,STboundSet &boundSrcSet,const BoundInSetItem compareBoundInSetItem,const PRegionItem pRegionItem);
	//vector<PRegionItem>  m_vectorRegionItems;
	std::map<REGIONID,PRegionItem> m_RegionItems;
	CIntersectIndex      m_xindex;
	BOOL m_sortdirty;
	static double m_dTol;	//精度
};

typedef struct _boundInSetItem  
{
	PRegionItem _RegionItem;
	std::vector<REGIONID> _boundIns;
} BoundInSetItem,* PBoundInSetItem;


#endif // !defined(AFX_BOUNDINTERSECT_H__87EE6F71_674C_42D7_902C_7419D6700858__INCLUDED_)
