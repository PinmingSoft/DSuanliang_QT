#pragma once
////#include "..\accesstable.h"


class PMProjectDBSERVICE CAccessProject_RoomTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_RoomTable(void);
	virtual ~CAccessProject_RoomTable(void);

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

	BOOL DelResultFloor(const CUIntArray &iFloorIDArr);

	/// ��ȡĳ��¥�����еļ������еľ��
	void GetHandleAtFloor(int iFloorID,CStringArray & arrHandle);

	//ɾ���������¥������
	BOOL DelResultFloor_Handle(int floorid,const CStringArray & handls);
};
