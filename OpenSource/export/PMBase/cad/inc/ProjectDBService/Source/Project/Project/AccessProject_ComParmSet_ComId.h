


#pragma once 


//#include "..\accesstable.h"

typedef std::set<int> CPmIntSet ; 
typedef CPmIntSet::iterator	CPmIntSetIter ;
typedef CPmIntSet::const_iterator CPmIntSetConIter ; 

/**
 * @brief �����Ĳ�������ֵ
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2013-5-20]
 * @note  
 */
class PMProjectDBSERVICE CProject_ComParmsSet_ComIdTable : public CSQLDataSet
{
	DECLARE_DYNCREATE(CProject_ComParmsSet_ComIdTable)

	CProject_ComParmsSet_ComIdTable();
	virtual ~CProject_ComParmsSet_ComIdTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString	parmid;
		static int				parmid_Index;

		static const CString	comid;
		static int				comid_Index;

		static const CString	subcomtype;
		static int				subcomtype_Index;
		
		static const CString	parmname;
		static int				parmname_Index;

		static const CString	parmvalue;
		static int				parmvalue_Index;

		static const CString	invalidmsg;
		static int				invalidmsg_Index;

	};

	struct PMProjectDBSERVICE CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

//���幹������ ���ݿ��
class PMProjectDBSERVICE CAccessProject_ComParmsSet_ComIdTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_ComParmsSet_ComIdTable(void);
	CAccessProject_ComParmsSet_ComIdTable(BOOL bTemplateDb);
	virtual ~CAccessProject_ComParmsSet_ComIdTable(void);

public:

	/**
	* @brief   ���� ������ṹ
	*/
	virtual BOOL TryUpdateTableField();


	/// 
	CSQLDataSet * GetDataSet();

	/**
	* @brief  ��ȡ�յ� Dataset�������� ִ��sql������
	* @date  : [13/7/2012]
	*/
	CSQLDataSet * GetEmptyDataSet();

	/// �����Ƿ����ͨ��������ڵļ�¼������Ϊ0�����ԣ����Ϊ0�������������
	static BOOL	CheckTable(CString &sErrorInfo);

	/// 
	void	GetComId( const int iComType , const int iSubComType ,const CString & strParmName , CPmIntSet & setComId ) ;

	/// 
	void	UpdateParmValue( const CString & strParmName , const CString & strParmValue , const CUIntArray & aryComId ) ;

	void	UpdateParmValue(const CString& strParmName,const CString& strParmValue);
	
	// ���¸ֽ��������
	void UpDateGJGSRule(const CString & strParmValue,const CUIntArray & aryComId);
	/// 
	void	DeleteGlobalParmName( const CString & strParmName , const CUIntArray & aryComId ) ;

	/// 
	void	InsertGlobalParmName( const CString & strParmName , const CString & strParmValue , const CUIntArray & aryComId  ) ;
	
	
	/// 
	/// ���¼������õĴ����ʽ
	/// 
	/// 
	void	GetJsszDjxsParm( const CString & strParmName , const CString & strParmValue , const CUIntArray & aryComId ) ;


	/// ��ȡcomid��Ӧ�����еĹ���
	BOOL	GetTableCtrl( const int iComId , CPMSQLTableCtrl *& pSqlTableCtrl ) ;

	/// 
	void	Delete() ; 

	void	DeleteJssz( const CUIntArray & aryComId ) ; 

	/// 
	void	Delete( const int iComId ) ;
	void	Delete( const CString strParmName , const CUIntArray & aryComId ) ;

	/// ��������,Ҫ���Ѱ�ԭ�в���ɾ��
	void	CopyParm(int comidFrom,int comidTo);

public:
	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		///delete from comparmsset_comid
		static const int m_iDelete ;
		static PMTSTRING m_strDelete ;

		/// delete from ComParmsSet_Handle
		static const int	m_iDeleteComId ;
		static PmTString	m_strDeleteComId ;
	};
};