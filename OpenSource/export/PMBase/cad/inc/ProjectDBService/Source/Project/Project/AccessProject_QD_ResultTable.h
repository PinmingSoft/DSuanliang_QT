#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CProjectQD_ResultTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProjectQD_ResultTable)

	CProjectQD_ResultTable();
	virtual ~CProjectQD_ResultTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;
		static const CString comtype;
		static const CString name;
		static const CString deid;
		static const CString dename;
		static const CString decode;
		static const CString unit;
		static const CString quantity;
		static const CString sections;
		static const CString formulas;
		static const CString editmode;
		static const CString rationrow;     //�����Ӧ�� Ration���ж�Ӧ�� �к�

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_QD_ResultTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_QD_ResultTable(void);

	virtual ~CAccessProject_QD_ResultTable(void);

	virtual BOOL TryUpdateTableField();

	/**
	* @brief  �������м�¼  
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	//ɾ�� ���м�¼
	BOOL DeleteAllRow();
};
