#pragma once
/**
 * @brief  :¥��cc�������
 *
 *            
 * @author :zfy
 * @version:v1.0
 * @date   :04/15/2010
 *@note   :
 */
#include "acarray.h"
typedef AcArray<int> PmGeIntArray;
class PMProjectDBSERVICE CFloorCC
{
public:
	CFloorCC(void);
	virtual ~CFloorCC(void);
	const static int kBaseOfCC = 10;

	//¥����Ϣ
	class PMProjectDBSERVICE CFloorInfo
	{
	public:
		CFloorInfo()
		{
			m_iFloorId = 0;
			m_dblLDMBG = 0;
			m_dblCG = 0;
		};
		CFloorInfo(const CFloorInfo & info)
		{
			*this = info;
		}
		void operator=(const CFloorInfo & info)
		{
			m_iFloorId = info.m_iFloorId;
			m_dblLDMBG = info.m_dblLDMBG;
			m_dblCG = info.m_dblCG;
			m_strLcmc = info.m_strLcmc;
			m_strFileName = info.m_strFileName;
		}
		CString ToCStr() const
		{
			CString str = _T("<CFloorInfo>");
			str += _T("<m_iFloorId>") +pmcommon::CStr(m_iFloorId) + _T("</m_iFloorId>");
			str += _T("<m_dblLDMBG>") +pmcommon::CStr(m_dblLDMBG) + _T("</m_dblLDMBG>");
			str += _T("<m_dblCG>") +pmcommon::CStr(m_dblCG) + _T("</m_dblCG>");
			str += _T("</CFloorInfo>");
			return str;
		}
		int m_iFloorId;			//floorId,
		double m_dblLDMBG;		//¥���湤�̱��
		double m_dblCG;			//���
		CString m_strLcmc;		//¥������
		CString m_strFileName;	//ͼֽ����
	};

	class PMProjectDBSERVICE CFloorCCInfo
	{
	public:
		CFloorCCInfo()
		{
			m_iFloorId = 0;
			m_dblLDMBG = 0;
			m_iCC = 0;
			m_dblCG = 0;
		};
		CString ToCStr() const
		{
			CString str = _T("<CFloorCCInfo>");
			str += _T("<m_iFloorId>") + pmcommon::CStr(m_iFloorId) + _T("</m_iFloorId>");
			str += _T("<m_dblLDMBG>") + pmcommon::CStr(m_dblLDMBG) + _T("</m_dblLDMBG>");
			str += _T("<m_iCC>") + pmcommon::CStr(m_iCC) + _T("</m_iCC>");
			str += _T("<m_dblCG>") + pmcommon::CStr(m_dblCG) + _T("</m_dblCG>");
			str += _T("</CFloorCCInfo>");
			return str;
		}
		int m_iFloorId;			//floorId,
		double m_dblLDMBG;		//¥���湤�̱��
		int m_iCC;              //cc
		double m_dblCG;			//���
	};

	enum CCType
	{
		COMN = 0	//��ͨ¥��
		,BZC		//��׼��
		,JOC		//��ż��
	};

	//��ʼ��¥����Ϣ,�Է���ʹ��,Initʱ��������е�����
	virtual void Init( NDataModelDataSet * pFloorDataSet );

	//���
	virtual void Reset();

	//��ȡ ��������¥��ױ��
	double GetGoundDiBG() const;

	//��ȡ ��������¥�� id
	int GetGoundFloorID() const;
	// ��ȡ��������¥���id���
	int GetGoundFloorIDNum() const;
	
	//��ȡ¥������
	CString GetLcmc(int floorid) const;
	//¥������
	double GetLdmbg(int floorid) const;
	//¥����
	double GetCg(int floorid) const;
	//��ȡ¥���Ӧ��ͼֽ��
	CString GetFileName(int floorid) const;
	//����¥������ ��ȡfloorid,�Ҳ�������-1
	int GetFloorIdByLcmc(const CString & lcmc) const;
	//����¥���Ӧ��ͼֽ�� ��ȡfloorid,�Ҳ�������-1
	int GetFloorIdByFileName(const CString & fileName) const;
	//
	/**
	* @brief   ���ù���¥��ķ�Χ,rangup ���ϵĹ���¥����,rangdown��ʾ���µ�¥�������
	*
	*          rangup,rangedownĬ��Ϊ2
	* @note  : 
	* @param : rangup ���ϵĹ���¥����
	* @param : rangdown ���µĹ���¥����
	* @return: 
	* @author: zfy
	* @date  : [24/4/2012]
	*/
	void SetRelativeRange(int rangeUp,int rangeDown);
	void GetRelativeRange(int & rangeUp,int & rangeDown);

