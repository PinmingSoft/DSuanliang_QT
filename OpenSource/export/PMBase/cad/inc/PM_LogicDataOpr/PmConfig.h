// PmConfig.h: interface for the PmConfig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMCONFIG_H__D8BB66DC_0911_4AEF_A0A0_E05FA6ABEB1B__INCLUDED_)
#define AFX_PMCONFIG_H__D8BB66DC_0911_4AEF_A0A0_E05FA6ABEB1B__INCLUDED_
// ***************************************************************
//  PmConfig   version:  1.0   ? date: 07/15/2008
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2008 - All Rights Reserved
//  ����:clz
// ***************************************************************
// �ļ�˵��:������ù���
// ***************************************************************
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//��ӦsysdataĿ¼�е�PmConfig.ini�ļ�

class PMLogicDataOprAPI PmConfig  :public PmFile::CIniFile
{

PmConfig();
virtual ~PmConfig();

public:
	////////////////////////Entity�Զ���ʵ�岿��
	//����:
	static CString KN_Entity;				//Entity��

	//�ؼ���
	static CString VN_nNameTextSize;		//�Զ���ʵ�������Ƶ����ִ�С


	////////////////////////ǽ�岿��//////////////////////////////////////////////////
	//Ԥ�ȶ����:keyname
	static CString KN_Wall;//ǽ��  keyname

	
	//Ԥ�����ֵ��valuename
			static CString VN_bImmediately;//��ǽ��������Ƿ�����pushback
			static CString VN_dMinLess;//ǽ�����С����
			static CString VN_bAutoExternd;//�Ƿ������Զ��ӳ�
			static CString VN_bSaveWqwbxInfo;//�Ƿ��ڻ��������ñ�����ǽ�����
			static CString VN_bInitZx;//�Ƿ��������߳�ʼ��,Ŀǰֻ��������ǽ��ʹ��
			static CString VN_bOnlyAllowSameBx;//�Ƿ�ֻ����ѡ����ͬ���͵ı���
			static CString VN_bOptimizeInZwbx;//�Ƿ�ʹ��������ǽ���Ż�
			static CString VN_nDivisionNumForEllipseForWall;//��Բ���и����
			
			//�����ߴ���ݲ�,�������˵�С��dSbtgBreak�Ļ�,���˵��ô�ϵ�
			static CString VN_dSbtgBreak;
	////////////////////////////��//////////////////////////////////////////////

			//������
			static CString KN_Axis;			//����

			//�ؼ���
			static CString VN_bShowZhowFu;	//�Ƿ���ʾ�������
			static CString VN_dAxisTolMax;	//������ƫ��������ƫǰ�����볬�����ֵ����Ϊ���ʺϾ�ƫ
	
////////////////////////////��//////////////////////////////////////////////
	static CString KN_Liang;//��  ģ��

	static CString VN_nDivisionNumForEllipseForLiang;//��Բ���и����
	
	static CString VN_bSortGJSimple;				 //�Ƿ���й���˳�����
	
	static CString VN_iJZBZTextSize;				//���б�ע�����С

	static CString VN_iJZBZTextSpan;				//���б�ע���ּ��

	static CString VN_dJZBZTextDistXRate;			//���б�ע�����˲��ľ��������糤�ȱ�

	static CString VN_iJZBZTextDistY;				//���б�ע�����ľ���

	static CString VN_iJZBZTextClr;					//���б�ע������ɫ

	static CString VN_iYWBZTextSize;				//ԭλ��ע�����С
	
	static CString VN_iYWBZTextSpan;				//ԭλ��ע���ּ��

	static CString VN_iYWBZTextDist;				//ԭλ��ע�����ľ���

	static CString VN_iYWBZTextClr;					//ԭλ��ע������ɫ
	
	static CString VN_iYWBZTOZZPT;					//ԭλ��ע��֧����ˮƽ����
	
	static CString VN_bShowJZBZ;					//�Ƿ���ʾ���б�ע

