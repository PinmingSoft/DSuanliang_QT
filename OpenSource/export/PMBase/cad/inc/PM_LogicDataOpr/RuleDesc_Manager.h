// RuleDesc_Manager.h: interface for the CRuleDesc_Manager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RULEDESC_MANAGER_H__1CB0E562_7A90_4FF2_879C_12335F265FEE__INCLUDED_)
#define AFX_RULEDESC_MANAGER_H__1CB0E562_7A90_4FF2_879C_12335F265FEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PMLogicDataOprAPI CRuleDesc_Manager  
{
public:
	BOOL GetCalRuleName(int iCalID,CString & strRuleName);
	void GetAllRuleName(CStringArray & arrRuleName) const;

	class CRuleInfo
	{
	public:
		CRuleInfo(int iCalRuleID,TCHAR * pCalRuleName,CArray <int, int&> & iRuleComTypeArr);
		virtual ~CRuleInfo();

		int GetCalRuleID();
		TCHAR * GetCalRuleName();
		CArray <int, int&> * GetRuleComTypes();

	protected:
		int m_iCalRuleID;
		TCHAR * m_pCalRuleName;
		CArray <int, int&> m_iRuleComTypeArr;
	};

	class CDefRelationComType
	{
	public:
		CDefRelationComType(int iComType,CArray <int, int&> & iRelationComTypeArr);
		~CDefRelationComType();

		int GetComType();
		CArray <int, int&> * GetRelationComType();

	protected:

		int m_iComType;
		CArray <int, int&> m_iRelationComTypeArr;
	};

	BOOL GetCalRule_ComType(int iComType,int iCalID,CArray <int, int&> &ComTypeArray);

	BOOL GetDefRelationComType(int iComType,CArray <int, int&> &ComTypeArray);
	
	static CRuleDesc_Manager * Instance()
	{
		if(NULL == m_pInstance)
		{
			m_pInstance = PMNew(CRuleDesc_Manager);
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

protected:
	
	CRuleDesc_Manager();
	virtual ~CRuleDesc_Manager();

	typedef std::map<int,CRuleInfo*>	CalRuleIDMapInfo_T;
	typedef std::map<int,CDefRelationComType*>	DefRelationComTypeMapInfo_T;

	CalRuleIDMapInfo_T m_AddCalRuleMap;
	CalRuleIDMapInfo_T m_KouCalRuleMap;
	DefRelationComTypeMapInfo_T m_DefRelationMap;

	static CRuleDesc_Manager * m_pInstance;

	CString	m_strIniFilePath;

	/// zfy add 2015.12.11,添加所有计算规则
	CStringArray m_arrRuleDesc;

private:

	CRuleDesc_Manager::CRuleInfo * BuildRuleInfo(int iCalID);
};

#endif // !defined(AFX_RULEDESC_MANAGER_H__1CB0E562_7A90_4FF2_879C_12335F265FEE__INCLUDED_)
