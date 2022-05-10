// QDDE_JSGZ_Controler.h: interface for the CQDDE_AddJSGZ_Controler class.
//用于获取额外计算规则信息
//////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QDDE_AddJSGZManager.h"

class PMLogicDataOprAPI CQDDE_AddJSGZ_Controler  
{
public:

	/// 获取对应parmid的dataset
	NDataModelDataSet *  GetAddJSGZInfo( CString strParmId );
	
	static CQDDE_AddJSGZ_Controler *Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = PMNew(CQDDE_AddJSGZ_Controler);
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

	void InitAddJSGZInfo();

	CQDDE_AddJSGZ_Controler();
	virtual ~CQDDE_AddJSGZ_Controler();

	static CQDDE_AddJSGZ_Controler * m_pInstance;

	CQDDE_AddJSGZManager m_QDDEAddJSGZManager;

	NDataModelDataSet * m_pDataSetQDDEJSGZ;
};
