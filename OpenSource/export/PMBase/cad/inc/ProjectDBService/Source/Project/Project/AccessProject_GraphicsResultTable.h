#pragma once
////#include "..\accesstable.h"


class PMProjectDBSERVICE CAccessProject_GraphicsResultTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_GraphicsResultTable(void);

	virtual ~CAccessProject_GraphicsResultTable(void);

	BOOL DelResultFloor_Component(int iFloorID, int iComID,const CString & strCADHandle);

	BOOL DelResultCurFloor_Component(int iComID,const CString & strCADHandle);

	

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
	* @brief 获取 计算结果 记录集  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/7/2012]
	*/
	BOOL GetResult_ComIDFloorID_TableCtrl(int iComID,int iFloorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/// 
	BOOL	GetResult_ComType_FloorId_TableCtrl( const int iComType , const int iFloorId , CPMSQLTableCtrl *&pSqlTableCtrl ) ;

	/**
	* @brief  获取 计算结果 总重 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/7/2012]
	*/
	BOOL GetCalResult(int iComID, int iComType,const CString & strHandle, CString &strResult);

	BOOL GetResultSumWeight_GJ(int iFloorID, int iComID, CString strHandle, double &dWeight);

	BOOL DeleteResultInfo( const CUIntArray & iDelIdArr);

	/**
	* @brief  删除指定的楼层 与 构件类型的记录 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [20/7/2012]
	*/
	BOOL DelResultFloor_ComType( const CUIntArray &iFloorIDArr, const  CUIntArray &iComTypeArr);

	BOOL DelResultFloor( const int iFloorId ) ;

	/**
	* @brief   获取整表的数据，不推荐使用，
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-7-12]
	*/
	NDataModelDataSet * GetDataSet() ; 

	CSQLDataSet * GetEmptyDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet * pResultDataSet);

	/// 重新设置id
	void SaveDataSetReCalId(CSQLDataSet * pResultDataSet);

	NDataModelDataSet * GetResultDataSet_DGJCL(int iFloorID,int iComID, CString strHandle,CString & strCurHandle);

	void InsertResult( const int iComId , NDataModelDataSet * pDataSet) ; 

	static PmTString GetSQL(const int iSQLIndex);

	BOOL SaveResult_SimCom(int iFloorID, int iComID, const CString & strHandle, NDataModelDataSet *pResultDataSet);


	/// 
	BOOL GetTableCtrl( 
		const CString & strFloorIds , 
		const CString & strComTypes ,
		CPMSQLTableCtrl *& pTableCtrl 
		) ; 

	/// 
	/// 计算结果锁定的时候调用，只需要获取 handle  一个字段 追加 一个字段id
	///
	/// select id ,cadhandle from graphicsresult where floorid = ? 
	BOOL GetTableCtrl( 
		const int iFloorId ,
		CPMSQLTableCtrl *& pTableCtrl 
		) ; 

protected:
	/// 
	/// mapComId2HandleAry 为不需要删除的构件的handle
	/// 
	BOOL DelResult( const int iFloorId , const PmInt2StrSetMap & mapComId2HandleAry ) ;

	
	/// 
	/// setHandle 为不需要删除的handleset
	/// 
	/// aryResultId 不需要清空
	BOOL	GetResultId( const int iFloorId , const int iComId , const PmStrSet & setHandle , CUIntArray & aryResultId ) ;

public:

	/// 删除指定构件的 计算结果
	/// 该接口只在构件删除的时候调用
	void				DelResult( const int iComId ) ; 

	/// 
	/// 批量删除构件的时候，调用的接口
	/// 
	void				DelResult( const CUIntArray & aryComId ) ; 

	/// 根据结果类型判断是否锁定
	BOOL				IsLock( const int iResultType ) ;

	/// 获取原始的结果类型
	int					GetOrgResultType( const int iResultType ) ; 

	/// 获取锁定后的结果类型
	int					GetLockResultType( const int iResultType ) ; 

	/// 获取指定id的DataSet
	CSQLDataSet	*		GetDataSet( const CUIntArray & aryResultId ) ;				

public:

	void				DeleteResult( const CUIntArray & aryResultId ) ;

protected:


protected:
	

	void				InsertDataSet( NDataModelDataSet * pDataSet ) ;

public:
	/// 去除没有构件与之对应的结果
	void				RemoveDirtyData() ; 

public:

	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		static const int		m_iSelectResult_ComIDFloorID;
		static const PmTString	m_strSelectResult_ComIDFloorID;//通过 comID floorid 获取 记录集

		static const int		m_iDeleteResult_id;
		static const PmTString	m_strDeleteResult_id;

		static const int		m_iDeleteResult_FloorComType;
		static const PmTString	m_strDeleteResult_FloorComType;//按楼层 构件类型 删除

		/// 
		static const int		m_iDelResult ;
		static const PMTSTRING	m_strDelResult ; 

		/// 
		static const int		m_iDelResult_IdArr ;
		static const PMTSTRING	m_strDelResult_IdArr ; 

		/// 
		static const int		m_iInsertDataSet ;
		static const PMTSTRING	m_strInsertDataSet ; 

		///delete from grahicgresult where comid=? and cadhandle=?
		static const int		m_iDeleteResult_ComIDHandle;
		static const PmTString	m_strDeleteResult_ComIDHandle;//按楼层 构件 删除

		///// delete from graphicresult where floorid = ? and cadhandle = ? 
		static const int		m_iDeleteResult_FloorHandle ;
		static const PmTString	m_strDeleteResult_FloorHandle ;

		/// select cadhandle from graphicsresult where floorid = ? 
		static const int		m_iSelectResult_FloorId ;
		static const PMTSTRING	m_strSelectResult_FloorId ;

		/// 根据 floorid 和 comtype 获取，记录集
		static const int		m_iGetComTypeFloorTableCtrl ; 
		static const PMTSTRING	m_strGetComTypeFloorTableCtrl ; 

	};
};



/**
* @brief   封装一些临时对象的定义操作 (充当 新老Access的 适配器)
*
*          
* @note  : 不需要每一个用到的地方都去定义一个临时对象 ， 有一些参数类型的转化可以在该类中实现
*
* @author: 杨兴耀
* @date  : [2012-7-17]
*/

class PMProjectDBSERVICE CProjectGraphicsResultOpr
{
public:
	CProjectGraphicsResultOpr() ;
	~CProjectGraphicsResultOpr() ; 

public:

	static NDataModelDataSet * GetDataSet() ; 
	static NDataModelDataSet * GetEmptyDataSet() ;
	static void InsertResult( const int iComId , NDataModelDataSet * pDataSet) ; 

	/// 根据结果类型判断是否锁定
	static BOOL				IsLock( const int iResultType ) ;

	/// 获取原始的结果类型
	static int					GetOrgResultType( const int iResultType ) ; 

	/// 获取锁定后的结果类型
	static int					GetLockResultType( const int iResultType ) ; 
};
