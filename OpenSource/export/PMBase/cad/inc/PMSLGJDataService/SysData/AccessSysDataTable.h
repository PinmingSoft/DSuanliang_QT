

#pragma once 





#include "..\AccessTable.h"
//#include "..\DbSqlConstName.h"
#include "..\PmSlGjDataService_Common.h"

/**
 * @brief 连接SysData的基类
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class  PmSLGJDataServiceAPI CSysDataTable : public CSQLDataSet
{
public:
	CSysDataTable() ;
	~CSysDataTable() ;

	virtual int InitFieldStr() = 0 ;

public:
	
};

class  PmSLGJDataServiceAPI CAccessSysDataTable : public CPMSLAccessTable
{
public:
	CAccessSysDataTable() ;

	~CAccessSysDataTable() ;

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
	virtual BOOL TryUpdateTableField() = 0
	{
		return TRUE ;
	}

};
