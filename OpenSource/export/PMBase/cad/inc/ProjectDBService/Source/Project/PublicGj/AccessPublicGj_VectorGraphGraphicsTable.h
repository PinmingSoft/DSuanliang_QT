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
	* @brief ɾ�� ָ��VectorID�� ͼ��  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	BOOL DeleteVector_VectorID(int iVectorID);

	/**
	* @brief  �������ͼ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [20/7/2012]
	*/
	BOOL InsertVector(int iVectorID, int &iSysVectorID);

	BOOL GetTablCtrl_VectorID(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);
};
