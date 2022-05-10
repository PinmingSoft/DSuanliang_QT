// PmCommonFun.h: interface for the PmCommonFun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMCOMMONFUN_H__45CF0A2C_6E10_4EFD_9971_54702E511AA4__INCLUDED_)
#define AFX_PMCOMMONFUN_H__45CF0A2C_6E10_4EFD_9971_54702E511AA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef ZFYDEBUG
#define FTRACE(buf) pmcommon::SaveFileContent(_T("c:\\parmsinfo.xml"),buf);
	#define RXPRINT(buf) acutPrintf(buf);
#else
	#define FTRACE(buf) (void)0
	#define RXPRINT(buf) (void)0;
#endif

//用于二进制数据操作用char,该char不允许变为TCHAR
typedef char BinaryChar;

namespace pmcommon
{
class PMBASECLASSAPI CPMSession_Lock
{
public:
	CPMSession_Lock(CRITICAL_SECTION * pSection);
	virtual ~CPMSession_Lock();

protected:

	CRITICAL_SECTION * m_pSection;
};

// 获取当前进程的内存增量
class PMBASECLASSAPI CPMMemoryWatch
{
public:
	
	CPMMemoryWatch( const CString & strMsg , int nOutput = 1 , BOOL bOnlyLog = TRUE);
	~CPMMemoryWatch();

protected:
	
