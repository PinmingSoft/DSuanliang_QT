#pragma once
typedef int(*InsertGJAllParm_T)(int iComType, int iFloorID, CString strName, int iVolume,int & iComID);

#include "Project_ComParmsCache.h"
class PMProjectDBSERVICE CComponentsContainer
{
public:
	CComponentsContainer(void);
	virtual ~CComponentsContainer(void);

	/**
	* @brief  转化ComType信息，主要处理 剪力墙 砌体墙翻译
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [28/12/2012]
	*/
	static BOOL TransComType2Arr(int iComType,CUIntArray & iComTypeArr);

	/**
	* @brief   获取指定ComID队列的 信息表
	*
	*          
	* @note  : 返回的所有DataSet都需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [25/9/2012]
	*/
	BOOL GetComponentInfoDataSetArr(CUIntArray & iComIDArr,CPM_StorageDataSet *& pComponentDataSet,\
		CPM_StorageDataSet *& pGraphicMapDataSet,CPM_StorageDataSet *& pVectorGraphicDataSet,\
		CPM_StorageDataSet *& pGJGraphicVectorDataSet,CPM_StorageDataSet *& pOwnGangJinDataSet);

	/**
	* @brief   队列的 信息表
	*
	*          
	* @note  : 
	* @param : CPM_StorageDataSet * pComponentDataSet,构件表
	CPM_StorageDataSet * pGraphicMapDataSet,自定义图形对应表
	CPM_StorageDataSet * pVectorGraphicDataSet,图形算量截面图表
	CPM_StorageDataSet * pGJGraphicVectorDataSet,图形钢筋截面图表
	CPM_StorageDataSet * pOwnGangJinDataSet,自定义钢筋表
	CUIntArray & iOldComIDArr,老ComID队列
	CUIntArray & iNewComIDArr，新ComID队列 
	int iCoverMode：0  新增构件名称
	1  覆盖构件名称 包括属性
	2	覆盖构件名称 不覆盖属性
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [25/9/2012]
	*/
	BOOL AppendComponentInfoDataSetArr(CPM_StorageDataSet * pComponentDataSet,\
		CPM_StorageDataSet * pGraphicMapDataSet,CPM_StorageDataSet * pVectorGraphicDataSet,\
		CPM_StorageDataSet * pGJGraphicVectorDataSet,CPM_StorageDataSet * pOwnGangJinDataSet,\
		CUIntArray & iOldComIDArr,CUIntArray & iNewComIDArr,int iCoverMode);

	/**
	* @brief :  获取当前层与块构件中构件名称相同的构件名称CStringArray。仅块构件功能用。
	*
	* @note  : 
	* @param : 
	* @return: 
	* @author: 魏将明
	* @date  : [28/9/2012]
	*/
	BOOL GetSameComNameAry_Kgj(CPM_StorageDataSet * pComponentDataSet, CStringArray &aryComName, BOOL & bHasNotFind);

	/**
	* @brief  通过ComID 刷新房间名称 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [18/12/2012]
	*/
	static BOOL ReFreshFangJianComParms_ComID(int iComID);
	static BOOL ReFreshFangJianComParms_ComID(int iComID,const std::map<int,int> & mapOldComid2New);
	static BOOL ReFreshFangJianComParms_ComID(int iComID,NDataModelDataSet * pComParmsDataSet);
	static BOOL ReFreshFangJianComParms_ComID(int iComID,NDataModelDataSet * pComParmsDataSet,const std::map<int,int> & mapsComidOld2New);

	/**
	* @brief 判断构件类型是否 可以显示  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [24/7/2012]
	*/
	static BOOL CheckComType_ShowUpFloor(int iComType);

	/**
	* @brief 判断构件类型是否 可以显示  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: lbw
	* @date  : 2020/1/10
	*/
	static BOOL CheckComType_ShowUpFloorAddJC(int iComType);

	/**
	* @brief   获取 0Q ComID
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [24/7/2012]
	*/
	static BOOL GetOQComID(int &iComID);

	/**
	* @brief  获取 工程标高 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [23/7/2012]
	*/
	static double GetGcbg( const int & nComID , const double & dLcbg ) ;

