
#pragma once 


#include "AccessSysDataTable.h"

/**
 * @brief 
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-4]
 * @note  
 */
class PmSLGJDataServiceAPI CSysHjdface_InfoTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysHjdface_InfoTable)

	CSysHjdface_InfoTable();
	~CSysHjdface_InfoTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString BH ;			/// 编号
		static const CString GJMC ;			/// 钢筋名称
		static const CString GJName ;		/// 钢筋
		static const CString GJValue ;		/// 钢筋参数值
		static const CString SLValue ;		/// 数量值
		static const CString SLConst ;		/// 数量需要支持的常量
		static const CString LenValue ;		/// 长度值
		static const CString LenConst ;		/// 长度需要支持的常量
		static const CString CheckValue ;	/// 正则表达式,限制钢筋的输入
		static const CString SLHitInfo ;	/// 数量的提示信息
		static const CString LenHitInfo ;	/// 长度的提示信息

		static int BH_Idx ;			/// 编号
		static int GJMC_Idx ;			/// 钢筋名称
		static int GJName_Idx ;		/// 钢筋
		static int GJValue_Idx ;		/// 钢筋参数值
		static int SLValue_Idx ;		/// 数量值
		static int SLConst_Idx ;		/// 数量需要支持的常量
		static int LenValue_Idx ;		/// 长度值
		static int LenConst_Idx ;		/// 长度需要支持的常量
		static int CheckValue_Idx ;	/// 正则表达式,限制钢筋的输入
		static int SLHitInfo_Idx ;	/// 数量的提示信息
		static int LenHitInfo_Idx ;	/// 长度的提示信息


		/// idx 递增的辅助变量
		/// idx 需要在函数 InitFieldStr 外 ，初始化为有意义的值
		/// 且赋值的顺序应该和 InitFieldStr中添加的顺序一样
		static int idx_step ; 
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/// at 2010年12月31日  14:04  by yxy
/// 在 SysData 里 保存了一张表 存储 27 根钢筋的初始化

struct PmSLGJDataServiceAPI CHjdFaceInfo 
{
	CString BH ;
	CString GJMC ; 
	CString GJName ; 
	CString GJValue ; 
	CString CheckValue ; 
	CString SLValue ; 
	CString SLConst ; 
	CString LenValue ; 
	CString LenConst ; 
	CString SLHitInfo ; 
	CString LenHitInfo ;
};


class PmSLGJDataServiceAPI CAccessSysData_Hjdface_InfoTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_Hjdface_InfoTable(void);
	virtual ~CAccessSysData_Hjdface_InfoTable(void);

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
	NDataModelDataSet * GetEmptyDataSet() ; 

	BOOL GetHjdFaceInfo( const CString & strGjName , CHjdFaceInfo & hjdfaceinfo ) ; 

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

		/// 
		static const int m_iGetHjdFaceInfo  ;
		static PMTSTRING m_strGetHjdFaceInfo ; 
	} ;
};

///
/// 后浇带 钢筋设置的界面的 主 DataSet 的结构 为:
///	pDataSet->AddField( FAName , ftBlob , 0 ) ;  方案名称
///	pDataSet->AddField( FAContent , ftBlob , 0 ) ; 方案内容
///	pDataSet->AddField( MainFace , ftBlob , 0 ) ; 主界面的DataSet
///	pDataSet->AddField( VectorID, ftBlob , 0 ) ; 图形ID 
///	pDataSet->AddField( VectorParm , ftBlob , 0 ) ; 图形的DataSet 
///
/// 其中 MainFace 又是一个 DataSet 其结构为:
/// pDataSet->AddField( BH , ftBlob , 0 ) ;     /// 编号
///	pDataSet->AddField( GJMC , ftBlob , 0 ) ; /// 钢筋名称
///	pDataSet->AddField( GJName , ftBlob , 0 ) ; /// 钢筋
///	pDataSet->AddField( GJValue , ftBlob , 0 ) ; /// 钢筋参数值
///	pDataSet->AddField( SLValue , ftBlob , 0 ) ; /// 数量值
///	pDataSet->AddField( LenValue , ftBlob , 0 ) ;/// 长度值
/// pDataSet->AddField( CheckValue, ftBlob , 0 ) ; /// 正则表达式,限制钢筋的输入
/// 
/// VectorParm 也是一个 DataSet 其结构 见 CVectorParmsTable 
/// 

