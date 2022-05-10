#pragma once
//#include "..\accesstable.h"


class PMProjectDBSERVICE CAccessProject_CalRule_SgdLbTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_CalRule_SgdLbTable(void);
	virtual ~CAccessProject_CalRule_SgdLbTable(void);

	virtual BOOL TryUpdateTableField();
	CSQLDataSet * GetDataSet();

	CPM_StorageDataSet * GetStorageDataSet();
	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	BOOL GetRowCount( int & iRowCount ) ;
};
