// ApplayFloorGjxxToParms.h: interface for the CApplayFloorGjxxToParms class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMAPPLAYFLOORGJXXTOPARMS_H__26552EB7_5A31_482E_91CE_8169699A74A7__INCLUDED_)
#define AFX_PMAPPLAYFLOORGJXXTOPARMS_H__26552EB7_5A31_482E_91CE_8169699A74A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// ***************************************************************
//  ApplayFloorGjxxToParms   version:  1.0   ? date: 06/10/2009
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2009 - All Rights Reserved
// ***************************************************************
// �ļ�˵��:�����㷨
//			���ڹ�����Ϣ����Ҫ���� ¥���(FloorID  ) , ��������(ComType) 
//			ȥ FloorGjxx �и��µ� ComParmsSet_Tatal ��  ,��ȥ ComParmsSet_Tatal ��ȡ
//			
//����Ĭ�Ϲ��� : ���еĶ�������Ҫ���£�ȫ������/��������
//
//������ϢӦ�õ����� : ֻ��Ҫ���� ������Ϣ
//
//�������� Ӧ�õ� ���� : ֻ��3��������Ҫ���� ( GJWG , GJJSGZ , GJZS )
//
//�������� Ӧ�õ����� :  �������õ�Ӧ�� ���漰�� ComParmsSet_Tatal ��
//
//������� Ӧ�õ����� : ComParmsSet_Tatal �ļ���������Ӧ��
//
//
// ***************************************************************
class PMProjectDBSERVICE CPMApplayFloorGjxxToParms  
{
public:
	
	static void RemoveDirtyData() ;

	CPMApplayFloorGjxxToParms();
	virtual ~CPMApplayFloorGjxxToParms();

private:
//	NDataModelDataSet * m_pDataSet ;
/// ����Ĭ�Ϲ���
	static void InitData(NDataModelDataSet *& pComParmDataSet,int nFloor ,int nComType );
	static void InitData2(NDataModelDataSet *& pComParmDataSet,int nFloor , int nComType ) ;

	/// ֻ�����ṹ��������Ķ���
	static void InitDataGjxx(NDataModelDataSet *& pComParmDataSet,int nFloor ,int nComType );


//	CString GetValue(int nFloor,  CString strParmName , NDataModelDataSet * pGjxxDataSet ) ;
//	void SetMgDj(NDataModelDataSet * pComParmDataSet, int nFloor , int nComType) ;
//	void SetMgDj2( NDataModelDataSet * pComParmDataSet, int nFloor , int nComType) ;

	static void InitDataJsgz(NDataModelDataSet *& pJSSZDataSet);

	static CString GetParmValue(NDataModelDataSet * pComParmDataSet,CString strParmName , int nSubComType );


/// Ϣ�ֽ���Ϣ Ӧ�õ����� - ͼ�η�
//	void InitDataTotal( int nFloor , int nComType )  ;
/// ������
//	void InitDataTotal2(  int nFloor , int nComType )  ; 

/// �������� Ӧ�õ�����
	static void InitDataJssz( int nComType ,NDataModelDataSet *& pJSSZDataSet) ;

	static void SetComParms( NDataModelDataSet * pDefComParmDataSet , NDataModelDataSet * pComParmDataSet ) ;

public:
	/// �����ʽ Ӧ�õ� ����
	static void ApplyDjxsToProject() ;
	/// �������� Ӧ�õ� ����
	static void ApplyGjsxToProject() ;
	/// �������� Ӧ�õ�����
	static void ApplyJsszToProject() ;
	/// ������� Ӧ�õ�����
	static void ApplyJsgzToProject() ;
	/// �ֽ���Ϣ Ӧ�õ�����
	static void ApplyGjxxToProject();
	/// ����ģ���е�Ĭ�Ϲ���
	static void UpdateDefalutComponents( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype);
	static void UpdateDefalutComponents2() ;



///ע�ͣ�����ҫ [2009��12��23��]                                  
///Ӧ�õ����� ����� ¥��� ����
///��ѡ��

//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// �ֽ���Ϣ
	/// Ӧ�õ� ͼ�η�
	static void ApplyGjxxToProject( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

	/// Ӧ�õ�������
	static void ApplyGjxxToProject2( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype
		) ;

	/// Ӧ��
	static void ApplyGjxxToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype ,
		const CUIntArray & arr_graphcomtype 
		) ;

//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// �����ʽ
	/// Ӧ�õ� ͼ�η�
	static void ApplyDjxsToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

	/// Ӧ�õ�������
	static void ApplyDjxsToProject2( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype
		) ;

	/// Ӧ��
	static void ApplyDjxsToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype ,
		const CUIntArray & arr_graphcomtype 
		) ;
//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	///��������
	/// Ӧ�õ� ͼ�η�
	static void ApplyGjsxToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

	/// Ӧ�õ�������
	static void ApplyGjsxToProject2( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype
		) ;

	/// Ӧ��
	static void ApplyGjsxToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype ,
		const CUIntArray & arr_graphcomtype 
		) ;

//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	///�������
	/// Ӧ�õ� ͼ�η�
	static void ApplyJsgzToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

	/// Ӧ�õ�������
	static void ApplyJsgzToProject2( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype
		) ;

	/// Ӧ��
	static void ApplyJsgzToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype ,
		const CUIntArray & arr_graphcomtype 
		) ;

//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	///��������
	/// Ӧ�õ� ͼ�η�
	static void ApplyJsszToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

};

#endif // !defined(AFX_APPLAYFLOORGJXXTOPARMS_H__26552EB7_5A31_482E_91CE_8169699A74A7__INCLUDED_)
