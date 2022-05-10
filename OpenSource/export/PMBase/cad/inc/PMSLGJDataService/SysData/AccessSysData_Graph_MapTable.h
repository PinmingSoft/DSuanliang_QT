

#pragma  once 


#include "AccessSysDataTable.h"

/**
 * @brief 
 *
 *        
 * @author 杨兴耀
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

	//获取 CSysGraphMapTable
	CSQLDataSet * GetDataSet();

	/**
	* @brief   尝试 升级表结构
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/6/2012]
	*/
	virtual BOOL TryUpdateTableField();

	/**
	* @brief   获取版本号
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-7-3]
	*/
	static	int	GetCurVersion() ;

	/**
	* @brief  通过 钢筋的VectorID 获取 算量 VectorID
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	int GetSLVectorID( int nGraphicsVectorID ) ;

	/**
	* @brief  通过 算量 VectorID 获取 钢筋VectorID 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	int GetGraphicsVectorID( int nVectorID ) ;

	/**
	* @brief  查找钢筋Vector 对应的 Vector 列表 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL FindGJVectorList( const int & nGJVectorID , CString & strGJVectorIDs);

	/**
	* @brief  通过 算量 VectorID 查找 第一个钢筋图形
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL FindGJVector ( const int & nVectorID , int & iGrphicsVectorID );

	/**
	* @brief 判断 指定的 算量 VectorID  是否有效  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL FindSLVector( const int & nVectorID );

	//



	//
	static PmTString GetSQL(const int iSQLIndex);

	struct PmSLGJDataServiceAPI SQLInfo
	{
		const static int		m_iInsertInfo_Sql;
		const static PmTString	m_strInsertInfo_Sql;//插入 记录 sql

		const static int		m_iSelectGJVectorID_SLVectorID_Sql;
		const static PmTString	m_strSelectGJVectorID_SLVectorID_Sql;//获取 钢筋VectorID 通过 算量VectorID

		const static int		m_iDeleteInfo_SLVectorID_Sql;
		const static PmTString	m_strDeleteInfo_SLVectorID_Sql;//删除指定的 算量 VectorID
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
	* @brief   寻找匹配关系，如果失败，则内部返回的指针为空
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [6/5/2020]
	*/
	PMShared_Ptr<CUIntArray> GetVectorMap(int vectorIdIndex) const;

	// 查找父类的 vectorid
	int FindVectorIdParent(int vectorid_gj) const;

	//获取 comtype  下允许显示在矢量图对话框中的 VectorId
	void GetVectorId(int comtype,CUIntArray & arrVectorIdIndex) const;

private:
	static CAccessSysData_GraphMapTableOpr * m_pInstance;

	//
	CSQLDataSet * m_pDataset;

	//vector分层组织结构
	std::map<int ,PMShared_Ptr<CUIntArray> > m_mapVector2GraphicsVector;

	//comtype 与vectorid的匹配
	std::map<int ,PMShared_Ptr<CUIntArray> > m_mapComtype2VectorId;

	//child (comtype|GraphicsVectorIndex ) 与 VectorIndex 的匹配
	std::map<CString,int> m_mapGraphicsVectorIndex2VectoriId;


	//
	CAccessSysData_GraphMapTableOpr();
	~CAccessSysData_GraphMapTableOpr();

};