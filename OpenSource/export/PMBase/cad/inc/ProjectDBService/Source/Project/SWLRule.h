#pragma once
/**
 * @brief  :实物量计算规则的各种dataset
 *
 *          defvalue 字段表示默认的强制的不可调整的扣减项目
 *				在计算时是要合并到quantity字段。但表示表格grid时不需要
 *			
 * @author :zfy
 * @version:v1.0
 * @date   :[9/26/2017]
 * @note   :
 */
class PMProjectDBSERVICE CSwlFjccDataset : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CSwlFjccDataset)

	CSwlFjccDataset(){};
	virtual ~CSwlFjccDataset(){};

	struct PMProjectDBSERVICE CFieldInfo
	{
		//id
		static const CString id;
		static int	 id_Index;

		static const CString rule_parmid;
		static int	 rule_parmid_Index;

		//comtype
		static const CString comtype;
		static int	 comtype_Index;

		//名称
		static const CString name;
		static int name_Index;

		//变量名称
		static const CString value;
		static int	 value_Index;

		//下拉值
		static const CString listdata;
		static int	 listdata_Index;

		//编辑模式
		static const CString inputmode;
		static int inputmode_Index;

		//正则表达式
		static const CString checkReg;
		static int checkReg_Index;

		//表名
		static const CString table_name;
	};

	struct PMProjectDBSERVICE SectionInfo
	{
		int m_parmid;
		SectionInfo()
		{
			m_parmid = -1;
		}
		
		//增加值，如果存在，则替换值
		void AddValue(CString parmName,CString parmValue);
		//设置值,仅设置已有的附件磁村
		void SetValue(const CStringArray & arrParmName,const CStringArray & arrParmValue);

		//合成附件尺寸
		CString GetSectionInfo() const;
	private:
		CStringArray m_arrParmName;
		CStringArray m_arrParmValue;
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CSwlRuleDataset : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CSwlRuleDataset)

	CSwlRuleDataset(){};
	virtual ~CSwlRuleDataset(){};

	struct PMProjectDBSERVICE CFieldInfo
	{
		//id
		static const CString id;
		static int	 id_Index;

		static const CString parmid;
		static int	 parmid_Index;

		//comtype
		static const CString comtype;
		static int	 comtype_Index;

		//名称
		static const CString parmname;
		static int parmname_Index;

		//变量名称
		static const CString mid_var_name;
		static int	 mid_var_name_Index;

		//变量值
		static const CString mid_var_value;
		static int	 mid_var_value_Index;

		//output
		static const CString output;
		static int	 output_Index;

		//排序字段，仅用于同parmid 内部的行的排序
		static const CString sortid;
		static int	 sortid_Index;

		//表名
		static const CString table_name;
	};

	virtual int InitFieldStr();

	//拷贝行，如果id重复，则替换，不重复，则新增.返回id值，如果id为 -1 说明没有复制成功
	int CopyRowFrom(CSwlRuleDataset * pDatasetArg,int rowArg);
};

class PMProjectDBSERVICE CSwlRuleMXDataset : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CSwlRuleMXDataset)

	CSwlRuleMXDataset(){};
	virtual ~CSwlRuleMXDataset(){};

	struct PMProjectDBSERVICE CFieldInfo
	{
		//id
		static const CString parmid;
		static int	 parmid_Index;

		static const CString rule_parmid;
		static int	 rule_parmid_Index;

		//comtype
		static const CString comtype;
		static int	 comtype_Index;

		//类型
		static const CString type;
		static int	 type_Index;

		//单位
		static const CString unit;
		static int unit_Index;

		//计算项目/扣减项目/增加项目
		static const CString value;
		static int value_Index;

		//描述
		static const CString desc;
		static int desc_Index;

		//扣自相交或者扣自身等的一些特殊扣减项目
		static const CString defvalue;
		static int defvalue_Index;

		//表名
		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CSwlRuleMX_UserDefDataset : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CSwlRuleMX_UserDefDataset)

	CSwlRuleMX_UserDefDataset();
	virtual ~CSwlRuleMX_UserDefDataset();

	struct PMProjectDBSERVICE CFieldInfo
	{
		//id
		static const CString id;
		//static const int	 id_Index;

		//parmid
		static const CString parmid;
		//static const int	 parmid_Index;

		//parmid
		static const CString parmsortid;
		//static const int	 parmsortid_Index;

		//名称
		static const CString dename;
		//static const int dename_Index;

		//单位
		static const CString unit;
		//static const int unit_Index;

		//计算项目/扣减项目/增加项目
		static const CString quantity;
		//static const int quantity_Index;

		//附件尺寸
		static const CString sections;
		//static const int sections_Index;

		//计算公式
		static const CString formulas;
		//static const int formulas_Index;

		//编辑模式
		static const CString editmode;
		//static const int editmode_Index;

		//是否输出
		static const CString output;
		//static const int output_Index;		

		//表名
		static const CString table_name;
		static const CString table_name_PrivateSWL;
	};

	virtual int InitFieldStr();
	int	InitFieldStrV2( NDataModelDataSet * pDataSet );
};

