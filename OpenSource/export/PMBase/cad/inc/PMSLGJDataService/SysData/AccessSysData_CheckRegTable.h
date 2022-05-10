#pragma once
#include "AccessSysDataTable.h "

/**
 * @brief 构件参数总表
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CSysCheckRegTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysCheckRegTable)

	CSysCheckRegTable();
	virtual ~CSysCheckRegTable();

	

public:

	virtual int InitFieldStr();

public:

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString checkreg_name;
		static const CString type;
		static const CString checkreg_info;
		static const CString info;

		static int id_Idx ;
		static int checkreg_name_Idx ;
		static int type_Idx ;
		static int checkreg_info_Idx ;
		static int info_Idx ;

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

class PmSLGJDataServiceAPI CAccessSysData_CheckRegTable :
	public CAccessSysDataTable
{
public:
	CAccessSysData_CheckRegTable(void);
	virtual ~CAccessSysData_CheckRegTable(void);

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
	* @brief 通过正则表达式 索引，获取正则表达式  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [28/6/2012]
	*/
	BOOL GetRegInfo(const CString & strRegName,CString & strRegInfo);

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// 添加支持已经存在的接口
	/// 

	/******************************************************************** 
	功能描述：用于在使用正则表达式索引名称，得到正则表达式
	参数：strName：正则表达式索引名称， strCheckRegInfo:正则表达式
	返 回 值：是否查找成功
	算法：
	注意事项：
	作    者：王建业
	时    间：[28/11/2007]
	*********************************************************************/ 
	BOOL GetCheckRegInfo( const CString & strName,CString & strCheckRegInfo);

	/******************************************************************** 
	功能描述：根据索引名称获取正则表达式
	参数：
	返 回 值：
	算法：
	注意事项：
	作    者：杨兴耀
	时    间：[2009年5月27日]
	*********************************************************************/ 
	CString GetRegValue( const CString & strIndex ) ;


protected:
	
	/// 判断是否是钢筋的正则表达式
	/// gjReg 为正则表达式
	/// 约定 正则表达式中包含 [A-G] 或 [A-E] 就认为是钢筋的正则表达式
	BOOL	IsSteel( const CString & gjReg ) ; 

	/// 处理11G钢筋的正则表达式
	void	ReplaceJb(  CString & strValue ) ;

	/// 返回正则表达式
	CString  GetCheckValue( const CString &strName ) ; 

	/// 处理|
	PmTString	DealRegInfoXS( const CString & strName ) ; 

	/// 处理斜杠
	PmTString	DealRegInfoXG( const CString & strName ) ; 

	/// 处理加号
	PmTString	DealRegInfoAdd( const CString & strName ) ; 

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

public:
	static PMTSTRING	GetSql( const int iType ) ;

	//固定的SQL 集合
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetRegSql ;
		static PMTSTRING m_strGetRegInfoSql ;
	};

public:

	/// 私有的常量
	struct PmSLGJDataServiceAPI constdata  
	{
		static const CString Begin ;			/// 开始
		static const CString Add ;				/// +号 
		static const CString AddConst ;			/// 替换加号的内容
		static const CString XG ;				/// 斜杠 (/)
		static const CString XGConst ;			/// 替换斜杠的常量
		static const CString Left ;				/// 左边的括号
		static const CString Right ;			/// 右边的括号

		static const CString BF	;				/// 新添加的钢筋级别
		static const CString BFConst ;			/// 用H替换BF 11G
		static const CString B ;				/// 用B提换BF	03G

		static const CString CF ;				/// 新添加的钢筋级别
		static const CString CFConst ;			/// 用I替换CF 
		static const CString C ;				/// 用C 替换CF 03G

		static const CString EF ;				/// 新添加的钢筋级别
		static const CString EFConst ;			/// 用J替换EF 11G
		static const CString E ;				/// 用E 替换 EF 03G 。 

		static const CString BE ;				/// 新添加的级别
		static const CString BEConst ;			/// 用 K 替换BE

		static const CString CE ;				/// 新添加的级别
		static const CString CEConst ;			/// 用 L 替换CE	

		static const CString EE ;				/// 新添加的级别
		static const CString EEConst ;			/// 用 M 替换EE	

		static const CString BFE ;				/// 新添加的级别
		static const CString BFEConst ;			/// 用 N 替换BEF

		static const CString CFE ;				/// 新添加的级别
		static const CString CFEConst ;			/// 用 O 替换CFE

		static const CString EFE ;				/// 新添加的级别
		static const CString EFEConst ;			/// 用 P 替换EFE

		static const CString JB ;				/// 钢筋级别
		static const CString JB1 ;				/// 钢筋级别
		static const CString JBConst ;			/// 11 G 时 钢筋级别[A-G] 替换[A-J]
		//static const CString JBConst2 ;			/// 11 G 时 钢筋级别[A-G] 替换[A-J]

		static const CString YaoJinReg ;		/// 腰筋的构造筋取级别和直径时用到
		static const CString GjReg;			/// 钢筋取级别和直径时用到

	};
};
