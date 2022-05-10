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

	// 2017.10.30 和BIM保持一致
	enum RUNMODE
	{
		DEFAULT = -1,
		SUANLIANG = 0,
		GANJIN = 1	,
		ShiGongAnQuan = 3,	//施工安全
		BIMAZ = 4 , /// 安装
		PeiMoPeiJia = 5, //配模配架
		BIMJsj = 6,		//脚手架
		BIMCDBZ = 7,	//场地布置
	};

	enum STEELSHOW
	{
		eShowName = 1
		,eShowDesc	
	};

	enum SHOW3DSTYLE
	{
		NOSHOW = 0		//平面显示
		,FULLSHOW = 1	//整层显示
		,AREASHOW = 2	//区域显示
	};

	//此枚举需要与自定义实体一致 
	enum Style3D
	{
		//eNoShow3D = 0		//不显示三维
		Solid = 1			//实体
		,LineFrame = 2		//线框
		//,Transparency = 3	//透明
		//,MGlass = 4		//材质:玻璃
		//,MEnviroment = 5	//材质;单个可视化校验环境				
		//FollowCurrent3DSetting = 6	//根据当前设置
	};

	enum SHOWGJ
	{
		SHOW2D =1			//显示2D
		,SHOW3D = 2			//显示3D
		////以下三个为保留
		//,SHOWTEXT = 4	//显示文字
		//,FILLENT = 8	//填充实体
		//,SHOWBOUND = 16	//显示外框

		////以下三个位轴网专用显示
		//,SHOWAXISLINE=32//主轴线
		//,SHOWAXISDIM=64	//主轴线标注
		//,SHOWAXISAID=128//辅助轴线
	};

	//响应器管理的类，在构造时关闭响应器，析构时动态开启响应器
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
	* @brief 获取计算开始计时的时间     
	* @note  : 
	*	
	* @param : 
	* @defenc: 
	* @return: 
	* @author: DWG
	* @date  : [2014年6月4日]
	*/
	clock_t	GetCalStartTime()const{ return m_startTime;}
	// 设置初始时间
	void    SetCalStartTime( clock_t time) { m_startTime = time; }

	/**
	* @brief   设置钢筋运算模式
	*
	*          
	* @note  : 在设置钢筋模式后，会将 参数表重置，除非特殊功能，否则不要使用
	* @param : GanJinCalMode ganjinCalMode：钢筋运算模式
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/11/2011]
	*/
	void SetGangJinCalMode(ProjectInfoMacro::GangJinMode gangjinCalMode);

	/**
	* @brief   从数据库中 读入钢筋模式
	*
	*          
	* @note  : 这个函数 目前只是给打开 新建工程使用
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/11/2011]
	*/
	BOOL ReadGangJinCalMode2Var();

	/**
	* @brief   获取 当前钢筋运算模式
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 返回钢筋模式
	* @author: 王建业
	* @date  : [30/11/2011]
	*/
	ProjectInfoMacro::GangJinMode GetGangJinCalMode();

	void SetRunMode(RUNMODE runMode);
	RUNMODE GetRunMode() const;

	//当前清单定额数据是否与模板一致
	void SetQddeEqualTemplate(BOOL bTemplate);
	BOOL IsQddeEqualTemplate() const;

	//获取默认工程模板库的名称,qc:26260
	CString GetDefaultTemplateName();

	//是否允许分解
	void SetPermitExplode(BOOL bPermit);
	BOOL IsPermitExplode() const;

	//钢筋名称的显示方式，1显示名称，2显示标注，3全部显示
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

	//砼条基
	void SetTc_Ttj( int typ );
	int  GetTc_Ttj();

	//空挡
	void SetTc_Kd(int typ);
	int getTc_Kd();

	//芯模
	void SetTc_Xm(int typ);
	int getTc_Xm();

	//楼地面和天棚
	void SetTc_TpLdm(int typ);
	int getTc_TpLdm();

	/// 自定义实体的所有构件的名称的文字大小
	void SetNameTextSize(int nTextSize);
	int GetNameTextSize() const;

	/**
	* @brief   原位标注与集中标注样式方面的配置
	*
	*          详细描述
	* @note  : 
	* @param : 
	* @return: 
	* @author: 庄峰毅
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

	// 文字大小和颜色可重新设置，且写入到pmconfig.ini中
	inline void SetJZBZTextSize(int iJZBZTextSize);
	inline void SetJZBZTextClr(int iJZBZTextClr);
	inline void SetYWBZTextSize(int iJZBZTextSize);
	inline void SetYWBZTextClr(int iJZBZTextClr);

	//0表示点选布置时不采用CAD BOUND 方式,1时表示采用CAD BOUND 方式
	inline void SetUseCADBound(int typ);
	inline int  GetUseCADBound();

	/************************************************************************/
	/* 三维显示控制
	*/
	/************************************************************************/
	//是否允许三维编辑
	inline void Set3DEditPermit(BOOL bPermit);
	inline BOOL Is3DEditPermit() const;

	//是否显示三维钢筋
	inline void SetShowSteel3D(BOOL bShowSteel3D);
	inline BOOL IsShowSteel3D() const;

	//是否立体显示
	inline void Set3DShow(SHOW3DSTYLE showStyle);
	inline BOOL Is3DShow() const;
	inline CProjectVar::SHOW3DSTYLE Get3DShow() const;

	//是否进行高级的立体显示
	inline void SetAdvance3D(BOOL bAdvance);
	inline BOOL IsAdvance3D() const;

	//设置当前三维显示风格
	inline void SetCurrent3DSetting(Style3D style3D);
	inline CProjectVar::Style3D GetCurrent3DSetting() const;

	//是否进行高级的立体显示
	inline BOOL IsPM3DOrbit();
	inline CString GetCommand_3DOrbit();

	// 图形中心点记录
	inline void SetDwgPosition(CPoint ptLB,CPoint ptRT);
	inline void GetDwgPosition(CPoint & ptLB,CPoint & ptRT) const;

	// 记录图纸窗口是否被拖动或者放大缩小过
	inline void SetDwgViewResized(BOOL bResized);
	inline BOOL IsDwgViewResized() const;

	/**************************************/
	// 分层控制
	/**************************************/
	/**
	* @brief   设置/获取/判断 当前的分层
	*
	*          iLevel数值在[0~9]之间，0为基础分层，当前分层默认可见
	*		   iLevel为-1时，我们认为当前分层为0分层，但显示分层为全部
	* @param : 
	* @return: 
	* @author: 庄峰毅
	* @date  : [14/8/2013]
	*/
	inline void SetCurLevel(int iLevel);
	inline int  GetCurLevel() const;

	/**
	* @brief   设置要显示的分层,如果想显示全部分层，则调用ShowAllLevel
	*			
	*	
	* @note  : 建议不要用等号，而采用IsLevelShow函数来判断某个楼层是否处于要求显示的状态	
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [15/8/2013]
	*/
	inline void SetLevelShow(const PmArray<int> & arr);
	//显示全部分层
	inline void ShowAllLevel();
	//是否全部分层都显示
	inline BOOL IsAllLevelShowed() const;
	//判断当前楼层是否显示，之所以用这个函数而不用等号，是为了防止以后需求出现同时可显示多个分层的情况发生
	inline BOOL IsLevelShow(int level) const;

	//取得构件分层名称 外部拆分 x\\x;x\\x
	inline CString GetLevelName();


	/**
	* @brief   开启/关闭全局实体响应器
	*
	*          详细描述
	* @note  : 
	* @param : 
	* @return: 
	* @author: 庄峰毅
	* @date  : [18/9/2013]
	*/
	//是否开启全局实体响应器，其在GraphicGJOperator模块中
	inline BOOL IsStartDbReactor() const;
	/// 重置db响应器，仅限紧急情况下使用，常常是因为发生莫名错误，导致需要重设计数器
	inline void ResetDbReactor();

	//当前是否为多视图,主要是缓存一个变量以便快速判断
	inline void SetCurMultiView(BOOL bMultiView);
	inline BOOL IsCurMultiView() const;

	//构件轴网纠偏，最大允许误差(即纠偏前后点距离超过这个值，认为不适合纠偏)
	inline double GetAxisTolMax();

	//设置显示墙装饰名称
	inline void SetShowWallDeName(BOOL bShow);
	inline BOOL IsShowWallDeName() const;

	/**
	* @brief   显示控制数据设置与获取
	*
	*          详细描述
	* @note  : 
	* @param : iShowState 0(二维与三维都隐藏 1:仅显示二维，三维隐藏 2:仅显示三维，二维隐藏 3:二维与三维都显示)
	* @return: 
	* @author: 庄峰毅
	* @date  : [18/9/2013]
	*/
	void SetShowControl(int comtype,int iShowState);
	void AppendShowControl(int comtype,int iShowState);
	void RemoveShowControl(int comtype,int iShowSate);
	//全部样式显示
	void SetFullShow(int comtype);
	//获取默认的全显示状态
	//static int GetFullShowState();
	//如果数据获取失败，将返回TRUE，即默认显示
	BOOL IsShowed(int comtype) const;	//2D与3D任何一个显示着，就认为是显示的
	BOOL IsShow2D(int comtype) const;
	BOOL IsShow3D(int comtype) const;

	//是否需要隐藏图层
	BOOL IsNeedHideLayer(int comtype) const;

	//清空显示控制
	void ClearShowControl();

	/**
	* @brief   设置当前项目是否是发生崩溃过的
	*
	*          1、记录该标记，主要是计算时用，清空缓存，TRUE时，内部将把所有floorid记录下来
	*			2、而后如果重新计算，则清空该floorid对应的缓存与标记
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
	* @brief  设置comid是否被删除过,删除过的话，下次执行某命令时，要进行当前图纸的保存
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
	* @brief 判断楼层是否有效。  
	*
	*          
	* @note  : 现在只判断一种情况，
	*			1 存在地下室，且设置了 有地下室时，不可切换到0层
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2014年6月4日]
	*/
	BOOL	IsValidFloor( const int iFloorId ) ;

	/**************************************/
	// 钢筋三维配色方案  
	/**************************************/
	// 三维钢筋颜色 
	int GetSteelColor();

	// 三维钢筋相关构件颜色 
	int GetSteelRelativeGjColor();

	// 三维钢筋构件边框颜色
	int GetSteelFrameColor();

	// 是否进行三维杂色处理
	BOOL IsDeal3DVariegated();

	// 是否正在进行单个构件钢筋量编辑
	BOOL IsSteelEditCommand();
	void SetSteelEditCommand(BOOL bEditSteel);

	/**************************************/
	// 云检查配色方案  
	/**************************************/
	int GetCloudCheckBarColor();

	// 默认的自动备份时间
	CString GetDefaultBakTime();