	//��ȡcc���ַ����������ccҪ�����10�ģ�����ֵΪcc����10����ַ���
	CString CCToStr(int cc) const;


	/******************************************************************** 
	������������ȡcc���ڵ�floorId���������жϸ�cc�Ƿ�Ϸ�
	��    ����
	�� �� ֵ����cc������ʱ����FALSE
	��    ����
	ע�����ccΪ����10��
	��    �ߣ�zfy
	ʱ    �䣺[22/11/2011]
	*********************************************************************/ 
	BOOL GetFloorId(int cc,int & floorId) const;

	//��ȡfloorId��Ӧ��cc,Ҫ���С�������򡣵�floorId������ʱ����FALSE��ccΪ����10��
	BOOL GetCC(int floorId,PmGeIntArray & aryCC) const;
	void GetCC(const PmGeIntArray & aryFloorId,PmGeIntArray & aryCC) const;

	//��ȡ���������cc
	void GetCCAll_Sort(PmGeIntArray & aryCC) const;

	//��ȡ�²��cc,�����ڷ���FALSE,ccΪ����10��
	BOOL GetCCPre(int curCC,int & ccPre) const;

	//��ȡ�ϲ��cc,�����ڷ���FALSE,ccΪ����10��
	BOOL GetCCNext(int curCC,int & ccNext) const;

	/******************************************************************** 
	�����������ж�����cc�����(des-src)����,����-1����1��ֻ���1��,0����1��������6��
	��    ����
	�� �� ֵ����des��src��ʱ��������������ͬʱ����0�����򷵻ظ���
	��    ����
	ע�����1��ȷ�������ccDes��ccSrc�Ǵ��ڵ�
	          2��ccΪ����10��,����ֵΪ��࣬������10
	��    �ߣ�zfy
	ʱ    �䣺[22/11/2011]
	*********************************************************************/ 
	int SubCC(int ccDes,int ccSrc);

	/******************************************************************** 
	�������������¥���cc����,aryCCҪ���ź���:1,2,3�����ϳ�"1~3"; 1,2,4�����ϳ�"1/2/4"
	��    ����
	�� �� ֵ��
	��    ����
	ע�����-1,0,1���ܱ��ϳ�-1~1
	��    �ߣ�zfy
	ʱ    �䣺[6/12/2011]
	*********************************************************************/ 
	CString JoinCCName(const PmGeIntArray & aryCC) const;

	/******************************************************************** 
	�����������ñ������ѡ���¥�㣬���������ڲ�
	��    ����
	�� �� ֵ��
	��    ����
	ע�����ccΪ����10��
	��    �ߣ�zfy
	ʱ    �䣺[18/11/2011]
	*********************************************************************/ 
	BOOL GetInsectCC(double diBG,double dingBG,int & iCCDown,int & iCCUp) const;
	BOOL GetInsectCC(double diBG,double dingBG,PmGeIntArray & arrCCInsect,BOOL bInsectPriority) const;

	/******************************************************************** 
	������������ȡ���ڵ�cc�뱾���cc�ļ��ϡ�������,Ŀǰ���ǳ��Ͽ�2��(kRangeUp����)������
	��1��(kRangeDown����)
	��    ����
	�� �� ֵ��
	��    ����1�����Ǽ���2�㣬��Ҫ��ȡ1,2,3,4������
	2��Ҫ���С��������
	ע�����ccΪ����10��
	��    �ߣ�zfy
	ʱ    �䣺[18/11/2011]
	*********************************************************************/ 
	//floorId������ʱ����FALSE
	BOOL GetRelativeCC(int floorId,PmGeIntArray & aryCC) const;
	void GetRelativeCC(const PmGeIntArray & floorIdArr,PmGeIntArray & aryCC) const;
	void GetRelativeCCForCal(int cc,PmGeIntArray & aryCC) const;

