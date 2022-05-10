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
	 功能描述：删除指定 注册表的 子键
	
	
	         _   _
	        (q\_/p)
	    .-.  |. .|
	       \ =\,/=
	        )/ _ \  |\
	       (/\):(/\  )\
	        \_   _/ |Oo\
	        `""^""` `"""`
	
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[7/6/2010]
	*********************************************************************/ 
	BOOL DelSubRegKey(RegRoot root,CString strKey);

	/******************************************************************** 
	 功能描述：获取当前CAD平台下，得最高版本注册表路径
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[30/12/2008]
	*********************************************************************/ 
	BOOL GetCADMaxRegVersion(CString strMainRegPath,CString & strNewRegPath);
	
	/******************************************************************** 
	 功能描述：读取注册表指定键值
	 参数：Key:注册表主键名称 strKey:键路径名称，strName:键名称，strValue：返回值（字符串）
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[3/11/2007]
	*********************************************************************/ 
	BOOL GetRegValue(RegRoot root,CString strKey,CString strName,CString & strValue);
	/******************************************************************** 
	 功能描述：写入注册表指定键值
	 参数：Key:注册表主键名称 strKey:键路径名称，strName:键名称，strValue：值（字符串）
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[3/11/2007]
	*********************************************************************/
	void SetRegValue(RegRoot root,CString strKey,CString strName,CString strValue);
private:

	/******************************************************************** 
	 功能描述：获取软件 编号
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[9/1/2009]
	*********************************************************************/ 
	int GetSoftCode();
};

#endif // !defined(AFX_PMREGEDITCONTROL_H__05D206F7_F4A1_4F5E_AA45_F711FE5BD5CF__INCLUDED_)
