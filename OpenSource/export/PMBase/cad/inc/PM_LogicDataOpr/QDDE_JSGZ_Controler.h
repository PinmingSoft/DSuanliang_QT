// QDDE_JSGZ_Controler.h: interface for the CQDDE_JSGZ_Controler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QDDE_JSGZ_CONTROLER_H__763DE1C6_51E3_47D1_ACBF_0608F56ACA15__INCLUDED_)
#define AFX_QDDE_JSGZ_CONTROLER_H__763DE1C6_51E3_47D1_ACBF_0608F56ACA15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QDDE_JSGZManager.h"

class PMLogicDataOprAPI CQDDE_JSGZ_Controler  
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

	NDataModelDataSet * GetQDDEJSGZDataSet()
	{
		return m_pDataSetQDDEJSGZ;
	}

	BOOL GetJSGZ_AllowUnit(int iParmID,CString & strAllowUnit);
	
	/******************************************************************** 
	 功能描述：将字符串信息变为 计算规则
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[1/9/2008]
	*********************************************************************/ 
	BOOL GetJSGZInfo(int iParmID,CString strParmInfo,NDataModelDataSet * pJSGZDataSet) const;

	/******************************************************************** 
	 功能描述：获取 中间变量 信息
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[1/9/2008]
	*********************************************************************/ 
	BOOL GetMidVarInfo(int iParmID,CString & strMidVarName,CString & strMidVarValue);

	/// 获取iComType对应的计算项目的DataSt 
	/// 如：天棚中的
	/// 基层/面层/满堂脚手架
	NDataModelDataSet *  GetJSGZInfo( const int iComType );

	/******************************************************************** 
	 功能描述：将计算规则 变为 字符串 用于保存
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[1/9/2008]
	*********************************************************************/ 
	BOOL GetJSGZ_String(NDataModelDataSet * pJSGZDataSet,CString &strJSGZInfo);

	static CQDDE_JSGZ_Controler *Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = PMNew(CQDDE_JSGZ_Controler);
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

	BOOL	IsComType5( const CString & sParmID ) ;

	/// 取 sParmID 的前三位或者四位
	CString	 GetComType3( const CString &  sParmID ) ;

private:

	void InitJSGZInfo();
	
	BOOL FindJSGZDataSetRow(int iParmID,int & iFindRow) const;

	CQDDE_JSGZ_Controler();
	virtual ~CQDDE_JSGZ_Controler();

	static CQDDE_JSGZ_Controler * m_pInstance;

	CQDDE_JSGZManager m_QDDEJSGZManager;

	NDataModelDataSet * m_pDataSetQDDEJSGZ;

	CString m_strSoftCode;//保存计算规则 软件编码
};

#endif // !defined(AFX_QDDE_JSGZ_CONTROLER_H__763DE1C6_51E3_47D1_ACBF_0608F56ACA15__INCLUDED_)
