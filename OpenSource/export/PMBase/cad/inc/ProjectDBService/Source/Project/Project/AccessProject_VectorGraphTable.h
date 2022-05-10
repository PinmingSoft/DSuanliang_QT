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
    * @brief 设置iVectorID的备注信息
    *
    *        用于设置自定义柱截面的备注信息
    * @author hn
    * @version v1.0
    * @date   
    * @note  
    */
 	BOOL SetVectorIDBz(int iVectorID,const CString & strBz);
	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief  获取Vector的 绘制信息，Table 
	*
	*          
	* @note  : 目前只给CAccessSysData_VectorGraphTable使用
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	BOOL GetVectorDrawInfo_Table(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief  通过VectorID 获取所有的 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [20/7/2012]
	*/
	BOOL GetTableCtrl_VectorID(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief  获取 配筋图 图形绘制 Buffer 
	*
	*          
	* @note  : pVectorBuffer 需要删除 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL GetVectorGraph_VectorID(int iVectorID,LPVOID & pVectorBuffer,long & lVectorBufferSize);

	/**
	* @brief 将配筋图信息 进行保存  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL SetVectorGraph_VectorID(int iVectorID,LPVOID pVectorBuffer,long lVectorBufferSize);

	BOOL SetVectorInfo_VectorID(int iVectorID,LPVOID pVectorInfoBuffer,long lVectorInfoBufferSize);

	BOOL InsertVector(int iComType,const CString & strVectorName,const CString & strBZ,\
		LPVOID pVectorBuffer,long lVectorBuffer,LPVOID pInfoBuffer,long lInfoBuffSize,int & iNewVectorID);

	/**
	* @brief  获取 VectorName 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL GetVectorName_VectorID(int iVectoriD,CString & strVectorName);

	/**
	* @brief  删除指定的VectorID 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL DeleteVector_VectorID(int iVectorID);

	/**
	* @brief 获取 Vector Bz  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL GetVectorBz_VectorID(int iVectorID,CString & strBz);

	/**
	* @brief 获取 配筋图 DataSet  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/7/2012]
	*/
	CSQLDataSet * GetDataSet();
};
