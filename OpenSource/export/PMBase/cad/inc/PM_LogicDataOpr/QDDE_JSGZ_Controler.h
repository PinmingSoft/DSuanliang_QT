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

	NDataModelDataSet * GetQDDEJSGZDataSet()
	{
		return m_pDataSetQDDEJSGZ;
	}

	BOOL GetJSGZ_AllowUnit(int iParmID,CString & strAllowUnit);
	
	/******************************************************************** 
	 �������������ַ�����Ϣ��Ϊ �������
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[1/9/2008]
	*********************************************************************/ 
	BOOL GetJSGZInfo(int iParmID,CString strParmInfo,NDataModelDataSet * pJSGZDataSet) const;

	/******************************************************************** 
	 ������������ȡ �м���� ��Ϣ
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[1/9/2008]
	*********************************************************************/ 
	BOOL GetMidVarInfo(int iParmID,CString & strMidVarName,CString & strMidVarValue);

	/// ��ȡiComType��Ӧ�ļ�����Ŀ��DataSt 
	/// �磺�����е�
	/// ����/���/���ý��ּ�
	NDataModelDataSet *  GetJSGZInfo( const int iComType );

	/******************************************************************** 
	 ������������������� ��Ϊ �ַ��� ���ڱ���
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[1/9/2008]
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

	/// ȡ sParmID ��ǰ��λ������λ
	CString	 GetComType3( const CString &  sParmID ) ;

private:

	void InitJSGZInfo();
	
	BOOL FindJSGZDataSetRow(int iParmID,int & iFindRow) const;

	CQDDE_JSGZ_Controler();
	virtual ~CQDDE_JSGZ_Controler();

	static CQDDE_JSGZ_Controler * m_pInstance;

	CQDDE_JSGZManager m_QDDEJSGZManager;

	NDataModelDataSet * m_pDataSetQDDEJSGZ;

	CString m_strSoftCode;//���������� �������
};

#endif // !defined(AFX_QDDE_JSGZ_CONTROLER_H__763DE1C6_51E3_47D1_ACBF_0608F56ACA15__INCLUDED_)
