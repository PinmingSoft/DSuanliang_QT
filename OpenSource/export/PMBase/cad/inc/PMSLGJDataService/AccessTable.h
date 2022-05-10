#pragma once

#include "ConnectManager.h"

//#include "DbSqlConstName.h"

#include "PmSlGjDataService_Common.h "

#include "DataBaseAndTableName.h"

/**
* @brief 数据库访问 基类  
*		用于封装数据访问
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: 王建业
* @date  : [16/1/2014]
*/
class PmSLGJDataServiceAPI CPMSLAccessTable
{
public:
	CPMSLAccessTable(void);
	virtual ~CPMSLAccessTable(void);

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
	virtual BOOL TryUpdateTableField() = 0;

	/// 
	/// 获取表对应的Index 
	/// 返回的是枚举变量 : CPmTable::TableName
	/// 
	virtual	int	 GetTableIndex()  
	{
		return eTableIndex_Init ;
	}

	/// 获取整形最大的数
	int GetMaxValue(CString fieldName,CString tableName);

protected:

	CConnect_sqlite * m_pDbBaseCtrl;//是读写数据库的控制 指针
};
