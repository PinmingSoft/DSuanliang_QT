#pragma once

class CJavascriptManager;
class PMLogicDataOprAPI CJsParserOpr
{
public:

	static CJsParserOpr * Instance()
	{
		if(NULL == m_pInstance)
		{
			m_pInstance = PMNew(CJsParserOpr);
		}
		return m_pInstance;
	}

	static void Release()
	{
		if(NULL != m_pInstance)
		{
			PMDelete(m_pInstance);
			m_pInstance = NULL ;
		}
	}

	/// 
	static int	GetMaxJsCount() ;

	/// 表示是否需要释放
	BOOL	NeedReease() ;

	/**
	* @brief 在执行Java脚本之前进行 参数设置  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [28/11/2012]
	*/
	void SetParameter(const CString & strName, const CString & strValue);
	void SetParameter(const CString & strName, double dValue);

	/**
	* @brief 在执行java脚本之后，对运行结果取数据  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [28/11/2012]
	*/
	BOOL GetParameter(const CString & strName,CString & strValue);

	/**
	* @brief  执行脚本计算 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [28/11/2012]
	*/
	BOOL Run(const CString & strJsContext,CString & strResult,CString & strError);

protected:
	CJsParserOpr(void);
	virtual ~CJsParserOpr(void);

	static CJsParserOpr * m_pInstance;

	CJavascriptManager * m_pJavascriptManager;

	/// 
	/// 执行了多少次
	/// 执行
	/// 
	int		m_iRunCount ; 

	/// 
	BOOL	m_bNeedClear ; 

	/// 最大的次数
	static	int m_iMaxRunCount ; 
};




/**
* @brief 参数计算的类  
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: 杨兴耀
* @date  : [2014年9月15日]
*/
class PMLogicDataOprAPI CParmCalOpr
{
private:
	CParmCalOpr() ; 
public:

	~CParmCalOpr() ; 

	static CParmCalOpr & Instance() ; 

	void	Clear() ;

public:
	BOOL Calc() ; 

public:

	CString GetAsStr( const CString & strParmName ) ; 
	int		GetAsInt( const CString & strParmName ) ; 
	double	GetAsDbl( const CString & strParmName ) ; 

	/// 
	void	AddParmStr( const CString & strParmName , const CString & strParmValue ) ;

	void	AddParmInt( const CString & strParmName , const int & iParmValue ) ;

	void	AddParmDbl( const CString & strParmName , const double & dParmValue ) ;

	void	AddParmMathMgdj( const CString & strParmName , const CString & strParmValue ) ;

protected:

	/// 
	PmStr2StrMap m_mapOutParm ; 

	/// 
	PmStr2StrMap m_mapInParm ;

	/// 
	PmStrList m_listParmName ; 


};

#define  PmParmCalOpr CParmCalOpr::Instance() 