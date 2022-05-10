#pragma once
// #include "..\..\accesstable.h"

class PMProjectDBSERVICE CAccessPublicGj_VectorGraphTable :
	public CPMSLAccessTable
{
public:
	CAccessPublicGj_VectorGraphTable(void);

	~CAccessPublicGj_VectorGraphTable(void);

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

	BOOL InsertVector(int iVectorID, int &iSysVectorID);

	BOOL GetTablCtrl_VectorID(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief 获取Vector的 绘制信息，Table 
	*
	*          
	* @note  : 目前只给CAccessSysData_VectorGraphTable使用
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [12/27/2018]
	*/
	BOOL GetVectorDrawInfo_Table(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);
};
