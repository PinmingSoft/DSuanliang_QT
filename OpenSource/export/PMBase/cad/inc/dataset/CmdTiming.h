#pragma once
#include <map>
#include <atlstr.h>

class DATASETDLLEXPORT CCmdTiming
{
	/**
	*  @brief : �߳�����,����ͬ���߳�
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2/7/2016 15:52 
	*/
	class CThreadLocker
	{
	public:
		CThreadLocker(void);
		~CThreadLocker();

		/**
		*  @brief : ���ùؼ�����ʵ���߳���
		*
		*
		*  @note
		*  @param : 
		*  @defenc: 
		*  @return: 
		*  @author: yjc
		*  @date  : 2/7/2016 15:53 
		*/
		class CCritical_Section
		{
		public:
			CCritical_Section(void);
			~CCritical_Section();
		public:
			CRITICAL_SECTION m_cs;
		};
	private:
		static CCritical_Section m_g_cs;	// ����ͬ�������ڵĸ����߳�
	};
public:
	CCmdTiming(const CString& strTimeInfo);
	~CCmdTiming(void);
public:
	static void InitRecordDB(const CString& strProjectDir, const CString& strProjectName);
private:
	/**
	*  @brief : ��¼ʱ����Ϣ�����ݿ��ļ�
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2/7/2016 15:55 
	*/
	void RecordTimeInfo(LONGLONG QuadPart);
private:
	LARGE_INTEGER StartingTime;		// ������¼��ʼ��ʱ��
	LARGE_INTEGER EndingTime;		// ������¼������ʱ��
	CString m_strTimeInfo;			// ������¼ʱ����Ϣ
private:
	static CString g_s_strDBPath;
	static BOOL g_s_bTimingOn;
};
