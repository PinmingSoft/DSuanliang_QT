#pragma once 

//�ص����������÷�װ��PmRegex::CheckValue
typedef BOOL (*CheckRegex_PTR)(const CString& strRegExp,const CString& strValue,int flag);


//�ص�����������
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
	// ע��ص�����
	static BOOL	 RegistCheckValueExport(CheckRegex_PTR pCalBackFun ) ; 
	//�ÿջص�����
	static BOOL  UnRegistCheckValueExport() ; 

	static BOOL CallCheckValue(CString strValue,CString strRegExp,int flag = 0);

private:
	static CheckRegex_PTR g_funCheckValue;
};