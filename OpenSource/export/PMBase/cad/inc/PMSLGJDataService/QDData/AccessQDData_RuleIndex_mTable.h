#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CQDRuleIndex_mTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CQDRuleIndex_mTable)

	CQDRuleIndex_mTable();
	virtual ~CQDRuleIndex_mTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString nodeid;			//清单编号---层次结构 用于树节点的创建
		static const CString qdid;			//清单ID --- 逻辑使用的清单编号 数字/英文字符/中文字符
		static const CString nodename;		//节点名
		static const CString comtype;			//构件种类
		static const CString unit;			//单位
		static const CString csxm;			//措施项目  1:措施项目 0:非措施项目
		static const CString variables;		//变量

		static const CString table_name;
	};

	virtual int InitFieldStr();
};


class PmSLGJDataServiceAPI CAccessQDData_RuleIndex_mTable :
	public CPMSLAccessTable
{
public:
	CAccessQDData_RuleIndex_mTable(void);

	~CAccessQDData_RuleIndex_mTable(void);

public:

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	void	Delete() ; 

	NDataModelDataSet * GetEmptyDataSet() ; 

	BOOL GetTableCtrl_NodeID(const CString & strNodeID,CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetTableCtrl_QDID(const CString & strQDID,CPMSQLTableCtrl *& pSQLTableCtrl);

	CString	GetNodeID( const CString & strQdid ) ;

	BOOL IsIn( CString strNodeID , CString strComType ) ;

	BOOL GetQdInfo( 
		const CString & strNodeID ,
		CString & strQdid , 
		CString & strQdName , 
		CString & strUnit );

	CString GetQdName( const CString & strNodeName ) ;

	/// 在清单维护的时候 ， 根据清单id 去获取可用的变量
	NDataModelDataSet *		GetVariableDataSet( const CString & strNodeID ) ; 

	NDataModelDataSet * GetVariableDataSet( NDataModelDataSet * pGridData , const CString & strNodeID ) ;

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		static const int		m_iSelectInfo_NodeID;
		static const PmTString	m_strSelectInfo_NodeID;

		static const int		m_iSelectInfo_QDID;
		static const PmTString	m_strSelectInfo_QDID;
	};

	/// 自定义清单的 nodeid 
	static const CString			m_strCusNodeID ; 

	/// 补充清单的 第一级 10
	static const CString			m_strAddQdNode1 ;

	/// 第二级 1001 
	static const CString			m_strAddQdNode2 ; 

	/// 第三级 100101
	static const CString			m_strAddQdNode3 ;

	/// 第四级 100101001 --- 分部
	static const CString			m_strAddQdNode4 ;

	/// 第四级 100101002 --- 措施
	static const CString			m_strAddQdNode4_1 ;

	/// 补充清单的章节名称: 补充清单
	static const CString			m_strQddQdNodeName ; 

	/// 补充清单的章节名称: 补充清单 --- 分部
	static const CString			m_strQddQdNodeName4 ;


	/// 补充清单的章节名称: 补充清单 --- 措施
	static const CString			m_strQddQdNodeName4_1 ;

};
