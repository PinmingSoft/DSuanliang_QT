#pragma once
////#include "..\accesstable.h"


class CAccessProject_GraphMapTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_GraphMapTable(void);

	virtual ~CAccessProject_GraphMapTable(void);

	/**
	* @brief   尝试 升级表结构
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/6/2012]
	*/
	virtual BOOL TryUpdateTableField();

	/*
	* @brief   插入算量图 钢筋图ID的 对应
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL Insert(int iSLVectorID,int iGJVectorID);

	/**
	* @brief 通过钢筋 VectorID  获取 算量VectorID  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	int GetSLVectorID( int nGraphicsVectorID ) ;

	/**
	* @brief  通过 算量 VectorID 获取 钢筋 VectorID
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	int GetGraphicsVectorID( int nVectorID ) ;

	/**
	* @brief  通过 钢筋VectoriD 获取 钢筋Vector 列表 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL FindGJVectorList( const int & nGJVectorID , CString & strGJVectorIDs);

	/**
	* @brief  通过算量 VectorID ，获取 钢筋 VectorID 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL GetGJVectorList_SLVectorID(int iSLVectorID,CString & strGJVectorIDs);

	/**
	* @brief  判断算量VectorID 是否合法 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL FindSLVector( const int & nVectorID );

	/**
	* @brief 删除 指定的 slVectorID  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL DeleteInfo(int iSLVectorID);
};
