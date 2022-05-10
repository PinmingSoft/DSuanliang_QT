#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_ProjectInfoTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ProjectInfoTable)

	CProject_ProjectInfoTable();
	virtual ~CProject_ProjectInfoTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					//序号
		static const CString parmtype;			//分类显示
		static const CString parmname;			//参数名称
		static const CString disparmname;			//参数显示名称
		static const CString parmvalue;			//参数值
		static const CString inputmode;			//输入模式
		static const CString datatype;			//值类型
		static const CString listdata;			//值列表
		static const CString checkreg;				//格式正则表达式

		static const CString table_name;			//表名
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_ProjectInfoTable:
	public CPMSLAccessTable
{
public:
	CAccessProject_ProjectInfoTable(void);
	CAccessProject_ProjectInfoTable(BOOL bTemplate);
	virtual ~CAccessProject_ProjectInfoTable(void);

	//实物量字段
	static const CString kParm_SWLRule;

	/**
	* @brief   尝试 升级表结构
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/6/2012]
	*/
	virtual BOOL TryUpdateTableField();

	/**
	* @brief  获取工程名称 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [20/7/2012]
	*/
	CString GetProjectName();

	/**
	* @brief  获取参数中 指定参数名的 对应值 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	BOOL GetProjectInfo_ParmValue(const CString & strParmName,CString & strParmValue);
	BOOL GetProjectInfo_ParmValueList(const CString & strParmName,CString & strParmValue,CString & strParmList);

	//获取 用户 清单 定额 信息
	BOOL GetDefaultValueOfQDDE(BOOL &bQDMode,CString &strQDName,CString &strDEName);
	BOOL GetDefaultValueOfQDDE(CString &strQDName,
		CString &strDEName, CString &strDEDataList,
		CString &strCalRuleOfQD,CString &strCalRuleDataListOfQD,
		CString &strCalRuleOfDE,CString &strCalRuleDataListOfDE,
		CString &strCalRuleOfSWL);

	BOOL SetUserValueOfQDDE(BOOL bQDMode,const CString &strQDName,
		const CString &strDEName, const CString &strDEDataList,
		const CString &strCalRuleOfQD,const CString &strCalRuleDataListOfQD,
		const CString &strCalRuleOfDE,const CString &strCalRuleDataListOfDE,
		const CString &strCalRuleOfSWL);

	//设置 实物量规则 信息
	BOOL SetUserValueOfSWLRule(const CString &strCalRuleOfSWL);

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	//获取 工程信息 DataSet
	CSQLDataSet * GetGcxxDataSet();

	//通过 PramType 获取 DataSet
	CSQLDataSet * GetDataSet(CUIntArray & iParmTypeArr);

	///
	CSQLDataSet * GetGctzDataSet() ;

	/**
	* @brief 将 指定参数名的 对应值 设置到表中  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	BOOL SetProjectInfo_ParmValue(const CString & strParmName,const CString & strParmValue);

	/// 
	BOOL	SetProjectInfo_ListData( const CString & strParmName , const CString & strListData ) ;

	/**
	* @brief 获取当前项目的 钢筋模式  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	BOOL GetProject_GangJinMode(ProjectInfoMacro::GangJinMode & gangJinMode);

	//获取 室外设计地坪标高(m)(SWSJDPBG)
	BOOL GetProjectSWSJDPBG(CString &strSWSJDPBG);

	//门材料
	CString	GetMCL(); 
	
	//窗材料
	CString	GetCCL(); 

	//楼地面材料
	CString	GetLDMCL();
	
	//墙面基层材料
	CString	GetJCCL(); 
	
	/// 内墙装饰材料
	CString	GetNQZSCL();

	//外墙面装饰材料
	CString	GetWQZSCL(); 

	//柱面装饰材料
	CString	GetZMZSCL(); 

	//天棚装饰材料
	CString	GetTPZSCL(); 

	//砖基础材料
	CString	GetZJCCL(); 

	//砖膜材料
	CString	GetZMCL(); 

	//砌体墙材料（地下室）
	CString	GetDNQCL(); 
	
	//单梁装饰材料
	CString GetLZSCL();

	//砌体外墙材料
	CString	GetWQCL();

	//砌体内墙材料
	CString	GetNQCL(); 

	//上垫层材料
	CString	GetSDCCL(); 

	//中垫层材料
	CString	GetZDCCL();

	//下垫层材料
	CString	GetXDCCL();

	//模板类型
	CString	GetMBLX();

	//栏杆材料
	CString	GetLGCL();

	//砼拌合要求
	CString GetTBHYQ();

	//土壤类别
	CString	GetTRLB();

	//大基坑开挖形式
	CString	GetKWTFS();

	//坑槽开挖形式
	CString	GetWTFS();

	//运土距离
	CString GetYTJL();

	BOOL GetQbg(CString &strDisplayName , CString &strValue );

	BOOL SetQbg(const CString & strValue) ;

	///柱标准高度(mm)
	BOOL GetZbg(CString &strDisplayName , CString &strValue ); 
	BOOL SetZbg(const CString & strValue) ;

	///梁标准高度(mm)
	BOOL GetLbg(CString &strDisplayName , CString &strValue ) ;
	BOOL SetLbg(CString strValue) ;

	///板标准高度(mm)
	BOOL GetBbg(CString &strDisplayName , CString &strValue ) ;
	BOOL SetBbg(CString strValue) ;

	///长度(m)
	BOOL GetCd(CString &strDisplayName , CString &strValue ) ;
	BOOL SetCd(CString strValue) ;

	///体积(m3)
	BOOL GetTj(CString &strDisplayName , CString &strValue ) ;
	BOOL SetTj(CString strValue) ;

	///面积(m2)
	BOOL GetMj(CString &strDisplayName , CString &strValue ) ;
	BOOL SetMj(CString strValue) ;

	//重量(t)
	BOOL GetZl(CString &strDisplayName , CString &strValue ) ;
	BOOL SetZl(CString strValue);


	///地下水位
	BOOL GetDxsw(CString & strValue , CString &strReg ) ;
	BOOL SetDxsw(CString strValue ) ;

	///室外设计地坪标高(m) 
	BOOL GetSwsjdpbg( CString &strValue , CString &strReg ) ;
	BOOL SetSwsjdpbg(CString strValue );

	///自然设计地坪标高(m)ZRSJDPBG
	BOOL GetZrsjdpbg( CString &strValue , CString &strReg ) ;
	BOOL SetZrsjdpbg(CString  strValue ) ;

	///楼层管理排序方式
	BOOL GetListMode(CString &strValue , CString& strListData ) ;
	BOOL SetListMode(CString strValue ) ;

	///是否使用地下水位
	BOOL GetDxswMode(CString &strValue , CString &strListData ) ;
	BOOL SetDxswMode(CString strValue ) ;

	//设置工程的名称
	void SetProjectName( const CString & strGCMC );
	//设置编制日期
	void SetProjecBZRQ( const CString & strBZRQ );

	/// 锁定构件的颜色
	CString	GetColorOfLockGj() ;
	void	SetColorOfLockGj( const CString & strColorOfLockGj ) ; 

	/// 钢筋结果区显示的列
	CString	GetInvisibleColumns() ; 
	void	SetInvisibleColumns( const CString & strInvisibleColumns ) ;

	/**
	* @brief  获取 项目 定额计算规则名称 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [16/7/2012]
	*/
	BOOL GetProjectDERuleFileName(CString &strDERuleFileName);

	/**
	* @brief  获取 定额 库名称 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [16/7/2012]
	*/
	BOOL GetProjectDEBaseName(CString &strDEBaseName);

	/**
	* @brief  获取 清单规则 名称 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [16/7/2012]
	*/
	BOOL GetProjectQDRuleFileName(CString &strQDRuleFileName);

	/**
	* @brief 获取 清单库 名称  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [16/7/2012]
	*/
	BOOL GetProjectQDBaseName(CString & strQDBaseName);

	/**
	* @brief  获取 清单模式 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/7/2012]
	*/
	BOOL GetProjectQDMode(BOOL &bQDMode);

	/**
	* @brief  获取 实物量计算规则
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [13/9/2017]
	*/
	BOOL GetProjectSwlRuleFileName(CString &strSwlRuleFileName);


	/// 
	BOOL GetColorOfAxis(CString &strColorOfAxis) ;

	void SetColorOfAxis( const CString & strColorOfAxis ) ;
	/// 支模方式的设置值
	BOOL					GetZmfs()  ; 

	/// 统计建筑超高
	BOOL					GetTjjzcg() ; 

	BOOL	GetCgsz( CString & strCgsz ) ;

	/// 获取施工段类别
	void GetSGDLB(CString &strSGDLB);
	void GetSGDLB(CStringArray & arrSGDName);
	/// 设置施工段类别
	BOOL SetSGDLB(const CString &strSGDLB);
	BOOL SetSGDLB(const CStringArray & arrSGDName);

	/******************************************************************** 
	功能描述：获取工程中的自然地坪高
	参数：
	返 回 值：
	算法：
	注意事项：单位 mm
	作    者：王建业
	时    间：[27/3/2008]
	*********************************************************************/ 
	BOOL GetProjectZRDPG(double & dHeight);

	/// 有地下室时不能切换到0层。返回TRUE表示不能切换到0层
	BOOL GetProject_NoChange0Floor();
	void GetProject_NoChange0Floor_ParmValueList(CString & strParmValue,CString & strListData);
	void SetProject_NoChange0Floor(BOOL bNoChange0Floor);

	/**
	* @brief  判断当前工程是否 有轴网 
	*
	*          
	* @note  : 在用户出现楼层删除、轴网删除 这个变量不会变化
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [15/7/2013]
	*/
	BOOL CheckProject_HasAxis();
	BOOL GetProject_FirstAxisFloorID(int & iFloorID);
	void SetProject_FirstAxisFloorID(int iFloorID);

	/// 获取 指定参数 对应的 记录集
	BOOL GetTableCtrl_ParmName(const CString & strParmName,CPMSQLTableCtrl *& pSQLTableCtrl);

	//获取表projectinfo 的 最大 id字段 ，剔除100000字段
	int GetMaxId(NDataModelDataSet * pProjectInfoDataSet) const;

	static PmTString GetSQL(const int iSQLIndex);

	static const int nParmType_Tfdy ;  /// 土方定义
	static const int nParmType_Clsz ;  /// 材料设置
	static const int nParmType_Zmsz ;  /// 支模设置

	static const double dSnbg_Init  ; /// 室内标高初始值

public:

	struct SQLInfo
	{
		static const PmTString m_strSelect_ParmValueSQL;//获取参数值的 sql
		static const PmTString m_strUpdate_ParmValueSQL;//设置参数值的 sql

		static const int m_iSelectAllInfo_ParmNameSQL;
		static const PmTString m_strSelectAllInfo_ParmNameSQL;//通过参数名 获取所有信息 的 sql
	};
};


