#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CPMJiangSuTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CPMJiangSuTable)

	CPMJiangSuTable();
	virtual ~CPMJiangSuTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString ctbh;				//承台编号
		static const CString dzfl;				//单桩反力(KN)
		static const CString qddj;				//承台混凝土强度等级
		static const CString fzbc;				//方桩边长D
		static const CString zxfzbc;				//最小方桩边长a
		static const CString zxfzbc2;				//最小方桩边长b
		static const CString a;
		static const CString a1;
		static const CString a2;
		static const CString b;
		static const CString c;
		static const CString c1;
		static const CString c2;
		static const CString h;
		static const CString h1;
		static const CString h2;
		static const CString gj1;					//①钢筋
		static const CString gj2;					//②钢筋
		static const CString gj3;					//③钢筋

		static const CString table_name;
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CAccessBZCTTj_JiangSuTable :
	public CPMSLAccessTable
{
public:
	CAccessBZCTTj_JiangSuTable(void);

	~CAccessBZCTTj_JiangSuTable(void);

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

	NDataModelDataSet * GetEmptyDataSet() ;

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

class PmSLGJDataServiceAPI CBzcttjJiangSuOpr
{
public:
	CBzcttjJiangSuOpr() ;
	~CBzcttjJiangSuOpr() ; 

public:
	static NDataModelDataSet * GetDataSet() ;  
	static NDataModelDataSet * GetEmptyDataSet() ; 
};
