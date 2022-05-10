#pragma once


typedef BOOL SimRockeyV5_GetXml_CallBack(CString strSerialNumber,CString & strRockeyXMLInfo);

typedef BOOL SimRockeyV5_Update_CallBack(const CString & strSerialNumber,CString & strErrorResult);

class KERNELBASECLASS_API CRockeyUIOpr
{
public:
	CRockeyUIOpr(void);
	~CRockeyUIOpr(void);

	/**
	* @brief 获取 加密锁V5 显示对话框
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/7/2017]
	*/
	BOOL DoShowRockeyV5InfoDlg(const CString & strRockeyInfo,SimRockeyV5_Update_CallBack * pUpdateCallBack, SimRockeyV5_GetXml_CallBack * pGetXmlCallBack);

	/**
	* @brief 获取 云平台登录 显示对话框
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/7/2017]
	*/
	static BOOL DoCloudLogInfoDlg(CString & strUseName,CString & strPWD);
};
