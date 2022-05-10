// Parms.h: interface for the CParms class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARMS_H__A938BB79_C932_46FC_9FF2_C99E7C2C1F37__INCLUDED_)
#define AFX_PARMS_H__A938BB79_C932_46FC_9FF2_C99E7C2C1F37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/**
 * @brief  :用于存储参数的数据结构
 *
 *          常用的为存储计算设置等数据
 * @author :zfy
 * @version:v1.0
 * @date   :04/15/2010
 * @note   :
 */

#if defined(_DEBUG) && !defined(_FULLDEBUG_)
#define _DEBUG_CPARMS_DEFINED
#undef _DEBUG
#pragma message ("     Compiling vector header files in release mode.")
#endif

#include <afxcoll.h>
#include <vector>

#ifdef _DEBUG_CPARMS_DEFINED
#define _DEBUG
#undef _DEBUG_CPARMS_DEFINED
#endif



#ifdef  _DEBUG
	#define TraceParmsDebug(parms)	(parms).TraceParm() 
	#define TraceParmsPtr(ptr)		(ptr)->TraceParm()
#else
	#define TraceParmsDebug(parms)	((void)0)
	#define TraceParmsPtr(ptr)		((void)0)
#endif

#include "Param.h"

typedef CArray<CParm*,CParm *&> MacroParmArray;
class PMBASECLASSAPI CParms  
{
public:
	CParms();
	virtual ~CParms();

	/**
	* @brief   添加param,如果已存在则替换
	*
	*          添加的先后顺序对最终信息组合(GetParmMacro)是有关的
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [11/5/2012]
	*/
	void Add(const CParm &parm);

	///添加param,如果已存在则替换,本函数保持输入参数顺序
	void Append(const CParm & parm);

	///添加params,如果已存在则替换,本函数保持输入参数顺序
	void Append(const CParms & parms);

	///添加params,如果已存在则保留原值
	void AppendNotReplace(CParms & parms);

	///移除某个参数
	void Remove(const CString & parmName);
	///移除所有参数
	void RemoveAll();

	///获取参数的总个数
	int	GetCount() const;

	/**
	* @brief   获取参数对应的值,不存在返回_T("")
	*
	*          详细描述
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [11/5/2012]
	*/
	CString GetValue(const CString & parmName) const;

	///获取参数对应的值,参数不存在或者不能转为int 的返回FALSE
	BOOL GetValueAsInt(const CString & parmName,int & value) const;
	///获取参数对应的值,如果参数找不到或者不正常，则返回0
	int GetValueAsInt(const CString & parmName) const;

	///获取参数对应的值,参数不存在或者不能转为double的返回FALSE
	BOOL GetValueAsDouble(const CString & parmName,double & value) const;
	///获取参数对应的值,如果参数找不到或者不正常，则返回0
	double GetValueAsDouble(const CString & parmName) const;

	/// 判断两个参数集是否一致
	BOOL IsSame(const CParms & parms) const;

	/**
	* @brief   设置参数的值，如果参数不存在，则不进行设置
	*
	*          详细描述
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [11/5/2012]
	*/
	BOOL SetValue(const CString & parmName,const CString & parmValue);
	BOOL SetValue(const CString & parmName,int parmValue);
	BOOL SetValue(const CString & parmName,double parmValue);

	/**
	* @brief   获取参数对象指针，使用时需要判断返回值，因为计算设置等参数由于数目过多，经常改动，导致返回值为NULL
	*
	*          推荐使用非指针对象来获取拷贝对象,指针对象的使用是为了效率,但加大了不稳定性
	* @note  : 
	* @param : 找不到对应参数则返回NULL
	* @return: 
	* @author: zfy
	* @date  : [11/5/2012]
	*/
	CParm * GetParm(const CString & name);
	const CParm * GetParm(const CString & name) const;
	BOOL GetParm(int idx,CParm & parm) const;				//该函数仅用于遍历用,由于map不是按顺序存的，所以idx含义不大
	BOOL GetParm(const CString & name,CParm & parm) const;

