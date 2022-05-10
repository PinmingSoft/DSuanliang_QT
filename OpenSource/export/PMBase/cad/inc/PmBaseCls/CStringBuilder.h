// CStringBuilder.h: interface for the CStringBuilder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CSTRINGBUILDER_H__15A70F78_DABE_4A27_A956_EAB0014C94D9__INCLUDED_)
#define AFX_CSTRINGBUILDER_H__15A70F78_DABE_4A27_A956_EAB0014C94D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class PMBASECLASSAPI CStringBuilder
{
public:
	CStringBuilder();
	virtual ~CStringBuilder();

	void	SetAutoIncrease(int autoSize) { m_AutoIncrease=autoSize; }
	void	Append(LPCTSTR pStr, int AutoIncrease=4096);
	void	Append(TCHAR c);
	void	AppendLine(LPCTSTR pStr, int AutoIncrease=4096);
	void	GetString(CString& str);
	LPTSTR	GetString();
	void	Empty(BOOL freeBuffer = TRUE);
	int		GetLength();

	LPTSTR	m_pMem;

private:
	int		m_bytesAlloc;
	int		m_bytesUsed;
	int		m_AutoIncrease;
};

#endif // !defined(AFX_CSTRINGBUILDER_H__15A70F78_DABE_4A27_A956_EAB0014C94D9__INCLUDED_)
