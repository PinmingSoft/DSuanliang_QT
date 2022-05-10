#pragma once
#include <Psapi.h>
#include <map>

#define PP_CAT(a, b) PP_CAT_I(a, b)
#define PP_CAT_I(a, b) a ## b
#define UNIQUE_NAME(base) PP_CAT(base, __COUNTER__)
//是否启用内存测试的开关,屏蔽掉该定义就关闭了测试 
//#define MEMINFO_ON
#ifdef MEMINFO_ON
	#define MemRecord(s)  CMemInfo UNIQUE_NAME(time)(s)
	#define MemRecord_Refresh CMemInfo::RefreshRec2DB()
#else 
	#define MemRecord(s)
	#define MemRecord_Refresh
#endif

class DATASETDLLEXPORT CMemInfo
{
public:
	CMemInfo(const CString& strMemInfo);
	~CMemInfo(void);

	struct MemInfo
	{
		MemInfo(): WorkingSetSize(0), nTime(0), dwThreadId(0)
		{

		}
		DWORD dwThreadId;		// 记录线程ID
		SIZE_T WorkingSetSize;	// 记录消耗的内存
		int nTime;				// 记录运行的次数
	};

	// 内存记录类,用于记录内存信息
	class CMemRecord
	{
	public:
		CMemRecord(void);
		~CMemRecord(void);
	public:
		// 用于添加内存信息
		void InsertMemInfo(const CString& strInfo, const SIZE_T& WorkingSetSize);
		// 记录内存信息实时刷新到数据库文件
		void RefreshRec2DB(void);
	private:
		// 记录内存信息到数据库文件
		void RecordMemInfo(void);
	private:
		std::multimap<const CString, MemInfo> m_g_mapMemInfo;
	};

	class CProcessLocker
	{
	public:
		CProcessLocker(void);
		~CProcessLocker();
	private:
		HANDLE m_hMutex;
	};

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
	CString m_strMemInfo;					// 用来记录内存信息
	PROCESS_MEMORY_COUNTERS m_StartPMC;		// 用来记录开始的内存状态
	PROCESS_MEMORY_COUNTERS m_EndPMC;		// 用来记录结束的内存状态
private:
	static CMemRecord m_g_MemRecord;		// 用来记录进程中的所有内存信息
};

