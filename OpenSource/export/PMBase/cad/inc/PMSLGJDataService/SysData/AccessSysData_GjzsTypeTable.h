

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
class PmSLGJDataServiceAPI CSysGjzsTypeTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysGjzsTypeTable)

	CSysGjzsTypeTable();
	~CSysGjzsTypeTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString GJType;
		static const CString sideType;
		static const CString zs;
		static const CString ZSType;
		static const CString VectorDiagramID;

		static int GJType_Idx ;
		static int sideType_Idx ;
		static int zs_Idx ;
		static int ZSType_Idx ;
		static int VectorDiagramID_Idx ;

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


class PmSLGJDataServiceAPI CAccessSysData_GjzsTypeTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_GjzsTypeTable(void);
	virtual ~CAccessSysData_GjzsTypeTable(void);

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

	/// 
	NDataModelDataSet * Get_GJZSType_DataSet();

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
	} ;
};
