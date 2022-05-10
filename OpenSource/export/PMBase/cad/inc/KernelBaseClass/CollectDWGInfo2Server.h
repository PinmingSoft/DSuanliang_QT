#pragma once

#include "PmKernelFun.h"

// ����ʶ����Ϣ ����
class CSimDrawInfo
{
public:
	CSimDrawInfo();
	virtual ~CSimDrawInfo();

	enum DrawType
	{
		eGJInfo = 1,		//ʶ��ֽ����
		eLayerInfo = 2		//ʶ�𹹼���ͼ��
	};

	DrawType GetDrawType() const
	{
		return m_DrawType;
	}

	// ��ȡ Json��Ϣ
	virtual std::string GetJsonInfo();

protected:

	DrawType m_DrawType;
};

// �ַ�ʶ����Ϣ
class CSimDrawInfo_GJInfo : public CSimDrawInfo
{
public:
	CSimDrawInfo_GJInfo();
	virtual ~CSimDrawInfo_GJInfo();

	void SetGJInfo(const CString & strOriginText,const CString & strReplaceText);
	
	// ��ȡ Json��Ϣ
	virtual std::string GetJsonInfo();

protected:

	CString m_strOriginText;
	CString m_strReplaceText;
};

// ͼ��ʶ����Ϣ
class CSimDrawInfo_LayerInfo : public CSimDrawInfo
{
public:
	CSimDrawInfo_LayerInfo();
	virtual ~CSimDrawInfo_LayerInfo();

	void SetGJInfo(const CString & strProjectGUID,const CString & strProjectName,int iType,const CStringArray & strLayerArr);

	// ��ȡ Json��Ϣ
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
	  ���������� ����ͼ����Ϣ ��������
	  ������	const CString & strProjectGUID 
				const CString & strProjectName,
				int iType,
				const CStringArray & strLayerArr
	  �� �� ֵ��
	  �㷨��
	  ע�����
	  ��    �ߣ�����ҵ
	  ʱ    �䣺[2020 6 24   10:51]
	*****************************************************************/
	bool SendLayerInfo2Server(const CString & strProjectGUID,const CString & strProjectName,int iType,const CStringArray & strLayerArr);

	/****************************************************************
	  ���������� ���͸ֽ���Ϣ ��������
	  ������	const CString & strOriginText 
				const CString & strReplaceText,
	  �� �� ֵ��
	  �㷨��
	  ע�����
	  ��    �ߣ�����ҵ
	  ʱ    �䣺[2020 6 24   10:51]
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

	// ����һ�������� �̷߳���
	bool PullDrawInfo(CSimDrawInfo *& pSimDrawInfo);

protected:

	CSimDrawInfoArr m_SimDrawInfoArr;	//������Ϣ

	CString m_strIniFilePath;
	CRITICAL_SECTION m_ThreadSection;	//�ź�������
	static BOOL m_bThreadExit;			//�߳��˳����
	HANDLE m_CheckThreadHandle;			//�߳̾��
};
