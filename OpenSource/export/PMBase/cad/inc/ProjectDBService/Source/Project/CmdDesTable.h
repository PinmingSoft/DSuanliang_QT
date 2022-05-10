#pragma once

class PMProjectDBSERVICE CCmdDesDataset : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CCmdDesDataset)

	CCmdDesDataset();
	virtual ~CCmdDesDataset(){};

	struct PMProjectDBSERVICE CFieldInfo
	{
		//命令
		static const CString command;

		//详细名称
		static const CString detailname;

		//名称
		static const CString name;

		//回退
		static const CString undo;

		//重复检测模式
		static const CString checkRepeatMode;

		//增量计算
		static const CString zljs;

		//是否品茗构件
		static const CString pmgj;

		//是否需要检测已有构件，没有已有构件不布置
		static const CString checkGJ;

		//表名
		static const CString table_name;
	};

	virtual int InitFieldStr();
	int	InitFieldStrV2( NDataModelDataSet * pDataSet );

	//获取英文名与详细中文名的匹配
	void GetDetailNameMap(std::map<CString, CString> & mapCmdDetailName) const;

	//获取英文名与中文简洁名的匹配
	void GetNameMap(std::map<CString, CString> & mapCmdDes) const;

	//获取英文名与回退状态的匹配
	void GetUndoMap(std::map<CString, int> & mapCmdUndo) const;

	//获取英文名与重复检测状态的匹配
	void GetCheckRepeatModeMap(std::map<CString, int> & mapCmdCheckRepeatMode) const;

	//获取英文名与增量计算的匹配
	void GetCheckZLJSMap(std::map<CString, int> & mapCmdZLJS) const;

	//获取英文名与是否检测的匹配
	void GetCheckGJMap(std::map<CString, int> & mapCmdCheckGJ) const;

	//获取英文名与是否品茗命令的匹配
	void GetPmCommand(std::map<CString, int> & mapCmdPM) const;
};

class PMProjectDBSERVICE CCmdDesTable
{
private:
	static BOOL m_bOwnCmdChange;
public:
	CCmdDesTable(void);
	~CCmdDesTable(void);

	//
	CCmdDesDataset * GetDataSet() const;

	//qc28054 自定义命令是否改变的标记
	static BOOL  GetOwnCmdChange();
	static void  SetOwnCmdChange(BOOL bOwnCmdChange);
};

class PMProjectDBSERVICE CCmdDesTableOpr
{
public:
	static CCmdDesTableOpr * Instance()
	{
		if (NULL == m_pInstance)
		{
			m_pInstance = PMNew(CCmdDesTableOpr);
		}
		return m_pInstance;
	}
	static void Release()
	{
		PMDelete(m_pInstance);
	}

	//
	BOOL IsCmdCheckGJ(CString cmd) const;

	BOOL IsPMCmd(CString cmd) const;

	//获取命令对应的中文描述
	CString GetChCmdName(CString enCmdName) const;

private:
	CCmdDesTableOpr();
	~CCmdDesTableOpr();

	//
	static CCmdDesTableOpr * m_pInstance;
	CCmdDesDataset * m_pDataset;

	//命令是否要检测构件已存在，已存在才可以添加继续执行命令
	std::map<CString,int> m_mapCmdCheckGJ;

	//明林给是否是品茗的命令
	std::map<CString,int> m_mapCmdPM;

	//命令名到命令的中文解释
	std::map<CString,CString> m_mapCmdEn_Ch;
};