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
���������������ַ�����StringBuffer��
������
�� �� ֵ��
�㷨�����ַ���������һ��Buffer�� ���в�������������ʽ���п��ƣ�ÿ���ڵ㶨���б���m_NodeSize���ơ�
ע������ڲ�ʹ��Sizeȫ��ʹ��TCHAR��
��    �ߣ�����ҵ
ʱ    �䣺[2010:11:8]   9:50
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
	* @brief   ���ӽ� LargeString ���浽 ָ���ļ���
	*
	*          
	* @note  : 
	* @param :const CString & strFilePath�� �ļ�·�� 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/11/2011]
	*/
	BOOL	Print2File(const CString & strFilePath);
private:

	CStringNode * m_pNode;//�ַ����ڵ�
	int		m_iNodeSize;//�ڵ㳤�ȣ��ڹ���ʱָ��
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// CLarge_StringBuilder ���¹���
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
	* @brief   ���ӽ� LargeString ���浽 ָ���ļ���
	*
	*          
	* @note  : 
	* @param :const CString & strFilePath�� �ļ�·�� 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/11/2011]
	*/
	BOOL	Print2File(const CString & strFilePath);

private:
	PmTString m_strData;
};


#endif // !defined(AFX_LARGE_STRINGBUILDER_H__15A70F78_DABE_4A27_A956_EAB0014C94D9__INCLUDED_)
