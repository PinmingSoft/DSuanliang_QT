// ExternManager.h: interface for the CExternManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNMANAGER_H__B23BAA42_65E9_4A0C_8EFE_35269E4246CF__INCLUDED_)
#define AFX_EXTERNMANAGER_H__B23BAA42_65E9_4A0C_8EFE_35269E4246CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PMProjectDBSERVICE CExternTableBase
{
public:
	CExternTableBase()
	{
		m_pExternConnectCtrl = CConnectManager::Instance()->GetConnectCtrl(CPmDataBase::Extern);
	}
	virtual ~CExternTableBase()
	{
		m_pExternConnectCtrl = NULL;
	}

protected:

	CConnect_sqlite * m_pExternConnectCtrl;
};

class PMProjectDBSERVICE CExternManager
{
protected:
	CExternManager();
	virtual ~CExternManager();
	static CExternManager * m_pInstance;

public:
	void ReleasePublicGJ();
	void ReleaseProject();

	static CExternManager *Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = PMNew(CExternManager);
		}
		return m_pInstance;
	}
	static void Release()
	{
		if ( m_pInstance )
		{
			PMDelete(m_pInstance);
			m_pInstance = NULL;
		}
	}
};




class PMProjectDBSERVICE CExternConnectTransaction
{
public:
	CExternConnectTransaction()
	{
		CConnect_sqlite * pConnectSqlite = CConnectManager::Instance()->GetConnectCtrl(CPmDataBase::Extern);
		if(NULL == pConnectSqlite)
		{
			m_pSQLTransaction = NULL;
			return;
		}
		m_pSQLTransaction = PMNew_Parm(CPMSQLBaseCtrl::CSQLTransaction,(pConnectSqlite->GetSQLBaseCtrl()));

	}

	virtual ~CExternConnectTransaction()
	{
		if(NULL != m_pSQLTransaction)
		{
			PMDelete(m_pSQLTransaction);
		}
	}

protected:

	CPMSQLBaseCtrl::CSQLTransaction * m_pSQLTransaction;
};

#endif // !defined(AFX_EXTERNMANAGER_H__B23BAA42_65E9_4A0C_8EFE_35269E4246CF__INCLUDED_)
