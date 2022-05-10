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

	/**
	* @brief  插入配筋图 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL InsertVector(int iComType,const CString & strVectorName,const CString & strBZ,\
						LPVOID pVectorBuffer,long lVectorBufferSize,LPVOID pInfoBuffer,long lInfoBuffSize,int & iNewVectorID);

	/**
	* @brief   设置vectorinfo 信息，该信息为长宽高、体信息
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
	* @brief   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL GetOwnGangJinVector_VectorID(int iVectorID,LPVOID & pGangJinVector,long & lGangjinVectorSize);

	/**
	* @brief 保存 自定义钢筋 绘制 信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL SetOwnGangJinVector_VectorID(int iVectorID,LPVOID pGangJinVector,long lGangJinVectorSize);

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
	BOOL GetVectorDrawInfo_Table_old(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief 获取 指定VectorID 对应的 TableCtrl  
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
	* @brief   获取 Vector Bz  
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
