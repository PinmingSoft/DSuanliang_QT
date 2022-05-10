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

	/// 获取某个楼层所有的计算结果中的句柄
	void GetHandleAtFloor(int iFloorID,CStringArray & arrHandle);

	//删除结果，按楼层与句柄
	BOOL DelResultFloor_Handle(int floorid,const CStringArray & handls);
};
