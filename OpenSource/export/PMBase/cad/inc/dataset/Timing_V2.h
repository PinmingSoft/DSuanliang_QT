#pragma once
#include <map>
#include <atlstr.h>

#define PP_CAT(a, b) PP_CAT_I(a, b)
#define PP_CAT_I(a, b) a ## b
#define UNIQUE_NAME(base) PP_CAT(base, __COUNTER__)
//是否启用时间测试的开关,屏蔽掉该定义就关闭了测试 
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
	*  @brief : 记录时间信息实时刷新到数据库文件
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
	*  @brief : 时间信息结构,用于存放时间信息
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
		DWORD dwThreadId;		// 记录线程ID
		LONGLONG ElapsedTime;	// 记录经过的时间
		int nTime;				// 记录运行的次数
	};

	/**
	*  @brief : 时间记录类,用于记录时间信息
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
		*  @brief : 用于添加时间信息
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
		*  @brief : 记录时间信息实时刷新到数据库文件
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
		*  @brief : 记录时间信息到数据库文件
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
	*  @brief : 进程锁类,用于进程间的同步
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
	*  @brief : 线程锁类,用于同步线程
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
		*  @brief : 利用关键段来实现线程锁
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
		static CCritical_Section m_g_cs;	// 用来同步进程内的各个线程
	};
private:
	LARGE_INTEGER StartingTime;		// 用来记录开始的时间
	LARGE_INTEGER EndingTime;		// 用来记录结束的时间
	CString m_strTimeInfo;			// 用来记录时间信息
private:
	static CTimeRecord m_g_TimeRecord;	// 用来记录进程中的所有时间信息
};