	static CString VN_bShowYWBZ;					//�Ƿ���ʾԭλ��ע
	
	static CString VN_bShowZZFH;					//�Ƿ���ʾ֧������
	

/////////////////////////////��/////////////////////////////////////////////
	static CString KN_Pole;//��
	static CString VN_bCheckInsertPtInAutoCreate;//��ת����ʱ�Ƿ�������Ϸ�
	static CString VN_dMinZWallForZzz;//�����Զ����ù�������שǽ��С����
	static CString VN_dMinDWHWidth;//��Ҫ�����಼�ù���������С�Ŵ����
	static CString VN_bBasePointForGZZ;//�ڶ˵㲼�ù�����
	static CString VN_bCornerForGZZ;//��ת�䴦���ù�����
	static CString VN_bTCrossForGZZ;//��T����ǽ�����ù�����
	static CString VN_bCrossForGZZ;//��ʮ����ǽ�����ù�����

	//////////////////////////////////////////////////////////////////////////
	//����
	static CString KN_Debug;//����
	static CString VN_bVisibleForTagId;//�ϲ��õı�ʶʵ���Ƿ�ɼ�
	static CString VN_bVisibleForNWTj;//�������������Ƿ�ɼ�
	static CString VN_bEraseTagId;//�Ƿ�ɾ����ʶʵ��

	//������
	BOOL ReadConfig();
	BOOL WriteConfig();

	//added by jjj,2009.12.15
	/************************************************************************************
	*ԭ�����ģ�������˳��ΪPmDataBase��PmCustomEntBase��PmGjOpBase��PmGraphicGJOperator
	*ĿǰҪ��ģ��PmCustomEntBase��ʹ��PmGjOpBase�����������Ϣ
	*����PmCustomEntBase��ֻ�л�ͼʱ��ʹ����Ϣ����ʱ����ģ���Ѿ����룬
	*��˿���������PmGraphicGJOperatorģ��ʱ����������Ϣ��ȡ����
	*Ϊ��ͳһ�����Ƶ�������Ϣͳһ���ŵ�Databaseģ��
	*
	*���裺1����PmConfig���ж�ȡ����
	*      2����PmGraphicGJOperator(Ҳ�����������ĺ�����ģ��)��InitApplication�н���Ϣ����
	          PmDataBase��CProjectVar����ʵ����
	*      3����PmCustomEntBase��ʹ��CProjectVar����ʵ�����Ϣ
	*************************************************************************************/
	static PmConfig *Instance();
	static void Release();
	
private:
	
	static PmConfig*s_pPmConfig;
};


class PMLogicDataOprAPI CIniFileMap
{

public:
	CIniFileMap() {}
	virtual ~CIniFileMap() {}

public:
	//
	virtual BOOL ReadFile();
	virtual BOOL WriteFile();
	void Clear();

	//
	void SetPath(CString path);

	//
	CString GetValue(const CString & strAppName,const CString & strKeyName,const CString & defValue = _T(""));
	BOOL SetValue(const CString & strAppName, const CString & strKeyName, const CString & strKeyValue, BOOL const create = TRUE);

protected:
	CString m_filePath;
	std::map<CString, std::map<CString, CString> *> m_fileMap;//��ֵmap
	std::map<int, CArray<CString, CString &> *> m_commentMap;//ע��map
	CArray<CString, CString &> m_keyArray;
};

class PMLogicDataOprAPI ComParamsSet : public CIniFileMap
{
	ComParamsSet();
	virtual ~ComParamsSet();

public:
	//������
	BOOL ReadConfig();
	BOOL WriteConfig();

	static ComParamsSet *Instance();
	static void Release();

protected:
	static ComParamsSet * s_pComParamsSet;
};

#endif // !defined(AFX_PMCONFIG_H__D8BB66DC_0911_4AEF_A0A0_E05FA6ABEB1B__INCLUDED_)
