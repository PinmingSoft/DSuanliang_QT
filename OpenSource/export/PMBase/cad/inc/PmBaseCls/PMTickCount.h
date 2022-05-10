#pragma once

/**
* @brief	利用线程计数的实现
*
*          
* @note  :	
* @param :	
* @defenc:	
* @return:	
* @author:	pzh
* @date  :	
*/

typedef void (*PMTickCount_T)(void* userData);

class PMBASECLASSAPI CPMTickCount
{
public:
	CPMTickCount(PMTickCount_T pCallBack, unsigned int iTimeLapse, void* pUserData);
	~CPMTickCount();

	void SetTimeLapse(unsigned int iLapse);
	unsigned int GetTimeLapse();
protected:
	class CountStruct 
	{
	public:
		CountStruct(PMTickCount_T callBack, unsigned int timeLapse, void* userData) 
			: pCallBack(callBack), iTimeLapse(timeLapse), pUserData(userData),bWorking(TRUE) {}

		PMTickCount_T pCallBack;	//回调指针
		unsigned int iTimeLapse;	//sleep间隔
		void* pUserData;			//data
		BOOL bWorking;	//状态标记，让线程自然退出
	};

	static UINT CountThread(LPVOID parm);
protected:
	CWinThread* m_pThread;
	CPMTickCount::CountStruct* m_pData;
};