#pragma once
/**
 * @brief  :��ȡ��ɫ���÷������ز���
 *
 *          
 *			
 *			
 * @author :zfy
 * @version:v1.0
 * @date   :[7/16/2020]
 * @note   :
 */
class PMProjectDBSERVICE CUIColorConfig
{
public:
	static CUIColorConfig * Instance()
	{
		if(m_pInstance == NULL)
		{
			m_pInstance = PMNew(CUIColorConfig);
		}
		return m_pInstance;
	}

	static void Release()
	{
		if(NULL != m_pInstance)
		{
			PMDelete(m_pInstance);
			m_pInstance = NULL;
		}
	}

	//MainColor  ö��
	static const CString VN_Main_BackColor;	
	static const CString VN_Main_TextColor;	

	enum ConfigType
	{
		eBlack		//��ɫ����
		,eWhite		//��ɫ����
		,eGreen		//��ɫ����
		,eYellow	//��ɫ����
	};
	//����/��ȡ��ɫ���
	void SetConfig(ConfigType typ);
	ConfigType GetConfig() const;

	//��ȡ������ɫ
	DWORD GetMainBackColor();

	//��ȡ��������ɫ
	DWORD GetMainTextColor();

	//��ȡѡ�к�ı���ɫ
	DWORD GetMainBackColorSel();

	//����ϵͳ����ֵ
	void SetPMSysVar(CString KN,CString varName,DWORD nValue);

	//��ȡϵͳ����ֵ,��ȡ����������� nDefaultValue
	DWORD GetPMSysVar(CString KN,CString varName,DWORD nDefaultValue);

protected:
	void LoadConfigure();

	//��ȡ���ֵ�ֵ
	DWORD GetValueColor(CString colorString) const;

protected:
	static CUIColorConfig * m_pInstance;
	
	// �����ļ�����
	CString m_strConfigFileName;

	// ϵͳ������ʱ��������
	std::map<CString,DWORD> m_mapSysVar;

	//��������
	PmFile::CIniFileEx m_iniFile;

	CUIColorConfig(void);
	~CUIColorConfig(void);
};

