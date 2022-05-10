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

	BOOL InsertVector(int iVectorID, int &iSysVectorID);

	BOOL GetTablCtrl_VectorID(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief ��ȡVector�� ������Ϣ��Table 
	*
	*          
	* @note  : Ŀǰֻ��CAccessSysData_VectorGraphTableʹ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [12/27/2018]
	*/
	BOOL GetVectorDrawInfo_Table(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);
};
