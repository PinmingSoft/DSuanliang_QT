// CalUnitManager.h: interface for the CCalUnitManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALUNITMANAGER_H__01498D77_FDF3_4873_AA89_9C575EA9FD67__INCLUDED_)
#define AFX_CALUNITMANAGER_H__01498D77_FDF3_4873_AA89_9C575EA9FD67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/******************************************************************** 
 �������������е�λ�������ⵥλ�ķ���
 ������
 �� �� ֵ��
 �㷨��
 ע�����
 ��    �ߣ�����ҵ
 ʱ    �䣺[20/8/2008]
*********************************************************************/ 

class PMLogicDataOprAPI CCalUnitManager  
{
public:

	/****************************************************************
	  ����������	 ������ⵥλ ���� �߹������湹�� ֧�ֵ�λ ����Ҫ����ʾ
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2011:3:14   10:40]
	*****************************************************************/
	BOOL CheckSpecComType_Unit(int iComType,CString strUnit);

	/// 
	BOOL RevertUnit( const CString &strOldUnit , CString &strNewUnit , double & dValue ) ;

	double RevertQuantity( CString strGcl , CString strUnit );

	/******************************************************************** 
	 �������������㵥λ��Ϣ
	 ������CString strUnit:Ҫ�����ĵ�λ,CStringArray & AllowUnitArr������ĵ�λ����,int & iCalMode������ʽ, double &dSpecValue������ϵ��
	 �� �� ֵ��
	 �㷨��
	 ע�����iCalMode��0���� 1���� 2���� 3����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[20/8/2008]
	*********************************************************************/ 
	CString CalUnitInfo(CString strUnit,CStringArray & AllowUnitArr,int & iCalMode, double &dSpecValue);
	
	/******************************************************************** 
	 �����������жϵ�λ�Ƿ�Ϸ�
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[6/4/2010]
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
	 ��������������λ��Ϊ�����ĵ�λ
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[29/9/2009]
	*********************************************************************/ 
	CString TransUnit1(CString strUnit);
	
	void InitUnitTran();
};

#endif // !defined(AFX_CALUNITMANAGER_H__01498D77_FDF3_4873_AA89_9C575EA9FD67__INCLUDED_)
