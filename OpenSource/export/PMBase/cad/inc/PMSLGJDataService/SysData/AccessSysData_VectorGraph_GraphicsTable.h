
#pragma once 



#include "AccessSysDataTable.h"

/**
 * @brief 
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-5]
 * @note  
 */
class PmSLGJDataServiceAPI CSysVectorGraph_GraphicsTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysVectorGraph_GraphicsTable)

	CSysVectorGraph_GraphicsTable();
	~CSysVectorGraph_GraphicsTable() ;

public:
	virtual int InitFieldStr();

public:

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id ;
		static const CString comtype ;
		static const CString VectorIndex ;
		static const CString VectorGraphName ;
		static const CString VectorGraph ;
		static const CString VectorGraphType ;
		static const CString VectorInfo ;
		static const CString GangJinVector;	//�Զ��� �ֽ������Ϣ----��������ʹ��
		static const CString Bz ;

		static int id_Idx ;
		static int comtype_Idx ;
		static int VectorIndex_Idx ;
		static int VectorGraphName_Idx ;
		static int VectorGraph_Idx ;
		static int VectorGraphType_Idx ;
		static int VectorInfo_Idx ;
		static int GangJinVector_Idx;//�Զ��� �ֽ������Ϣ 
		static int Bz_Idx ;

	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

};


class PmSLGJDataServiceAPI CAccessSysData_VectorGraph_GraphicsTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_VectorGraph_GraphicsTable(void);
	virtual ~CAccessSysData_VectorGraph_GraphicsTable(void);

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

	static PmTString GetSQL(const int iSQLIndex);

	/**
	* @brief  ��ȡ ���ͼ ͼ�λ��� Buffer 
	*
	*          
	* @note  : pVectorBuffer ��Ҫɾ�� 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL GetVectorGraph_VectorID(int iVectorID,LPVOID & pVectorBuffer,long & lVectorBufferSize);

	/**
	* @brief  ��ȡVector�� ������Ϣ��Table 
	*
	*          
	* @note  : Ŀǰֻ��CSLComponentManagerʹ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	BOOL GetVectorDrawInfo_Table(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief   ����vectorInfo �� ������Ϣ
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [6/28/2016]
	*/
	BOOL SetVectorDrawInfo_Table(int iVectorID,LPVOID pVectorBuffer,long lVectorBufferSize);

	/// ��ȡ vectorid �� vectorname
	BOOL GetVectorForComtype(int comtype,CUIntArray & arrVectorIdMain,CStringArray & arrVectorName);	

	/// ��ȡ vectordialog ��ʾ�� vectorid 
	BOOL GetVectorForVectorDialog(int comtype,CUIntArray & arrVectorIdMain,CStringArray & arrVectorBz,CStringArray & arrVectorChild);

	/**
	* @brief ���� ���ͼ ���� ��Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL SetVectorGraph_VectorID(int iVectorID,LPVOID pVectorBuffer,long lVectorBufferSize);
	
	/**
	* @brief  ��ȡ VectorName 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL GetVectorName_VectorID(int iVectoriD,CString & strVectorName);

	//��ȡĳ vectorid ��Ӧ�����ݿ���Ϣ
	BOOL GetTableCtrl_VectorID(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief  ɾ��ָ��VectorID�� ͼ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL DeleteVector_VectorID(int iVectorID);

	/**
	* @brief   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL GetOwnGangJinVector_VectorID(int iVectorID,LPVOID & pGangJinVector,long & lGangjinVectorSize);

	/**
	* @brief ���� �Զ���ֽ� ���� ��Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL SetOwnGangJinVector_VectorID(int iVectorID,LPVOID pGangJinVector,long lGangJinVectorSize);

	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetTableCtrlForComtype(int comtype,CPMSQLTableCtrl *& pSQLTableCtrl);

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	/**
	* @brief ��ȡ Vector Bz  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL GetVectorBz_VectorID(int iVectorID,CString & strBz);

	/**
    * @brief ����iVectorID�ı�ע��Ϣ
    *
    *        ���������Զ���������ı�ע��Ϣ
    * @author hn
    * @version v1.0
    * @date   
    * @note  
    */
	BOOL SetVectorIDBz(int iVectorID,const CString & strBz);

	struct PmSLGJDataServiceAPI SQLInfo
	{
		const static int		m_iSelectVectorInfo_Sql;
		const static PmTString m_strSelectVectorInfo_Sql;//��ȡ Vector ������Ϣ�� sql

		const static int		m_iSelectVectorGraph_Sql;
		const static PmTString	m_strSelectVectorGraph_Sql;//��ȡ����ͼ�λ��� sql

		const static int		m_iUpdateVectorGraph_Sql;
		const static PmTString  m_strUpdateVectorGraph_Sql;//���� ͼ�λ��� sql

		const static int		m_iInsertVectorInfo_Sql;
		const static PmTString  m_strInsertVectorInfo_Sql;//���� ͼ�λ�����Ϣ sql

		const static int		m_iSelectVectorName_Sql;
		const static PmTString	m_strSelectVectorName_Sql;//��ȡ VectorName sql

		const static int		m_iDeleteVectorID_Sql;
		const static PmTString  m_strDeleteVectorID_Sql;//ɾ��ָ��VectoriD sql

		const static int		m_iSelectOwnGangJin_Sql;
		const static PmTString  m_strSelectOwnGangJin_Sql;//��ȡ ָ��VetoriD �ֽ�� sql

		const static int		m_iUpdateOwnGangJin_Sql;
		const static PmTString	m_strUpdateOwnGangJin_Sql;//���� ָ��VectorID �ֽ�� sql

		const static int		m_iSelectAllInfo_VectorID_Sql;
		const static PmTString	m_strSelectAllInfo_VectorID_Sql;//��ȡVector�� ������ ������Ϣ�� sql

		const static int		m_iUpdateVectorInfo_Sql;
		const static PmTString m_strUpdateVectorInfo_Sql;//���� VectorGraph��ͼ�� sql

		const static int		m_iSelectVectorBz_Sql;
		const static PmTString	m_strSelectVectorBz_Sql;//��ȡ Vector��Bz sql

		const static int		m_iUpdateVectorBz_Sql;
		const static PmTString m_strUpdateVectorBz_Sql;//����vectorID��ע sql
	};
};
