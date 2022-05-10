// ManageVectorGraph.h: interface for the CManageVectorGraph class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Project_MANAGEVECTORGRAPH_H__EE1FFC83_E229_404F_B62A_94E2ECECED3A__INCLUDED_)
#define AFX_Project_MANAGEVECTORGRAPH_H__EE1FFC83_E229_404F_B62A_94E2ECECED3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include ".\project\PMVectorGraphicCtrl.h"
// ***************************************************************
//  ManageVectorGraph   version:  1.0   ? date: 08/31/2009
//  -------------------------------------------------------------
//  �������ͼ�εĽӿ�
//  -------------------------------------------------------------
//  Copyright (C) 2009 - All Rights Reserved
// ***************************************************************
// �ļ�˵��:
// ***************************************************************
class PMProjectDBSERVICE CProject_ManageVectorGraph  
{
private:

public:
	
	CProject_ManageVectorGraph();
	virtual ~CProject_ManageVectorGraph();

	/**
	* @brief ɾ�����ͼ ��Ӧ����Ϣ  
	*
	*          zfy note 2020.06.08, v9.9 ��ʼ��������ɾ�� �ֽ����ͼ
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [23/4/2012]
	*/
	static BOOL DelVector_AllInfo(int iVectorID);
	
	static int GetVectorID( const int nGraphicsVector );

	/**
	* @brief  ͨ���ֽ��VectorID ��ȡ �Զ���ֽ� Buffer BufferSize��Ϣ
	*
	*          
	* @note  : ������ pBuffer ��Ҫɾ��
	* @param : int iGJVectorID,LPVOID & pBuffer,int & lBufferSize
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [24/4/2012]
	*/
	static BOOL GetOwnGangjinInfo(int iGJVectorID,LPVOID & pBuffer,long & lBufferSize);

	/**
	* @brief  ���Զ���ֽ���Ϣ ���浽 ���ݿ��� 
	*
	*          
	* @note  : ��Ŀǰֻ���� ѡͼ������ ������Ϣ
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [24/4/2012]
	*/
	static BOOL SetOwnGangJinInfo(int iGJVectorID,LPVOID pBuffer,int lBufferSize);

	/// ���� Bz 
	//static BOOL GetSLVectorBzInfo(int iSLVectorID, CString & strBz);
	//static BOOL SetSLVectorBzInfo(int iVectorID,const CString & strBz);

	/// ��ȡ/���� Bz
	static BOOL GetGJVectorBzInfo(int iSLVectorID, CString & strBz);

	/// ��ȡ ComType
	static BOOL GetVectorComType(int iVectorID, int &iComType) ;
	static BOOL GetVectorGraphicsComType( int iVectorID , int & iComType ) ;

	/// ȡ VectorName 
	//static BOOL GetSLVectorName(int iVectorID, CString &strVectorName) ;
	static BOOL GetGJVectorName( int iVectorID , CString & strVectorName ) ;

	/// ���� VectorName
	//static BOOL SetSLVectorName(int iVectorID, CString strVectorName) ;
	static BOOL SetGJVectorName(int iVectorID, CString strVectorName) ;

	/// ���� ��ע
	static BOOL SetGJVectorBz(int iSLVectorID, CString strBz);
	static BOOL GetGJVectorBz(int iSLVectorID, CString &strBz);
	/// ���� VectorInfo �е����ݣ��¸ֽ�ʸ��ͼ ����Ҳ�����ַ�ʽ��ȡ
	static BOOL SetSLVectorInfo(int iSLVectorID, CPMVectorEntityInfo * pVectorEntityInfo) ;
//	BOOL SetVectorGraphicsInfo(int iVectorID, CString strVectorInfo) ;

	/**
	* @brief    ��ȡ VectorInfo �� �����ݣ��¸ֽ�ʸ��ͼ ����Ҳ�����ַ�ʽ��ȡ
	*
	*			������Ϊ�������ݣ�������ʸ��ͼͼ �ĳ����� ������polyline , ��� �������ϵ�
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [6/9/2020]
	*/
	static BOOL GetSLVectorInfo(int iSLVectorID, CPMVectorEntityInfo *& pVectorEntityInfo) ;
	static BOOL GetSLVectorInfo(int iSLVectorID, LPVOID& pbuff, long & buffSize) ;
//	BOOL GetGJVectorInfo(int iGJVectorID, CString &strVectorInfo) ;

	/**
	* @brief  ��ȡ ����ͼ�ε� ���ƣ�pbuff ��Ҫɾ��  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	//static BOOL GetSLVectorData(int iSLVectorID, LPVOID& pbuff, long & buffSize) ;

	/**
	* @brief ��ȡ vectorgraph ����Ϣ ������ �ֽ�ͼ ����   pbuff ��Ҫɾ��
	*
	*          ��vector ������ ���ͼ����ͼԪ������ͬ��
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	static BOOL GetGJVectorData(int iGJVectorID, LPVOID& pbuff, long & buffSize) ;

	/// ���� VectorGraph 
	//static BOOL SetSLVectorData(int iSLVectorID, LPVOID pbuff, long buffSize) ;
	static BOOL SetGJVectorData(int iGJVectorID, LPVOID pbuff, long buffSize) ;

	/// ���� Vector 
	static BOOL InsertVector2Project(int iComType, const CString & strVectorName,CMemFile * pMemFile,\
		LPVOID pVectorInfoBuffer,long lVectorInfoBufferSize,const CString & strBz,int & iGJVectorID);


	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// ���� �������ģʽ : nSoftMode , �� ͼ��ID :  strVectorID
	/// strVectorID �ĺ�����λ ���� 50  ���ͼ�ž��� �ֽ�ͼ�η��е�
	/// �� nSoftMode == 1 ��ʱ�� ֱ�ӿ��� ���� strVectorID 
	/// �� nSoftMode == 0 ��ʱ�� ����Ҫȥ GraphMap �в����� strVectorID ��Ӧ��
	/// ������ strVectorID 
	/// ��֮ ��Ȼ
	//static int GetVectorID( int nSoftMode , int nVectorID ) ;
	//static CString GetVectorID( int nSoftMode ,CString strVectorID ) ;

	/**
	* @brief   ͨ���ֽ�� VectorID ��ȡ ������ VectorID
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [24/11/2011]
	*/
	//static int GJVectorID2SLVectorID(int nVectorID);

