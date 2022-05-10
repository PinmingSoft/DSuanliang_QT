


#pragma once 


//#include "..\accesstable.h"

typedef std::set<int> CPmIntSet ; 
typedef CPmIntSet::iterator	CPmIntSetIter ;
typedef CPmIntSet::const_iterator CPmIntSetConIter ; 

/**
 * @brief 构件的参数设置值
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2013-5-20]
 * @note  
 */
class PMProjectDBSERVICE CProject_ComParmsSet_ComIdTable : public CSQLDataSet
{
	DECLARE_DYNCREATE(CProject_ComParmsSet_ComIdTable)

	CProject_ComParmsSet_ComIdTable();
	virtual ~CProject_ComParmsSet_ComIdTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString	parmid;
		static int				parmid_Index;

		static const CString	comid;
		static int				comid_Index;

		static const CString	subcomtype;
		static int				subcomtype_Index;
		
		static const CString	parmname;
		static int				parmname_Index;

		static const CString	parmvalue;
		static int				parmvalue_Index;

		static const CString	invalidmsg;
		static int				invalidmsg_Index;

	};

	struct PMProjectDBSERVICE CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

//具体构件参数 数据库表
class PMProjectDBSERVICE CAccessProject_ComParmsSet_ComIdTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_ComParmsSet_ComIdTable(void);
	CAccessProject_ComParmsSet_ComIdTable(BOOL bTemplateDb);
	virtual ~CAccessProject_ComParmsSet_ComIdTable(void);

public:

	/**
	* @brief   尝试 升级表结构
	*/
	virtual BOOL TryUpdateTableField();


	/// 
	CSQLDataSet * GetDataSet();

	/**
	* @brief  获取空的 Dataset，但是有 执行sql的能力
	* @date  : [13/7/2012]
	*/
	CSQLDataSet * GetEmptyDataSet();

	/// 检测表是否合理，通常这个表内的记录不可能为0，所以，如果为0，则是有问题的
	static BOOL	CheckTable(CString &sErrorInfo);

	/// 
	void	GetComId( const int iComType , const int iSubComType ,const CString & strParmName , CPmIntSet & setComId ) ;

	/// 
	void	UpdateParmValue( const CString & strParmName , const CString & strParmValue , const CUIntArray & aryComId ) ;

	void	UpdateParmValue(const CString& strParmName,const CString& strParmValue);
	
	// 更新钢筋根数规则
	void UpDateGJGSRule(const CString & strParmValue,const CUIntArray & aryComId);
	/// 
	void	DeleteGlobalParmName( const CString & strParmName , const CUIntArray & aryComId ) ;

	/// 
	void	InsertGlobalParmName( const CString & strParmName , const CString & strParmValue , const CUIntArray & aryComId  ) ;
	
	
	/// 
	/// 更新计算设置的搭接形式
	/// 
	/// 
	void	GetJsszDjxsParm( const CString & strParmName , const CString & strParmValue , const CUIntArray & aryComId ) ;


	/// 获取comid对应的所有的构件
	BOOL	GetTableCtrl( const int iComId , CPMSQLTableCtrl *& pSqlTableCtrl ) ;

	/// 
	void	Delete() ; 

	void	DeleteJssz( const CUIntArray & aryComId ) ; 

	/// 
	void	Delete( const int iComId ) ;
	void	Delete( const CString strParmName , const CUIntArray & aryComId ) ;

	/// 拷贝参数,要求已把原有参数删除
	void	CopyParm(int comidFrom,int comidTo);

public:
	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		///delete from comparmsset_comid
		static const int m_iDelete ;
		static PMTSTRING m_strDelete ;

		/// delete from ComParmsSet_Handle
		static const int	m_iDeleteComId ;
		static PmTString	m_strDeleteComId ;
	};
};