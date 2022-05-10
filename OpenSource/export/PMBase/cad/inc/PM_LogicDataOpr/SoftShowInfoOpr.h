#pragma once

#define PMMB		

class PMLogicDataOprAPI CSoftShowTextInfoOpr
{
public:
	CSoftShowTextInfoOpr(void);
	virtual ~CSoftShowTextInfoOpr(void);
	/**
	* @brief 获取学习版提示信息       
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 戴闻刚
	* @date  : [2020/12/23]
	*/
	static CString GetLearningVersionMsg();

	/**
	* @brief 获取程序版本号
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/12/2012]
	*/
	static void GetProjectVer(CString & strMainVer,CString & strSubVer);

	/**
	* @brief 获取配置文件路径 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/12/2012]
	*/
	static CString GetConfigFilePath();

	/**
	* @brief  获取文件选择对话框 过滤文字 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/12/2012]
	*/
	static CString GetProjectFileDialog_Filter();

	/**
	* @brief  获取文件选择对话框 扩展名 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/12/2012]
	*/
	static CString GetProjectFileDialog_Ext();

	/**
	* @brief  获取文件选择对话框 显示文字 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/12/2012]
	*/
	static CString GetProjectFileDialog_SoftTxt();


	static CString GetFullSoftName();
	/**
	* @brief  获取MESSAGEBOX、Welcome、Loading对话框上 显示文字 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [5/12/2012]
	*/
	static CString GetSimSoftName();

	/**
	* @brief  子名称 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [5/12/2012]
	*/
	static CString GetCompanyLogName();

	/**
	* @brief  获取公司电话 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [5/12/2012]
	*/
	static CString GetCompanyTel();

	/**
	* @brief   获取公司电话 文字说明
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [7/1/2013]
	*/
	static CString GetCompanyTelInfo();

	/**
	* @brief  获取公司名称 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [5/12/2012]
	*/
	static CString GetCompanyName();

	/**
	* @brief  获取公司网址 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [5/12/2012]
	*/
	static CString GetCompanyURL();
	/**
	*  @brief : 获取支付地址
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/10/21 9:56
	*/
	CString GetPayURL();
	/**
	* @brief  zip压缩文件名称
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [5/12/2012]
	*/
	static CString GetProjectZip_Filter();
};

/**
* @brief  图片显示控制 
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: 王建业
* @date  : [7/12/2012]
*/
class PMLogicDataOprAPI CSoftShowPicInfoOpr
{
public:
	CSoftShowPicInfoOpr(void);
	virtual ~CSoftShowPicInfoOpr(void);

	/**
	* @brief 加载软件Ico  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [7/12/2012]
	*/
	static HICON GetSoftLogIcon(HINSTANCE temHInstance);

	/**
	* @brief 加载关于LOG
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [7/12/2012]
	*/
	static HBITMAP GetSoftLogBit( HINSTANCE temHInstance,CRect rect );
protected:

	static CString GetPicDirPath();
};

class PMLogicDataOprAPI CSoftLogicInfoOpr
{
public:
	CSoftLogicInfoOpr();
	virtual ~CSoftLogicInfoOpr();

	enum PMSoftType
	{
		eSLGJ_Master = 0,
		eSLGJ_HuNan = 1,
		eSLGJ_YunNan = 2,
	};
	/**
	* @brief  判断是否是 OEM版本 
	*
	*          
	* @note  : OEM合成信息控制方式
				主公司版本：SL_GJ|Master		4721c4f0fa22bb18224dfb90774c469a
				湖南版本：SL_GJ|HuNan			6562f0d0563e46a9bce080ea38752a47
				湖南版本：SL_GJ|YunNan			4e7d3c27c5b8de8a05f9e0e9a3a3697b
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [10/12/2012]
	*/
	static BOOL CheckIsOEMSoft();

	static PMSoftType GetSoftType();

	/**
	* @brief 获取配置文件路径 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/12/2012]
	*/
	static CString GetConfigFilePath();

	/**
	* @brief 获取项目工程的 软件编号  
	*
	*          
	* @note  : 用于区分 主算量 与OEM算量的 区别
				合成规则 软件的 SoftCode2|ProjectFile
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/12/2012]
	*/
	static CString GetSoftProjectCode();

	/**
	* @brief 判断 打开的 用户工程 是否是  逻辑可打开范围  
	*
	*          
	* @note  : 不能打开返回FALSE
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/12/2012]
	*/
	static BOOL CheckProjectSoftCode(const CString & strProjectCode);

protected:

	static const CString m_strSL_GJMaster;
	static const CString m_strSL_GJ_HuNan;
	static const CString m_strSL_GJ_YunNan;
};