	/**
	 * @brief ��Ӽ�����ȡ����floorid�ĺ���
	 *
	 *        
	 * @author ����ҫ
	 * @version v1.0
	 * @date  [2014��8��21��]
	 * @note  
	 */
	/// 
	void	GetRelationCc2FloorId( const PmGeIntArray & aryCc , PmGeIntArray & aryFloorId ) ;

	/// 
	void	GetRelationFloorId( const int iFloorId , PmGeIntArray & aryFloorId ) ;

	/// 
	void	GetRelationFloorId( const PmGeIntArray & arySrcFloorId , PmGeIntArray & aryDesFloorId ) ;


	/******************************************************************** 
	������������ȡ���ڵ�cc��������,Ŀǰ���ǳ��Ͽ�2��(kRangeUp����)������
	��1��(kRangeDown����)
	��    ����
	�� �� ֵ��
	��    ����1�����Ǽ���2�㣬��Ҫ��ȡ1,3,4������
			  2��Ҫ���С��������
	ע�����ccΪ����10��
	��    �ߣ�zfy
	ʱ    �䣺[18/11/2011]
	*********************************************************************/ 
	void GetNearCC(int floorId,PmGeIntArray & aryCC) const;
	void GetNearCC(const PmGeIntArray & floorIdArr,PmGeIntArray & aryCC) const;


	//��ȡCC��¥��ױ����¥�㶥��ߣ���Ϊ���̱�ߣ��������ڲ��ж���,ccΪ����10��
	BOOL GetCCBG(int cc,double & bgBottom,double & bgTop) const;

	/// 
	BOOL GetCcCg( const int iCc , double & dCg ) const ;

	double GetCcLdmbg( const int iCc ) const ;

	//��ӡ��Ա,������
	//void PrintMember() const;

	/// �ж��Ƿ��е�����
	BOOL	HasDxs() const; 

	BOOL	IsUnderBaseFloor( const int iFloorId ) const ; 

	/// �Ƿ��ǵײ�
	BOOL	IsLastFloor( const int iFloorId ) const ;

	/// �Ƿ��Ƕ���
	BOOL	IsTopFloor( const int iFloorId ) const ;

	/**
	*  @brief : ��floorid��ȡ��Ӧ��¥������
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/8/10 17:30
	*/
	void GetCcLdmbgArry(const int iFloorId,CArray<double,double&>& arryCcLdmbg);
protected:
	//���¿�ѡ1��
	int m_iRangeDown;
	//���Ͽ�ѡ2��
	int m_iRangeUp;

public:
	//��¥�����Ʋ��Ϊcc���磺1~3���Ϊ1,2,3; 1/2/4�ŷ�Ϊ1,2,4���ٳ���10
	CFloorCC::CCType SplitFloorName(CString floorName,PmGeIntArray & aryCC);
protected:
	//aryFlooInfo����aryCC����,ccΪ����10��
	void SortFloorInfoBy(const PmGeIntArray & aryCC,CArray<CFloorCCInfo,CFloorCCInfo &> & aryFloorInfo) const;
	//��CC��������,0��������ǰ�棬��(0,-2,-1,1,2...),ccΪ����10��
	void SortCC(PmGeIntArray & aryCC) const;
	//�Ƿ�Ϊ�в�,ccΪ����10��
	BOOL IsJiaCC(int cc) const{return ((cc % kBaseOfCC) == 0)?FALSE:TRUE;}

protected:
	//��Ӧ��floorId��cc Map
	std::map<int,PmGeIntArray> m_MapIdtoCC;
	std::map<int,int>          m_MapCCtoId;

	CArray<CFloorCCInfo,CFloorCCInfo &> m_aryCCInfo;
	//floorInfo����
	CArray<CFloorInfo,CFloorInfo &> m_aryFloorInfo;
	//���������cc,��:0,-3,-2,-1,1,2,3,4,5...
	PmGeIntArray m_aryCC;
};

