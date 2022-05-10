#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CAttribute_MidSouthTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CAttribute_MidSouthTable)

	CAttribute_MidSouthTable();
	virtual ~CAttribute_MidSouthTable();

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

class PmSLGJDataServiceAPI CAccessYZBTj_Attribute_MidSouthTable :
	public CPMSLAccessTable
{
public:
	CAccessYZBTj_Attribute_MidSouthTable(void);

	virtual ~CAccessYZBTj_Attribute_MidSouthTable(void);

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();
};
