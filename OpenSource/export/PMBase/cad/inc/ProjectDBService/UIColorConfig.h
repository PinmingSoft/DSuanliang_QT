#pragma once
/**
 * @brief  :获取颜色配置风格与相关参数
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

	//MainColor  枚举
	static const CString VN_Main_BackColor;	
	static const CString VN_Main_TextColor;	

	enum ConfigType
	{
		eBlack		//黑色方案
		,eWhite		//白色方案
		,eGreen		//绿色方案
		,eYellow	//黄色方案
	};
	//设置/获取配色风格
	void SetConfig(ConfigType typ);
	ConfigType GetConfig() const;

	//获取主背景色
	DWORD GetMainBackColor();

	//获取主文字颜色
	DWORD GetMainTextColor();

	//获取选中后的背景色
	DWORD GetMainBackColorSel();

	//设置系统参数值
	void SetPMSysVar(CString KN,CString varName,DWORD nValue);

	//获取系统参数值,获取不到，则采用 nDefaultValue
	DWORD GetPMSysVar(CString KN,CString varName,DWORD nDefaultValue);

protected:
	void LoadConfigure();

	//读取文字的值
	DWORD GetValueColor(CString colorString) const;

protected:
	static CUIColorConfig * m_pInstance;
	
	// 配置文件名称
	CString m_strConfigFileName;

	// 系统级别临时参数缓存
	std::map<CString,DWORD> m_mapSysVar;

	//参数缓存
	PmFile::CIniFileEx m_iniFile;

	CUIColorConfig(void);
	~CUIColorConfig(void);
};

