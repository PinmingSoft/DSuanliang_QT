#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_CustomSteelComponentsTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_CustomSteelComponentsTable)

	CProject_CustomSteelComponentsTable();
	virtual ~CProject_CustomSteelComponentsTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					
		static const CString comname;				//��������	
		static const CString floorid;				//¥��ID
		static const CString folderid;			//������ID
		static const CString comtype;				//�������	
		static const CString volume;				//�˹���������
		static const CString comparms;			//��������
		static const CString inputdata;			//ƽ���������
		static const CString showid;				
		static const CString sumvolume;		

		static const CString table_name;			//����
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_CustomSteelComponents :
	public CPMSLAccessTable
{
public:
	CAccessProject_CustomSteelComponents(void);

	virtual ~CAccessProject_CustomSteelComponents(void);

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

	BOOL GetTableCtrl_ComID(int iComID,CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetDataSet_ComID(int iComID,CSQLDataSet *& pSQLDataSet);

	BOOL GetTableCtrl_ComTypeFloor(int iFloorID,int iComType,CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetTableCtrl( CPMSQLTableCtrl *& pSQLTableCtrl ) ;

	CString GetComName(int iComID);

	void SetComName( int nComID ,const CString & strComName );

	int GetComType(int iComID);

	int InsertCom( CString strComName , 
		int nComType ,
		int nFloorID ) ;

	void DeleteCom( int nComID ) ;

	static PmTString GetSQL(const int iSQLIndex);

	/// 
	CSQLDataSet * GetDataSet();

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

	struct SQLInfo
	{
		//select * from customsteelComponents where comid=?;
		static const int		m_iSelectAllInfo_ComID;
		static const PmTString	m_strSelectAllInfo_ComID;

		//select * from customsteelComponents where floor=? and comtype=?
		static const int		m_iSelectAllInfo_ComTyeFloor;
		static const PmTString	m_strSelectAllInfo_ComTypeFloor;

		//delete from customsteelComponents where id=?;
		static const int		m_iDeleteInfo_ComID;
		static const PmTString	m_strDeleteInfo_ComID;

		/// select * from customsteelComponents 
		static const int		m_iGetDataSet ;
		static const PMTSTRING	m_strGetDataSet ; 
	};
};
