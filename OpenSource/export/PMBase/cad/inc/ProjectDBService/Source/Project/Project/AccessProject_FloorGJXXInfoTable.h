#pragma once
//#include "..\accesstable.h"
#include "AccessProject_FloorDJMGInfoTable.h"

class PMProjectDBSERVICE CProject_FloorGJXXInfoTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_FloorGJXXInfoTable)

	CProject_FloorGJXXInfoTable();
	virtual ~CProject_FloorGJXXInfoTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					//编号
		static const CString floorid;				//楼层号
		static const CString comtype;				//构件类别编号
		static const CString component;			//构件类别名称
		static const CString tqd;					//砼强度等级
		static const CString zdj;					//砖等级
		static const CString sjdj;				//砂浆等级
		static const CString jdff;				//浇捣方法
		static const CString ldzg;				//离地总高（m）
		static const CString bhc;					//保护层
		static const CString kzdj;				//抗震等级
		static const CString gjlx;				//钢筋类型
		static const CString bfl;					//纵筋搭接百分率
		static const CString zdcmg;				//自动查锚固
		static const CString zdcdj;				//自动查搭接
		static const CString sel_rdgjxs;			//是否要使用 易扰动钢筋系数
		static const CString rdgjxs;				//易扰动钢筋系数
		static const CString sel_bhchdxs;			//是否要使用 锚固区保护层厚度修正系数
		static const CString bhchdxs;				//锚固区保护层厚度修正系数

		static const CString table_name;
	};

	virtual BOOL GetCreateIndexSQL(CStringArray & strFieldNameArr,CString & strIndexName);

	virtual int InitFieldStr();
};


class PMProjectDBSERVICE CAccessProject_FloorGJXXInfoTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_FloorGJXXInfoTable(void);
	CAccessProject_FloorGJXXInfoTable(const CString &strPath);
	virtual ~CAccessProject_FloorGJXXInfoTable(void);

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	/**
	* @brief  刷新 锚固搭接 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [15/10/2012]
	*/
	void ReFreshMGDJ() ;

	//按楼层 构件类型复制
	void CopyFloorComTypeInfo( int nSrcFloorID , 
		const CUIntArray &nArrTargetFloor , 
		const CUIntArray &nArrTargetComType ) ;

	void SetColValue(const CString &strColName, CString strValue, int nFloorID , const CUIntArray &nArrFilterComType);

	void ReSetTQd( int nFloorID , CString strTqd , const CUIntArray &nArrFilterComType);

	void ReSetSjdj( int nFloorID , CString strSjdj , const CUIntArray &nArrFilterComType);

	void ReSetZdj( int nFloorID , CString strZdj , const CUIntArray &nArrFilterComType);

	/**
	* @brief 将图形法的 ComType 转化为 楼层构件信息对应的 ComType  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/7/2012]
	*/
	static int ConvertComType(int nComType);

	/**
	* @brief  将构件法的 ComType 转化为 楼层构件信息对应的 ComType   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/7/2012]
	*/
	static int ConvertComType_Gj( int nComType );

	virtual BOOL TryUpdateTableField();

	/**
	* @brief  获取锚固搭接 信息 
	*
	*          
	* @note  : iComType:只接收 楼层信息 对应的 ComType
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [4/7/2012]
	*/
	BOOL GetMG_DJInfo(int iFloorID,int iComType,const CString & strGJIndex,CProject_FloorDJMGInfoTable::GJZJ gjZJ,BOOL bIsMG,CString & strValue);

	/**
	* @brief   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [5/7/2012]
	*/
	BOOL GetFloorGJXXInfo(int iFloorID,int iComType,CPMSQLTableCtrl *& pFloorGJXXTableCtrl);

	//获取指定的砼强度
	BOOL GetSpecifyTQD( int iFloorID, int nComType , CString& strTQD);
	///BOOL GetSpecifyTQD( int iFloorID, CString strComponent, CString& strTQD);
	
	//获取指定的 离地总高
	BOOL GetSpecifyLDZG( int iFloorID, int nComType , CString & strLDZG);

	//获取指定的砖等级
	BOOL GetSpecifyZDJ( int iFloorID, int nComType , CString& strZDJ);

	//获取指定的砂浆等级
	BOOL GetSpecifySJDJ( int iFloorID, int nComType , CString& strSJDJ);

	//获取指定的浇捣方式
	BOOL GetSpecifyJDFF( int iFloorID, int nComType , CString& strJDFF);

	//获取指定的保护层厚度
	BOOL GetSpecifyBHC( int iFloorID, int nComType , int& iSJDJ);

	/**
	* @brief  获取FloorGJXX表 内容，DataSet需要删除 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [10/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	CSQLDataSet * GetEmptyDataSet() ;

	/**
	* @brief  获取指定行 表内容 ，需要删除 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	CSQLDataSet * GetFloorID_DataSet(int iFloorID);

	/**
	* @brief 获取 最大的 ID值  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL GetTable_MaxID(int & iMaxID);

	/**
	* @brief 获取 楼层 钢筋 系数 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL GetFloorGJXX_XZXS( const int iFloorID,const int iComType,double & dRDGJXS,double & dBHCHDXS);

	/**
	* @brief   根据floorid|convertcomtype 来获取对应的RDGJXS,BHCHDXS值
	*
	*			注意：FloorComtype中的comtype不是正常意义上的comtype,为covertcomtype函数转换过的
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [10/23/2019]
	*/
	BOOL GetFloorGJXX_XZXS(std::map<CString,CString> & mapFloorComtype2TQD ,
		std::map<CString,double> & mapFloorComtype2RDGJXS ,
		std::map<CString,double> & mapFloorComtype2BHCHDXS);

	/**
	* @brief  获取楼层 构件信息及 搭接锚固DataSet
	*
	*          
	* @note  : pFloorGJXXDataSet，pFloorMGDJDataSet（需要删除）
	* @param : int nFloorID:楼层ID
	*			int nComType：构件类型
	*			NDataModelDataSet *& pFloorGJXXDataSet：构件信息
	*			NDataModelDataSet *& pFloorMGDJDataSet：构件搭接锚固
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [1/12/2011]
	*/
	BOOL GetFloorGJXXInfoDataSet( 
		const int nFloorID,
		const int nComType,
		NDataModelDataSet *& pFloorGJXXDataSet,
		NDataModelDataSet *& pFloorMGDJDataSet
		);


	CSQLDataSet * GetDataSet( const int iFloorID , const int iComType ) ;

	/**
	* @brief 更改 抗震等级  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [23/7/2012]
	*/
	void ChangeWithKzdj(const CString & strKzdj ) ;

	void ChangeWithTqd(CString strTqd, int nFloorID);

