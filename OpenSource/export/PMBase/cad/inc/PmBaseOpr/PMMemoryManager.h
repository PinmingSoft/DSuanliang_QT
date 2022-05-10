// PMMemoryManager.h: interface for the CPMMemoryManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMMEMORYMANAGER_H__A796C352_6F35_4E36_8C2C_D76A8C343F11__INCLUDED_)
#define AFX_PMMEMORYMANAGER_H__A796C352_6F35_4E36_8C2C_D76A8C343F11__INCLUDED_

#include "PmArxVersion.h"
#if _MSC_VER <= PMVC2008_VER	// vc2008
#include "boost/smart_ptr.hpp"
#else
#include <memory>
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef _TESTMEMORY
	#define PMCheckSpecMemoryLive(TYPE,ShowMsgBox)		CPMMemoryManager::Instance()->CheckSpecMemoryLine(TYPE,ShowMsgBox)
	#define PMAddSpecMemory(TYPE)			CPMMemoryManager::Instance()->AddSpecMemory(TYPE)
	#define PMNewCArray(TYPE)				(CArray<TYPE,TYPE&> *)(CPMMemoryManager::Instance()->AddMemoryInfo(new CArray<TYPE,TYPE&>,__FILE__,__LINE__))
	#define PMNewAcArray(TYPE)				(AcArray<TYPE> *)(CPMMemoryManager::Instance()->AddMemoryInfo(new AcArray<TYPE>,__FILE__,__LINE__))
	#define PMNew(TYPE)						(TYPE*)(CPMMemoryManager::Instance()->AddMemoryInfo(new TYPE,__FILE__,__LINE__))
	#define PMNew_Parm(TYPE,Parm)			(TYPE*)(CPMMemoryManager::Instance()->AddMemoryInfo(new TYPE Parm,__FILE__,__LINE__))
	#define PMRegMemory(TYPE)				CPMMemoryManager::Instance()->AddMemoryInfo(TYPE,__FILE__,__LINE__)
	#define PMUnregMemory(TYPE)				CPMMemoryManager::Instance()->RemoveMemoryInfo(TYPE,__FILE__,__LINE__)
	#define PMDelete(TYPE)					{CPMMemoryManager::Instance()->RemoveMemoryInfo(TYPE,__FILE__,__LINE__);delete TYPE;TYPE=NULL;}
	#define PMDeleteVoid(TYPE,Value)		{CPMMemoryManager::Instance()->RemoveMemoryInfo(Value,__FILE__,__LINE__);delete (TYPE)Value;Value=NULL;}
	#define PMDeletePBYTE(Value)			{CPMMemoryManager::Instance()->RemoveMemoryInfo(Value,__FILE__,__LINE__);delete [](BYTE*)Value;Value=NULL;}
	#define PMShowLeaks						CPMMemoryManager::Instance()->ShowMemoryLeak()
	#define PMFreeLeaks						CPMMemoryManager::Instance()->ClearMemoryInfo()
#else
	#define PMCheckSpecMemoryLive(TYPE,ShowMsgBox)		TRUE	
	#define PMAddSpecMemory(TYPE)			TRUE
	#define PMNewCArray(TYPE)				new CArray<TYPE,TYPE&>
	#define PMNewAcArray(TYPE)				new AcArray<TYPE>
	#define PMNew(TYPE)						new TYPE
	#define PMNew_Parm(TYPE,Parm)			new TYPE Parm
	#define PMRegMemory(TYPE)
	#define PMUnregMemory(TYPE)			
	#define PMDelete(TYPE)					{delete TYPE;(TYPE)=NULL;}
	#define PMDeleteVoid(TYPE,Value)		{delete (TYPE)Value;Value=NULL;}
	#define PMDeletePBYTE(Value)			{delete [](BYTE*)Value;Value=NULL;}
	#define PMShowLeaks		
	#define PMFreeLeaks
#endif

//定义智能指针
#if _MSC_VER <= PMVC2008_VER	// vc2008
#define PMShared_Ptr						boost::shared_ptr
#else
#define PMShared_Ptr						std::shared_ptr
#endif

//
#define PMNewShared_Ptr(TYPE)				PMShared_Ptr<TYPE>(new TYPE)
#define PMNewShared_Ptr2(TYPE,Parm)			PMShared_Ptr<TYPE>(new TYPE Parm)

//内存异常派生
class PMBASECLASSOPRAPI CPMMemoryManagerException : public CException
{

};

