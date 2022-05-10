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

//���ڶ��������ݲ�����char,��char�������ΪTCHAR
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

// ��ȡ��ǰ���̵��ڴ�����
class PMBASECLASSAPI CPMMemoryWatch
{
public:
	
	CPMMemoryWatch( const CString & strMsg , int nOutput = 1 , BOOL bOnlyLog = TRUE);
	~CPMMemoryWatch();

protected:
	
	double m_dBefWorkMem;		/// ��ʼ�������ڴ�
	double m_dBefPageMem;		/// ��ʼ��ҳ���ڴ�
	BOOL m_bOnlyLog;			/// TRUE : ֻ�����log��,FALSE �����log�л������Ի���
	CString  m_strMsg ;			/// ��ǲ��Եĺ���
	int		m_nOutput ;			/// ��������
								/// 1 : ֻ��� �ܵ��ڴ������� ( Ĭ�� )
								/// 2 : ����ڴ����ϸ , �����ڴ�/ҳ���ڴ�
};

/// ģ����٣����ڸ��٣��ж�ģ���Ƿ���ȷ�˳�
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
  ���������� ��ȡ��ǰ�ڴ�ʹ�����
	������
	�� �� ֵ��0������ 1:�и�ʹ����(1.0G) 2����ʹ���ʣ�1.5G�� 3��������2G�� 4: (3G)
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2011:3:25   15:24]
*****************************************************************/
PMBASECLASSAPI int CheckMemoryFull(float & fMemorySize) ; 

/**
* @brief   ��new BYTE ��ʽ ����һ�����ڴ棬���ڴ��pBuffer����������
*
*			���ʧ�ܣ�����NULL.
* @note  : �ڴ����ⲿ�� delete []�ͷ�
* @param : 
* @return: 
* @author: zfy
* @date  : [12/24/2015]
*/
PMBASECLASSAPI void * MemoryCopy(const void * pBuffer,long lngBufferSize);

/**************************
	ʱ��׷�ٺ���
***************************/
PMBASECLASSAPI void BeginClock(int index);
PMBASECLASSAPI void EndClock(int index);
PMBASECLASSAPI void ShowClockInterval(int index);
PMBASECLASSAPI DWORD GetClockInterval(int index);
PMBASECLASSAPI void ReleaseClock(int index = -1);
PMBASECLASSAPI void ShowAllClock();
PMBASECLASSAPI void ReleaseAllClock();

/**************************
	�ļ���������
***************************/
PMBASECLASSAPI BOOL GetFileContent(const CString & fileName,CString & content);
PMBASECLASSAPI BOOL SaveFileContent(const CString & fileName,const CString & content);
PMBASECLASSAPI BOOL AppendFileContent(const CString & fileName,const CString & content);
PMBASECLASSAPI BOOL RemoveFile(const CString & fileName);
//


/**************************
	��������׷�ٺ���
***************************/
//�ַ�����������׷��
PMBASECLASSAPI void TraceStringArray(CStringArray & ary);
PMBASECLASSAPI int  LookUpStringArray(const CStringArray & ary,const CString & value);
PMBASECLASSAPI int  LookUpStringArrayNoCase(const CStringArray & ary,const CString & value);

//��תԪ��λ��
PMBASECLASSAPI void Reverse(CStringArray & ary);
PMBASECLASSAPI void Reverse(CUIntArray & ary);

//Ѱ��CUIntArray ��š��Ҳ�������-1
PMBASECLASSAPI int Find(const CUIntArray & datas,int desValue);

//�޳��ظ�
PMBASECLASSAPI void RemoveSame(CStringArray & ary);
PMBASECLASSAPI void RemoveSame(CStringArray & datas1,const CStringArray & datas2);
PMBASECLASSAPI void RemoveSame(CUIntArray & ary);
PMBASECLASSAPI void RemoveSame(CUIntArray & datas1,UINT data2);
PMBASECLASSAPI void RemoveSame(CUIntArray & datas1,const CUIntArray & datas2);

//dataset����׷��
//PMBASECLASSAPI void TraceDataSet(NDataModelDataSet * pDataSet);

