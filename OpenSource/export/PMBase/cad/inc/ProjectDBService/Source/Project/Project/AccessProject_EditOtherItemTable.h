#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_EditOtherItemTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_EditOtherItemTable)

	CProject_EditOtherItemTable();
	virtual ~CProject_EditOtherItemTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;							//序号
		static const CString indexs;						//该表中用不到,editohteritem 表中用来显示排序
		static const CString floorid;						//构件所属楼层编号
		static const CString floorshowid;					//楼层的排序id
		static const CString calitemid;					//定额的时候存放 计算项目ID,清单的时候存放空
		static const CString calitemname;					//定额的时候存放 计算项目名称,清单的时候存放 "清单" 两个字
		static const CString calitemnamelistdata;			//计算项目的下拉裂表
		static const CString rationrow;					//定额的排序ID(定额的时候,存定额的ID,清单的时候存0)
		static const CString decode;						//定额的时候存放定额编码 ,清单的时候存放清单ID .
		static const CString dename;						//定额的时候存放定额名称 ,清单的时候存放清单名称.
		static const CString unit;						//单位
		static const CString unitlistdata;				//单位的下拉列表值
		static const CString quantity;					//计算量
		static const CString transformula;				//工程量计算公式(用于显示)
		static const CString positions;					//在平面图中的位置
		static const CString qdid;						//在定额时填入清单ID,清单的时候为空
		static const CString qdname;						//清单名称
		static const CString qdcode;						//清单编码
		static const CString qdunit;						//清单单位
		static const CString qdunitlistdata;				//清单单位的下拉列表
		static const CString mainmode;					//主体模式 是清单还是定额(1清单,0定额)
		static const CString mainmodelistdata;			//主体模式的下拉列表
		static const CString itemcharacter;				//项目特征
		static const CString variable;					//变量

		static const CString table_name;					//表名
	};

	virtual int InitFieldStr();
};


class PMProjectDBSERVICE CAccessProject_EditOtherItemTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_EditOtherItemTable(void);
public:
	virtual ~CAccessProject_EditOtherItemTable(void);

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

	/// 
	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	/**
	* @brief  获取空的 Dataset，但是有 执行sql的能力
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	CSQLDataSet * GetEmptyDataSet();

	/**
	* @brief 获取ID的 最大值  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	BOOL GetMaxID(int & iMaxID);

	//删除 所有记录
	BOOL DeleteAllRow();

	/// 
	BOOL	DeleteFloor( const int iFloorId ) ;

	/**
	* @brief   获取记录集
	*
	*          
	* @note  : 
	* @param : strCalItemNames 为 1,2,3 的格式，不能为空
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-8-15]
	*/
	BOOL	GetTableCtrl( const int iFloorId , const CString & strCalItemNames , CPMSQLTableCtrl *& pSqliteTableCtrl ) ;

	/**
	* @brief   获取记录集，提供给报表使用
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-8-16]
	*/
	BOOL	GetTableCtrl( const CString & strFloorIds , CPMSQLTableCtrl *& pSqliteTableCtrl , const BOOL bQd = TRUE ) ;

	/// 
	BOOL	GetTableCtrlQdde( const CString & strFloorIds , CPMSQLTableCtrl *& pSqliteTableCtrl ) ;


	/// 去除找不到楼层的脏数据
	void	RemoveDirtyData() ; 

public:
	
	static PMTSTRING	GetSql( const int iType ) ;

public:
	struct SQLInfo
	{
		/// 
		static const int			m_iGetTableCtrl ;
		static const PMTSTRING		m_strGetTableCtrl ; 

		/// 
		static const int			m_iGetTableCtrl_ForReport ;
		static const PMTSTRING		m_strGetTableCtrl_ForReport ; 

		/// 
		static const int			m_iGetTableCtrl_ForReport1 ;
		static const PMTSTRING		m_strGetTableCtrl_ForReport1 ; 
	} ;
};




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 清单定额定制 表也放在该文件定义 
class PMProjectDBSERVICE CProject_QddeCustomizeTable : public CSQLDataSet
{
public:
	CProject_QddeCustomizeTable() ; 
	virtual	~CProject_QddeCustomizeTable() ; 

public:
	virtual int InitFieldStr() ; 

public:
	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString qdde_index ;	/// 显示的序号 1 / 1.1  1.2
		static const CString qdde_id ;		/// 内部的逻辑id
		static const CString qdde_parent ;  /// 清单，定额时为对应的清单 - 12 位 
		static const CString qdde_node ;	/// 清单 定额 都需要保存  --- 9位
		static const CString qdde_level ;	/// 等级关系 {1,2,2,1,2,2} ,控制树的结构
		static const CString qdde_code ; 
		static const CString qdde_attr ;	/// 项目特征
		static const CString qdde_att_content ; ///  项目特征的内容
		static const CString qdde_name ; 
		static const CString qdde_unit ;

		static const CString qdde_add ; /// 标记是否是新增的，0 或者空 为 导入的， 1 为新增的 

		

		static const CString table_name ; 

		/// 
		/// 清单库和定额库对应的id
		static	const CString m_strQdId ;
		static	const CString m_strDeId ;
	};

};

class PMProjectDBSERVICE CAccessProject_QddeCustomizeTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_QddeCustomizeTable(void);
public:
	virtual ~CAccessProject_QddeCustomizeTable(void);

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

	/// 
	CSQLDataSet * GetDataSet();
	
	/**
	* @brief  获取空的 Dataset，但是有 执行sql的能力
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	CSQLDataSet * GetEmptyDataSet();

	/**
	* @brief 获取ID的 最大值  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	BOOL GetMaxID(int & iMaxID);

	//删除 所有记录
	BOOL DeleteAllRow();

	CSQLDataSet * GetDataSet( const CString & strBaseQdId ) ;

	/// 查找是否有 nodeid
	BOOL	HasNodeId( const CString & strBaseNodeId ) ; 

	/// 
	/// 判断清单id 是否是新增的
	/// 
	BOOL	IsAddQdId( const CString & strQdId ) ; 

public:
	CString		GetQdBaseName() ; 
	CString		GetDeBaseName() ; 
public:
	
	static PMTSTRING	GetSql( const int iType ) ;

public:
	struct SQLInfo
	{
	
	} ;

public:
	
};




