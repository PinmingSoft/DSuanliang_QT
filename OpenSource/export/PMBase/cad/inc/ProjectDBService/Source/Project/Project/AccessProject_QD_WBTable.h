#pragma once
//#include "..\accesstable.h"

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// �嵥����� ��Ҳ���ڸ��ļ����� 
class PMProjectDBSERVICE CProject_QD_WBTable : public CSQLDataSet
{
public:
	CProject_QD_WBTable() ; 
	virtual	~CProject_QD_WBTable() ; 

public:
	virtual int InitFieldStr() ; 

public:
	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString qdde_index ;	/// ��ʾ����� 1 / 1.1  1.2
		static const CString qdde_id ;		/// �ڲ����߼�id
		static const CString qdde_parent ;  /// �嵥������ʱΪ��Ӧ���嵥 - 12 λ 
		static const CString qdde_node ;	/// �嵥 ���� ����Ҫ����  --- 9λ
		static const CString qdde_level ;	/// �ȼ���ϵ {1,2,2,1,2,2} ,�������Ľṹ
		static const CString qdde_code ; 
		static const CString qdde_attr ;	/// ��Ŀ����
		static const CString qdde_att_content ; ///  ��Ŀ����������
		static const CString qdde_name ; 
		static const CString qdde_unit ;

		static const CString qdde_add ; /// ����Ƿ��������ģ�0 ���߿� Ϊ ����ģ� 1 Ϊ������ 

		

		static const CString table_name ; 

		/// 
		/// �嵥��Ͷ�����Ӧ��id
		static	const CString m_strQdId ;
		static	const CString m_strDeId ;
	};

};

class PMProjectDBSERVICE CAccessProject_QD_WBTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_QD_WBTable(void);
public:
	virtual ~CAccessProject_QD_WBTable(void);

	/**
	* @brief   ���� ������ṹ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/6/2012]
	*/
	virtual BOOL TryUpdateTableField();

	/// 
	CSQLDataSet * GetDataSet();
	
	/**
	* @brief  ��ȡ�յ� Dataset�������� ִ��sql������
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	CSQLDataSet * GetEmptyDataSet();

	/**
	* @brief ��ȡID�� ���ֵ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	BOOL GetMaxID(int & iMaxID);

	//ɾ�� ���м�¼
	BOOL DeleteAllRow();

	CSQLDataSet * GetDataSet( const CString & strBaseQdId ) ;

	/// �����Ƿ��� nodeid
	BOOL	HasNodeId( const CString & strBaseNodeId ) ; 

	/// 
	/// �ж��嵥id �Ƿ���������
	/// 
	BOOL	IsAddQdId( const CString & strQdId ) ; 

public:
	CString		GetQdBaseName() ; 
	CString		GetDeBaseName() ; 
public:
	
	static PMTSTRING	GetSql( const int iType ) ;

public:
	struct SQLInfo
	{
	
	} ;

public:
	
};




