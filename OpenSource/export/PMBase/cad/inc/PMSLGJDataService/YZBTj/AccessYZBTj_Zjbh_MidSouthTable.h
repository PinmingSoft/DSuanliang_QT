#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CPMZjbh_MidSouthTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CPMZjbh_MidSouthTable)

	CPMZjbh_MidSouthTable();
	virtual ~CPMZjbh_MidSouthTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString m_id;
		static const CString m_parentid;
		static const CString m_zone1;
		static const CString m_zjmc;
		static const CString m_idex;

		static const CString m_table_name;
	};

	virtual int InitFieldStr();
};


class PmSLGJDataServiceAPI CAccessYZBTj_Zjbh_MidSouthTable :
	public CPMSLAccessTable
{
public:
	CAccessYZBTj_Zjbh_MidSouthTable(void);

	~CAccessYZBTj_Zjbh_MidSouthTable(void);

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();
};
