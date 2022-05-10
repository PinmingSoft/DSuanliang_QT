
#pragma  once 



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
class PmSLGJDataServiceAPI CSysCsflibTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysCsflibTable)

	CSysCsflibTable();
	~CSysCsflibTable() ;



public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString libcode;
		static const CString comtype;
		static const CString parmName;
		static const CString des ;

		static int libcode_Idx ;
		static int comtype_Idx ;
		static int parmName_Idx ;
		static int des_Idx ;

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


class PmSLGJDataServiceAPI CAccessSysData_CsflibTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_CsflibTable(void);
	virtual ~CAccessSysData_CsflibTable(void);

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
	/// 
	///  dataset ��Ҫ��Χά�� ������ʹ���е�index��������д����
	/// 
	NDataModelDataSet * GetLibDataSet( const int comType, const CString & parmName) ;
	
	///
	///
	///  dataset ��Ҫ��Χά��������ʹ���е�index��������д����
	/// 
	CSysCsflibTable * GetEmptyDataSet();

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
 		static const int m_iGetLibDataSet ;
 		static PMTSTRING m_strGetLibDataSet ;
 	};

};
