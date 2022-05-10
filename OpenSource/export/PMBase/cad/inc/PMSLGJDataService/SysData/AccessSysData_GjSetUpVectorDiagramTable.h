

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
class PmSLGJDataServiceAPI CSysGJSetupVectorDiagramTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysGJSetupVectorDiagramTable)

	CSysGJSetupVectorDiagramTable();
	~CSysGJSetupVectorDiagramTable() ;

public:
	virtual int InitFieldStr();

public:

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString gjtype;
		static const CString combinedzs;
		static const CString combinedType;
		static const CString VertorDiagramID;

		static int id_Idx ;
		static int gjtype_Idx ;
		static int combinedzs_Idx ;
		static int combinedType_Idx ;
		static int VertorDiagramID_Idx ;

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


class PmSLGJDataServiceAPI CAccessSysData_GJSetupVectorDiagramTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_GJSetupVectorDiagramTable(void);
	virtual ~CAccessSysData_GJSetupVectorDiagramTable(void);

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
	int Get_GJGBVectorDiagramID( const CString & strGHZS ,const CString & strGHType) ;

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
		static const int m_iGet_GJGBVectorDiagramID ; 
		static PMTSTRING m_strGet_GJGBVectorDiagramID ; 
	} ;
};
