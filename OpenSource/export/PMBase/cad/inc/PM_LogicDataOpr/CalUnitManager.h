// CalUnitManager.h: interface for the CCalUnitManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALUNITMANAGER_H__01498D77_FDF3_4873_AA89_9C575EA9FD67__INCLUDED_)
#define AFX_CALUNITMANAGER_H__01498D77_FDF3_4873_AA89_9C575EA9FD67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/******************************************************************** 
 功能描述：进行单位管理，特殊单位的分析
 参数：
 返 回 值：
 算法：
 注意事项：
 作    者：王建业
 时    间：[20/8/2008]
*********************************************************************/ 

class PMLogicDataOprAPI CCalUnitManager  
{
public:

	/****************************************************************
	  功能描述：	 检测特殊单位 处理 线构件，面构件 支持单位 但是要有提示
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2011:3:14   10:40]
	*****************************************************************/
	BOOL CheckSpecComType_Unit(int iComType,CString strUnit);

	/// 
	BOOL RevertUnit( const CString &strOldUnit , CString &strNewUnit , double & dValue ) ;

	double RevertQuantity( CString strGcl , CString strUnit );

	/******************************************************************** 
	 功能描述：运算单位信息
	 参数：CString strUnit:要分析的单位,CStringArray & AllowUnitArr：允许的单位队列,int & iCalMode：处理方式, double &dSpecValue：运算系数
	 返 回 值：
	 算法：
	 注意事项：iCalMode：0：加 1：减 2：乘 3：除
	 作    者：王建业
	 时    间：[20/8/2008]
	*********************************************************************/ 
	CString CalUnitInfo(CString strUnit,CStringArray & AllowUnitArr,int & iCalMode, double &dSpecValue);
	
	/******************************************************************** 
	 功能描述：判断单位是否合法
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[6/4/2010]
	*********************************************************************/ 
	BOOL CheckUnitAllow(CString strUnit,CStringArray & AllowUnitArr);

	static CCalUnitManager *Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = PMNew(CCalUnitManager);
		}
		return m_pInstance;
	}
	static void Release()
	{
		if (m_pInstance != NULL)
		{
			PMDelete(m_pInstance);
			m_pInstance = NULL;
		}
	}
protected:
	static CCalUnitManager * m_pInstance;

	CCalUnitManager();
	virtual ~CCalUnitManager();

	typedef std::map<CString,CString>TranUnitMapInfo_T;
	TranUnitMapInfo_T m_MapTranUnitInfo;
private:

	/******************************************************************** 
	 功能描述：将单位变为可理解的单位
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[29/9/2009]
	*********************************************************************/ 
	CString TransUnit1(CString strUnit);
	
	void InitUnitTran();
};

#endif // !defined(AFX_CALUNITMANAGER_H__01498D77_FDF3_4873_AA89_9C575EA9FD67__INCLUDED_)
