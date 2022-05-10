#pragma once
/**
 * @brief  :楼层cc的相关类
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

	//楼层信息
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
		double m_dblLDMBG;		//楼地面工程标高
		double m_dblCG;			//层高
		CString m_strLcmc;		//楼层名称
		CString m_strFileName;	//图纸名称
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
		double m_dblLDMBG;		//楼地面工程标高
		int m_iCC;              //cc
		double m_dblCG;			//层高
	};

	enum CCType
	{
		COMN = 0	//普通楼层
		,BZC		//标准层
		,JOC		//奇偶层
	};

	//初始化楼层信息,以方便使用,Init时将清空类中的数据
	virtual void Init( NDataModelDataSet * pFloorDataSet );

	//清空
	virtual void Reset();

	//获取 建筑最下楼层底标高
	double GetGoundDiBG() const;

	//获取 建筑最下楼层 id
	int GetGoundFloorID() const;
	// 获取建筑最下楼层的id编号
	int GetGoundFloorIDNum() const;
	
	//获取楼层名称
	CString GetLcmc(int floorid) const;
	//楼地面标高
	double GetLdmbg(int floorid) const;
	//楼层层高
	double GetCg(int floorid) const;
	//获取楼层对应的图纸名
	CString GetFileName(int floorid) const;
	//根据楼层名称 获取floorid,找不到返回-1
	int GetFloorIdByLcmc(const CString & lcmc) const;
	//根据楼层对应的图纸名 获取floorid,找不到返回-1
	int GetFloorIdByFileName(const CString & fileName) const;
	//
	/**
	* @brief   设置关联楼层的范围,rangup 向上的关联楼层数,rangdown表示向下的楼层关联数
	*
	*          rangup,rangedown默认为2
	* @note  : 
	* @param : rangup 向上的关联楼层数
	* @param : rangdown 向下的关联楼层数
	* @return: 
	* @author: zfy
	* @date  : [24/4/2012]
	*/
	void SetRelativeRange(int rangeUp,int rangeDown);
	void GetRelativeRange(int & rangeUp,int & rangeDown);

	//获取cc的字符串表达，传入的cc要求乘于10的，返回值为cc除于10后的字符串
	CString CCToStr(int cc) const;


	/******************************************************************** 
	功能描述：获取cc所在的floorId，可用于判断该cc是否合法
	参    数：
	返 回 值：当cc不存在时返回FALSE
	算    法：
	注意事项：cc为乘于10的
	作    者：zfy
	时    间：[22/11/2011]
	*********************************************************************/ 
	BOOL GetFloorId(int cc,int & floorId) const;

	//获取floorId对应的cc,要求从小到大排序。当floorId不存在时返回FALSE。cc为乘于10的
	BOOL GetCC(int floorId,PmGeIntArray & aryCC) const;
	void GetCC(const PmGeIntArray & aryFloorId,PmGeIntArray & aryCC) const;

	//获取所有排序的cc
	void GetCCAll_Sort(PmGeIntArray & aryCC) const;

	//获取下层的cc,不存在返回FALSE,cc为乘于10的
	BOOL GetCCPre(int curCC,int & ccPre) const;

	//获取上层的cc,不存在返回FALSE,cc为乘于10的
	BOOL GetCCNext(int curCC,int & ccNext) const;

	/******************************************************************** 
	功能描述：判断两个cc的相差(des-src)层数,比如-1层与1层只相差1层,0层与1层可能相差6层
	参    数：
	返 回 值：当des比src高时，返回正数。相同时返回0，否则返回负数
	算    法：
	注意事项：1、确保输入的ccDes、ccSrc是存在的
	          2、cc为乘于10的,返回值为间距，不乘于10
	作    者：zfy
	时    间：[22/11/2011]
	*********************************************************************/ 
	int SubCC(int ccDes,int ccSrc);

	/******************************************************************** 
	功能描述：组合楼层的cc名称,aryCC要求排好序:1,2,3将被合成"1~3"; 1,2,4将被合成"1/2/4"
	参    数：
	返 回 值：
	算    法：
	注意事项：-1,0,1不能被合成-1~1
	作    者：zfy
	时    间：[6/12/2011]
	*********************************************************************/ 
	CString JoinCCName(const PmGeIntArray & aryCC) const;

	/******************************************************************** 
	功能描述：用标高来款选相关楼层，仅上下相邻层
	参    数：
	返 回 值：
	算    法：
	注意事项：cc为乘于10的
	作    者：zfy
	时    间：[18/11/2011]
	*********************************************************************/ 
	BOOL GetInsectCC(double diBG,double dingBG,int & iCCDown,int & iCCUp) const;
	BOOL GetInsectCC(double diBG,double dingBG,PmGeIntArray & arrCCInsect,BOOL bInsectPriority) const;

	/******************************************************************** 
	功能描述：获取相邻的cc与本层的cc的集合。计算用,目前我们朝上框2层(kRangeUp变量)，朝下
	框1层(kRangeDown变量)
	参    数：
	返 回 值：
	算    法：1、我们计算2层，需要获取1,2,3,4层数据
	2、要求从小到大排序
	注意事项：cc为乘于10的
	作    者：zfy
	时    间：[18/11/2011]
	*********************************************************************/ 
	//floorId不存在时返回FALSE
	BOOL GetRelativeCC(int floorId,PmGeIntArray & aryCC) const;
	void GetRelativeCC(const PmGeIntArray & floorIdArr,PmGeIntArray & aryCC) const;
	void GetRelativeCCForCal(int cc,PmGeIntArray & aryCC) const;

	/**
	 * @brief 添加几个获取关联floorid的函数
	 *
	 *        
	 * @author 杨兴耀
	 * @version v1.0
	 * @date  [2014年8月21日]
	 * @note  
	 */
	/// 
	void	GetRelationCc2FloorId( const PmGeIntArray & aryCc , PmGeIntArray & aryFloorId ) ;

	/// 
	void	GetRelationFloorId( const int iFloorId , PmGeIntArray & aryFloorId ) ;

	/// 
	void	GetRelationFloorId( const PmGeIntArray & arySrcFloorId , PmGeIntArray & aryDesFloorId ) ;


	/******************************************************************** 
	功能描述：获取相邻的cc。计算用,目前我们朝上框2层(kRangeUp变量)，朝下
	框1层(kRangeDown变量)
	参    数：
	返 回 值：
	算    法：1、我们计算2层，需要获取1,3,4层数据
			  2、要求从小到大排序
	注意事项：cc为乘于10的
	作    者：zfy
	时    间：[18/11/2011]
	*********************************************************************/ 
	void GetNearCC(int floorId,PmGeIntArray & aryCC) const;
	void GetNearCC(const PmGeIntArray & floorIdArr,PmGeIntArray & aryCC) const;


	//获取CC的楼层底标高与楼层顶标高，其为工程标高，用于相邻层判断用,cc为乘于10的
	BOOL GetCCBG(int cc,double & bgBottom,double & bgTop) const;

	/// 
	BOOL GetCcCg( const int iCc , double & dCg ) const ;

	double GetCcLdmbg( const int iCc ) const ;

	//打印成员,测试用
	//void PrintMember() const;

	/// 判断是否有地下室
	BOOL	HasDxs() const; 

	BOOL	IsUnderBaseFloor( const int iFloorId ) const ; 

	/// 是否是底层
	BOOL	IsLastFloor( const int iFloorId ) const ;

	/// 是否是顶层
	BOOL	IsTopFloor( const int iFloorId ) const ;

	/**
	*  @brief : 从floorid获取对应的楼地面标高
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
	//朝下框选1层
	int m_iRangeDown;
	//朝上框选2层
	int m_iRangeUp;

public:
	//把楼层名称拆分为cc。如：1~3拆分为1,2,3; 1/2/4才分为1,2,4。再乘于10
	CFloorCC::CCType SplitFloorName(CString floorName,PmGeIntArray & aryCC);
protected:
	//aryFlooInfo根据aryCC排序,cc为乘于10的
	void SortFloorInfoBy(const PmGeIntArray & aryCC,CArray<CFloorCCInfo,CFloorCCInfo &> & aryFloorInfo) const;
	//对CC进行排序,0层排在最前面，即(0,-2,-1,1,2...),cc为乘于10的
	void SortCC(PmGeIntArray & aryCC) const;
	//是否为夹层,cc为乘于10的
	BOOL IsJiaCC(int cc) const{return ((cc % kBaseOfCC) == 0)?FALSE:TRUE;}

protected:
	//对应的floorId和cc Map
	std::map<int,PmGeIntArray> m_MapIdtoCC;
	std::map<int,int>          m_MapCCtoId;

	CArray<CFloorCCInfo,CFloorCCInfo &> m_aryCCInfo;
	//floorInfo数组
	CArray<CFloorInfo,CFloorInfo &> m_aryFloorInfo;
	//所有有序的cc,如:0,-3,-2,-1,1,2,3,4,5...
	PmGeIntArray m_aryCC;
};

/***************************************************************
Floor.h   version:  1.0   ? date: 18/11/2011
-------------------------------------------------------------

-------------------------------------------------------------
Copyright (C) $YEAR - All Rights Reserved
***************************************************************
文件说明: 用于存储楼层方面的操作与函数(单元测试完毕)
注意事项：1、要求所有的传入的cc均存在
		  2、要求所有的传入的floorId均存在
		  3、程序逻辑上，内部所有cc都是乘于10的，这样可兼容错层
作    者：zfy
时    间：[18/11/2011]
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
//			acutPrintf(_T("\n 注意事项：CFloorCach要求所有的传入的cc均存在;要求所有的传入的floorId均存在!!!"));
//			acutPrintf(_T("\n 通知：CFloorCach保证所有的返回的cc、floorId等都不需要有效性检查!!!"));
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
	//转送对象,以获取对方的方法
	CFloorCC * operator->();

	//重置楼层信息
	static void UpdateFloorInfo();

	//室外设计地坪标高
	double GetSwdpbg() const{return m_dSwdpbg;}
	//自然设计地坪标高
	double GetZrdpbg() const{return m_dZrdpbg;}

protected:
	static CFloorCach * m_pInstance;
	//楼层管理中的信息
	CFloorCC m_floorCC;

	//室外设计地坪标高
	double m_dSwdpbg;
	//自然设计地坪标高
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
		//标高参数模式
		int m_bgMode;				//同OdBGData 0：没有标高，1：底标高 2：顶标高 3：顶底标高

		//底标高 参数名
		CString m_strDiBGParm;		

		//顶标高 参数名
		CString m_strDingBGParm;	

		BGParm(){m_bgMode = 0;}
	};

	//根据工程重新刷新信息
	void UpdateByProject();

	//标高模式信息
	void UpdateBGModeInfo();

	//结构特征信息
	void UpdateFloorGJXXInfo();

	//更新楼层信息
	//返回标高模式，0：楼层标高 1：工程标高
	int GetBGMode(int floorid,int comtype) const;

	//标高参数信息
	const BGParm * GetBGParm(int comtype) const;

	/**
	* @brief 获取结构特征中的构件信息
	*
	*          
	* @note  : 
	* @param : comtypeConvert 此处与正常comtype不一样，需要用comtypeConvert=CAccessProject_FloorGJXXInfoTable::ConvertComType(comtype) ; 转换才可以
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [5/10/2019]
	*/
	BOOL GetFloorGJXXInfo(int floorid,int comtypeConvert,CString fieldName,CString & fieldValue) const;

protected:
	static CProjectSettingCache * m_pInstance;

	//标高管理中的信息: 楼层"floorid|comtype" 与 "标高模式" 的匹配
	std::map<CString,int> m_mapBGMode;

	//默认comtype的标高参数
	std::map<int,BGParm *> m_mapBGParm;

	//结构特征中的构件信息
	//CProject_FloorGJXXInfoTable * m_pDatasetFloorGJXXInfo;
	CSQLDataSet  * m_pDatasetFloorGJXXInfo;

	//
	CProjectSettingCache(void);
	~CProjectSettingCache(void);

	//初始化高度调整用的那张表
	void InitBGParm();
};