public:
	BOOL	IsUseSteel3D() ; 
	void	SetUseSteel3D( const BOOL bUseSteel3D ) ;

	/// 钢筋三维显示时是否强制显示成线条方式------这可以大大加快三维显示速度
	BOOL	IsSteel3DUseLineOnly();
	void	SetSteel3DUseLineOnly( const BOOL bSteel3DUseLineOnly );

	/// 一个像素对应多少cad的坐标长度
	double GetXPixelArea() const;
	double GetYPixelArea() const;
	void SetPixelArea(double dValueX,double dValueY);

	/**
	 * @brief  :构件名称显示
	 *
	 * 详细描述
	 * @author zyj
	 * @version v1.0
	 * @date  2016/2/29 14:43
	 * @note  :
	 */
	void SetShowName(int iComtype,int iShowState);
	void AppendShowName(int comtype,int iShowState);
	BOOL GetShowName(int iComtype) const;

	/**
	* @brief 该标志符仅为区分当前进行的是Move等操作还是普通拖拽操作 
	*		 
	*        
	* @note  :
	*		   
	* @param : 
	* @defenc: 
	* @return: 
	* @author: wrq
	* @date  : [2016年9月27日]
	*/
	void SetOprType(BOOL bIsCmdOpr);
	BOOL IsCmdOpr();

	/**
	* @brief   是否在板筋布置命令中
	*
	*			当在板筋布置命令中时，我们设置改变量为TRUE，退出命令时，则设置为FALSE
	*			当在板筋布置命令中时，如果切换布置的构件类型，我们要把构件设置为 eShowHatch状态
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/24/2017]
	*/
	BOOL IsInCmdDrawBanJin() const;
	void SetInCmdDrawBanJin(BOOL bCmdDrawBanJin);

	/**
	* @brief  用于整栋三维显示构件反查中的"返回三维显示"功能
	*         记录上次的值,直接返回,避免用户重新选择操作.
	* @note  :关于UseAllFloorLastChoose,因为消息传递机制限制,
	*		  设置该值在切换至整栋图纸后会重置为FALSE.
	* @author: wrq
	* @date  : [2016年12月21日]
	*/
	void UseAllFloorLastChoose(BOOL bUseLast);
	BOOL IsUseAllFloorLastChoose();

	void SaveExtent(CString strPtMin, CString strPtMax);
	void GetExtent(CString &strPtMin, CString &strPtMax);

	void RecordAllFloorLastChoose(const CUIntArray &iFloorIdArray, const CUIntArray &iComtypeArray);
	void GetAllFloorLastChoose(CUIntArray &iFloorIdArray, CUIntArray &iComtypeArray);

	// 设置/获取是否显示楼地面起卷高度
	void SetLdmQjgdShow(BOOL bShow);
	BOOL IsLdmQjgdShow();

	void SetPillarInfo(int iComid, int iComtype, int iVectorid);
	void GetPillarInfo(int &iComid, int &iComtype, int &iVectorid);

	void SetNotPInfo(int iComid, int iComtype, int iVectorid);
	void GetNotPInfo(int &iComid, int &iComtype, int &iVectorid);

	// 表格是否自动高
	BOOL IsGridAutoHeight();

	/**************************************/
	/* 临时系统参数
	1、VN_DefaultBakTime:系统默认备份时间,默认 120
	2、VN_MTJC_BJM_SHOW :是否显示满基变截面控制，0：不显示 1：显示
	3、VN_UseColorFilter:是否使用颜色过滤 0：不使用 1：使用
	4、VN_ColorFilter_Current :颜色过滤时---当前的颜色
	5、VN_ColorFilter_DisCurrent :颜色过滤时---非当前的颜色
	6、VN_ColorCADFade  :褪色的褪色度设置
	7、VN_Wall_QDJ  :是否使用墙倒角，不使用时，除非区域整理，否则不会倒角
	8、VN_MaxNumOfUndo：最大的回退命令数
	9、VN_Ban_PatternScale 表示板填充密度
	10、VN_PatternColorRatio 表示填充颜色比率，[0,100]适用于所有构件,可大于100
	11、VN_CheckRepeatMode 表示布置时是否进行重复检测
	12、VN_UsePreviousSelFirst 表示优先使用之前已选择的构件
	13、VN_ViewChanged 表示视图是否发生了修改
	14、VN_ColorPublicGJ 表示公共构件的颜色
	15、VN_ColorBack_CellChoosed 表示单元格被批量选中时的背景色
	16、VN_CAL_SL_LT 表示 算量计算时，拉通构件(墙、墙装饰、条基)是否计算
	17、VN_RecogniseZZ_RecoverBG_JM 表示识别支座时是否恢复梁的标高与截面
	18、VN_JIG_Count 表示 jig的计数
	19、VN_PasteLayer_UnCatagory 表示粘贴时是否要对图层进行分类，不分类，则全部归为其他图层
	20、VN_Original_Coordinatesb 标识是否开启原坐标， 0不开启 1开启
	21、VN_Wall_TZQDJ  是否使用砼墙和砌体墙之间的倒角，不使用时，否则不会倒角
	22、VN_UseWorkSpace 是否使用工作区
	23、VN_UseHelpRobot 是否使用帮助小机器人
	24、VN_AutoExplodeInPaste 是否粘贴图纸时自动炸开
	25、VN_MultiViewSynchronize 是否进行多视口联动
	26、VN_RepeatFill 是否显示重复位置的填充色块
	27、VN_HighlightHasNotQDDE  是否高亮没有清单定额的构件栏构件
	28、VN_WallGJ_Break 墙钢筋是否支持断开计算
	*/
	/**************************************/
	//系统变量名
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

	//获取系统参数列表
	CString GetSysVarList() const;
	//设置系统参数值
	void SetPMSysVar(CString varName,int nValue);
	//获取系统参数值,获取不到，则采用 nDefaultValue
	int GetPMSysVar(CString varName,int nDefaultValue);

	//读取与保存配置,从sysdata\pmconfig.ini 中
	BOOL WriteSysVarToConfig(CString varName);
	BOOL ReadSysVarFromConfig(CString varName);

	//读取配置,从sysdata\pmconfig.ini 中,从返回值nValue返回，但不存入map表
	BOOL ReadVarFromConfig(CString KN,CString varName,int & nValue) const;

	//获取 用户名 密码
	BOOL GetLogin_UsePwd(CString & strUserName,CString & strPwd);

	void SetLogin_UsePwd(const CString & strUserName,const CString & strPwd,const CString & strUserId);

	/************************************************************************/
	/* 获取中望版本的一些特殊设置
	*/
	/************************************************************************/
	//设置系统参数值
	void SetZWVar(CString varName,int nValue);
	//获取系统参数值,获取不到，则采用 nDefaultValue
	int GetZWVar(CString varName,int nDefaultValue);

