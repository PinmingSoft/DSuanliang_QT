#pragma once
//#include "..\accesstable.h"


class PMProjectDBSERVICE CAccessProject_GJJMInfoTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_GJJMInfoTable(void);

	virtual ~CAccessProject_GJJMInfoTable(void);

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	CSQLDataSet * GetEmptyDataSet();

	BOOL GetTable_MaxID(int & iMaxID);

	BOOL DelResultFloor_ComType(const CUIntArray &iFloorIDArr, const CUIntArray &iComTypeArr);

	/// ��ȡĳ��¥�����еļ������еľ��
	void GetHandleAtFloor(int iFloorID,CStringArray & arrHandle);

	//ɾ���������¥������
	BOOL DelResultFloor_Handle(int floorid,const CStringArray & handls);
};
