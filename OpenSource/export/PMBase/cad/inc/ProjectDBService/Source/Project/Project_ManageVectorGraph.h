// ManageVectorGraph.h: interface for the CManageVectorGraph class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Project_MANAGEVECTORGRAPH_H__EE1FFC83_E229_404F_B62A_94E2ECECED3A__INCLUDED_)
#define AFX_Project_MANAGEVECTORGRAPH_H__EE1FFC83_E229_404F_B62A_94E2ECECED3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include ".\project\PMVectorGraphicCtrl.h"
// ***************************************************************
//  ManageVectorGraph   version:  1.0   ? date: 08/31/2009
//  -------------------------------------------------------------
//  管理访问图形的接口
//  -------------------------------------------------------------
//  Copyright (C) 2009 - All Rights Reserved
// ***************************************************************
// 文件说明:
// ***************************************************************
class PMProjectDBSERVICE CProject_ManageVectorGraph  
{
private:

public:
	
	CProject_ManageVectorGraph();
	virtual ~CProject_ManageVectorGraph();

	/**
	* @brief 删除配筋图 对应的信息  
	*
	*          zfy note 2020.06.08, v9.9 开始本函数仅删除 钢筋截面图
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [23/4/2012]
	*/
	static BOOL DelVector_AllInfo(int iVectorID);
	
	static int GetVectorID( const int nGraphicsVector );

	/**
	* @brief  通过钢筋的VectorID 获取 自定义钢筋 Buffer BufferSize信息
	*
	*          
	* @note  : 传出的 pBuffer 需要删除
	* @param : int iGJVectorID,LPVOID & pBuffer,int & lBufferSize
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [24/4/2012]
	*/
	static BOOL GetOwnGangjinInfo(int iGJVectorID,LPVOID & pBuffer,long & lBufferSize);

	/**
	* @brief  将自定义钢筋信息 保存到 数据库中 
	*
	*          
	* @note  : 他目前只用在 选图工具中 保存信息
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [24/4/2012]
	*/
	static BOOL SetOwnGangJinInfo(int iGJVectorID,LPVOID pBuffer,int lBufferSize);

	/// 设置 Bz 
	//static BOOL GetSLVectorBzInfo(int iSLVectorID, CString & strBz);
	//static BOOL SetSLVectorBzInfo(int iVectorID,const CString & strBz);

	/// 获取/设置 Bz
	static BOOL GetGJVectorBzInfo(int iSLVectorID, CString & strBz);

	/// 获取 ComType
	static BOOL GetVectorComType(int iVectorID, int &iComType) ;
	static BOOL GetVectorGraphicsComType( int iVectorID , int & iComType ) ;

	/// 取 VectorName 
	//static BOOL GetSLVectorName(int iVectorID, CString &strVectorName) ;
	static BOOL GetGJVectorName( int iVectorID , CString & strVectorName ) ;

	/// 设置 VectorName
	//static BOOL SetSLVectorName(int iVectorID, CString strVectorName) ;
	static BOOL SetGJVectorName(int iVectorID, CString strVectorName) ;

	/// 设置 备注
	static BOOL SetGJVectorBz(int iSLVectorID, CString strBz);
	static BOOL GetGJVectorBz(int iSLVectorID, CString &strBz);
	/// 设置 VectorInfo 中的数据，新钢筋矢量图 表中也是这种方式获取
	static BOOL SetSLVectorInfo(int iSLVectorID, CPMVectorEntityInfo * pVectorEntityInfo) ;
//	BOOL SetVectorGraphicsInfo(int iVectorID, CString strVectorInfo) ;

	/**
	* @brief    获取 VectorInfo 列 中数据，新钢筋矢量图 表中也是这种方式获取
	*
	*			该数据为附加数据，描述了矢量图图 的长，宽 ，截面polyline , 体积 是如何组合的
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [6/9/2020]
	*/
	static BOOL GetSLVectorInfo(int iSLVectorID, CPMVectorEntityInfo *& pVectorEntityInfo) ;
	static BOOL GetSLVectorInfo(int iSLVectorID, LPVOID& pbuff, long & buffSize) ;
//	BOOL GetGJVectorInfo(int iGJVectorID, CString &strVectorInfo) ;

	/**
	* @brief  获取 算量图形的 绘制，pbuff 需要删除  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	//static BOOL GetSLVectorData(int iSLVectorID, LPVOID& pbuff, long & buffSize) ;

	/**
	* @brief 获取 vectorgraph 列信息 ，用于 钢筋图 绘制   pbuff 需要删除
	*
	*          该vector 描述了 配筋图本身图元，不等同于
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [12/7/2012]
	*/
	static BOOL GetGJVectorData(int iGJVectorID, LPVOID& pbuff, long & buffSize) ;

	/// 设置 VectorGraph 
	//static BOOL SetSLVectorData(int iSLVectorID, LPVOID pbuff, long buffSize) ;
	static BOOL SetGJVectorData(int iGJVectorID, LPVOID pbuff, long buffSize) ;

