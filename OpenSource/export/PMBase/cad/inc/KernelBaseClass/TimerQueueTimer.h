#pragma once

class KERNELBASECLASS_API CTimerQueueTimer
{
public:
	/**
	*  @brief : ����timer-queue��ʱ��,ʵ��ÿ��һ��ʱ��������һ�λص�����
	*
	*
	*  @note  
	*  @param : TimerRoutine: �ص�����,��ϵͳ��DueTime����֮��ʼ����,ÿ��lPeriod����ʱ����ִ��һ��
							
							������������:

							VOID CALLBACK WaitOrTimerCallback(
							_In_ PVOID   lpParameter,
							_In_ BOOLEAN TimerOrWaitFired
							);

				Period: ʱ����,����Ϊ��λ
				DueTime: ϵͳ�ڵ�һ�η������ûص�����,������ʱ��,����Ϊ��λ
				Parameter: ���ݸ��ص������Ĳ���

	*  @defenc:  ע��: �ص�����һ��Ҫ�ܹ���������,�������޵ȴ�����ѭ��,
					    ����������������ȴ��ص�������ɶ��޷�����,����
						�����߳̿���.
	*  @return: 
	*  @author: yjc
	*  @date  : 2018/8/13 18:10
	*/
	CTimerQueueTimer(WAITORTIMERCALLBACK TimerRoutine,DWORD Period,DWORD DueTime = 0,PVOID Parameter = NULL);

	/**
	*  @brief : �Ƴ���ʱ��
	*
	*
	*  @note
	*  @param : 
	*  @defenc: �����������õ�DeleteTimerQueueTimer��һֱ�ȴ����еĻص�������ɺ�,
				�Ż᷵��.��������ص�������Ϊ����ѭ�����ߵȴ��޷�����,�����߳�
				�ͻῨ��.
	*  @return: 
	*  @author: yjc
	*  @date  : 2018/8/13 18:32
	*/
	~CTimerQueueTimer(void);
private:
	 HANDLE m_hTimer; // timer-queue��ʱ���ľ��
};
