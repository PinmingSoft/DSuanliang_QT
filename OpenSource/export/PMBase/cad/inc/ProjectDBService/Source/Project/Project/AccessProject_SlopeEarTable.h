
#pragma once
/**
 * @brief ��Ӷ�CAccessProject_SlopeEarTable���ݿ��Ĳ���
 *
 *        
 * @author ֣����
 * @version v1.0
 * @date  2016��3��17��   9:10
 * @note  
 */

class PMProjectDBSERVICE CAccessProject_SlopeEarTable :
	public CPMSLAccessTable
{
public: 
	CAccessProject_SlopeEarTable(void);

	virtual ~CAccessProject_SlopeEarTable(void);

	virtual BOOL TryUpdateTableField();


public:
	CSQLDataSet * GetDataSet() ;

	CPM_StorageDataSet * GetStorageDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	static PMTSTRING	GetSql( const int iType ) ;

	void GetParmValue( const CString & strParmname, CString & strParmValue );
public:
	//�̶���SQL ����
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 
	} ;

protected:
	//�̶���SQL ����
	static PmTString m_strSelectFptf_SQL;//��ȡ comparm buffer��sql��
};