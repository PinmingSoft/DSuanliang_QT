

#pragma once 


#include "AccessSysDataTable.h"

/**
 * @brief 层表
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-9-5]
 * @note  
 */
class PmSLGJDataServiceAPI CSysLayerInfoTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysLayerInfoTable)

	CSysLayerInfoTable();
	virtual ~CSysLayerInfoTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;						//编号
		static const CString floorid;					//楼层ID
		static const CString comtype;					//构件编号
		static const CString layer;					//层名称
		static const CString color;					//层颜色
		static const CString showindex;				//绘制顺序
		static const CString showcolor;				//三维显示颜色
		static const CString layerinfo;				//层显示信息
		static const CString alllayername;			//所有层名
		static const CString showsize;				//显示大小
		static const CString controlmode;				//控制模式 1 控制层 0 不控制层

		static const CString table_name;				//图层表
	};

	virtual int InitFieldStr();
};


class PmSLGJDataServiceAPI CAccessSysData_LayerInfoTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_LayerInfoTable(void);
	virtual ~CAccessSysData_LayerInfoTable(void);

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
