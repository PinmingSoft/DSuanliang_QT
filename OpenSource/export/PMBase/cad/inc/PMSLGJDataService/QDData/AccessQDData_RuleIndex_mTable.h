#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CQDRuleIndex_mTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CQDRuleIndex_mTable)

	CQDRuleIndex_mTable();
	virtual ~CQDRuleIndex_mTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString nodeid;			//�嵥���---��νṹ �������ڵ�Ĵ���
		static const CString qdid;			//�嵥ID --- �߼�ʹ�õ��嵥��� ����/Ӣ���ַ�/�����ַ�
		static const CString nodename;		//�ڵ���
		static const CString comtype;			//��������
		static const CString unit;			//��λ
		static const CString csxm;			//��ʩ��Ŀ  1:��ʩ��Ŀ 0:�Ǵ�ʩ��Ŀ
		static const CString variables;		//����

		static const CString table_name;
	};

	virtual int InitFieldStr();
};


class PmSLGJDataServiceAPI CAccessQDData_RuleIndex_mTable :
	public CPMSLAccessTable
{
public:
	CAccessQDData_RuleIndex_mTable(void);

	~CAccessQDData_RuleIndex_mTable(void);

public:

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	void	Delete() ; 

	NDataModelDataSet * GetEmptyDataSet() ; 

	BOOL GetTableCtrl_NodeID(const CString & strNodeID,CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetTableCtrl_QDID(const CString & strQDID,CPMSQLTableCtrl *& pSQLTableCtrl);

	CString	GetNodeID( const CString & strQdid ) ;

	BOOL IsIn( CString strNodeID , CString strComType ) ;

	BOOL GetQdInfo( 
		const CString & strNodeID ,
		CString & strQdid , 
		CString & strQdName , 
		CString & strUnit );

	CString GetQdName( const CString & strNodeName ) ;

	/// ���嵥ά����ʱ�� �� �����嵥id ȥ��ȡ���õı���
	NDataModelDataSet *		GetVariableDataSet( const CString & strNodeID ) ; 

	NDataModelDataSet * GetVariableDataSet( NDataModelDataSet * pGridData , const CString & strNodeID ) ;

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		static const int		m_iSelectInfo_NodeID;
		static const PmTString	m_strSelectInfo_NodeID;

		static const int		m_iSelectInfo_QDID;
		static const PmTString	m_strSelectInfo_QDID;
	};

	/// �Զ����嵥�� nodeid 
	static const CString			m_strCusNodeID ; 

	/// �����嵥�� ��һ�� 10
	static const CString			m_strAddQdNode1 ;

	/// �ڶ��� 1001 
	static const CString			m_strAddQdNode2 ; 

	/// ������ 100101
	static const CString			m_strAddQdNode3 ;

	/// ���ļ� 100101001 --- �ֲ�
	static const CString			m_strAddQdNode4 ;

	/// ���ļ� 100101002 --- ��ʩ
	static const CString			m_strAddQdNode4_1 ;

	/// �����嵥���½�����: �����嵥
	static const CString			m_strQddQdNodeName ; 

	/// �����嵥���½�����: �����嵥 --- �ֲ�
	static const CString			m_strQddQdNodeName4 ;


	/// �����嵥���½�����: �����嵥 --- ��ʩ
	static const CString			m_strQddQdNodeName4_1 ;

};
