#pragma once
/**
 * @brief  用于标高参数的批量快速获取，仅用于查询，不用于写入
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

	/// 获取:comtype|parmname 与 parmvalue 的匹配
	void GetBG_Base(std::map<CString,CString> & mapsComtypeBG);

	/// 获取:comid|parmname 与 parmvalue 的匹配
	void GetBG_Comid(std::map<CString,CString> & mapsComtypeBG);

private:
	CSqliteDataBase m_Db;	// procject数据库对象
	CSqliteDBStmt m_Stmt;	// 操作数据库的语句对象
};
