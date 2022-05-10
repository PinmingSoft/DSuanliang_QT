#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_EditOtherItemTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_EditOtherItemTable)

	CProject_EditOtherItemTable();
	virtual ~CProject_EditOtherItemTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;							//���
		static const CString indexs;						//�ñ����ò���,editohteritem ����������ʾ����
		static const CString floorid;						//��������¥����
		static const CString floorshowid;					//¥�������id
		static const CString calitemid;					//�����ʱ���� ������ĿID,�嵥��ʱ���ſ�
		static const CString calitemname;					//�����ʱ���� ������Ŀ����,�嵥��ʱ���� "�嵥" ������
		static const CString calitemnamelistdata;			//������Ŀ�������ѱ�
		static const CString rationrow;					//���������ID(�����ʱ��,�涨���ID,�嵥��ʱ���0)
		static const CString decode;						//�����ʱ���Ŷ������ ,�嵥��ʱ�����嵥ID .
		static const CString dename;						//�����ʱ���Ŷ������� ,�嵥��ʱ�����嵥����.
		static const CString unit;						//��λ
		static const CString unitlistdata;				//��λ�������б�ֵ
		static const CString quantity;					//������
		static const CString transformula;				//���������㹫ʽ(������ʾ)
		static const CString positions;					//��ƽ��ͼ�е�λ��
		static const CString qdid;						//�ڶ���ʱ�����嵥ID,�嵥��ʱ��Ϊ��
		static const CString qdname;						//�嵥����
		static const CString qdcode;						//�嵥����
		static const CString qdunit;						//�嵥��λ
		static const CString qdunitlistdata;				//�嵥��λ�������б�
		static const CString mainmode;					//����ģʽ ���嵥���Ƕ���(1�嵥,0����)
		static const CString mainmodelistdata;			//����ģʽ�������б�
		static const CString itemcharacter;				//��Ŀ����
		static const CString variable;					//����

		static const CString table_name;					//����
	};

	virtual int InitFieldStr();
};


class PMProjectDBSERVICE CAccessProject_EditOtherItemTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_EditOtherItemTable(void);
public:
	virtual ~CAccessProject_EditOtherItemTable(void);

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

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

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

	/// 
	BOOL	DeleteFloor( const int iFloorId ) ;

	/**
	* @brief   ��ȡ��¼��
	*
	*          
	* @note  : 
	* @param : strCalItemNames Ϊ 1,2,3 �ĸ�ʽ������Ϊ��
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-8-15]
	*/
	BOOL	GetTableCtrl( const int iFloorId , const CString & strCalItemNames , CPMSQLTableCtrl *& pSqliteTableCtrl ) ;

	/**
	* @brief   ��ȡ��¼�����ṩ������ʹ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-8-16]
	*/
	BOOL	GetTableCtrl( const CString & strFloorIds , CPMSQLTableCtrl *& pSqliteTableCtrl , const BOOL bQd = TRUE ) ;

	/// 
	BOOL	GetTableCtrlQdde( const CString & strFloorIds , CPMSQLTableCtrl *& pSqliteTableCtrl ) ;


	/// ȥ���Ҳ���¥���������
	void	RemoveDirtyData() ; 

public:
	
	static PMTSTRING	GetSql( const int iType ) ;

public:
	struct SQLInfo
	{
		/// 
		static const int			m_iGetTableCtrl ;
		static const PMTSTRING		m_strGetTableCtrl ; 

		/// 
		static const int			m_iGetTableCtrl_ForReport ;
		static const PMTSTRING		m_strGetTableCtrl_ForReport ; 

		/// 
		static const int			m_iGetTableCtrl_ForReport1 ;
		static const PMTSTRING		m_strGetTableCtrl_ForReport1 ; 
	} ;
};




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// �嵥����� ��Ҳ���ڸ��ļ����� 
class PMProjectDBSERVICE CProject_QddeCustomizeTable : public CSQLDataSet
{
public:
	CProject_QddeCustomizeTable() ; 
	virtual	~CProject_QddeCustomizeTable() ; 

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

class PMProjectDBSERVICE CAccessProject_QddeCustomizeTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_QddeCustomizeTable(void);
public:
	virtual ~CAccessProject_QddeCustomizeTable(void);

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