	/// 插入 Vector 
	static BOOL InsertVector2Project(int iComType, const CString & strVectorName,CMemFile * pMemFile,\
		LPVOID pVectorInfoBuffer,long lVectorInfoBufferSize,const CString & strBz,int & iGJVectorID);


	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// 根据 软件运行模式 : nSoftMode , 和 图形ID :  strVectorID
	/// strVectorID 的后面两位 大于 50  这个图号就是 钢筋图形法中的
	/// 当 nSoftMode == 1 的时候 直接可以 返回 strVectorID 
	/// 当 nSoftMode == 0 的时候 就需要去 GraphMap 中查找与 strVectorID 对应的
	/// 算量的 strVectorID 
	/// 反之 亦然
	//static int GetVectorID( int nSoftMode , int nVectorID ) ;
	//static CString GetVectorID( int nSoftMode ,CString strVectorID ) ;

	/**
	* @brief   通过钢筋的 VectorID 获取 算量的 VectorID
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [24/11/2011]
	*/
	//static int GJVectorID2SLVectorID(int nVectorID);

	/******************************************************************** 
	 功能描述：根据算量的 VectorID  去获取图形法的 VectorID 
		zfy note 2020.06.02 . 因为大部分调用方都是固定图号的访问，暂不修改，以防止图号类型问题类型
	 参数： 
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：杨兴耀
	 时    间：[2009年9月8日]
	*********************************************************************/ 
	//static BOOL GetGraphicsVector( const int nVectorIndex , int & nGraphicsVectorIndex );

	/******************************************************************** 
	 功能描述：判断 配筋图 nVectorID1 和 nVectorID2 是否 对应同一个截面图
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：杨兴耀
	 时    间：[2009年9月10日]
	*********************************************************************/ 
	static BOOL HaveSameJm( const int nGraphicsVectorID1 , const int nGraphicsVectorID2);

	/// 获取承台的配筋图号
	static int GetCtVectorID( const int &nVectorID );
//	CMap<int , const int & , int  , const int & > m_map_ctvectormap ;

	static NDataModelDataSet * GetBzctPamrs( int nComID );
	
	/**
	* @brief   获取某 vectorid 匹配的 vectorid 串，用于矢量图选择对话框中的层次关系
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [6/4/2020]
	*/
	static BOOL FindGJVectorList( const int &nVectorID  , CString & strVectorIDs );


	// ***************************************************************
	//  杨兴耀注释  时间:2010年04月23日
	//  -------------------------------------------------------------
	//  功能: 对已有构件的 图形id 进行检查 
	//  -------------------------------------------------------------
	//  返回值:
	//  -------------------------------------------------------------
	//  参数:
	// ***************************************************************
	//  注意事项:
	// ***************************************************************
	static void UpdateVector() ; 

	// 收藏夹的操作 [2010-4-27 by 杨兴耀]
	// 返回值	0 : 没有改变
	//			1 : 算量的图形 id 改变
	//			2 : 钢筋的图形 id 改变
	//			3 : 算量 和 钢筋的 id 都改变 
	static int OperatePublicComponent(int & nGraphicVectorID ) ; 

	/// 删除收藏构件的 图形
	static void DelPublicComponent( int nComID ) ; 
	//  在收藏夹中应用到工程的时候
	//  将自定义图形 插入到 工程文件
	static int Insert2Project( CString &strGraphicVectorID ) ; 

	/// 构件收藏 中用来获取图形数据 --- 算量图
	//static BOOL GetPublicVectorData(int ID, LPVOID& pbuff, long & buffSize) ; 

	/// 构件收藏 中用来获取图形数据 --- 钢筋图
	static BOOL GetPublicVectorData_Gj(int ID, LPVOID& pbuff, long & buffSize) ;

	/// 构件收藏，钢筋矢量图到算量矢量图的id转换
	//static int PublicGJVectorID2SLVectorID(int nVectorID);

	/// 构件收藏，获取算量图的vectorinfo
	static BOOL GetPublicSLVectorInfo(int iSLVectorID, CPMVectorEntityInfo *& pVectorEntityInfo);
	
	/// 检查 图形ID 是否存在
	//static BOOL FindGraphVector( const int & nVectorID ) ;
	static BOOL FindGraphicsGraphVector( const int & nVectorID ) ; 

	/// 根据ComType 获取 最开始的 ComType 
	//static BOOL GetVectorID( const int & nComType , int & nVectorID , int & nVectorID_Gj ) ; 


	/// 现在只在 升级 截面图的地方用到
	/// 在 GraphMap 中查找 算量的 VectorID 
	//static BOOL Find( const int & nVectorID ) ; 

	/// 判断
	//static int Find( const int & nVectorID ,  int & nVectorID_Gj ) ;

protected:
		
	/// 删除指定图形
	//static BOOL DeleteSLVectorID(int iVectorID) ;
	static BOOL DeleteGJVectorID(int iVectorID) ;

	//获取vectorinfo 信息
	static BOOL GetVectorDrawInfo_Table(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);
};




#endif // !defined(AFX_Project_MANAGEVECTORGRAPH_H__EE1FFC83_E229_404F_B62A_94E2ECECED3A__INCLUDED_)
