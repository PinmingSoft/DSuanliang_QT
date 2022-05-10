

#pragma once 

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 工程的高度调整

class PMProjectDBSERVICE CProjectGdtz
{
public:
	CProjectGdtz() ; 
	virtual ~CProjectGdtz() ; 

public:

	/// 
	/// 显示的DataSet需要 disparmname 和 iuputmode 等
	/// 
	static NDataModelDataSet * GetShowDataset( const int iComType ) ;

	/// 
	/// 将 pSrcDataSet 转化为 pDesDataSet 
	///
	/// pSrcDataSet 是本table的结构
	/// pDesDataSet 是显示Dataset的结构
	/// 
	static void	ConvertDataSet( NDataModelDataSet * pSrcDataSet , NDataModelDataSet * pDesDataSet ) ; 

	static BOOL GetBgMode_ComID( const int  nComID , int & nMode) ;

	static BOOL GetBg_XDValue( const int  nComID , int & nMode , double & dibg, double & dbg ) ;

	static BOOL GetBg( const int  nComID , int & nMode , CParm & dibgParam, CParm & dbgParam ) ;

	/* @brief 获取标高模式  
		*
		*          
		* @note  : nMode : 0 : nComID 对应　没有标高
		///			1 : nComID 对应　只有　底标高
		///			2 : nComID 对应　只有　顶标高
		///			3 : nComID 对应　底标高　和　顶标高　都有
		* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
		* @date  : [17/8/2012]
	*/
	static BOOL GetBgMode_ComType( const int nComType, int & nMode);

	/**
	* @brief   获取基准标高的参数名
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [5/11/2018]
	*/
	static BOOL GetBgParmName( const int nComType, int & nMode, CStringArray & arrParmName);

	/**
	* @brief   获取所有标高参数，无论时基准标高还是非基准的联动标高
	*
	*			对于基础构件通常是 一个基准标高 外加一个联动标高
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/11/2020]
	*/
	static BOOL GetBgParmNameFull( const int nComType, int & nMode, CString & topBGParm,CString & bottomBGParm);
} ; 



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
class PMProjectDBSERVICE CSysDataComParmSet_ParmValueCache
{
public:
	CSysDataComParmSet_ParmValueCache();

	virtual ~CSysDataComParmSet_ParmValueCache();

	BOOL GetParmValue(int iComType,int iSubComType,CString strParmName,CString & strParmValue,CString & stInvalidMsg);

protected:

	NDataModelDataSet * m_pComParmSetDataSet;
	int m_GangJinMode;
	int m_DefGangJinMode;
	CStringArray  m_SortFieldArr;
};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
class PMProjectDBSERVICE CSysData_ComParamsSet_GjTable
{
public:
	CSysData_ComParamsSet_GjTable() ; 
	virtual ~CSysData_ComParamsSet_GjTable() ; 

public:
	static  NDataModelDataSet * GetDataSet(const int comType) ;
};