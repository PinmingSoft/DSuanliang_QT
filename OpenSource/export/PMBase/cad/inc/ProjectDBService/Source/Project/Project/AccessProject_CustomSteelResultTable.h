#pragma once
//#include "..\accesstable.h"


class PMProjectDBSERVICE CProject_CustomSteelResultTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_CustomSteelResultTable)

	CProject_CustomSteelResultTable();
	virtual ~CProject_CustomSteelResultTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					//该表的逻辑id
		static const CString floorid;				//楼层
		static const CString comid;				//构件
		static const CString gjlb;				//钢筋类别
		static const CString gjlx;				//钢筋类型
		static const CString gjjb;				//钢筋级别
		static const CString zj;					//直径
		static const CString gs;					//跟数
		static const CString th;					//图号
		static const CString jt;					//简图
		static const CString jsgs;				//计算公式
		static const CString wg;					//弯勾
		static const CString tqd;					//砼强度
		static const CString dj;					//搭接
		static const CString cd;					//长度
		static const CString jtgs;				//接头个数
		static const CString zz;					//总重
		static const CString gsms;				//公式描述
		static const CString index0;				
		static const CString index1;				
		static const CString index2;				
		static const CString jtparms;				//简图参数
		static const CString sttype;				//钢筋类别 默认0时为计算所得，1时为手工加入
		static const CString jtformula;			//简图计算公式
		static const CString resulttype;			
		static const CString djxs;				
		static const CString errortype;			
		static const CString cc;				
		static const CString ccamount;			

		static const CString table_name;			//钢筋计算结果表
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_CustomSteelResultTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_CustomSteelResultTable(void);

	virtual ~CAccessProject_CustomSteelResultTable(void);

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

	void SetResultDataSet( int nComID , CSQLDataSet * pDataSet ) ;

	void DeleteResnultDataSet( int nComID );

	CSQLDataSet * GetResultDataSet(int nComID );

	/// 
	CSQLDataSet * GetDataSet();

	/**
	* @brief 获取ID的 最大值  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	BOOL GetMaxID(int & iMaxID);

	/// 
	BOOL GetTableCtrl( 
		const CString & strFloorIds , 
		const CString & strComTypes ,
		CPMSQLTableCtrl *& pTableCtrl 
		) ; 

public:

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		//delete from customresult where comid=?
		const static int		m_iDeleteInfo_ComID;
		const static PmTString	m_strDeleteInfo_ComID;

		//select * from customresult where comid=?
		const static int		m_iSelectInfo_ComID;
		const static PmTString	m_strSelectInfo_ComID;

		/// 
		static const int		m_iGetTableCtrl ; 
		static const PMTSTRING	m_strGetTableCtrl ; 

		/// 
		static const int		m_iInsert_ComId ;
		static const PMTSTRING	m_strInsertComId ; 
	};
};
