#pragma once
//#include "..\accesstable.h"

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 清单定额定制 表也放在该文件定义 
class PMProjectDBSERVICE CProject_QD_WBTable : public CSQLDataSet
{
public:
	CProject_QD_WBTable() ; 
	virtual	~CProject_QD_WBTable() ; 

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

class PMProjectDBSERVICE CAccessProject_QD_WBTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_QD_WBTable(void);
public:
	virtual ~CAccessProject_QD_WBTable(void);

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




