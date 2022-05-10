
#pragma once 



#include "AccessSysData_VectorGraphTable.h"

/**
 * @brief 
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-5]
 * @note  
 */
class PmSLGJDataServiceAPI CSysVectorGraph_GjTable : public CSysDataTable
{
	
public:
	DECLARE_DYNCREATE(CSysVectorGraph_GjTable)

	enum GJ_VectorGraphType{VGT_PF,VGT_PARMS};

	CSysVectorGraph_GjTable();
	~CSysVectorGraph_GjTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id ;
		static const CString comtype ;
		static const CString VectorIndex ;
		static const CString VectorGraphName ;
		static const CString Bz ;
		static const CString VectorGraph ;
		static const CString VectorInfo ;
		static const CString VectorGraphType ;
		static const CString GangJinVector;//�Զ��� �ֽ������Ϣ 

		static int id_Idx ;
		static int comtype_Idx ;
		static int VectorIndex_Idx ;
		static int VectorGraphName_Idx ;
		static int Bz_Idx ;
		static int VectorGraph_Idx ;
		static int VectorInfo_Idx ;
		static int VectorGraphType_Idx ;
		static int GangJinVector_Idx;//�Զ��� �ֽ������Ϣ 

	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

};


class PmSLGJDataServiceAPI CAccessSysData_VectorGraph_GjTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_VectorGraph_GjTable(void);
	virtual ~CAccessSysData_VectorGraph_GjTable(void);

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

	BOOL GetVectorGraph( const int id, const int type, BYTE*&pbuff, int &buffSize);

	BOOL GetVectorGraph( const int id,  BYTE*&pbuff, int &buffSize);

	BOOL GetDataSet_ID(int id,CSQLDataSet *& pSQLDataSet);

	BOOL SetVectorData(int id, LPVOID pbuff, long buffSize) ;

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
		static const int m_iGetVectorGraph ; 
		static PMTSTRING m_strGetVectorGraph ; 

		//
		static const int m_iSelectAllInfo_VectorID;
		static PMTSTRING m_strSelectAllInfo_VectorID;
	} ;
};


/**
* @brief   ��װһЩ��ʱ����Ķ������ (�䵱 ����Access�� ������)
*
*          
* @note  : ����Ҫÿһ���õ��ĵط���ȥ����һ����ʱ���� �� ��һЩ�������͵�ת�������ڸ�����ʵ��
*
* @author: ����ҫ
* @date  : [2012-7-17]
*/

class PmSLGJDataServiceAPI CSysDataVectorGraphGjOpr
{
public:
	CSysDataVectorGraphGjOpr();
	~CSysDataVectorGraphGjOpr() ; 

public:
	static BOOL GetVectorGraph( const int id, const int type, BYTE*&pbuff, int &buffSize);

	static BOOL GetVectorGraph( const int id,  BYTE*&pbuff, int &buffSize);
};