	/******************************************************************** 
	 �������������������� VectorID  ȥ��ȡͼ�η��� VectorID 
		zfy note 2020.06.02 . ��Ϊ�󲿷ֵ��÷����ǹ̶�ͼ�ŵķ��ʣ��ݲ��޸ģ��Է�ֹͼ��������������
	 ������ 
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҫ
	 ʱ    �䣺[2009��9��8��]
	*********************************************************************/ 
	//static BOOL GetGraphicsVector( const int nVectorIndex , int & nGraphicsVectorIndex );

	/******************************************************************** 
	 �����������ж� ���ͼ nVectorID1 �� nVectorID2 �Ƿ� ��Ӧͬһ������ͼ
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҫ
	 ʱ    �䣺[2009��9��10��]
	*********************************************************************/ 
	static BOOL HaveSameJm( const int nGraphicsVectorID1 , const int nGraphicsVectorID2);

	/// ��ȡ��̨�����ͼ��
	static int GetCtVectorID( const int &nVectorID );
//	CMap<int , const int & , int  , const int & > m_map_ctvectormap ;

	static NDataModelDataSet * GetBzctPamrs( int nComID );
	
	/**
	* @brief   ��ȡĳ vectorid ƥ��� vectorid ��������ʸ��ͼѡ��Ի����еĲ�ι�ϵ
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [6/4/2020]
	*/
	static BOOL FindGJVectorList( const int &nVectorID  , CString & strVectorIDs );


	// ***************************************************************
	//  ����ҫע��  ʱ��:2010��04��23��
	//  -------------------------------------------------------------
	//  ����: �����й����� ͼ��id ���м�� 
	//  -------------------------------------------------------------
	//  ����ֵ:
	//  -------------------------------------------------------------
	//  ����:
	// ***************************************************************
	//  ע������:
	// ***************************************************************
	static void UpdateVector() ; 

	// �ղؼеĲ��� [2010-4-27 by ����ҫ]
	// ����ֵ	0 : û�иı�
	//			1 : ������ͼ�� id �ı�
	//			2 : �ֽ��ͼ�� id �ı�
	//			3 : ���� �� �ֽ�� id ���ı� 
	static int OperatePublicComponent(int & nGraphicVectorID ) ; 

	/// ɾ���ղع����� ͼ��
	static void DelPublicComponent( int nComID ) ; 
	//  ���ղؼ���Ӧ�õ����̵�ʱ��
	//  ���Զ���ͼ�� ���뵽 �����ļ�
	static int Insert2Project( CString &strGraphicVectorID ) ; 

	/// �����ղ� ��������ȡͼ������ --- ����ͼ
	//static BOOL GetPublicVectorData(int ID, LPVOID& pbuff, long & buffSize) ; 

	/// �����ղ� ��������ȡͼ������ --- �ֽ�ͼ
	static BOOL GetPublicVectorData_Gj(int ID, LPVOID& pbuff, long & buffSize) ;

	/// �����ղأ��ֽ�ʸ��ͼ������ʸ��ͼ��idת��
	//static int PublicGJVectorID2SLVectorID(int nVectorID);

	/// �����ղأ���ȡ����ͼ��vectorinfo
	static BOOL GetPublicSLVectorInfo(int iSLVectorID, CPMVectorEntityInfo *& pVectorEntityInfo);
	
	/// ��� ͼ��ID �Ƿ����
	//static BOOL FindGraphVector( const int & nVectorID ) ;
	static BOOL FindGraphicsGraphVector( const int & nVectorID ) ; 

	/// ����ComType ��ȡ �ʼ�� ComType 
	//static BOOL GetVectorID( const int & nComType , int & nVectorID , int & nVectorID_Gj ) ; 


	/// ����ֻ�� ���� ����ͼ�ĵط��õ�
	/// �� GraphMap �в��� ������ VectorID 
	//static BOOL Find( const int & nVectorID ) ; 

	/// �ж�
	//static int Find( const int & nVectorID ,  int & nVectorID_Gj ) ;

protected:
		
	/// ɾ��ָ��ͼ��
	//static BOOL DeleteSLVectorID(int iVectorID) ;
	static BOOL DeleteGJVectorID(int iVectorID) ;

	//��ȡvectorinfo ��Ϣ
	static BOOL GetVectorDrawInfo_Table(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);
};




#endif // !defined(AFX_Project_MANAGEVECTORGRAPH_H__EE1FFC83_E229_404F_B62A_94E2ECECED3A__INCLUDED_)
