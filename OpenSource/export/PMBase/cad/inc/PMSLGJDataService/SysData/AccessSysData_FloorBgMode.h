
#pragma  once 



#include "AccessSysDataTable.h"

/**
 * @brief ���ģʽ
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-9-5]
 * @note  
 */
class PmSLGJDataServiceAPI CSysFloorBGModeTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysFloorBGModeTable)

	CSysFloorBGModeTable();
	virtual ~CSysFloorBGModeTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;			
		static const CString floorid;						//¥��ID
		static const CString comtype;						//��������
		static const CString comname;						//��������
		static const CString bgmode;						//��ģʽ 0��¥���� 1�����̱��

		static const CString table_name;					//����
	};

	virtual int InitFieldStr();
};


class PmSLGJDataServiceAPI CAccessSysData_FloorBGModeTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_FloorBGModeTable(void);
	virtual ~CAccessSysData_FloorBGModeTable(void);

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
	BOOL GetRowCount( int & iRowCount ) ; 


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