	double m_dBefWorkMem;		/// 开始的物理内存
	double m_dBefPageMem;		/// 开始的页面内存
	BOOL m_bOnlyLog;			/// TRUE : 只输出到log中,FALSE 输出到log中还弹出对话框
	CString  m_strMsg ;			/// 标记测试的函数
	int		m_nOutput ;			/// 标记输出的
								/// 1 : 只输出 总的内存增长量 ( 默认 )
								/// 2 : 输出内存的明细 , 物理内存/页面内存
};

/// 模块跟踪，用于跟踪，判断模块是否正确退出
class PMBASECLASSAPI CModuleTracker
{
public:
	CModuleTracker(HMODULE hModule,int nCode = 1001);
	~CModuleTracker();

private:
	CString m_strPath;
	int m_iCode;
};


PMBASECLASSAPI enum 
{
	eThousand = 1000 
	, eMillion = 1000000
	, eThousandMillion = 1000000000
};

PMBASECLASSAPI float GetCurMemorySize() ; 

/****************************************************************
  功能描述： 获取当前内存使用情况
	参数：
	返 回 值：0：正常 1:中高使用率(1.0G) 2：高使用率（1.5G） 3：已满（2G） 4: (3G)
	算法：
	注意事项：
	作    者：王建业
	时    间：[2011:3:25   15:24]
*****************************************************************/
PMBASECLASSAPI int CheckMemoryFull(float & fMemorySize) ; 

/**
* @brief   用new BYTE 方式 创建一块新内存，用于存放pBuffer二进制数据
*
*			如果失败，返回NULL.
* @note  : 内存由外部用 delete []释放
* @param : 
* @return: 
* @author: zfy
* @date  : [12/24/2015]
*/
PMBASECLASSAPI void * MemoryCopy(const void * pBuffer,long lngBufferSize);

/**************************
	时间追踪函数
***************************/
PMBASECLASSAPI void BeginClock(int index);
PMBASECLASSAPI void EndClock(int index);
PMBASECLASSAPI void ShowClockInterval(int index);
PMBASECLASSAPI DWORD GetClockInterval(int index);
PMBASECLASSAPI void ReleaseClock(int index = -1);
PMBASECLASSAPI void ShowAllClock();
PMBASECLASSAPI void ReleaseAllClock();

/**************************
	文件操作函数
***************************/
PMBASECLASSAPI BOOL GetFileContent(const CString & fileName,CString & content);
PMBASECLASSAPI BOOL SaveFileContent(const CString & fileName,const CString & content);
PMBASECLASSAPI BOOL AppendFileContent(const CString & fileName,const CString & content);
PMBASECLASSAPI BOOL RemoveFile(const CString & fileName);
//


/**************************
	常用数据追踪函数
***************************/
//字符串数组内容追踪
PMBASECLASSAPI void TraceStringArray(CStringArray & ary);
PMBASECLASSAPI int  LookUpStringArray(const CStringArray & ary,const CString & value);
PMBASECLASSAPI int  LookUpStringArrayNoCase(const CStringArray & ary,const CString & value);

//反转元素位置
PMBASECLASSAPI void Reverse(CStringArray & ary);
PMBASECLASSAPI void Reverse(CUIntArray & ary);

//寻找CUIntArray 序号。找不到返回-1
PMBASECLASSAPI int Find(const CUIntArray & datas,int desValue);

//剔除重复
PMBASECLASSAPI void RemoveSame(CStringArray & ary);
PMBASECLASSAPI void RemoveSame(CStringArray & datas1,const CStringArray & datas2);
PMBASECLASSAPI void RemoveSame(CUIntArray & ary);
PMBASECLASSAPI void RemoveSame(CUIntArray & datas1,UINT data2);
PMBASECLASSAPI void RemoveSame(CUIntArray & datas1,const CUIntArray & datas2);

//dataset内容追踪
//PMBASECLASSAPI void TraceDataSet(NDataModelDataSet * pDataSet);

/**************************
	常用数据/字符串操作函数
***************************/
//四舍五入,num为保留的小数个数
PMBASECLASSAPI int GetNear(double src1);
PMBASECLASSAPI double GetNear(double src1,int num);
//由于stdlib库与math.lib库冲突，以致某些时候abs函数出错
PMBASECLASSAPI double GetAbs(double src);
//指数运算，要求value>=0,num >=0,否则返回false
PMBASECLASSAPI bool Pow(double value,int num,double & result);
//10的n次方。如果num小于等于0，则返回1
PMBASECLASSAPI INT64 PowTen(int num);
//ax^2+bx+c=0的方程式的解
PMBASECLASSAPI BOOL GetEquationResult(double a,double b,double c,CArray<double,double> & results);

/**
* @brief   求解n元方程式的解[类似于 a1X1+a2X2+a3X3+a4=0 的多元方程式]
*
*			
* @note  : 
* @param : int n表示 n元 ，此时arrEquation长度必须为n*(n+1)个参数，且元素序列为n行*(n+1)列的矩阵
* @return: TRUE/FALSE
* @author: zfy
* @date  : [1/27/2016]
*/
PMBASECLASSAPI BOOL GetEquationResult(const CArray<double,double> & arrEquation,int n,CArray<double,double> & results);

/**
* @brief   判断valueCheck是否在 [rangeLow,rangeHigh]范围内
*
*			误差kTol 用于相等时的判断
* @note  : 
* @param : 
* @return: TRUE/FALSE
* @author: zfy
* @date  : [10/18/2019]
*/
PMBASECLASSAPI BOOL IsValueInRange(double rangeLow,double rangeHigh,double valueCheck,double kTol);

/******************************************************************** 
 功能描述：判断两个范围是否相交
 参    数：bInsectPriority表示是否是相交优先
 返 回 值：
 算    法：
 注意事项：如果相交优先,则如果两个范围本来在端部有少量差距且这个差距在误差范围内，则很可能导致
						两个范围相交
		   如果相交不优先,则如果两个范围本来在端部有少量的相交且这个相交在误差范围内，则很可能导致
						两个范围不相交。
 作    者：zfy
 时    间：[1/19/2011]
*********************************************************************/

//范围是否可相交,kTol不能使用<0的数
PMBASECLASSAPI BOOL IsRangeInsect(double xDes1
									,double xDes2
									,double xSrc1
									,double xSrc2
									,BOOL bInsectPriority
									,double kTol = 1);

//是否为数字的判断
PMBASECLASSAPI BOOL IsNumeric(const CString & sData);
//表达式
PMBASECLASSAPI BOOL IsExpressionCanCal(const CString & sData,double & dResultCal);
PMBASECLASSAPI BOOL CalExpression(const CString & sData,double & dResultCal);
//获取尾部数值
PMBASECLASSAPI BOOL GetTailNumeric(const CString & sData,int & iPos,double & dValue);
//data是否以head开头
PMBASECLASSAPI BOOL IsHeadOf(const CString & sData,CString sHead);
//data是否以tail结尾
PMBASECLASSAPI BOOL IsTailOf(const CString & sData,CString sTail);
/**
* @brief   增加尾部数字的值
*
*          如果sData为空，则返回 1
* @note  : 
* @param : 
* @return: 
* @author: zfy
* @date  : [9/30/2015]
*/
PMBASECLASSAPI CString IncreaseName(const CString & sData);

/**
* @brief   判断是否为中文，本函数仅初略判断
*			GB2312规定"对任意一个图形字符都采用两个字节表示，每个字节均采用七位编码表示"，
*			习惯上称第一个字节为"高字节"，第二个字节为"低字节"。
*          其编码范围是高位0XA1-0XFE，低位也是0XA1-0XFE；汉字编码范围是高位0XB0-0XF7，低位是0XA1-0XFE.
* @note  : 
* @param : 
* @return: 
* @author: zfy
* @date  : [8/7/2014]
*/
PMBASECLASSAPI BOOL IsChineseChar(TCHAR chr);

//拆分字符串,a|b|c,将被分解成a,b,c
PMBASECLASSAPI BOOL Split(const CString & strValue,const CString & delim, CStringArray & aryStr);
//拆分字符串,a1|b1;a2|b2;a3|b3 ,将被分解成a1,a2,a3 与b1,b2,b3。a1|b1;a2|b2;a3|b3; 也将被分拆成同样的结果
PMBASECLASSAPI BOOL Split(const CString & strValue,const CString & delim,const CString & subDelim, CStringArray & aryStr1,CStringArray & aryStr2);
//按空格分隔字符串，中间可以隔很多空格
PMBASECLASSAPI BOOL SplitByBlank(const CString & strValue,CStringArray & aryStr);
//合并字符串
PMBASECLASSAPI CString Combine(const CString & delim,const CStringArray & aryStr1,BOOL bTailSplitter=FALSE);
PMBASECLASSAPI CString Combine(const CString & delim,const CString & subDelim,const CStringArray & aryStr1,const CStringArray & aryStr2,BOOL bTailSplitter=FALSE);
/**
* @brief 计算出CString实际长度(中文按2个长度)
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: lbw
* @date  : [9/24/2019]
*/
PMBASECLASSAPI int GetCStringRelLength(const CString & delim);
/**
* @brief 合并字符串，允许在内容外添加单引号
*
*          
* @note  : 
* @param : bHasQuote 表示是否添加单引号
* @defenc: 
* @return: 
* @author: zfy
* @date  : [3/11/2019]
*/
PMBASECLASSAPI CString CombineWithSingleQuote(const CString & delim,const CStringArray & handls,BOOL bHasQuote);

/**
* @brief   把书写表达式中的sqrt符号替换为(√),有更号的字符串要警惕，其第一格为@符号。不支持根号内还有根号
*
*          不支持有变量的表达式，仅支持数学表达式，
* @note  : 内部实现仅仅简单替换sqrt,并在上面加上_，同时第一格加@符号
* @param : 
* @return: 
* @author: zfy
* @date  : [20/4/2012]
*/
PMBASECLASSAPI CString ChangeSqrtSym(CString sValue);

///len表示字符个数,chr为初始化的字符
PMBASECLASSAPI CString AllocStr(int len,CString str);

///替换某个位置到某个位置间的字符为chr
PMBASECLASSAPI CString ReplaceStrTo(CString sValue,int iPosBegin,int iPosEnd,TCHAR chr);

///替换字符串，要求arrParnmName长度与arrParmValue一致。否则返回原字符串
PMBASECLASSAPI CString ReplaceParm(CString sExpression,const CStringArray & arrParmName,const CStringArray & arrParmValue);

//获取pos位置配对的括号(左右小括号/左右中括号/左右大括号/其他符号则匹配下个相同字符)位置,如果找不到匹配的也返回-1
PMBASECLASSAPI int GetMatchBlankPos(CString sValue,int pos);
//计算字符串
PMBASECLASSAPI double Calc(const TCHAR * lptstr);

PMBASECLASSAPI int CalcAsInt(const TCHAR * lptstr);

PMBASECLASSAPI bool CalcString(const TCHAR * lptstr,double & dResult);

/**
* @brief   计算带参数表 计算式
*			
*          
* @note  : 减少业务代码替换公式，执行过程。
* @param : 
* @return: 
* @author: wjy
* @date  : [10/22/2019]
*/
PMBASECLASSAPI bool CalcString_Parm(const TCHAR * lptstr,const CStringNumberList & parmList, double & dResult);

//要求strHex为合法的十六进制并以Ox开头，十六进制转换为十进制
PMBASECLASSAPI BOOL IsHex(const CString& strhex);

//判断是否是16进制的CAD句柄----开头不用以Ox开头
PMBASECLASSAPI BOOL IsHexHandle(const CString& strhex);
PMBASECLASSAPI UINT64 HexHandle2Ten(const CString& strhex);


//十六进制转换为十进制
PMBASECLASSAPI PmLong Hex2Ten(CString& strhex);

//十进制转换为十六进制
PMBASECLASSAPI CString Ten2Hex(long & lsrc);

//十进制(LONG64)转换为十六进制
PMBASECLASSAPI CString Ten64ToHex(LONG64 & lsrc);

/******************************************************************** 
 功能描述：智能拆分字符串
 参    数：
 返 回 值：
 算    法：
 注意事项：1、首先去除首尾空格
		   2、a|b|c将被分解成a,b,c   (*如果c为空字符串，将仅有a,b)
              a|b|c|将被分解为a,b,c
		   3、如果为空字符串(或者全部为空格)的话,则返回_T("")
 作    者：zfy
 时    间：[23/1/2008]
*********************************************************************/
PMBASECLASSAPI BOOL SplitRegularFormat(const CString & strValue,const CString & delim, CStringArray & aryStr);
//把1.111222333转化为1.111
PMBASECLASSAPI const CString CStr(double value);
//保留3位小数，并且会自动四舍五入,如:6.0036->6.003 ,-6.0036->-6.004,-6.0032->-6.003
PMBASECLASSAPI const CString CStr(double value,int num);
//1转化为"1",123转化为"123";
PMBASECLASSAPI const CString CStr(int id);

//功能等同于SimpleStr，但为防止1.4624999999999999类的数值转换的时候变成1.462。 
//  而实际1.4624999999999999为1.4625，四舍五入为1.463。现象对小数部分用Float转化处理
PMBASECLASSAPI const CString CStrUseFloat(double value,int num);

//转化为规则字符串，即尽可能的减少其后的0,默认最多保存3位
PMBASECLASSAPI const CString SimpleStr_Zero(double value,int num = 3);
PMBASECLASSAPI const CString SimpleStr(double value,int num = 3);
PMBASECLASSAPI const CString SimpleStr(const CString & value);
//比较两个浮点型,0表示相同 1表示前面大 -1表示后面大
PMBASECLASSAPI int CompareDbl(double src1,double src2);

//比较两个浮点型,0表示相同 1表示前面大 -1表示后面大 --- 添加可以设置误差的接口
PMBASECLASSAPI int CompareDbl(double src1,double src2 , const double dTol ) ;
//比较两个浮点型,0表示相同 1表示前面大 -1表示后面大 添加误差控制
PMBASECLASSAPI int CompareDblV2(double src1,double src2 , const double dTol = 0.000001 );

//判断是否为0
PMBASECLASSAPI BOOL IsZero(double src,double dTol=0.001);

/// 毫米转化为米
PMBASECLASSAPI	double ConvertMmToM( double dMm ) ; 

/// 毫米转化为米 --- 返回字符串
PMBASECLASSAPI	CString ConvertMmToMStr( double dMm ) ; 

/// 平方毫米转化为平方米
PMBASECLASSAPI  double ConvertSmToM( double dSm ) ; 

/// 平方毫米转化为平方米 --- 返回字符串
PMBASECLASSAPI  CString ConvertSmToMStr( double dSm ) ; 

/// 立方毫米转化为立方米
PMBASECLASSAPI  double  ConvertCmToM( double dCm ) ; 

/// 立方毫米转化为立方米 --- 返回字符串
PMBASECLASSAPI  CString  ConvertCmToMStr( double dCm ) ; 

/// 米转化为毫米
PMBASECLASSAPI  double ConvertMToMm( double dM ) ; 

/// 米转化为毫米 --- 返回字符串
PMBASECLASSAPI  CString ConvertMToMmStr( double dM ) ; 

/// 
PMBASECLASSAPI void Replace(CString & jsgs, const CString &sParam, const CString &sValue) ;

 
PMBASECLASSAPI void	ReplaceMath(  CString & strParm ) ;

/// 
PMBASECLASSAPI void	ReplaceMgDj( CString & strParm ) ;
PMBASECLASSAPI void	ReplaceMg( CString & strParm ,CString strMgz,CString strMgzB) ;
PMBASECLASSAPI void	ReplaceDj( CString & strParm ,CString strDjz) ;

/// 字符替换,替换大括号，中括号为小括号，同时剔除中文字字符
PMBASECLASSAPI CString ReplaceChineseChar(CString exp);

/// 删除括号内的东西
PMBASECLASSAPI CString ClearBlankContent(CString exp,TCHAR sBlankBegin = _T('<'),TCHAR sBlankEnd = _T('>'));

/**
* @brief   判断名称中是否存在字符串permitchar中的某个字符
*
*			
* @note  : 
* @param : 
* @return: TRUE/FALSE
* @author: zfy
* @date  : [11/21/2017]
*/
PMBASECLASSAPI BOOL IsContainChar(CString name,CString sCharList);

/**
* @brief   分析文本的实际绘制宽度
*
*			因为绘制1 与 绘制 8 ，两则宽度不一样
* @note  : 
* @param : 
* @return: TRUE/FALSE
* @author: zfy
* @date  : [8/24/2018]
*/
PMBASECLASSAPI double GetTextWidth(CString sText,double dblTextSize);
PMBASECLASSAPI double GetTextWidth(CString sText,double dblTextSize,double dSpan);

/**
* @brief   ini文件读取与写入
*
*
* @note  : 
* @param : strSegName 表示  段名
* @param : strKeyName 表示  键名
* @param : strKeyValue 表示 键值
* @param : valueSize 表示 strKeyValue 的最大可能大小,如果strKeyValue很大，需要更改这个值，以便数据可完整读出
* @param : strFilePath 表示 ini文件名，如: grid.ini
* @return: 
* @author: zfy
* @date  : [11/12/2015]
*/
PMBASECLASSAPI BOOL ReadIniFileInfo(CString strSegName, CString strKeyName, CString &strKeyValue,CString strFilePath,int valueSize=1000);
PMBASECLASSAPI BOOL WriteIniFileInfo(CString strSegName, CString strKeyName, CString strKeyValue,CString strFilePath);

//排序AFX_EXT_API，模板不用写输入输出
template <class T> void Sort(CArray<T,T> & datas)
{
	for (INT_PTR i = 0;i < datas.GetSize();i++)
	{
		for (INT_PTR j = 0;j < datas.GetSize() - i -1;j++)
		{
			T data1 = datas[j];
			T data2 = datas[j+1];
			//
			if (data1 > data2)
			{
				datas[j] = data2;
				datas[j+1] = data1;
			}
		}
	}
}

template <class T1,class T2> void Sort(CArray<T1,T1> & datas1,CArray<T2,T2> & attaches)
{
	for (INT_PTR i = 0;i < datas1.GetSize();i++)
	{
		for (INT_PTR j = 0;j < datas1.GetSize() - i -1;j++)
		{
			T1 data1 = datas1[j];
			T1 data2 = datas1[j+1];
			//
			if (data1 > data2)
			{
				datas1[j] = data2;
				datas1[j+1] = data1;
				T2 datAttach = attaches[j];
				attaches[j] = attaches[j+1];
				attaches[j+1] = datAttach;
			}
		}
	}
}

template <class T> void Reverse(CArray<T,T> & datas)
{
	INT_PTR iSize = datas.GetSize();
	for (INT_PTR i = 0;i < iSize / 2;i++)
	{
		T data1 = datas[i];
		T data2 = datas[iSize - i - 1];
		datas.SetAt(i,data2);
		datas.SetAt(iSize - i - 1,data1);
	}
}

template <class T> int Find(const CArray<T,T> & datas,T des)
{
	INT_PTR iSize = datas.GetSize();
	for (INT_PTR i = 0;i < iSize;i++)
	{
		T data1 = datas[i];
		if (data1 == des)
			return PmCast::ToInt(i);
	}
	//
	return -1;
}

template <class T> int GetMaxIndex(const CArray<T,T> & datas)
{
	if (datas.GetSize() == 0)
		return -1;
	INT_PTR idxMax = 0;
	T maxData = datas[0];
	for (INT_PTR i = 1;i < datas.GetSize();i++)
	{
		T data1 = datas[i];
		if (data1 > maxData)
		{
			idxMax = i;
			maxData = data1;
		}
	}
	return PmCast::ToInt(idxMax);
}

template <class T> int GetMinIndex(const CArray<T,T> & datas)
{
	if (datas.GetSize() == 0)
		return -1;
	INT_PTR idxMin = 0;
	T minData = datas[0];
	for (INT_PTR i = 1;i < datas.GetSize();i++)
	{
		T data1 = datas[i];
		if (data1 < minData)
		{
			idxMin = i;
			minData = data1;
		}
	}
	return PmCast::ToInt(idxMin);
}

template <class T> void Remove(CArray<T,T> & datas,const T des)
{
	INT_PTR iSize = datas.GetSize();
	for (INT_PTR i = iSize - 1;i >= 0;i--)
	{
		T data1 = datas[i];
		if (data1 == des)
		{
			datas.RemoveAt(i);
		}
	}
}

template <class T> void RemoveSame(CArray<T> & datas)
{
	//排序
	for (INT_PTR i = 0;i < datas.GetSize();i++)
	{
		T data1 = datas[i];
		for (INT_PTR j = i + 1;j < datas.GetSize();j++)
		{
			T data2 = datas[j];
			if (data1 == data2)
			{
				datas.RemoveAt(i);
				i--;
				break;
			}
		}
	}
}

template <class T> void RemoveSame(CArray<T,T> & datas)
{
	//排序
	for (INT_PTR i = 0;i < datas.GetSize();i++)
	{
		T data1 = datas[i];
		for (INT_PTR j = i + 1;j < datas.GetSize();j++)
		{
			T data2 = datas[j];
			if (data1 == data2)
			{
				datas.RemoveAt(i);
				i--;
				break;
			}
		}
	}
}

template <class T> void RemoveSame(CArray<T,T&> & datas)
{
	//排序
	for (INT_PTR i = 0;i < datas.GetSize();i++)
	{
		T data1 = datas[i];
		for (INT_PTR j = i + 1;j < datas.GetSize();j++)
		{
			T data2 = datas[j];
			if (data1 == data2)
			{
				datas.RemoveAt(i);
				i--;
				break;
			}
		}
	}
}


template <class T> void RemoveSame(CArray<T,T> & datas1,const CArray<T,T> & datas2)
{
	std::set<T> setData2;
	for (int j = 0;j < datas2.GetSize();j++)
	{
		setData2.insert(datas2[j]);
	}

	//删除
	for (INT_PTR i = datas1.GetSize() - 1;i >= 0;i--)
	{
		T data1 = datas1[i];
		if (setData2.find(data1) != setData2.end())
		{
			datas1.RemoveAt(i);
		}
	}
}

template <class T> void RemoveSame(std::vector<T> & datas1,const std::vector<T>  & datas2)
{
	std::set<T> setData2;
	for (std::vector<T>::const_iterator iter = datas2.begin();iter != datas2.end();iter++)
	{
		setData2.insert(*iter);
	}

	//排序
	for (std::vector<T>::const_iterator iterData1 = datas1.begin();iterData1 != datas1.end();)
	{
		T data1 = *iterData1;
		//
		if (setData2.find(data1) != setData2.end())
		{
			iterData1 = datas1.erase(iterData1);
		}
		else
		{
			iterData1++;
		}
	}
}

template <class T> void ReleaseMem(CArray<T *,T *> & datas)
{
	//排序
	for (INT_PTR i = 0;i < datas.GetSize();i++)
	{
		T * data1 = datas[i];
		PMDelete(data1);
	}
	datas.RemoveAll();
}

template <class T> void ReleaseMem(CArray<T *> & datas)
{
	//排序
	for (INT_PTR i = 0;i < datas.GetSize();i++)
	{
		T * data1 = datas[i];
		PMDelete(data1);
	}
	datas.RemoveAll();
}

//释放map内数据值的内容
template <class T1,class T2> void ReleaseMem(std::map<T1,T2 *> & datas)
{
	//排序
	for (std::map<T1,T2 *>::iterator iter = datas.begin();iter != datas.end();iter++)
	{
		T2 * data1 = iter->second;
		PMDelete(data1);
	}
	datas.clear();
}

template <class T1> void ReleaseMem(std::vector<T1 *> & datas)
{
	//排序
	for (std::vector<T1 *>::iterator iter = datas.begin();iter != datas.end();iter++)
	{
		T1 * data1 = *iter;
		PMDelete(data1);
	}
	datas.clear();
}

// 功能描述：取上限
template<class T> inline int GetCeil(const T &src)
{
	int iSrc = (int)src/1;
	return (src - iSrc >0) ? (iSrc + 1) : iSrc;
}

// 功能描述：取整
template<class T> inline int GetFloor(const T &src)
{
	return (int)src/1;
}

// 功能描述：交换
template<class T> inline void Swap(T &src1,T &src2)
{
	T temp = src1;	src1 = src2; src2 = temp;
}

} // pmcommon

#endif // !defined(AFX_PMCOMMONFUN_H__45CF0A2C_6E10_4EFD_9971_54702E511AA4__INCLUDED_)
