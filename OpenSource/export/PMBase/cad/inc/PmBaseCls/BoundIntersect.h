// BoundIntersect.h: interface for the CBoundIntersect class.
//  ���ڼ������
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

	// ���þ���
	static void setTol(double dTol);
	static double getTol();

	/**
	* @brief   ��ȡ�����ѡ���
	*
	*          ��ϸ����
	* @note  : 
	* @param : 
	* @return: 
	* @author: dwg
	* @history:zfy ���ע�� [7/11/2014]
	* @date  : [7/11/2014]
	*/
	void GetInBound(std::vector<BoundInItem*> &boundInItems);
	void GetInBound(std::vector<BoundInItem> &boundInItems);

	/// �����������������������������GetInBound
	void AddRegion(REGIONID objectID,double* points);

	/**
	* @brief   ��ȡ�����ѡ���
	*
	*          Ҫ��des Ԫ���� srcԪ�ز��ظ�
	* @note  : 
	* @param : boundInItemsDes  :des ��ѡ src�� ���
	* @param : boundInItemsSrc  :src ��ѡ des�� ���
	* @return: 
	* @author: dwg
	* @history:zfy ���ע�� [7/11/2014]
	* @date  : [7/11/2014]
	*/
	void GetInBound(std::vector<BoundInItem> &boundInItemsDes,std::vector<BoundInItem> &boundInItemsSrc);
	/// bIsSrcΪ�Ƿ���boundInItemsSrc���У������������������������������GetInBound
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
	static double m_dTol;	//����
};

typedef struct _boundInSetItem  
{
	PRegionItem _RegionItem;
	std::vector<REGIONID> _boundIns;
} BoundInSetItem,* PBoundInSetItem;


#endif // !defined(AFX_BOUNDINTERSECT_H__87EE6F71_674C_42D7_902C_7419D6700858__INCLUDED_)
