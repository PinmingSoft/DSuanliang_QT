// Timing.h: interface for the CTiming class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMING_H__1B5079C5_8A63_4E1B_B164_115388BAC23B__INCLUDED_)
#define AFX_TIMING_H__1B5079C5_8A63_4E1B_B164_115388BAC23B__INCLUDED_
// ***************************************************************
//  Timing   version:  1.0   ? date: 02/26/2008
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2008 - All Rights Reserved
//  作者:clz
// ***************************************************************
// 文件说明:时间测定类
//
//==============================使用说明========================
//	可以使用宏 ,在release下自动去掉时间测试代码,
//	已经做了输出和查看结果的命令: timing ,该命令设置放在柱工程中
//	输出命令由若干选项控制:
//	1:是否清空保存的结果?直接在命令中选择
//	2:是否清空已经输出的结果?在配置文件c:\TimingSet.ini中设置
//
//	如果直接在代码中嵌入CTiming 对象,请把该对象的声明放在函数入口处.
//	一般默认使用只需要使用 DEFAULT_TIMING 宏
// ***************************************************************
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <map>

//全局默认测试
#ifdef  _DEBUG
#define DEFAULT_TIMING(strFunName) \
CTiming OneFunTimeing(strFunName);
#else
#define DEFAULT_TIMING(strFunName) 
#endif

#ifdef  _DEBUG
#define _TIMING_1(strFunName,bAddUp) \
CTiming OneFunTimeing_1(strFunName, bAddUp);
#else
#define _TIMING_1(strFunName,bAddUp) 
#endif


#ifdef  _DEBUG
#define _TIMING_2(strFunName,bAddUp,strBelong) \
CTiming OneFunTimeing_2(strFunName,bAddUp,strBelong);
#else
#define _TIMING_2(strFunName,bAddUp,strBelong) 
#endif

//设置某一函数的总时间函数
#ifdef  _DEBUG
	#define _TIMING_TOTAL(strFunName,bAddUp,strBelong) \
		CTiming OneFunTimeing_3(strFunName,bAddUp,strBelong,true);
#else
	#define _TIMING_TOTAL(strFunName,bAddUp,strBelong) 
#endif

//函数分段测试宏
#ifdef _DEBUG 
#define	_BEGIN_SEG_TIMING(nSegTag,strFunName,bAddUp,strBelong) \
			CTiming *pNewObj##nSegTag = NULL;\
					{\
					static CString str1 = #nSegTag;\
					static CString str2 = str1 + strFunName;\
					pNewObj##nSegTag = new CTiming(str2,bAddUp,strBelong);\
					}\


