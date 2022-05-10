

#pragma once 

/**
 * @brief 工程设置中，设置构件参数，统一的控制类
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2013-5-22]
 * @note  
 */


typedef std::set<int> CPmIntSet ; 
typedef CPmIntSet::iterator	CPmIntSetIter ;
typedef CPmIntSet::const_iterator CPmIntSetConIter ; 


/// 
typedef std::map< int , int > CPmInt2IntMap ;
typedef CPmInt2IntMap::iterator CPmInt2IntMapIter ; 
typedef CPmInt2IntMap::const_iterator CPmInt2IntMapConIter ; 


typedef std::map< CString , int > CPmStr2IntMap ;
typedef CPmStr2IntMap::iterator CPmStr2IntMapIter ;
typedef CPmStr2IntMap::const_iterator CPmStr2IntMapConIter ;

class PMProjectDBSERVICE CProjectGlobleParmOpr
{

private:
	CProjectGlobleParmOpr() ; 

public:
	virtual ~CProjectGlobleParmOpr() ; 

	static CProjectGlobleParmOpr & Instance() ; 

public:
	void		Init() ; 

	void		Release() ;

	/// 应用所有的参数， 全局参数类外
	void		ApplyAllDataSet() ;

	/// 处理计算设置中的搭接形式
	void		DealJsszDjxs() ; 

	// 把计算设置保存到数据库文件中
	void SaveJsszToProject();

	void ApplyComParmsSet_ComIdTable();
	///	钢筋模式的切换 03/11/16
	void		ChangeGangJinMode(ProjectInfoMacro::GangJinMode mode) ; 

	/// 判断计算设置是否发生修改
	BOOL		IsGlobalParmModified() const
	{
		if(m_pParmBase)
			return m_pParmBase->GetModified();
		return FALSE;
	}

public:


	/// 计算设置回复默认
	void		ResumeJssz(const int iComType , NDataModelDataSet * pDefaultDataSet , const int iSubComtype = -1) ; 

	/// 
	NDataModelDataSet * GetJsszDataSet( const int iComType , const int iSubComtype = -1) ; 

	/// 
	void SetJsszDataSet( const int iComType , NDataModelDataSet * pJsszDataSet , const int iSubComtype = -1) ;

	/**
	* @brief 提供ComType对应的所有subComType
	*			arrValue代表其编号
	*			arrName代表其名字
	* @author 王荣强
	* @version v1.0
	* @date  [2016-11-01]
	* @note  该函数会清空传入数组;另外该函数效率较低
	*/
	void GetSubComtypeByComtype(const int iComType, CStringArray &arrValue, CStringArray &arrName);

public:
	void		ResumeJsgz( ) ;

public:

	void		ApplyDefaultComponents( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype 
		) ;

	/**
	* @brief   为新建工程新增的函数，对后浇梁做特殊处理  其他不变
	*
	*			
	* @note  : 
	* @param : 
	* @return: 
	* @author: wyz
	* @date  : [7/23/2021]
	*/
	void		ApplyDefaultComponentsNewProject( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype 
		) ;

	/// 应用计算设置
	void		ApplyJsszToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

protected:
	/// 
	/// aryComType 为不需要应用构件的comtype
	/// 
	/// 
	void		ApplyJsszToProjectComId( const CUIntArray & aryInComId , const CUIntArray & aryNotInComId , const CUIntArray & arr_graphcomtype ) ;

protected:
	/**
	* @brief 将sysdata数据库中comparmsset与comparmsset_XXG表替换project数据库中comparmsset_base表
	*
	*        
	* @author 王荣强
	* @version v1.0
	* @date  [2016-11-01]
	* @note  
	*/
	void		CopySysUnionTable2ProTable(ProjectInfoMacro::GangJinMode mode);

	/**
	* @brief 高钢筋模式向低底钢筋模式转换
	*		 目前主要还是替换16G中在11G/03G不存在的量
	*        
	* @author 王荣强
	* @version v1.0
	* @date  [2016-12-26]
	* @note  
	*/
	void		ConvertToLowVersion();

protected:
	void		GetHasSetComId( const CPmIntSet & setHasSetComId , CUIntArray & aryDesComId  ) ;

public:

	void		ApplyJsgzToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		)  ;

protected:
	void		ApplyJsgzToProject(
		const CUIntArray & aryInComId , 
		const CUIntArray & aryNotInComId ,
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		)  ;

public:

	void		ApplyGjsxToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

protected:
	void		ApplyGjsxToProject(
		const CUIntArray & aryInComId , 
		const CUIntArray & aryNotInComId ,
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

	
public:
	// 对钢筋根数计算规则进行全局设置
	void ApplyALLGJ_Rule(const CString& strParmValue);
	void		ApplyDjxsToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

protected:
	void		ApplyDjxsToProject(
		const CUIntArray & aryInComId , 
		const CUIntArray & aryNotInComId ,
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

public:

	/// 计算设置的搭接形式应用
	void		ApplyJsszDjxsToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ; 

protected:
	void	GetInComId( const CUIntArray & aryAllComId , const int iComType , CUIntArray & aryDesComId ) ;

public:

	void		ApplyGjxxToProject( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		)  ;

protected:
	void		ApplyGjxxToProject( 
		const CUIntArray & aryInComId , 
		const CUIntArray & aryNotInComId ,
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		)  ;


protected:
	NDataModelDataSet * GetSpecialDataSet( const PmStrSet & setTotalParm ) ;

	void	GetInComId( const CUIntArray & aryAllComId , const int iFloorId , const int iComType , CUIntArray & aryDesComId ) ;

	//设置parmbase 的值-----不函数仅内部使用，不会判断row的合理性
	void	SetFieldValue(const CString & fieldName, int row, const CString & fieldValue);

public:
	/// 
	void	SetComParm( const CString & strParmName,const CString & strParmValue);

	/// 
	BOOL	GetComParm( const CString & strParmName , CString & strParmValue ) ;

	/// 
	BOOL	GetComParmValueList(const CString & strParmName,CString & strParmValue,CString & strParmList )  ;

	/// 
	BOOL	GetGJTZZ_Const(const CString & strGJBLFS,CString & strDoubleGJTZZ,CString & strSingleGJTZZ);

	/// 
	BOOL	GetGJTZZ_ComParmSet(CString & strDoubleGJTZZ,CString & strSingleGJTZZ);

	/// 
protected:

	/// 
	void	InitParmBase() ;

	/// 
	void	FillParmBase() ; 

	/// 
protected:

	/// 对 comparmsset_base 的一个备份， 多了一列 orgparmvalue 
	NDataModelDataSet * m_pParmBase ; 

	/// 
	static const CString	m_strOrgParmValue ; 
	static const CString	m_strOrgInvaidMsg ; 

};

#define ProjectGlobleParmOpr CProjectGlobleParmOpr::Instance() 