#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CAccessDEData_ProjectCodeTable :
	public CPMSLAccessTable
{
public:
	CAccessDEData_ProjectCodeTable(void);

	virtual ~CAccessDEData_ProjectCodeTable(void);

	/**
	* @brief   ���� ������ṹ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/6/2012]
	*/
	virtual BOOL TryUpdateTableField();

};
