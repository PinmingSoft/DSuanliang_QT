// Timing.h: interface for the CTiming class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMING_H__1B5079C5_8A63_4E1B_B164_115388BAC23B__INCLUDED_)
#define AFX_TIMING_H__1B5079C5_8A63_4E1B_B164_115388BAC23B__INCLUDED_
// ***************************************************************
//  Timing   version:  1.0   ? date: 02/26/2008
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2008 - All Rights Reserved
//  ����:clz
// ***************************************************************
// �ļ�˵��:ʱ��ⶨ��
//
//==============================ʹ��˵��========================
//	����ʹ�ú� ,��release���Զ�ȥ��ʱ����Դ���,
//	�Ѿ���������Ͳ鿴���������: timing ,���������÷�����������
//	�������������ѡ�����:
//	1:�Ƿ���ձ���Ľ��?ֱ����������ѡ��
//	2:�Ƿ�����Ѿ�����Ľ��?�������ļ�c:\TimingSet.ini������
//
//	���ֱ���ڴ�����Ƕ��CTiming ����,��Ѹö�����������ں�����ڴ�.
//	һ��Ĭ��ʹ��ֻ��Ҫʹ�� DEFAULT_TIMING ��
// ***************************************************************
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <map>

//ȫ��Ĭ�ϲ���
#ifdef  _DEBUG
#define DEFAULT_TIMING(strFunName) \
CTiming OneFunTimeing(strFunName);
#else
#define DEFAULT_TIMING(strFunName) 
#endif

#ifdef  _DEBUG
#define _TIMING_1(strFunName,bAddUp) \
CTiming OneFunTimeing_1(strFunName, bAddUp);
#else
#define _TIMING_1(strFunName,bAddUp) 
#endif


#ifdef  _DEBUG
#define _TIMING_2(strFunName,bAddUp,strBelong) \
CTiming OneFunTimeing_2(strFunName,bAddUp,strBelong);
#else
#define _TIMING_2(strFunName,bAddUp,strBelong) 
#endif

//����ĳһ��������ʱ�亯��
#ifdef  _DEBUG
	#define _TIMING_TOTAL(strFunName,bAddUp,strBelong) \
		CTiming OneFunTimeing_3(strFunName,bAddUp,strBelong,true);
#else
	#define _TIMING_TOTAL(strFunName,bAddUp,strBelong) 
#endif

//�����ֶβ��Ժ�
#ifdef _DEBUG 
#define	_BEGIN_SEG_TIMING(nSegTag,strFunName,bAddUp,strBelong) \
			CTiming *pNewObj##nSegTag = NULL;\
					{\
					static CString str1 = #nSegTag;\
					static CString str2 = str1 + strFunName;\
					pNewObj##nSegTag = new CTiming(str2,bAddUp,strBelong);\
					}\


