#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CAccessPublicGj_VectorGraphGraphicsTable :
	public CPMSLAccessTable
{
public:
	CAccessPublicGj_VectorGraphGraphicsTable(void);

	~CAccessPublicGj_VectorGraphGraphicsTable(void);

	virtual BOOL TryUpdateTableField();

	/**
	* @brief 删除 指定VectorID的 图形  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	BOOL DeleteVector_VectorID(int iVectorID);

	/**
	* @brief  插入配筋图 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [20/7/2012]
	*/
	BOOL InsertVector(int iVectorID, int &iSysVectorID);

	BOOL GetTablCtrl_VectorID(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);
};
