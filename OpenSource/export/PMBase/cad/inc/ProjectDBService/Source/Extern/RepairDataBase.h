#pragma once

#define floor2floorgjxxinfo 10  /// 楼层到楼层信息表 的对应关系  是 1层 对应 10 行 (2010-5-20)  

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//// 专门用于 修复数据库
class PMProjectDBSERVICE CRepairDataBase
{
private:
	CRepairDataBase();
	static CRepairDataBase * m_pInstance;
public:
	virtual ~CRepairDataBase();
	static CRepairDataBase *Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = PMNew(CRepairDataBase);
		}
		return m_pInstance;
	}
	static void Release()
	{
		if ( m_pInstance )
		{
			PMDelete(m_pInstance);
			m_pInstance = NULL;
		}
	}

	
public:
	/// 返回有问题的 表 数 
	int Check( ) ; 
	/// 修复 
	void Repair() ; 

	/// 检查 floorgjxxinfo 是否有问题
	BOOL CheckFloorGjxxInfoTable() ; 

	/// 修复 floorgjxxinfo 表
	/// 根据楼成表去重构一遍  
	void RepairFloorGjxxInfoTable() ;

private:

//////////////////////////////////////////////////////////////////////////
/// common 
	BOOL Update_DataSet(NDataModelDataSet * pTemDataSet,NDataModelDataSet * pNewDataSet) ; 

};
