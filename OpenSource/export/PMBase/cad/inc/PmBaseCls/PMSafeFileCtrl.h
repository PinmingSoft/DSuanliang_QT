// PMSafeFileCtrl.h: interface for the CPMSafeFileCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMSAFEFILECTRL_H__2D7E1727_FC00_4BD4_A55D_B875808AB6B1__INCLUDED_)
#define AFX_PMSAFEFILECTRL_H__2D7E1727_FC00_4BD4_A55D_B875808AB6B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/****************************************************************
  ����������˫�ļ����������
	������
	�� �� ֵ��
	�㷨��
	ע�����
			1���ļ��� ��ǰ ���Ƴ�һ����ʱ�ļ���
				1�����ļ�ʱҪ��� FileInfo�� ֮ǰ�Ĵ�״̬��
			2������ʱ�����޸ı��浽��ʱ�ļ��У��ڱ��淵����ȷ�ı�־�󣬽��ļ����ǻ�ԭ�ļ��С�
			3������ �����ĵ���DWGͼֽҪ�������µ���������д �򿪺ͱ��� �رյĺ�����
			4����FileInfo.ini�ļ��У�Ҫ�����ļ��Ŀ���״̬���磺�ļ��Ǵ򿪣���ȡ�����棬���ǡ�

			2012:2:28   wjy��ȥ����ʱ�ļ� ���̸߳��ƣ��ļ����Ʊ�����Ӳ�����Կ��ơ�
							���߳� �������Ч�ʣ����������� �߳��˳�ʱ �ļ�û�и�����ɡ�
								���̱������ˡ�
	��    �ߣ�����ҵ
	ʱ    �䣺[2011:8:21   14:03]
*****************************************************************/
#define PMFileInfoFileName	_T("FileInfo.ini")

class PMBASECLASSAPI CPMSafeFileCtrl  
{
public:

	enum PMFileRunMode
	{
		NoOpen = 0,
		Opening = 1,
		Reading = 2,
		Writing = 3,
		Cover = 4,	
	};

	enum PMFileReturnMode
	{
		PMFile_OK = 0,
		PMFile_NoFile = 1,
		PMFile_Opened = 2,
		PMFile_IniFileError = 3,
		PMFile_CoverError = 4,
		PMFile_ArrError = 5,
		PMFile_SaveError = 6
	};
	CPMSafeFileCtrl();
	virtual ~CPMSafeFileCtrl();

	/****************************************************************
	  ������������鵱ǰ�Ƿ���ִ�б��棬��Ҫ�� �����ڶ��߳��£������ļ�����ʧ��
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2011:8:23   9:15]
	*****************************************************************/
	BOOL CheckIsCanSave();

	/****************************************************************
	  ������������ָ�� �ļ�
		������
		�� �� ֵ��
		�㷨��
		ע�����
			1��Ҫ������д������� ���ܴ��ض����ļ�
			2������������ OpenSafeFile Ҫ��ʹ�û��ຯ������ ���� ������� ����ִ��
		��    �ߣ�����ҵ
		ʱ    �䣺[2011:8:21   15:24]
	*****************************************************************/
	virtual PMFileReturnMode OpenSafeFile(const CString & strFilePath);

	/****************************************************************
	  ��������������ָ�� �ļ�
		������
		�� �� ֵ��
		�㷨��
		ע�����
			1��Ҫ������д������� ���ܱ����ض����ļ�
			2������������ SaveSafeFile Ҫ��ִ��������� ���룬�� ִ�л���� ʵ��
		��    �ߣ�����ҵ
		ʱ    �䣺[2011:8:21   15:27]
	*****************************************************************/
	virtual PMFileReturnMode SaveSafeFile();

	/****************************************************************
	  �����������ر� ָ�� �ļ�
		������bNeedSave  �Ƿ��� �رյ�ʱ�� ����
		�� �� ֵ��
		�㷨��
		ע�����
			1��Ҫ������д������� ���ܱ����ض����ļ�
			2������������ CloseSafeFile Ҫ��ʹ�û��ຯ������ ���� ������� ����ִ��
		��    �ߣ�����ҵ
		ʱ    �䣺[2011:8:21   15:28]
	*****************************************************************/
	virtual PMFileReturnMode CloseSafeFile(BOOL bNeedSave);

	/****************************************************************
	  ���������� ��ȡ�����ļ� ·��
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2011:8:22   9:27]
	*****************************************************************/
	CString GetRunFilePath();

	CString GetFileName();

	CString GetFilePath();

	CString GetIniFilePath();

	//void SetThreadRunMode(PMFileReturnMode fileReturnMode)
	//{
	//	m_ThreadFunRunMode = fileReturnMode;
	//}

	/*CRITICAL_SECTION * GetRunRitiCal_Section()
	{
		return & m_CoverFunThreadSection;
	}*/

protected:
	
	/****************************************************************
	  ������������� ָ���ļ��Ƿ���Բ�����
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2011:8:21   14:11]
	*****************************************************************/
	PMFileReturnMode CheckFileIsNormal(const CString & strFilePath);

	/****************************************************************
	  �������������� �ļ�������״̬ ����� �ļ��Ļָ���ʽ
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2011:8:21   14:06]
	*****************************************************************/
	PMFileReturnMode CheckFile_CloseError();

	/****************************************************************
	  �������������� ���ļ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2011:8:21   14:13]
	*****************************************************************/
	PMFileReturnMode CoverMainFile();
	
	static void CoverMainFile_Thread(CPMSafeFileCtrl * pPMSafeCtrl);

	PMFileRunMode m_FileRunMode;//�ļ����� ״̬ 
	CString m_strFileName;//�ļ����� ����Ϊ Ini���õ� ����ʹ��
	CString m_strFilePath;//ԭʼ�ļ� ·������
	CString m_strTemRunFilePath;//������ʱ �ļ� ·������
	CString m_strFileCtrlIniPath;//�ļ� ����״̬ �ļ� ·��

//	PMFileReturnMode m_ThreadFunRunMode;//�̺߳��� ���н��

//	CRITICAL_SECTION m_CoverFunThreadSection;
};

#endif // !defined(AFX_PMSAFEFILECTRL_H__2D7E1727_FC00_4BD4_A55D_B875808AB6B1__INCLUDED_)
