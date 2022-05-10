#pragma once
//zfy atten 2018.01.10,�����Ѳ���ʹ��
#include "QDDE_SWLManager.h"
class CQDDE_SWL_Controler
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

	NDataModelDataSet * GetQDDESWLDataSet()
	{
		return m_pDataSetQDDESWL;
	}

	BOOL GetSWL_AllowUnit(int iParmID,CString & strAllowUnit);
	
	/******************************************************************** 
	 �������������ַ�����Ϣ��Ϊ �������
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[1/9/2008]
	*********************************************************************/ 
	BOOL GetSWLInfo(int iParmID,CString strParmInfo,NDataModelDataSet * pSWLDataSet);

	/// ��ȡiComType��Ӧ�ļ�����Ŀ��DataSt 
	/// �磺�����е�
	/// ����/���/���ý��ּ�
	NDataModelDataSet *  GetSWLInfo( const int iComType );

	/******************************************************************** 
	 ������������������� ��Ϊ �ַ��� ���ڱ���
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[1/9/2008]
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

	CString m_strSoftCode;//���������� �������
};
