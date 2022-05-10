#pragma once

#define PMMB		

class PMLogicDataOprAPI CSoftShowTextInfoOpr
{
public:
	CSoftShowTextInfoOpr(void);
	virtual ~CSoftShowTextInfoOpr(void);
	/**
	* @brief ��ȡѧϰ����ʾ��Ϣ       
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ���Ÿ�
	* @date  : [2020/12/23]
	*/
	static CString GetLearningVersionMsg();

	/**
	* @brief ��ȡ����汾��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/12/2012]
	*/
	static void GetProjectVer(CString & strMainVer,CString & strSubVer);

	/**
	* @brief ��ȡ�����ļ�·�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/12/2012]
	*/
	static CString GetConfigFilePath();

	/**
	* @brief  ��ȡ�ļ�ѡ��Ի��� �������� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/12/2012]
	*/
	static CString GetProjectFileDialog_Filter();

	/**
	* @brief  ��ȡ�ļ�ѡ��Ի��� ��չ�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/12/2012]
	*/
	static CString GetProjectFileDialog_Ext();

	/**
	* @brief  ��ȡ�ļ�ѡ��Ի��� ��ʾ���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/12/2012]
	*/
	static CString GetProjectFileDialog_SoftTxt();


	static CString GetFullSoftName();
	/**
	* @brief  ��ȡMESSAGEBOX��Welcome��Loading�Ի����� ��ʾ���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [5/12/2012]
	*/
	static CString GetSimSoftName();

	/**
	* @brief  ������ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [5/12/2012]
	*/
	static CString GetCompanyLogName();

	/**
	* @brief  ��ȡ��˾�绰 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [5/12/2012]
	*/
	static CString GetCompanyTel();

	/**
	* @brief   ��ȡ��˾�绰 ����˵��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [7/1/2013]
	*/
	static CString GetCompanyTelInfo();

	/**
	* @brief  ��ȡ��˾���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [5/12/2012]
	*/
	static CString GetCompanyName();

	/**
	* @brief  ��ȡ��˾��ַ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [5/12/2012]
	*/
	static CString GetCompanyURL();
	/**
	*  @brief : ��ȡ֧����ַ
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/10/21 9:56
	*/
	CString GetPayURL();
	/**
	* @brief  zipѹ���ļ�����
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [5/12/2012]
	*/
	static CString GetProjectZip_Filter();
};

/**
* @brief  ͼƬ��ʾ���� 
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: ����ҵ
* @date  : [7/12/2012]
*/
class PMLogicDataOprAPI CSoftShowPicInfoOpr
{
public:
	CSoftShowPicInfoOpr(void);
	virtual ~CSoftShowPicInfoOpr(void);

	/**
	* @brief �������Ico  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [7/12/2012]
	*/
	static HICON GetSoftLogIcon(HINSTANCE temHInstance);

	/**
	* @brief ���ع���LOG
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: jqf
	* @date  : [7/12/2012]
	*/
	static HBITMAP GetSoftLogBit( HINSTANCE temHInstance,CRect rect );
protected:

	static CString GetPicDirPath();
};

class PMLogicDataOprAPI CSoftLogicInfoOpr
{
public:
	CSoftLogicInfoOpr();
	virtual ~CSoftLogicInfoOpr();

	enum PMSoftType
	{
		eSLGJ_Master = 0,
		eSLGJ_HuNan = 1,
		eSLGJ_YunNan = 2,
	};
	/**
	* @brief  �ж��Ƿ��� OEM�汾 
	*
	*          
	* @note  : OEM�ϳ���Ϣ���Ʒ�ʽ
				����˾�汾��SL_GJ|Master		4721c4f0fa22bb18224dfb90774c469a
				���ϰ汾��SL_GJ|HuNan			6562f0d0563e46a9bce080ea38752a47
				���ϰ汾��SL_GJ|YunNan			4e7d3c27c5b8de8a05f9e0e9a3a3697b
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [10/12/2012]
	*/
	static BOOL CheckIsOEMSoft();

	static PMSoftType GetSoftType();

	/**
	* @brief ��ȡ�����ļ�·�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/12/2012]
	*/
	static CString GetConfigFilePath();

	/**
	* @brief ��ȡ��Ŀ���̵� ������  
	*
	*          
	* @note  : �������� ������ ��OEM������ ����
				�ϳɹ��� ����� SoftCode2|ProjectFile
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/12/2012]
	*/
	static CString GetSoftProjectCode();

	/**
	* @brief �ж� �򿪵� �û����� �Ƿ���  �߼��ɴ򿪷�Χ  
	*
	*          
	* @note  : ���ܴ򿪷���FALSE
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/12/2012]
	*/
	static BOOL CheckProjectSoftCode(const CString & strProjectCode);

protected:

	static const CString m_strSL_GJMaster;
	static const CString m_strSL_GJ_HuNan;
	static const CString m_strSL_GJ_YunNan;
};