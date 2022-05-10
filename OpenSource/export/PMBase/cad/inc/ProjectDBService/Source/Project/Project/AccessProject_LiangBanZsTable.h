#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_LiangBanZsTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_LiangBanZsTable)

	CProject_LiangBanZsTable();
	virtual ~CProject_LiangBanZsTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;
		static const CString floorid;
		static const CString liangvolume;
		static const CString banvolume;
		static const CString banarea;
		static const CString banhd;
		static const CString lianghandle;	
		static const CString banhandle;

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_LiangBanZsTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_LiangBanZsTable(void);

	virtual ~CAccessProject_LiangBanZsTable(void);

public:

	/**
	* @brief  ��mm����Ϊ���ݱ���� ��� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/5/2013]
	*/
	static int Trans2SaveBG(const double & dValue);

	/**
	* @brief �������еı�� ���� ���룬��MM   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/5/2013]
	*/
	static double Trans2OutInfo(int iValue);

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	/**
	* @brief   ��ȡָ��¥�����������
	*
	*          
	* @note  : 
	* @param : strFloorIds ָ����¥�㣬 ��δ�յ�ʱ��ȡ����¥���
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-8-14]
	*/
	BOOL GetTableCtrl( const CString & strFloorIds ,  CPMSQLTableCtrl *& pSqliteTableCtrl );

public:

	static PMTSTRING	GetSql( const int iType ) ;

public:
	struct SQLInfo
	{
		/// 
		static const int			m_iGetTableCtrl ;
		static const PMTSTRING		m_strGetTableCtrl ; 

		/// 
		static const int			m_iGetTableCtrlFloorIds ;
		static const PmTString		m_strGetTableCtrlFloorIds ; 
	} ; 
};
