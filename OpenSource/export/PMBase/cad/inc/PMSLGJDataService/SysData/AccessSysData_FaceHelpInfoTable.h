

#pragma once 


#include "AccessSysDataTable.h"

/**
 * @brief 
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CSysFaceHelpInfoTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysFaceHelpInfoTable)

	CSysFaceHelpInfoTable();
	~CSysFaceHelpInfoTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id ;
		static const CString comtype ;
		static const CString colname ;
		static const CString chname ;
		static const CString value ;
		static const CString exp ;

		static int id_Idx ;
		static int comtype_Idx ;
		static int colname_Idx ;
		static int chname_Idx ;
		static int value_Idx ;
		static int exp_Idx ;

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


class PmSLGJDataServiceAPI CAccessSysData_FaceHelpInfoTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_FaceHelpInfoTable(void);
	virtual ~CAccessSysData_FaceHelpInfoTable(void);

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

	NDataModelDataSet * GetDataSet( const int iComType , const CString & strColName ) ;

	NDataModelDataSet * GetDataSet( const int iComType  ) ;

	/// 
	/// ��ȡ�յ�DataSet 
	CSysFaceHelpInfoTable * GetEmptyDataSet();

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
		static const int m_iGetDataSet_ComType ; 
		static PMTSTRING m_strGetDataSet_ComType ; 

		///
		static const int m_iGetDataSet_ComType_ParamName ; 
		static PMTSTRING m_strGetDataSet_ComType_ParamName ; 
	} ;
};
