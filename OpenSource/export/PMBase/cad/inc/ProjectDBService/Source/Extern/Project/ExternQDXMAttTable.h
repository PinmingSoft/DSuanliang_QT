// ExternQDXMAttTable.h: interface for the CExternQDXMAttTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNQDXMATTTABLE_H__80EA6329_9961_4170_9517_B9D830DAAF5F__INCLUDED_)
#define AFX_EXTERNQDXMATTTABLE_H__80EA6329_9961_4170_9517_B9D830DAAF5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"
class PMProjectDBSERVICE CExternQDXMAttTable : public CExternTableBase
{
protected:
	

public:

	CExternQDXMAttTable();
	virtual ~CExternQDXMAttTable();

	/******************************************************************** 
	 功能描述：从当前 DataSet导入到Project中
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[25/5/2009]
	*********************************************************************/ 
	BOOL Import_2Project();

	CSQLDataSet * GetDataSet();

};

#endif // !defined(AFX_EXTERNQDXMATTTABLE_H__80EA6329_9961_4170_9517_B9D830DAAF5F__INCLUDED_)
