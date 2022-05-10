

#pragma once 

////#include "..\accesstable.h"


class PMProjectDBSERVICE CAccessProject_TtymjResultTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_TtymjResultTable(void);

	~CAccessProject_TtymjResultTable(void);

public:
	virtual BOOL TryUpdateTableField();
	BOOL DelResultFloor_ComType( const CUIntArray &iFloorIDArr, const CUIntArray &iComTypeArr);
	void DeleteDirtyData();
	CSQLDataSet * GetDataSet();
	void DelResultFloor_Handle(int floorid,const CStringArray & handls);
	void GetHandleAtFloor(int iFloorID,CStringArray & handls);
};