class PMProjectDBSERVICE CPrivateSWL_UserDefDataset : public CSwlRuleMX_UserDefDataset
{
public:
	DECLARE_DYNCREATE(CPrivateSWL_UserDefDataset)

	CPrivateSWL_UserDefDataset();
	virtual ~CPrivateSWL_UserDefDataset();

	//
	static const CString field_entityid;
	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessPrivateSWL_UserDef : public CPMSLAccessTable
{
public:
	CAccessPrivateSWL_UserDef();
	CAccessPrivateSWL_UserDef(BOOL bExtern);
	virtual ~CAccessPrivateSWL_UserDef();
	virtual BOOL TryUpdateTableField()
	{
		return TRUE ;
	}
	//
	/// 获取私有属性的 swlRuleMX_UserDef_handle 的 dataset
	CPrivateSWL_UserDefDataset * GetDataSet_SWLRuleMX_UserDef_Handle(const CStringArray & listId) const;

	/// 删除entityid 在 listId 中的数据
	void  DeleteSWLRuleMX_UserDef_Handle(const CStringArray & listId,BOOL bClearUnLegal) const;
};

class PMProjectDBSERVICE CSWLRule : public CPMSLAccessTable
{
public:
	CSWLRule(void);
	~CSWLRule(void);

	typedef struct  
	{
		CString m_strParmId;
		CString m_strName;
		CString m_strUnit;
		CString m_strQuantity;
		CString m_strSections;
		CString m_strFormula;
		CString m_strExport;
		CString m_strEditmode;
	}SWLJSRULES;

public:
	/// 获取 CProject_SwlRule_ForCal 
	BOOL LoadDataSet(CProject_SwlRule_ForCal *& pDataSet);	

	//获取表格显示用dataset
	CProject_SwlRule_ForCal * GetDataSetForGrid();
	CProject_SwlRule_ForCal * GetDataSetForGrid(int comtype);

	//获取计算用的dataset
	CProject_SwlRule_ForCal * GetDataSetForCal();
	CProject_SwlRule_ForCal * GetDataSetForCal(int comtype);

	//获取全部默认的dataset
	CProject_SwlRule_ForCal * GetDataSetForAllDefault();

	/**
	* @brief   获取部分默认的dataset,arrComtype为默认，其他未非默认
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [10/24/2017]
	*/
	CProject_SwlRule_ForCal * GetDataSetForDefault(const PmArray<int> & arrComtype,BOOL bGetAllComtype);

	/// 获取swlFjcc 的 dataset
	CSwlFjccDataset * GetDataSet_Fjcc() const;

	/// 获取swlRule 的 dataset
	CSwlRuleDataset * GetDataSet_SWLRule() const;

	/// 获取swlRuleMX 的 dataset
	CSwlRuleMXDataset * GetDataSet_SWLRuleMX() const;

	/// 获取swlRuleMX_UserDef 的 dataset
	CSwlRuleMX_UserDefDataset * GetDataSet_SWLRuleMX_UserDef() const;
	CSwlRuleMX_UserDefDataset * GetDataSet_SWLRuleMX_UserDef(int comtype) const;
	BOOL GetDataSet_UserDef(int comtype,CSwlRuleMX_UserDefDataset * pDataSet_UserDef) const;

	/************************************************************************/
	/* 表swlRuleMX_UserDef_handle的操作
	*/
	/************************************************************************/
	/// 把SWLRuleMX_UserDef 内容转为 CPrivateSWL_UserDefDataset的内容并返回
	CPrivateSWL_UserDefDataset * GetDataSet_SWLRuleMX_UserDefAsHandle(int comtype) const;


	/**
	* @brief   读取用户的实物量ini文件(SwljsRules.ini)到我们新的SWLRuleMX_UserDef表中
	*
	*			升级用
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [12/28/2017]
	*/
	BOOL WriteUserIniToUserDef();

	/**
	* @brief   从配置文件读取默认信息
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [1/11/2018]
	*/
	static CString GetSwlRuleInfo(int iComType,int iItemID);

	/**
	* @brief   获取实物量信息------实物量维护时的扣减项目对话框用
	*
	*			用按兼容清单定额的dataset的方式(CDE_SWL_Com)返回的结果
	* @note  : 
	* @param : ruleParmId 要求为 swlRule 表的 parmid
	* @param : pJSGZDataSet 要求为 CDE_SWL_Com 格式
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [1/11/2018]
	*/
	BOOL GetSWLInfoForKJXM(int ruleParmId,CString quantity,NDataModelDataSet * pJSGZDataSet) const;