/**
* @brief 内存监视 实现类  
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: 王建业
* @date  : [15/1/2014]
*/
class PMBASECLASSOPRAPI CPMMemoryManager  
{
public:

	BOOL CheckSpecMemoryLine(LPVOID pMemoryAddr,BOOL bShowMsgBox);

	void ClearMemoryInfo();
	void ShowMemoryLeak();

	BOOL AddSpecMemory(LPVOID pMemoryAddr);

	LPVOID AddMemoryInfo(LPVOID pMemoryAddr,const char * cFilePath,int iLine);

	void RemoveMemoryInfo(LPCVOID pMemoryAddr,const char * cFilePath,int iCurLine);

	class CPMFileInfo
	{
	public:
		CPMFileInfo(BOOL bNeedDel,const char * cFilePath,int iLine);
		virtual ~CPMFileInfo();

		const char * GetFilePath() const {return m_cFilePath;}

		int GetFileLine() const {return m_iFileLine;}

	protected:
		
		char * m_cFilePath;
		int m_iFileLine;
		BOOL m_bNeedDel;
	};

	class CPMNewMemoryInfo
	{
	public:

		CPMNewMemoryInfo(LPCVOID pMemoryAddr,const CPMFileInfo * pFileInfo);
		
		CPMNewMemoryInfo(CPMNewMemoryInfo * pMemoryInfo);
		virtual ~CPMNewMemoryInfo();

		const CPMFileInfo * GetFileInfo(){return m_pFileInfo;} 

		const char * GetFilePath(){return m_pFileInfo->GetFilePath();}

		int GetFileLine(){return m_pFileInfo->GetFileLine();}

		LPCVOID GetMemoryAddr(){return m_pMemoryAddr;}

		int GetNewCount(){return m_iNewCount;}
		void SetNewCount(int iNewCount){m_iNewCount = iNewCount;}

	protected:

		int m_iNewCount;
		LPCVOID m_pMemoryAddr;
		
		const CPMFileInfo * m_pFileInfo;
	};

	class CPMSpecMemoryLogInfo
	{
	public:
		CPMSpecMemoryLogInfo();
		virtual ~CPMSpecMemoryLogInfo();

		CPMNewMemoryInfo * GetYMemoryInfo(){return m_pYMemoryInfo;}
		void SetYMemoryInfo(CPMNewMemoryInfo * pMemoryInfo){m_pYMemoryInfo = pMemoryInfo;}

		CPMNewMemoryInfo * GetDMemoryInfo(){return m_pDMemoryInfo;}
		void SetDMemoryInfo(CPMNewMemoryInfo * pMemoryInfo){m_pDMemoryInfo = pMemoryInfo;}

	protected:
		CPMNewMemoryInfo * m_pYMemoryInfo;
		CPMNewMemoryInfo * m_pDMemoryInfo;
	};
	
	struct PMFileInfoCmpIter 
	{ 
		inline bool operator()(const CPMFileInfo * pFileInfo1,const CPMFileInfo * pFileInfo2)  const
		{
			if (pFileInfo1 == NULL ||pFileInfo2==NULL)
			{
				return false;
			}
			int iCmp = strcmp(pFileInfo1->GetFilePath(),pFileInfo2->GetFilePath());
			if(0 != iCmp)
			{
				if(iCmp < 0)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			return pFileInfo1->GetFileLine() < pFileInfo2->GetFileLine(); 
		} 
	}; 


	static CPMMemoryManager * Instance()
	{
		if(NULL == m_pInstance)
		{
			m_pInstance = new CPMMemoryManager;	
		}
		return m_pInstance;
	}

