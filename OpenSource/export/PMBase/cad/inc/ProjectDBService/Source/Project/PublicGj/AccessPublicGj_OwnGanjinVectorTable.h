#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CAccessPublicGj_OwnGangjinVectorTable :
	public CPMSLAccessTable
{
public:
	CAccessPublicGj_OwnGangjinVectorTable(void);

	~CAccessPublicGj_OwnGangjinVectorTable(void);

	virtual BOOL TryUpdateTableField();

	/**
	* @brief  获取 自定义 钢筋 Buffer 
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	BOOL GetOwnGangjinVector(int iComID,LPVOID & pBuffer,long & lBufferSize);

	/**
	* @brief  修改 自定义钢筋 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	BOOL SetOwnGangJinVector(int iComID,LPVOID pBuffer,long lBufferSize);

	/**
	* @brief  删除 自定义钢筋 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	BOOL RemoveOwnGangJinVector(int iComID);
};
