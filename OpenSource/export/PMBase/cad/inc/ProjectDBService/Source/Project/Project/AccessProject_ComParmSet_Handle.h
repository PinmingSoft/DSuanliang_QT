

#pragma once 



////#include "..\accesstable.h"


class PMProjectDBSERVICE CProject_ComParmsSet_HandleTable : public CSQLDataSet
{
	DECLARE_DYNCREATE(CProject_ComParmsSet_HandleTable)

	CProject_ComParmsSet_HandleTable();
	virtual ~CProject_ComParmsSet_HandleTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString	parmid;
		static int				parmid_Index;

		static const CString	comid;
		static int				comid_Index;

		static const CString	handle;
		static int				handle_Index;

		static const CString	subcomtype;
		static int				subcomtype_Index;
		
		static const CString	parmname;
		static int				parmname_Index;

		static const CString	parmvalue;
		static int				parmvalue_Index;

		static const CString	invalidmsg;
		static int				invalidmsg_Index;

	};

	struct PMProjectDBSERVICE CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

/**
 * @brief 私有属性调整后，保存的参数
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2013-5-20]
 * @note  
 */
class PMProjectDBSERVICE CAccessProject_ComParmsSet_HandleTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_ComParmsSet_HandleTable(void);
	virtual ~CAccessProject_ComParmsSet_HandleTable(void);

public:

	/**
	* @brief   尝试 升级表结构
	*/
	virtual BOOL TryUpdateTableField();

	/// 
	CSQLDataSet * GetDataSet();

	/// 
	BOOL		GetDistinctComIdHandle( CPMSQLTableCtrl *& pTableCtrl ) ; 

	/// 
	/// 专用接口
	/// 
	BOOL		GetTableCtrl( const int iFloorId ,  CPMSQLTableCtrl *& pTableCtrl ) ;

	/// 
	BOOL		Delete( const CUIntArray & aryRowId ) ;

	/**
	* @brief  获取空的 Dataset，但是有 执行sql的能力
	* @date  : [13/7/2012]
	*/
	CSQLDataSet * GetEmptyDataSet();

	/// 
	CSQLDataSet * GetDataSet( const int iComId , const CString & strHandle ) ;
	/// 注意此map非空，是按主键已经设置好去实现的。
	void GetDataSet(std::map<std::pair<int, CString>, CSQLDataSet *> & parms_sets);

	/// 获取参数值
	BOOL GetParmValue( const int iComId , const CString & strHandle , const CString & strParmName,CString & strParmValue) ;

	/// 
	void	Delete() ; 

	/// 
	void	Delete( const int iComId ) ;


	void		Delete( const int iComId , const CString & strHandle ) ; 

	void	Delete( const CString strParmName , const CUIntArray & aryComId ) ;

	void	DeleteJssz( const CUIntArray & aryComId ) ; 

	/**
	* @brief 获取二维构件 参数表  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/6/2014]
	*/
	BOOL GetHandleTableCtrl(  const int iComId,const CString & strHandle,  CPMSQLTableCtrl *& pTableCtrl ) ;

public:
	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		///delete from ComParmsSet_Handle
		static const int m_iDelete ;
		static PMTSTRING m_strDelete ;

		/// delete from ComParmsSet_Handle
		static const int	m_iDeleteComIdHandle ;
		static PmTString	m_strDeleteComIdHandle ;
	};
};