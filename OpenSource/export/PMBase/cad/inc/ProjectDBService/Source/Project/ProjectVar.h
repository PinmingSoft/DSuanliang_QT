// ProjectVar.h: interface for the CProjectVar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROJECTVAR_H__0C3C9F30_2393_49CB_BAA6_A194628AE2E2__INCLUDED_)
#define AFX_PROJECTVAR_H__0C3C9F30_2393_49CB_BAA6_A194628AE2E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include ".\Project\AccessProject_ProjectInfoTable.h"
//// 
class PMProjectDBSERVICE CProjectVar  
{
public:
	static CProjectVar * Instance()
	{
		if(m_pInstance == NULL)
		{
//			m_pInstance = new CProjectVar();
			m_pInstance = PMNew(CProjectVar);
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

	// 2017.10.30 ��BIM����һ��
	enum RUNMODE
	{
		DEFAULT = -1,
		SUANLIANG = 0,
		GANJIN = 1	,
		ShiGongAnQuan = 3,	//ʩ����ȫ
		BIMAZ = 4 , /// ��װ
		PeiMoPeiJia = 5, //��ģ���
		BIMJsj = 6,		//���ּ�
		BIMCDBZ = 7,	//���ز���
	};

	enum STEELSHOW
	{
		eShowName = 1
		,eShowDesc	
	};

	enum SHOW3DSTYLE
	{
		NOSHOW = 0		//ƽ����ʾ
		,FULLSHOW = 1	//������ʾ
		,AREASHOW = 2	//������ʾ
	};

	//��ö����Ҫ���Զ���ʵ��һ�� 
	enum Style3D
	{
		//eNoShow3D = 0		//����ʾ��ά
		Solid = 1			//ʵ��
		,LineFrame = 2		//�߿�
		//,Transparency = 3	//͸��
		//,MGlass = 4		//����:����
		//,MEnviroment = 5	//����;�������ӻ�У�黷��				
		//FollowCurrent3DSetting = 6	//���ݵ�ǰ����
	};

	enum SHOWGJ
	{
		SHOW2D =1			//��ʾ2D
		,SHOW3D = 2			//��ʾ3D
		////��������Ϊ����
		//,SHOWTEXT = 4	//��ʾ����
		//,FILLENT = 8	//���ʵ��
		//,SHOWBOUND = 16	//��ʾ���

		////��������λ����ר����ʾ
		//,SHOWAXISLINE=32//������
		//,SHOWAXISDIM=64	//�����߱�ע
		//,SHOWAXISAID=128//��������
	};

	//��Ӧ��������࣬�ڹ���ʱ�ر���Ӧ��������ʱ��̬������Ӧ��
	class PMProjectDBSERVICE CDbReactorHide
	{
	public:
		CDbReactorHide();
		~CDbReactorHide();
	};

	class PMProjectDBSERVICE CSteel3DEdit
	{
	public:
		CSteel3DEdit();
		~CSteel3DEdit();
	};

	/**
	* @brief ��ȡ���㿪ʼ��ʱ��ʱ��     
	* @note  : 
	*	
	* @param : 
	* @defenc: 
	* @return: 
	* @author: DWG
	* @date  : [2014��6��4��]
	*/
	clock_t	GetCalStartTime()const{ return m_startTime;}
	// ���ó�ʼʱ��
	void    SetCalStartTime( clock_t time) { m_startTime = time; }

	/**
	* @brief   ���øֽ�����ģʽ
	*
	*          
	* @note  : �����øֽ�ģʽ�󣬻Ὣ ���������ã��������⹦�ܣ�����Ҫʹ��
	* @param : GanJinCalMode ganjinCalMode���ֽ�����ģʽ
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/11/2011]
	*/
	void SetGangJinCalMode(ProjectInfoMacro::GangJinMode gangjinCalMode);

	/**
	* @brief   �����ݿ��� ����ֽ�ģʽ
	*
	*          
	* @note  : ������� Ŀǰֻ�Ǹ��� �½�����ʹ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/11/2011]
	*/
	BOOL ReadGangJinCalMode2Var();

	/**
	* @brief   ��ȡ ��ǰ�ֽ�����ģʽ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: ���ظֽ�ģʽ
	* @author: ����ҵ
	* @date  : [30/11/2011]
	*/
	ProjectInfoMacro::GangJinMode GetGangJinCalMode();

	void SetRunMode(RUNMODE runMode);
	RUNMODE GetRunMode() const;

	//��ǰ�嵥���������Ƿ���ģ��һ��
	void SetQddeEqualTemplate(BOOL bTemplate);
	BOOL IsQddeEqualTemplate() const;

	//��ȡĬ�Ϲ���ģ��������,qc:26260
	CString GetDefaultTemplateName();

	//�Ƿ�����ֽ�
	void SetPermitExplode(BOOL bPermit);
	BOOL IsPermitExplode() const;

	//�ֽ����Ƶ���ʾ��ʽ��1��ʾ���ƣ�2��ʾ��ע��3ȫ����ʾ
//	void SetSteelShowtype(int typ);
	int  GetNameShowStyle( int nComType ) ;
	
	void SetNameShowStyle(int typ);
	int  GetNameShowStyle() ;

	void SetSteelShowtype_BanJin(int typ);
	int  GetSteelShowtype_BanJin() ;

	void SetSteelShowtype_DiaoJin(int typ);
	int  GetSteelShowtype_DiaoJin() ;

	void SetTc_Mj(int typ);
	int  GetTc_Mj() ;

	void SetTc_Xjb(int typ);
	int  GetTc_Xjb() ;
	
	void SetTc_L( int typ );
	int  GetTc_L();

	void SetTc_Q( int typ );
	int  GetTc_Q();

	//������
	void SetTc_Ttj( int typ );
	int  GetTc_Ttj();

	//�յ�
	void SetTc_Kd(int typ);
	int getTc_Kd();

	//оģ
	void SetTc_Xm(int typ);
	int getTc_Xm();

	//¥���������
	void SetTc_TpLdm(int typ);
	int getTc_TpLdm();

	/// �Զ���ʵ������й��������Ƶ����ִ�С
	void SetNameTextSize(int nTextSize);
	int GetNameTextSize() const;

	/**
	* @brief   ԭλ��ע�뼯�б�ע��ʽ���������
	*
	*          ��ϸ����
	* @note  : 
	* @param : 
	* @return: 
	* @author: ׯ����
	* @date  : [18/9/2013]
	*/
	void SetJZBZConfig(int iJZBZTextSize,int iZJBZTextSpan,double dJZBZTextDistXRate,
						int iJZBZTextDistY,int iJZBZTextClr);
	inline int GetJZBZTextSize()const;
	inline int GetJZBZTextSpan()const;
	inline double GetJZBZTextDistXRate()const;
	inline int GetJZBZTextDistY()const;
	inline int GetJZBZTextClr()const;
	void SetYWBZConfig(int iYWBZTextSize,int iYWBZTextSpan,int iYWBZTextDist,int iYWBZTextClr,int iYWBZTOZZPT);
	inline int GetYWBZTextSize()const;
	inline int GetYWBZTextSpan()const;
	inline int GetYWBZTextDist()const;
	inline int GetYWBZTextClr()const;
	inline int GetYWBZTOZZPT()const;

	// ���ִ�С����ɫ���������ã���д�뵽pmconfig.ini��
	inline void SetJZBZTextSize(int iJZBZTextSize);
	inline void SetJZBZTextClr(int iJZBZTextClr);
	inline void SetYWBZTextSize(int iJZBZTextSize);
	inline void SetYWBZTextClr(int iJZBZTextClr);

	//0��ʾ��ѡ����ʱ������CAD BOUND ��ʽ,1ʱ��ʾ����CAD BOUND ��ʽ
	inline void SetUseCADBound(int typ);
	inline int  GetUseCADBound();

	/************************************************************************/
	/* ��ά��ʾ����
	*/
	/************************************************************************/
	//�Ƿ�������ά�༭
	inline void Set3DEditPermit(BOOL bPermit);
	inline BOOL Is3DEditPermit() const;

	//�Ƿ���ʾ��ά�ֽ�
	inline void SetShowSteel3D(BOOL bShowSteel3D);
	inline BOOL IsShowSteel3D() const;

	//�Ƿ�������ʾ
	inline void Set3DShow(SHOW3DSTYLE showStyle);
	inline BOOL Is3DShow() const;
	inline CProjectVar::SHOW3DSTYLE Get3DShow() const;

	//�Ƿ���и߼���������ʾ
	inline void SetAdvance3D(BOOL bAdvance);
	inline BOOL IsAdvance3D() const;

	//���õ�ǰ��ά��ʾ���
	inline void SetCurrent3DSetting(Style3D style3D);
	inline CProjectVar::Style3D GetCurrent3DSetting() const;

	//�Ƿ���и߼���������ʾ
	inline BOOL IsPM3DOrbit();
	inline CString GetCommand_3DOrbit();

	// ͼ�����ĵ��¼
	inline void SetDwgPosition(CPoint ptLB,CPoint ptRT);
	inline void GetDwgPosition(CPoint & ptLB,CPoint & ptRT) const;

	// ��¼ͼֽ�����Ƿ��϶����߷Ŵ���С��
	inline void SetDwgViewResized(BOOL bResized);
	inline BOOL IsDwgViewResized() const;

	/**************************************/
	// �ֲ����
	/**************************************/
	/**
	* @brief   ����/��ȡ/�ж� ��ǰ�ķֲ�
	*
	*          iLevel��ֵ��[0~9]֮�䣬0Ϊ�����ֲ㣬��ǰ�ֲ�Ĭ�Ͽɼ�
	*		   iLevelΪ-1ʱ��������Ϊ��ǰ�ֲ�Ϊ0�ֲ㣬����ʾ�ֲ�Ϊȫ��
	* @param : 
	* @return: 
	* @author: ׯ����
	* @date  : [14/8/2013]
	*/
	inline void SetCurLevel(int iLevel);
	inline int  GetCurLevel() const;

	/**
	* @brief   ����Ҫ��ʾ�ķֲ�,�������ʾȫ���ֲ㣬�����ShowAllLevel
	*			
	*	
	* @note  : ���鲻Ҫ�õȺţ�������IsLevelShow�������ж�ĳ��¥���Ƿ���Ҫ����ʾ��״̬	
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [15/8/2013]
	*/
	inline void SetLevelShow(const PmArray<int> & arr);
	//��ʾȫ���ֲ�
	inline void ShowAllLevel();
	//�Ƿ�ȫ���ֲ㶼��ʾ
	inline BOOL IsAllLevelShowed() const;
	//�жϵ�ǰ¥���Ƿ���ʾ��֮������������������õȺţ���Ϊ�˷�ֹ�Ժ��������ͬʱ����ʾ����ֲ���������
	inline BOOL IsLevelShow(int level) const;

	//ȡ�ù����ֲ����� �ⲿ��� x\\x;x\\x
	inline CString GetLevelName();


	/**
	* @brief   ����/�ر�ȫ��ʵ����Ӧ��
	*
	*          ��ϸ����
	* @note  : 
	* @param : 
	* @return: 
	* @author: ׯ����
	* @date  : [18/9/2013]
	*/
	//�Ƿ���ȫ��ʵ����Ӧ��������GraphicGJOperatorģ����
	inline BOOL IsStartDbReactor() const;
	/// ����db��Ӧ�������޽��������ʹ�ã���������Ϊ����Ī�����󣬵�����Ҫ���������
	inline void ResetDbReactor();

	//��ǰ�Ƿ�Ϊ����ͼ,��Ҫ�ǻ���һ�������Ա�����ж�
	inline void SetCurMultiView(BOOL bMultiView);
	inline BOOL IsCurMultiView() const;

	//����������ƫ������������(����ƫǰ�����볬�����ֵ����Ϊ���ʺϾ�ƫ)
	inline double GetAxisTolMax();

	//������ʾǽװ������
	inline void SetShowWallDeName(BOOL bShow);
	inline BOOL IsShowWallDeName() const;

	/**
	* @brief   ��ʾ���������������ȡ
	*
	*          ��ϸ����
	* @note  : 
	* @param : iShowState 0(��ά����ά������ 1:����ʾ��ά����ά���� 2:����ʾ��ά����ά���� 3:��ά����ά����ʾ)
	* @return: 
	* @author: ׯ����
	* @date  : [18/9/2013]
	*/
	void SetShowControl(int comtype,int iShowState);
	void AppendShowControl(int comtype,int iShowState);
	void RemoveShowControl(int comtype,int iShowSate);
	//ȫ����ʽ��ʾ
	void SetFullShow(int comtype);
	//��ȡĬ�ϵ�ȫ��ʾ״̬
	//static int GetFullShowState();
	//������ݻ�ȡʧ�ܣ�������TRUE����Ĭ����ʾ
	BOOL IsShowed(int comtype) const;	//2D��3D�κ�һ����ʾ�ţ�����Ϊ����ʾ��
	BOOL IsShow2D(int comtype) const;
	BOOL IsShow3D(int comtype) const;

	//�Ƿ���Ҫ����ͼ��
	BOOL IsNeedHideLayer(int comtype) const;

	//�����ʾ����
	void ClearShowControl();

	/**
	* @brief   ���õ�ǰ��Ŀ�Ƿ��Ƿ�����������
	*
	*          1����¼�ñ�ǣ���Ҫ�Ǽ���ʱ�ã���ջ��棬TRUEʱ���ڲ���������floorid��¼����
	*			2������������¼��㣬����ո�floorid��Ӧ�Ļ�������
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [5/27/2014]
	*/
	void SetIsDump(BOOL bDump);
	BOOL IsDump(int floorId) const;
	void ClearDumpTag(int floorId);

	/**
	* @brief  ����comid�Ƿ�ɾ����,ɾ�����Ļ����´�ִ��ĳ����ʱ��Ҫ���е�ǰͼֽ�ı���
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [3/24/2017]
	*/
	void SetComIdDeleted(BOOL bDel);
	BOOL IsComIdDeleted() const;


	/**
	* @brief �ж�¥���Ƿ���Ч��  
	*
	*          
	* @note  : ����ֻ�ж�һ�������
	*			1 ���ڵ����ң��������� �е�����ʱ�������л���0��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2014��6��4��]
	*/
	BOOL	IsValidFloor( const int iFloorId ) ;

	/**************************************/
	// �ֽ���ά��ɫ����  
	/**************************************/
	// ��ά�ֽ���ɫ 
	int GetSteelColor();

	// ��ά�ֽ���ع�����ɫ 
	int GetSteelRelativeGjColor();

	// ��ά�ֽ���߿���ɫ
	int GetSteelFrameColor();

	// �Ƿ������ά��ɫ����
	BOOL IsDeal3DVariegated();

	// �Ƿ����ڽ��е��������ֽ����༭
	BOOL IsSteelEditCommand();
	void SetSteelEditCommand(BOOL bEditSteel);

	/**************************************/
	// �Ƽ����ɫ����  
	/**************************************/
	int GetCloudCheckBarColor();

	// Ĭ�ϵ��Զ�����ʱ��
	CString GetDefaultBakTime();

public:
	BOOL	IsUseSteel3D() ; 
	void	SetUseSteel3D( const BOOL bUseSteel3D ) ;

	/// �ֽ���ά��ʾʱ�Ƿ�ǿ����ʾ��������ʽ------����Դ��ӿ���ά��ʾ�ٶ�
	BOOL	IsSteel3DUseLineOnly();
	void	SetSteel3DUseLineOnly( const BOOL bSteel3DUseLineOnly );

	/// һ�����ض�Ӧ����cad�����곤��
	double GetXPixelArea() const;
	double GetYPixelArea() const;
	void SetPixelArea(double dValueX,double dValueY);

	/**
	 * @brief  :����������ʾ
	 *
	 * ��ϸ����
	 * @author zyj
	 * @version v1.0
	 * @date  2016/2/29 14:43
	 * @note  :
	 */
	void SetShowName(int iComtype,int iShowState);
	void AppendShowName(int comtype,int iShowState);
	BOOL GetShowName(int iComtype) const;

	/**
	* @brief �ñ�־����Ϊ���ֵ�ǰ���е���Move�Ȳ���������ͨ��ק���� 
	*		 
	*        
	* @note  :
	*		   
	* @param : 
	* @defenc: 
	* @return: 
	* @author: wrq
	* @date  : [2016��9��27��]
	*/
	void SetOprType(BOOL bIsCmdOpr);
	BOOL IsCmdOpr();

	/**
	* @brief   �Ƿ��ڰ���������
	*
	*			���ڰ���������ʱ���������øı���ΪTRUE���˳�����ʱ��������ΪFALSE
	*			���ڰ���������ʱ������л����õĹ������ͣ�����Ҫ�ѹ�������Ϊ eShowHatch״̬
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/24/2017]
	*/
	BOOL IsInCmdDrawBanJin() const;
	void SetInCmdDrawBanJin(BOOL bCmdDrawBanJin);

	/**
	* @brief  ����������ά��ʾ���������е�"������ά��ʾ"����
	*         ��¼�ϴε�ֵ,ֱ�ӷ���,�����û�����ѡ�����.
	* @note  :����UseAllFloorLastChoose,��Ϊ��Ϣ���ݻ�������,
	*		  ���ø�ֵ���л�������ͼֽ�������ΪFALSE.
	* @author: wrq
	* @date  : [2016��12��21��]
	*/
	void UseAllFloorLastChoose(BOOL bUseLast);
	BOOL IsUseAllFloorLastChoose();

	void SaveExtent(CString strPtMin, CString strPtMax);
	void GetExtent(CString &strPtMin, CString &strPtMax);

	void RecordAllFloorLastChoose(const CUIntArray &iFloorIdArray, const CUIntArray &iComtypeArray);
	void GetAllFloorLastChoose(CUIntArray &iFloorIdArray, CUIntArray &iComtypeArray);

	// ����/��ȡ�Ƿ���ʾ¥�������߶�
	void SetLdmQjgdShow(BOOL bShow);
	BOOL IsLdmQjgdShow();

	void SetPillarInfo(int iComid, int iComtype, int iVectorid);
	void GetPillarInfo(int &iComid, int &iComtype, int &iVectorid);

	void SetNotPInfo(int iComid, int iComtype, int iVectorid);
	void GetNotPInfo(int &iComid, int &iComtype, int &iVectorid);

	// ����Ƿ��Զ���
	BOOL IsGridAutoHeight();

	/**************************************/
	/* ��ʱϵͳ����
	1��VN_DefaultBakTime:ϵͳĬ�ϱ���ʱ��,Ĭ�� 120
	2��VN_MTJC_BJM_SHOW :�Ƿ���ʾ�����������ƣ�0������ʾ 1����ʾ
	3��VN_UseColorFilter:�Ƿ�ʹ����ɫ���� 0����ʹ�� 1��ʹ��
	4��VN_ColorFilter_Current :��ɫ����ʱ---��ǰ����ɫ
	5��VN_ColorFilter_DisCurrent :��ɫ����ʱ---�ǵ�ǰ����ɫ
	6��VN_ColorCADFade  :��ɫ����ɫ������
	7��VN_Wall_QDJ  :�Ƿ�ʹ��ǽ���ǣ���ʹ��ʱ�����������������򲻻ᵹ��
	8��VN_MaxNumOfUndo�����Ļ���������
	9��VN_Ban_PatternScale ��ʾ������ܶ�
	10��VN_PatternColorRatio ��ʾ�����ɫ���ʣ�[0,100]���������й���,�ɴ���100
	11��VN_CheckRepeatMode ��ʾ����ʱ�Ƿ�����ظ����
	12��VN_UsePreviousSelFirst ��ʾ����ʹ��֮ǰ��ѡ��Ĺ���
	13��VN_ViewChanged ��ʾ��ͼ�Ƿ������޸�
	14��VN_ColorPublicGJ ��ʾ������������ɫ
	15��VN_ColorBack_CellChoosed ��ʾ��Ԫ������ѡ��ʱ�ı���ɫ
	16��VN_CAL_SL_LT ��ʾ ��������ʱ����ͨ����(ǽ��ǽװ�Ρ�����)�Ƿ����
	17��VN_RecogniseZZ_RecoverBG_JM ��ʾʶ��֧��ʱ�Ƿ�ָ����ı�������
	18��VN_JIG_Count ��ʾ jig�ļ���
	19��VN_PasteLayer_UnCatagory ��ʾճ��ʱ�Ƿ�Ҫ��ͼ����з��࣬�����࣬��ȫ����Ϊ����ͼ��
	20��VN_Original_Coordinatesb ��ʶ�Ƿ���ԭ���꣬ 0������ 1����
	21��VN_Wall_TZQDJ  �Ƿ�ʹ����ǽ������ǽ֮��ĵ��ǣ���ʹ��ʱ�����򲻻ᵹ��
	22��VN_UseWorkSpace �Ƿ�ʹ�ù�����
	23��VN_UseHelpRobot �Ƿ�ʹ�ð���С������
	24��VN_AutoExplodeInPaste �Ƿ�ճ��ͼֽʱ�Զ�ը��
	25��VN_MultiViewSynchronize �Ƿ���ж��ӿ�����
	26��VN_RepeatFill �Ƿ���ʾ�ظ�λ�õ����ɫ��
	27��VN_HighlightHasNotQDDE  �Ƿ����û���嵥����Ĺ���������
	28��VN_WallGJ_Break ǽ�ֽ��Ƿ�֧�ֶϿ�����
	*/
	/**************************************/
	//ϵͳ������
	static const CString VN_DefaultBakTime;	
	static const CString VN_MTJC_BJM_SHOW;	
	static const CString VN_UseColorFilter;
	static const CString VN_ColorFilter_Current;
	static const CString VN_ColorFilter_DisCurrent;
	static const CString VN_ColorCADFade;	
	static const CString VN_Wall_QDJ;
	static const CString VN_Wall_TZQDJ;
	static const CString VN_MaxNumOfUndo;
	static const CString VN_Ban_PatternScale;
	static const CString VN_PatternColorRatio;
	static const CString VN_CheckRepeatMode;
	static const CString VN_UsePreviousSelFirst;
	static const CString VN_ViewChanged;
	static const CString VN_ColorPublicGJ;
	static const CString VN_ColorBack_CellChoosed;
	static const CString VN_CAL_SL_LT;
	static const CString VN_RecogniseZZ_RecoverBG_JM;
	static const CString VN_JIG_Count;
	static const CString VN_PasteLayer_UnCatagory;
	static const CString VN_Original_Coordinatesb;
	static const CString VN_UseWorkSpace;
	static const CString VN_UseHelpRobot;
	static const CString VN_AutoExplodeInPaste;
	static const CString VN_MultiViewSynchronize;
	static const CString VN_RepeatFill;
	static const CString VN_HighlightHasNotQDDE;
	static const CString VN_WallGJCal_Break;

	//��ȡϵͳ�����б�
	CString GetSysVarList() const;
	//����ϵͳ����ֵ
	void SetPMSysVar(CString varName,int nValue);
	//��ȡϵͳ����ֵ,��ȡ����������� nDefaultValue
	int GetPMSysVar(CString varName,int nDefaultValue);

	//��ȡ�뱣������,��sysdata\pmconfig.ini ��
	BOOL WriteSysVarToConfig(CString varName);
	BOOL ReadSysVarFromConfig(CString varName);

	//��ȡ����,��sysdata\pmconfig.ini ��,�ӷ���ֵnValue���أ���������map��
	BOOL ReadVarFromConfig(CString KN,CString varName,int & nValue) const;

	//��ȡ �û��� ����
	BOOL GetLogin_UsePwd(CString & strUserName,CString & strPwd);

	void SetLogin_UsePwd(const CString & strUserName,const CString & strPwd,const CString & strUserId);

	/************************************************************************/
	/* ��ȡ�����汾��һЩ��������
	*/
	/************************************************************************/
	//����ϵͳ����ֵ
	void SetZWVar(CString varName,int nValue);
	//��ȡϵͳ����ֵ,��ȡ����������� nDefaultValue
	int GetZWVar(CString varName,int nDefaultValue);

protected:

	//��ȡ�뱣������,��sysdata\pmconfig.ini ��
	BOOL WriteZWVarToConfig(CString varName);
	BOOL ReadZWVarFromConfig(CString varName);

	//��ȡ����,��sysdata\pmconfig.ini ��,�ӷ���ֵnValue���أ���������map��
	BOOL ReadZWVarFromConfig(CString varName,int & nValue) const;

protected:	
	static CProjectVar * m_pInstance;
	//��ǰ���صĴ�������<=0 ʱ��ʾ������Ӧ��
	static int m_iDbReactorCounter;

	static const CString m_strLevelName;

	CProjectVar();
	RUNMODE m_iRunMode;			//0������ 1���ֽ�
	std::map<CString,int> m_mapSysVar;	//ϵͳ������ʱ��������
	std::map<CString,int> m_mapZWVar;	//���������Ļ���
	BOOL m_bQddeEqualTemplate;	//��ǰ�嵥���������Ƿ���ģ��һ��
	BOOL m_bPermitExplode;		//�Ƿ�����ֽ�
	//��ǰ�Ƿ�Ϊ˫��ͼ
	BOOL m_bCurMultiView;		//��ǰ�Ƿ�Ϊ����ͼ
	//
	BOOL m_b3DEditPermit;		//�Ƿ�������ά�༭
	BOOL m_bShowSteel3D;		//�Ƿ���ʾ��ά�ֽ�
	SHOW3DSTYLE m_i3DShow;		//�Ƿ�3D��ʾ
	BOOL m_bAdvance3D;			//�Ƿ�߼�3D��ʾ
	Style3D m_style3DCurrent;	//��ǰ��ά����ʾ��ʽ�������ڱ�ʾ�Ƿ��Ƕ�ά������ά
	CString  m_strCmdPM3DOrbit;	//��ά��ת����
	BOOL m_bShowWallDeName;		//�Ƿ�ǿ����ʾ����ǽװ�ε�����
	CString m_strDefaultTemplateName;	//Ĭ�Ϲ���ģ�����
	//�Ƿ���ȫ��ʵ����Ӧ��������GraphicGJOperatorģ����
	BOOL m_bStartDbReactor;

	ProjectInfoMacro::GangJinMode m_GangJinCalMode ;//0:03G�ֽ����� 1:11G�ֽ�����

	////////////////////////////////////////////////////////////////
	/// at 2010��12��9��  14:16  by yxy
	/// 
	/// -1 ��Ҫȥ�����ļ���ȡ
	/// int     m_iSteelShowtype;	//1��ʾ���ƣ�2��ʾ��ע��3ȫ����ʾ

	/// ͨ��
	int     m_iNameShowtype ;
	/// ���򷤰��
	int		m_iSteelShowtype_BanJin ; 
	/// ���� 
	int		m_iSteelShowtype_DiaoJin ; 

	/// �Ƿ���Ҫ��� 
	/// 1 ��Ҫ���
	/// 0 ����Ҫ���
	/// -1 ��Ҫȥ��ȡ�����ļ�
	int		m_iTc_Mj ;
	int		m_iTc_Xjb ; 
	int		m_iTc_L;
	int		m_iTc_Q;
	int		m_iTc_Ttj;
	int		m_iTc_Kd;
	int		m_iTc_Xm;
	int     m_iTc_TpLdm;

	/// �Զ���ʵ������й��������Ƶ����ִ�С
	int m_nNameTextSize;
	//added by jjj,2009.12.16
	//���б�ע����ߴ�
	int m_iJZBZTextSize;
	//���б�ע���־���
	int m_iJZBZTextSpan;
	//���б�ע�����ľ���
	double m_dJZBZTextDistXRate;
	//���б�ע�����˵ľ���
	int m_iJZBZTextDistY;
	//���б�ע������ɫ
	int m_iJZBZTextClr;
	//ԭλ��ע����ߴ�
	int m_iYWBZTextSize;
	//ԭλ��ע���־���
	int m_iYWBZTextSpan;
	//ԭλ��ע�����ľ���
	int m_iYWBZTextDist;
	//ԭλ��ע������ɫ
	int m_iYWBZTextClr;
	//ԭλ��ע��֧������
	int m_iYWBZTOZZPT;

	//װ��
	int m_iUseCADBound;

	//��ǰ����ʾ���
	int m_iLevel;
	//Ҫ��ʾ�Ĳ�Ż��߲�ŵļ���
	PmArray<int> m_arrLevelShow;
	//������ƫ��������ƫǰ�����볬�����ֵ����Ϊ���ʺϾ�ƫ
	int m_dAxisTolMax;

	//��ʾ��������,comtype���Ӧ����ʾ״̬�ı��,0(��ά����ά������ 1:����ʾ��ά����ά���� 2:����ʾ��ά����ά���� 3:��ά����ά����ʾ����������ʱ����Ϊ��3)
	std::map<int,int> m_mapShowGJ;

	/// �Ƿ�������������¼�ñ�ǣ���Ҫ�Ǽ���ʱ�ã���ջ���
	BOOL m_bHasDump;
	CUIntArray m_arrDumpFloor;

	/**************************************/
	// �ֽ���ά��ɫ����  
	/**************************************/
	// ��ά�ֽ���ɫ 
	int m_iSteelColor;
	
	// ��ά�ֽ���ع�����ɫ 
	int m_iSteelRelativeGjColor;

	// ��ά�ֽ���߿���ɫ
	int m_iSteelFrameColor;

	/// �Ƿ�ʹ����ά�ֽ�
	BOOL m_bUseSteel3D ;

	/// �Ƿ�ǿ��ʹ��������ʾ
	BOOL m_bSteel3DUseLineOnly;

	/// �Ƿ������ά��ɫ����
	int m_nDeal3DVariegated;

	/// �Ƿ����ڽ��е��������ֽ����ı༭����
	BOOL m_bEditSteelCommand;

	/**************************************/
	// �Ƽ����ɫ����  
	/**************************************/
	int m_iCloudCheckBarColor;

	/// һ�����ض�Ӧ����cad�����곤��
	double m_dXPixelArea;
	double m_dYPixelArea;

	/// ���������Ƿ���ʾmap
	std::map<int,int> m_mapShowName;

	/// �Ƿ�����ʹ������༭ʵ��(��Ҫ�������ֳ�Move��ֱ����ק����)
	BOOL m_bCmdOpr;

	/// �Ƿ����ڰ���������
	BOOL m_bCmdDrawBanJin;

	/// ����������ά��ʾ���������е�"������ά��ʾ"����
	/// ��¼�ϴε�ֵ,ֱ�ӷ���  �����û�����ѡ����� wrq
	BOOL m_bUseLast;
	CString m_strPtMin;
	CString m_strPtMax;
	CUIntArray m_iFloorIdArray;
	CUIntArray m_iComTypeArray;

	//comid�Ƿ�������ɾ����
	BOOL m_bComIdDeleted;

	// command 'PM_ZS_SHOWLDM_QJGD'��ʹ��
	BOOL m_bShowLdmQjgd;

	// ��Ҫ�������ֽ����ͼ������(���ֽ����ͼ�ѵ���Ϊ��ģ̬����)
	int m_iPillarComid;
	int m_iPillarComtype;
	int m_iPillarVectorid;
	

	//���ڳ����ֽ����ͼ֮�����������
	int m_iNotPComid;
	int m_iNotPComtype;
	int m_iNotPVectorid;

	// ͼ������Ļ�ϵ����������Ͻǵ�
	CPoint m_ptScreenLeftBottom;
	CPoint m_ptScreenRightTop;

	// ͼ�δ����Ƿ����ù�
	BOOL m_bDwgViewResized;

	// ����Ƿ��Զ���
	int m_nGridAutoHeight;

	//
	clock_t m_startTime;  /// ���㿪ʼ��ʱ�ĳ�ʼʱ��

	//�û���¼ Cookie �ڲ������ƶ˵�Ψһ��ʾ
	CString m_strLogin_UserName;
	CString m_strLogin_PWD;
	CString m_strLogin_UserId;
};

#endif // !defined(AFX_PROJECTVAR_H__0C3C9F30_2393_49CB_BAA6_A194628AE2E2__INCLUDED_)
