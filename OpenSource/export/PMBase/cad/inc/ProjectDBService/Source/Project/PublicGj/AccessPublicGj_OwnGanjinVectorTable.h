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
	* @brief  ��ȡ �Զ��� �ֽ� Buffer 
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	BOOL GetOwnGangjinVector(int iComID,LPVOID & pBuffer,long & lBufferSize);

	/**
	* @brief  �޸� �Զ���ֽ� ��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	BOOL SetOwnGangJinVector(int iComID,LPVOID pBuffer,long lBufferSize);

	/**
	* @brief  ɾ�� �Զ���ֽ� ��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	BOOL RemoveOwnGangJinVector(int iComID);
};