protected:

	/**
	* @brief 通过指定的 行 获取 扰动系数  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [23/7/2012]
	*/
	BOOL GetFloorGJXX_XZXS_Row(NDataModelDataSet * pFloorGJXXDataSet,int iFloorIDGJXXRow,double & dRDGJXS,double & dBHCHDXS);

	//固定的SQL 集合
	struct SQLInfo
	{
		static const PmTString m_strSelectFloorGJXXInfo_SQL;	//获取整表数据
		static const PmTString m_strSelectFloorMGDJ_SQL;//获取 锚固搭接的sql；
		static const PmTString m_strSelectFloorGJXXInfo_FloorComType_SQL;//获取 楼层钢筋所有信息sql；t
		//static const PmTString m_strSelectFloorTQD_SQL;//获取 砼强度 sql
		//static const PmTString m_strSelectFloorLDZG_SQL;//获取 离地总高 sql
		//static const PmTString m_strSelectFloorZDJ_SQL;//获取 砖等级 sql
		//static const PmTString m_strSelectFloorSJDJ_SQL;//获取  砂浆等级 sql
		//static const PmTString m_strSelectFloorJDFF_SQL;//获取 浇捣方式 sql
		//static const PmTString m_strSelectFloorBHC_SQL;//获取 保护层 sql
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

class PMProjectDBSERVICE CProjectFloorGjxxOpr
{
public:
	CProjectFloorGjxxOpr() ; 
	~CProjectFloorGjxxOpr() ; 

public:
	static BOOL GetFloorGJXX_XZXS( const int iFloorID,const int iComType,double & dRDGJXS,double & dBHCHDXS) ; 

	//获取指定的砼强度
	static BOOL GetSpecifyTQD( const int iFloorID, const int nComType , CString& strTQD);
	///BOOL GetSpecifyTQD( int iFloorID, CString strComponent, CString& strTQD);

	//获取指定的 离地总高
	static BOOL GetSpecifyLDZG( const int iFloorID, const int nComType , CString & strLDZG);

	//获取指定的砖等级
	static BOOL GetSpecifyZDJ( const int iFloorID, const int nComType , CString& strZDJ);

	//获取指定的砂浆等级
	static BOOL GetSpecifySJDJ( const int iFloorID, const int nComType , CString& strSJDJ);

	//获取指定的浇捣方式
	static BOOL GetSpecifyJDFF( const int iFloorID, const int nComType , CString& strJDFF);

	//获取指定的保护层厚度
	static BOOL GetSpecifyBHC( const int iFloorID, const int nComType , int& iBhc);
	static BOOL GetSpecifyBHC( const int iFloorID, const int nComType , CString & strBhc);
};
