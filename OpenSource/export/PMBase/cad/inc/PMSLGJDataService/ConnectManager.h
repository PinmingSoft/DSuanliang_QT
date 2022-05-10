#pragma once

#include "DataBaseAndTableName.h"
/**
* @brief   数据库连接基类
*
*          
* @note  : 没有真正意义的 实现
* @param : 
* @defenc: 
* @return: 
* @author: 王建业
* @date  : [26/6/2012]
*/
class CConnectBase
{
public:
	CConnectBase();
	virtual ~CConnectBase();

	/// 
	virtual void CheckTableIsLive()
	{

	}


	/**
	* @brief  修改 当前连接的 位置 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/6/2012]
	*/
	CString GetFilePath() const;

	/**
	* @brief  当前数据 文件夹 位置
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/6/2012]
	*/
	CString GetFileDir() const;

	
	void	SetIniPath( const CString & strIniPath ) ; 

	CString	GetIniPath( ) const ; 

	/**
	* @brief  用于当前连接的 引用计数 
	*			增加引用计数
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/6/2012]
	*/
	bool AddUseCount();

	/**
	* @brief 用于当前连接的 引用计数 
	*			减少引用计数
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/6/2012]
	*/
	bool SubUseCount();

	/**
	* @brief   连接数据源
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/6/2012]
	*/
	virtual bool ConnectBase(const CString & strFilePath) = 0;

	/**
	* @brief  释放数据源 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/6/2012]
	*/
	virtual bool DisconnectBase() = 0;

	/**
	* @brief  是否产生过 备份 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/8/2012]
	*/
	BOOL CheckHasBakDone()
	{
		return m_bHasBak;
	}

	/**
	* @brief 重设备份标记  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/8/2012]
	*/
	void HasBakDone()
	{
		m_bHasBak = TRUE;
	}
protected:

	BOOL m_bHasBak;			//是否有进行过备份
	
	CString m_strFilePath; //要连接的数据库 位置

	/// 
	CString	m_strIniPath ; /// 工程文件的 路径 *.pmsl , 只有project时才有意义，

	int m_iConnectUseCount;//当前数据的 连接次数
};

/**
* @brief  数据库连接的 sqlite的 实现。 
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: 王建业
* @date  : [26/6/2012]
*/ 
class PmSLGJDataServiceAPI CConnect_sqlite : public CConnectBase
{
public:
	CConnect_sqlite();
	virtual ~CConnect_sqlite();

	virtual void CheckTableIsLive()
	{

	}

	CPMSQLBaseCtrl * GetSQLBaseCtrl()
	{
		return m_pSQLBaseCtrl;
	}

	/**
	* @brief   连接数据源
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/6/2012]
	*/
	bool ConnectBase(const CString & strFilePath);

	/**
	* @brief  释放数据源 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/6/2012]
	*/
	bool DisconnectBase();

	/// 
	bool BackUpDataBase( const CString & strToFileName ) ;

	/**
	* @brief 在pTemDataSet中，加入SQL控制对象
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	BOOL RegSQLCtrl(CSQLDataSet * pTemDataSet);

	/**
	* @brief  生成SQL语句 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [10/7/2012]
	*/
	static bool BuildSQL(CPMSQLBaseCtrl::CSQLType sqlType,CSQLDataSet * pDataSet,PmTString & sNewSQL);

	/**
	* @brief  创建表结构 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [10/7/2012]
	*/
	bool DoCreateSQLTable(CSQLDataSet * pTableDataSet);

	/**
	* @brief 获取 DataSet,按照当前DataSet的结构，进行装载 
	*
	*          
	* @note  : 如果需要保存，执行 DataSet.UpdateSQL()函数
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [8/6/2012]
	*/
	bool GetDataSet(CSQLDataSet * pDataSet);

	/**
	* @brief  执行sql 并装载DataSet 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [28/6/2012]
	*/
	bool GetDataSet(LPCTSTR strSQL,CSQLDataSet * pDataSet);

	/**
	* @brief  获取 执行sql之后的 结果集 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [20/6/2012]
	*/
	bool GetSQLTableCtrl(LPCTSTR sSQL,CPMSQLTableCtrl *& pTableCtrl);

	/**
	* @brief  通过自动合成的 sql 获取 结果集 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [28/6/2012]
	*/
	bool GetSQLTableCtrl(CStringArray & strSelectArr,CStringArray & strWhereKeyArr,CStringArray & strWhereValueArr,const CString & strTableName,CPMSQLTableCtrl *& pTableCtrl);

