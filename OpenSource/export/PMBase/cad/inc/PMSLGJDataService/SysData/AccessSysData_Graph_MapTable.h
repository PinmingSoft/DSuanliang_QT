

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
class PmSLGJDataServiceAPI CSysGraphMapTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysGraphMapTable)

	CSysGraphMapTable();
	~CSysGraphMapTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString ID ;
		static const CString VectorIndex ;
		static const CString Comtype;
		static const CString GraphicsVectorIndex ;

		static int ID_Idx ;
		static int VectorIndex_Idx ;
		static int GraphicsVectorIndex_Idx ;
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};
};


class PmSLGJDataServiceAPI CAccessSysData_GraphMapTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_GraphMapTable(void);
	virtual ~CAccessSysData_GraphMapTable(void);

	//��ȡ CSysGraphMapTable
	CSQLDataSet * GetDataSet();

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
	* @brief  ͨ�� �ֽ��VectorID ��ȡ ���� VectorID
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	int GetSLVectorID( int nGraphicsVectorID ) ;

	/**
	* @brief  ͨ�� ���� VectorID ��ȡ �ֽ�VectorID 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	int GetGraphicsVectorID( int nVectorID ) ;

	/**
	* @brief  ���Ҹֽ�Vector ��Ӧ�� Vector �б� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL FindGJVectorList( const int & nGJVectorID , CString & strGJVectorIDs);

	/**
	* @brief  ͨ�� ���� VectorID ���� ��һ���ֽ�ͼ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL FindGJVector ( const int & nVectorID , int & iGrphicsVectorID );

	/**
	* @brief �ж� ָ���� ���� VectorID  �Ƿ���Ч  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL FindSLVector( const int & nVectorID );

	//



	//
	static PmTString GetSQL(const int iSQLIndex);

	struct PmSLGJDataServiceAPI SQLInfo
	{
		const static int		m_iInsertInfo_Sql;
		const static PmTString	m_strInsertInfo_Sql;//���� ��¼ sql

		const static int		m_iSelectGJVectorID_SLVectorID_Sql;
		const static PmTString	m_strSelectGJVectorID_SLVectorID_Sql;//��ȡ �ֽ�VectorID ͨ�� ����VectorID

		const static int		m_iDeleteInfo_SLVectorID_Sql;
		const static PmTString	m_strDeleteInfo_SLVectorID_Sql;//ɾ��ָ���� ���� VectorID
	};
};

class PmSLGJDataServiceAPI CAccessSysData_GraphMapTableOpr
{
public:
	static CAccessSysData_GraphMapTableOpr * Instance()
	{
		if (NULL == m_pInstance)
		{
			m_pInstance = PMNew(CAccessSysData_GraphMapTableOpr);
		}
		return m_pInstance;
	}

	//
	static void Release(){PMDelete(m_pInstance);}

	//
	/**
	* @brief   Ѱ��ƥ���ϵ�����ʧ�ܣ����ڲ����ص�ָ��Ϊ��
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [6/5/2020]
	*/
	PMShared_Ptr<CUIntArray> GetVectorMap(int vectorIdIndex) const;

	// ���Ҹ���� vectorid
	int FindVectorIdParent(int vectorid_gj) const;

	//��ȡ comtype  ��������ʾ��ʸ��ͼ�Ի����е� VectorId
	void GetVectorId(int comtype,CUIntArray & arrVectorIdIndex) const;

private:
	static CAccessSysData_GraphMapTableOpr * m_pInstance;

	//
	CSQLDataSet * m_pDataset;

	//vector�ֲ���֯�ṹ
	std::map<int ,PMShared_Ptr<CUIntArray> > m_mapVector2GraphicsVector;

	//comtype ��vectorid��ƥ��
	std::map<int ,PMShared_Ptr<CUIntArray> > m_mapComtype2VectorId;

	//child (comtype|GraphicsVectorIndex ) �� VectorIndex ��ƥ��
	std::map<CString,int> m_mapGraphicsVectorIndex2VectoriId;


	//
	CAccessSysData_GraphMapTableOpr();
	~CAccessSysData_GraphMapTableOpr();

};