/**
* @brief   封装一些临时对象的定义操作
*
*          
* @note  : 不需要每一个用到的地方都去定义一个临时对象 ， 有一些参数类型的转化可以在该类中实现
*
* @author: 杨兴耀
* @date  : [2012-7-17]
*/

class PMProjectDBSERVICE CProjectInfoOpr
{
public:
	CProjectInfoOpr();
	~CProjectInfoOpr() ; 

public:
	static BOOL GetColorOfAxis(CString &strColorOfAxis) ;

	static  CString GetProjectName();
	
	static  BOOL GetProjectZRDPG(double & dHeight) ;

	static  BOOL GetProjectDXSW( double & dDxsw ) ;

	static  BOOL GetProjectSWSJDPBG(CString &strSWSJDPBG);

	static  BOOL GetProjectQDMode(BOOL &bQDMode);

	//设置工程的名称
	static  void SetProjectName( const CString & strGCMC );
	//设置编制日期
	static  void SetProjecBZRQ( const CString & strBZRQ );

	static  int  GetGangJinMode() ; 

	static  BOOL GetZmfs() ;

	static	BOOL	GetCgsz( CString & strCgsz ) ;

	static  BOOL	 GetTjjzcg()  ;


	/// 锁定构件的颜色
	static CString	GetColorOfLockGj() ;
	static void	SetColorOfLockGj( const CString & strColorOfLockGj ) ; 

