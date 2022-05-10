

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
class PmSLGJDataServiceAPI CSysSteelDiagram_ParamsTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysSteelDiagram_ParamsTable)

	CSysSteelDiagram_ParamsTable();
	~CSysSteelDiagram_ParamsTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString sdid;
		static const CString parmName;
		static const CString ParmType;
		static const CString ParmValue;
		static const CString ScriptParm;

		static int id_Idx ;
		static int sdid_Idx ;
		static int parmName_Idx ;
		static int ParmType_Idx ;
		static int ParmValue_Idx ;
		static int ScriptParm_Idx ;

		/// idx �����ĸ�������
		/// idx ��Ҫ�ں��� InitFieldStr �� ����ʼ��Ϊ�������ֵ
		/// �Ҹ�ֵ��˳��Ӧ�ú� InitFieldStr����ӵ�˳��һ��
		static int idx_step ; 
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};
};


class PmSLGJDataServiceAPI CAccessSysData_SteelDiagram_ParamsTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_SteelDiagram_ParamsTable(void);
	virtual ~CAccessSysData_SteelDiagram_ParamsTable(void);

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

	NDataModelDataSet * GetEmptyDataSet() ;

	NDataModelDataSet * Get_SteelJTParms_DataSet( const int iSteelID);

	CString GetSteeldiagramParms( const int nDiagramID );

	void GetSteeldiagramParms( const int nDiagramID , CStringArray & aryParms ) ;

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
	NDataModelDataSet * GetDataSet() ; 

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
		static const int m_iGet_SteelJTParms_DataSet ;
		static PMTSTRING m_strGet_SteelJTParms_DataSet ; 

		/// 
		static const int m_iGetSteeldiagramParms ;
		static PMTSTRING m_strGetSteeldiagramParms ; 
	} ;
};
