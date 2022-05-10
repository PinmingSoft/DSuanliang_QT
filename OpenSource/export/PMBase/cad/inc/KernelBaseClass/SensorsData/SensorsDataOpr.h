#pragma once

//神策数据收集   参数sensdata会申请内存，需手动释放
typedef int (_stdcall *DoInitSensors_Dll)(const char *pWorkPath,const char * pDistinct_id,int author_mode,const char * pApp_type,const char * pApp_version,const char * pJsonParamInfo);
typedef int (_stdcall *DoReleaseSensors_Dll)();
typedef int (_stdcall *DoSensorsDoCommand_Dll)(const char * pCommand, const char * pCommandParam);
typedef int (_stdcall *DoSensorsDoGroupCommand_Dll)(const char * pGroupCommand, const char * pCommand, const char * pCommandParam);
typedef int (_stdcall *DoDownLoadFile_Dll)(const char * pUrl,const char * pFileName);


//神策数据 操作类
class KERNELBASECLASS_API CSensorsAnalyticsOpr
{
public:
	
	static CSensorsAnalyticsOpr * Instance()
	{
		if(NULL == m_pInstance)
		{
			//			m_pInstance = new CPMKernelRockeyManager();
			m_pInstance = PMNew(CSensorsAnalyticsOpr);
		}
		return m_pInstance;
	}

	static void Release()
	{
		if ( m_pInstance )
		{
			//			delete m_pInstance;
			PMDelete(m_pInstance);
			m_pInstance = NULL;
		}
	}

	/****************************************************************
	功能描述： 启动 神策统计
	参数：		int author_mode 0 学习版 1:单机锁 正式版  2：账号 正式版 
				const CString & strDistinct_id 账号信息
				const CString & strAppName 软件名称
				const CString & strAppVersion 软件版本号
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[2018:10:8   18:58]
	*****************************************************************/
	BOOL DoSensorsLogin(int author_mode,const CString & strDistinct_id,const CString & strAppName,const CString & strAppVersion);

	/****************************************************************
	功能描述： 发送 执行的命令
	参数：		const CString & strCommand 命令 文字 不能是 中文
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[2018:10:8   19:00]
	*****************************************************************/
	BOOL DoCommand(const CString & strCommand,const CString & strParam);

	/****************************************************************
	功能描述： 发送 命令编组 执行的命令
	参数：		const CString & strGroupCommand 命令 文字 不能是 中文,
				const CString & strCommand  命令可以是中文, 
				const CString & strParam Json参数组
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[2018:10:8   19:00]
	*****************************************************************/
	BOOL DoGroupCommand(const CString & strGroupCommand,const CString & strCommand, const CString & strParam);
	
	BOOL DoDownloadFile(const CString & strUrl,const CString & strFilePath);

private:

	//停止 神策统计
	BOOL DoReleaseSensors();

	CSensorsAnalyticsOpr(void);
	~CSensorsAnalyticsOpr(void);
	static CSensorsAnalyticsOpr * m_pInstance;

	HINSTANCE m_hDllInstance;

	BOOL m_bHasInit;	//是否完成初始化
	DoSensorsDoCommand_Dll m_pDoSensorsDoCommand_DllFun;
	DoSensorsDoGroupCommand_Dll	m_pDoSensorsDoGroupCommand_DllFun;
	DoInitSensors_Dll m_pDoInitSensors_DllFun;
	DoReleaseSensors_Dll m_pDoReleaseSensors_DllFun;
	DoDownLoadFile_Dll m_pDoDownLoadFile_DllFun;
};