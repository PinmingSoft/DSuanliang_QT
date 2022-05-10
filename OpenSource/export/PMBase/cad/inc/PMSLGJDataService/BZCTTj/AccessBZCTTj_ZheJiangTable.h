#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CPMZheJiangTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CPMZheJiangTable)

	CPMZheJiangTable();
	virtual ~CPMZheJiangTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString ctbh;				//承台编号
		static const CString qddj;				//承台混凝土强度等级
		static const CString dzfl;				//单桩反力(KN)
		static const CString zdbbc;				//柱短边边长(mm)a
		static const CString zdbbc2;				//柱短边边长(mm)b
		static const CString zjj;					//桩间距S(mm)
		static const CString bp;					//bp(mm)
		static const CString l1;					//L1(mm)
		static const CString l2;					//L2(mm)
		static const CString h1;					//H(mm)
		static const CString h2;					//h(mm)
		static const CString gj1;					//①钢筋
		static const CString gj2;					//②钢筋
		static const CString gj3;					//③钢筋
		static const CString gj4;					//④钢筋
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CAccessBZCTTj_ZheJiangTable :
	public CPMSLAccessTable
{
public:
	CAccessBZCTTj_ZheJiangTable(void);

	~CAccessBZCTTj_ZheJiangTable(void);
	
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

class PmSLGJDataServiceAPI CBzcttjZheJiangOpr
{
public:
	CBzcttjZheJiangOpr() ;
	~CBzcttjZheJiangOpr() ; 

public:
	static NDataModelDataSet * GetDataSet() ;  
	static NDataModelDataSet * GetEmptyDataSet() ; 

};
