#pragma once

#include "ConnectManager.h"

//#include "DbSqlConstName.h"

#include "PmSlGjDataService_Common.h "

#include "DataBaseAndTableName.h"

/**
* @brief ���ݿ���� ����  
*		���ڷ�װ���ݷ���
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: ����ҵ
* @date  : [16/1/2014]
*/
class PmSLGJDataServiceAPI CPMSLAccessTable
{
public:
	CPMSLAccessTable(void);
	virtual ~CPMSLAccessTable(void);

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
	virtual BOOL TryUpdateTableField() = 0;

	/// 
	/// ��ȡ���Ӧ��Index 
	/// ���ص���ö�ٱ��� : CPmTable::TableName
	/// 
	virtual	int	 GetTableIndex()  
	{
		return eTableIndex_Init ;
	}

	/// ��ȡ����������
	int GetMaxValue(CString fieldName,CString tableName);

protected:

	CConnect_sqlite * m_pDbBaseCtrl;//�Ƕ�д���ݿ�Ŀ��� ָ��
};
