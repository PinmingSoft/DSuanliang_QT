// ExternVectorGraphTable.h: interface for the CExternVectorGraphTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNVECTORGRAPHTABLE_H__6E731706_F731_4DCB_9574_C72D4E317EE5__INCLUDED_)
#define AFX_EXTERNVECTORGRAPHTABLE_H__6E731706_F731_4DCB_9574_C72D4E317EE5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../ExternManager.h"

class PMProjectDBSERVICE CExternVectorGraphTable : public CExternTableBase
{
protected:
	
public:

	CExternVectorGraphTable();
	virtual ~CExternVectorGraphTable();

	/******************************************************************** 
	 功能描述：插入图  从 源插到 目标数据库中
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[7/5/2009]
	*********************************************************************/ 
	BOOL Insert2ProjectVectorGraph(int iVectorID,int & iSLVectorID,int & iGJVectorID);

	BOOL Insert2ProjectVectorGraphGraphics(int iVectorID,int & iNewVectorID);

	CSQLDataSet * GetDataSet();
};

#endif // !defined(AFX_EXTERNVECTORGRAPHTABLE_H__6E731706_F731_4DCB_9574_C72D4E317EE5__INCLUDED_)