	/**
	* @brief  获取 工程标高 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [23/7/2012]
	*/
	static double GetLcbg( const int & nComID , const double & dGcbg ) ;

	/**
	* @brief  在参数表中 搜索 指定 的 参数 值 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	static CString			GetParmValue( NDataModelDataSet * pComParmsDataSet ,  const CString & strParmName ) ; 

	/**
	* @brief 在配筋图参数中 搜索参数  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [5/7/2013]
	*/
	static BOOL GetVectorParm_ParmValue( NDataModelDataSet * pVectorParmDataSet ,  const CString & strParmName ,CString & strParmValue) ;

	/**
	* @brief   在参数表中 搜索 指定 的 参数值
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	static BOOL			SetParmValue( NDataModelDataSet * pComParmsDataSet ,  const CString & strParmName ,CString  strParmValue ) ;

	/******************************************************************** 
	功能描述：获取所有构件 显示参数表
	参数：
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[11/9/2009]
	*********************************************************************/ 
	static BOOL GetGJDisAllAttParm(int iComID, CParms & Attparms);

	//注册和取消注册 插入新构件 并生成参数
	static BOOL RegistInsertGJAllParmCallBack(InsertGJAllParm_T pCalBackFun);
	static BOOL UnRegistInsertGJAllParmCallBack();

	// hn 2016.10.08 删除comid改为将删除的记录存放在componentsdel表中，后期可做恢复，避免找不到comid崩溃
	static BOOL DelComponent_ID(int iComID);
	static BOOL DelComponent_IDNew(int iComID);

	static BOOL DelComponent_IDArr(const CUIntArray & iComIDArr);
	static BOOL DelComponent_IDArrNew(const CUIntArray & iComIDArr);


	/**
	* @brief  获取指定构件参数表  钢筋 VectorID
	*
	*          
	* @note  : 
	* @param :
	*			
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/11/2011]
	*/
	static int GetComParms_VectorID_GJ(int iComID);

	//zfy note 2020.05.29,目前已把这函数等同于 GetComParms_VectorID_GJ，以便编译通过，但尽量还是用 GetComParms_VectorID_GJ ，这样定义更明确
	static int GetComParms_VectorID(int iComID);
	/**
	* @brief  获取指定构件类型的 参数表 
	*
	*          
	* @note  : 
	* @param :
	*			CUIntArray &iParmTypeArr ：构件参数 类别（是算量参数 钢筋参数）
	*			NDataModelDataSet * pComParmDataSet：需要按参数类型过滤的参数
	* @defenc: 
	* @return: 返回DataSet需要 删除
	* @author: 王建业
	* @date  : [29/11/2011]
	*/
	static BOOL GetComParmsDataSet_ParmType(int iComID,CUIntArray &iParmTypeArr,NDataModelDataSet *& pComParmDataSet);

	/**
	* @brief  根据iComponentComType 来设置参数hide的标记
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	static BOOL FillNoNeedParms(int iComID,int iComType,NDataModelDataSet * pComParmsDataSet);

	/**
	* @brief 根据iComponentComType 来设置参数hide的标记
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [12/11/2018]
	*/
	static void FiterParmsWithComponentComType(int iComID,int iComType,int iComponentComType,NDataModelDataSet * pComParmsDataSet);

	/**
	* @brief  	//需在工程标高或楼层标高模式下计算
	*
	*          
	* @note  : 
	* @param : nChangeMode : 0 表示 插入点标高、顶底标高 要减去一个楼地面标高 进行显示，通常用于将UI的dataset(工程标高)转为数据存储用
							 1 表示 插入点标高、顶底标高 根据实际标高模式决定加减进行联动，或者存储用dataset转界面用UI的dataset
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	static BOOL ReCalComponentBGExtend(int iComID,int iCalMode, int iComType,NDataModelDataSet *pDataSet);

	//按标高模式重新显示标高的中文名
	static BOOL ShowChNameDisplay_BG(int iComID,int nChangeMode, int iComType,NDataModelDataSet *pDataSet);

	/**
	* @brief   重新联动标高
	*
	*			1.用于某标高改动过后，另一标高或者插入点标高重算
	*			2.用于界面显示时的的工程标高重算
	*			3.本函数的定义修改是因为 qc:26038
	* @note  : 本函数 是 基于原先的 他人写的的 ReCalComponentBG 进行重新修改。重新 清晰定义了 参数含义
	* @param : nChangeMode : 0 表示 插入点标高、顶底标高 要减去一个楼地面标高 进行显示，通常用于将UI的dataset(工程标高)转为数据存储用
							 1 表示 插入点标高、顶底标高 根据实际标高模式决定加减进行联动，或者存储用dataset转界面用UI的dataset
							 2 通常 插入点标高、顶底标高 存在联动，顶底标高 不进行楼地面标高的加减,插入点标高根据实际标高模式决定加减进行联动。用于dataset间的复制
	*
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/17/2018]
	*/
	static BOOL ReCalComponentBG(int iComID,int nChangeMode, int iComType,NDataModelDataSet *pDataSet);

