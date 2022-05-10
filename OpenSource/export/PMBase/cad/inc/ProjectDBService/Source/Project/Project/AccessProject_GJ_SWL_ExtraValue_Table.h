#pragma once
//#include "..\accesstable.h"

/**
 * @brief  :
 * ����ʵ�������������
 *          
 * @author :���й�
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

	/// ��ȡĳ��¥�����еļ������еľ��
	void GetHandleAtFloor(int iFloorID,CStringArray & arrHandle);

	/*����floorId �� comtypeɾ�����еĽ��*/
	BOOL DelResultFloor_ComType(CUIntArray &iFloorIDArr, CUIntArray &iComTypeArr);

	//ɾ���������¥������
	void DelResultFloor_Handle(int floorid,const CStringArray & handls);
};
