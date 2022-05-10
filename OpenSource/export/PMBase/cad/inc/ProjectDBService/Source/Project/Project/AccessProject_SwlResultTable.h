#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CAccessProject_SwlResultTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_SwlResultTable(void);

	~CAccessProject_SwlResultTable(void);

	virtual BOOL TryUpdateTableField();

	/**
	* @brief  ��ȡ������ ��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/7/2012]
	*/
	BOOL GetCalResult(int iComID,const CString & strHandle,CString & strResult);

	/**
	* @brief  ��ȡ������ ��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/7/2012]
	*/
	BOOL GetCalResult_TableCtrl(int iComID,CPMSQLTableCtrl *& pSQLTableCtrl);

	//ɾ�� ���м�¼
	BOOL DeleteAllRow();

	CSQLDataSet * GetDataSet();

	CSQLDataSet * GetEmptyDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	BOOL GetTable_MaxID(int & iMaxID);

	/**
	* @brief  ɾ��ָ����¥�� �� �������͵ļ�¼ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [20/7/2012]
	*/
	BOOL DelResultFloor_ComType(CUIntArray &iFloorIDArr, CUIntArray &iComTypeArr);

	//ɾ���������¥������
	void DelResultFloor_Handle(int floorid,const CStringArray & handls);

	void DeleteDirtyData();


	BOOL GetTableCtrl_FloorComType(int iFloorID,int iComType,CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetDataSet_FloorComType(int iFloorID,int iComType,CSQLDataSet *& pSQLDataSet);

	/// ��ȡĳ��¥�����еļ������еľ��
	void GetHandleAtFloor(int iFloorID,CStringArray & arrHandle);

	/// 
	BOOL GetTableCtrl_ForReport( const CString & strFloorIds , const CString & strComTypes , const CString & strOrderBy ,  CPMSQLTableCtrl *& pSqliteTableCtrl ) ;

	/// 
	BOOL GetTableCtrlForReportJmInfo(  const CString & strFloorIds , const CString & strComTypes , 
		const CString & strGroupBy , const CString & strOrderBy ,  
		CPMSQLTableCtrl *& pSqliteTableCtrl ) ;

public:
	BOOL DelKcResult( const CUIntArray & aryFloorId )  ;


public:

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		/// 
		static const int			m_iSelectResult_ComID;
		static const PmTString		m_strSelectResult_ComID;//ͨ�� Handle ��ȡ ������

		/// 
		static const int			m_iSelectResult_ComTypeFloor;
		static const PmTString		m_strSelectResult_ComTypeFloor;

		/// 
		static const int			m_iSelectReult_ForReport ; 
		static const PMTSTRING		m_strSelectReult_ForReport ;

		/// ��Ҫ���� gjjminfo ��
		static const int			m_iSelectResultForReportJmInfo ;
		static const PmTString		m_strSelectResultForReportJmInfo ; 


	};
};
