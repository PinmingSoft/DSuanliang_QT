#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CAccessProject_SwlRoomTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_SwlRoomTable(void);
	virtual ~CAccessProject_SwlRoomTable(void);

	virtual BOOL TryUpdateTableField();

	/**
	* @brief �������м�¼��
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	//ɾ�� ���м�¼
	BOOL DeleteAllRow();

	BOOL GetTable_MaxID(int & iMaxID);

	CSQLDataSet * GetEmptyDataSet();

	BOOL DelResultFloor(CUIntArray &iFloorIDArr);

	/// ��ȡĳ��¥�����еļ������еľ��
	void GetHandleAtFloor(int iFloorID,CStringArray & arrHandle);

	//ɾ���������¥������
	BOOL DelResultFloor_Handle(int floorid,const CStringArray & handls);
};
