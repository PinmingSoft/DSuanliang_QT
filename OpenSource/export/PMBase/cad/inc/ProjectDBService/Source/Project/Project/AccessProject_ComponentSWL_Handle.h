#pragma once

#include <tuple>

class PMProjectDBSERVICE CProject_ComponentSWL_Handle : public CSQLDataSet  
{
public:
	DECLARE_DYNCREATE(CProject_ComponentSWL_Handle)

	CProject_ComponentSWL_Handle(){};
	virtual ~CProject_ComponentSWL_Handle(){};
	virtual int InitFieldStr();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id ;
		static const CString comid ;
		static const CString handle ;

		//表名
		static const CString table_name;
	};
};

class PMProjectDBSERVICE CAccessProject_ComponentSWL_Handle:
	public CPMSLAccessTable
{
public:
	CAccessProject_ComponentSWL_Handle(void);
	CAccessProject_ComponentSWL_Handle(BOOL bExtern);
	virtual ~CAccessProject_ComponentSWL_Handle(void);

	//
	BOOL TryUpdateTableField()
	{
		return TRUE;
	}

	/**
	* @brief 查询 component_swl_handle 表
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [4/3/2019]
	*/
	CSQLDataSet * GetDataSet();
	CSQLDataSet * GetDataSet(int comid,CString handle);

	/**
	* @brief 查询 CPrivateSWL_UserDefDataset 表
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [4/3/2019]
	*/
	CPrivateSWL_UserDefDataset * GetDataSet_UserDef(int comid,CString handle) const;
	CPrivateSWL_UserDefDataset * GetDataSet_UserDef(const CUIntArray& arrComid,const CStringArray& arrHandle) const;

	/**
	* @brief 获取计算用实物量的数据集
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [4/9/2019]
	*/
	CProject_SwlRule_ForCal * GetDataSet_SwlRuleForCal(CProject_SwlRule_ForCal * pDatasetForCalDefault
													,int comid
													,int comtype
													,CString handle) const;

	/// map非空，且tuple中三个数据分别是comid,comtype,handle
	void CAccessProject_ComponentSWL_Handle::GetDataSet_SwlRuleForCal(CProject_SwlRule_ForCal * pDatasetForCalDefault,
		                             std::map<std::tuple<int, int, CString>, CProject_SwlRule_ForCal*> & swlrule_sets);


	/**
	* @brief  更新或者插入关联 component_swl_info_handle 的记录,swlRuleMX_UserDef_handle的记录
	*
	*          
	* @note  : 
	* @param : pDs 为 CPrivateSWL_UserDefDataset
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [4/1/2019]
	*/
	void UpdateSWL_Info(int comid,CString handle,CSQLDataSet * pDs);
	BOOL UpdateSWL_Info(const CUIntArray & arrComid,CStringArray & arrHandle,CSQLDataSet * pDs);
	/// 没有采用事务的方式的记录插入----主要因为外部有数据库事务控制
	void UpdateSWL_Info_NoTransaction(int comid,CString handle,CSQLDataSet * pDs);

	//删除 记录
	void Delete(int comid,CString handle);
	BOOL Delete(const CUIntArray & arrComid,const CStringArray & arrHandle);

private:
	BOOL m_bExtern;

	//获取所有相关 component_swl_handle 表 的 id
	void GetId(const CUIntArray & arrComid,const CStringArray & arrHandle,CStringArray & arrId) const;

	/// 没有采用事务的方式的记录插入----主要因为外部有数据库事务控制
	BOOL UpdateSWL_Info_NoTransaction(const CUIntArray & arrComid,CStringArray & arrHandle,CSQLDataSet * pDs);
};