class PmSLGJDataServiceAPI CHjdDataSetOpr  
{
public:
	CHjdDataSetOpr() ;
	~CHjdDataSetOpr() ; 

public:
	struct PmSLGJDataServiceAPI constdata 
	{
		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		static const CString FAName ;		/// 方案名称
		static const CString FAContent ;	/// 方案内容
		static const CString MainFace ;		/// 主界面的DataSet
		static const CString VectorID ;		/// 图形ID 
		static const CString VectorParm ; 	/// 图形的DataSet 
		//////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////
		/// at 2010年9月15日  16:24  by yxy
		/// 将钢筋名称定义为常量

		/// 梁
		static const CString HJD1;					/// 梁内加强箍筋						/// 1
		static const CString HJD2 ;					/// 梁内横向上部加强筋					/// 2
		static const CString HJD3 ;					/// 梁内横向下部加强筋					/// 3

		/// 板
		static const CString HJD4 ;					/// 板内上部横向加强筋					/// 4
		static const CString HJD5 ;					/// 板内下部横向加强筋					/// 5
		static const CString HJD6 ;					/// 板内纵向上部分布筋					/// 6
		static const CString HJD7 ;					/// 板内纵向下部分布筋					/// 7

		/// 墙
		static const CString HJD8 ;					/// 墙内竖向内侧加强筋					/// 8
		static const CString HJD9 ;					/// 墙内竖向外侧加强筋					/// 9
		static const CString HJD10 ;				/// 墙横向内侧加强筋					/// 10 
		static const CString HJD11 ;				/// 墙横向外侧加强筋					/// 11 


		/// 基础梁
		static const CString HJD12 ;				/// 基础梁加强箍筋						/// 12
		static const CString HJD13 ;				/// 基础梁横向上部加强筋				/// 13
		static const CString HJD14 ;				/// 基础梁横向下部加强筋				/// 14


		/// 筏板
		static const CString HJD15 ;				/// 筏板内上部横向加强筋				/// 15
		static const CString HJD16 ;				/// 筏板内下部横向加强筋				/// 16
		static const CString HJD17 ;				/// 筏板内上部纵向分布筋				/// 17
		static const CString HJD18 ;				/// 筏板内下部纵向分布筋				/// 18
		static const CString HJD19 ;				/// 筏板加强带上部横向加强筋			/// 19 
		static const CString HJD20 ;				/// 筏板加强带下部横向加强筋			/// 20 
		static const CString HJD21 ;				/// 筏板加强带纵向上部分布筋			/// 21  
		static const CString HJD22 ;				/// 筏板加强带纵向下部分布筋			/// 22
		static const CString HJD23 ;				/// 筏板加强带下部横向加强筋1			/// 23 
		static const CString HJD24 ;				/// 筏板加强带内截高方向拉筋1			/// 24
		static const CString HJD25 ;				/// 筏板加强带内截高方向拉筋2			/// 25 
		static const CString HJD26 ;				/// 筏板加强带内纵向上部分布筋			/// 26
		static const CString HJD27 ;				/// 筏板加强带内纵向下部分布筋			/// 27
		static const CString HJD28 ;				/// 筏板加强带内截高方向拉筋3			/// 28
		
		static const CString HJD29 ;				/// 筏板加强带横向加强筋		
		static const CString HJD30 ;				/// 筏板加强带纵向加强筋			
		static const CString HJD31 ;				/// 筏板加强带内截高方向拉筋			
		static const CString HJD32 ;				/// 筏板加强带上部横向加强筋			
		static const CString HJD33 ;				/// 筏板加强带下部横向加强筋			
		static const CString HJD34 ;				/// 筏板加强带纵向上部分布筋			
		static const CString HJD35 ;				/// 筏板加强带纵向下部分布筋				
		static const CString HJD36 ;				/// 筏板加强带上部横向加强筋			
		static const CString HJD37 ;				/// 筏板加强带下部横向加强筋				
		static const CString HJD38 ;				/// 筏板加强带纵向上部分布筋			
		static const CString HJD39 ;				/// 筏板加强带纵向下部分布筋				
		static const CString HJD40 ;				/// 筏板加强带横向加强筋1				
		static const CString HJD41 ;				/// 筏板加强带横向加强筋2				
		static const CString HJD42 ;				/// 筏板加强带纵向加强筋	

