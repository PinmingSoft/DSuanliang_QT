// Param.h: interface for the CParam class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARAM_H__94436FBA_4954_4966_881C_FDB8BBFACC3F__INCLUDED_)
#define AFX_PARAM_H__94436FBA_4954_4966_881C_FDB8BBFACC3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/**
* @brief   用于表示参数，比如：计算设置的参数
*
*          CParms类的内部单位存储结构
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
		PTNoCombin = 5, /* 不用进行参数合并*/
		PTHandle = 6	//句柄参数，其采用字符串获取
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

public: //属性设置
	ParmType GetType() const;
	void SetType(ParmType type);
	void SetParm(const CString & name,const CString & value,const CString & description,ParmType type=PTString);
	void SetParm(const CString & name,int value,const CString & description,ParmType type=PTString);
	void SetParm(const CString & name,double value,const CString & description,ParmType type=PTString);
	void SetParm(const CString & name,float value,const CString & description,ParmType type=PTString);

	///获取/设置参数名
	const CString &	GetParmName() const ;
	void	SetParmName(const CString & name);

	///获取/设置参数的值
	CString	GetParmValue() const ;
	void	SetParmValue(const CString & value);
	void	SetParmValue(int value) ;
	void	SetParmValue(double value);

	///获取/设置参数的描述
	CString	GetDes() const;
	void	SetDes(const CString & des);

	///获取/设置参数的排序序号
	int		GetSortIndex() const;
	void	SetSortIndex(int index);

	/************************************************************************/
	/*				特殊字段                                                */
	/************************************************************************/
	///	用于进行参数替换方案值 if语句
	void	SetInsertExpress(const CString & sExpress);
	CString	GetInsertExpress() const;
	/// 要插入的参数  , c1$v1;c2$v2;
	void	SetInsertValue(const CString & sValue);
	CString	GetInsertValue() const;
	/// 用于标识进行替换的标签，如果宏文件中找到这个标签，就用combine函数返回值进行替换
	void	SetInsertLabel(const CString & sLabel);
	CString	GetInsertLabel() const;
	/// 记录InvalidMsg信息，比较普遍的特殊信息
	CString	GetInvalidMsg() const ;
	void	SetInvalidMsg(const CString & msg);

	///还回替换m_InsertExpress被m_InsertValue替换后的信息
	CString	GetExpression();

protected:
//DATE:
	CString		m_strName;
	CString		m_strValue;
	CString		m_strDescription;
	//zfy add 20070829
	CString		m_strInvalidMsg;
	ParmType	m_iType;			//0表示字符型，1表示非字符型,3 为表达式
	
	//与类别3相关的参数，表达式类，如果是表达式参数，系统将采用另外一种
	//注意 本支持尚未写实现代码
	CString		m_InsertValue;		//要插入的参数  , c1$v1;c2$v2;
	CString		m_InsertExpress;	//用于进行参数替换方案值 if语句
	CString		m_InsertLable;		//用于标识进行替换的标签，如果宏文件中找到这个标签，就用combine函数返回值进行替换

	int			m_sortIndex;


};

#endif // !defined(AFX_PARAM_H__94436FBA_4954_4966_881C_FDB8BBFACC3F__INCLUDED_)
