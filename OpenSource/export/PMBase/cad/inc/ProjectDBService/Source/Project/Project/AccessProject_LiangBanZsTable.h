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
	* @brief  将mm翻译为数据保存的 标高 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/5/2013]
	*/
	static int Trans2SaveBG(const double & dValue);

	/**
	* @brief 将数据中的标高 进行 翻译，成MM   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/5/2013]
	*/
	static double Trans2OutInfo(int iValue);

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	/**
	* @brief   获取指定楼层的梁板折算
	*
	*          
	* @note  : 
	* @param : strFloorIds 指定的楼层， 但未空的时候，取所有楼层的
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
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
