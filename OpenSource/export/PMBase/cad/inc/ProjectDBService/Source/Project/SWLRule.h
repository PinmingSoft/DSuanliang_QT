#pragma once
/**
 * @brief  :ʵ�����������ĸ���dataset
 *
 *          defvalue �ֶα�ʾĬ�ϵ�ǿ�ƵĲ��ɵ����Ŀۼ���Ŀ
 *				�ڼ���ʱ��Ҫ�ϲ���quantity�ֶΡ�����ʾ���gridʱ����Ҫ
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

		//����
		static const CString name;
		static int name_Index;

		//��������
		static const CString value;
		static int	 value_Index;

		//����ֵ
		static const CString listdata;
		static int	 listdata_Index;

		//�༭ģʽ
		static const CString inputmode;
		static int inputmode_Index;

		//������ʽ
		static const CString checkReg;
		static int checkReg_Index;

		//����
		static const CString table_name;
	};

	struct PMProjectDBSERVICE SectionInfo
	{
		int m_parmid;
		SectionInfo()
		{
			m_parmid = -1;
		}
		
		//����ֵ��������ڣ����滻ֵ
		void AddValue(CString parmName,CString parmValue);
		//����ֵ,���������еĸ����Ŵ�
		void SetValue(const CStringArray & arrParmName,const CStringArray & arrParmValue);

		//�ϳɸ����ߴ�
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

		//����
		static const CString parmname;
		static int parmname_Index;

		//��������
		static const CString mid_var_name;
		static int	 mid_var_name_Index;

		//����ֵ
		static const CString mid_var_value;
		static int	 mid_var_value_Index;

		//output
		static const CString output;
		static int	 output_Index;

		//�����ֶΣ�������ͬparmid �ڲ����е�����
		static const CString sortid;
		static int	 sortid_Index;

		//����
		static const CString table_name;
	};

	virtual int InitFieldStr();

	//�����У����id�ظ������滻�����ظ���������.����idֵ�����idΪ -1 ˵��û�и��Ƴɹ�
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

		//����
		static const CString type;
		static int	 type_Index;

		//��λ
		static const CString unit;
		static int unit_Index;

		//������Ŀ/�ۼ���Ŀ/������Ŀ
		static const CString value;
		static int value_Index;

		//����
		static const CString desc;
		static int desc_Index;

		//�����ཻ���߿�����ȵ�һЩ����ۼ���Ŀ
		static const CString defvalue;
		static int defvalue_Index;

		//����
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

		//����
		static const CString dename;
		//static const int dename_Index;

		//��λ
		static const CString unit;
		//static const int unit_Index;

		//������Ŀ/�ۼ���Ŀ/������Ŀ
		static const CString quantity;
		//static const int quantity_Index;

		//�����ߴ�
		static const CString sections;
		//static const int sections_Index;

		//���㹫ʽ
		static const CString formulas;
		//static const int formulas_Index;

		//�༭ģʽ
		static const CString editmode;
		//static const int editmode_Index;

		//�Ƿ����
		static const CString output;
		//static const int output_Index;		

		//����
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
	/// ��ȡ˽�����Ե� swlRuleMX_UserDef_handle �� dataset
	CPrivateSWL_UserDefDataset * GetDataSet_SWLRuleMX_UserDef_Handle(const CStringArray & listId) const;

	/// ɾ��entityid �� listId �е�����
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
	/// ��ȡ CProject_SwlRule_ForCal 
	BOOL LoadDataSet(CProject_SwlRule_ForCal *& pDataSet);	

	//��ȡ�����ʾ��dataset
	CProject_SwlRule_ForCal * GetDataSetForGrid();
	CProject_SwlRule_ForCal * GetDataSetForGrid(int comtype);

	//��ȡ�����õ�dataset
	CProject_SwlRule_ForCal * GetDataSetForCal();
	CProject_SwlRule_ForCal * GetDataSetForCal(int comtype);

	//��ȡȫ��Ĭ�ϵ�dataset
	CProject_SwlRule_ForCal * GetDataSetForAllDefault();

	/**
	* @brief   ��ȡ����Ĭ�ϵ�dataset,arrComtypeΪĬ�ϣ�����δ��Ĭ��
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [10/24/2017]
	*/
	CProject_SwlRule_ForCal * GetDataSetForDefault(const PmArray<int> & arrComtype,BOOL bGetAllComtype);

	/// ��ȡswlFjcc �� dataset
	CSwlFjccDataset * GetDataSet_Fjcc() const;

	/// ��ȡswlRule �� dataset
	CSwlRuleDataset * GetDataSet_SWLRule() const;

	/// ��ȡswlRuleMX �� dataset
	CSwlRuleMXDataset * GetDataSet_SWLRuleMX() const;

	/// ��ȡswlRuleMX_UserDef �� dataset
	CSwlRuleMX_UserDefDataset * GetDataSet_SWLRuleMX_UserDef() const;
	CSwlRuleMX_UserDefDataset * GetDataSet_SWLRuleMX_UserDef(int comtype) const;
	BOOL GetDataSet_UserDef(int comtype,CSwlRuleMX_UserDefDataset * pDataSet_UserDef) const;

	/************************************************************************/
	/* ��swlRuleMX_UserDef_handle�Ĳ���
	*/
	/************************************************************************/
	/// ��SWLRuleMX_UserDef ����תΪ CPrivateSWL_UserDefDataset�����ݲ�����
	CPrivateSWL_UserDefDataset * GetDataSet_SWLRuleMX_UserDefAsHandle(int comtype) const;


	/**
	* @brief   ��ȡ�û���ʵ����ini�ļ�(SwljsRules.ini)�������µ�SWLRuleMX_UserDef����
	*
	*			������
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [12/28/2017]
	*/
	BOOL WriteUserIniToUserDef();

	/**
	* @brief   �������ļ���ȡĬ����Ϣ
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
	* @brief   ��ȡʵ������Ϣ------ʵ����ά��ʱ�Ŀۼ���Ŀ�Ի�����
	*
	*			�ð������嵥�����dataset�ķ�ʽ(CDE_SWL_Com)���صĽ��
	* @note  : 
	* @param : ruleParmId Ҫ��Ϊ swlRule ��� parmid
	* @param : pJSGZDataSet Ҫ��Ϊ CDE_SWL_Com ��ʽ
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [1/11/2018]
	*/
	BOOL GetSWLInfoForKJXM(int ruleParmId,CString quantity,NDataModelDataSet * pJSGZDataSet) const;

	// ʵ�������Զ��岿�ֵĸ����ߴ�����
	void UpgradeFjcc_UserDef();

	//ʹ��pDatasetUserDef �� ˽�������滻  pDataSet �е�Ĭ�����ݻ�������pDatasetUserDef����
	void ApplyUserDefTo(CProject_SwlRule_ForCal * pDataSetDes,CSwlRuleMX_UserDefDataset * pDatasetUserDef,BOOL bNeedAppendDefValue);

