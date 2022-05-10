#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CAccessProject_VectorGraphTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_VectorGraphTable(void);
	virtual ~CAccessProject_VectorGraphTable(void);

	virtual BOOL TryUpdateTableField();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

    /**
    * @brief ����iVectorID�ı�ע��Ϣ
    *
    *        ���������Զ���������ı�ע��Ϣ
    * @author hn
    * @version v1.0
    * @date   
    * @note  
    */
 	BOOL SetVectorIDBz(int iVectorID,const CString & strBz);
	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

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

	/**
	* @brief  ͨ��VectorID ��ȡ���е� ��Ϣ 
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

	BOOL SetVectorInfo_VectorID(int iVectorID,LPVOID pVectorInfoBuffer,long lVectorInfoBufferSize);

	BOOL InsertVector(int iComType,const CString & strVectorName,const CString & strBZ,\
		LPVOID pVectorBuffer,long lVectorBuffer,LPVOID pInfoBuffer,long lInfoBuffSize,int & iNewVectorID);

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
	* @brief ��ȡ Vector Bz  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL GetVectorBz_VectorID(int iVectorID,CString & strBz);

	/**
	* @brief ��ȡ ���ͼ DataSet  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/7/2012]
	*/
	CSQLDataSet * GetDataSet();
};
