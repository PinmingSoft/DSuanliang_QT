// Param.h: interface for the CParam class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARAM_H__94436FBA_4954_4966_881C_FDB8BBFACC3F__INCLUDED_)
#define AFX_PARAM_H__94436FBA_4954_4966_881C_FDB8BBFACC3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/**
* @brief   ���ڱ�ʾ���������磺�������õĲ���
*
*          CParms����ڲ���λ�洢�ṹ
* @note  : 
* @param : 
* @return: 
* @author: zfy
* @date  : [11/5/2012]
*/
#include "PmStdString.h"

class PMBASECLASSAPI CParm  
{
public:
	enum ParmType
	{
		PTString = 1,
		PTNotString = 2,
		PTEXPRESSION = 3,
		PTEXPRESSIONNotString = 4,
		PTNoCombin = 5, /* ���ý��в����ϲ�*/
		PTHandle = 6	//���������������ַ�����ȡ
	};

public:
	CParm();
	CParm(const CParm & macro);
	CParm(const CString & name,const CString & value,const CString & description);
	CParm(const CString & name,const CString & value,const CString & description,ParmType type);
	CParm(const CString & name,int value,const CString & description,ParmType type);
	CParm(const CString & name,double value,const CString & description,ParmType type);
	CParm(const CString & name,float value,const CString & description,ParmType type);

	void operator=(const CParm & macro);
	CString combine();

	BOOL Combine_String(PmTString & combineString);

	CString Replace(CString value);
	virtual ~CParm();

public: //��������
	ParmType GetType() const;
	void SetType(ParmType type);
	void SetParm(const CString & name,const CString & value,const CString & description,ParmType type=PTString);
	void SetParm(const CString & name,int value,const CString & description,ParmType type=PTString);
	void SetParm(const CString & name,double value,const CString & description,ParmType type=PTString);
	void SetParm(const CString & name,float value,const CString & description,ParmType type=PTString);

	///��ȡ/���ò�����
	const CString &	GetParmName() const ;
	void	SetParmName(const CString & name);

	///��ȡ/���ò�����ֵ
	CString	GetParmValue() const ;
	void	SetParmValue(const CString & value);
	void	SetParmValue(int value) ;
	void	SetParmValue(double value);

	///��ȡ/���ò���������
	CString	GetDes() const;
	void	SetDes(const CString & des);

	///��ȡ/���ò������������
	int		GetSortIndex() const;
	void	SetSortIndex(int index);

	/************************************************************************/
	/*				�����ֶ�                                                */
	/************************************************************************/
	///	���ڽ��в����滻����ֵ if���
	void	SetInsertExpress(const CString & sExpress);
	CString	GetInsertExpress() const;
	/// Ҫ����Ĳ���  , c1$v1;c2$v2;
	void	SetInsertValue(const CString & sValue);
	CString	GetInsertValue() const;
	/// ���ڱ�ʶ�����滻�ı�ǩ��������ļ����ҵ������ǩ������combine��������ֵ�����滻
	void	SetInsertLabel(const CString & sLabel);
	CString	GetInsertLabel() const;
	/// ��¼InvalidMsg��Ϣ���Ƚ��ձ��������Ϣ
	CString	GetInvalidMsg() const ;
	void	SetInvalidMsg(const CString & msg);

	///�����滻m_InsertExpress��m_InsertValue�滻�����Ϣ
	CString	GetExpression();

protected:
//DATE:
	CString		m_strName;
	CString		m_strValue;
	CString		m_strDescription;
	//zfy add 20070829
	CString		m_strInvalidMsg;
	ParmType	m_iType;			//0��ʾ�ַ��ͣ�1��ʾ���ַ���,3 Ϊ���ʽ
	
	//�����3��صĲ��������ʽ�࣬����Ǳ��ʽ������ϵͳ����������һ��
	//ע�� ��֧����δдʵ�ִ���
	CString		m_InsertValue;		//Ҫ����Ĳ���  , c1$v1;c2$v2;
	CString		m_InsertExpress;	//���ڽ��в����滻����ֵ if���
	CString		m_InsertLable;		//���ڱ�ʶ�����滻�ı�ǩ��������ļ����ҵ������ǩ������combine��������ֵ�����滻

	int			m_sortIndex;


};

#endif // !defined(AFX_PARAM_H__94436FBA_4954_4966_881C_FDB8BBFACC3F__INCLUDED_)
