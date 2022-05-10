#pragma once
////#include "..\accesstable.h"


class CAccessProject_GraphMapTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_GraphMapTable(void);

	virtual ~CAccessProject_GraphMapTable(void);

	/**
	* @brief   ���� ������ṹ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/6/2012]
	*/
	virtual BOOL TryUpdateTableField();

	/*
	* @brief   ��������ͼ �ֽ�ͼID�� ��Ӧ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL Insert(int iSLVectorID,int iGJVectorID);

	/**
	* @brief ͨ���ֽ� VectorID  ��ȡ ����VectorID  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	int GetSLVectorID( int nGraphicsVectorID ) ;

	/**
	* @brief  ͨ�� ���� VectorID ��ȡ �ֽ� VectorID
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	int GetGraphicsVectorID( int nVectorID ) ;

	/**
	* @brief  ͨ�� �ֽ�VectoriD ��ȡ �ֽ�Vector �б� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL FindGJVectorList( const int & nGJVectorID , CString & strGJVectorIDs);

	/**
	* @brief  ͨ������ VectorID ����ȡ �ֽ� VectorID 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL GetGJVectorList_SLVectorID(int iSLVectorID,CString & strGJVectorIDs);

	/**
	* @brief  �ж�����VectorID �Ƿ�Ϸ� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL FindSLVector( const int & nVectorID );

	/**
	* @brief ɾ�� ָ���� slVectorID  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL DeleteInfo(int iSLVectorID);
};
