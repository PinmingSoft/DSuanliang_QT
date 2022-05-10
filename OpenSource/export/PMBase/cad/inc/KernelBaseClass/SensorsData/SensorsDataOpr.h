#pragma once

//��������ռ�   ����sensdata�������ڴ棬���ֶ��ͷ�
typedef int (_stdcall *DoInitSensors_Dll)(const char *pWorkPath,const char * pDistinct_id,int author_mode,const char * pApp_type,const char * pApp_version,const char * pJsonParamInfo);
typedef int (_stdcall *DoReleaseSensors_Dll)();
typedef int (_stdcall *DoSensorsDoCommand_Dll)(const char * pCommand, const char * pCommandParam);
typedef int (_stdcall *DoSensorsDoGroupCommand_Dll)(const char * pGroupCommand, const char * pCommand, const char * pCommandParam);
typedef int (_stdcall *DoDownLoadFile_Dll)(const char * pUrl,const char * pFileName);


//������� ������
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
	���������� ���� ���ͳ��
	������		int author_mode 0 ѧϰ�� 1:������ ��ʽ��  2���˺� ��ʽ�� 
				const CString & strDistinct_id �˺���Ϣ
				const CString & strAppName �������
				const CString & strAppVersion ����汾��
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2018:10:8   18:58]
	*****************************************************************/
	BOOL DoSensorsLogin(int author_mode,const CString & strDistinct_id,const CString & strAppName,const CString & strAppVersion);

	/****************************************************************
	���������� ���� ִ�е�����
	������		const CString & strCommand ���� ���� ������ ����
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2018:10:8   19:00]
	*****************************************************************/
	BOOL DoCommand(const CString & strCommand,const CString & strParam);

	/****************************************************************
	���������� ���� ������� ִ�е�����
	������		const CString & strGroupCommand ���� ���� ������ ����,
				const CString & strCommand  �������������, 
				const CString & strParam Json������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2018:10:8   19:00]
	*****************************************************************/
	BOOL DoGroupCommand(const CString & strGroupCommand,const CString & strCommand, const CString & strParam);
	
	BOOL DoDownloadFile(const CString & strUrl,const CString & strFilePath);

private:

	//ֹͣ ���ͳ��
	BOOL DoReleaseSensors();

	CSensorsAnalyticsOpr(void);
	~CSensorsAnalyticsOpr(void);
	static CSensorsAnalyticsOpr * m_pInstance;

	HINSTANCE m_hDllInstance;

	BOOL m_bHasInit;	//�Ƿ���ɳ�ʼ��
	DoSensorsDoCommand_Dll m_pDoSensorsDoCommand_DllFun;
	DoSensorsDoGroupCommand_Dll	m_pDoSensorsDoGroupCommand_DllFun;
	DoInitSensors_Dll m_pDoInitSensors_DllFun;
	DoReleaseSensors_Dll m_pDoReleaseSensors_DllFun;
	DoDownLoadFile_Dll m_pDoDownLoadFile_DllFun;
};