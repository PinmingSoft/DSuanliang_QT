#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CAccessDEData_ProjectCodeTable :
	public CPMSLAccessTable
{
public:
	CAccessDEData_ProjectCodeTable(void);

	virtual ~CAccessDEData_ProjectCodeTable(void);

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

};
