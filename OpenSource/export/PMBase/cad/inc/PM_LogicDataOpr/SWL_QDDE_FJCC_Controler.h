// QDDE_FJCC_Controler.h: interface for the CQDDE_FJCC_Controler class.
//
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QDDE_FJCCManager.h"
/**
 * @brief  :
 * ���������ȡʵ���������ø��ӳߴ����
 *          
 * @author :���й�
 * @version:v1.0
 * @date   :[12/2/2016]
 * @note   :
 */

class PMLogicDataOprAPI CSWL_QDDE_FJCC_Controler  
{
public:

	/******************************************************************** 
	 ������������ȡ������
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[3/2/2009]
	*********************************************************************/ 
	CString GetSoftCode()
	{
		return m_strSoftCode;
	}

	/******************************************************************** 
	 �����������������ߴ� ��Ϊ �ַ��� ���ڱ���
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[1/9/2008]
	*********************************************************************/ 
	BOOL GetFJCC_String(NDataModelDataSet * pFJCCDataSet,CString &strFJCCInfo);
	
	/******************************************************************** 
	 �������������ַ�����Ϣ��Ϊ �����ߴ�
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[1/9/2008]
	*********************************************************************/ 
	BOOL GetFJCCInfo(int iParmID,CString strParmInfo,NDataModelDataSet * pFJCCDataSet);

	//����ָ�� ����ά��
	NDataModelDataSet * GetFJCCDataSet()
	{
		return m_pDataSetQDDEFJCC;
	}

	static CSWL_QDDE_FJCC_Controler *Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = PMNew(CSWL_QDDE_FJCC_Controler);
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
	CSWL_QDDE_FJCC_Controler();
	virtual ~CSWL_QDDE_FJCC_Controler();

	static CSWL_QDDE_FJCC_Controler * m_pInstance;

	CQDDE_FJCCManager m_QDDEFJCCManager;
	NDataModelDataSet * m_pDataSetQDDEFJCC;

	CString m_strSoftCode;//���渽���ߴ� �������
};

