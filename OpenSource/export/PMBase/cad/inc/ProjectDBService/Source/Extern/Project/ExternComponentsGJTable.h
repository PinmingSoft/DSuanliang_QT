// ExternComponentsGJTable.h: interface for the CExternComponentsGJTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNCOMPONENTSGJTABLE_H__987B24FE_61B1_4BE0_961B_7D0B7E466C49__INCLUDED_)
#define AFX_EXTERNCOMPONENTSGJTABLE_H__987B24FE_61B1_4BE0_961B_7D0B7E466C49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternComponentsGJTable : public CExternTableBase 
{
protected:

public:
	CExternComponentsGJTable();
	virtual ~CExternComponentsGJTable();

	CSQLDataSet * GetDataSet();

	/**
	* @brief   获取 DataSet
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/6/2012]
	*/
	BOOL GetDataSet_FloorComType(int iFloorID,int iComType,CSQLDataSet *& pComponentDataSet);
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 编辑零星钢筋的构件表
class PMProjectDBSERVICE CExternCustomSteelComponentsTable : public CExternTableBase 
{
protected:

public:
	CExternCustomSteelComponentsTable();
	virtual ~CExternCustomSteelComponentsTable();

	CSQLDataSet * GetDataSet();
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 编辑零星构件的结果表
class PMProjectDBSERVICE CExternCustomSteelResultTable : public CExternTableBase 
{
protected:

public:
	CExternCustomSteelResultTable();
	virtual ~CExternCustomSteelResultTable();

	CSQLDataSet * GetDataSet();
};

#endif // !defined(AFX_EXTERNCOMPONENTSGJTABLE_H__987B24FE_61B1_4BE0_961B_7D0B7E466C49__INCLUDED_)
