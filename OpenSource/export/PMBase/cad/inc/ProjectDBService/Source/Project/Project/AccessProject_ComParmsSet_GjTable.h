

#pragma once  


////#include "..\accesstable.h"


class PMProjectDBSERVICE CProject_ComParamsSet_GjTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ComParamsSet_GjTable)

	CProject_ComParamsSet_GjTable();
	virtual ~CProject_ComParamsSet_GjTable();

public:
	virtual int InitFieldStr();

public:
	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString ParmID ;                      
		static const CString comtype ;                     
		static const CString SubComType ;                          
		static const CString parmname ;                    
		static const CString parmvalue ;                   
		static const CString InvalidMsg ;
	};

	struct PMProjectDBSERVICE CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

};

/**
 * @brief 构件发参数总表
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-18]
 * @note  该类的作用只是作为 工程设置保存的值 该类操作获取的DataSet都是SysData中的DataSet 
		  所以该表只需保存部分字段。
 */
class PMProjectDBSERVICE CAccessProject_ComParamsSet_GjTable : public CPMSLAccessTable 
{
public:
	CAccessProject_ComParamsSet_GjTable(void);
	virtual ~CAccessProject_ComParamsSet_GjTable(void);

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
	* @brief   获取版本号
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-7-3]
	*/
	static	int	GetCurVersion() ;

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

	NDataModelDataSet * GetDataSet( const int comType);

	NDataModelDataSet * GetDataSet( const int comType,const int parmType);

	NDataModelDataSet * GetDataSet( const int comType,const int parmType , const int hide ) ;

	NDataModelDataSet * GetEmptyDataSet() ; 

	/**
	* @brief  使用SysData中的数据 对Project中的参数表进行替换 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/9/2012]
	*/
	BOOL InitProjectDataSet();

	/// 保持设置
	void	SaveDataSet( NDataModelDataSet * pDataSet ) ;
	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;

private:

	/**
	* @brief   根据Comtype和parmname获取 parmvalue 和 invalidmsg 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-7-18]
	*/
	BOOL	GetValueAndInvalidMsg( 
		const int iComType , const CString & strParmName ,
		CString & strValue , CString & strInvalidMsg
		) ;

	/// 同步value 和 invalidmsg 
	void	SynsValueAndInvalidMsg( NDataModelDataSet * pDataSet ) ;

public:
	//固定的SQL 集合
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetValueAndInvalidMsg ; 
		static PMTSTRING m_strGetValueAndInvalidMsg ; 
	} ;
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

class PMProjectDBSERVICE CProjectComParamsSetGjOpr
{
public:
	CProjectComParamsSetGjOpr() ;
	~CProjectComParamsSetGjOpr() ; 

public:

	static NDataModelDataSet * GetDataSet() ; 

	static NDataModelDataSet * GetDataSet( const int comType);

	static NDataModelDataSet * GetDataSet( const int comType,const int parmType);

	static NDataModelDataSet * GetDataSet( const int comType,const CUIntArray & aryParmType);

	static NDataModelDataSet * GetDataSet( const int comType,const int parmType , const int hide ) ;

	static NDataModelDataSet * GetEmptyDataSet() ; 

	static void	SaveDataSet( NDataModelDataSet * pDataSet ) ;


};