/**************************
	��������/�ַ�����������
***************************/
//��������,numΪ������С������
PMBASECLASSAPI int GetNear(double src1);
PMBASECLASSAPI double GetNear(double src1,int num);
//����stdlib����math.lib���ͻ������ĳЩʱ��abs��������
PMBASECLASSAPI double GetAbs(double src);
//ָ�����㣬Ҫ��value>=0,num >=0,���򷵻�false
PMBASECLASSAPI bool Pow(double value,int num,double & result);
//10��n�η������numС�ڵ���0���򷵻�1
PMBASECLASSAPI INT64 PowTen(int num);
//ax^2+bx+c=0�ķ���ʽ�Ľ�
PMBASECLASSAPI BOOL GetEquationResult(double a,double b,double c,CArray<double,double> & results);

/**
* @brief   ���nԪ����ʽ�Ľ�[������ a1X1+a2X2+a3X3+a4=0 �Ķ�Ԫ����ʽ]
*
*			
* @note  : 
* @param : int n��ʾ nԪ ����ʱarrEquation���ȱ���Ϊn*(n+1)����������Ԫ������Ϊn��*(n+1)�еľ���
* @return: TRUE/FALSE
* @author: zfy
* @date  : [1/27/2016]
*/
PMBASECLASSAPI BOOL GetEquationResult(const CArray<double,double> & arrEquation,int n,CArray<double,double> & results);

/**
* @brief   �ж�valueCheck�Ƿ��� [rangeLow,rangeHigh]��Χ��
*
*			���kTol �������ʱ���ж�
* @note  : 
* @param : 
* @return: TRUE/FALSE
* @author: zfy
* @date  : [10/18/2019]
*/
PMBASECLASSAPI BOOL IsValueInRange(double rangeLow,double rangeHigh,double valueCheck,double kTol);

/******************************************************************** 
 �����������ж�������Χ�Ƿ��ཻ
 ��    ����bInsectPriority��ʾ�Ƿ����ཻ����
 �� �� ֵ��
 ��    ����
 ע���������ཻ����,�����������Χ�����ڶ˲����������������������Χ�ڣ���ܿ��ܵ���
						������Χ�ཻ
		   ����ཻ������,�����������Χ�����ڶ˲����������ཻ������ཻ����Χ�ڣ���ܿ��ܵ���
						������Χ���ཻ��
 ��    �ߣ�zfy
 ʱ    �䣺[1/19/2011]
*********************************************************************/

//��Χ�Ƿ���ཻ,kTol����ʹ��<0����
PMBASECLASSAPI BOOL IsRangeInsect(double xDes1
									,double xDes2
									,double xSrc1
									,double xSrc2
									,BOOL bInsectPriority
									,double kTol = 1);

//�Ƿ�Ϊ���ֵ��ж�
PMBASECLASSAPI BOOL IsNumeric(const CString & sData);
//���ʽ
PMBASECLASSAPI BOOL IsExpressionCanCal(const CString & sData,double & dResultCal);
PMBASECLASSAPI BOOL CalExpression(const CString & sData,double & dResultCal);
//��ȡβ����ֵ
PMBASECLASSAPI BOOL GetTailNumeric(const CString & sData,int & iPos,double & dValue);
//data�Ƿ���head��ͷ
PMBASECLASSAPI BOOL IsHeadOf(const CString & sData,CString sHead);
//data�Ƿ���tail��β
PMBASECLASSAPI BOOL IsTailOf(const CString & sData,CString sTail);
/**
* @brief   ����β�����ֵ�ֵ
*
*          ���sDataΪ�գ��򷵻� 1
* @note  : 
* @param : 
* @return: 
* @author: zfy
* @date  : [9/30/2015]
*/
PMBASECLASSAPI CString IncreaseName(const CString & sData);

/**
* @brief   �ж��Ƿ�Ϊ���ģ��������������ж�
*			GB2312�涨"������һ��ͼ���ַ������������ֽڱ�ʾ��ÿ���ֽھ�������λ�����ʾ"��
*			ϰ���ϳƵ�һ���ֽ�Ϊ"���ֽ�"���ڶ����ֽ�Ϊ"���ֽ�"��
*          ����뷶Χ�Ǹ�λ0XA1-0XFE����λҲ��0XA1-0XFE�����ֱ��뷶Χ�Ǹ�λ0XB0-0XF7����λ��0XA1-0XFE.
* @note  : 
* @param : 
* @return: 
* @author: zfy
* @date  : [8/7/2014]
*/
PMBASECLASSAPI BOOL IsChineseChar(TCHAR chr);

