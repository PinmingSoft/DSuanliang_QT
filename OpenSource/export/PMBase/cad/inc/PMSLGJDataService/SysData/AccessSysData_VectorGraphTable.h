
#pragma once 




#include "AccessSysDataTable.h"

/**
 * @brief 
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-5]
 * @note  
 */
class PmSLGJDataServiceAPI CSysVectorGraphTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysVectorGraphTable)

	CSysVectorGraphTable();
	~CSysVectorGraphTable() ;

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
		static const CString GangJinVector;//自定义 钢筋绘制信息 

		static int id_Idx ;
		static int comtype_Idx ;
		static int VectorIndex_Idx ;
		static int VectorGraphName_Idx ;
		static int Bz_Idx ;
		static int VectorGraph_Idx ;
		static int VectorInfo_Idx ;
		static int VectorGraphType_Idx ;
		static int GangJinVector_Idx;//自定义 钢筋绘制信息 

	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};
};


class PmSLGJDataServiceAPI CAccessSysData_VectorGraphTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_VectorGraphTable(void);
	virtual ~CAccessSysData_VectorGraphTable(void);

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

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);
	
    /**
    * @brief 设置iVectorID的备注信息
    *
    *        用于设置自定义柱截面的备注信息
    * @author hn
    * @version v1.0
    * @date   
    * @note  
    */
	BOOL SetVectorIDBz(int iVectorID,const CString & strBz);
public:
	/**
	* @brief  获取Vector的 绘制信息，Table 
	*
	*          
	* @note  : 目前只给CSLComponentManager使用
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	BOOL GetVectorDrawInfo_Table(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief   更新vectorInfo 的 绘制信息
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [6/28/2016]
	*/
	BOOL SetVectorDrawInfo_Table(int iVectorID,LPVOID pVectorBuffer,long lVectorBufferSize);


	/**
	* @brief  获取 配筋图 图形绘制 Buffer 
	*
	*          
	* @note  : pVectorBuffer 需要删除 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL GetVectorGraph_VectorID(int iVectorID,LPVOID & pVectorBuffer,long & lVectorBufferSize);
	
	/**
	* @brief 保存 配筋图 绘制 信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL SetVectorGraph_VectorID(int iVectorID,LPVOID pVectorBuffer,long lVectorBufferSize);
	/**
	* @brief   获取 VectorName
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL GetVectorName_VectorID(int iVectorID,CString & strVectorName);

	/**
	* @brief  删除指定VectorID的 图 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL DeleteVector_VectorID(int iVectorID);

	/**
	* @brief 获取 Vector Bz  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	BOOL GetVectorBz_VectorID(int iVectorID,CString & strBz);

	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetTableCtrl_VectorID(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	static PmTString GetSQL(const int iSQLIndex);

	struct PmSLGJDataServiceAPI SQLInfo
	{
		const static int		m_iSelectVectorInfo_Sql;
		const static PmTString m_strSelectVectorInfo_Sql;//获取 Vector 绘制信息的 sql

		const static int		m_iSelectAllRowVectorInfo_Sql;
		const static PmTString m_strSelectAllRowVectorInfo_Sql;//获取Vector的 所有信息的 sql

		const static int		m_iSelectVectorGraph_Sql;
		const static PmTString m_strSelectVectorGraph_Sql;//获取 VectorGraph的图形 sql

		const static int		m_iUpdateVectorGraph_Sql;
		const static PmTString m_strUpdateVectorGraph_Sql;//保存 VectorGraph的图形 sql

		const static int		m_iInsertVectorInfo_Sql;
		const static PmTString m_strInsertVectorInfo_Sql;//插入 Vector信息

		const static int		m_iSelectVectorName_Sql;
		const static PmTString m_strSelectVectorName_Sql;//获取 VectorName的 sql

		const static int		m_iDeleteVectorID_Sql;
		const static PmTString m_strDeleteVectorID_Sql;//删除 指定的VectorID的 sql

		const static int		m_iSelectVectorBz_Sql;
		const static PmTString	m_strSelectVectorBz_Sql;//获取 Vector的Bz sql

		const static int		m_iSelectAllInfo_VectorID_Sql;
		const static PmTString	m_strSelectAllInfo_VectorID_Sql;//获取 Vector 所在列的所有信息 sql

		const static int		m_iUpdateVectorInfo_Sql;
		const static PmTString m_strUpdateVectorInfo_Sql;//保存 VectorGraph的图形 sql

		const static int		m_iUpdateVectorBz_Sql;
		const static PmTString m_strUpdateVectorBz_Sql;//设置vectorID备注 sql
	};
};
