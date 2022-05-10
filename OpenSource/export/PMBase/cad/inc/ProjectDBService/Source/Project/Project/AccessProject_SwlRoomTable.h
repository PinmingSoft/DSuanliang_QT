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
	* @brief 返回所有记录集
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	//删除 所有记录
	BOOL DeleteAllRow();

	BOOL GetTable_MaxID(int & iMaxID);

	CSQLDataSet * GetEmptyDataSet();

	BOOL DelResultFloor(CUIntArray &iFloorIDArr);

	/// 获取某个楼层所有的计算结果中的句柄
	void GetHandleAtFloor(int iFloorID,CStringArray & arrHandle);

	//删除结果，按楼层与句柄
	BOOL DelResultFloor_Handle(int floorid,const CStringArray & handls);
};
