// OutPutTextTable.h: interface for the COutPutTextTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OUTPUTTEXTTABLE_H__6DEF5448_6EDA_4346_A4F1_C40DFBD1ABED__INCLUDED_)
#define AFX_OUTPUTTEXTTABLE_H__6DEF5448_6EDA_4346_A4F1_C40DFBD1ABED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class KERNELBASECLASS_API COutPutTextTable  
{
public:

	class KERNELBASECLASS_API CTextNode
	{
	public:
		CTextNode();
		virtual ~CTextNode();

		void SetNodeHead(char * NodeHead);
		char * GetNodeHead() {return m_cNodeHead;}

		BOOL AddNodeValue(char* strHeadName,char* strNodeValue);

		void AddTextNode(char* strHeadName);

		CTextNode * GetNextTextNode(){return m_pNextNode;}

		CArray<char*,char*&> * GetTextValueArr(){return &m_cNodeValueArr;}

	protected:
		char* m_cNodeHead;
		CArray<char*,char*&> m_cNodeValueArr;
		CTextNode * m_pNextNode;
	};

	COutPutTextTable();
	virtual ~COutPutTextTable();

	void AddTextNode(CString strHeadName);

	BOOL AddNodeValue(CString strHeadName,CString strNodeValue);

	void EndOneRowWrite();

	BOOL Print2File(CString strFilePath);

protected:

	void Print2File_SplitLine(CFile * pFile,CUIntArray & iMaxColSizeArr);
	void Print2File_Head(CFile * pFile,CUIntArray & iMaxColSizeArr);
	void Print2File_WriteInfo(CFile * pFile,CString strInfo,int iLength);

	CTextNode * m_pTextNode;
};

#endif // !defined(AFX_OUTPUTTEXTTABLE_H__6DEF5448_6EDA_4346_A4F1_C40DFBD1ABED__INCLUDED_)
