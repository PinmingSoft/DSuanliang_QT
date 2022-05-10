#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CDEChapterTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CDEChapterTable)

	CDEChapterTable();
	virtual ~CDEChapterTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString px;
		static const CString chapter;
		static const CString chaptername;

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CAccessDEData_ChapterTable :
	public CPMSLAccessTable
{
public:
	CAccessDEData_ChapterTable(void);

	virtual ~CAccessDEData_ChapterTable(void);

	/**
	* @brief   ���� ������ṹ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/6/2012]

	*/
	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	NDataModelDataSet * GetEmptyDataSet() ; 
};
