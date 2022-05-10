// QDDE_FJCC_Controler.h: interface for the CQDDE_FJCC_Controler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QDDE_FJCC_CONTROLER_H__9A122B88_B1AC_4348_8315_54F5E187EA9C__INCLUDED_)
#define AFX_QDDE_FJCC_CONTROLER_H__9A122B88_B1AC_4348_8315_54F5E187EA9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QDDE_FJCCManager.h"

class PMLogicDataOprAPI CQDDE_FJCC_Controler  
{
public:

	/******************************************************************** 
	 功能描述：获取软件编号
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[3/2/2009]
	*********************************************************************/ 
	CString GetSoftCode()
	{
		return m_strSoftCode;
	}

	/******************************************************************** 
	 功能描述：将附件尺寸 变为 字符串 用于保存
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[1/9/2008]
	*********************************************************************/ 
	BOOL GetFJCC_String(NDataModelDataSet * pFJCCDataSet,CString &strFJCCInfo);
	
	/******************************************************************** 
	 功能描述：将字符串信息变为 附件尺寸
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[1/9/2008]
	*********************************************************************/ 
	BOOL GetFJCCInfo(int iParmID,CString strParmInfo,NDataModelDataSet * pFJCCDataSet);

	//返回指针 不用维护
	NDataModelDataSet * GetFJCCDataSet()
	{
		return m_pDataSetQDDEFJCC;
	}

	static CQDDE_FJCC_Controler *Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = PMNew(CQDDE_FJCC_Controler);
		}
		return m_pInstance;
	}
	static void Release()
	{
		if (m_pInstance != NULL)
		{
			PMDelete(m_pInstance);
			m_pInstance = NULL;
		}
	}
private:
	void InitFJXXInfo();
	CQDDE_FJCC_Controler();
	virtual ~CQDDE_FJCC_Controler();

	static CQDDE_FJCC_Controler * m_pInstance;

	CQDDE_FJCCManager m_QDDEFJCCManager;
	NDataModelDataSet * m_pDataSetQDDEFJCC;

	CString m_strSoftCode;//保存附件尺寸 软件编码
};

#endif // !defined(AFX_QDDE_FJCC_CONTROLER_H__9A122B88_B1AC_4348_8315_54F5E187EA9C__INCLUDED_)
