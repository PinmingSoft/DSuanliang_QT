#pragma once

class PMBASECLASSAPI CSaveData_Storage
{
public:
	CSaveData_Storage(const CString & strFilePath,BOOL bWriteMode);
	virtual ~CSaveData_Storage(void);

	BOOL ReadStreamInfo(const CString & strKey,LPVOID & pBuffer,ULONG & lBufferSize);

	BOOL WriteStreamInfo(const CString & strKey,LPCVOID pBuffer,ULONG lBufferSize);

protected:

	IStorage * m_pStorage;
	CString m_strFilePath;
};

class PMBASECLASSAPI CSaveTransProcessDebugInfo
{
public:
	CSaveTransProcessDebugInfo(BOOL bWriteMode);
	virtual ~CSaveTransProcessDebugInfo();

	/**
	* @brief ��ȡ������������  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/3/2013]
	*/
	long GetTransInfoCount();

	/**
	* @brief ��ȡָ���� ��������  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/3/2013]
	*/
	BOOL GetTransInfo(long index,LPVOID & pBuffer,ULONG & lBufferSize);

	/**
	* @brief  ����ָ���� �������� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/3/2013]
	*/
	BOOL SetTransInfo(LPCVOID pBuffer,ULONG lBufferSize);

protected:

	void SetTransInfoCount(long lCount);

	BOOL m_bWriteMode;		//�Ƿ��� д��ģʽ
	CSaveData_Storage m_SaveDataOpr;
};