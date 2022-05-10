#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CAccessProject_VectorGraphGraphicsTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_VectorGraphGraphicsTable(void);
	virtual ~CAccessProject_VectorGraphGraphicsTable(void);

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	/**
	* @brief  ��ȡ ���ͼ ͼ�λ��� Buffer 
	*
	*          
	* @note  : pVectorBuffer ��Ҫɾ�� 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL GetVectorGraph_VectorID(int iVectorID,LPVOID & pVectorBuffer,long & lVectorBufferSize);

	/**
	* @brief �����ͼ��Ϣ ���б���  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL SetVectorGraph_VectorID(int iVectorID,LPVOID pVectorBuffer,long lVectorBufferSize);

	/**
	* @brief  �������ͼ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL InsertVector(int iComType,const CString & strVectorName,const CString & strBZ,\
						LPVOID pVectorBuffer,long lVectorBufferSize,LPVOID pInfoBuffer,long lInfoBuffSize,int & iNewVectorID);

	/**
	* @brief   ����vectorinfo ��Ϣ������ϢΪ����ߡ�����Ϣ
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [6/8/2020]
	*/
	BOOL SetVectorInfo_VectorID(int iVectorID,LPVOID pVectorInfoBuffer,long lVectorInfoBufferSize);

	/**
	* @brief  ��ȡ VectorName 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL GetVectorName_VectorID(int iVectoriD,CString & strVectorName);

	/**
	* @brief  ɾ��ָ����VectorID 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL DeleteVector_VectorID(int iVectorID);

	/**
	* @brief   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL GetOwnGangJinVector_VectorID(int iVectorID,LPVOID & pGangJinVector,long & lGangjinVectorSize);

	/**
	* @brief ���� �Զ���ֽ� ���� ��Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL SetOwnGangJinVector_VectorID(int iVectorID,LPVOID pGangJinVector,long lGangJinVectorSize);

	/**
	* @brief  ��ȡVector�� ������Ϣ��Table 
	*
	*          
	* @note  : Ŀǰֻ��CAccessSysData_VectorGraphTableʹ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	BOOL GetVectorDrawInfo_Table(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);
	BOOL GetVectorDrawInfo_Table_old(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief ��ȡ ָ��VectorID ��Ӧ�� TableCtrl  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [20/7/2012]
	*/
	BOOL GetTableCtrl_VectorID(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief   ��ȡ Vector Bz  
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [6/4/2020]
	*/
	BOOL GetVectorBz_VectorID(int iVectorID,CString & strBz);
};
