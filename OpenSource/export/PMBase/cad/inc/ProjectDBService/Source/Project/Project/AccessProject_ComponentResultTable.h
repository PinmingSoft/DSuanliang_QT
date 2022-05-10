#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_ComponentResultTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ComponentResultTable)

	CProject_ComponentResultTable();
	virtual ~CProject_ComponentResultTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					//�ñ���߼�id
		static const CString floorid;				//¥��
		static const CString comid;				//����
		static const CString gjlb;				//�ֽ����
		static const CString gjlx;				//�ֽ�����
		static const CString gjjb;				//�ֽ��
		static const CString zj;					//ֱ��
		static const CString gs;					//����
		static const CString th;					//ͼ��
		static const CString jt;					//��ͼ
		static const CString jsgs;				//���㹫ʽ
		static const CString wg;					//�乴
		static const CString tqd;					//��ǿ��
		static const CString dj;					//���
		static const CString cd;					//����
		static const CString jtgs;				//��ͷ����
		static const CString zz;					//����
		static const CString gsms;				//��ʽ����
		static const CString index0;				
		static const CString index1;				
		static const CString index2;				
		static const CString jtparms;				//��ͼ����
		static const CString sttype;				//�ֽ���� Ĭ��0ʱΪ�������ã�1ʱΪ�ֹ�����
		static const CString jtformula;			//��ͼ���㹫ʽ
		static const CString resulttype;			
		static const CString djxs;				
		static const CString errortype;			
		static const CString cc;				
		static const CString ccamount;			

		static const CString table_name;			//�ֽ��������
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_ComponentResultTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_ComponentResultTable(void);
	~CAccessProject_ComponentResultTable(void);
	

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

public:

	/// 
	BOOL GetMaxId( int & iMaxId ) ;

	/**
	* @brief   ��ȡ DataSet 
	*
	*          
	* @note  : ���� ������� �������ĺܴ�
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/6/2012]
	*/
	CSQLDataSet * GetDataSet() ;

	CSQLDataSet * GetDataSet( const int iComId ) ;

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	/// ����ָ�������ļ����� 
	void  SetDataSet( const int iComId , NDataModelDataSet * pResult ) ; 

	BOOL GetRowCount( int & iRowCount ) ;

	/// 
	BOOL GetTableCtrl( 
		const CString & strFloorIds , 
		const CString & strComFolderIds ,
		CPMSQLTableCtrl *& pTableCtrl 
		) ; 

	/// ɾ��ָ�������� ������
	void				DelResult( const int iComId ) ; 


	/// ȥ��û�й�����֮��Ӧ�Ľ��
	void				RemoveDirtyData() ; 

private:
	void				InsertDataSet( const int iComId ,NDataModelDataSet * pDataSet ) ;

public:
	static PMTSTRING GetSQL(const int iSQLIndex);

public:

	struct SQLInfo
	{
		static const int		m_iSelectResult_ComID_Sql;
		static const PMTSTRING	m_strSelectResult_ComID_Sql;//��ȡ ָ���� ComID�� ��¼ sql

		/// 
		static const int		m_iDelResult ;
		static const PMTSTRING	m_strDelResult ; 

		/// 
		static const int		m_iInsertDataSet ;
		static const PMTSTRING	m_strInsertDataSet ; 

		/// 
		static const int		m_iGetTableCtrl ; 
		static const PMTSTRING	m_strGetTableCtrl ; 
	};
};
