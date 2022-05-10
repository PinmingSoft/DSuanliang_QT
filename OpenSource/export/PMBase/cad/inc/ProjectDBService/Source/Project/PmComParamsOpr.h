

#pragma once 

/**
 * @brief 处理参数的操作类 
 *			这里操作所用的 ComType 都是FloorGJXX 对应的 ComType
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-19]
 * @note  
 */

class PMProjectDBSERVICE CPmComParamsOpr
{
public:
	CPmComParamsOpr() ;
	~CPmComParamsOpr() ; 

public:

	//去除 计算设置 参数
	static BOOL RemoveJSSZParmValue_Component();

	//保存参数表 到 默认参数中
	//static void SaveComParmTable_DataSet(NDataModelDataSet *pData);

	/**
	* @brief  设置构件参数 的 默认值 
	*
	*          
	* @note  : 
	* @param : const int iComType：构件类型
	*			const int iFloorID：所在楼层
	*			NDataModelDataSet * pComParmsSet ：要重置的DataSet
	*			BOOL bIsGraphic：是否是图形法
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [14/9/2012]
	*/
	static BOOL SetDefaultComParmValue(  const int iComType,const int iFloorID, NDataModelDataSet * pComParmsSet ,BOOL bIsGraphic);

	static BOOL GetFloorGjxxParmValue(int iComType,int iFloorID,const CString& strParmName,CString& strParmValue);

	static BOOL GetFloorGJXX_ParmValue(const int & nFloor, const int & nComType , const CString & strParmName ,CString & strValue,CPMSQLTableCtrl * pFloorGJXXTableCtrl  ) ;

	static BOOL Get03GFloorMGDJValue(int iFloorID,int iComType,const CString & strParmName,CString & strParmValue  );

	static BOOL Get11GFloorMGDJValue(int iFloorID,int iComType,const CString & strParmName,CString & strParmValue  );

	///  所有的项都保存 ---- 在构件收藏中用到 
	///  收藏构件的时候 应该 把收藏的构件的 所有的参数值都保存下来
	///  因为 不知道在哪里应用, 所以需要 保存所有的参数值 
	static CString SaveComParm2Str_Full ( int nComID , NDataModelDataSet * pDataSet ) ; 

	//设置默认 参数总表的 箍筋组合方式
	//static BOOL SetComParmGujinZhuhe();

	/**
	* @brief  按照构件类型 获取 计算设置 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [23/7/2012]
	*/
	static NDataModelDataSet * GetComParmsTable_Jssz(int nComType);

	/**
	* @brief   设置参数总表中 指定参数名的 参数值
	*
	*          
	* @note  : 
	* @param : const CString & strParmName：要设置的参数名称
	*			const CString & strParmValue:要设置的 参数值
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/11/2011]
	*/
//	static BOOL SetComParms_TotalTable_ParmValue(const CString & strParmName,const CString & strParmValue);

	static BOOL GetComParms_TotalTable_ParmValueList(const CString & strParmName,CString & strParmValue,CString & strParmList);

	static BOOL GetGJTZZ_Const(const CString & strGJBLFS,CString & strDoubleGJTZZ,CString & strSingleGJTZZ);

	static BOOL GetGJTZZ_ComParmSet(CString & strDoubleGJTZZ,CString & strSingleGJTZZ);

	/**
	* @brief   获取 构件表中的 指定参数名称的 正则表达式
	*
	*          
	* @note  : 
	* @param : const int nComType ：构件类型
	*			const CString & strParmName ：构件名称
	*			CString  &strRegValue:返回正则表达式
	*
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/11/2011]
	*/
	//private:
	static	BOOL GetComParmSetTable_CheckReg( const int nComType , const CString & strParmName , CString  &strRegValue);


	/**
	* @brief  获取03G参数总表中 指定参数名的 参数值  
	*
	*          
	* @note  : 此函数 只会去 03G中的参数
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/11/2011]
	*/
	static BOOL GetComParms_Total03GTable_ParmValue(const CString & strParmName,CString & strParmValue);

	/******************************************************************** 
	功能描述：获取完整构件属性
	参数：
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[27/3/2009]
	*********************************************************************/ 
	static NDataModelDataSet * GetComponentFullGJSX( const int iComID );

	/**
	* @brief  保存 界面修改的属性 
	*
	*          其内部存在参数附加的设置与标高联动
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [25/7/2012]
	*/
	static void SetComAttributes_UI( int iComID , NDataModelDataSet * pDataSet ) ;

	/// 保存界面修改---与上面的函数的区别是，不进行额外的标高联动处理
	static void SetComAttributes_UISimple( int iComID , NDataModelDataSet * pDataSet) ;

	//计算设置专用的参数设置
	static void SetComAttributes_JSSZ( int iComID , const NDataModelDataSet * pDataSet ) ;

public:
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// 获取参数的的常量 --- 界面使用的接口 ，临时读取文件，效率偏低
	/// 
	static CString	GetCheckReg(const int iComType , const CString & strParamName ,const CString & strSubComType = _T("0") ) ;
	static CString	GetListData( const int iComType , const CString & strParamName ,const CString & strSubComType  = _T("0") ) ;
	static CString	GetValidateExpr( const int iComType , const CString & strParamName , const CString & strSubComType  = _T("0") ) ;
	static CString	GetHitInfo( const int iComType , const CString & strParamName , const CString & strSubComType  = _T("0") ) ;

	static CString	GetCheckRegInt(const int iComType , const CString & strParamName ,const int  iSubComType = 0 ) ;
	static CString	GetListDataInt( const int iComType , const CString & strParamName ,const int  iSubComType = 0 ) ;
	static CString	GetValidateExprInt( const int iComType , const CString & strParamName , const int  iSubComType = 0 ) ;
	static CString	GetHitInfoInt( const int iComType , const CString & strParamName ,const int  iSubComType = 0 ) ;


private:
	static	CString	GetConfigPath() ; 
	static	BOOL	GetComParmConstValue( const CString & strAppName , const CString & strKeyName , CString & strKeyValue ) ;

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// 工程设置中的一些下拉选项的值和常量
public:
	static CString	Getlcxz()  ;
	
	static CString GetTQD() ;
	
	static CString GetZDJ() ;
	
	static CString GetSJDJ() ;
	
	static CString GetKZDJ() ;
	
	static CString GetGJLX() ;
	
	static CString Getbfl() ;
	
	static CString GetJDFF() ;
	
	static CString Getbhc() ;
	
	static CString GetCG();

	static CString GetDjxs() ;
	
	/*static CString GetLDZG();*/

private:
	static CString GetConstFilePath() ; 

	static BOOL		GetListData( const CString & strAppName , const CString & strKeyName , CString & strKeyValue ) ;
	
};
