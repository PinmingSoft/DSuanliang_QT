#pragma once
#include <map>
#include <atlstr.h>

#define PP_CAT(a, b) PP_CAT_I(a, b)
#define PP_CAT_I(a, b) a ## b
#define UNIQUE_NAME(base) PP_CAT(base, __COUNTER__)
//�Ƿ�����ʱ����ԵĿ���,���ε��ö���͹ر��˲��� 
//#define TIMINGV2_ON
#ifdef TIMINGV2_ON
#define Timing_V2(s)  CTiming_V2 UNIQUE_NAME(time)(s)
#define Timing_Refresh CTiming_V2::RefreshRec2DB()
#else 
#define Timing_V2(s)
#define Timing_Refresh
#endif
class DATASETDLLEXPORT CTiming_V2
{
public:
	CTiming_V2(const CString& strTimeInfo);
	~CTiming_V2(void);
public:
	/**
	*  @brief : ��¼ʱ����Ϣʵʱˢ�µ����ݿ��ļ�
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2020/08/05 11:04:07 
	*/
	static void RefreshRec2DB(void);
private:
	/**
	*  @brief : ʱ����Ϣ�ṹ,���ڴ��ʱ����Ϣ
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2/7/2016 15:50 
	*/
	struct TimeInfo
	{
		TimeInfo(): ElapsedTime(0), nTime(0), dwThreadId(0)
		{

		}
		DWORD dwThreadId;		// ��¼�߳�ID
		LONGLONG ElapsedTime;	// ��¼������ʱ��
		int nTime;				// ��¼���еĴ���
	};

	/**
	*  @brief : ʱ���¼��,���ڼ�¼ʱ����Ϣ
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2/7/2016 15:50 
	*/
	class CTimeRecord
	{
	public:
		CTimeRecord(void);
		~CTimeRecord(void);
	public:
		/**
		*  @brief : �������ʱ����Ϣ
		*
		*
		*  @note
		*  @param : 
		*  @defenc: 
		*  @return: 
		*  @author: yjc
		*  @date  : 2/7/2016 15:55 
		*/
		void InsertTimeInfo(const CString& strInfo, const LONGLONG& ElapsedTime);
		/**
		*  @brief : ��¼ʱ����Ϣʵʱˢ�µ����ݿ��ļ�
		*
		*
		*  @note
		*  @param : 
		*  @defenc: 
		*  @return: 
		*  @author: yjc
		*  @date  : 2020/08/05 11:04:07 
		*/
		void RefreshRec2DB(void);
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
		void RecordTimeInfo(void);
	private:
		std::multimap<const CString, TimeInfo> m_g_mapTimeInfo;
	};

	/**
	*  @brief : ��������,���ڽ��̼��ͬ��
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2/7/2016 15:51 
	*/
	class CProcessLocker
	{
	public:
		CProcessLocker(void);
		~CProcessLocker();
	private:
		HANDLE m_hMutex;
	};

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
private:
	LARGE_INTEGER StartingTime;		// ������¼��ʼ��ʱ��
	LARGE_INTEGER EndingTime;		// ������¼������ʱ��
	CString m_strTimeInfo;			// ������¼ʱ����Ϣ
private:
	static CTimeRecord m_g_TimeRecord;	// ������¼�����е�����ʱ����Ϣ
};
