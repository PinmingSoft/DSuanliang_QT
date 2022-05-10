// ExternGraphicsResultTable.h: interface for the CExtern3DGraphicsResultTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERN3DGRAPHICSRESULTTABLE_H__CE111FA5_C7A5_4B1B_824C_77A803194CDA__INCLUDED_)
#define AFX_EXTERN3DGRAPHICSRESULTTABLE_H__CE111FA5_C7A5_4B1B_824C_77A803194CDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/**
 * @brief  ��ά�ֽ�ļ�������
 *
 *        
 * @author ���Ÿ�
 * @version v1.0
 * @date  2015��5��8��   
 * @note  
 */

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExtern3DGraphicsResultTable : public CExternTableBase 
{
protected:

public:

	BOOL Import2Project(int iFloorID);

	void ClearDataSet();

	CExtern3DGraphicsResultTable();
	virtual ~CExtern3DGraphicsResultTable();

	int InitFieldStr();

	CSQLDataSet * GetDataSet();
	NDbDataSet * GetDataSet(int iFloorID, int iComID);

	CSQLDataSet * GetDataSet( const CUIntArray & aryFloor , const CUIntArray  & aryComType ) ; 

	// ��ȡ���ڹ������ȶԵ����ݿ�
	CSQLDataSet * GetDataSet_Cmp( const CUIntArray & aryFloor , const CUIntArray & aryComType );

	BOOL SaveDataSet();

};

#endif // !defined(AFX_EXTERN3DGRAPHICSRESULTTABLE_H__CE111FA5_C7A5_4B1B_824C_77A803194CDA__INCLUDED_)
