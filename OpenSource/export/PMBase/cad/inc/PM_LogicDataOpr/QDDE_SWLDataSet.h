#pragma once

//CSwl_SysDefRuleXML
class PMLogicDataOprAPI CSwl_SysDefRuleXML
{
public:
	CSwl_SysDefRuleXML(void);
	~CSwl_SysDefRuleXML(void);

	NDataModelDataSet * m_pAllDataSetSWL; // 记录对应Swl_SysDefRule.xml文件所有的字段值

	// 读取对应xml数据集的所有字段值
	BOOL LoadXML(CString sXMLName);

	// 用来保存从数据库中读取的数据集
	// 	NDataModelDataSet * m_pDataSetSWL;

	CString GetSoftCode()
	{
		return m_strSoftCode;
	}
protected:
	CString m_strSoftCode;//保存计算规则 软件编码
};
