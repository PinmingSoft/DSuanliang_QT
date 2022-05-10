// PMRegeditControl.h: interface for the CPMRegeditControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMREGEDITCONTROL_H__05D206F7_F4A1_4F5E_AA45_F711FE5BD5CF__INCLUDED_)
#define AFX_PMREGEDITCONTROL_H__05D206F7_F4A1_4F5E_AA45_F711FE5BD5CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PMLogicDataOprAPI CPMRegeditControl  
{
public:
	enum RegRoot
	{CLASSES_ROOT,CURRENT_USER,LOCAL_MACHINE,USERS};
	CPMRegeditControl();
	virtual ~CPMRegeditControl();
	
 	static CString m_strCADProfilesRegPath;
 	static CString m_strCADExeRegPath;
	static CString m_strPMCADRegPath;
	static CString m_strPMCADSXSZRegPath;
// 	CString m_strCADProfilesRegPath;
// 	CString m_strCADExeRegPath;
	
	/******************************************************************** 
	 ����������ɾ��ָ�� ע���� �Ӽ�
	
	
	         _   _
	        (q\_/p)
	    .-.  |. .|
	       \ =\,/=
	        )/ _ \  |\
	       (/\):(/\  )\
	        \_   _/ |Oo\
	        `""^""` `"""`
	
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[7/6/2010]
	*********************************************************************/ 
	BOOL DelSubRegKey(RegRoot root,CString strKey);

	/******************************************************************** 
	 ������������ȡ��ǰCADƽ̨�£�����߰汾ע���·��
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[30/12/2008]
	*********************************************************************/ 
	BOOL GetCADMaxRegVersion(CString strMainRegPath,CString & strNewRegPath);
	
	/******************************************************************** 
	 ������������ȡע���ָ����ֵ
	 ������Key:ע����������� strKey:��·�����ƣ�strName:�����ƣ�strValue������ֵ���ַ�����
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[3/11/2007]
	*********************************************************************/ 
	BOOL GetRegValue(RegRoot root,CString strKey,CString strName,CString & strValue);
	/******************************************************************** 
	 ����������д��ע���ָ����ֵ
	 ������Key:ע����������� strKey:��·�����ƣ�strName:�����ƣ�strValue��ֵ���ַ�����
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[3/11/2007]
	*********************************************************************/
	void SetRegValue(RegRoot root,CString strKey,CString strName,CString strValue);
private:

	/******************************************************************** 
	 ������������ȡ��� ���
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[9/1/2009]
	*********************************************************************/ 
	int GetSoftCode();
};

#endif // !defined(AFX_PMREGEDITCONTROL_H__05D206F7_F4A1_4F5E_AA45_F711FE5BD5CF__INCLUDED_)