	/// 钢筋结果区显示的列
	static CString	GetInvisibleColumns() ; 
	static void	SetInvisibleColumns( const CString & strInvisibleColumns ) ;

};

/**
 * @brief 构件comid的 控制类 ，
所有的业务模块的 comid都由这个类控制
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2015年5月12日]
 * @note  
 */
class PMProjectDBSERVICE CPmBimComIdOpr 
{
private:
	CPmBimComIdOpr() ; 

public:
	virtual ~CPmBimComIdOpr();
	static CPmBimComIdOpr & Instance() ; 

	enum eSpecialComid
	{
		eCustomComID = SpecComID-1,
	};
public:

	/**
	* @brief   返回的 MaxComId 已经自增了 1 ，外面不需要再去++
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2015年5月12日]
	*/
	int		GetMaxComId() ; 

	/// 
	void	SetMaxComId( const int iMaxComId ) ; 


	/**
	* @brief 将 MaxComId 保存到  ProjectInfo  中， id 固定为 100000  
	*		 不存在时自动新建一条记录
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2015年5月12日]
	*/
	void	SaveMaxComId() ; 


	/// 
	void	InitMaxComId() ; 

protected:
	/// 
	BOOL	HasMaxComId() ; 

	/// 
	void	InsertMaxComId() ; 

protected:
	int		m_iMaxComId ; 

	CString		m_strMaxComIdName ;

};

#define PmBimComIdOpr CPmBimComIdOpr::Instance()
