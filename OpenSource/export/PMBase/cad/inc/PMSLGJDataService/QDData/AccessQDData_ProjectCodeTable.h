#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CAccessQDData_ProjectCodeTable :
	public CPMSLAccessTable
{
public:
	CAccessQDData_ProjectCodeTable(void);

	virtual ~CAccessQDData_ProjectCodeTable(void);

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


	/**
	* @brief  获取所有 内容  
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	/**
	* @brief 获取 指定清单库 是否可以 递增清单编号
	*
	*          
	* @note  : 数据库中 没有设置这个值就按递增处理。
	* @param : 
	* @defenc: 
	* @return: TRUE:递增编号 FALSE:不递增编号
	* @author: 王建业
	* @date  : [2/2/2012]
	*/
	BOOL GetNeedCalQDID();

	
protected:

	/**
	* @brief 判断 消耗量定额  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [24/8/2012]
	*/
	BOOL CheckNeedXHL_DE();

public:
	BOOL CheckNeedXHL_DE( const CString & strDeKuName );


};