		// 基础梁
		static const CString HJD43 ;				/// 基础梁加强带上部横向加强筋			
		static const CString HJD44 ;				/// 基础梁加强带下部横向加强筋			
		static const CString HJD45 ;				/// 基础梁加强带纵向上部分布筋				
		static const CString HJD46 ;				/// 基础梁加强带纵向下部分布筋			
		static const CString HJD47 ;				/// 基础梁加强带下部横向加强筋				
		static const CString HJD48 ;				/// 基础梁加强带内截高方向拉筋1				
		static const CString HJD49 ;				/// 基础梁加强带内截高方向拉筋2			
		static const CString HJD50 ;				/// 基础梁加强带内截高方向拉筋3			
		static const CString HJD51 ;				/// 基础梁加强带内纵向上部分布筋			
		static const CString HJD52 ;				/// 基础梁加强带内纵向下部分布筋
		static const CString HJD53 ;				/// 基础梁加强带横向加强筋
		static const CString HJD54 ;				/// 基础梁加强带纵向分布筋
		static const CString HJD55 ;				/// 基础梁加强带内截高方向拉筋
		static const CString HJD56 ;				/// 基础梁加强带上部横向加强筋
		static const CString HJD57 ;				/// 基础梁加强带下部横向加强筋				
		static const CString HJD58 ;				/// 基础梁加强带纵向上部分布筋				
		static const CString HJD59 ;				/// 基础梁加强带纵向下部分布筋			
		static const CString HJD60 ;				/// 基础梁加强带纵向上部分布筋				
		static const CString HJD61 ;				/// 基础梁加强带纵向下部分布筋				
		static const CString HJD62 ;				/// 基础梁加强带纵向上部分布筋				
		static const CString HJD63 ;				/// 基础梁加强带纵向下部分布筋				
		static const CString HJD64 ;				/// 基础梁加强带横向加强筋1				
		static const CString HJD65 ;				/// 基础梁加强带横向加强筋2
		static const CString HJD66 ;				/// 基础梁加强带纵向分布筋

		// 砼外墙
		static const CString HJD67 ;				/// 墙加强带内横向内侧加强筋				
		static const CString HJD68 ;				/// 墙加强带内横向外侧加强筋				
		static const CString HJD69 ;				/// 墙加强带内竖向内侧分布筋			
		static const CString HJD70 ;				/// 墙加强带内竖向外侧分布筋				
		static const CString HJD71 ;				/// 墙加强带内横向外侧加强筋				
		static const CString HJD72 ;				/// 墙加强带内截高方向拉筋1				
		static const CString HJD73 ;				/// 墙加强带内截高方向拉筋2				
		static const CString HJD74 ;				/// 墙加强带内截高方向拉筋3
		static const CString HJD75 ;				/// 墙加强带内竖向内侧分布筋
		static const CString HJD76 ;				/// 墙加强带内竖向外侧分布筋
		static const CString HJD77 ;				/// 墙加强带内横向加强筋
		static const CString HJD78 ;				/// 墙加强带内竖向分布筋
		static const CString HJD79 ;				/// 墙加强带内截高方向拉筋3				
		static const CString HJD80 ;				/// 墙加强带内横向内侧加强筋				
		static const CString HJD81 ;				/// 墙加强带内横向外侧加强筋			
		static const CString HJD82 ;				/// 墙加强带内竖向内侧分布筋				
		static const CString HJD83 ;				/// 墙加强带内竖向外侧分布筋				
		static const CString HJD84 ;				/// 墙加强带内横向内侧加强筋				
		static const CString HJD85 ;				/// 墙加强带内横向外侧加强筋				
		static const CString HJD86 ;				/// 墙加强带内竖向内侧分布筋				
		static const CString HJD87 ;				/// 墙加强带内竖向外侧分布筋
		static const CString HJD88 ;				/// 墙加强带内横向加强筋1
		static const CString HJD89 ;				/// 墙加强带内横向加强筋2
		static const CString HJD90 ;				/// 墙加强带内竖向分布筋

