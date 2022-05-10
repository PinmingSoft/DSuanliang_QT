// CLarge_StringBuilder_Bak.h: interface for the CStringBuilder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LARGE_STRINGBUILDER_H__15A70F78_DABE_4A27_A956_EAB0014C94D9__INCLUDED_)
#define AFX_LARGE_STRINGBUILDER_H__15A70F78_DABE_4A27_A956_EAB0014C94D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "pmstdstring.h"

#define LargeStringBuilder_NodeSize 4096

/******************************************************************** 
功能描述：超大字符串的StringBuffer。
参数：
返 回 值：
算法：将字符串不放在一个Buffer中 进行操作。以链表形式进行控制，每个节点定长有变量m_NodeSize控制。
注意事项：内部使用Size全部使用TCHAR。
作    者：王建业
时    间：[2010:11:8]   9:50
*********************************************************************/ 
class PMBASECLASSAPI CLarge_StringBuilder_Bak
{
public:
	CLarge_StringBuilder_Bak();
	CLarge_StringBuilder_Bak(int iNodeSize);
	
	virtual ~CLarge_StringBuilder_Bak();

	class CStringNode
	{
	public:
		CStringNode(CLarge_StringBuilder_Bak * pStringBuilder);
		virtual ~CStringNode();

		BYTE * GetBuffer();
		int GetUseSize(){return m_iNodeUse;}
		void SetUseSize(int iUseSize){m_iNodeUse = iUseSize;}

		void AppendBuffer(LPVOID pBuffer,int iBufferSize);

		CStringNode * GetNextStringNode(){return m_pNextStringNode;}

	protected:
		BYTE * m_pMem;
		int m_iNodeUse;
		CStringNode * m_pNextStringNode;

		CLarge_StringBuilder_Bak * m_pStringBuilder;
	};

	int GetNodeSize(){return m_iNodeSize;}

	CStringNode * GetStringNode(){return m_pNode;}

	void	Append(LPCTSTR pStr);
	void	Append(BYTE * pBuffer,int iBufferSize);
	void	Append(CLarge_StringBuilder_Bak * pStringBuilder);
	void	AppendLine(LPCTSTR pStr);
	void	GetString(CString& str);
	void	Empty();
	int		GetLength();

	/**
	* @brief   增加将 LargeString 保存到 指定文件中
	*
	*          
	* @note  : 
	* @param :const CString & strFilePath： 文件路径 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/11/2011]
	*/
	BOOL	Print2File(const CString & strFilePath);
private:

	CStringNode * m_pNode;//字符串节点
	int		m_iNodeSize;//节点长度，在构造时指定
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// CLarge_StringBuilder 重新构造
/// 

class PMBASECLASSAPI CLarge_StringBuilder
{
public:
	CLarge_StringBuilder();
	virtual ~CLarge_StringBuilder();

public:

	void	Append(LPCTSTR pStr);
	void	AppendLine(LPCTSTR pStr);
	void	GetString(CString& str);
	void	Empty();
	int		GetLength();

	/**
	* @brief   增加将 LargeString 保存到 指定文件中
	*
	*          
	* @note  : 
	* @param :const CString & strFilePath： 文件路径 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/11/2011]
	*/
	BOOL	Print2File(const CString & strFilePath);

private:
	PmTString m_strData;
};


#endif // !defined(AFX_LARGE_STRINGBUILDER_H__15A70F78_DABE_4A27_A956_EAB0014C94D9__INCLUDED_)
