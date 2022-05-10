#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_AxisTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_AxisTable)

	CProject_AxisTable();
	virtual ~CProject_AxisTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;
		static const CString type;						//��������
		static const CString name;						//������
		static const CString axisxml;						//����xml��-----��ϸ��Ϣ

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

//�������ݿ����
class PMProjectDBSERVICE CAccessProject_AxisTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_AxisTable(void);

	virtual ~CAccessProject_AxisTable(void);

	virtual BOOL TryUpdateTableField();

	/**
	* @brief   ��ȡ��������ݣ����Ƽ�ʹ�ã�
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-12]
	*/
	CSQLDataSet * GetDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet *& pSQLDataSet);
	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;


public:
	//�̶���SQL ����
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 
	} ;
};