#define  _END_SEG_TIMING(nSegTag) \
			if (pNewObj##nSegTag != NULL)\
			{\
				delete pNewObj##nSegTag ;\
				pNewObj##nSegTag = NULL;\
			}
#else

#define  _BEGIN_SEG_TIMING(SegTag,strFunName,bAddUp,strBelong)
#define  _END_SEG_TIMING(SegTag)

#endif



//�Ƿ�����ʱ����ԵĿ���,���ε��ö���͹ر��˲��� 
#define INSERT_TIME_CODE
#ifdef INSERT_TIME_CODE
	#define TIME_CODE(code_seg){code_seg}
#else 
	#define TIME_CODE(code_seg){}
#endif

const CString QUAN_JU_TIMING = _T("ȫ��ͳ��");//ȫ��ͳ��

// ����������ʱ��ⶨ,����ͳ�Ƶ�����������ʱ��
// �㷨�� 
// ע��������з�����û�з���ֵ.
// ������
// �� �� ֵ��
// ��    �ߣ�������
// ʱ    �䣺[26/2/2008]
class PMBASECLASSOPRAPI CTiming  
{
public:
	//ʹ�ú�������,��Ӧ��ӡ����
	// ����������strFunNameʹ�ú�����,���ڱ�ʶ��ʲô��ʱ,
	//			bAddUp��ʶ�ڶ���ظ�����ʱ�Ƿ���ͳ�ƻ���ֻͳ��һ��,	Ĭ���ǲ��ö��ͳ��
	//			strBelong��ʶ������˭����,Ĭ��ȡȫ��,Ŀ�����ڿ�������Լ���ͳ�ƽ������Ӱ�����
	//			bIsTatolTimeRecord ��ʾ�Ƿ��Ǹñ��ȫ��ʱ��.�������ʱ��,��ô����ʹ�ø��������ۼӵõ���ʱ��
	//			һ����Ӧ�����ֻ����һ�������͵ļ�¼,�������
	// �㷨�� 
	// ע�����
	// ������
	// �� �� ֵ��
	// ��    �ߣ�������
	// ʱ    �䣺[26/2/2008]
	CTiming(const CString &strFunName, bool bAddUp = true, const CString &strBelong = QUAN_JU_TIMING, bool bIsTatolTimeRecord = false);
	virtual ~CTiming();
	
	// �����������Ƿ�����ۼ�ͳ��
	// �㷨�� 
	// ע������ۼ���Ŀ����������ô���,��ʱ��
	//				�������Ϊ������Ļ�,��ֻͳ��һ�ε��û��ѵ�ʱ��
	// ������
	// �� �� ֵ��
	// ��    �ߣ�������
	// ʱ    �䣺[26/2/2008]
	void SetAddUp(bool bAddUp){m_bAddUp = bAddUp;};

	// �������������ý������
	// �㷨�� 
	// ע�����
	// ������
	// �� �� ֵ��
	// ��    �ߣ�������
	// ʱ    �䣺[26/2/2008]
	void SetBelong(const CString &strBlong){m_strBelong = strBlong;};

	// ������������ǰ����ʱ��,��������ʱ��������
	// �㷨�� 
	// ע�����
	// ������
	// �� �� ֵ��
	// ��    �ߣ�������
	// ʱ    �䣺[9/2/2009]
	BOOL CountTime();

private:
	BOOL m_bHasCount;//�Ƿ��Ѿ���ʱ����

private:
	CString m_strKey;//������
	DWORD m_BeginTime;//��ʼʱ��
	DWORD m_EndTime;
	bool m_bAddUp;//�Ƿ���Ҫͳ��
	bool m_bIsTatolTimeRecord;//�Ƿ��Ǹñ��ȫ����ʱ��

	CString m_strBelong;//������Χ,��������˭������,�����ֲ���ģ��
};

//������Լ�¼
class PMBASECLASSOPRAPI CRecord
{
	struct FunInfo_T //������Ϣ
	{
		DWORD nCount;//���ô���
		DWORD nTotalTime;
		bool bAddUp;//�Ƿ���ͳ��
		bool bIsTatolTimeRecord;//�Ƿ���ȫ��ʱ��ļ�¼
		FunInfo_T(DWORD nC = 0, DWORD nT = 0, bool bA = true, bool bIsTR = false):nCount(nC),nTotalTime(nT),bAddUp(bA),bIsTatolTimeRecord(bIsTR){;};
	};
	//����ͳ�ƽ��
	typedef std::map<CString, FunInfo_T>Table_T;//����һ����λ�Ĳ��Ա�����,��������ӳ��
	typedef std::map<CString, Table_T>AllTable_T;//���еĲ�������

public:

	//������м�¼
	static void ClearAll();

	//���ָ��������м�¼
	static void ClearTable(const CString &strTableKey);

	//�õ��ܱ�ͷ
	static BOOL GetZbt(CString &strZbt);


protected:

	friend class CTiming;
	friend class COutPutMessage;
	// ��������������һ����¼
	// �㷨�� 
	// ע�������Ĳ������ֻ����CTimingʹ��
	// ������
	// �� �� ֵ��
	// ��    �ߣ�������
	// ʱ    �䣺[26/2/2008]
	static BOOL AddRecord(const CString &strTableKey, const CString &strFunKey, DWORD Time, bool bAddUp, bool bIsTatolTimeRecord);
	
	CRecord(){;};
	~CRecord(){;};

	//ͳ��һ�ű��д���,��ʱ��, ƽ��ʱ��
	static void CountTable(Table_T &aTable, DWORD &nTotalCs, DWORD &nTotalTime, DWORD &nPjsj);

	//ͳ�ƶ��ű��д���,��ʱ��, ƽ��ʱ��
	static void CountTable(AllTable_T &aTable, DWORD &nTotalCs, DWORD &nTotalTime, DWORD &nPjsj);

private:
	static AllTable_T s_AllTable;

	static DWORD s_nTotalCount;//�ܵĵ��ô���
};


//�����Ϣ,���������ض���,�����Ҫ���¶������Ŀ��,�����ظ���,��ʵ�������麯��
//��ʱ��������֧��!

//ʵ��Ϊ������ļ�
class PMBASECLASSOPRAPI COutPutMessage
{
public:
	COutPutMessage();
	virtual ~COutPutMessage(){;};

	//�����Ϣ
	BOOL PrintRecord();
protected:
	
	//���Ŀ���������
	virtual BOOL Clear();
	
	BOOL AppendFileContent(const CString & strFilePath,const CString & strAppendInfo);

	//����һ��
	virtual BOOL AddOneLine(const CString &strOneLineContext);

	//��ʾ����
	virtual void Show();

private:

	CString m_strFilePath;
};

//ʱ�������ص�ѡ��������
class PMBASECLASSOPRAPI CTimingSet
{
public:
	static CTimingSet *Instance();
	static void Release();

	// ������������Ϣ����Ƿ���׷��ģʽ,�������,��ô�ϴε������Ŀ������ݻᱻ���.
	// �㷨�� 
	// ע�����
	// ������
	// �� �� ֵ��
	// ��    �ߣ�������
	// ʱ    �䣺[27/2/2008]
	BOOL IsSuperadditionMode();

	//����׷��ģʽ
	BOOL SetSuperadditionMode(BOOL bSuperaddition);
protected:
	CTimingSet(){m_strTimingIniFilePath = _T("c:\\TimingSet.ini"); memset(m_chBuf, 0, 100);};
	~CTimingSet(){;};

	//���ú�ȡ��ֵ
	BOOL SetKeyAndValue(const CString &strKey, int nValue);
	BOOL GetKeyAndValue(const CString &strKey, int &nValue);

	static const CString strBoolDefault;//����ֵĬ��
	static const CString APP_NAME;//
	static const CString SuperadditionMode;//׷��ģʽ
	static const int BUF_SIZE;
private:
	TCHAR m_chBuf[100];
	CString m_strTimingIniFilePath;

	static CTimingSet *s_pTimingSet;
};

#endif // !defined(AFX_TIMING_H__1B5079C5_8A63_4E1B_B164_115388BAC23B__INCLUDED_)
