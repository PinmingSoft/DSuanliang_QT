// IntersectIndex.h: interface for the CIntersectIndex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INTERSECTINDEX_H__A365CBC5_3459_467C_8256_5434ED310885__INCLUDED_)
#define AFX_INTERSECTINDEX_H__A365CBC5_3459_467C_8256_5434ED310885__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
#include "IndexItem.h"
//using namespace std;

class PMBASECLASSAPI CIntersectIndex  
{
public:
	CIntersectIndex(int size);
	CIntersectIndex();
	virtual ~CIntersectIndex();

	// 设置精度
	static void setTol(double dTol);
	static double getTol();

    void QSort();
	void QXSort();
	void Reset();
	void Init(int size);
	void Add(IndexItem item);
	bool Mod(double oldIndexValue,double newIndexValue,IndexItem item);
	bool Del(double IndexValue,IndexItem item);
    int  FindLowerbound(double IndexValue);
	int  FindUpperbound(double IndexValue);
	int  GetCount();
	void EraseAll()
	{
		m_index.erase(m_index.begin(),m_index.end());
	}
	std::vector<IndexItem>& GetIndex()
	{
		return m_index;
	}
	
	std::vector<IndexItem>::iterator Lowerbound(double IndexValue);
	std::vector<IndexItem>::iterator Upperbound(double IndexValue);
	std::vector<IndexItem>::iterator begin();
	std::vector<IndexItem>::iterator end();
	protected:
	std::vector<IndexItem>::iterator FindItem(double IndexValue,const IndexItem item);
private:
	std::vector<IndexItem>  m_index;
	static double m_dTol;	//精度
};

#endif // !defined(AFX_INTERSECTINDEX_H__A365CBC5_3459_467C_8256_5434ED310885__INCLUDED_)
