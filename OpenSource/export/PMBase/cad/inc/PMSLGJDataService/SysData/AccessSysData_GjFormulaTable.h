
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
class PmSLGJDataServiceAPI CSysGjFormulaTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysGjFormulaTable)

	CSysGjFormulaTable();
	~CSysGjFormulaTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString ID ;
		static const CString GanJinMode;
		static const CString GJJSFS ;
		static const CString GJZS ;
		static const CString GJBH ;
		static const CString ZJSL ;
		static const CString BBCD ;
		static const CString HBCD ;
		static const CString GJZCD ;

		static int ID_Idx ;
		static int GanJinMode_Idx ;
		static int GJJSFS_Idx ;
		static int GJZS_Idx ;
		static int GJBH_Idx ;
		static int ZJSL_Idx ;
		static int BBCD_Idx ;
		static int HBCD_Idx ;
		static int GJZCD_Idx ;

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


class PmSLGJDataServiceAPI CAccessSysData_GjFormulaTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_GjFormulaTable(void);
	virtual ~CAccessSysData_GjFormulaTable(void);

public:
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
	/// ��ȡ�յ�DataSet 
	CSysGjFormulaTable * GetEmptyDataSet();

	/// 
	NDataModelDataSet * GetDataSet( const int  iGanJinMode, const int nGJJSFS , const CString &strGJZS );

	/// 
	NDataModelDataSet * GetDataSet( const int nGJJSFS , const CString &strGJZS ) ;

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


public:
	static PMTSTRING	GetSql( const int iType ) ;

	//�̶���SQL ����
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 


		/// 
		static const int m_iGetDataSet1 ;
		static PMTSTRING m_strGetDataSet1 ;

		/// 
		static const int m_iGetDataSet2 ;
		static PMTSTRING m_strGetDataSet2 ;
	};
};
