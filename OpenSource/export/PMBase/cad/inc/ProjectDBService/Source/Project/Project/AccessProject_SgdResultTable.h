#pragma once
////#include "..\accesstable.h"


class PMProjectDBSERVICE CAccessProject_SgdResultTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_SgdResultTable(void);

	~CAccessProject_SgdResultTable(void);

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
	BOOL DelResultFloor_ComType(const CUIntArray &iFloorIDArr, const CUIntArray &iComTypeArr);

	void	DeleteDirtyData() ;

	BOOL DelResultFloor( const int iFloorId ) ;

	//ɾ���������¥������
	void DelResultFloor_Handle(int floorid,const CStringArray & handls);

	BOOL GetTableCtrl_FloorComType(int iFloorID,int iComType,CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetDataSet_FloorComType(int iFloorID,int iComType,CSQLDataSet *& pSQLDataSet);

	/// ��ȡĳ��¥�����еļ������еľ��
	void GetHandleAtFloor(int iFloorID,CStringArray & arrHandle);

	///
	BOOL GetTableCtrl_ForReport( const CString & strFloorIds , const CString & strComTypes , CPMSQLTableCtrl *& pSqliteTableCtrl , const BOOL bQd = TRUE ) ;

	/// 
	CString		GetQuantity( const int iComId , const CString & strHandle , const CString & strCalItemName ,
		const CString & strQddeId , const CString & strQddeName , const CString strQddeUnit ) ;


	/// ȥ��û�й�����֮��Ӧ�Ľ��
	void				RemoveDirtyData() ; 

public:
	/// ɾ����㹹���Ľ��
	BOOL				DelKcResult( const CUIntArray & aryFloorId ) ;

public:

	/**
		* @brief ��ȡ�������
		*
		*          
		* @note  : 
		* @param : 
		* @defenc: 
		* @return: 
		* @author: ����ҫ
		* @date  : 2013��10��16��   14:33
	*/
	double				GetJzmj( const int iFloorId , const CString & strMainMode  ) ; 

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


	};
};
