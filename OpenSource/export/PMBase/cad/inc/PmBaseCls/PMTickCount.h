#pragma once

/**
* @brief	�����̼߳�����ʵ��
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

		PMTickCount_T pCallBack;	//�ص�ָ��
		unsigned int iTimeLapse;	//sleep���
		void* pUserData;			//data
		BOOL bWorking;	//״̬��ǣ����߳���Ȼ�˳�
	};

	static UINT CountThread(LPVOID parm);
protected:
	CWinThread* m_pThread;
	CPMTickCount::CountStruct* m_pData;
};