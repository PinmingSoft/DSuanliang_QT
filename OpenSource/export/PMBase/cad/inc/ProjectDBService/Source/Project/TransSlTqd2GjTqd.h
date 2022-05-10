

#pragma once 

/**
 * @brief 算量的砼强度转换为钢筋的砼强度
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-13]
 * @note  
 */
#include "./Project/AccessProject_ProjectInfoTable.h"

class PMProjectDBSERVICE CPMTransSLTQD2GJTQD  
{
private:

	/****************************************************************
	功能描述： 将TQD进行才分 得到 TQD值和 渗透等级 
	参数：
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[2011:8:1   10:45]
	*****************************************************************/
	static BOOL SplitTQDInfo( const CString & strTQD,int & iTQD,int & iSTDJ);

public:

	/**
	* @brief  将 C20/P6 翻译成 C20  
	*
	*          
	* @note  :
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [7/12/2011]
	*/
	static CString TransComplexToSample(ProjectInfoMacro::GangJinMode gangJinMode,CString strTqd ) ;

	/****************************************************************
	功能描述： 检测TQD是否合法
	参数：
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[2011:8:1   10:44]
	*****************************************************************/
	static BOOL CheckTQDIsOk( const CString & strTQD);

	/******************************************************************** 
	功能描述：将算量TQD 翻译为 钢筋TQD
	参数：
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[13/4/2009]
	*********************************************************************/ 
	static CString TransSLTQD2GJTQD( const int iComID, const CString & strSLTQD);

	/**
	* @brief  将钢筋TQD 翻译为 算量 TQD 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/2/2012]
	*/
	static CString TransGJTQD2SLTQD(const CString & strGJTQD);

	/**
	* @brief  将 C20/P6 翻译成 C20  
	*
	*          
	* @note  :
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [7/12/2011]
	*/
	static CString TransComplexToSample( const CString & strTqd ) ;

	CPMTransSLTQD2GJTQD();
	virtual ~CPMTransSLTQD2GJTQD();
};



/**
* @brief   封装一些临时对象的定义操作 (充当 新老Access的 适配器)
*
*          
* @note  : 不需要每一个用到的地方都去定义一个临时对象 ， 有一些参数类型的转化可以在该类中实现
*
* @author: 杨兴耀
* @date  : [2012-7-17]
*/

class PMProjectDBSERVICE CSysData_InitMgOpr 
{
public:
	static CSysData_InitMgOpr * Instance()
	{
		if (NULL == m_pInstance)
		{
			m_pInstance = PMNew(CSysData_InitMgOpr);
		}
		return m_pInstance;
	}

	static void Release()
	{
		PMDelete(m_pInstance);
	}

	static CString GetKey(const int iGangJinMode,
		const CString & strKzdj , 
		const CString & strGjlx , 
		const CString & strGjzl ,
		const CString & strTqd );

	//
	static void GetMgDj(
		const CString & strKzdj , 
		const CString & strGjlx , 
		const CString & strGjzl ,
		const CString & strTqd , 
		const CString & strDjbfl, 
		const CString & str25 ,
		const double dRDGJXS,
		const double dBHCHDXS,
		CString & strMgz, 
		CString & strDjz, 
		const int iComType = -1 
		);

	static void GetMgDj(
		const CString & strKzdj , 
		const CString & strGjlx , 
		const CString & strGjzl ,
		const CString & strTqd , 
		const CString & strDjbfl, 
		const CString & str25 ,
		const double dRDGJXS,
		const double dBHCHDXS,
		const int iGangJinMode ,
		CString & strMgz, 
		CString & strDjz, 
		const int iComType = -1 
		);

	//锚固值与搭接百分率
	static CString GetDjValue(const CString & strMgz,const CString & strbfl);

	/// 获取搭接锚固
	static CString GetDjValue( const CString & strValue ,const double dValue);
	static CString GetMgValue( const CString & strValue ,const double dValue);

protected:
	static CSysData_InitMgOpr * m_pInstance;

	//
	CSysData_InitMgOpr() ;
	~CSysData_InitMgOpr() ; 

	//初始化锚固搭接值
	void InitData_MgDj();

	//
	struct MgDjInfo
	{
		CString m_mgz1;
		CString m_mgz2;
		CString m_djz1;
		CString m_djz2;
	};

	//gangjin_mode|kzdj|gjlx|gjzl|tqd
	std::map<CString,MgDjInfo *> m_mapMgzDjz;

	/// gangjin_
	BOOL	GetRfqMg( 
		const int iComType , 
		const CString & strGjzl , 
		const CString & strTqd , 
		const CString & strbfl , 
		const CString & str25 ,
		CString & strMgz ,
		CString & strDjz 
		);

	void	GetMg( 
		const CString & strKzdj , 
		const CString & strGjlx , 
		const CString & strGjzl ,
		const CString & strTqd ,
		const int iGangJinMode ,
		CString & strMg1 ,
		CString & strMg2 ,
		CString & strDj1 ,
		CString & strDj2
		) ;   

	// 切割搭接值 该数据储存方式为XX*d;XX*d;XX*d;
	//wrq [2017-1-16]
	static CString SplitDjValueList(const CString & strDjzList,const CString & strbfl);
};
