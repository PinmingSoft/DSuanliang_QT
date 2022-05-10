#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CAccessProject_SwlGJJMInfoTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_SwlGJJMInfoTable(void);

	virtual ~CAccessProject_SwlGJJMInfoTable(void);

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	CSQLDataSet * GetEmptyDataSet();

	BOOL GetTable_MaxID(int & iMaxID);

	BOOL DelResultFloor_ComType(CUIntArray &iFloorIDArr, CUIntArray &iComTypeArr);

	/// ��ȡĳ��¥�����еļ������еľ��
	void GetHandleAtFloor(int iFloorID,CStringArray & arrHandle);

	//ɾ���������¥������
	BOOL DelResultFloor_Handle(int floorid,const CStringArray & handls);
};
