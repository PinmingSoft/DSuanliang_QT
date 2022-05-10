#pragma once
#include "..\accesstable.h"


class PmSLGJDataServiceAPI CPMContentTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CPMContentTable)

	CPMContentTable();
	virtual ~CPMContentTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString nodename;
		static const CString parentid;
		static const CString tablename;
		static const CString range;
		static const CString vectorid	;

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CAccessBZCTTj_ContentTable :
	public CPMSLAccessTable
{
public:
	CAccessBZCTTj_ContentTable(void);

	~CAccessBZCTTj_ContentTable(void);

	/**
	* @brief   尝试 升级表结构
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/6/2012]
	*/
	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();
};
