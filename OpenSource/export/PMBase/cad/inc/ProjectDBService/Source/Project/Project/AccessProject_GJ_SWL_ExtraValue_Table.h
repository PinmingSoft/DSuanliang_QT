#pragma once
//#include "..\accesstable.h"

/**
 * @brief  :
 * 构件实物量额外参数表
 *          
 * @author :李中国
 * @version:v1.0
 * @date   :[11/21/2016]
 * @note   :
 */

class PMProjectDBSERVICE CAccessProject_SWL_ExtraValue_Table :
	public CPMSLAccessTable
{
public:
	CAccessProject_SWL_ExtraValue_Table(void);

	virtual ~CAccessProject_SWL_ExtraValue_Table(void);

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	CSQLDataSet * GetEmptyDataSet();

	BOOL GetTable_MaxID(int & iMaxID);

	/// 获取某个楼层所有的计算结果中的句柄
	void GetHandleAtFloor(int iFloorID,CStringArray & arrHandle);

	/*根据floorId 与 comtype删除表中的结果*/
	BOOL DelResultFloor_ComType(CUIntArray &iFloorIDArr, CUIntArray &iComTypeArr);

	//删除结果，按楼层与句柄
	void DelResultFloor_Handle(int floorid,const CStringArray & handls);
};
