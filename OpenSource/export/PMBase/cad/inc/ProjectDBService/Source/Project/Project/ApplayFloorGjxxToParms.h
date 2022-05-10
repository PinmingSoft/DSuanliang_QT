// ApplayFloorGjxxToParms.h: interface for the CApplayFloorGjxxToParms class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMAPPLAYFLOORGJXXTOPARMS_H__26552EB7_5A31_482E_91CE_8169699A74A7__INCLUDED_)
#define AFX_PMAPPLAYFLOORGJXXTOPARMS_H__26552EB7_5A31_482E_91CE_8169699A74A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// ***************************************************************
//  ApplayFloorGjxxToParms   version:  1.0   ? date: 06/10/2009
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2009 - All Rights Reserved
// ***************************************************************
// 文件说明:更新算法
//			对于构件信息，需要根据 楼层号(FloorID  ) , 构件种类(ComType) 
//			去 FloorGjxx 中更新到 ComParmsSet_Tatal 中  ,再去 ComParmsSet_Tatal 获取
//			
//升级默认构件 : 所有的东西都需要更新：全局设置/计算设置
//
//构建信息应用到工程 : 只需要更新 构建信息
//
//箍筋属性 应用到 工程 : 只有3个参数需要更新 ( GJWG , GJJSGZ , GJZS )
//
//计算设置 应用到工程 :  计算设置的应用 不涉及到 ComParmsSet_Tatal 表
//
//计算规则 应用到工程 : ComParmsSet_Tatal 的几个参数的应用
//
//
// ***************************************************************
class PMProjectDBSERVICE CPMApplayFloorGjxxToParms  
{
public:
	
	static void RemoveDirtyData() ;

	CPMApplayFloorGjxxToParms();
	virtual ~CPMApplayFloorGjxxToParms();

private:
//	NDataModelDataSet * m_pDataSet ;
/// 升级默认构件
	static void InitData(NDataModelDataSet *& pComParmDataSet,int nFloor ,int nComType );
	static void InitData2(NDataModelDataSet *& pComParmDataSet,int nFloor , int nComType ) ;

	/// 只升级结构特征里面的东西
	static void InitDataGjxx(NDataModelDataSet *& pComParmDataSet,int nFloor ,int nComType );


//	CString GetValue(int nFloor,  CString strParmName , NDataModelDataSet * pGjxxDataSet ) ;
//	void SetMgDj(NDataModelDataSet * pComParmDataSet, int nFloor , int nComType) ;
//	void SetMgDj2( NDataModelDataSet * pComParmDataSet, int nFloor , int nComType) ;

	static void InitDataJsgz(NDataModelDataSet *& pJSSZDataSet);

	static CString GetParmValue(NDataModelDataSet * pComParmDataSet,CString strParmName , int nSubComType );


/// 息钢筋信息 应用到工程 - 图形法
//	void InitDataTotal( int nFloor , int nComType )  ;
/// 构件法
//	void InitDataTotal2(  int nFloor , int nComType )  ; 

/// 计算设置 应用到工程
	static void InitDataJssz( int nComType ,NDataModelDataSet *& pJSSZDataSet) ;

	static void SetComParms( NDataModelDataSet * pDefComParmDataSet , NDataModelDataSet * pComParmDataSet ) ;

public:
	/// 搭接形式 应用到 工程
	static void ApplyDjxsToProject() ;
	/// 箍筋属性 应用到 工程
	static void ApplyGjsxToProject() ;
	/// 计算设置 应用到工程
	static void ApplyJsszToProject() ;
	/// 计算规则 应用到工程
	static void ApplyJsgzToProject() ;
	/// 钢筋信息 应用到工程
	static void ApplyGjxxToProject();
	/// 更新模板中的默认构件
	static void UpdateDefalutComponents( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype);
	static void UpdateDefalutComponents2() ;



///注释：杨兴耀 [2009年12月23日]                                  
///应用到工程 添加了 楼层和 构件
///的选择

//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// 钢筋信息
	/// 应用到 图形法
	static void ApplyGjxxToProject( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

	/// 应用到构件法
	static void ApplyGjxxToProject2( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype
		) ;

	/// 应用
	static void ApplyGjxxToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype ,
		const CUIntArray & arr_graphcomtype 
		) ;

//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// 搭接形式
	/// 应用到 图形法
	static void ApplyDjxsToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

	/// 应用到构件法
	static void ApplyDjxsToProject2( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype
		) ;

	/// 应用
	static void ApplyDjxsToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype ,
		const CUIntArray & arr_graphcomtype 
		) ;
//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	///箍筋属性
	/// 应用到 图形法
	static void ApplyGjsxToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

	/// 应用到构件法
	static void ApplyGjsxToProject2( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype
		) ;

	/// 应用
	static void ApplyGjsxToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype ,
		const CUIntArray & arr_graphcomtype 
		) ;

//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	///计算规则
	/// 应用到 图形法
	static void ApplyJsgzToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

	/// 应用到构件法
	static void ApplyJsgzToProject2( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype
		) ;

	/// 应用
	static void ApplyJsgzToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_componentcomtype ,
		const CUIntArray & arr_graphcomtype 
		) ;

//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	///计算设置
	/// 应用到 图形法
	static void ApplyJsszToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

};

#endif // !defined(AFX_APPLAYFLOORGJXXTOPARMS_H__26552EB7_5A31_482E_91CE_8169699A74A7__INCLUDED_)
