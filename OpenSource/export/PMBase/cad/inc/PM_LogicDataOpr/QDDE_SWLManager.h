#pragma once

class PMLogicDataOprAPI CQDDE_SWLManager
{
public:
	CQDDE_SWLManager(void);
	~CQDDE_SWLManager(void);

	NDataModelDataSet * m_pDataSetSWL;
	BOOL LoadXML(CString sXMLName,CString strComName);

	// �����ݿ��ж�ȡ�����ݼ���ȥ
	BOOL LoadDataSet(CString strPath);

	// �����ݿ�swlRule��swlRuleMX���л�ȡ�ֶμ�����
	BOOL LoadDataSet(CString strPath, NDataModelDataSet *& pDataSet);

	CString GetSoftCode()
	{
		return m_strSoftCode;
	}

protected:
	CString m_strSoftCode;//���������� �������
};
