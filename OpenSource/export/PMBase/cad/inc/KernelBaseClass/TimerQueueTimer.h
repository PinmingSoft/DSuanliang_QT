#pragma once

class KERNELBASECLASS_API CTimerQueueTimer
{
public:
	/**
	*  @brief : 利用timer-queue计时器,实现每隔一个时间间隔调用一次回调函数
	*
	*
	*  @note  
	*  @param : TimerRoutine: 回调函数,由系统在DueTime毫秒之后开始调用,每隔lPeriod毫秒时间间隔执行一次
							
							函数声明如下:

							VOID CALLBACK WaitOrTimerCallback(
							_In_ PVOID   lpParameter,
							_In_ BOOLEAN TimerOrWaitFired
							);

				Period: 时间间隔,毫秒为单位
				DueTime: 系统在第一次发生调用回调函数,经过的时间,毫秒为单位
				Parameter: 传递给回调函数的参数

	*  @defenc:  注意: 回调函数一定要能够正常结束,不能无限等待或者循环,
					    否则析构函数会因等待回调函数完成而无法返回,导致
						整个线程卡死.
	*  @return: 
	*  @author: yjc
	*  @date  : 2018/8/13 18:10
	*/
	CTimerQueueTimer(WAITORTIMERCALLBACK TimerRoutine,DWORD Period,DWORD DueTime = 0,PVOID Parameter = NULL);

	/**
	*  @brief : 移除计时器
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 析构函数调用的DeleteTimerQueueTimer会一直等待所有的回调函数完成后,
				才会返回.所以如果回调函数因为无限循环或者等待无法返回,整个线程
				就会卡死.
	*  @return: 
	*  @author: yjc
	*  @date  : 2018/8/13 18:32
	*/
	~CTimerQueueTimer(void);
private:
	 HANDLE m_hTimer; // timer-queue计时器的句柄
};
