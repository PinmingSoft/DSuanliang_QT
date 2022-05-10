#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CQDDefaultQdValueTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CQDDefaultQdValueTable)

	CQDDefaultQdValueTable();
	virtual ~CQDDefaultQdValueTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString comtype;
		static const CString calitemname;
		static const CString qdvalue;
		static const CString subcalitemname;

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CAccessQDData_DefaultQdValueTable :
	public CPMSLAccessTable
{
public:

	struct CDefaultValue  
	{
		CStringArray m_arr_calitemname ; 
		CStringArray m_arr_qdvalue ; 
		CStringArray m_arr_subcalitemname ; 

		void empty()
		{
			m_arr_calitemname.RemoveAll() ; 
			m_arr_qdvalue.RemoveAll() ; 
			m_arr_subcalitemname.RemoveAll() ; 
		}
		CString getcalitemname( int nIndex )
		{
			return m_arr_calitemname.GetAt(nIndex) ; 
		}

		CString getqdvalue( int nIndex )
		{
			return m_arr_qdvalue.GetAt(nIndex) ; 
		}

		CString getsubcalitemname( int nIndex )
		{
			return m_arr_subcalitemname.GetAt(nIndex) ;
		}
		/// 
		int getcount()
		{
			return (int)m_arr_calitemname.GetSize() ; 
		}
	};

	CAccessQDData_DefaultQdValueTable(void);

	virtual ~CAccessQDData_DefaultQdValueTable(void);

	virtual BOOL TryUpdateTableField();

	BOOL GetQdValue( CString  strComType , CDefaultValue &defaulvalue );

	CSQLDataSet * GetDataSet();

	NDataModelDataSet * GetEmptyDataSet() ; 

	//通过 comtype calItemname 获取 记录集
	BOOL GetTableCtrl_ComTypeCalItemName(const CString & strComType,const CString & strCalItemName,CPMSQLTableCtrl *& pSQLTableCtrl);

	void GetSubCalItemName(const CString & strComType , 
		const CString & strCalItemName ,
		CStringArray &arr_subCalItemName );

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		static const int			m_iSelectInfo_ComType;
		static const PmTString		m_strSelectInfo_ComType;

		static const int			m_iSelectInfo_ComTypeCalItemName;
		static const PmTString		m_strSelectInfo_ComTypeCalItemName;
	};
};
