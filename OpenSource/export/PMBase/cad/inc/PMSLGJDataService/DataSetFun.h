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
// �ļ�˵��:ͨ�õ���dataset������صĺ���
// ע������:
// ��    ��:ZFY
// ***************************************************************
namespace DataSetFun  
{
	//��ȡ���ͼ����
	PmSLGJDataServiceAPI void GetParmsFromDataset(NDataModelDataSet *pDataSetInput,CParms & parms);
	PmSLGJDataServiceAPI void GetGrighParmsFromDataset(NDataModelDataSet *pDataSetInput,CParms & parms);

	int CompareRow(NDataModelDataSet * pDataSet,int rowSrc,const CUIntArray & cols,const CStringArray & itemToFindDes);
	PmSLGJDataServiceAPI int CompareRow(NDataModelDataSet * pDataSet,int rowSrc,const CStringArray & fields,const CStringArray & itemToFindDes);
	/**
	* @brief ���Ź���ı�����۰���ң��������ҵ��ĵ�һ���к�,�Ҳ�������-1
	*
	*          ע�⣺һ��Ҫ��pDataSet���Ѿ���fields������˵�
	* @note  : 
	* @param : fields ��ʾҪ���ҵ��У�����ǰ������ȱȶ�
	* @param : values ��ʾҪ���ҵ�ֵ��������fields��һһ��Ӧ
	* @defenc: 
	* @return: ����Ҳ�������-1
	* @author: zfy
	* @date  : [5/14/2019]
	*/
	PmSLGJDataServiceAPI int FindFirstRow(NDataModelDataSet * pDataSet,const CStringArray & fields,const CStringArray & values);
	PmSLGJDataServiceAPI int FindFirstRow(NDataModelDataSet * pDataSet,const CUIntArray & cols,const CStringArray & itemToFind);
};

#endif // !defined(AFX_DATASETFUN_H__D3C2FD1D_832C_484B_A591_6F49301E72BB__INCLUDED_)
