#pragma once 

//回调函数，调用封装的PmRegex::CheckValue
typedef BOOL (*CheckRegex_PTR)(const CString& strRegExp,const CString& strValue,int flag);


//回调函数管理类
class PMLogicDataOprAPI  CPM_LogicDataOpr_CallBack
{
public:
	CPM_LogicDataOpr_CallBack()  
	{

	}

	virtual ~CPM_LogicDataOpr_CallBack() 
	{

	}

public:
	// 注册回调函数
	static BOOL	 RegistCheckValueExport(CheckRegex_PTR pCalBackFun ) ; 
	//置空回调函数
	static BOOL  UnRegistCheckValueExport() ; 

	static BOOL CallCheckValue(CString strValue,CString strRegExp,int flag = 0);

private:
	static CheckRegex_PTR g_funCheckValue;
};