	//重算 标注
	static BOOL ChangeWithBz( const int & nComID ,const CString &strBz );

	/**
	* @brief  重算构件 备注
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	static BOOL ReSumGJBz_VectorInfo(int iComID, CString &strVectorInfo);

	/**
	* @brief  重算顶 底 标高
	*			
	*          qc:30186,此 pDataSetForDb 我们为数据库存储用的标高，统一为相对标高 
	* @note  : 
	* @param : pDataSet
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	static BOOL ReCalComponentDbg_Dibg(int iComID, CString strEditParmName, NDataModelDataSet * pDataSetForDb);

	/**
	* @brief  重算 截面 参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	static BOOL ReBuildJMParm(int iComID,int iComType,CString & strJM);

	//添加一个 专门判断 柱截面的 函数
	//nMode 截面的 模式
	//1 : 矩形, 2 :圆形 ,3 :异形,4:半圆形,5:圆环形,6:T形,7:十字形,8:Z字形,9:L形,
	//10:梯形,11:正六边形,12:正八边形,13:工字形1,14:工字形2
	static BOOL CheckVectorMode_Zhu(int iComID, int &nMode);

	/******************************************************************** 
	功能描述：检查配筋图是否是矩形
	参数：int iComID,BOOL & bMode TRUE：矩形 FALSE：异形
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[29/4/2008]
	*********************************************************************/ 
	static BOOL CheckVectorMode(int iComID, BOOL &bMode);

	/******************************************************************** 
	功能描述：检查当前构件 检查配筋图是否是矩形
	参数：int iComID,BOOL & bMode TRUE：矩形 FALSE：异形
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[29/4/2008]
	*********************************************************************/ 
	static BOOL GetCurGjVectorMode(BOOL &bMode);

	/******************************************************************** 
	功能描述：根据ComType 获取顶标高 底标高的参数名称
	参数：iComType：构件类型，iBGMode：0 没有标高，1：只有顶标高，2：只有底标高 3：都有，
	strDingParmName：顶标高参数名 strDiParmName：底标高参数名
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[2010:12:29]   16:56
	*********************************************************************/ 
	static BOOL GetBGInfo_DingDiParmName(int iComType,int & iBGMode,CString & strDingParmName,CString & strDiParmName);

