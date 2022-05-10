

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
class PmSLGJDataServiceAPI CSysSteelDiagram_LibTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysSteelDiagram_LibTable)

	CSysSteelDiagram_LibTable();
	~CSysSteelDiagram_LibTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString parentid;
		static const CString libName;

		static int id_Idx;
		static int parentid_Idx;
		static int libName_Idx;

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


class PmSLGJDataServiceAPI CAccessSysData_SteelDiagram_LibTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_SteelDiagram_LibTable(void);
	virtual ~CAccessSysData_SteelDiagram_LibTable(void);

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
	NDataModelDataSet * GetLibDataSetFirstLevel();
	NDataModelDataSet * GetLibDataSetChildLevel( const int parentID );

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
		static const int m_iGetLibDataSetFirstLevel ; 
		static PMTSTRING m_strGetLibDataSetFirstLevel ; 

		/// 
		static const int m_iGetLibDataSetChildLevel ; 
		static PMTSTRING m_strGetLibDataSetChildLevel ; 
	} ;
};
