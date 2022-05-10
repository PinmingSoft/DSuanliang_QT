
#pragma  once 



#include "AccessSysDataTable.h"

/**
 * @brief 标高模式
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-9-5]
 * @note  
 */
class PmSLGJDataServiceAPI CSysFloorBGModeTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysFloorBGModeTable)

	CSysFloorBGModeTable();
	virtual ~CSysFloorBGModeTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;			
		static const CString floorid;						//楼层ID
		static const CString comtype;						//构件类型
		static const CString comname;						//构件名称
		static const CString bgmode;						//高模式 0：楼层标高 1：工程标高

		static const CString table_name;					//表名
	};

	virtual int InitFieldStr();
};


class PmSLGJDataServiceAPI CAccessSysData_FloorBGModeTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_FloorBGModeTable(void);
	virtual ~CAccessSysData_FloorBGModeTable(void);

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
	BOOL GetRowCount( int & iRowCount ) ; 


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
	} ;
};