private:
	/// ��ʼ������������Ϣ
	void InitParmidToSortid(CSwlRuleDataset * pDataSetSWLRule);

	//
	BOOL LoadDataSet(CSwlFjccDataset * pDataSetFjcc
		,CSwlRuleDataset * pDataSetSWLRule
		,CSwlRuleMXDataset * pDataSetSWLRuleMX
		,CProject_SwlRule_ForCal *& pDataSet);

	//
	BOOL LoadDataSetDefault(CProject_SwlRule_ForCal *& pDataSet);

	/// ��sysdata���ݿ��ȡĬ�ϵ�swlRule����Ϣ
	//CSwlRuleDataset * GetDataSet_SWLRule_Default() const;

	/// ��swlRuleMX_UserDef������Ӧ��dataset
	void ApplyUserModify(CProject_SwlRule_ForCal * pDataSet,BOOL bNeedAppendDefValue) const;
	void ApplyUserModify(CProject_SwlRule_ForCal * pDataSet,BOOL bNeedAppendDefValue,const PmArray<int> & arrComtypeDeny) const;

	/// ��swlRuleMX_UserDef������Ӧ��dataset
	void ApplyModify(CSwlRuleMX_UserDefDataset * pDatasetUserDef,CProject_SwlRule_ForCal * pDataSet,BOOL bNeedAppendDefValue,const PmArray<int> & arrComtypeDeny) const;
	void ApplyAdd(CSwlRuleMX_UserDefDataset * pDatasetUserDef,CProject_SwlRule_ForCal * pDataSet,BOOL bNeedAppendDefValue,const PmArray<int> & arrComtypeDeny) const;

	/// parmid �Ƿ������ini �ļ���
	BOOL IsParmIdExistInIniFile(CString strComtype,CString strParmid) const;

	//��quantity�ֶ������ defValue Ĭ�Ͽۼ���
	CString AppendDefValue(CString sQuantiy,CString sDefValue) const;

	/// �Ƿ�quantiy����ʱ�Ƿ�ϲ�defvalue�ֶ�
	void SetCombineDefValue(BOOL bCombineDefValue);

	/// ��ȡʵ�����ļ����� .ini �ļ� ·��
	static CString GetSWLRulePath();

	//��ȡʵ���������ߴ�
	CString GetFjcc(CSwlFjccDataset * pDataset,CString parmid) const;
	void BuildFjcc(CSwlFjccDataset * pDataset);

	/// ��ȡʵ�������������ۼ�������Ŀ
	CString GetQuantiy(CSwlRuleMXDataset * pDataset,CString parmid,CString & sUnit,CString & sDefValue_KJXM) const;
	void BuildQuantiy(CSwlRuleMXDataset * pDataset);

	/// �滻comtype��Ӧ�ļ�¼
	void ReplaceComtype(CSwlRuleDataset * pDataSetSWLRule
		,CSwlRuleDataset * pDataSetSWLRuleDefault
		,const PmArray<int> & arrComtypeDefault) const;

	/// Ѱ��ʵ��������������к�---ͨ��id��ѯ
	static int FindSWLRuleRow(NDataModelDataSet * pDataSet,int id);
	/// Ѱ��ʵ��������������к�---ͨ��parmid��ѯ
	static int FindSWLRuleRow_Parm(NDataModelDataSet * pDataSet,int parmid);

	virtual BOOL TryUpdateTableField()
	{
		return TRUE ;
	}

	//dataset ����ת��
	void CopyUserDefToSWL(CSwlRuleMX_UserDefDataset * pSrc,CSwlRuleMX_UserDefDataset * pDes) const;

private:
	const int kSortBase;
	NDataModelDataSet * m_pDatasetDefaultForGrid;

	//
	CConnect_sqlite * m_pSysdataBaseCtrl;//�Ƕ�дsysdata���ݿ�Ŀ��� ָ��

	//
	PmFile::CIniFileEx m_iniFile;

	//quantiy����ʱ�Ƿ�ϲ�defvalue�ֶ�
	BOOL m_bCombineDefValue;

	//
	CMapA2BArray<int,CString> m_mapParmidToFjcc;
	CMapA2BArray<int,CString> m_mapParmidToQuantiy;
	CMapA2BArray<int,CString> m_mapParmidToUnit;
	CMapA2BArray<int,CString> m_mapParmidToDefValue;
	CMapA2BArray<int,int> m_mapParmidToSortid;
};