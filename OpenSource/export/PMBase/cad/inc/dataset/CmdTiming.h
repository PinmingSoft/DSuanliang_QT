#pragma once
#include <map>
#include <atlstr.h>

class DATASETDLLEXPORT CCmdTiming
{
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
public:
	CCmdTiming(const CString& strTimeInfo);
	~CCmdTiming(void);
public:
	static void InitRecordDB(const CString& strProjectDir, const CString& strProjectName);
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
	void RecordTimeInfo(LONGLONG QuadPart);
private:
	LARGE_INTEGER StartingTime;		// 用来记录开始的时间
	LARGE_INTEGER EndingTime;		// 用来记录结束的时间
	CString m_strTimeInfo;			// 用来记录时间信息
private:
	static CString g_s_strDBPath;
	static BOOL g_s_bTimingOn;
};