protected:

	//读取与保存配置,从sysdata\pmconfig.ini 中
	BOOL WriteZWVarToConfig(CString varName);
	BOOL ReadZWVarFromConfig(CString varName);

	//读取配置,从sysdata\pmconfig.ini 中,从返回值nValue返回，但不存入map表
	BOOL ReadZWVarFromConfig(CString varName,int & nValue) const;

protected:	
	static CProjectVar * m_pInstance;
	//当前隐藏的次数，当<=0 时表示开启响应器
	static int m_iDbReactorCounter;

	static const CString m_strLevelName;

	CProjectVar();
	RUNMODE m_iRunMode;			//0：算量 1：钢筋
	std::map<CString,int> m_mapSysVar;	//系统级别临时参数缓存
	std::map<CString,int> m_mapZWVar;	//中望参数的缓存
	BOOL m_bQddeEqualTemplate;	//当前清单定额数据是否与模板一致
	BOOL m_bPermitExplode;		//是否允许分解
	//当前是否为双视图
	BOOL m_bCurMultiView;		//当前是否为多视图
	//
	BOOL m_b3DEditPermit;		//是否允许三维编辑
	BOOL m_bShowSteel3D;		//是否显示三维钢筋
	SHOW3DSTYLE m_i3DShow;		//是否3D显示
	BOOL m_bAdvance3D;			//是否高级3D显示
	Style3D m_style3DCurrent;	//当前三维的显示方式，不用于表示是否是二维还是三维
	CString  m_strCmdPM3DOrbit;	//三维旋转命令
	BOOL m_bShowWallDeName;		//是否强制显示所有墙装饰的名称
	CString m_strDefaultTemplateName;	//默认工程模板库名
	//是否开启全局实体响应器，其在GraphicGJOperator模块中
	BOOL m_bStartDbReactor;

	ProjectInfoMacro::GangJinMode m_GangJinCalMode ;//0:03G钢筋运算 1:11G钢筋运算

	////////////////////////////////////////////////////////////////
	/// at 2010年12月9日  14:16  by yxy
	/// 
	/// -1 需要去配置文件读取
	/// int     m_iSteelShowtype;	//1显示名称，2显示标注，3全部显示

	/// 通用
	int     m_iNameShowtype ;
	/// 板筋或筏板筋
	int		m_iSteelShowtype_BanJin ; 
	/// 吊筋 
	int		m_iSteelShowtype_DiaoJin ; 

	/// 是否需要填充 
	/// 1 需要填充
	/// 0 不需要填充
	/// -1 需要去读取配置文件
	int		m_iTc_Mj ;
	int		m_iTc_Xjb ; 
	int		m_iTc_L;
	int		m_iTc_Q;
	int		m_iTc_Ttj;
	int		m_iTc_Kd;
	int		m_iTc_Xm;
	int     m_iTc_TpLdm;

	/// 自定义实体的所有构件的名称的文字大小
	int m_nNameTextSize;
	//added by jjj,2009.12.16
	//集中标注字体尺寸
	int m_iJZBZTextSize;
	//集中标注文字距离
	int m_iJZBZTextSpan;
	//集中标注到梁的距离
	double m_dJZBZTextDistXRate;
	//集中标注到梁端的距离
	int m_iJZBZTextDistY;
	//集中标注字体颜色
	int m_iJZBZTextClr;
	//原位标注字体尺寸
	int m_iYWBZTextSize;
	//原位标注文字距离
	int m_iYWBZTextSpan;
	//原位标注到梁的距离
	int m_iYWBZTextDist;
	//原位标注字体颜色
	int m_iYWBZTextClr;
	//原位标注到支座距离
	int m_iYWBZTOZZPT;

	//装饰
	int m_iUseCADBound;

	//当前可显示层号
	int m_iLevel;
	//要显示的层号或者层号的几何
	PmArray<int> m_arrLevelShow;
	//轴网纠偏的误差，即纠偏前后点距离超过这个值，认为不适合纠偏
	int m_dAxisTolMax;

	//显示控制数据,comtype与对应的显示状态的标记,0(二维与三维都隐藏 1:仅显示二维，三维隐藏 2:仅显示三维，二维隐藏 3:二维与三维都显示，其他数据时都认为是3)
	std::map<int,int> m_mapShowGJ;

	/// 是否发生过崩溃，记录该标记，主要是计算时用，清空缓存
	BOOL m_bHasDump;
	CUIntArray m_arrDumpFloor;

	/**************************************/
	// 钢筋三维配色方案  
	/**************************************/
	// 三维钢筋颜色 
	int m_iSteelColor;
	
	// 三维钢筋相关构件颜色 
	int m_iSteelRelativeGjColor;

	// 三维钢筋构件边框颜色
	int m_iSteelFrameColor;

	/// 是否使用三维钢筋
	BOOL m_bUseSteel3D ;

	/// 是否强制使用线条显示
	BOOL m_bSteel3DUseLineOnly;

	/// 是否进行三维杂色处理
	int m_nDeal3DVariegated;

	/// 是否正在进行单个构件钢筋量的编辑命令
	BOOL m_bEditSteelCommand;

	/**************************************/
	// 云检查配色方案  
	/**************************************/
	int m_iCloudCheckBarColor;

	/// 一个像素对应多少cad的坐标长度
	double m_dXPixelArea;
	double m_dYPixelArea;

	/// 构件名称是否显示map
	std::map<int,int> m_mapShowName;

	/// 是否正在使用命令编辑实体(主要还是区分出Move与直接拖拽操作)
	BOOL m_bCmdOpr;

	/// 是否正在板筋布置命令中
	BOOL m_bCmdDrawBanJin;

	/// 用于整栋三维显示构件反查中的"返回三维显示"功能
	/// 记录上次的值,直接返回  避免用户重新选择操作 wrq
	BOOL m_bUseLast;
	CString m_strPtMin;
	CString m_strPtMax;
	CUIntArray m_iFloorIdArray;
	CUIntArray m_iComTypeArray;

	//comid是否曾经被删除过
	BOOL m_bComIdDeleted;

	// command 'PM_ZS_SHOWLDM_QJGD'中使用
	BOOL m_bShowLdmQjgd;

	// 主要用于柱钢筋截面图的设置(柱钢筋截面图已调整为非模态窗口)
	int m_iPillarComid;
	int m_iPillarComtype;
	int m_iPillarVectorid;
	

	//用于除柱钢筋截面图之外的所有设置
	int m_iNotPComid;
	int m_iNotPComtype;
	int m_iNotPVectorid;

	// 图形在屏幕上的左下与右上角点
	CPoint m_ptScreenLeftBottom;
	CPoint m_ptScreenRightTop;

	// 图形窗口是否被重置过
	BOOL m_bDwgViewResized;

	// 表格是否自动高
	int m_nGridAutoHeight;

	//
	clock_t m_startTime;  /// 计算开始计时的初始时间

	//用户登录 Cookie 内部进入云端的唯一标示
	CString m_strLogin_UserName;
	CString m_strLogin_PWD;
	CString m_strLogin_UserId;
};

#endif // !defined(AFX_PROJECTVAR_H__0C3C9F30_2393_49CB_BAA6_A194628AE2E2__INCLUDED_)
