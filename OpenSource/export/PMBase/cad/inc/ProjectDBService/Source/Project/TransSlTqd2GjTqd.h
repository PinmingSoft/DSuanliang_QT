

#pragma once 

/**
 * @brief ��������ǿ��ת��Ϊ�ֽ����ǿ��
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-13]
 * @note  
 */
#include "./Project/AccessProject_ProjectInfoTable.h"

class PMProjectDBSERVICE CPMTransSLTQD2GJTQD  
{
private:

	/****************************************************************
	���������� ��TQD���вŷ� �õ� TQDֵ�� ��͸�ȼ� 
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2011:8:1   10:45]
	*****************************************************************/
	static BOOL SplitTQDInfo( const CString & strTQD,int & iTQD,int & iSTDJ);

public:

	/**
	* @brief  �� C20/P6 ����� C20  
	*
	*          
	* @note  :
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [7/12/2011]
	*/
	static CString TransComplexToSample(ProjectInfoMacro::GangJinMode gangJinMode,CString strTqd ) ;

	/****************************************************************
	���������� ���TQD�Ƿ�Ϸ�
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2011:8:1   10:44]
	*****************************************************************/
	static BOOL CheckTQDIsOk( const CString & strTQD);

	/******************************************************************** 
	����������������TQD ����Ϊ �ֽ�TQD
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[13/4/2009]
	*********************************************************************/ 
	static CString TransSLTQD2GJTQD( const int iComID, const CString & strSLTQD);

	/**
	* @brief  ���ֽ�TQD ����Ϊ ���� TQD 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/2/2012]
	*/
	static CString TransGJTQD2SLTQD(const CString & strGJTQD);

	/**
	* @brief  �� C20/P6 ����� C20  
	*
	*          
	* @note  :
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [7/12/2011]
	*/
	static CString TransComplexToSample( const CString & strTqd ) ;

	CPMTransSLTQD2GJTQD();
	virtual ~CPMTransSLTQD2GJTQD();
};



/**
* @brief   ��װһЩ��ʱ����Ķ������ (�䵱 ����Access�� ������)
*
*          
* @note  : ����Ҫÿһ���õ��ĵط���ȥ����һ����ʱ���� �� ��һЩ�������͵�ת�������ڸ�����ʵ��
*
* @author: ����ҫ
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

	//ê��ֵ���Ӱٷ���
	static CString GetDjValue(const CString & strMgz,const CString & strbfl);

	/// ��ȡ���ê��
	static CString GetDjValue( const CString & strValue ,const double dValue);
	static CString GetMgValue( const CString & strValue ,const double dValue);

protected:
	static CSysData_InitMgOpr * m_pInstance;

	//
	CSysData_InitMgOpr() ;
	~CSysData_InitMgOpr() ; 

	//��ʼ��ê�̴��ֵ
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

	// �и���ֵ �����ݴ��淽ʽΪXX*d;XX*d;XX*d;
	//wrq [2017-1-16]
	static CString SplitDjValueList(const CString & strDjzList,const CString & strbfl);
};
