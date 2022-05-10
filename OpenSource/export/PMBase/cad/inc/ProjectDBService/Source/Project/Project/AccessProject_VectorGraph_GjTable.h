#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CVectorGraph_GjTable : public CSQLDataSet
{
	DECLARE_DYNCREATE(CVectorGraph_GjTable)

	CVectorGraph_GjTable();
	virtual ~CVectorGraph_GjTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString m_id;
		static const CString m_vectorgraphtype;
		static const CString m_vectorgraphname;
		static const CString m_vectorgraph;

		static const CString m_table_name;
	};

	virtual int InitFieldStr();
};

class CAccessProject_VectorGraph_GjTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_VectorGraph_GjTable(void);
	virtual ~CAccessProject_VectorGraph_GjTable(void);

	virtual BOOL TryUpdateTableField();
};
