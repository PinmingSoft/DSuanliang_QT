#pragma once
#include <Psapi.h>
#include <map>

#define PP_CAT(a, b) PP_CAT_I(a, b)
#define PP_CAT_I(a, b) a ## b
#define UNIQUE_NAME(base) PP_CAT(base, __COUNTER__)
//�Ƿ������ڴ���ԵĿ���,���ε��ö���͹ر��˲��� 
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
		DWORD dwThreadId;		// ��¼�߳�ID
		SIZE_T WorkingSetSize;	// ��¼���ĵ��ڴ�
		int nTime;				// ��¼���еĴ���
	};

	// �ڴ��¼��,���ڼ�¼�ڴ���Ϣ
	class CMemRecord
	{
	public:
		CMemRecord(void);
		~CMemRecord(void);
	public:
		// ��������ڴ���Ϣ
		void InsertMemInfo(const CString& strInfo, const SIZE_T& WorkingSetSize);
		// ��¼�ڴ���Ϣʵʱˢ�µ����ݿ��ļ�
		void RefreshRec2DB(void);
	private:
		// ��¼�ڴ���Ϣ�����ݿ��ļ�
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
	CString m_strMemInfo;					// ������¼�ڴ���Ϣ
	PROCESS_MEMORY_COUNTERS m_StartPMC;		// ������¼��ʼ���ڴ�״̬
	PROCESS_MEMORY_COUNTERS m_EndPMC;		// ������¼�������ڴ�״̬
private:
	static CMemRecord m_g_MemRecord;		// ������¼�����е������ڴ���Ϣ
};

