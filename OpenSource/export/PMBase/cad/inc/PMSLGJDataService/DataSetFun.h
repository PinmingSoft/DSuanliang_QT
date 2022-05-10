// DataSetFun.h: interface for the CDataSetFun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATASETFUN_H__D3C2FD1D_832C_484B_A591_6F49301E72BB__INCLUDED_)
#define AFX_DATASETFUN_H__D3C2FD1D_832C_484B_A591_6F49301E72BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ***************************************************************
//  DataSetFun   version:  1.0   ? date: 05/05/2009
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2009 - All Rights Reserved
// ***************************************************************
// 文件说明:通用的与dataset操作相关的函数
// 注意事项:
// 作    者:ZFY
// ***************************************************************
namespace DataSetFun  
{
	//获取配筋图参数
	PmSLGJDataServiceAPI void GetParmsFromDataset(NDataModelDataSet *pDataSetInput,CParms & parms);
	PmSLGJDataServiceAPI void GetGrighParmsFromDataset(NDataModelDataSet *pDataSetInput,CParms & parms);

	int CompareRow(NDataModelDataSet * pDataSet,int rowSrc,const CUIntArray & cols,const CStringArray & itemToFindDes);
	PmSLGJDataServiceAPI int CompareRow(NDataModelDataSet * pDataSet,int rowSrc,const CStringArray & fields,const CStringArray & itemToFindDes);
	/**
	* @brief 对排过序的表进行折半查找，并返回找到的第一个行号,找不到返回-1
	*
	*          注意：一定要求pDataSet是已经按fields排序过了的
	* @note  : 
	* @param : fields 表示要查找的列，有序，前面的优先比对
	* @param : values 表示要查找的值，有序，与fields列一一对应
	* @defenc: 
	* @return: 如果找不到返回-1
	* @author: zfy
	* @date  : [5/14/2019]
	*/
	PmSLGJDataServiceAPI int FindFirstRow(NDataModelDataSet * pDataSet,const CStringArray & fields,const CStringArray & values);
	PmSLGJDataServiceAPI int FindFirstRow(NDataModelDataSet * pDataSet,const CUIntArray & cols,const CStringArray & itemToFind);
};

#endif // !defined(AFX_DATASETFUN_H__D3C2FD1D_832C_484B_A591_6F49301E72BB__INCLUDED_)