//����ַ���,a|b|c,�����ֽ��a,b,c
PMBASECLASSAPI BOOL Split(const CString & strValue,const CString & delim, CStringArray & aryStr);
//����ַ���,a1|b1;a2|b2;a3|b3 ,�����ֽ��a1,a2,a3 ��b1,b2,b3��a1|b1;a2|b2;a3|b3; Ҳ�����ֲ��ͬ���Ľ��
PMBASECLASSAPI BOOL Split(const CString & strValue,const CString & delim,const CString & subDelim, CStringArray & aryStr1,CStringArray & aryStr2);
//���ո�ָ��ַ������м���Ը��ܶ�ո�
PMBASECLASSAPI BOOL SplitByBlank(const CString & strValue,CStringArray & aryStr);
//�ϲ��ַ���
PMBASECLASSAPI CString Combine(const CString & delim,const CStringArray & aryStr1,BOOL bTailSplitter=FALSE);
PMBASECLASSAPI CString Combine(const CString & delim,const CString & subDelim,const CStringArray & aryStr1,const CStringArray & aryStr2,BOOL bTailSplitter=FALSE);
/**
* @brief �����CStringʵ�ʳ���(���İ�2������)
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
* @brief �ϲ��ַ�������������������ӵ�����
*
*          
* @note  : 
* @param : bHasQuote ��ʾ�Ƿ���ӵ�����
* @defenc: 
* @return: 
* @author: zfy
* @date  : [3/11/2019]
*/
PMBASECLASSAPI CString CombineWithSingleQuote(const CString & delim,const CStringArray & handls,BOOL bHasQuote);

/**
* @brief   ����д���ʽ�е�sqrt�����滻Ϊ(��),�и��ŵ��ַ���Ҫ���裬���һ��Ϊ@���š���֧�ָ����ڻ��и���
*
*          ��֧���б����ı��ʽ����֧����ѧ���ʽ��
* @note  : �ڲ�ʵ�ֽ������滻sqrt,�����������_��ͬʱ��һ���@����
* @param : 
* @return: 
* @author: zfy
* @date  : [20/4/2012]
*/
PMBASECLASSAPI CString ChangeSqrtSym(CString sValue);

///len��ʾ�ַ�����,chrΪ��ʼ�����ַ�
PMBASECLASSAPI CString AllocStr(int len,CString str);

///�滻ĳ��λ�õ�ĳ��λ�ü���ַ�Ϊchr
PMBASECLASSAPI CString ReplaceStrTo(CString sValue,int iPosBegin,int iPosEnd,TCHAR chr);

///�滻�ַ�����Ҫ��arrParnmName������arrParmValueһ�¡����򷵻�ԭ�ַ���
PMBASECLASSAPI CString ReplaceParm(CString sExpression,const CStringArray & arrParmName,const CStringArray & arrParmValue);

//��ȡposλ����Ե�����(����С����/����������/���Ҵ�����/����������ƥ���¸���ͬ�ַ�)λ��,����Ҳ���ƥ���Ҳ����-1
PMBASECLASSAPI int GetMatchBlankPos(CString sValue,int pos);
//�����ַ���
PMBASECLASSAPI double Calc(const TCHAR * lptstr);

PMBASECLASSAPI int CalcAsInt(const TCHAR * lptstr);

PMBASECLASSAPI bool CalcString(const TCHAR * lptstr,double & dResult);

/**
* @brief   ����������� ����ʽ
*			
*          
* @note  : ����ҵ������滻��ʽ��ִ�й��̡�
* @param : 
* @return: 
* @author: wjy
* @date  : [10/22/2019]
*/
PMBASECLASSAPI bool CalcString_Parm(const TCHAR * lptstr,const CStringNumberList & parmList, double & dResult);

//Ҫ��strHexΪ�Ϸ���ʮ�����Ʋ���Ox��ͷ��ʮ������ת��Ϊʮ����
PMBASECLASSAPI BOOL IsHex(const CString& strhex);

