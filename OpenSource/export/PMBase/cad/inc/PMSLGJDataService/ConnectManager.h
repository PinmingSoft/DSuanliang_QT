#pragma once

#include "DataBaseAndTableName.h"
/**
* @brief   ���ݿ����ӻ���
*
*          
* @note  : û����������� ʵ��
* @param : 
* @defenc: 
* @return: 
* @author: ����ҵ
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
	* @brief  �޸� ��ǰ���ӵ� λ�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [26/6/2012]
	*/
	CString GetFilePath() const;

	/**
	* @brief  ��ǰ���� �ļ��� λ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [26/6/2012]
	*/
	CString GetFileDir() const;

	
	void	SetIniPath( const CString & strIniPath ) ; 

	CString	GetIniPath( ) const ; 

	/**
	* @brief  ���ڵ�ǰ���ӵ� ���ü��� 
	*			�������ü���
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [26/6/2012]
	*/
	bool AddUseCount();

	/**
	* @brief ���ڵ�ǰ���ӵ� ���ü��� 
	*			�������ü���
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [26/6/2012]
	*/
	bool SubUseCount();

	/**
	* @brief   ��������Դ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [26/6/2012]
	*/
	virtual bool ConnectBase(const CString & strFilePath) = 0;

	/**
	* @brief  �ͷ�����Դ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [26/6/2012]
	*/
	virtual bool DisconnectBase() = 0;

	/**
	* @brief  �Ƿ������ ���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/8/2012]
	*/
	BOOL CheckHasBakDone()
	{
		return m_bHasBak;
	}

	/**
	* @brief ���豸�ݱ��  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/8/2012]
	*/
	void HasBakDone()
	{
		m_bHasBak = TRUE;
	}
protected:

	BOOL m_bHasBak;			//�Ƿ��н��й�����
	
	CString m_strFilePath; //Ҫ���ӵ����ݿ� λ��

	/// 
	CString	m_strIniPath ; /// �����ļ��� ·�� *.pmsl , ֻ��projectʱ�������壬

	int m_iConnectUseCount;//��ǰ���ݵ� ���Ӵ���
};

/**
* @brief  ���ݿ����ӵ� sqlite�� ʵ�֡� 
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: ����ҵ
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
	* @brief   ��������Դ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [26/6/2012]
	*/
	bool ConnectBase(const CString & strFilePath);

	/**
	* @brief  �ͷ�����Դ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [26/6/2012]
	*/
	bool DisconnectBase();

	/// 
	bool BackUpDataBase( const CString & strToFileName ) ;

	/**
	* @brief ��pTemDataSet�У�����SQL���ƶ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	BOOL RegSQLCtrl(CSQLDataSet * pTemDataSet);

	/**
	* @brief  ����SQL��� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [10/7/2012]
	*/
	static bool BuildSQL(CPMSQLBaseCtrl::CSQLType sqlType,CSQLDataSet * pDataSet,PmTString & sNewSQL);

	/**
	* @brief  ������ṹ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [10/7/2012]
	*/
	bool DoCreateSQLTable(CSQLDataSet * pTableDataSet);

	/**
	* @brief ��ȡ DataSet,���յ�ǰDataSet�Ľṹ������װ�� 
	*
	*          
	* @note  : �����Ҫ���棬ִ�� DataSet.UpdateSQL()����
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [8/6/2012]
	*/
	bool GetDataSet(CSQLDataSet * pDataSet);

	/**
	* @brief  ִ��sql ��װ��DataSet 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [28/6/2012]
	*/
	bool GetDataSet(LPCTSTR strSQL,CSQLDataSet * pDataSet);

	/**
	* @brief  ��ȡ ִ��sql֮��� ����� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [20/6/2012]
	*/
	bool GetSQLTableCtrl(LPCTSTR sSQL,CPMSQLTableCtrl *& pTableCtrl);

	/**
	* @brief  ͨ���Զ��ϳɵ� sql ��ȡ ����� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [28/6/2012]
	*/
	bool GetSQLTableCtrl(CStringArray & strSelectArr,CStringArray & strWhereKeyArr,CStringArray & strWhereValueArr,const CString & strTableName,CPMSQLTableCtrl *& pTableCtrl);

	/**
	* @brief ִ��SQL ���  
	*
	*          
	* @note  : ��Ϊ DataSet �����Ψһ ִ�нӿ�
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [8/6/2012]
	*/
	bool ExecuteSQL(LPCTSTR sSQL);
	bool ExecuteSQL_FAST(LPCTSTR sSQL);

	/**
	* @brief  ��ȡָ����� ���ֵ 
	*
	*          
	* @note  : ����ID�� ����
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	bool GetTable_ColMaxValue(const CString & strColName,const CString & strTableName,int & iMaxID);

	bool GetTable_ColMaxValue(const CString & strColName,const CString & strTableName, CString & strMaxID);

	/**
	* @brief   ��ȡָ����� ������
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
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
	//��ȡ����
	CConnect_sqlite * GetConnectCtrl(CPmDataBase::DataBaseName dataBaseName);

	//��������
	bool ConnectDataBase(CPmDataBase::DataBaseName dataBaseName,const CString & strFilePath);

	//��������
	bool ConnectDataBase( CPmDataBase::DataBaseName dataBaseName, CConnectBase * pNewConnect ,const CString & strFilePath);

	//�Ͽ�����
	bool DisConnectDataBase( CPmDataBase::DataBaseName dataBaseName);

	/// 
	bool	BackUpDataBase( CPmDataBase::DataBaseName dataBaseName,const CString & strToFilePath ) ;

	/// ������ݿ��������
	bool	CkeckProjectIntegrity( ) ;
	bool	CkeckSysdataIntegrity( ) ;
	bool    CkeckQdIntegrity();
	bool    CkeckTemplateIntegrity();

	/// 
	bool	CkeckDataBaseIntegrity( CPmDataBase::DataBaseName dataBaseName , const CString & strFilePath ) ;

public:

	/**
	* @brief  �޸� ��ǰ���ӵ� λ�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [26/6/2012]
	*/
	CString GetFilePath( const CPmDataBase::DataBaseName dataBaseName ) ;

	/**
	* @brief  ��ǰ���� �ļ��� λ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
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
 * @brief  :����Ŀ���
 *
 *          ע�����
 *			1�����񴥷����ڲ��������µ�ʵ��������֣���������sqlite3_open16�µ����Ӵ����Ĳ�ѯ��д�����
 *				����㣬�����ڲ������� CSqliteDataBase Db(xxx) ���� ���� sqlite3_open16 ����
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