	/**
	* @brief 执行SQL 语句  
	*
	*          
	* @note  : 作为 DataSet 保存的唯一 执行接口
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [8/6/2012]
	*/
	bool ExecuteSQL(LPCTSTR sSQL);
	bool ExecuteSQL_FAST(LPCTSTR sSQL);

	/**
	* @brief  获取指定表的 最大值 
	*
	*          
	* @note  : 用于ID的 推算
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	bool GetTable_ColMaxValue(const CString & strColName,const CString & strTableName,int & iMaxID);

	bool GetTable_ColMaxValue(const CString & strColName,const CString & strTableName, CString & strMaxID);

	/**
	* @brief   获取指定表的 总行数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-7-23]
	*/
	bool GetTable_RowCount( const CString & strTableName,int & iRowCount ) ;

	BOOL  IsTableExsit( const CString & strTableName ) ;

	BOOL ClearTable( const CString & strTableName ) ; 

protected:

	CPMSQLBaseCtrl * m_pSQLBaseCtrl;
};

class PmSLGJDataServiceAPI CConnectManager
{
public:
	
	static CConnectManager * Instance()
	{
		if(NULL == m_pInstance)
		{
			m_pInstance = PMNew(CConnectManager);
		}
		return m_pInstance;
	}

	static void Release()
	{
		if(NULL != m_pInstance)
		{
			PMDelete(m_pInstance);
			m_pInstance = NULL;
		}
	}

public:
	//获取连接
	CConnect_sqlite * GetConnectCtrl(CPmDataBase::DataBaseName dataBaseName);

	//进行连接
	bool ConnectDataBase(CPmDataBase::DataBaseName dataBaseName,const CString & strFilePath);

	//进行连接
	bool ConnectDataBase( CPmDataBase::DataBaseName dataBaseName, CConnectBase * pNewConnect ,const CString & strFilePath);

	//断开连接
	bool DisConnectDataBase( CPmDataBase::DataBaseName dataBaseName);

	/// 
	bool	BackUpDataBase( CPmDataBase::DataBaseName dataBaseName,const CString & strToFilePath ) ;

	/// 检测数据库的完整性
	bool	CkeckProjectIntegrity( ) ;
	bool	CkeckSysdataIntegrity( ) ;
	bool    CkeckQdIntegrity();
	bool    CkeckTemplateIntegrity();

	/// 
	bool	CkeckDataBaseIntegrity( CPmDataBase::DataBaseName dataBaseName , const CString & strFilePath ) ;

public:

	/**
	* @brief  修改 当前连接的 位置 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/6/2012]
	*/
	CString GetFilePath( const CPmDataBase::DataBaseName dataBaseName ) ;

	/**
	* @brief  当前数据 文件夹 位置
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/6/2012]
	*/
	CString GetFileDir( const CPmDataBase::DataBaseName dataBaseName ) ;

	CString	GetIniPath( const CPmDataBase::DataBaseName dataBaseName ) ;

	void	SetIniPath( const CPmDataBase::DataBaseName dataBaseName , const CString & strIniPath ) ;

protected:

	CConnectManager(void);
	virtual ~CConnectManager(void);

	static CConnectManager * m_pInstance;

	typedef std::map<int,CConnectBase*> CConnectBaseCtrlMap_T;
	CConnectBaseCtrlMap_T m_ConnenctBaseMap;
};

/**
 * @brief  :事务的控制
 *
 *          注意事项：
 *			1、事务触发后，内部不宜有新的实物操作出现，即不能有sqlite3_open16新的链接触发的查询或写入操作
 *				具体点，就是内部不能有 CSqliteDataBase Db(xxx) 函数 或者 sqlite3_open16 函数
 * @author :zfy
 * @version:v1.0
 * @date   :[5/17/2018]
 * @note   :
 */
class PmSLGJDataServiceAPI CProjectConnectTransaction
{
public:
	CProjectConnectTransaction()
	{
		CConnect_sqlite * pConnectSqlite = CConnectManager::Instance()->GetConnectCtrl(CPmDataBase::Project);
		if(NULL == pConnectSqlite)
		{
			m_pSQLTransaction = NULL;
			return;
		}
		m_pSQLTransaction = PMNew_Parm(CPMSQLBaseCtrl::CSQLTransaction,(pConnectSqlite->GetSQLBaseCtrl()));

	}

	virtual ~CProjectConnectTransaction()
	{
		if(NULL != m_pSQLTransaction)
		{
			PMDelete(m_pSQLTransaction);
		}
	}

protected:

	CPMSQLBaseCtrl::CSQLTransaction * m_pSQLTransaction;
};
