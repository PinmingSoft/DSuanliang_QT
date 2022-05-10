#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CAccessQDData_ProjectCodeTable :
	public CPMSLAccessTable
{
public:
	CAccessQDData_ProjectCodeTable(void);

	virtual ~CAccessQDData_ProjectCodeTable(void);

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


	/**
	* @brief  ��ȡ���� ����  
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	/**
	* @brief ��ȡ ָ���嵥�� �Ƿ���� �����嵥���
	*
	*          
	* @note  : ���ݿ��� û���������ֵ�Ͱ���������
	* @param : 
	* @defenc: 
	* @return: TRUE:������� FALSE:���������
	* @author: ����ҵ
	* @date  : [2/2/2012]
	*/
	BOOL GetNeedCalQDID();

	
protected:

	/**
	* @brief �ж� ����������  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [24/8/2012]
	*/
	BOOL CheckNeedXHL_DE();

public:
	BOOL CheckNeedXHL_DE( const CString & strDeKuName );


};
