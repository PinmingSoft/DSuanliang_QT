

#pragma  once 


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
class PmSLGJDataServiceAPI CSysRegInfoTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysRegInfoTable)

	CSysRegInfoTable();
	~CSysRegInfoTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString ID ;
		static const CString RegName ;		/// ����ǰ�����$���ţ��� $2B25$
		static const CString RegInfo ;		/// ԭ�ӵ�������ʽ���������ŵġ�
		static const CString RegInfoKH ;	/// ԭ�ӵ�������ʽ�������ŵġ�
		static const CString Type ;			
		/// ���ʽ������.Ŀǰ��λ���� 10 ��ʾ��ԭ�ӱ��ʽ�����Ǹֽ���ʽ
		/// ��һλ�Ƿ���ԭ�ӱ��ʽ 1:ԭ�ӱ��ʽ��2:���ӱ��ʽ��
		/// �ڶ�λ�Ƿ��Ǹֽ���ʽ1���ֽ���ʽ��0 �����Ǹֽ�ı��ʽ

		static int ID_Idx ;
		static int RegName_Idx ;		
		static int RegInfo_Idx ;		
		static int RegInfoKH_Idx ;	
		static int Type_Idx ;	


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


class PmSLGJDataServiceAPI CAccessSysData_RegInfoTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_RegInfoTable(void);
	virtual ~CAccessSysData_RegInfoTable(void);

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
