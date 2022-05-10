
#pragma once 

/**
 * @brief 数据库，批量操作的处理
 *		  一些操作当数据量较大时，处理速度太慢，如 图纸上的删除构件，联动删除计算结果时，太慢
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-9-21]
 * @note  该类使用单键
 */

/// 定义int 到 PmStrSet 的 map 
typedef std::map< int , PmStrSet > PmInt2StrSetMap  ; 
typedef PmInt2StrSetMap::iterator	PmInt2StrSetMapIter ; 
typedef PmInt2StrSetMap::const_iterator PmInt2StrSetMapConIter ; 


/// 
class PMProjectDBSERVICE CPmDataBaseBatchOpr
{
private:
	CPmDataBaseBatchOpr() ; 

public:
	virtual ~CPmDataBaseBatchOpr();
	static CPmDataBaseBatchOpr & Instance() ; 

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// 处理图纸上删除构件时，对应删除计算结果的响应
	/// 
	/// 处理的是当前楼层
public:

	/// 
	void	AddFloorIdHandle( const int iFloorId , const CString & strHandle ) ; 

	void	AddComIdHandle( const int iComId , const CString & strHandle ) ; 

	/// 
	void	Update() ; 


/**
 * @brief 根据数据库获取DATASET 
 * @author 李鑫鹏
 * @version v1.0
 * @date  [2019-11-6]
 * @note
 * @return 成功返回 TRUE 失败返回FALSE
 */
	BOOL	GetDataSetFromDb(const CString strTableName , CSQLDataSet & pDataSet);

private:
	void	Update( const int iFloorId , const PmStrSet & setHandle ) ;

	void	UpdateGraphicResult( const int iFloorId ,  const PmStrSet & setHandle ) ;

	void	UpdatePrivateParm( const int iFloorId , const PmStrSet & setHandle  ) ;

	void	UpdatePrivateQdde( const int iFloorId , const PmStrSet & setHandle ) ;

	/// 跨层构件
	void	UpdateKcEntity( const int iFloorId , const PmStrSet & setHandle ) ;

private:
	CString		FormatHandle( const int iHandleLow , const int iHandleHigh ) ;

private:

	/// 
	PmInt2StrSetMap  m_mapFloorId2HandleSet ; 

};



#define PmDbBatchOpr CPmDataBaseBatchOpr::Instance()