//�ж��Ƿ���16���Ƶ�CAD���----��ͷ������Ox��ͷ
PMBASECLASSAPI BOOL IsHexHandle(const CString& strhex);
PMBASECLASSAPI UINT64 HexHandle2Ten(const CString& strhex);


//ʮ������ת��Ϊʮ����
PMBASECLASSAPI PmLong Hex2Ten(CString& strhex);

//ʮ����ת��Ϊʮ������
PMBASECLASSAPI CString Ten2Hex(long & lsrc);

//ʮ����(LONG64)ת��Ϊʮ������
PMBASECLASSAPI CString Ten64ToHex(LONG64 & lsrc);

/******************************************************************** 
 �������������ܲ���ַ���
 ��    ����
 �� �� ֵ��
 ��    ����
 ע�����1������ȥ����β�ո�
		   2��a|b|c�����ֽ��a,b,c   (*���cΪ���ַ�����������a,b)
              a|b|c|�����ֽ�Ϊa,b,c
		   3�����Ϊ���ַ���(����ȫ��Ϊ�ո�)�Ļ�,�򷵻�_T("")
 ��    �ߣ�zfy
 ʱ    �䣺[23/1/2008]
*********************************************************************/
PMBASECLASSAPI BOOL SplitRegularFormat(const CString & strValue,const CString & delim, CStringArray & aryStr);
//��1.111222333ת��Ϊ1.111
PMBASECLASSAPI const CString CStr(double value);
//����3λС�������һ��Զ���������,��:6.0036->6.003 ,-6.0036->-6.004,-6.0032->-6.003
PMBASECLASSAPI const CString CStr(double value,int num);
//1ת��Ϊ"1",123ת��Ϊ"123";
PMBASECLASSAPI const CString CStr(int id);

//���ܵ�ͬ��SimpleStr����Ϊ��ֹ1.4624999999999999�����ֵת����ʱ����1.462�� 
//  ��ʵ��1.4624999999999999Ϊ1.4625����������Ϊ1.463�������С��������Floatת������
PMBASECLASSAPI const CString CStrUseFloat(double value,int num);

//ת��Ϊ�����ַ������������ܵļ�������0,Ĭ����ౣ��3λ
PMBASECLASSAPI const CString SimpleStr_Zero(double value,int num = 3);
PMBASECLASSAPI const CString SimpleStr(double value,int num = 3);
PMBASECLASSAPI const CString SimpleStr(const CString & value);
//�Ƚ�����������,0��ʾ��ͬ 1��ʾǰ��� -1��ʾ�����
PMBASECLASSAPI int CompareDbl(double src1,double src2);

//�Ƚ�����������,0��ʾ��ͬ 1��ʾǰ��� -1��ʾ����� --- ��ӿ����������Ľӿ�
PMBASECLASSAPI int CompareDbl(double src1,double src2 , const double dTol ) ;
//�Ƚ�����������,0��ʾ��ͬ 1��ʾǰ��� -1��ʾ����� ���������
PMBASECLASSAPI int CompareDblV2(double src1,double src2 , const double dTol = 0.000001 );

//�ж��Ƿ�Ϊ0
PMBASECLASSAPI BOOL IsZero(double src,double dTol=0.001);

/// ����ת��Ϊ��
PMBASECLASSAPI	double ConvertMmToM( double dMm ) ; 

/// ����ת��Ϊ�� --- �����ַ���
PMBASECLASSAPI	CString ConvertMmToMStr( double dMm ) ; 

/// ƽ������ת��Ϊƽ����
PMBASECLASSAPI  double ConvertSmToM( double dSm ) ; 

/// ƽ������ת��Ϊƽ���� --- �����ַ���
PMBASECLASSAPI  CString ConvertSmToMStr( double dSm ) ; 

/// ��������ת��Ϊ������
PMBASECLASSAPI  double  ConvertCmToM( double dCm ) ; 

/// ��������ת��Ϊ������ --- �����ַ���
PMBASECLASSAPI  CString  ConvertCmToMStr( double dCm ) ; 

/// ��ת��Ϊ����
PMBASECLASSAPI  double ConvertMToMm( double dM ) ; 

/// ��ת��Ϊ���� --- �����ַ���
PMBASECLASSAPI  CString ConvertMToMmStr( double dM ) ; 

