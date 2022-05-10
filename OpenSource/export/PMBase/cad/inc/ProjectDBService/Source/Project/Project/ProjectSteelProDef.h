

#pragma once 


/**
 * @brief 钢筋属性定义 界面中 ， 对钢筋属性的缓冲 
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2013-5-27]
 * @note  
 */

typedef std::map< int , NDataModelDataSet * > PmInt2DataSetMap ; 
typedef PmInt2DataSetMap::iterator PmInt2DataSetMapIter ; 
typedef PmInt2DataSetMap::const_iterator PmInt2DataSetMapConIter ; 


class PMProjectDBSERVICE CProjectSteelProDefOpr
{
private:
	CProjectSteelProDefOpr() ; 

public:
	virtual ~CProjectSteelProDefOpr() ; 

	static CProjectSteelProDefOpr & Instance() ; 


public:
	/// 退出属性定义，触发保存
	void	Save() ; 


	void	Release() ;

public:

	///获取构件的参数(all)
	NDataModelDataSet * GetComParm( const int iComId )  ;

	/// 
	/// 获取钢筋与算量混合的属性定义，有重算标高，隐藏参数
	/// 
	NDataModelDataSet * GetSxdyDataSet( const int iComId ) ; 

	/// 仅获取钢筋属性定义
	NDataModelDataSet * GetGJ_SxdyDataSet( const int iComId ) ;

	/// 仅获取算量属性定义
	NDataModelDataSet * GetSL_SxdyDataSet( const int iComId ) ; 


	/// 
	/// 设置属性定义的数据到，构件参数
	/// 
	void		SetSxdyDataSet( const int iComId , NDataModelDataSet * pSxdyDataSet ) ;


	/// 
	NDataModelDataSet * GetJsszDataSet( const int iComId ) ; 

	/// 
	void		SetJsszDataSet( const int iComId , NDataModelDataSet * pJsszDataSet ) ;

	/// 
	int			GetComponentType( const int iComId ) ;

	/// 
	NDataModelDataSet * GetBaseSxDataSet( const int iComId ) ;

	void		SetBaseSxDataSet( const int iComId , NDataModelDataSet * pBaseSxDataSet ) ; 

	/// 
	NDataModelDataSet * GetDjxsDataSet( const int iComId ) ;

	void		SetDjxsDataSet( const int iComId , NDataModelDataSet * pDjxsDataSet ) ;

public:
	void		SetDataSet( const int iComId , const NDataModelDataSet * pDataSet ) ;


};


#define ProjectSteelProOpr CProjectSteelProDefOpr::Instance() 