#pragma once

#include "AccessProject_ComponentsTable.h"



class PMProjectDBSERVICE CProject_ComponentsDelTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ComponentsDelTable)

	CProject_ComponentsDelTable();
	virtual ~CProject_ComponentsDelTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					
		static const CString comname;					
		static const CString floorid;				
		static const CString comtype;				
		static const CString volume;					//此构件的数量
		static const CString comparms;				//构件属性
		static const CString qddedata;					//清单数据
		static const CString vectorparms;				//配筋图参数
		static const CString showid;				
		static const CString bz;						//描述
		static const CString editmode;				//是否修改

		static const CString table_name;				//表名
	};

	virtual BOOL GetCreateIndexSQL(CStringArray & strFieldNameArr,CString & strIndexName);

	virtual int InitFieldStr();
};


class PMProjectDBSERVICE CAccessProject_ComponentsDelTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_ComponentsDelTable(void);
public:
	virtual ~CAccessProject_ComponentsDelTable(void);
	BOOL TryUpdateTableField();

	/**
	* @brief 复制components中的comid记录到componentsdel中，isExit表示componentsdel中是否存在此comid
	*
	*        
	* @author hn
	* @version v1.0
	* @date  10/8/2016
	* @note  
	*/
	BOOL SetDataSet_ComID( int iComID,CSQLDataSet *& pComponentDataSet, BOOL &isExsit );
	//固定的SQL 集合
	struct PMProjectDBSERVICE SQLInfo
	{
		static const int		m_iInsertInfo_SQL;
		static const PmTString m_strInsertInfo_SQL;//插入记录；

		static const int		m_iDeleteInfo_ComID;
		static const PmTString	m_strDeleteInfo_ComID;// 删除记录

		static const int		m_iUpdateVectorParmBuffer_SQL;
		static const PmTString m_strUpdateVectorParmBuffer_SQL;//设置VectorParm Buffer的Sql

		static const int		m_iSelectVectorParmBuffer_SQL;
		static const PmTString m_strSelectVectorParmBuffer_SQL;//获取 vectorparm buffer的sql；
	};

	/**
	* @brief SQL语句
	*
	*        
	* @author hn
	* @version v1.0
	* @date  9/29/2016
	* @note  
	*/
	static PmTString GetSQL(const int iSQLIndex);
	/**
	* @brief 获取最大COMID
	*
	*        
	* @author hn
	* @version v1.0
	* @date  9/29/2016
	* @note  
	*/
	BOOL GetTable_MaxID(int & iMaxID);
	/**
	* @brief 获取comid对应的信息，找不到comid时返回FALSE
	*
	*        
	* @author hn
	* @version v1.0
	* @date  10/8/2016
	* @note  
	*/
	BOOL GetDataSet_ComID(int iComID,CSQLDataSet *& pComponentdelDataSet);
	/**
	* @brief copy信息到components表中
	*
	*        
	* @author hn
	* @version v1.0
	* @date  10/8/2016
	* @note  
	*/
	BOOL CopyComponentsdelComIdToComponents(int iComID);
	/**
	* @brief 记录数
	*
	*        
	* @author hn
	* @version v1.0
	* @date  10/8/2016
	* @note  
	*/
	BOOL GetRowCount( int & iRowCount );
	/**
	* @brief 设置截面图信息到componentsdel中
	*
	*        
	* @author hn
	* @version v1.0
	* @date  3/30/2017 
	* @note  
	*/
	BOOL SetVectorParm_Buffer(int iComID,void * pVectorParmBuffer,long lVectorParmBufferSize);
	/**
	* @brief 获取vector数据
	*
	*        
	* @author hn
	* @version v1.0
	* @date  3/30/2017 
	* @note  
	*/
	BOOL GetVectorParmDataSet(int iComID,CProject_VectorParmsTable *& pVectorDataSet);
};