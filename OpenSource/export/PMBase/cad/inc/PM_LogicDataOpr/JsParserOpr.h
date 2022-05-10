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

	/// ��ʾ�Ƿ���Ҫ�ͷ�
	BOOL	NeedReease() ;

	/**
	* @brief ��ִ��Java�ű�֮ǰ���� ��������  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [28/11/2012]
	*/
	void SetParameter(const CString & strName, const CString & strValue);
	void SetParameter(const CString & strName, double dValue);

	/**
	* @brief ��ִ��java�ű�֮�󣬶����н��ȡ����  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [28/11/2012]
	*/
	BOOL GetParameter(const CString & strName,CString & strValue);

	/**
	* @brief  ִ�нű����� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [28/11/2012]
	*/
	BOOL Run(const CString & strJsContext,CString & strResult,CString & strError);

protected:
	CJsParserOpr(void);
	virtual ~CJsParserOpr(void);

	static CJsParserOpr * m_pInstance;

	CJavascriptManager * m_pJavascriptManager;

	/// 
	/// ִ���˶��ٴ�
	/// ִ��
	/// 
	int		m_iRunCount ; 

	/// 
	BOOL	m_bNeedClear ; 

	/// ���Ĵ���
	static	int m_iMaxRunCount ; 
};




/**
* @brief �����������  
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: ����ҫ
* @date  : [2014��9��15��]
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