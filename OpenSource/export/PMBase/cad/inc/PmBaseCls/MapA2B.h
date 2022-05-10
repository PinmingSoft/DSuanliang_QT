// MapA2B.h: interface for the CMapA2B class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPA2B_H__A8824381_FDB3_4021_8BE8_34F7B8C7FEDF__INCLUDED_)
#define AFX_MAPA2B_H__A8824381_FDB3_4021_8BE8_34F7B8C7FEDF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ***************************************************************
//  MapA2B   version:  1.0   ? date: 09/04/2008
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2008 - All Rights Reserved
// ***************************************************************
// 文件说明:仅用于支持"="号的TA到TB类型的匹配
// 注意事项:
// 作    者:ZFY
// ***************************************************************

#ifdef _DEBUG
#define _DEBUG_ZLL_WAS_DEFINED
#undef _DEBUG
#pragma message ("		连接MFC、STD、run-timing用Release")
#endif

#include <afxtempl.h>

#ifdef _DEBUG_ZLL_WAS_DEFINED
#define _DEBUG
#undef _DEBUG_ZLL_WAS_DEFINED
#endif

template<class TA,class TB>
class CMapItem  
{
public:
	CMapItem(){};
	~CMapItem(){}
	CMapItem(TA key,TB value)
	{
		m_key = key;
		m_value = value;
	}

	CMapItem(const CMapItem & src)
	{
		m_key = src.m_key;
		m_value = src.m_value;
	}

	void operator = (const CMapItem & src)
	{
		m_key = src.m_key;
		m_value = src.m_value;
	}

	const TA & GetKey() const {return m_key;}
	const TB & GetValue() const {return m_value;}
	void SetKey(TA value){m_key = value;}
	void SetValue(TB value){m_value = value;}
protected:
	TA m_key;
	TB m_value;
};

template<class TA,class TB> class CMapA2BArray
{
public:
	typedef CMapItem<TA,TB> MAPITEM;
	CMapA2BArray(){};
	~CMapA2BArray(){};
	void Add(TA key,const TB & value)
	{
		MAPITEM itm(key,value);
		m_maps.Add(itm);
	};
	void Copy(const CMapA2BArray<TA,TB> & src)
	{
		m_maps.Copy(src.m_maps);
	}
	void Remove(TA key)
	{
		int idx = LookUp(key);
		if (idx != -1)
		{
			RemoveAt(idx);
		}
	};
	void RemoveAt(int idx)
	{
		m_maps.RemoveAt(idx);
	}
	void RemoveAll()
	{
		m_maps.RemoveAll();
	}
	int  LookUp(const TA & key) const 
	{
		int iSize = PmCast::ToInt(m_maps.GetSize());
		for (int i = 0;i < iSize;i++)
		{
			const MAPITEM & itm = m_maps[i];
			const TA & keyDes = itm.GetKey();
			if (key == keyDes)
			{
				return i;
			}
		}
		return -1;
	};
	BOOL GetValue(const TA & key,TB & value) const 
	{
		int idx = LookUp(key);
		if (idx == -1)
		{
			return FALSE;
		}
		else
		{
			value = GetValueAt(idx);
			return TRUE;
		}
	}

	TB   GetValueAt(int idx) const 
	{
		const MAPITEM & itm = m_maps.GetAt(idx);
		return itm.GetValue();
	}
	BOOL SetValue(const TA & key,const TB & value)
	{
		int idx = LookUp(key);
		if (idx == -1)
		{
			return FALSE;
		}
		else
		{
			SetValueAt(idx,value);
			return TRUE;
		}		
	}
	BOOL SetOrAddValue(const TA & key,const TB & value)
	{
		int idx = LookUp(key);
		if (idx == -1)
		{			
			Add(key,value);
		}
		else
		{
			SetValueAt(idx,value);
		}
		return TRUE;
	}

	void SetValueAt(int idx,const TB & value)
	{
		MAPITEM & itm = m_maps.ElementAt(idx);
		itm.SetValue(value);
	}
	const TA &  GetKey(int idx) const 
	{
		const MAPITEM & itm = m_maps.GetAt(idx);
		return itm.GetKey();
	}
	/// 左右交换
	void Swap(int idx1,int idx2)
	{
		MAPITEM item = m_maps.GetAt(idx1);
		m_maps[idx1] = m_maps[idx2];
		m_maps[idx2] = item;
	}
	int  GetSize() const {return PmCast::ToInt(m_maps.GetSize());}

	// 获取value元素
	TB&			operator [] (int idx)
	{
		return m_maps[idx];
	}
	const TB &	operator [] (int idx) const
	{
		return m_maps[idx];
	}

protected:
	CArray<MAPITEM> m_maps;

};

#endif // !defined(AFX_MAPA2B_H__A8824381_FDB3_4021_8BE8_34F7B8C7FEDF__INCLUDED_)