	/**
	* @brief  获取指定ComID的参数表中的 参数值
	*
	*          
	* @note  : 
	//CComParmsSet_ParmName::Globel_ParmType = 1;全局参数
	//CComParmsSet_ParmName::SL_ParmType = 2;算量参数, 钢筋中也要出现的算量参数
	//CComParmsSet_ParmName::GJ_ParmType = 3;钢筋参数
	//CComParmsSet_ParmName::GJ_JSSZ_ParmType = 4;计算设置参数
	//CComParmsSet_ParmName::SL_ParmType_OL = 5 ; 在算量中才出现的属性参数
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	static BOOL GetComAttribute(int comID,int iParmType,const CString & sAttributeKey,CString &sValue);
	static BOOL GetComAttribute(int comID,const CString & sAttributeKey,CString &sValue);

	static BOOL GetComAttribute(NDataModelDataSet * pComParmsDataSet , int comID,int iParmType,const CString & sAttributeKey,CString &sValue);
	static BOOL GetComAttribute(NDataModelDataSet * pComParmsDataSet , int comID,const CString & sAttributeKey,CString &sValue);
	static BOOL GetComAttribute(NDataModelDataSet * pComParmsDataSet 
								,int comID
								,int iParmType
								,const CString & sAttributeKey
								,CString &sValue
								,CString &sValueNoTrans);
	static BOOL GetComAttribute(int comID,const CSubComtypeParms * pParms_SX,const CParms * pParms_Vector,const CString & sAttributeKey,CString & sValue,BOOL bTransComParms);
	static BOOL GetComAttribute(int comID
								,const CSubComtypeParms * pParms_SX
								,const CParms * pParms_Vector
								,const CString & sAttributeKey
								,CString & sValue
								,CString & sDisplayName
								,CString & sInvalidMsg
								,BOOL bTransComParms);

	static BOOL GetComAttribute_NotTrans(int comID,int iParmType,CString sAttributeKey,CString &sValue );
	static BOOL GetComAttribute_NotTrans(int comID,CString sAttributeKey,CString &sValue );
	static BOOL GetComAttribute_NotTrans(NDataModelDataSet * pComParmsDataSet,int comID,int iParmType,CString sAttributeKey,CString &sValue );
	static BOOL GetComAttribute_NotTrans(NDataModelDataSet * pComParmsDataSet,int comID,const CString & sAttributeKey,CString &sValue);
	/**
	* @brief  设置 指定的参数 到构件中
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	static BOOL SetComAttribute(int comID,int iParmType,const CString & sAttributeKey,CString strValue);

	static BOOL SetComAttribute(int comID,const CString & sAttributeKey,CString strValue);

	static BOOL SetComAttributeForComponentType(int comID, int componentType, const CString & sAttributeKey,CString strValue);

	static BOOL SetComAttribute(NDataModelDataSet * pComParmDataSet ,int iParmType,const CString & sAttributeKey,CString strValue);

	static BOOL SetComAttribute(NDataModelDataSet * pComParmDataSet ,const CString & sAttributeKey,CString strValue);

	static BOOL SetComAttributeForComponentType(NDataModelDataSet * pComParmDataSet ,int componentType, const CString & sAttributeKey,CString strValue);

	/**
	* @brief  通过 ComID parmtype，获取 指定参数的信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [1/8/2012]
	*/
	static BOOL GetComParmInfo(int comID,int iParmType,const CString strParmName,CString & strDisParmName,CString & strParmValue,\
		CString & strInvalidMsg);

	static BOOL GetInvalidMsg( const int comID,const int iParmType,const CString & strParamName , CString &strInvalidMsg );
	static BOOL GetInvalidMsg( const int comID,const CString & strParamName, CString &strInvalidMsg  );

	static BOOL GetInvalidMsg( NDataModelDataSet * pComParmsDataSet , const int comID,const CString & strParamName, CString &strInvalidMsg  );

	static BOOL SetInvalidMsg( const int iComId , const CString & strParmName , const CString & strInvalidMsg ) ;

	//是否仅是层高或层底相关的表达式
	static BOOL IsFloorExp(CString strParmValue);

	//计算层高表达式
	static double CalFloorExp(CString strParmValue,double dCg);
	//
	static BOOL IsExp(CString strParmValue,CString strParmName);

	//表达式替换,strParmValue 可以为 $cg + 350,  strExpList格式为:  $cg=200|$sjswdp=-100|$zrsjdp=20
	static double CalExp(CString strParmValue,CString strExpList);

	/**
	* @brief   strParmValue 可以为 $cg + 350 ,strParmName为$cg, dCg 为 $cg的值
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [1/9/2018]
	*/
	static double CalExp(CString strParmValue,CString strParmName,double dCg);

