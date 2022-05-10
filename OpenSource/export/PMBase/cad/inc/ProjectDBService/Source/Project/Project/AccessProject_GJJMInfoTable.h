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

	/// 获取某个楼层所有的计算结果中的句柄
	void GetHandleAtFloor(int iFloorID,CStringArray & arrHandle);

	//删除结果，按楼层与句柄
	BOOL DelResultFloor_Handle(int floorid,const CStringArray & handls);
};
