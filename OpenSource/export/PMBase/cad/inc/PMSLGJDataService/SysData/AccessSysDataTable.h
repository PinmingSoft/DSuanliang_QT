

#pragma once 





#include "..\AccessTable.h"
//#include "..\DbSqlConstName.h"
#include "..\PmSlGjDataService_Common.h"

/**
 * @brief ����SysData�Ļ���
 *
 *        
 * @author ����ҫ
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
	virtual BOOL TryUpdateTableField() = 0
	{
		return TRUE ;
	}

};
