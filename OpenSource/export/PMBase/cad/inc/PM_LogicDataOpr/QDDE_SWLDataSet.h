#pragma once

//CSwl_SysDefRuleXML
class PMLogicDataOprAPI CSwl_SysDefRuleXML
{
public:
	CSwl_SysDefRuleXML(void);
	~CSwl_SysDefRuleXML(void);

	NDataModelDataSet * m_pAllDataSetSWL; // ��¼��ӦSwl_SysDefRule.xml�ļ����е��ֶ�ֵ

	// ��ȡ��Ӧxml���ݼ��������ֶ�ֵ
	BOOL LoadXML(CString sXMLName);

	// ������������ݿ��ж�ȡ�����ݼ�
	// 	NDataModelDataSet * m_pDataSetSWL;

	CString GetSoftCode()
	{
		return m_strSoftCode;
	}
protected:
	CString m_strSoftCode;//���������� �������
};