/***************************************************************
Floor.h   version:  1.0   ? date: 18/11/2011
-------------------------------------------------------------

-------------------------------------------------------------
Copyright (C) $YEAR - All Rights Reserved
***************************************************************
�ļ�˵��: ���ڴ洢¥�㷽��Ĳ����뺯��(��Ԫ�������)
ע�����1��Ҫ�����еĴ����cc������
		  2��Ҫ�����еĴ����floorId������
		  3�������߼��ϣ��ڲ�����cc���ǳ���10�ģ������ɼ��ݴ��
��    �ߣ�zfy
ʱ    �䣺[18/11/2011]
***************************************************************/
class PMProjectDBSERVICE CFloorCach
{
public:
	static CFloorCach & Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = PMNew(CFloorCach);
//#ifdef _DEBUG
//			acutPrintf(_T("\n ע�����CFloorCachҪ�����еĴ����cc������;Ҫ�����еĴ����floorId������!!!"));
//			acutPrintf(_T("\n ֪ͨ��CFloorCach��֤���еķ��ص�cc��floorId�ȶ�����Ҫ��Ч�Լ��!!!"));
//#endif
		}
		//
		return (*m_pInstance);
	}
	static void Release()
	{
		if (m_pInstance != NULL)
		{

			PMDelete(m_pInstance);
			m_pInstance = NULL;
		}
	}
	
	//
	//ת�Ͷ���,�Ի�ȡ�Է��ķ���
	CFloorCC * operator->();

	//����¥����Ϣ
	static void UpdateFloorInfo();

	//������Ƶ�ƺ���
	double GetSwdpbg() const{return m_dSwdpbg;}
	//��Ȼ��Ƶ�ƺ���
	double GetZrdpbg() const{return m_dZrdpbg;}

protected:
	static CFloorCach * m_pInstance;
	//¥������е���Ϣ
	CFloorCC m_floorCC;

	//������Ƶ�ƺ���
	double m_dSwdpbg;
	//��Ȼ��Ƶ�ƺ���
	double m_dZrdpbg;

	//
	CFloorCach(void);
	~CFloorCach(void);
};

class PMProjectDBSERVICE CProjectSettingCache
{
public:
	static CProjectSettingCache * Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = PMNew(CProjectSettingCache);
		}
		//
		return m_pInstance;
	}
	static void Release()
	{
		if (m_pInstance != NULL)
		{

			PMDelete(m_pInstance);
			m_pInstance = NULL;
		}
	}

	struct BGParm
	{
		//��߲���ģʽ
		int m_bgMode;				//ͬOdBGData 0��û�б�ߣ�1���ױ�� 2������� 3�����ױ��

		//�ױ�� ������
		CString m_strDiBGParm;		

		//����� ������
		CString m_strDingBGParm;	

		BGParm(){m_bgMode = 0;}
	};

	//���ݹ�������ˢ����Ϣ
	void UpdateByProject();

	//���ģʽ��Ϣ
	void UpdateBGModeInfo();

	//�ṹ������Ϣ
	void UpdateFloorGJXXInfo();

	//����¥����Ϣ
	//���ر��ģʽ��0��¥���� 1�����̱��
	int GetBGMode(int floorid,int comtype) const;

	//��߲�����Ϣ
	const BGParm * GetBGParm(int comtype) const;

	/**
	* @brief ��ȡ�ṹ�����еĹ�����Ϣ
	*
	*          
	* @note  : 
	* @param : comtypeConvert �˴�������comtype��һ������Ҫ��comtypeConvert=CAccessProject_FloorGJXXInfoTable::ConvertComType(comtype) ; ת���ſ���
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [5/10/2019]
	*/
	BOOL GetFloorGJXXInfo(int floorid,int comtypeConvert,CString fieldName,CString & fieldValue) const;

protected:
	static CProjectSettingCache * m_pInstance;

	//��߹����е���Ϣ: ¥��"floorid|comtype" �� "���ģʽ" ��ƥ��
	std::map<CString,int> m_mapBGMode;

	//Ĭ��comtype�ı�߲���
	std::map<int,BGParm *> m_mapBGParm;

	//�ṹ�����еĹ�����Ϣ
	//CProject_FloorGJXXInfoTable * m_pDatasetFloorGJXXInfo;
	CSQLDataSet  * m_pDatasetFloorGJXXInfo;

	//
	CProjectSettingCache(void);
	~CProjectSettingCache(void);

	//��ʼ���߶ȵ����õ����ű�
	void InitBGParm();
};