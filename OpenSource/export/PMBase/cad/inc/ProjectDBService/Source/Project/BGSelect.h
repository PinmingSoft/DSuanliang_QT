#pragma once
/**
 * @brief  ���ڱ�߲������������ٻ�ȡ�������ڲ�ѯ��������д��
 *			
 *        
 * @author zfy
 * @version v1.0
 * @date  [5/14/2019]
 * @note  
 */
class PMProjectDBSERVICE CBGSelect
{
public:
	CBGSelect(void);
	~CBGSelect(void);

	/// ��ȡ:comtype|parmname �� parmvalue ��ƥ��
	void GetBG_Base(std::map<CString,CString> & mapsComtypeBG);

	/// ��ȡ:comid|parmname �� parmvalue ��ƥ��
	void GetBG_Comid(std::map<CString,CString> & mapsComtypeBG);

private:
	CSqliteDataBase m_Db;	// procject���ݿ����
	CSqliteDBStmt m_Stmt;	// �������ݿ��������
};