		static const  CString HJDFBqtgj ;		/// 筏板加其他钢筋					/// 
		static const  CString HJDJLqtgj ;		/// 基础梁其他钢筋					/// 
		static const  CString HJDLqtgj ;		/// 梁其他钢筋					/// 
		static const  CString HJDQqtgj ;		/// 墙其他钢筋					/// 
		static const  CString HJDBqtgj ;		/// 板其他钢筋					/// 
		/// 定义初始化的界面图
		static const CString LiangVectorID  ; 
		static const CString JcLiangVectorID ; 
		static const CString BanVectorID ; 
		static const CString QiangVectorID ; 
		static const CString FaBanVectorID1 ; 
		static const CString FaBanVectorID2 ;
		static const CString FaBanVectorID3 ;
		static const CString FaBanVectorID4 ;
		static const CString FaBanVectorID5 ;
		static const CString FaBanVectorID6 ;
		static const CString FaBanVectorID7 ;
		static const CString QiangVectorID1 ; 
		static const CString QiangVectorID2 ;
		static const CString QiangVectorID3 ;
		static const CString QiangVectorID4 ;
		static const CString QiangVectorID5 ;
		static const CString QiangVectorID6 ;
		static const CString QiangVectorID7 ;
		static const CString JcLiangVectorID1 ; 
		static const CString JcLiangVectorID2 ;
		static const CString JcLiangVectorID3 ;
		static const CString JcLiangVectorID4 ;
		static const CString JcLiangVectorID5 ;
		static const CString JcLiangVectorID6 ;
		static const CString JcLiangVectorID7 ;

		static const CString FanName1 ;
		static const CString FanName2 ;
	};

	enum CType
	{
		eLiang  = 0,	/// 梁
		eBan ,		/// 板
		eQiang ,	/// 墙
		eQiang1 ,	/// 墙1
		eQiang2 ,	/// 墙2
		eQiang3 ,	/// 墙3
		eQiang4 ,	/// 墙4
		eQiang5 ,	/// 墙5
		eQiang6 ,	/// 墙6
		eQiang7 ,	/// 墙7
		eQiangNq ,	/// 墙
		eJcLiang ,	/// 基础梁
		eJcLiang1 ,	/// 基础梁1
		eJcLiang2 ,	/// 基础梁2
		eJcLiang3 ,	/// 基础梁3
		eJcLiang4 ,	/// 基础梁4
		eJcLiang5 ,	/// 基础梁5
		eJcLiang6 ,	/// 基础梁6
		eJcLiang7 ,	/// 基础梁7
		eFaban1,	/// 筏板1
		eFaBan2,	/// 筏板2
		eFaBan3,	/// 筏板3
		eFaBan4,	/// 筏板4
		eFaBan5,	/// 筏板5
		eFaBan6,	/// 筏板6
		eFaBan7		/// 筏板7
	};

public:
	/// 
	static NDataModelDataSet *				GetDataSet( CHjdDataSetOpr::CType type  ) ; 

	/// 总的DataSet 
	static NDataModelDataSet *				GetTotalDataSet() ; 
	/// 主界面上的DataSet
	static NDataModelDataSet *				GetMainFaceDataSet() ;

	////////////////////////////////////////////////////////////////
	/// at 2010年9月20日  16:40  by yxy
	/// pGridDataset 和 pVectorDataSet 调用者需要维护
	/// 在计算后浇带刚筋的时候
	/// 获取包含钢筋的pGridDataset 和 图形的pVectorDataSet
	/// 墙/板/筏板 都用这个接口 
	static BOOL							GetDataSet( 
		CString  strValue ,
		NDataModelDataSet * pGridDataset , 
		NDataModelDataSet * pVectorDataSet 
		) ;

