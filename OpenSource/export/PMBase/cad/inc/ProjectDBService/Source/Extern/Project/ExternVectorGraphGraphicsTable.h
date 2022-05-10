// ExternVectorGraphGraphicsTable.h: interface for the CExternVectorGraphGraphicsTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNVECTORGRAPHGRAPHICSTABLE_H__47980683_B27E_42A7_9724_0F9846E8641D__INCLUDED_)
#define AFX_EXTERNVECTORGRAPHGRAPHICSTABLE_H__47980683_B27E_42A7_9724_0F9846E8641D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PMProjectDBSERVICE CExternVectorGraphGraphicsTable : public CPM_StorageDataSet
{
protected:
	CExternVectorGraphGraphicsTable();
	virtual ~CExternVectorGraphGraphicsTable();
	static CExternVectorGraphGraphicsTable * m_pInstance;

public:

	/******************************************************************** 
	 功能描述：插入图  从 源插到 目标数据库中
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[7/5/2009]
	*********************************************************************/ 
	BOOL Insert2ProjectVectorGraph(int iVectorID,int & iProjectVectorID);

	static CExternVectorGraphGraphicsTable *Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = PMNew(CExternVectorGraphGraphicsTable);
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
	//判断 m_pInstance 是否被初始化
	static BOOL CheckInstance()
	{
		if ( m_pInstance)
			return TRUE;
		return FALSE ;	
	}

	int InitFieldStr();

	NDbDataSet * GetDataSet();

	BOOL SaveDataSet();
};

#endif // !defined(AFX_EXTERNVECTORGRAPHGRAPHICSTABLE_H__47980683_B27E_42A7_9724_0F9846E8641D__INCLUDED_)