/// 
PMBASECLASSAPI void Replace(CString & jsgs, const CString &sParam, const CString &sValue) ;

 
PMBASECLASSAPI void	ReplaceMath(  CString & strParm ) ;

/// 
PMBASECLASSAPI void	ReplaceMgDj( CString & strParm ) ;
PMBASECLASSAPI void	ReplaceMg( CString & strParm ,CString strMgz,CString strMgzB) ;
PMBASECLASSAPI void	ReplaceDj( CString & strParm ,CString strDjz) ;

/// �ַ��滻,�滻�����ţ�������ΪС���ţ�ͬʱ�޳��������ַ�
PMBASECLASSAPI CString ReplaceChineseChar(CString exp);

/// ɾ�������ڵĶ���
PMBASECLASSAPI CString ClearBlankContent(CString exp,TCHAR sBlankBegin = _T('<'),TCHAR sBlankEnd = _T('>'));

/**
* @brief   �ж��������Ƿ�����ַ���permitchar�е�ĳ���ַ�
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
* @brief   �����ı���ʵ�ʻ��ƿ��
*
*			��Ϊ����1 �� ���� 8 �������Ȳ�һ��
* @note  : 
* @param : 
* @return: TRUE/FALSE
* @author: zfy
* @date  : [8/24/2018]
*/
PMBASECLASSAPI double GetTextWidth(CString sText,double dblTextSize);
PMBASECLASSAPI double GetTextWidth(CString sText,double dblTextSize,double dSpan);

/**
* @brief   ini�ļ���ȡ��д��
*
*
* @note  : 
* @param : strSegName ��ʾ  ����
* @param : strKeyName ��ʾ  ����
* @param : strKeyValue ��ʾ ��ֵ
* @param : valueSize ��ʾ strKeyValue �������ܴ�С,���strKeyValue�ܴ���Ҫ�������ֵ���Ա����ݿ���������
* @param : strFilePath ��ʾ ini�ļ�������: grid.ini
* @return: 
* @author: zfy
* @date  : [11/12/2015]
*/
PMBASECLASSAPI BOOL ReadIniFileInfo(CString strSegName, CString strKeyName, CString &strKeyValue,CString strFilePath,int valueSize=1000);
PMBASECLASSAPI BOOL WriteIniFileInfo(CString strSegName, CString strKeyName, CString strKeyValue,CString strFilePath);

//����AFX_EXT_API��ģ�岻��д�������
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
	//����
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
	//����
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
	//����
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

	//ɾ��
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

	//����
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
	//����
	for (INT_PTR i = 0;i < datas.GetSize();i++)
	{
		T * data1 = datas[i];
		PMDelete(data1);
	}
	datas.RemoveAll();
}

template <class T> void ReleaseMem(CArray<T *> & datas)
{
	//����
	for (INT_PTR i = 0;i < datas.GetSize();i++)
	{
		T * data1 = datas[i];
		PMDelete(data1);
	}
	datas.RemoveAll();
}

//�ͷ�map������ֵ������
template <class T1,class T2> void ReleaseMem(std::map<T1,T2 *> & datas)
{
	//����
	for (std::map<T1,T2 *>::iterator iter = datas.begin();iter != datas.end();iter++)
	{
		T2 * data1 = iter->second;
		PMDelete(data1);
	}
	datas.clear();
}

template <class T1> void ReleaseMem(std::vector<T1 *> & datas)
{
	//����
	for (std::vector<T1 *>::iterator iter = datas.begin();iter != datas.end();iter++)
	{
		T1 * data1 = *iter;
		PMDelete(data1);
	}
	datas.clear();
}

// ����������ȡ����
template<class T> inline int GetCeil(const T &src)
{
	int iSrc = (int)src/1;
	return (src - iSrc >0) ? (iSrc + 1) : iSrc;
}

// ����������ȡ��
template<class T> inline int GetFloor(const T &src)
{
	return (int)src/1;
}

// ��������������
template<class T> inline void Swap(T &src1,T &src2)
{
	T temp = src1;	src1 = src2; src2 = temp;
}

} // pmcommon

#endif // !defined(AFX_PMCOMMONFUN_H__45CF0A2C_6E10_4EFD_9971_54702E511AA4__INCLUDED_)
