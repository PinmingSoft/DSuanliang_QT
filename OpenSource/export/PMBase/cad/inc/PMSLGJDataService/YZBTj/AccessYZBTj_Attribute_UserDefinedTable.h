#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CAttribute_UserDefinedTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CAttribute_UserDefinedTable)

	CAttribute_UserDefinedTable();
	virtual ~CAttribute_UserDefinedTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString m_id;
		static const CString m_zjid;
		static const CString m_tj_bh;
		static const CString m_tj_name;
		static const CString m_length;
		static const CString m_width;
		static const CString m_height;
		static const CString m_volume;
		static const CString m_material;

		static const CString m_table_name;
	};

	virtual int InitFieldStr();
};


class PmSLGJDataServiceAPI CAccessYZBTj_Attribute_UserDefinedTable :
	public CPMSLAccessTable
{
public:
	CAccessYZBTj_Attribute_UserDefinedTable(void);

	~CAccessYZBTj_Attribute_UserDefinedTable(void);

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();
};