	/**
	* @brief 对参数Value中的特殊变量 进行翻译  
	*
	*          注意：取层高仅被翻译为层的高度,取层底仅被翻译为0，取标高被翻译为楼层底的工程标高
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	static CString TransComParms_ParmValue(int iComID,CString strParmValue);

	////////////////////////////////////////////
	/// 郑琪崇 [2014年5月21日]
	/// 说明:
	/// 翻译参数，版本2 ， 
	/// 翻译的值，通过strTransValue 返回。
	/// 函数返回值表示 翻译的值 是工程标高的(TRUE)，还是楼层标高的(FALSE)
	/// 一般都是楼层标高的，少部分为 工程标高，如$sjswdp /$zrsjdp
	static BOOL TransComParms_ParmValueV2( const int iComID, const CString & strParmValue , CString & strTransValue );

	/******************************************************************** 
	功能描述：判断某个参数是否需要翻译
	参    数：nComID : 构件ID ; sAttributeKey : 参数名　; bHasTranslate 是否需要翻译 
	返 回 值：执行是否成功
	算    法：需翻译的　值　都是　带　'$' 标志的
	注意事项：
	作    者：杨兴耀
	时    间：[27/5/2008]
	*********************************************************************/ 
	static BOOL ComParmNeedTranslate( const int  nComID , const  CString & sAttributeKey,BOOL &bNeedTranslate);

	/**
	* @brief  根据构件信息 获取 DJXS 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [23/7/2012]
	*/
 	static BOOL GetComParm_DJXSDataSet(const int nComID,  NDataModelDataSet *& pDJXSDataSet);
// 
// 	static int GetComDjxs( const int iComId ,  const CString & strHandle , const double & dDia , const BOOL bVertical = FALSE ) ; 
// 	static int GetComDjxs( const int iComId ,  const CString & strHandle , const CString & strDia , const BOOL bVertical = FALSE ) ;


	/**
	* @brief   获取构件的搭接形式，以CString的返回
	*
	*          
	* @note  : 
	* @param : bNeedSx 是否需要竖向搭接 
	* @defenc: 
	* @return: 返回的string的样式 : /// m_strDJXS格式为 6-10$1;12-20$1;24-30$3	
									/// m_strDJXS格式为 3-10$1&1;12-14$1&1;16-22$4&4;25-50$8&8	
	* @author: 杨兴耀
	* @date  : [2012-9-4]
	*/
	static CString	GetComParmDjxs( const int iComId  , const BOOL bNeedSx = FALSE ) ;

	/******************************************************************** 
	功能描述：获取指定构件的sAttributeKey 的显示名称
	参数：comID：构件ID sAttributeKey：构件参数名 sAttrDisName：返回的显示名称
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[23/4/2008]
	*********************************************************************/ 
	static BOOL GetComAttrDisParmName( const int comID, const CString & sAttributeKey,CString &sAttrDisName) ;

	/**
	* @brief  插入构件的 回调接口
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [18/7/2012]
	*/
	static int InsertGJ_AllParm(int iComType, int iFloorID, CString strName, int iVolume,int & iComID);

	/**
	* @brief 翻译成显示 值  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [18/7/2012]
	*/
	static CString TransShowParmValue(int iComID,const CString & strParmName,const CString & strParmValue);

	static BOOL CheckComType_CanCalInGJ(int iComType);

	static BOOL CheckComType_CanCalInSL(int iComType);

	/**
	* @brief  判断这个构件类型 是否可以显示在 钢筋界面
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [10/10/2013]
	*/
	static BOOL CheckComType_CanShowInGJ(int iComType);

	/**
	* @brief  判断这个构件类型 是否可以显示在 算量界面
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [10/10/2013]
	*/
	static BOOL CheckComType_CanShowInSL(int iComType);

	static int Get_GJComType( const int comID);

protected:

//	static int GetComDjxsTemp( const int iComId , const CString & strHandle ,  const double & dDia , const BOOL bVertical = FALSE ) ;

	static BOOL GetComponentInfoDataSetArr_VectorInfo(CUIntArray & iComIDArr,\
		CPM_StorageDataSet * pGraphicMapDataSet,\
		CPM_StorageDataSet * pVectorGraphicDataSet,\
		CPM_StorageDataSet * pGJGraphicVectorDataSet);
	
	//重新命名块构件名称
	static void ReBuildGjName( CString& strTemComName );
	
	/**
	* @brief  重新改写装饰的ComId
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 郑琪崇
	* @date  : [2015/07/10]
	*///
	void ReBuildComId_ZS(const CUIntArray & iNewComIDArr, const CUIntArray & arrComtype,const CUIntArray & iOldComIDArr );
	static InsertGJAllParm_T s_pInsertGJAllParmCalBackFun;
};
