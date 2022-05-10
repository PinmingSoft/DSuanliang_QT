

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
class PmSLGJDataServiceAPI CSysSpecialVariableTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysSpecialVariableTable)

	CSysSpecialVariableTable();
	~CSysSpecialVariableTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString comtype ; 
		static const CString variables ; 

		static int comtype_Idx ; 
		static int variables_Idx ; 

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


class PmSLGJDataServiceAPI CAccessSysData_SpecialVariableTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_SpecialVariableTable(void);
	virtual ~CAccessSysData_SpecialVariableTable(void);

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

	////////////////////////////////////////////////////////////////
	/// at 2011��2��17��  15:20  by yxy
	/// ��ȡ�������ַ���
	CString  GetVariables( const int & nComType ) ; 

	/// ��ȡ������ DataSet 
	NDataModelDataSet * GetVariableDataSet( const int & nComType ) ; 

	///
	void	GetVariables( const int &nComType , CStringArray & ary_variable ) ; 

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
		static const int m_iGetVariables ; 
		static PMTSTRING m_strGetVariables ; 
	} ;
};