	static void Release()
	{
		if(NULL != m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}
	BOOL AppendCString2File(const CString & strFilePath,const CString & strAppendInfo);

	/// 记录sql的日志
	BOOL AppendSqlLog2File( const CString & strSql ) ;

	//是否登记内存
	inline BOOL IsRecordMem()
	{
		return m_bIsRecordMem;
	}

protected:
	
	CPMMemoryManager();
	virtual ~CPMMemoryManager();

	static CPMMemoryManager * m_pInstance;

	BOOL m_bIsRecordMem;		//是否进行内存登记
	CString m_strMemoryLogFilePath;
	
	BOOL GetCodeFileInfo(const char * cFilePath,int iLine,CPMFileInfo *& pCodeFileInfo,int & iNewCount);

	typedef std::map<LPCVOID,CPMNewMemoryInfo*> AddrMapMemoryInfo_T;
	AddrMapMemoryInfo_T m_MapMemoryInfo;

	typedef std::map<LPCVOID,CPMSpecMemoryLogInfo*> AddrMapSepcMemoryInfo_T;
	AddrMapSepcMemoryInfo_T m_MapSpecMemoryInfo;
		
	typedef std::map<CPMFileInfo *,int,PMFileInfoCmpIter>	FileLineInfoMapNewCount_T;
	FileLineInfoMapNewCount_T m_MapNewCount;

	CRITICAL_SECTION m_LockCriticalSection;
};
// 
// /****************************************************************
//   功能描述：做为 内存 缓存的 基础 接口
// 	参数：
// 	返 回 值：
// 	算法：在 需要的时候 可以 被 管理类 释放 指定 级别的 内存
// 			级别 越高 对 内存 压力 越大。
// 	注意事项：
// 	作    者：王建业
// 	时    间：[2011:3:25   17:47]
// *****************************************************************/
// class PMBASECLASSOPRAPI CPMMemoryCache
// {
// public:
// 
// 	enum CacheMode
// 	{
// 		LowLevel = 1,//低等级
// 		NormalLevel = 2,//普通级别
// 		HighLevel = 3,//高级别
// 		VeryHighLevel = 4//严重
// 	};
// 
// 	CPMMemoryCache();
// 	virtual ~CPMMemoryCache();
// 
// 	/****************************************************************
// 	  功能描述：获取 缓存的 等级
// 		参数：
// 		返 回 值：
// 		算法：
// 		注意事项：
// 		作    者：王建业
// 		时    间：[2011:3:25   18:09]
// 	*****************************************************************/
// 	CPMMemoryCache::CacheMode GetMemoryCacheMode();
// 
// 	/****************************************************************
// 	  功能描述：用于释放 内存 缓冲
// 		参数：
// 		返 回 值：
// 		算法：
// 		注意事项：
// 		作    者：王建业
// 		时    间：[2011:3:25   17:47]
// 	*****************************************************************/
// 	virtual int ReleaseCache() = 0;
// 
// protected:
// 
// 	CacheMode m_PMMemoryCacheMode;//内存缓存的 级别
// };
// 
// 
// class PMBASECLASSOPRAPI CPMMemoryCacheManager
// {
// public:
// 	static CPMMemoryCacheManager * Instance()
// 	{
// 		if(NULL == m_pInstance)
// 		{
// 			m_pInstance = new CPMMemoryCacheManager;	
// 		}
// 		return m_pInstance;
// 	}
// 
// 	static void Release()
// 	{
// 		if(NULL != m_pInstance)
// 		{
// 			delete m_pInstance;
// 			m_pInstance = NULL;
// 		}
// 	}
// 
// 	/****************************************************************
// 	  功能描述：加入内存管理 
// 		参数：
// 		返 回 值：
// 		算法：
// 		注意事项：
// 		作    者：王建业
// 		时    间：[2011:3:25   18:00]
// 	*****************************************************************/
// 	BOOL AddMemoryCache(CPMMemoryCache * pMemoryCache);
// 
// 	/****************************************************************
// 	功能描述：从管理类 中移出 缓存指针
// 	参数：
// 	返 回 值：
// 	算法：
// 	注意事项：
// 	作    者：王建业
// 	时    间：[2011:3:25   18:00]
// 	*****************************************************************/
// 	BOOL RemoveMemoryCache(CPMMemoryCache * pMemoryCache);
// 
// 	/****************************************************************
// 	  功能描述：根据内存 使用 情况 释放 缓存
// 		参数：
// 		返 回 值：
// 		算法：
// 		注意事项：
// 		作    者：王建业
// 		时    间：[2011:3:25   18:02]
// 	*****************************************************************/
// 	BOOL ClearUpMemoryCache();
// 
// 	void ClearLevelMemoryCache(CPMMemoryCache::CacheMode memoryCacheMode);
// 	
// private:
// 
// 	CPMMemoryCacheManager();
// 	virtual ~CPMMemoryCacheManager();
// 
// 	CArray<CPMMemoryCache*,CPMMemoryCache*&> m_PMMemoryCacheArr;
// 	static CPMMemoryCacheManager * m_pInstance;
// };

#endif // !defined(AFX_PMMEMORYMANAGER_H__A796C352_6F35_4E36_8C2C_D76A8C343F11__INCLUDED_)
