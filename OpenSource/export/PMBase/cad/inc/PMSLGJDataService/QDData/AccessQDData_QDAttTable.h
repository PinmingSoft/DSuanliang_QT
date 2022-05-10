#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CQDAttTable : public CSQLDataSet 
{
public:
	DECLARE_DYNCREATE(CQDAttTable)

	CQDAttTable();
	virtual ~CQDAttTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString m_id;
		static const CString m_qdnumber;
		static const CString m_parmdisplayname;
		static const CString m_parmvalue;
		static const CString m_listdata;
		static const CString m_checkreg;
		static const CString m_inputmode;
		static const CString m_output1;			//是否输出 1: 输出 ; 0:不输出 ;(在报表中是否显示)

		static const CString m_table_name;
	};

	virtual int InitFieldStr();

public:
	virtual int InitFieldStr( CPM_StorageDataSet * pDataSet ) ;
private:
	/// 有些地方需要使用 CPM_StorageDataSet DataSet 
	/// 添加一个接口，可以传递需要构造的类型。 
	virtual int InitFieldStr( NDataModelDataSet * pDataSet ) ;
};


class PmSLGJDataServiceAPI CAccessQDData_QDAttTable :
	public CPMSLAccessTable
{
public:
	CAccessQDData_QDAttTable(void);

	~CAccessQDData_QDAttTable(void);

	virtual BOOL TryUpdateTableField();

	BOOL GetDataSet_QDNumber(const CString & strQDNumber,CSQLDataSet *& pQDAttDataSet);

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	NDataModelDataSet * GetEmptyDataSet() ;

	NDataModelDataSet * GetEmptyDataSet_Storage() ; 

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		static const int			m_iSelectInfo_QDNumber;
		static const PmTString		m_strSelectInfo_QDNumber;
	};
};
