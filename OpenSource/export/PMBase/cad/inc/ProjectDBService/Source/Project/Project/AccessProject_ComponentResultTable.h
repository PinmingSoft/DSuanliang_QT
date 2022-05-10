#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_ComponentResultTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ComponentResultTable)

	CProject_ComponentResultTable();
	virtual ~CProject_ComponentResultTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					//该表的逻辑id
		static const CString floorid;				//楼层
		static const CString comid;				//构件
		static const CString gjlb;				//钢筋类别
		static const CString gjlx;				//钢筋类型
		static const CString gjjb;				//钢筋级别
		static const CString zj;					//直径
		static const CString gs;					//跟数
		static const CString th;					//图号
		static const CString jt;					//简图
		static const CString jsgs;				//计算公式
		static const CString wg;					//弯勾
		static const CString tqd;					//砼强度
		static const CString dj;					//搭接
		static const CString cd;					//长度
		static const CString jtgs;				//接头个数
		static const CString zz;					//总重
		static const CString gsms;				//公式描述
		static const CString index0;				
		static const CString index1;				
		static const CString index2;				
		static const CString jtparms;				//简图参数
		static const CString sttype;				//钢筋类别 默认0时为计算所得，1时为手工加入
		static const CString jtformula;			//简图计算公式
		static const CString resulttype;			
		static const CString djxs;				
		static const CString errortype;			
		static const CString cc;				
		static const CString ccamount;			

		static const CString table_name;			//钢筋计算结果表
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_ComponentResultTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_ComponentResultTable(void);
	~CAccessProject_ComponentResultTable(void);
	

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

public:

	/// 
	BOOL GetMaxId( int & iMaxId ) ;

	/**
	* @brief   获取 DataSet 
	*
	*          
	* @note  : 现在 这个函数 性能消耗很大
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/6/2012]
	*/
	CSQLDataSet * GetDataSet() ;

	CSQLDataSet * GetDataSet( const int iComId ) ;

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	/// 设置指定构件的计算结果 
	void  SetDataSet( const int iComId , NDataModelDataSet * pResult ) ; 

	BOOL GetRowCount( int & iRowCount ) ;

	/// 
	BOOL GetTableCtrl( 
		const CString & strFloorIds , 
		const CString & strComFolderIds ,
		CPMSQLTableCtrl *& pTableCtrl 
		) ; 

	/// 删除指定构件的 计算结果
	void				DelResult( const int iComId ) ; 


	/// 去除没有构件与之对应的结果
	void				RemoveDirtyData() ; 

private:
	void				InsertDataSet( const int iComId ,NDataModelDataSet * pDataSet ) ;

public:
	static PMTSTRING GetSQL(const int iSQLIndex);

public:

	struct SQLInfo
	{
		static const int		m_iSelectResult_ComID_Sql;
		static const PMTSTRING	m_strSelectResult_ComID_Sql;//获取 指定的 ComID的 记录 sql

		/// 
		static const int		m_iDelResult ;
		static const PMTSTRING	m_strDelResult ; 

		/// 
		static const int		m_iInsertDataSet ;
		static const PMTSTRING	m_strInsertDataSet ; 

		/// 
		static const int		m_iGetTableCtrl ; 
		static const PMTSTRING	m_strGetTableCtrl ; 
	};
};
