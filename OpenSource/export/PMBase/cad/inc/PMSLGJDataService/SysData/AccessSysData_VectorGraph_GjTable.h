
#pragma once 



#include "AccessSysData_VectorGraphTable.h"

/**
 * @brief 
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-5]
 * @note  
 */
class PmSLGJDataServiceAPI CSysVectorGraph_GjTable : public CSysDataTable
{
	
public:
	DECLARE_DYNCREATE(CSysVectorGraph_GjTable)

	enum GJ_VectorGraphType{VGT_PF,VGT_PARMS};

	CSysVectorGraph_GjTable();
	~CSysVectorGraph_GjTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id ;
		static const CString comtype ;
		static const CString VectorIndex ;
		static const CString VectorGraphName ;
		static const CString Bz ;
		static const CString VectorGraph ;
		static const CString VectorInfo ;
		static const CString VectorGraphType ;
		static const CString GangJinVector;//自定义 钢筋绘制信息 

		static int id_Idx ;
		static int comtype_Idx ;
		static int VectorIndex_Idx ;
		static int VectorGraphName_Idx ;
		static int Bz_Idx ;
		static int VectorGraph_Idx ;
		static int VectorInfo_Idx ;
		static int VectorGraphType_Idx ;
		static int GangJinVector_Idx;//自定义 钢筋绘制信息 

	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

};


class PmSLGJDataServiceAPI CAccessSysData_VectorGraph_GjTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_VectorGraph_GjTable(void);
	virtual ~CAccessSysData_VectorGraph_GjTable(void);

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

	BOOL GetVectorGraph( const int id, const int type, BYTE*&pbuff, int &buffSize);

	BOOL GetVectorGraph( const int id,  BYTE*&pbuff, int &buffSize);

	BOOL GetDataSet_ID(int id,CSQLDataSet *& pSQLDataSet);

	BOOL SetVectorData(int id, LPVOID pbuff, long buffSize) ;

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

	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;


public:
	//固定的SQL 集合
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetVectorGraph ; 
		static PMTSTRING m_strGetVectorGraph ; 

		//
		static const int m_iSelectAllInfo_VectorID;
		static PMTSTRING m_strSelectAllInfo_VectorID;
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

class PmSLGJDataServiceAPI CSysDataVectorGraphGjOpr
{
public:
	CSysDataVectorGraphGjOpr();
	~CSysDataVectorGraphGjOpr() ; 

public:
	static BOOL GetVectorGraph( const int id, const int type, BYTE*&pbuff, int &buffSize);

	static BOOL GetVectorGraph( const int id,  BYTE*&pbuff, int &buffSize);
};