	/**
	* @brief   按一定顺序一定格式，数据计算用宏字符串
	*
	*          var ttt = 1; 这样的串的组合
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [11/5/2012]
	*/
	CString GetParmMacro(const CString & parmName) const;
	CString GetParmMacro() const;//取得所有的参数转换为宏
	BOOL GetParmMacro_String(PmTString & largeStringBuilder) const;
	
	/**
	* @brief   获取参数信息,完整格式为:  描述:值(参数)
	*
	*          详细描述
	* @note  : 
	* @param : iStyle :0	不显示参数 ; 1	显示参数
	* @return: 
	* @author: zfy
	* @date  : [5/19/2009]
	*/
	CString GetParmsInfo(int iStyle = 0) const;
	
	///打印字符串到输出窗口
	void TraceParm(std::vector <CParm*> & vect) const;
	CString TraceParm() const;

	///把类输出成数组结构,内存归本类管理，外部不得删除
    void GetParmsArray(MacroParmArray &array) const;

	/// 把类按排序输出成数组,内存归本类管理，外部不得删除
	void GetParmsSorted(MacroParmArray &array) const;

	///把参数移动最后.GetParmMacro宏组合用
	void MoveParmToLast(const CString & parmName);
	///把参数移到parmNameBefore前,parmNameBefore不存在则移到最前。GetParmMacro宏组合用
	void MoveParmToBegin(const CString & parmName, CString parmNameBefore = _T(""));


	/**
	* @brief   实现对参数的拆分，用于板梁等参数处理中
	*
	*          详细描述
	* @note  : 
	* @param : 
	* @return: parmName存在，则返回true，else false
	* @author: zll
	* @date  : 01/07/2009
	*/
	BOOL SplitParm(const CString &parmName,								 /*要操作拆分的参数名*/
				   const CString &parmRepName,							 /*拆分中要替换的名字*/
				   const CString & parmDesc = _T(""),						 /*新的参数名的解释*/
				   const CParm::ParmType &parmType = CParm::PTNotString, /*拆分后形成新的参数的数据类型	*/				   
				   const int &size = 2									 /*要拆分的参数的个数*/
				   );

	/**
	* @brief   重载Add函数，方便操作，减少重复代码
	*
	*          详细描述
	* @note  : 
	* @param : 
	* @return: 
	* @author: zll
	* @date  : 01/07/2009
	*/
	inline void Add(const CString & parmName, const CString & parmValue, const CString & parmDesc, CParm::ParmType parmType)
	{	
		Add(CParm(parmName, parmValue, parmDesc, parmType));
	}	
	inline void Add(const CString & parmName, int parmValue, const CString & parmDesc, CParm::ParmType parmType)
	{	
		Add(CParm(parmName, parmValue, parmDesc, parmType));
	}
	inline void Add(const CString & parmName, double parmValue, const CString & parmDesc, CParm::ParmType parmType)
	{	
		Add(CParm(parmName, parmValue, parmDesc, parmType));
	}
	inline void Add(const CString & parmName, float parmValue, const CString & parmDesc, CParm::ParmType parmType)
	{	
		Add(CParm(parmName, parmValue, parmDesc, parmType));
	}
//////////////////////////////////////////////////////////////////////////
protected:
	int m_maxIndex;
	//从变量名称到变量对象的映射
	CMapStringToPtr  m_mapStringToParm;
};


// 参数名与 参数值对应 表
class PMBASECLASSAPI CStringNumberList
{
public:
	CStringNumberList();
	~CStringNumberList();

	void AddParm(const CString & strParmName,const CString & strParmValue);

	void AddParm(const CString & strParmName,double dValue);

	// 获取Lua脚本需要 参数表
	std::string GetParmInfo() const;

protected:
	PmArray<std::string> m_strNameArr;
	PmArray<std::string> m_strValueArr;
};


#endif // !defined(AFX_PARMS_H__A938BB79_C932_46FC_9FF2_C99E7C2C1F37__INCLUDED_)
