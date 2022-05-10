// ParmAccess.h: interface for the CParmAccess class.
//
//////////////////////////////////////////////////////////////////////

/**
 * @brief 该文件从 SteelDataService 移过来的
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-18]
 * @note  
 */

#if !defined(AFX_PARMACCESS_H__A0149476_B72F_44A6_9AB5_7A2EB9FD0F21__INCLUDED_)
#define AFX_PARMACCESS_H__A0149476_B72F_44A6_9AB5_7A2EB9FD0F21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PMProjectDBSERVICE CParmAccess  
{
private:
	CParmAccess();
	virtual ~CParmAccess();

public:
//项目层面的设置存取
	//取得指定构件类别的计算设置,本函数将从全局对象中进行取得设置值
	//需要删除
    static NDataModelDataSet * GetComCalSetupDataSetByType(int comType); 
	static NDataModelDataSet * GetComCalSetupDataSetByType(int comType,int parmType);
	static NDataModelDataSet * GetComCalSetupDataSetByType(int comType,int parmType,int hide);

	/**
	* @brief  获取 参数表所有信息的 CParms 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/9/2012]
	*/
	static CParms * GetComponentParms(const int iComId );

	/// 
	static CParm::ParmType MapDatatypeToParmtype(int datatype);


//构件层面的设置存储
	//************************************
	// Method:  GetComSetupDataSet  
	// Access: public   
	// Returns:  返回指定ID的所有设置DataSet
	// Qualifier: 
	// Parameter: comID 控件的id编码
	// Remark: 本方法取得构件的所有相关设置项，本函数将对全局设置和
	//         构件设置的设置项进行合并,所以原则上本函数只是支持计算
	//         中的参数取得
	//			(wjy)返回NDataModelDataSet需要删除
	//************************************
    static NDataModelDataSet * GetComSetupDataSet(int comID);

	//************************************
	// Method:  GetComSetupDataSet  
	// Access:  public  
	// Qualifier: 
	// Parameter: comID构件id parmType 设置类别
	// Returns: 返回指定类别指定参数类别的设置表
	// Remark: 本函数用于取得指定构件，指定参数类别的设置列表
	// 如果本构件中对相应的参数类别中没有进行设置，函数将从全局设置中取得
	// 由于函数按照类别进行设置，所以本函数原则上用于界面中的参数设置。
	// 本函数返回的DataSet在经过值的修改后可作为存储设置的参数调用
	//			(wjy)返回NDataModelDataSet需要删除
	//************************************
    static NDataModelDataSet* GetComSetupDataSet(int comID,int parmType);

	static NDataModelDataSet* GetComSetupDataSet(int comID,int parmType,int hide);
	
	//NDataModelDataSet* GetComSetupDataSet(int comID);
	//保存指定ID的构件设置，本构件的设置在保存时将替换原有的本类别的设置项，
	//同时将保存在指定构件的存储空间内
	static void	SetComSetupDataSet(int comID, NDataModelDataSet * pDataSet);

	/// 设置构件法的参数，已经存在的参数不做处理，
	/// 没有的新增
	static void SetComSetupDataSet_V2( const int comID , NDataModelDataSet * pDataSet ) ; 

	/******************************************************************** 
	 功能描述：二分法查找对应的parmid在DataSet中所在的行数
	 参    数：
	 返 回 值：parmid对应的row,返回-1表示没有找到对应的parmid
	 算    法：
	 注意事项：调用之前，pDataSet要对ParmId排序（从大到小），
	 作    者：zll
	 时    间：8/7/2008   16:06
	*********************************************************************/ 
	static int	FindParmIdFromDS(NDataModelDataSet *pDataSet, const int &parmid);
	
	/******************************************************************** 
	 功能描述：二分法查找对应的parmid在DataSet中所在的行数
	 参    数：row 为输出参数，代表找到的parmid的行或，这个parmid待插入的行
	 返 回 值：找到了Parmid，返回真，反之返回假
	 算    法：折半查找法
	 注意事项：若返回TRUE，row为要的行，反之，row为待插入的行
	 作    者：zll
	 时    间：14/7/2008   13:29
	*********************************************************************/ 
	static BOOL FindParmIdFromDS(NDataModelDataSet *pDataSet, const int &parmid, int &row);

	/**
	* @brief 获取03G中 参数总表中 指定参数名的 ParmID  
	*
	*          
	* @note  : 目前发现 钢筋构件法 导入图形法 有使用
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/11/2011]
	*/
	static int GetComParms_Total03G_ParmID(const CString & strParmName);

private: 
	/******************************************************************** 
	 功能描述：GetComSetupDataSet
	 参    数：
	 返 回 值：返回指定类别指定参数类别的设置表
	 算    法：
	 注意事项：被其他GetComSetupDataSet函数调用！
	 作    者：zll
	 时    间：10/7/2008   17:15
	*********************************************************************/ 
	static NDataModelDataSet * GetComSetupDataSet(int comID, int comType, NDataModelDataSet * pDataSetFromGlobe);

};

#endif // !defined(AFX_PARMACCESS_H__A0149476_B72F_44A6_9AB5_7A2EB9FD0F21__INCLUDED_)
