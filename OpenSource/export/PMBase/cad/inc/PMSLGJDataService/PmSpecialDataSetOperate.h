// PmSpecialDataSetOperate.h: interface for the CPmSpecialDataSetOperate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMSPECIALDATASETOPR_H__14DF9551_37BC_4E5A_98D0_36B59FB02DF7__INCLUDED_)
#define AFX_PMSPECIALDATASETOPR_H__14DF9551_37BC_4E5A_98D0_36B59FB02DF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PmSLGJDataServiceAPI CPmSpecialDataSetOpr
{
public:
	CPmSpecialDataSetOpr();
	virtual ~CPmSpecialDataSetOpr();

	/**
	* @brief  获取参数 设置值 
	*
	*          
	* @note  : 通过参数 类型进行快速过滤
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	static BOOL GetComParmSet_ParmValue(NDataModelDataSet * pComParmDataSet,int iParmType,const CString & strParmName,CString & strParmVaue);

	/**
	* @brief  将DataSet的Field复制到 另一个DataSet
	*
	*          
	* @note  : 注意 不会复制 表格内容
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/12/2011]
	*/
	static BOOL CopyDataSetField(CPM_StorageDataSet * pFromDataSet,CPM_StorageDataSet * pToDataSet);

	/******************************************************************** 
	功能描述：用于复制构件属性，由于加入了 内存共享DataSet，直接的RowsCopy会加大内存 损耗
	参数：
	返 回 值：
	算法：
	注意事项：
	作    者：王建业
	时    间：[2010:12:14]   8:50
	*********************************************************************/ 
	static BOOL CopyComParmsDataSet(NDataModelDataSet * pFormComParmDataSet,NDataModelDataSet * pToComParmDataSet);

	/// 多项查询
	static BOOL GetDataSetRowArray( 
		NDataModelDataSet * pDataSet ,
		const CStringArray & fieldnames ,
		const CStringArray & fieldvalues ,
		CUIntArray & rows ) ;

	/// 单项查找
	/// 返回的行号 是从小到大的
	static BOOL GetDataSetRowArray( 
		NDataModelDataSet * pDataSet ,
		const CString sFieldValue ,
		const CString sFieldName ,
		CUIntArray &rows 
		) ; 
	
	// ***************************************************************
	//  杨兴耀注释  时间:2010年03月12日
	//  -------------------------------------------------------------
	//  功能: 将数据源 pSrcDataSet 拷贝一份 (所有的行拷贝)
	//  -------------------------------------------------------------
	//  返回值:拷贝后的目标数据源
	//  -------------------------------------------------------------
	//  参数:pSrcDataSet 需要被拷贝的数据源 
	// ***************************************************************
	//  注意事项: 返回的数据源 是new 出来的一个数据源，所以调用的地方
	//			  用完后需释放
	// ***************************************************************
	static NDataModelDataSet * RowsCopy(  NDataModelDataSet * pSrcDataSet ) ; 

	/// 返回的DataSet 为 重 NDbDataSet new 出来的 且有表名 和 主键
	/// 该接口获取的DataSet 在调用 update 的时候可以更新到 mdb 文件中 
	static NDataModelDataSet * GetNDbDataSet(  NDataModelDataSet * pSrcDataSet ) ; 
	// ***************************************************************
	//  杨兴耀注释  时间:2010年03月29日
	//  -------------------------------------------------------------
	//  功能:
	//  -------------------------------------------------------------
	//  返回值:
	//  -------------------------------------------------------------
	//  参数:
	// ***************************************************************
	//  注意事项:
	// ***************************************************************
	static void ExportDataSetToTxt( const CString & strFileName , NDataModelDataSet * pDataSet ) ; 

	// ***************************************************************
	//  杨兴耀注释  时间:2010年04月01日
	//  -------------------------------------------------------------
	//  功能:
	//  -------------------------------------------------------------
	//  返回值:
	//  -------------------------------------------------------------
	//  参数:
	// ***************************************************************
	//  注意事项:
	// ***************************************************************
	static void SetModify( NDataModelDataSet * pDataSet , const BOOL & bModify ) ;

	/// 获取 DataSet 的 列名
	static void GetFieldArray( NDataModelDataSet * pDataSet , CStringArray & arr_fields ) ;
	/// 根据 列名，类型 ，大小
	/// 获取一个新的DataSet 
	static NDataModelDataSet * GetDataSet( 
		const CStringArray & arr_fields , 
		const CArray<FieldType , FieldType>& arr_fieldtypes ,
		const CUIntArray & arr_fieldsizes ) ;
	/// 为ftBlob 字段写一个定制一个接口
	static NDataModelDataSet * GetDataSet( 
		const CStringArray & arr_fields 
		) ;


};

#endif // !defined(AFX_PMSPECIALDATASETOPR_H__14DF9551_37BC_4E5A_98D0_36B59FB02DF7__INCLUDED_)
