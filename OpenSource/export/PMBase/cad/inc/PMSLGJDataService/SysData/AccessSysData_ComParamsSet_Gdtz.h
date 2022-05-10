
#pragma  once 



#include "AccessSysDataTable.h"

/**
 * @brief 高度调整 参数表
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CSysComParamsSet_GdtzTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysComParamsSet_GdtzTable)

	CSysComParamsSet_GdtzTable() ; 
	~CSysComParamsSet_GdtzTable() ;

	
public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString ParmID ;
		static		 int	 ParmID_Index;

		static const CString gangjin_mode ;
		static		 int	 gangjin_mode_Index;

		static const CString UpdateMode ;
		static		 int	 UpdateMode_Index;

		static const CString comtype ;
		static		 int	 comtype_Index;

		static const CString SubComType ;
		static		 int	 SubComType_Index;

		static const CString parmtype ;
		static		 int	 parmtype_Index;

		static const CString parmname ;
		static		 int	 parmname_Index;

		static const CString parmdisplayname ;
		static		 int	 parmdisplayname_Index;

		static const CString parmvalue ;
		static		 int	 parmvalue_Index;

		static const CString InputMode ;
		static		 int	 InputMode_Index;

		static const CString DataType ;
		static		 int	 DataType_Index;

		static const CString processType ;
		static		 int	 processType_Index;

		static const CString exp ;
		static		 int	 exp_Index;

		static const CString InvalidMsg ;
		static		 int	 InvalidMsg_Index;

		static const CString Hide ;
		static		 int	 Hide_Index;

		static const CString SortID ;
		static		 int	 SortID_Index;

		static const CString TreeNode ;
		static		int		TreeNode_Index;

		static const CString ListData ; 

		static const CString Mode ;
		static		int		Mode_Index ; 
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};
};

class PmSLGJDataServiceAPI CAccessSysData_ComParamsSet_GdtzTable :
	public CAccessSysDataTable
{
public:
	CAccessSysData_ComParamsSet_GdtzTable(void);
	virtual ~CAccessSysData_ComParamsSet_GdtzTable(void);

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

	/// 
	NDataModelDataSet * GetDataSet( const int iComType) ;

	NDataModelDataSet * GetShowDataSet( const int iComType) ;

	/// 获取标高 
	/// nMode : 0 : nComID 对应　没有标高
	///			1 : nComID 对应　只有　底标高
	///			2 : nComID 对应　只有　顶标高
	///			3 : nComID 对应　底标高　和　顶标高　都有
	/// dibgParam 底标高 参数
	/// dbgParam  顶标高 参数
	/// 
	/// 基础类构件 和 基础梁构件 的标高是 绝对标高 。
	/// 其他构件的 标高都是相对标高
protected:
	BOOL GetBg( const int  nComID , int & nMode , CParm & dibgParam, CParm & dbgParam );

	/**
	* @brief   
	*
	*          
	* @note  : nMode : 0 : nComID 对应　没有标高
	///			1 : nComID 对应　只有　底标高
	///			2 : nComID 对应　只有　顶标高
	///			3 : nComID 对应　底标高　和　顶标高　都有
	/// dibgParam 底标高 参数
	/// dbgParam  顶标高 参数
	///  获取标高为 相对标高
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [24/8/2012]
	*/

protected:
	BOOL GetBg_XDValue( const int  nComID , int & nMode , double & dibg, double & dbg );

	/**
	* @brief 获取标高模式  
	*
	*          
	* @note  : nMode : 0 : nComID 对应　没有标高
	///			1 : nComID 对应　只有　底标高
	///			2 : nComID 对应　只有　顶标高
	///			3 : nComID 对应　底标高　和　顶标高　都有
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/8/2012]
	*/
	BOOL GetBgMode_ComID( const int  nComID , int & nMode);
protected:
	/**
	* @brief 获取标高模式  
	*
	*          
	* @note  : nMode : 0 : nComID 对应　没有标高
	///			1 : nComID 对应　只有　底标高
	///			2 : nComID 对应　只有　顶标高
	///			3 : nComID 对应　底标高　和　顶标高　都有
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/8/2012]
	*/
	BOOL GetBgMode_ComType( const int nComType, int & nMode);
public:
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

	BOOL HasParm( const int iComType , const CString & strParmName ) ;


	/// 
	/// 显示的DataSet需要 disparmname 和 iuputmode 等
	/// 
	NDataModelDataSet * GetShowDataset() ; 
private:
	/// 
	/// 将 pSrcDataSet 转化为 pDesDataSet 
	///
	/// pSrcDataSet 是本table的结构
	/// pDesDataSet 是显示Dataset的结构
	/// 
	void	ConvertDataSet( NDataModelDataSet * pSrcDataSet , NDataModelDataSet * pDesDataSet ) ; 

	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;


public:
	//固定的SQL 集合
	struct PmSLGJDataServiceAPI SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// GetDataSet( const int iComType) 
		static const int m_iGetDataSet1 ;
		static PMTSTRING m_strGetDataSet1 ; 

		/// 和 m_iGetDataSet1 的区别只是排序不同
		static const int m_iGetDataSet2 ;
		static PMTSTRING m_strGetDataSet2 ; 
	} ;

};
