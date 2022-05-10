

#pragma once 


#include "AccessSysDataTable.h"

/**
 * @brief 
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-4]
 * @note  
 */
class PmSLGJDataServiceAPI CSysMacrosTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysMacrosTable)

	CSysMacrosTable();
	~CSysMacrosTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString key_ch ;
		static const CString key_en ;
		static const CString content ;
		static const CString description ;

		static int key_ch_Idx ;
		static int key_en_Idx ;
		static int content_Idx ;
		static int description_Idx ;

		/// idx �����ĸ�������
		/// idx ��Ҫ�ں��� InitFieldStr �� ����ʼ��Ϊ�������ֵ
		/// �Ҹ�ֵ��˳��Ӧ�ú� InitFieldStr����ӵ�˳��һ��
		static int idx_step ; 
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const CString table_name_v2 ;
		static const int cur_version ; 
	};
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
class PmSLGJDataServiceAPI CSysMacrosV2Table : public CSysMacrosTable
{
public:
	DECLARE_DYNCREATE(CSysMacrosV2Table)

	CSysMacrosV2Table();
	~CSysMacrosV2Table() ;

public:
	virtual int InitFieldStr();

} ; 

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 

class PmSLGJDataServiceAPI CAccessSysData_MacrosTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_MacrosTable(void);
	virtual ~CAccessSysData_MacrosTable(void);

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

	/**
	* @brief   ��ȡ�汾��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-3]
	*/
	static	int	GetCurVersion() ;

	/// ��ȡ�ű�������
	BOOL GetMacroContent( const CString & sPath,CString & sContent );

	BOOL SetMacroContent( const CString & sPath,const CString & sContent );

	BOOL GetDataSet_MacroPath(const CString & strPath,CSQLDataSet *& pSQLDataSet);

	/**
	* @brief   ��ȡ��������ݣ����Ƽ�ʹ�ã�
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-12]
	*/
	CSQLDataSet * GetDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);
	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;


public:
	//�̶���SQL ����
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetDataSet_Key_Ch ; 
		static PMTSTRING m_strGetDataSet_Key_Ch ; 

		/// 
		static const int m_iGetMacroContent ; 
		static PMTSTRING m_strGetMacroContent ; 
	} ;
};




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 

class PmSLGJDataServiceAPI CAccessSysData_MacrosV2Table : public CAccessSysDataTable 
{
public:
	CAccessSysData_MacrosV2Table(void);
	virtual ~CAccessSysData_MacrosV2Table(void);

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

	/**
	* @brief   ��ȡ�汾��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-3]
	*/
	static	int	GetCurVersion() ;

	/// ��ȡ�ű�������
	BOOL GetMacroContent( const CString & sPath,CString & sContent );

	BOOL SetMacroContent( const CString & sPath,const CString & sContent );

	BOOL GetDataSet_MacroPath(const CString & strPath,CSQLDataSet *& pSQLDataSet);

	/**
	* @brief   ��ȡ��������ݣ����Ƽ�ʹ�ã�
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-12]
	*/
	CSQLDataSet * GetDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);
	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;


public:
	//�̶���SQL ����
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetDataSet_Key_Ch ; 
		static PMTSTRING m_strGetDataSet_Key_Ch ; 

		/// 
		static const int m_iGetMacroContent ; 
		static PMTSTRING m_strGetMacroContent ; 
	} ;
};