#define  _END_SEG_TIMING(nSegTag) \
			if (pNewObj##nSegTag != NULL)\
			{\
				delete pNewObj##nSegTag ;\
				pNewObj##nSegTag = NULL;\
			}
#else

#define  _BEGIN_SEG_TIMING(SegTag,strFunName,bAddUp,strBelong)
#define  _END_SEG_TIMING(SegTag)

#endif



//是否启用时间测试的开关,屏蔽掉该定义就关闭了测试 
#define INSERT_TIME_CODE
#ifdef INSERT_TIME_CODE
	#define TIME_CODE(code_seg){code_seg}
#else 
	#define TIME_CODE(code_seg){}
#endif

const CString QUAN_JU_TIMING = _T("全局统计");//全局统计

// 功能描述：时间测定,用于统计单个函数运行时间
// 算法： 
// 注意事项：所有方法都没有返回值.
// 参数：
// 返 回 值：
// 作    者：蔡绿洲
// 时    间：[26/2/2008]
class PMBASECLASSOPRAPI CTiming  
{
public:
	//使用函数名称,对应打印函数
	// 功能描述：strFunName使用函数名,用于标识对什么计时,
	//			bAddUp标识在多次重复调用时是否多次统计或者只统计一次,	默认是采用多次统计
	//			strBelong标识测试是谁做的,默认取全局,目的在于可以清空自己的统计结果而不影响别人
	//			bIsTatolTimeRecord 表示是否是该表的全局时间.如果是总时间,那么不会使用各个函数累加得到总时间
	//			一个表应该最多只设置一个该类型的记录,否则出错
	// 算法： 
	// 注意事项：
	// 参数：
	// 返 回 值：
	// 作    者：蔡绿洲
	// 时    间：[26/2/2008]
	CTiming(const CString &strFunName, bool bAddUp = true, const CString &strBelong = QUAN_JU_TIMING, bool bIsTatolTimeRecord = false);
	virtual ~CTiming();
	
	// 功能描述：是否参与累计统计
	// 算法： 
	// 注意事项：累计项目包括输出调用次数,总时间
	//				如果设置为不参与的话,则只统计一次调用花费的时间
	// 参数：
	// 返 回 值：
	// 作    者：蔡绿洲
	// 时    间：[26/2/2008]
	void SetAddUp(bool bAddUp){m_bAddUp = bAddUp;};

	// 功能描述：设置结果所属
	// 算法： 
	// 注意事项：
	// 参数：
	// 返 回 值：
	// 作    者：蔡绿洲
	// 时    间：[26/2/2008]
	void SetBelong(const CString &strBlong){m_strBelong = strBlong;};

	// 功能描述：提前计算时间,则在析构时不计算了
	// 算法： 
	// 注意事项：
	// 参数：
	// 返 回 值：
	// 作    者：蔡绿洲
	// 时    间：[9/2/2009]
	BOOL CountTime();

private:
	BOOL m_bHasCount;//是否已经计时过了

private:
	CString m_strKey;//函数名
	DWORD m_BeginTime;//开始时间
	DWORD m_EndTime;
	bool m_bAddUp;//是否需要统计
	bool m_bIsTatolTimeRecord;//是否是该表的全局总时间

	CString m_strBelong;//所属范围,可以区分谁做测试,或区分测试模块
};

//保存测试记录
class PMBASECLASSOPRAPI CRecord
{
	struct FunInfo_T //函数信息
	{
		DWORD nCount;//调用次数
		DWORD nTotalTime;
		bool bAddUp;//是否是统计
		bool bIsTatolTimeRecord;//是否是全局时间的记录
		FunInfo_T(DWORD nC = 0, DWORD nT = 0, bool bA = true, bool bIsTR = false):nCount(nC),nTotalTime(nT),bAddUp(bA),bIsTatolTimeRecord(bIsTR){;};
	};
	//保存统计结果
	typedef std::map<CString, FunInfo_T>Table_T;//保存一个单位的测试表数据,函数名称映射
	typedef std::map<CString, Table_T>AllTable_T;//所有的测试数据

public:

	//清除所有记录
	static void ClearAll();

	//清除指定表的所有记录
	static void ClearTable(const CString &strTableKey);

	//得到总表头
	static BOOL GetZbt(CString &strZbt);


protected:

	friend class CTiming;
	friend class COutPutMessage;
	// 功能描述：插入一条记录
	// 算法： 
	// 注意事项：表的插入操作只允许CTiming使用
	// 参数：
	// 返 回 值：
	// 作    者：蔡绿洲
	// 时    间：[26/2/2008]
	static BOOL AddRecord(const CString &strTableKey, const CString &strFunKey, DWORD Time, bool bAddUp, bool bIsTatolTimeRecord);
	
	CRecord(){;};
	~CRecord(){;};

	//统计一张表中次数,总时间, 平均时间
	static void CountTable(Table_T &aTable, DWORD &nTotalCs, DWORD &nTotalTime, DWORD &nPjsj);

	//统计多张表中次数,总时间, 平均时间
	static void CountTable(AllTable_T &aTable, DWORD &nTotalCs, DWORD &nTotalTime, DWORD &nPjsj);

private:
	static AllTable_T s_AllTable;

	static DWORD s_nTotalCount;//总的调用次数
};


//输出信息,可以用于重定向,如果需要重新定制输出目标,请重载该类,并实现所有虚函数
//暂时不做这项支持!

//实现为输出到文件
class PMBASECLASSOPRAPI COutPutMessage
{
public:
	COutPutMessage();
	virtual ~COutPutMessage(){;};

	//输出信息
	BOOL PrintRecord();
protected:
	
	//清除目标输出区域
	virtual BOOL Clear();
	
	BOOL AppendFileContent(const CString & strFilePath,const CString & strAppendInfo);

	//加入一行
	virtual BOOL AddOneLine(const CString &strOneLineContext);

	//显示出来
	virtual void Show();

private:

	CString m_strFilePath;
};

//时间测试相关的选项设置类
class PMBASECLASSOPRAPI CTimingSet
{
public:
	static CTimingSet *Instance();
	static void Release();

	// 功能描述：信息输出是否是追加模式,如果不是,那么上次的输出到目标的内容会被清除.
	// 算法： 
	// 注意事项：
	// 参数：
	// 返 回 值：
	// 作    者：蔡绿洲
	// 时    间：[27/2/2008]
	BOOL IsSuperadditionMode();

	//设置追加模式
	BOOL SetSuperadditionMode(BOOL bSuperaddition);
protected:
	CTimingSet(){m_strTimingIniFilePath = _T("c:\\TimingSet.ini"); memset(m_chBuf, 0, 100);};
	~CTimingSet(){;};

	//设置和取得值
	BOOL SetKeyAndValue(const CString &strKey, int nValue);
	BOOL GetKeyAndValue(const CString &strKey, int &nValue);

	static const CString strBoolDefault;//布尔值默认
	static const CString APP_NAME;//
	static const CString SuperadditionMode;//追加模式
	static const int BUF_SIZE;
private:
	TCHAR m_chBuf[100];
	CString m_strTimingIniFilePath;

	static CTimingSet *s_pTimingSet;
};

#endif // !defined(AFX_TIMING_H__1B5079C5_8A63_4E1B_B164_115388BAC23B__INCLUDED_)