	// 实物量的自定义部分的附件尺寸升级
	void UpgradeFjcc_UserDef();

	//使用pDatasetUserDef 的 私有数据替换  pDataSet 中的默认数据或者新增pDatasetUserDef数据
	void ApplyUserDefTo(CProject_SwlRule_ForCal * pDataSetDes,CSwlRuleMX_UserDefDataset * pDatasetUserDef,BOOL bNeedAppendDefValue);

private:
	/// 初始化基本排序信息
	void InitParmidToSortid(CSwlRuleDataset * pDataSetSWLRule);

	//
	BOOL LoadDataSet(CSwlFjccDataset * pDataSetFjcc
		,CSwlRuleDataset * pDataSetSWLRule
		,CSwlRuleMXDataset * pDataSetSWLRuleMX
		,CProject_SwlRule_ForCal *& pDataSet);

	//
	BOOL LoadDataSetDefault(CProject_SwlRule_ForCal *& pDataSet);

	/// 从sysdata数据库获取默认的swlRule表信息
	//CSwlRuleDataset * GetDataSet_SWLRule_Default() const;

	/// 把swlRuleMX_UserDef的内容应用dataset
	void ApplyUserModify(CProject_SwlRule_ForCal * pDataSet,BOOL bNeedAppendDefValue) const;
	void ApplyUserModify(CProject_SwlRule_ForCal * pDataSet,BOOL bNeedAppendDefValue,const PmArray<int> & arrComtypeDeny) const;

	/// 把swlRuleMX_UserDef的内容应用dataset
	void ApplyModify(CSwlRuleMX_UserDefDataset * pDatasetUserDef,CProject_SwlRule_ForCal * pDataSet,BOOL bNeedAppendDefValue,const PmArray<int> & arrComtypeDeny) const;
	void ApplyAdd(CSwlRuleMX_UserDefDataset * pDatasetUserDef,CProject_SwlRule_ForCal * pDataSet,BOOL bNeedAppendDefValue,const PmArray<int> & arrComtypeDeny) const;

	/// parmid 是否存在于ini 文件中
	BOOL IsParmIdExistInIniFile(CString strComtype,CString strParmid) const;

	//把quantity字段添加上 defValue 默认扣减项
	CString AppendDefValue(CString sQuantiy,CString sDefValue) const;

	/// 是否quantiy生成时是否合并defvalue字段
	void SetCombineDefValue(BOOL bCombineDefValue);

	/// 获取实物量的计算用 .ini 文件 路径
	static CString GetSWLRulePath();

	//获取实物量附件尺寸
	CString GetFjcc(CSwlFjccDataset * pDataset,CString parmid) const;
	void BuildFjcc(CSwlFjccDataset * pDataset);

	/// 获取实物量计算规则与扣减增加项目
	CString GetQuantiy(CSwlRuleMXDataset * pDataset,CString parmid,CString & sUnit,CString & sDefValue_KJXM) const;
	void BuildQuantiy(CSwlRuleMXDataset * pDataset);

	/// 替换comtype对应的记录
	void ReplaceComtype(CSwlRuleDataset * pDataSetSWLRule
		,CSwlRuleDataset * pDataSetSWLRuleDefault
		,const PmArray<int> & arrComtypeDefault) const;

	/// 寻找实物量计算规则表的行号---通过id查询
	static int FindSWLRuleRow(NDataModelDataSet * pDataSet,int id);
	/// 寻找实物量计算规则表的行号---通过parmid查询
	static int FindSWLRuleRow_Parm(NDataModelDataSet * pDataSet,int parmid);

	virtual BOOL TryUpdateTableField()
	{
		return TRUE ;
	}

	//dataset 数据转换
	void CopyUserDefToSWL(CSwlRuleMX_UserDefDataset * pSrc,CSwlRuleMX_UserDefDataset * pDes) const;

private:
	const int kSortBase;
	NDataModelDataSet * m_pDatasetDefaultForGrid;

	//
	CConnect_sqlite * m_pSysdataBaseCtrl;//是读写sysdata数据库的控制 指针

	//
	PmFile::CIniFileEx m_iniFile;

	//quantiy生成时是否合并defvalue字段
	BOOL m_bCombineDefValue;

	//
	CMapA2BArray<int,CString> m_mapParmidToFjcc;
	CMapA2BArray<int,CString> m_mapParmidToQuantiy;
	CMapA2BArray<int,CString> m_mapParmidToUnit;
	CMapA2BArray<int,CString> m_mapParmidToDefValue;
	CMapA2BArray<int,int> m_mapParmidToSortid;
};