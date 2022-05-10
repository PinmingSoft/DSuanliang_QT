#pragma once

class PMLogicDataOprAPI CQDDE_SWLManager
{
public:
	CQDDE_SWLManager(void);
	~CQDDE_SWLManager(void);

	NDataModelDataSet * m_pDataSetSWL;
	BOOL LoadXML(CString sXMLName,CString strComName);

	// 从数据库中读取到数据集中去
	BOOL LoadDataSet(CString strPath);

	// 从数据库swlRule和swlRuleMX表中获取字段集数据
	BOOL LoadDataSet(CString strPath, NDataModelDataSet *& pDataSet);

	CString GetSoftCode()
	{
		return m_strSoftCode;
	}

protected:
	CString m_strSoftCode;//保存计算规则 软件编码
};
