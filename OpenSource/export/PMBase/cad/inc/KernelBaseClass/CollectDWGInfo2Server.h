#pragma once

#include "PmKernelFun.h"

// 基础识别信息 基类
class CSimDrawInfo
{
public:
	CSimDrawInfo();
	virtual ~CSimDrawInfo();

	enum DrawType
	{
		eGJInfo = 1,		//识别钢筋符号
		eLayerInfo = 2		//识别构件的图层
	};

	DrawType GetDrawType() const
	{
		return m_DrawType;
	}

	// 获取 Json信息
	virtual std::string GetJsonInfo();

protected:

	DrawType m_DrawType;
};

// 字符识别信息
class CSimDrawInfo_GJInfo : public CSimDrawInfo
{
public:
	CSimDrawInfo_GJInfo();
	virtual ~CSimDrawInfo_GJInfo();

	void SetGJInfo(const CString & strOriginText,const CString & strReplaceText);
	
	// 获取 Json信息
	virtual std::string GetJsonInfo();

protected:

	CString m_strOriginText;
	CString m_strReplaceText;
};

// 图层识别信息
class CSimDrawInfo_LayerInfo : public CSimDrawInfo
{
public:
	CSimDrawInfo_LayerInfo();
	virtual ~CSimDrawInfo_LayerInfo();

	void SetGJInfo(const CString & strProjectGUID,const CString & strProjectName,int iType,const CStringArray & strLayerArr);

	// 获取 Json信息
	virtual std::string GetJsonInfo();

protected:

	CString m_strProjectGUID;
	CString m_strProjectName;
	int m_iType;
	CStringArray m_strLayerNameArr;
};

typedef PmArray<CSimDrawInfo*>  CSimDrawInfoArr;

class KERNELBASECLASS_API CCollectDWGInfo2Server
{
public:

	CCollectDWGInfo2Server(const CString & strIniFilePath);
	~CCollectDWGInfo2Server(void);
	
	/****************************************************************
	  功能描述： 发送图层信息 给服务器
	  参数：	const CString & strProjectGUID 
				const CString & strProjectName,
				int iType,
				const CStringArray & strLayerArr
	  返 回 值：
	  算法：
	  注意事项：
	  作    者：王建业
	  时    间：[2020 6 24   10:51]
	*****************************************************************/
	bool SendLayerInfo2Server(const CString & strProjectGUID,const CString & strProjectName,int iType,const CStringArray & strLayerArr);

	/****************************************************************
	  功能描述： 发送钢筋信息 给服务器
	  参数：	const CString & strOriginText 
				const CString & strReplaceText,
	  返 回 值：
	  算法：
	  注意事项：
	  作    者：王建业
	  时    间：[2020 6 24   10:51]
	*****************************************************************/
	bool SendGJInfo2Server(const CString & strOriginText,const CString & strReplaceText);

	static BOOL GetThreadExit()
	{
		return m_bThreadExit;
	}

	CString GetIniFilePath() const
	{
		return m_strIniFilePath;
	}

	// 推送一个工作给 线程发送
	bool PullDrawInfo(CSimDrawInfo *& pSimDrawInfo);

protected:

	CSimDrawInfoArr m_SimDrawInfoArr;	//绘制信息

	CString m_strIniFilePath;
	CRITICAL_SECTION m_ThreadSection;	//信号量控制
	static BOOL m_bThreadExit;			//线程退出标记
	HANDLE m_CheckThreadHandle;			//线程句柄
};
