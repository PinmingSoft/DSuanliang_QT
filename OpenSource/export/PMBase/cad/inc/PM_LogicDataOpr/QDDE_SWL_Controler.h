#pragma once
//zfy atten 2018.01.10,本类已不再使用
#include "QDDE_SWLManager.h"
class CQDDE_SWL_Controler
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

	NDataModelDataSet * GetQDDESWLDataSet()
	{
		return m_pDataSetQDDESWL;
	}

	BOOL GetSWL_AllowUnit(int iParmID,CString & strAllowUnit);
	
	/******************************************************************** 
	 功能描述：将字符串信息变为 计算规则
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[1/9/2008]
	*********************************************************************/ 
	BOOL GetSWLInfo(int iParmID,CString strParmInfo,NDataModelDataSet * pSWLDataSet);

	/// 获取iComType对应的计算项目的DataSt 
	/// 如：天棚中的
	/// 基层/面层/满堂脚手架
	NDataModelDataSet *  GetSWLInfo( const int iComType );

	/******************************************************************** 
	 功能描述：将计算规则 变为 字符串 用于保存
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[1/9/2008]
	*********************************************************************/ 
	BOOL GetSWL_String(NDataModelDataSet * pSWLDataSet,CString &strSWLInfo);

	static CQDDE_SWL_Controler *Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = PMNew(CQDDE_SWL_Controler);
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

	void InitSWLInfo();
	
	BOOL FindSWLDataSetRow(int iParmID,int & iFindRow);

	CQDDE_SWL_Controler();
	virtual ~CQDDE_SWL_Controler();

	static CQDDE_SWL_Controler * m_pInstance;

	CQDDE_SWLManager m_QDDESWLManager;

	NDataModelDataSet * m_pDataSetQDDESWL;

	CString m_strSoftCode;//保存计算规则 软件编码
};
