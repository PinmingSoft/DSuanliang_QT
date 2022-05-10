

#pragma  once 


#include "AccessSysData_CsfvectordiagramTable.h"

/**
 * @brief 
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CSysCsfvectordiagram_GjTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysCsfvectordiagram_GjTable)

	CSysCsfvectordiagram_GjTable() ;
	~CSysCsfvectordiagram_GjTable() ;

public:
	virtual int InitFieldStr() ; 

public:

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString comtype;
		static const CString parmName;
		static const CString gangjin_mode ;
		static const CString valuevectorid;
		static const CString csflibcode;
		static const CString viewtext;
		static const CString VectorGraph;
		static const CString Msg;
		
		static int id_Idx ;
		static int comtype_Idx ;
		static int parmName_Idx ;
		static int gangjin_mode_Idx ;
		static int valuevectorid_Idx ;
		static int csflibcode_Idx ;
		static int viewtext_Idx ;
		static int VectorGraph_Idx ;
		static int Msg_Idx ;

		/// idx 递增的辅助变量
		/// idx 需要在函数 InitFieldStr 外 ，初始化为有意义的值
		/// 且赋值的顺序应该和 InitFieldStr中添加的顺序一样
		static int idx_step ; 
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};
};

class PmSLGJDataServiceAPI CAccessSysData_Csfvectordiagram_GjTable : public CAccessSysDataTable
{
public:
	CAccessSysData_Csfvectordiagram_GjTable() ;
	~CAccessSysData_Csfvectordiagram_GjTable() ;

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
	* @brief   插入图形
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 返回 id 
	* @author: 杨兴耀
	* @date  : [2012-7-10]
	*/
	int			InsertCSFVector();

	/// 获取空的DataSet 
	CSysCsfvectordiagramTable * GetEmptyDataSet();

	///
	/// 
	///  dataset 需要外围维护 ，可以使用列的index来操作读写数据
	/// 
	NDataModelDataSet * GetCSFVectorDiagramDataSet(  const int comType, const CString & parmName , const CString & libCode);

	/// 获取数据
	BOOL GetVectorGraph( const int id, const int comtype, BYTE*&pbuff, int &buffSize) ;

	BOOL GetVectorGraph( const int id, const int comtype, LPVOID &lpstr, int &buffSize) ;

	BOOL GetVectorGraph(int id, LPVOID &lpstr, int &buffSize) ;

	///
	/// 
	///  dataset 需要外围维护 ，可以使用列的index来操作读写数据
	/// 
	/// 该函数的具体业务不清楚
	/// 需要根据调用的地方去理解
	/// 
	NDataModelDataSet * GetTermDiagramDataSet(
		const int iComType,
		const CString & strParmName, 
		const CString & strTerm
		) ;

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
	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

protected:

	/// 获取最大的id
	int		GetMaxId() ;


public:
	static PMTSTRING	GetSql( const int iType ) ;

	//固定的SQL 集合
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetMaxId ; 
		static PMTSTRING m_strGetMaxId ; 

		/// 
		static const int m_iInsertCSFVector ; 
		static PMTSTRING m_strInsertCSFVector ; 

		/// 
		static const int m_iGetCSFVectorDiagramDataSet ;
		static PMTSTRING m_strGetCSFVectorDiagramDataSet ; 

		/// 
		static const int m_iGetVectorGraph ; 
		static PMTSTRING m_strGetVectorGraph ; 

		/// 
		static const int m_iGetTermDiagramDataSet ;
		static PMTSTRING m_strGetTermDiagramDataSet ;
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

class PmSLGJDataServiceAPI CSysDataCsfvectordiagramGjOpr
{
public:
	CSysDataCsfvectordiagramGjOpr() ; 
	~CSysDataCsfvectordiagramGjOpr() ; 

public:

	static NDataModelDataSet * GetTermDiagramDataSet(
		const int iComType,
		const CString & strParmName, 
		const CString & strTerm
		) ; 

	static NDataModelDataSet * GetCSFVectorDiagramDataSet(  const int comType, const CString & parmName , const CString & libCode);

	/// 获取数据
	static BOOL GetVectorGraph( const int id, const int comtype, BYTE*&pbuff, int &buffSize) ;

	static BOOL GetVectorGraph( const int id, const int comtype, LPVOID &lpstr, int &buffSize) ;

	static BOOL GetVectorGraph(int id, LPVOID &lpstr, int &buffSize) ;
};