	/// 梁和基础梁用这个接口 
	static BOOL							GetDataSet( 
		const int & nWidth , 
		const int &nHeight , 
		CString strValue ,
		NDataModelDataSet * pGridDataset , 
		NDataModelDataSet * pVectorDataSet 
		) ;

	/*****************************************************
	* 获取后浇带信息中"其他钢筋"项的具体值
	* 参数:
	*	strData:代表包含信息的字符串流,例如后浇带属性fbhjd中的InvalidMsg列
	*	type:代表具体的后浇带类型,目前仅支持eFaBan1
	* 返回值:
	*	为NULL时代表获取失败
	* 注意:
	*	返回的指针在使用完毕后需要删除,否则会导致内存泄漏
	* wrq [2017-4-19]
	*****************************************************/
	static NDataModelDataSet* GetQtgjInfo(CString strData, CHjdDataSetOpr::CType type);

	/*****************************************************
	* v9.4新增"其他钢筋"属性项,旧版本的属性中需要加入该项
	* 因为其结构操作较为麻烦,所以不直接升级,改为在此添加
	* 返回值:
	*	TRUE代表添加成功
	*	FALSE代表已存在或者该类型不存在其他钢筋属性项
	* wrq [2017-4-20]
	*****************************************************/
	static BOOL AddQtgjInfo(NDataModelDataSet *pDataSet, CHjdDataSetOpr::CType type);

private:
	/// 梁
	static NDataModelDataSet *				GetLiangDataSet() ;
	/// 基础梁
	static NDataModelDataSet *				GetJcLiangDatSet() ; 
	/// 板
	static NDataModelDataSet *				GetBanDataSet() ; 
	/// 墙
	static NDataModelDataSet *				GetQiangDataSet() ; 
	/// 筏板1
	static NDataModelDataSet *				GetFaBan1() ; 
	/// 筏板2
	static NDataModelDataSet *				GetFaBan2() ; 
	/// 筏板3
	static NDataModelDataSet *				GetFaBan3();
	/// 筏板4
	static NDataModelDataSet *				GetFaBan4();
	/// 筏板5
	static NDataModelDataSet *				GetFaBan5();
	/// 筏板6
	static NDataModelDataSet *				GetFaBan6();
	/// 筏板7
	static NDataModelDataSet *				GetFaBan7();

	/// 砼外墙1
	static NDataModelDataSet *				GetQiangDataSet1() ; 
	/// 砼外墙2
	static NDataModelDataSet *				GetQiangDataSet2() ; 
	/// 砼外墙3
	static NDataModelDataSet *				GetQiangDataSet3();
	/// 砼外墙4
	static NDataModelDataSet *				GetQiangDataSet4();
	/// 砼外墙5
	static NDataModelDataSet *				GetQiangDataSet5();
	/// 砼外墙6
	static NDataModelDataSet *				GetQiangDataSet6();
	/// 砼外墙7
	static NDataModelDataSet *				GetQiangDataSet7();
	/// 基础梁1
	static NDataModelDataSet *				GetJcLiangDatSet1() ; 
	/// 基础梁2
	static NDataModelDataSet *				GetJcLiangDatSet2() ; 
	/// 基础梁3
	static NDataModelDataSet *				GetJcLiangDatSet3() ; 
	/// 基础梁4
	static NDataModelDataSet *				GetJcLiangDatSet4() ; 
	/// 基础梁5
	static NDataModelDataSet *				GetJcLiangDatSet5() ; 
	/// 基础梁6
	static NDataModelDataSet *				GetJcLiangDatSet6() ; 
	/// 基础梁7
	static NDataModelDataSet *				GetJcLiangDatSet7() ;
	
	/// 拆分表达式
	static void							GetMinMaxWidth( CString strValue , int &nMin , int &nMax , BOOL & bIsEqu ) ; 
	static void							GetMinMaxHeight( CString strValue , int &nMin , int &nMax,BOOL & hIsEqu) ; 
	///新增
	static void                         GetOperator( const int iPos, CString strValue , int &nMin , int &nMax  , BOOL & bIsEqu );
	static void							InsertRow( NDataModelDataSet * pDataSet , 
		const CString & strGjName , 
		const CString & strBH = _T("-1") ) ; 
};
