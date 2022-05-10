// ProgressDlg_Control.h: interface for the CProgressDlg_Control class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROGRESSDLG_CONTROL_H__9EED85D1_13C4_4F18_83A7_588CD88076DB__INCLUDED_)
#define AFX_PROGRESSDLG_CONTROL_H__9EED85D1_13C4_4F18_83A7_588CD88076DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/******************************************************************** 
 功能描述：进度条的控制类
 参数：
 返 回 值：
 算法：
 注意事项：
	Msg:目前有三种格式：
		1：//标题0|信息1|起始位置2|终止位置3|每秒步长4|是否自动计时5|当前进程ID|是否需要停止
		2：//$位置
		3://#Close 用于关闭进度条

 作    者：王建业
 时    间：[27/9/2008]
*********************************************************************/ 

///////////////////////////////////
///王建业 
///注意 发现在匿名管道中，使用继承进程的方法，可能会使cad文档变只读
///[3/11/2008]
//////////////////////////////////

class PMLogicDataOprAPI CProgressDlg_Control  
{
public:

	/******************************************************************** 
	 功能描述：
	 参数：
	 返 回 值：
	 算法：
	 注意事项：在m_iMaxPos置入大于0 的值时,进度条显示的是精确位置的进度条 
				等于小于0 显示的是只计时风格的进度条
				m_iStep m_bHasTimer 功能 还没有实现(有要求再说)
	 作    者：王建业
	 时    间：[27/9/2008]
	*********************************************************************/ 
	class PMLogicDataOprAPI CProgressInfo
	{
	public:
		CProgressInfo();
		
		CString m_strCaption;//标题
		CString m_strMsgInfo;//显示信息
		int m_iMaxPos;//进度最大值
		int m_iMinPos;//进度最小值
		int m_iStep;//每秒步长
		BOOL m_bHasTimer;//有否自动计时（自动走进度）
		BOOL m_bNeedStop;//是否需要停止按钮
	};
	
	/**
	* @brief 判断当前进度条是否发出停止要求  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/8/2012]
	*/
	BOOL CheckNeedStop();

	/******************************************************************** 
	 功能描述：设定进度条信息
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[12/6/2008]
	*********************************************************************/ 
	BOOL SetProgressInfo(CProgressInfo proInfo);

	/******************************************************************** 
	 功能描述：设定进度条的进度
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[12/6/2008]
	*********************************************************************/ 
	void SetProgressPos(int iPos);

	/******************************************************************** 
	 功能描述：在启动进度条的同时，进行界面输入捕捉
	 参数：//TRUE:进程关闭 FALSE:使用中间文件
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[2/9/2008]
	*********************************************************************/ 
	void SetClosePosDlgMode(BOOL bMode){m_bClosePosDlgMode = bMode;}

	CProgressDlg_Control();
	
	/******************************************************************** 
	 功能描述：在启动进度条的同时，进行界面输入捕捉
	 参数：bEnableUIControl： TRUE 捕捉 FALSE 不捕捉
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[2/9/2008]
	*********************************************************************/ 
	CProgressDlg_Control(BOOL bEnableUIControl);
	
	virtual ~CProgressDlg_Control();
	
protected:

	/*
	///////////////////////////////////
	///王建业 
	///暂时不用
	///[3/11/2008]
	//////////////////////////////////
// 	HANDLE m_hPipeRead; // 匿名管道读句柄
// 	HANDLE m_hPipeWrite; // 匿名管道写句柄
	*/
	BOOL m_bClosePosDlgMode;//TRUE:进程关闭 FALSE:使用中间文件

	PROCESS_INFORMATION m_pi;
private:
	CString GetProcessFile();
	BOOL CheckProcessRunMode();
	void CreateProgressDlg();
};

#endif // !defined(AFX_PROGRESSDLG_CONTROL_H__9EED85D1_13C4_4F18_83A7_588CD88076DB__INCLUDED_)
