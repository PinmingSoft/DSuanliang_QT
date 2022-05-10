#pragma once


typedef BOOL SimRockeyV5_GetXml_CallBack(CString strSerialNumber,CString & strRockeyXMLInfo);

typedef BOOL SimRockeyV5_Update_CallBack(const CString & strSerialNumber,CString & strErrorResult);

class KERNELBASECLASS_API CRockeyUIOpr
{
public:
	CRockeyUIOpr(void);
	~CRockeyUIOpr(void);

	/**
	* @brief ��ȡ ������V5 ��ʾ�Ի���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/7/2017]
	*/
	BOOL DoShowRockeyV5InfoDlg(const CString & strRockeyInfo,SimRockeyV5_Update_CallBack * pUpdateCallBack, SimRockeyV5_GetXml_CallBack * pGetXmlCallBack);

	/**
	* @brief ��ȡ ��ƽ̨��¼ ��ʾ�Ի���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/7/2017]
	*/
	static BOOL DoCloudLogInfoDlg(CString & strUseName,CString & strPWD);
};
