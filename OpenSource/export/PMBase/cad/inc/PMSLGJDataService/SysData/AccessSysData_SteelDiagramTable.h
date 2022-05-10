

#pragma  once 



#include "AccessSysDataTable.h"

/**
 * @brief 
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-4]
 * @note  
 */
class PmSLGJDataServiceAPI CSysSteelDiagramTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysSteelDiagramTable)

	CSysSteelDiagramTable();
	~CSysSteelDiagramTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString libid;
		static const CString formula ;
		static const CString defaultHeight ;
		static const CString diagram ;
		static const CString ScriptFormula;

		static int id_Idx ;
		static int libid_Idx ;
		static int formula_Idx ;
		static int defaultHeight_Idx ;
		static int diagram_Idx ;
		static int ScriptFormula_Idx ;

		/// idx 递增的辅助变量
		/// idx 需要在函数 InitFieldStr 外 ，初始化为有意义的值
		/// 且赋值的顺序应该和 InitFieldStr中添加的顺序一样
		static int idx_step ; 
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};
};


class PmSLGJDataServiceAPI CAccessSysData_SteelDiagramTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_SteelDiagramTable(void);
	virtual ~CAccessSysData_SteelDiagramTable(void);

	/**
	* @brief   尝试 升级表结构
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/6/2012]
	*/
	virtual BOOL TryUpdateTableField();

	/**
	* @brief   获取版本号
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-7-3]
	*/
	static	int	GetCurVersion() ;

	/**
	* @brief   获取整表的数据，不推荐使用，
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-7-12]
	*/
	NDataModelDataSet * GetDataSet() ; 

	NDataModelDataSet * GetEmptyDataSet() ; 

	/**
	* @brief   获取指定VectorID的 图信息，
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: wjy
	* @date  : [2012-7-12]
	*/
	BOOL GetSteeldiagram(int id, LPVOID & pbuff, long &buffSize) ;

	/**
	* @brief   获取指定VectorID的 图信息，
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: wjy
	* @date  : [2012-7-12]
	*/
	BOOL GetDataSet_VectorID(int iVectorID,CSQLDataSet *& pSQLDataSet);

	/**
	* @brief 获取 指定 id的 记录集 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [16/7/2012]
	*/
	BOOL GetTablcCtrl_Id(int id,CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL SetSteeldiagram(int id, LPVOID pbuff, long buffSize) ;

	int GetLibid( const int id ) ; 

	BOOL IsGj( const CString & strth ) ;

	/**
	* @brief  获取 钢筋 公式 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [16/7/2012]
	*/
	CString GetFormula(int id);

	/**
	* @brief  通过 ScriptFormula 获取 对应的 图ID
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [16/7/2012]
	*/
	BOOL GetID_ScriptFormula(const CString & strScriptFormula,int & iID);

	/**
	* @brief  获取 钢筋 脚本公式 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [16/7/2012]
	*/
	CString GetScriptFormula(int id);

	/**
	* @brief  获取 钢筋 子类型 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [16/7/2012]
	*/
	NDataModelDataSet* GetSteeldiagramDataSet(int libID);

	/**
	* @brief  获取钢筋图 区域，记录 
	*
	*          
	* @note  :int iMinID 是等于最小值 ,int iMaxID  是等于最大值 ，
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/7/2012]
	*/
	NDataModelDataSet * GetSteelDiagramDataSet_Range(int iMinID,int iMaxID);

	/**
	* @brief  获取钢筋图 区域，记录 队列
	*
	*          
	* @note  :
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/7/2012]
	*/
	NDataModelDataSet * GetSteelDiagramDataSet_Arr(CUIntArray & iIDArr);

	/**
	* @brief   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/7/2012]
	*/
	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief 获取图号合成计算公式 对应  的图号
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/9/2012]
	*/
	BOOL GetTableCtrl_ScriptFormula(const CString & strScriptFormula,CPMSQLTableCtrl *& pSQLTableCtrl);

	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;


public:
	//固定的SQL 集合
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		static const int m_iSelectDiagram_id_Sql;
		static const PMTSTRING m_strSelectDiagram_id_Sql;

		static const int m_iSelectAllInfo_id_Sql;
		static const PMTSTRING m_strSelectAllInfo_id_Sql;

		//select * from steeldiagram where id >= 123 and id <= 300
		static const int		m_iSelectAllInfo_idRange;
		static const PMTSTRING	m_strSelectAllInfo_idRange;

		//select * from steedldiagrm where scriptformula=?
		static const int		m_iSelectAllInfo_ScriptFormula;
		static const PMTSTRING	m_strSelectAllInfo_ScriptFormula;
	} ;
};
