#pragma once

//#include "PMArchiveBase.h"
#include "ParmInfoBase.h"

namespace ProjectInfoMacro
{
	enum GangJinMode//钢筋模式
	{
		GangjinDefault = -1,
		GangJin03G = 0,
		GangJin11G = 1,
		GangJin16G = 2
	};
}

namespace Steel3DInfo 
{
	//弯钩类型
	enum WGLX
	{
		eNoWg = 0	//没弯钩
		,eWg90		//90度弯钩
		,eWg135		//135弯钩
		,eWg180		//180度弯钩
	};
}



class PMLogicDataOprAPI CProject_CalRule_SgdLbTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_CalRule_SgdLbTable)

	CProject_CalRule_SgdLbTable();
	virtual ~CProject_CalRule_SgdLbTable();

	struct PMLogicDataOprAPI CFieldInfo
	{	
		static const CString comtype;					//构件comtype
		static const CString parmid;					//对应SysDefRule.xml中的parmid
		static const CString parmname;					//对应SysDefRule.xml中的parmname
		static const CString sgdlb;						//施工段类别

		static const CString table_name;				//表名
		static const CString strSQL;					// SQL语句
	};

	virtual int InitFieldStr();
	int InitFieldStr( NDataModelDataSet * pDataSet );
};

class PMLogicDataOprAPI CProject_QtgjTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_QtgjTable)

	CProject_QtgjTable();
	virtual ~CProject_QtgjTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id ;
		static const CString comtype ;
		static const CString showname ;
		static const CString qtgj ; 
	};


	struct PMLogicDataOprAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};


	virtual int InitFieldStr();

public:
	/// 
	/// 该接口升级里面调用
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};

class PMLogicDataOprAPI CProject_TtymjTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_TtymjTable)

	CProject_TtymjTable();
	virtual ~CProject_TtymjTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id ;
		static const CString comtype ;
		static const CString showname ;
		static const CString ttymj ; 
	};


	struct PMLogicDataOprAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};


	virtual int InitFieldStr();

public:
	/// 
	/// 该接口升级里面调用
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};

class PMLogicDataOprAPI CProject_FloorDJXSTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_FloorDJXSTable)

	CProject_FloorDJXSTable();
	virtual ~CProject_FloorDJXSTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;
		static int	 id_Index;

		static const CString zjfw;			//直径范围
		static int		zjfw_Index;

		static const CString jc;				//基础
		static int			jc_Index;

		static const CString qsx;				//墙竖向
		static int			qsx_Index;

		static const CString qsp;				//墙横向
		static int			qsp_Index;

		static const CString zhu;				//柱
		static int			zhu_Index;

		static const CString kjl;				//框架梁	
		static int			kjl_Index;

		static const CString cl;				//次梁	
		static int			cl_Index;

		static const CString ban;				//板
		static int			ban_Index;

		static const CString qt;				//其它
		static int			qt_Index;

		static const CString sp_value ;//水平向 搭接 
		static const CString sz_value ;//垂直向 搭接

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

/**
 * @brief 添加放坡土方增量折算厚度的Grid字段
 *
 *        
 * @author 郑琪崇
 * @version v1.0
 * @date  2016年3月18日   12:19
 * @note  
 */
class PMLogicDataOprAPI CProject_SlopeEarTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SlopeEarTable)

	CProject_SlopeEarTable();
	virtual ~CProject_SlopeEarTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;
		static int	 id_Index;

		static const CString jclx;			//基础类型
		static int		jclx_Index;

		static const CString parmname;		//参数名称
		static int parmname_Index;

		static const CString wtsd;			//挖土深度
		static int			wtsd_Index;

		static const CString fptfzshd;		//放坡土方折算厚度
		static int			fptfzshd_Index;


		static const CString table_name;
	};

	virtual int InitFieldStr();

	int	InitFieldStrV2( NDataModelDataSet * pDataSet ) ; 
};

/**
 * @brief  :实物量计算用数据结构
 *
 *          
 * @author :zfy
 * @version:v1.0
 * @date   :[9/11/2017]
 * @note   :
 */
class PMLogicDataOprAPI CProject_SwlRule_ForCal : public CPM_StorageDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SwlRule_ForCal)

	CProject_SwlRule_ForCal();
	virtual ~CProject_SwlRule_ForCal();

	struct PMLogicDataOprAPI CFieldInfo
	{
		//id
		static const CString id;
		static const int	 id_Index;
		
		static const CString parmid;
		static const int	 parmid_Index;

		//名称
		static const CString name;
		static const int name_Index;

		//comtype
		static const CString comtype;
		static const int	 comtype_Index;

		//变量名称
		static const CString mid_var_name;
		static const int	 mid_var_name_Index;

		//变量值
		static const CString mid_var_value;
		static const int	 mid_var_value_Index;

		//是否输出
		static const CString output;
		static const int	 output_Index;

		//排序字段，仅用于同parmid 内部的行的排序
		static const CString sortid;
		static const int	 sortid_Index;

		//单位
		static const CString unit;
		static const int unit_Index;

		//计算项目/扣减项目/增加项目
		static const CString quantity;
		static const int quantity_Index;

		//附件尺寸
		static const CString sections;
		static const int sections_Index;

		//计算公式
		static const CString formulas;
		static const int formulas_Index;

		//编辑模式
		static const CString editmode;
		static const int editmode_Index;

		//表名
		static const CString table_name;
	};

	virtual int InitFieldStr();

	int	InitFieldStrV2( NDataModelDataSet * pDataSet ) ; 
};

class PMLogicDataOprAPI CProject_SpecificGravityTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SpecificGravityTable)

	CProject_SpecificGravityTable();
	virtual ~CProject_SpecificGravityTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;					
		static const CString xh;
		static const CString gjlx;
		static const CString diameter;
		static const CString sg;

		///static const CString table_name;
	};

	struct PMLogicDataOprAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

class PMLogicDataOprAPI CProject_ProjectCodeTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ProjectCodeTable)

	CProject_ProjectCodeTable();
	virtual ~CProject_ProjectCodeTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString parmname;
		static const CString parmvalue;

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PMLogicDataOprAPI CSysComParamsSetTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CSysComParamsSetTable)

	CSysComParamsSetTable();
	virtual ~CSysComParamsSetTable();

public:
	virtual int InitFieldStr();

public:
	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString ParmID ;
		static const CString gangjin_mode ;
		static const CString UpdateMode ;
		static const CString comtype ;
		static const CString SubComType ;
		static const CString parmtype ;
		static const CString parmname ;
		static const CString parmdisplayname ;
		static const CString parmvalue ;
		static const CString InputMode ;
		static const CString DataType ;
		static const CString processType ;
		static const CString exp ;
		static const CString InvalidMsg ;
		static const CString Hide ;
		static const CString SortID ;
		static const CString TreeNode ;
		static const CString used_bz;

		static		 int	 ParmID_Index;
		static		 int	 gangjin_mode_Index;
		static		 int	 UpdateMode_Index;
		static		 int	 comtype_Index;
		static		 int	 SubComType_Index;
		static		 int	 parmtype_Index;
		static		 int	 parmname_Index;
		static		 int	 parmdisplayname_Index;
		static		 int	 parmvalue_Index;
		static		 int	 InputMode_Index;
		static		 int	 DataType_Index;
		static		 int	 processType_Index;
		static		 int	 exp_Index;
		static		 int	 InvalidMsg_Index;
		static		 int	 Hide_Index;
		static		 int	 SortID_Index;
		static		 int	 TreeNode_Index;
		static		 int	 used_bz_Index;

		/// idx 递增的辅助变量
		/// idx 需要在函数 InitFieldStr 外 ，初始化为有意义的值
		/// 且赋值的顺序应该和 InitFieldStr中添加的顺序一样
		static int idx_step ; 
	};

	struct PMLogicDataOprAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

};



class PMLogicDataOprAPI CProject_VectorParmsTable : public CPM_StorageDataSet  
{
public:
	DECLARE_DYNCREATE(CProject_VectorParmsTable)

	CProject_VectorParmsTable();
	virtual ~CProject_VectorParmsTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString	parmid ;
		static int				parmid_Index;

		static const CString	vectorid ;
		static int				vectorid_Index;

		static const CString	parmmode ;
		static int				parmmode_Index;

		static const CString	datatype ;//1:钢筋信息  2：算量信息
		static int				datatype_Index;

		static const CString	parmname ;
		static int				parmname_Index;

		static const CString	parmvalue ;
		static int				parmvalue_Index;

		static const CString	msgInfo;
		static int				msgInfo_Index;
	};

	virtual int InitFieldStr();

};

//////////////////////////////////////////////////////////////////////////
//
class PMLogicDataOprAPI CProject_QDDE_UITable : public NDbDataSet  
{
public:
	DECLARE_DYNCREATE(CProject_QDDE_UITable)

	/// 行的种类
	enum RowType
	{
		eItem = 1 ,			/// 计算项目
		eQd = 2 ,			/// 清单
		eSubItem = 3 ,		/// 清单下的子项目
		eDe = 4 			/// 定额
	} ; 

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id ;
		static const CString ComType ;
		static const CString name ;
		static const CString subname ; /// 子项目 和 清单的项目特征
		static const CString DEID ;
		static const CString DEName ;
		static const CString DECode ;
		static const CString Unit ;
		static const CString Quantity ;
		static const CString Sections ;
		static const CString Formulas ;
		static const CString EditMode ;
		static const CString RationRow ;
		static const CString RowType ;   /// 行的类型
		static const CString ItemCharacter ; 
		static const CString NodeID ; 
		static const CString Index_qdtable;//保存的清单ComID 数据库 主键
//		static const CString Index_qdinfotable;//保存清单信息 数据库 主键

		static int id_Index;
		static int ComType_Index ;
		static int name_Index ;
		static int subname_Index ; /// 子项目 和 清单的项目特征
		static int DEID_Index ;
		static int DEName_Index ;
		static int DECode_Index ;
		static int Unit_Index ;
		static int Quantity_Index ;
		static int Sections_Index ;
		static int Formulas_Index ;
		static int EditMode_Index ;
		static int RationRow_Index ;
		static int RowType_Index ;   /// 行的类型
		static int ItemCharacter_Index ; 
		static int NodeID_Index ; 
		static int Index_qdtable_Index;
//		static int Index_qdinfotable_Index;
	};

	CProject_QDDE_UITable();
	virtual ~CProject_QDDE_UITable();
	virtual int InitFieldStr();

};


class PMLogicDataOprAPI CProject_VectorBuildInfoTable : public NDataModelDataSet  
{
public:
	DECLARE_DYNCREATE(CProject_VectorBuildInfoTable)
	CProject_VectorBuildInfoTable();
	virtual ~CProject_VectorBuildInfoTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id ;
		static const CString hzxx ;
		static const CString qdm ;
		static const CString zzm ;
		static const CString gd ;
		static const CString tgx ;
		static const CString dtbl ;
	};

	virtual int InitFieldStr() ;
};


struct PMLogicDataOprAPI CQDDE_JSGZ_Com
{
	static const CString id ;
	static int	id_Index;

	static const CString ParmID ;
	static int	ParmID_Index;

	static const CString ParmName ;
	static int	ParmName_Index;

	static const CString Value ;
	static int	Value_Index;

	static const CString DefValue ;
	static int	DefValue_Index;

	static const CString ListData ;
	static int	ListData_Index;

	static const CString IniType ;
	static int	IniType_Index;

	static const CString Desc ;
	static int	Desc_Index;

	static NDataModelDataSet * GetDataSet() ;
};

struct PMLogicDataOprAPI CQDDE_FJCC_Com
{
	static const CString id ;
	static int			id_Index;

	static const CString ComType ;
	static int			ComType_Index;

	static const CString parmdisplayname ;
	static int			parmdisplayname_Index;

	static const CString ParmValue ;
	static int			ParmValue_Index;

	static const CString ListData ;
	static int			ListData_Index;

	static const CString InputMode ;
	static int			InputMode_Index;

	static const CString CheckReg ;
	static int			CheckReg_Index;

	static NDataModelDataSet * GetDataSet() ;
};


class PMLogicDataOprAPI CProject_FloorTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_FloorTable)

	CProject_FloorTable();
	virtual ~CProject_FloorTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;							//楼层号
		static const CString showid;						//层显示序号
		static const CString lcmc;						//楼层名称
		static const CString lcxz;						//楼层性质
		static const CString cs;							//层数
		static const CString cg;							//层高(mm)
		static const CString ldmbg;						//楼地面标高(mm)
		static const CString tqd;							//砼强度
		static const CString zdj;							//砖等级
		static const CString sjdj;						//砂浆等级
		static const CString filename;					//图形文件名称
		static const CString bz;							//备注
		static const CString ztjzmj;						//主体建筑面积
		static const CString ytjzmj;						//阳台建筑面积
		static const CString jss;							//主体建筑面积的计算式
		static const CString bh;							//板厚(mm)
		static const CString dmj;							//单层建筑面积(m2)

		static const CString table_name;					//表名
	};

	virtual int InitFieldStr();
};


class PMLogicDataOprAPI CProject_ResultTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ResultTable)

	CProject_ResultTable();
	virtual ~CProject_ResultTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;							//主键id
		static const CString comid;						//构件编号
		static const CString cadhandle;					//CAD唯一标识，字符串
		static const CString calitemid;					//存放 QDData 中 对应的 id , 清单和定额的 附属关系 依赖这个字段
		static const CString calitemname;					//定额的时候存放 计算项目名称,清单的时候存放 "清单" 两个字
		static const CString positions;					//在平面图中的位置
		static const CString topaxis;						//上
		static const CString buttonaxis;					//下
		static const CString rightaxis;					//右
		static const CString leftaxis;					//左
		static const CString rationrow;					//定额对应在 Ration表中对应的 行号
		static const CString qddeid;						//定额的时候存放定额编码 ,清单的时候存放清单ID .
		static const CString qddename;					//定额的时候存放定额名称 ,清单的时候存放清单名称.
		static const CString unit;						//单位
		static const CString formula;						//工程量计算公式
		static const CString transformula;				//工程量计算公式(用于显示)
		static const CString quantity;					//计算量
		static const CString mainmode;					//主体 1:清单  0:定额
		static const CString fjhandle;					//房间Handle
		static const CString gjmode;						//构件特殊标记 0：正常 1：梁板折算
		static const CString nodeid ;
		static const CString calfloorid ;				/// 构件所在的实际楼层id, 表示跨层构件所在的实际楼层
		static const CString CCInfo;//CC信息队列 如 2,3

		static const CString quantity_5D;					//计算量,5D需要的单个的量(若为联通则,每个构件单独的量,没有经过A值转换的)

		/// 一些常量的定义还是放在该类中定义，虽然已经不属于该表结构
		static const CString FloorID ;
		static const CString FloorShowID ;
		static const CString ComType ;
		static const CString ShowID ; 
		static const CString ComName ;
		

		static const CString table_name;

		static const int cur_version ; 
	};

	virtual int InitFieldStr();

public:
	/// 
	/// 该接口升级里面调用
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};


//实物量报表需要的额外值存储
class PMLogicDataOprAPI CProject_SWLExtraValueTable  : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SWLExtraValueTable)

	CProject_SWLExtraValueTable();
	virtual ~CProject_SWLExtraValueTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;						//序号
		static const CString cadhandle;				//构件的句柄
		static const CString comid;					//构件的id
		static const CString comtype;					//构件的种类
		static const CString floorid;					//构件所在楼层
		static const CString parmname;			//构件参数名称
		static const CString parmvalue;			//构件参数值
		static const CString parmenum;           //参数对应的枚举值
		static const CString table_name;
	};

	virtual int InitFieldStr();
};


class PMLogicDataOprAPI CProject_SgdResultTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SgdResultTable)

	CProject_SgdResultTable();
	virtual ~CProject_SgdResultTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;							//主键id
		static const CString comid;						//构件编号
		static const CString cadhandle;					//CAD唯一标识，字符串
		static const CString calitemid;					//存放 QDData 中 对应的 id , 清单和定额的 附属关系 依赖这个字段
		static const CString calitemname;					//定额的时候存放 计算项目名称,清单的时候存放 "清单" 两个字
		static const CString positions;					//在平面图中的位置
		static const CString topaxis;						//上
		static const CString buttonaxis;					//下
		static const CString rightaxis;					//右
		static const CString leftaxis;					//左
		static const CString rationrow;					//定额对应在 Ration表中对应的 行号
		static const CString qddeid;						//定额的时候存放定额编码 ,清单的时候存放清单ID .
		static const CString qddename;					//定额的时候存放定额名称 ,清单的时候存放清单名称.
		static const CString unit;						//单位
		static const CString formula;						//工程量计算公式
		static const CString transformula;				//工程量计算公式(用于显示)
		static const CString quantity;					//计算量
		static const CString mainmode;					//主体 1:清单  0:定额
		static const CString fjhandle;					//房间Handle
		static const CString gjmode;						//构件特殊标记 0：正常 1：梁板折算
		static const CString nodeid ;
		static const CString worksegcomid;				// 施工段comid
		static const CString calfloorid ;				/// 构件所在的实际楼层id, 表示跨层构件所在的实际楼层
		static const CString CCInfo;//CC信息队列 如 2,3

		static const CString quantity_5D;					//计算量,5D需要的单个的量(若为联通则,每个构件单独的量,没有经过A值转换的)

		/// 一些常量的定义还是放在该类中定义，虽然已经不属于该表结构
		static const CString FloorID ;
		static const CString FloorShowID ;
		static const CString ComType ;
		static const CString ShowID ; 
		static const CString ComName ;


		static const CString table_name;

		static const int cur_version ; 
	};

	virtual int InitFieldStr();

public:
	/// 
	/// 该接口升级里面调用
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};


class PMLogicDataOprAPI CProject_RoomTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_RoomTable)

	CProject_RoomTable();
	virtual ~CProject_RoomTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;				//该表的逻辑ID,主键.
		static const CString fjcomid;			//房间ComID
		static const CString fjhandle;		//房间ComID
		static const CString fjname;			//房间名称
		static const CString fjposition;		//房间位置
		static const CString floorid;			//楼层ID
		static const CString floorshowid;		//楼层排序ID
		static const CString nqmcomid;		//内墙面  ------数组
		static const CString nqmhandle;		//内墙面Handle--数组
		static const CString zmcomid;		//柱面  ------数组
		static const CString zmhandle;		//柱面Handle--数组
		static const CString ldmcomid;		//楼地面
		static const CString ldmhandle;
		static const CString tpcomid;			//天棚
		static const CString tphandle;

		static const CString table_name;

		static const int cur_version ;
	};

	virtual int InitFieldStr();

public:
	/// 
	/// 该接口升级里面调用
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};


class PMLogicDataOprAPI CProject_GJJMInfoTable  : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_GJJMInfoTable)

	CProject_GJJMInfoTable();
	virtual ~CProject_GJJMInfoTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;						//序号
		static const CString cadhandle;				//构件的句柄
		static const CString comid;					//构件的id
		static const CString comtype;					//构件的种类
		static const CString floorid;					//构件所在楼层
		static const CString pathlength;				//构件的绘制长度
		static const CString jminfo;					//构件的截面信息 (B*H)
		static const CString jmarea;					//构件的截面面积
		static const CString width;					//构件的厚度
		static const CString dingbg;					//构件的顶标高
		static const CString dibg;					//构件的底标高
		static const CString jmb;						//截面宽
		static const CString jmh;						//截面高
		static const CString jmgirth;					//截面周长
		static const CString pmxz;					//平面形状 1 弧形 0 直型
		static const CString extend;					//扩展信息 格式为 : 标志|值; 标志:1 斜度, 2 挖土深度, 3 房间编号 , 4 基础深度 , 5 墙面材料

		static const CString table_name;
	};

	virtual int InitFieldStr();
};


class PMLogicDataOprAPI CProject_ParmValueTable : public CPM_StorageDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ParmValueTable)

	CProject_ParmValueTable();
	virtual ~CProject_ParmValueTable();

	struct  PMLogicDataOprAPI CFieldInfo
	{
		static const CString SubComType;
		static		int		SubComType_Index;

		static const CString ParmName ;
		static		int		ParmName_Index;

		static const CString ParmValue ;
		static		int		ParmValue_Index;

		static const CString InvalidMsg;
		static		int		InvalidMsg_Index;
	};

	virtual int InitFieldStr();
};


class PMLogicDataOprAPI CProject_SwlResultTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SwlResultTable)

	CProject_SwlResultTable();
	virtual ~CProject_SwlResultTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;							//主键id
		static const CString comid;						//构件编号
		static const CString cadhandle;					//CAD唯一标识，字符串
		static const CString calitemid;					//存放 QDData 中 对应的 id , 清单和定额的 附属关系 依赖这个字段
		static const CString calitemname;					//定额的时候存放 计算项目名称,清单的时候存放 "清单" 两个字
		static const CString positions;					//在平面图中的位置
		static const CString topaxis;						//上
		static const CString buttonaxis;					//下
		static const CString rightaxis;					//右
		static const CString leftaxis;					//左
		static const CString rationrow;					//定额对应在 Ration表中对应的 行号
		static const CString qddeid;						//定额的时候存放定额编码 ,清单的时候存放清单ID .
		static const CString qddename;					//定额的时候存放定额名称 ,清单的时候存放清单名称.
		static const CString unit;						//单位
		static const CString formula;						//工程量计算公式
		static const CString transformula;				//工程量计算公式(用于显示)
		static const CString quantity;					//计算量
		static const CString mainmode;					//主体 1:清单  0:定额
		static const CString fjhandle;					//房间Handle
		static const CString gjmode;						//构件特殊标记 0：正常 1：梁板折算
		static const CString nodeid ;
		static const CString calfloorid ;
		static const CString CCInfo;//CC信息队列 如 2,3

		static const CString quantity_5D;					//计算量,5D需要的单个的量(若为联通则,每个构件单独的量,没有经过A值转换的)

		/// 一些常量的定义还是放在该类中定义，虽然已经不属于该表结构
		static const CString FloorID ;
		static const CString FloorShowID ;
		static const CString ComType ;
		static const CString ShowID ; 
		static const CString ComName ;

		static const CString table_name;

		static const int cur_version ; 
	};

	virtual int InitFieldStr();

public:
	/// 
	/// 该接口升级里面调用
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};

class PMLogicDataOprAPI CProject_SgdSwlResultTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SgdSwlResultTable)

	CProject_SgdSwlResultTable();
	virtual ~CProject_SgdSwlResultTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;							//主键id
		static const CString comid;						//构件编号
		static const CString cadhandle;					//CAD唯一标识，字符串
		static const CString calitemid;					//存放 QDData 中 对应的 id , 清单和定额的 附属关系 依赖这个字段
		static const CString calitemname;					//定额的时候存放 计算项目名称,清单的时候存放 "清单" 两个字
		static const CString positions;					//在平面图中的位置
		static const CString topaxis;						//上
		static const CString buttonaxis;					//下
		static const CString rightaxis;					//右
		static const CString leftaxis;					//左
		static const CString rationrow;					//定额对应在 Ration表中对应的 行号
		static const CString qddeid;						//定额的时候存放定额编码 ,清单的时候存放清单ID .
		static const CString qddename;					//定额的时候存放定额名称 ,清单的时候存放清单名称.
		static const CString unit;						//单位
		static const CString formula;						//工程量计算公式
		static const CString transformula;				//工程量计算公式(用于显示)
		static const CString quantity;					//计算量
		static const CString mainmode;					//主体 1:清单  0:定额
		static const CString fjhandle;					//房间Handle
		static const CString gjmode;						//构件特殊标记 0：正常 1：梁板折算
		static const CString nodeid ;
		static const CString worksegcomid;					// 施工段comid
		static const CString calfloorid ;
		static const CString CCInfo;//CC信息队列 如 2,3

		static const CString quantity_5D;					//计算量,5D需要的单个的量(若为联通则,每个构件单独的量,没有经过A值转换的)


		/// 一些常量的定义还是放在该类中定义，虽然已经不属于该表结构
		static const CString FloorID ;
		static const CString FloorShowID ;
		static const CString ComType ;
		static const CString ShowID ; 
		static const CString ComName ;

		static const CString table_name;

		static const int cur_version ; 
	};

	virtual int InitFieldStr();

public:
	/// 
	/// 该接口升级里面调用
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};

class PMLogicDataOprAPI CProject_SwlRoomTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SwlRoomTable)

	CProject_SwlRoomTable();
	virtual ~CProject_SwlRoomTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;				//该表的逻辑ID,主键.
		static const CString fjcomid;			//房间ComID
		static const CString fjhandle;		//房间ComID
		static const CString fjname;			//房间名称
		static const CString fjposition;		//房间位置
		static const CString floorid;			//楼层ID
		static const CString floorshowid;		//楼层排序ID
		static const CString nqmcomid;		//内墙面  ------数组
		static const CString nqmhandle;		//内墙面Handle--数组
		static const CString ldmcomid;		//楼地面
		static const CString ldmhandle;
		static const CString tpcomid;			//天棚
		static const CString tphandle;

		static const CString table_name;

		static const int cur_version ; 
	};

	virtual int InitFieldStr();

public:
	/// 
	/// 该接口升级里面调用
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};


class PMLogicDataOprAPI CProject_SwlGJJMInfoTable  : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SwlGJJMInfoTable)

	CProject_SwlGJJMInfoTable();
	virtual ~CProject_SwlGJJMInfoTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;						//序号
		static const CString cadhandle;				//构件的句柄
		static const CString comid;					//构件的id
		static const CString comtype;					//构件的种类
		static const CString floorid;					//构件所在楼层
		static const CString pathlength;				//构件的绘制长度
		static const CString jminfo;					//构件的截面信息 (B*H)
		static const CString jmarea;					//构件的截面面积
		static const CString width;					//构件的厚度
		static const CString dingbg;					//构件的顶标高
		static const CString dibg;					//构件的底标高
		static const CString jmb;						//截面宽
		static const CString jmh;						//截面高
		static const CString jmgirth;					//截面周长
		static const CString pmxz;					//平面形状 1 弧形 0 直型
		static const CString extend;					//扩展信息 格式为 : 标志|值; 标志:1 斜度, 2 挖土深度, 3 房间编号 , 4 基础深度 , 5 墙面材料

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

/**
 * @brief  :实物量规则维护界面用的dataset
 *
 *          
 * @author :zfy
 * @version:v1.0
 * @date   :[9/5/2017]
 * @note   :
 */
class PMLogicDataOprAPI CSwljsRulesTable  : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CSwljsRulesTable)

	CSwljsRulesTable();
	virtual ~CSwljsRulesTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;						//序号
		static const CString parmid;					//实物量计算规则 的 parmid
		static const CString name;						//名称
		static const CString unit;						//单位
		static const CString quantity;					//计算方法、增加项目、扣减项目
		static const CString sections;					//附件尺寸
		static const CString formulas;					//自定义的计算公式
		static const CString isOutput;					//是否输出
		static const CString editmode;					//
		static const CString defaultValue;				//
		static const CString sortid;

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

struct PMLogicDataOprAPI CDE_SWL_Com
{
	static const CString id ;
	static int	id_Index;

	static const CString ParmID ;
	static int	ParmID_Index;

	static const CString ParmName ;
	static int	ParmName_Index;

	static const CString OutPut;
	static int  OutPut_Index;

	static const CString Value ;
	static int	Value_Index;

	static const CString DefValue ;
	static int	DefValue_Index;

	static const CString ListData ;
	static int	ListData_Index;

	static const CString IniType ;
	static int	IniType_Index;

	static const CString Desc ;
	static int	Desc_Index;

	static NDataModelDataSet * GetDataSet() ;
};
 
 
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 /// 钢筋计算结果
 class PMLogicDataOprAPI CProject_GraphicsResultTable: public CSQLDataSet
 {
 public:
 	DECLARE_DYNCREATE(CProject_GraphicsResultTable)
 
 	CProject_GraphicsResultTable();
 	virtual ~CProject_GraphicsResultTable();
 
 	struct PMLogicDataOprAPI CFieldInfo
 	{
 		static const CString id;					//该表的逻辑id
 		static const CString floorid;				//楼层
 		static const CString comid;				//构件
 		static const CString cadhandle;			//cad句柄
 		static const CString positions;			//在平面图中的位置
 		static const CString topaxis;				//上
 		static const CString buttonaxis;			//下
 		static const CString rightaxis;			//右
 		static const CString leftaxis;			//左
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
 		static const CString jtdrawbuffer;
 		static const CString mtgs ;
 		static const CString mtxs ; 
 
 		static const CString table_name;			//钢筋计算结果表
 	};
 
 	virtual int InitFieldStr();
 
 public:
 	struct PMLogicDataOprAPI CTableData 
 	{
 		static const int cur_version ; 
 	};
 
 	/// 
 	/// 该接口升级里面调用
 	/// 
 	int		InitFieldStr( const int iVersion ) ; 
 };

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
class PMLogicDataOprAPI CProject_GraphicsResultV2Table : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_GraphicsResultV2Table)
public:
	CProject_GraphicsResultV2Table() ; 
	virtual ~CProject_GraphicsResultV2Table() ;

public:
	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString showindex ;		// 显示的顺序，
												//在结果区显示和在在报表中显示，会依赖这个字段

		static const CString id;				//该表的逻辑id
		static const CString comid;				//构件
		static const CString floorid ;			//楼层id
		static const CString cadhandle;			//cad句柄
		static const CString positions;			//在平面图中的位置
		static const CString gjlb;				//钢筋名称 
		static const CString gjlx;				//钢筋类型
		static const CString gjjb;				//钢筋级别
		static const CString zj;				//直径
		static const CString gs;				//根数
		static const CString th;				//图号		
		static const CString wg;				//弯勾
		static const CString dj;				//搭接
		static const CString djxs;				//搭接形式
		static const CString jtgs;				//接头个数
		static const CString cd;				//长度
		static const CString zz;				//总重
		static const CString jsgs;				//计算公式	--- 长度的数字描述
		static const CString gsms;				//公式描述 --- 长度的公司描述
		static const CString count_des ;		//根数的公式描述 --- 数字描述
		static const CString sttype;			//钢筋类别 默认0时为计算所得，1时为手工加入
		static const CString resulttype;		//计算结果的种类， 构件结果锁定		
		static const CString errortype;			//计算结果有错误，需要出现问号	
		static const CString cc;				//楼层的层数
		static const CString cc_count;			//楼层的层数
		static const CString jtdrawbuffer;		//简图信息包括3维信息
		static const CString tzz;				//钢筋按中心线等计算方式产生的调整值

		/// 
		/// 锚头个数和锚头形式，
		/// 在柱和梁计算的时候需要
		/// 
		static const CString mtgs ;				//
		static const CString mtxs ;				//

		static const CString table_name;			//钢筋计算结果表
	};

public:
	virtual int InitFieldStr();

public:
	struct PMLogicDataOprAPI CTableData 
	{
		static const int cur_version ; 
	};

	/// 
	/// 该接口升级里面调用
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};

class PMLogicDataOprAPI CProject_TtymjResultTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_TtymjResultTable)
public:
	CProject_TtymjResultTable() ; 
	virtual ~CProject_TtymjResultTable() ;

public:
	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString showindex ;		// 显示的顺序，
		//在结果区显示和在在报表中显示，会依赖这个字段

		static const CString id;				//该表的逻辑id
		static const CString comid;				//构件
		static const CString floorid ;			//楼层id
		static const CString cadhandle;			//cad句柄
		static const CString comtype;			//comtype
		static const CString bh;				//编号
		static const CString lb;				//类别
		static const CString gnmc;				//功能名称
		static const CString sl;				//数量
		static const CString zj;				//直径
		static const CString gg;				//规格		
		static const CString bz;				//备注
		static const CString table_name;		//套筒预埋件结果表
	};

public:
	virtual int InitFieldStr();

public:
	struct PMLogicDataOprAPI CTableData 
	{
		static const int cur_version ; 
	};

	/// 
	/// 该接口升级里面调用
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};
/// 
struct PMLogicDataOprAPI CComParmsSet_ParmName
{
	static const int Unkown_ParmType;
	static const int Globel_ParmType;	/// 全局的参数 (在工程设置中设置的,在图形法和构件法中都需要的属性参数)
	static const int SL_ParmType;		/// 算量的参数(在算量和图形法钢筋中都需要的需要有的属性参数)
	static const int GJ_ParmType;		/// 钢筋的参数( 在钢筋中才需要的属性参数 )
	static const int GJ_JSSZ_ParmType;	/// 钢筋计算设置的参数 (钢筋中才需要)
	static const int SL_ParmType_OL ;   /// 算量的参数 ( 只在算量的中才有的 属性参数 )
	static const int Vector_ParmType;

	static const CString d_length;
	static const CString H_length;
	static const CString ZDCDJ;
	static const CString ZDCMG;
	static const CString bfl;
	static const CString KZDJ;
	static const CString DJ1;
	static const CString DJB1 ;
	static const CString DJ2;
	static const CString DJB2 ;
	static const CString DJ3;
	static const CString DJB3 ;
	static const CString DJ4;
	static const CString DJB4;
	static const CString DJ5;
	static const CString DJ6;
	static const CString DJ7;
	static const CString MG1;
	static const CString MGB1 ;
	static const CString MG2;
	static const CString MGB2 ;
	static const CString MG3;
	static const CString MGB3 ;
	static const CString MG4;
	static const CString MGB4;
	static const CString MG5;
	static const CString MG6;
	static const CString MG7;
	static const CString ZJWG;
	static const CString DJXS;
	static const CString GJWG;
	static const CString GJTZZ;//钢筋调整值
	static const CString GJJSFS;//钢筋计算方式
	static const CString GJZS;
	static const CString wgjd;
	static const CString TQD;
	static const CString JCTQD;//基础砼强度
	static const CString DCTQD;//垫层砼强度
	static const CString GJLX;
	static const CString bhc;
	static const CString def1jt;
	static const CString GJ_rule;
	static const CString GJJSGZ;
	static const CString GJJSSZ_UI;
	static const CString kwgjd;

	static const CString component;

	static const CString componenttype;
	static const CString jm;
	static const CString loss_coefficient;//损耗率

	static const CString Length;	//长
	static const CString Width;		//宽
	static const CString Height;	//高
	static const CString JMBian;	//边属性
	static const CString JMBianOrder;	//截面边绘制顺序

	static const CString Topbg;//顶标高
	static const CString Bottombg;//底标高

	static const CString VectorID;	//截面图ID 
	static const CString VectorID_Gj; //钢筋配筋图ID 

	static const CString JMMS;		//截面描述
	static const CString GJYS;		//构件颜色

	static const CString GJMS;      //qc:29805 新增钢筋描述
};

/**
* @brief 参数拆分基类，用于将复杂参数 拆分成单一数据方便处理  
*
*          
* @note  : 目前他只是为CCalComParmsInfo 的parmvalue进行拆分服务。
* @param : 
* @defenc: 
* @return: 
* @author: 王建业
* @date  : [8/1/2014]
*/
class PMLogicDataOprAPI CComParmSplitBase
{
public:
	CComParmSplitBase(){};
	virtual ~CComParmSplitBase(){};

	/**
	* @brief 外部访问参数的 统一接口  
	*
	*          
	* @note  : 
	* @param : const CString & strParmName：参数名称
				const CParmInfoBase *& pTemValueBase：参数拆分后的结果，不用维护返回指针
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [8/1/2014]
	*/
	virtual BOOL GetComParmInfo(const CString & strParmName,const CParmInfoBase *& pTemValueBase) = 0;

protected:

	/**
	* @brief 在获取参数的情况下，没有拆分数据，使用接口进行拆分处理。  
	*
	*          
	* @note  : 
	* @param : const CString & strParmName:参数名称
				const CString & strParmValue：参数值
				CParmInfoBase *& pTemValueBase：参数拆分后的结果，外部需要维护返回的内存
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [8/1/2014]
	*/
	virtual BOOL DoSplitComParm(const CString & strParmName,const CString & strParmValue,CParmInfoBase *& pTemValueBase) = 0;
};

class PMLogicDataOprAPI CComParmsInfoMap
{
public:

	CComParmsInfoMap();
	virtual ~CComParmsInfoMap();

	class PMLogicDataOprAPI CCalComParmsInfo
	{
	public:
		friend CComParmSplitBase;

		CCalComParmsInfo();
		virtual ~CCalComParmsInfo();

		void SetParmName(const CString & strParmName);
		CString GetParmName();

		void SetParmValue(const CString & strParmValue);
		CString GetParmValue();

		void SetInvalidMsg(const CString & strInvalidMsg);
		CString GetInvalidMsg();

		BOOL SerializeFrom(const CPmArchiveBase & archive);
		BOOL SerializeTo(CPmArchiveBase & archive) const;

		/// 
		CParmInfoBase * GetParmInfoBase();
		void SetParmInfoBase(CParmInfoBase * pTemParmInfoBase);

		/// 
		void	ReleaseParmInfoBase() ; 

	protected:
		CString m_strParmName;
		CString m_strParmValue;
		CString m_strInvalidMsg;
		CParmInfoBase * m_pParmValueBase;
	};

	void	AddSortParmName( const CString & strParmName ) ;

	BOOL	HasParm( const CString & strParmName ) ; 

	BOOL AddComParmInfo(const CString & strName,CCalComParmsInfo * pComParmsInfo);
	BOOL GetComParmValue(const CString & strName,CString & strParmValue) const ;
	// qc:28671 获取Invalidmsg值
	BOOL GetInvalidmsgValue(const CString & strName,CString & strInvalidmsgValue) const ;
	BOOL GetComParmInv(const CString & strName,CString & strParmValue) const ;
	CCalComParmsInfo * GetComParmInfo(const CString & strName) const ;

	/// 
	void	ReleaseParmInfoBase() ; 

	void	ReleaseParmInfoBase( const CString & strParmName ) ; 

	const CMapStringToPtr * GetMapPtr() const;

	BOOL SerializeFrom(const CPmArchiveBase & archive);
	BOOL SerializeTo(CPmArchiveBase & archive) const;

protected:

	CMapStringToPtr m_ComParmNameMap;

	/// 
	/// 钢筋名称排序,钢筋计算需要用到.
	/// 
	PmStrList	m_listSortParmName ;

};

typedef CArray<CComParmsInfoMap::CCalComParmsInfo*,CComParmsInfoMap::CCalComParmsInfo*&>	CCalComParmsInfoArr;

struct PMLogicDataOprAPI CVariables 
{
	const static CString  A ;
	const static CString  L ;
	const static CString  W ;
	const static CString  D ;
	const static CString  H ;
	const static CString  S ;
	const static CString  Lq ;
	const static CString  ZTMLen;
	const static CString  Ln ;
};

namespace Graphic_ComType
{
	//构件大类
	enum eGjType_T
	{
		eError = -1,//错误
		eLiang = 1,//梁	
		ePole = 2,	//柱
		eWall = 3,//墙
		eBan = 4,//板
		eJc = 5,//基础
		eMcd = 6, //门窗洞
		eZs = 7,//装饰
		eLsgj = 8,//零星构件
		eOther = 9,//其他构件
	};

	enum ComType
	{
		Error = 0, // 错误码

		/***** 梁系列 *****/
		LIANG = 100, 
		LIANG_KL = 101,		//框架梁
		LIANG_CL = 102,		//次梁
		LIANG_DL = 103,		//独立梁
		LIANG_JCL = 104,	//基础梁
		LIANG_QL = 105,		//圈梁
		LIANG_GL = 106,		//过梁
		LIANG_JCLL = 107,	//基础连梁
		LIANG_CTL = 108,	//承台梁
		LIANG_DJ = 109,		//吊筋
		LIANG_ZZJ = 110,	//转角筋
		LIANG_LL  = 111,	//连梁
		LIANG_AL  = 112,	//暗梁
		LIANG_DKL  = 113,	//地框梁
		LIANG_JCLJY = 114,	//基础梁加腋
		LIANG_BLH = 116,	//扁梁核心区

		/***** 柱系列 *****/
		ZHU = 200,
		ZHU_KZ = 201,		//砼柱
		ZHU_GZ = 202,		//构造柱
		ZHU_AZ = 203,		//暗柱
		ZHU_ZZ = 204,		//砖柱
		ZHU_ZM = 205 ,		//柱帽

		/***** 墙系列 *****/
		QIANG = 300,
		QIANG_0Q  = 301,	//0墙
		QIANG_TWQ = 302,	//砼外墙
		QIANG_TNQ = 303,	//砼内墙
		QIANG_ZWQ = 304,	//砖外墙
		QIANG_ZNQ = 305,	//砖内墙
		QIANG_TCQ = 306,	//填充墙
		QIANG_JBQ = 307,	//间壁墙
		QIANG_DTQ = 308,	//电梯井墙
		QIANG_MQ  = 309,	//幕墙
		QIANG_QTJJ= 312,	//砌体加筋
		QIANG_JLQ = 313,	//剪力墙
		QIANG_QTQ = 314,	//砌体墙

		QIANG_WQWBX = 315 , /// 外墙外边线
		QIANG_MP	= 316 , /// 满铺
		QIANG_RFQ	= 317, //人防墙
		QIANG_JIAYE_QQ = 318,	//墙墙加腋
		QIANG_JIAYE_QB = 319,	//墙板加腋
		QIANG_QTLJ = 320,		//砌体连接

		/***** 板系列 *****/
		BAN = 400,
		BAN_XB = 401,		//现浇板
		BAN_YB = 402,		//预制板
		BAN_LTB = 403,		//楼梯
		BAN_GB = 404,		//拱形板
		BAN_QB = 405,		//球形板
		BAN_LXB = 406,		//螺旋板
		BAN_BDONG = 407,	//板洞
		BAN_TB = 408,		//梯板
		BAN_WJX = 409,		//屋脊线
		BAN_JIAYE = 410,	//梁板加腋
		BAN_DONG = 1002,	//板洞

		/***** 基础系列 *****/
		JICHU = 500,
		JICHU_TTJ = 501,	//砼条基
		JICHU_ZSJ = 502,	//砖石条基
		JICHU_DLJ = 503,	//独立基础
		JICHU_CT = 504,		//承台
		JICHU_RGZJ = 505,	//人工挖孔灌注桩
		JICHU_QTZJ = 506,	//其他桩
		JICHU_MTJ = 507,	//满堂基础
		JICHU_JSJ = 508,	//集水井
		JICHU_BZCT = 509,	//标准承台
		JICHU_JK = 510,		//井坑
		JICHU_STJSJ = 511,	//实体集水井
		JICHU_ZD = 512,		//柱墩
		JICHU_GZZJ = 513,	//灌注桩

		/***** 门窗系列 *****/	
		MC = 600,
		MC_M = 601,			//门
		MC_C = 602,			//窗
		MC_D = 603,			//墙洞
		MC_PC = 604,		//飘窗
		MC_ZPC = 605,		//转角飘窗
		MC_LHC = 606,		//老虎窗
		MC_BK = 607,		//壁龛
		MC_CTB = 608,		//窗台
		MC_MD = 609 ,		// 门剁
		MC_MCT = 610 ,		// 门窗套
		MC_PCD = 1004,		//飘窗洞
		MC_ZJPCD = 1005,	//转角飘窗洞

		/***** 装饰系列 *****/
		ZS = 700,
		ZS_FJS = 701,		//房间
		ZS_DMS = 702,		//楼地面
		ZS_TJS = 703,		//踢脚线
		ZS_NQS = 704,		//内墙面
		ZS_WQS = 705,		//外墙面
		ZS_QQS = 706,		//墙裙
		ZS_ZMS = 707,		//柱面
		ZS_ZQQS = 708,		//柱墙裙
		ZS_ZTJS = 709,		//柱踢脚
		ZS_TPS = 710,		//天棚
		ZS_WMS = 711,		//屋面
		ZS_WMS_LKX = 1003,  //屋面轮宽阔线
		ZS_BWS = 712,		//保温层
		ZS_DLZS = 713 ,		// 单梁装饰
		ZS_DDS = 714,		//吊顶

		/***** 零星系列 *****/
		LX = 800,
		LX_YT = 801,	    //阳台
		LX_YP = 802,		//雨篷
		LX_LG = 803,		//栏杆
		LX_SSLX = 804,		//散水
		LX_YG = 805,		//檐沟
		LX_TJ = 806,		//台阶
		LX_PD = 807,		//坡道
		LX_PSG = 808,		//排水沟
		LX_HJD = 809,		//后浇带
		LX_TJING = 810,		//天井
		LX_JD = 811,		//外墙节点
		LX_AREA = 812,		//建筑面积
		LX_YaDing = 813 ,	//压顶
		LX_LanBan = 814 ,		//栏板
		LX_YTYPZS = 815 ,   //阳台雨棚折实
		LX_STTJ	= 816,		//实体台阶
		LX_STPD = 817,		//实体坡道
		LX_SGD = 818,      //施工段
		LX_FK = 819,		//反坎构件

		/***** 其它系列 *****/
		QT = 900,
		QT_DST = 901,		//点构件
		QT_XST = 902,		//线构件
		QT_MST = 903,		//面构件
		QT_TST = 904,		//体构件

		OTHER = 1000,			//其他大类
		OTHER_ZW = 1001,		//轴网
		OTHER_GCSZ = 1002,		//工程设置
		OTHER_BB = 1003,		//报表
		OTHER_CADZH = 1004,		//CAD转化
		OTHER_SCLX = 1005,		//收藏类型---用于导航栏的收藏类型节点
		OTHER_LIANGZZ = 1015 ,	//支座的comtype，只是在钢筋计算的时候使用
		/***** 板筋系列 *****/
		BANJIN = 1100,
		BANJIN_DJ = 1101,		//底筋
		BANJIN_MJ = 1102,		//面筋
		BANJIN_ZBSLJ = 1103,	//跨板负筋
		BANJIN_SCSXGJ = 1104,	//双层双向钢筋
		BANJIN_ZZFJ = 1105,		//支座负筋
		BANJIN_WDJ = 1106,		//温度筋
		BANJIN_LCBD = 1107,		//楼层板带:跨中板带和柱上板带
		BANJIN_CJ = 1108,		//撑筋
		BANJIN_BJQY = 1109,		//板筋区域
		BANJIN_FSJ = 1110 ,		//放射筋

		/***** 筏筋系列 *****/
		FABANJIN = 1200,
		FABANJIN_FDJ = 1201,	//筏板底筋
		FABANJIN_FMJ = 1202,	//筏板面筋
		FABANJIN_FZBSLJ = 1203, //跨筏板筋
		FABANJIN_ZJCJ = 1204,	//中层筋
		FABANJIN_ZZGJ = 1205,	//筏板负筋
		FABANJIN_FBJ = 1206,	//U形封边筋
		FABANJIN_JCBD = 1207,	//基础板带: 跨中板带和柱上板带
		FABANJIN_CJ = 1208,		//撑筋
		FABANJIN_BJQY = 1209,	//筏板筋区域
		FABANJIN_FSJ = 1210	,	//筏板放射筋

		//
		TUFAN = 1300 ,			// 土方
		TUFAN_DKW = 1301 ,		// 大开挖
		TUFAN_DXSFW = 1302 ,	// 地下室范围
		TUFAN_FXHTT = 1303,		// 房心回填土
		
		//空心楼盖
		KXLG = 1400,			//空心楼盖
		KXLG_BAN = 1401,		//空心楼盖板
		KXLG_ZM = 1402,			//空心楼盖柱帽
		KXLG_ZLL = 1403,		//主肋梁
		KXLG_CLL = 1404,		//次肋梁
		KXLG_XM = 1405,			//芯模
		KXLG_KD = 1406,			//空挡
		KXLG_SLJ = 1407,		//空心楼盖受力筋

		//装配式
		ZPS = 1500,
		ZPS_YZZ = 1501,			//预制柱
		ZPS_YZWQ = 1502,		//预制外墙
		ZPS_YZNQ = 1503,		//预制内墙
		ZPS_DHL = 1504,			//叠合梁
		ZPS_HJL = 1505,			//后浇梁
		ZPS_DHB = 1506,			//叠合板
		ZPS_HJB = 1507,			//后浇板
		ZPS_JF = 1508,			//板缝
		ZPS_DHBMJ = 1509,		//叠合板面筋
		ZPS_KDHBJ = 1510,		//跨叠合板筋
		ZPS_DHBFJ = 1511,		//叠合板负筋

		BIMSAFE_3D_MB = 5110,	//面板
		BIMSAFE_3D_XL = 5111,	//小梁
		BIMSAFE_3D_ZL = 5112,	//主梁
		BIMSAFE_3D_KOUJIAN = 5113,	//扣件

		BIMSAFT_PQBZ = 5201,	//剖切面实体
		BIMSAFT_KXPQ = 5202,	//框选剖切实体
		BIMSAFT_BDBH = 5203,   //板洞编号图
		BIMSAFT_QDBH = 5204,   //墙洞编号图
		BIMSAFT_BDBG = 5205,   //板顶标高
	};
	
	/**
	* @brief   基础构件comtype的判断
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/1/2020]
	*/
	PMLogicDataOprAPI BOOL IsJichuComtype(int comtype);

	/**
	* @brief   获取大类comtype
	*
	*			我们把基础梁，基础连梁，地框梁，基础梁加腋归为基础
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/1/2020]
	*/
	PMLogicDataOprAPI int GetComtypeDL(int comtype);
};

//实物量额外参数
namespace SWL_EV
{
	enum SWL_EV_Name{
		JMCC = 1,						//截面尺寸(mm*mm)
		ZC=2,							//周长(m)
		GD=3,							//高度(m)
		JMMJ=4,						//截面面积(m2)
		GJMC=5,						//构件名称
		ISBJM=6,						//是否变截面
		ZSGX=7,							//装饰绑定关系, 房间comId字符串形式
		QMJCCL=8,							//墙面基础材料，字符串形式
		SWLBB = 9					//实物量报表
	};
}

namespace DrawBar_UI
{

}

namespace GJ_ComType
{
	// Note: Comtype的命名规则：分两部分，“_”前为对应枚举形简写,
	//		 后为通过对应的构件的中文名称拼音的第一个字母或数字来命名的;  
	// Date: [5/6/2008]
	//构件：梁
	enum eLIANG
	{	
		eLiang = 100, 
		eLKJ    = 110,
		eL_lckjl  = 111,					// 楼层框架梁 
		eL_wmkjl  = 112,					// 屋面框架梁
		eL_kzl    = 113,					// 框支梁	
		eL_kjlzl  = 114,					// 框架梁折梁	
		eL_hxkjl  = 115,					// 弧形框架梁	
		eL_gxkjl  = 116,					// 拱形框架梁				
		eLFKJ   = 120,
		eL_cl	  = 121,					// 次梁
		eL_hxfkjl = 122,					// 弧形非框架梁
		eL_gxfkjl = 123,					// 拱形非框架梁
		eL_fkjlzl = 124,					// 非框架梁折梁
		eL_jzl    = 125,					// 井字梁
		eLJC    = 130,
		eL_jczl   = 131,					// 基础主梁	
		eL_jccl	  = 132,					// 基础次梁
		eL_jcjyl  = 133,					// 基础梁加腋
		eL_jcdkl  = 134,					// 地框梁
		eLOTH   = 140,
		eL_ql	  = 141,					// 圈梁
		eL_gl	  = 142,					// 过梁
		eL_ctl	  = 143,					// 承台梁
		eL_jcll   = 144,					// 基础连梁
		eL_dj	  = 145,					//吊筋
		eL_zzj	  = 146,					//转角筋
		eL_ll_g	  = 147,					//连梁（图形法）
		eL_al_g	  = 148,					//暗梁（图形法）

		eL_ql_KJJG = 151,					//框架结构
		eL_ql_ZHJG = 152,					//砖混结构

		eL_KBLIANG = 155,					//框扁梁
		eL_TZZHLIANG = 156,					//托柱转换梁
		eL_KJLLIANG = 157,					//框架连梁
		eL_ZLL_KJLIANG	= 521, //楼层主肋梁//pmparms里面的区分参数
		eL_ZLL_WMLIANG	= 522, //屋面主肋梁
		eL_CLL_CILIANG	= 160, //次肋梁
		eL_DHL_kjl	= 161, //叠合框架梁
		eL_DHL_fkjl	= 162, //叠合非框架梁

		eL_HJL_lckjl = 661,					//后浇楼层框架梁
		eL_HJL_wmkjl = 662,					//后浇屋面框架梁
		eL_HJL_kzl = 663,					//后浇框支梁
		eL_HJL_kjbl = 664,					//后浇框架扁梁
		eL_HJL_tzzhl = 665,					//后浇托柱转换梁
		eL_HJL_fkjl = 666,					//后浇非框架梁
		eL_HJL_jzl = 667,					//后浇井字梁
		eL_HJL_ptll = 668,					//后浇普通连梁
		eL_HJL_kjll = 669,					//后浇框架连梁

		/*自定义构件*/
		eL_zdy	  = 199						// 自定义
	};//eLIANG
	//构件：柱
	enum eZHU
	{	
		eZhu = 200,
		eZKJ  = 210,
		eZ_kjz   = 211,						// 框架柱
		eZ_lsz   = 212,						// 梁上柱
		eZ_qsz   = 213,						// 墙上柱			
		eZ_kzz   = 214,						// 框支柱
		eZ_xz    = 215,						// 芯柱				
		eZGZ  = 220,
		eZ_gzz   = 221,						// 构造柱

		//modify by zhengwei 20111230
		eZ_kjjg  = 222,                     //框架结构
		eZ_zhjg  = 223,                     //砖混结构

		eZ_qsgzz = 222,						// 墙上构造柱
		eZ_lsgzz = 223,						// 梁上构造柱
		eZA   = 230,
		eZ_az	 = 231,						// 暗柱	
		eZOTH = 240,
		eZ_ntz	 = 241,						// 牛腿
		eZ_zm	 = 242,						//柱帽
		/*自定义构件*/
		eZ_zdy	 = 299						// 自定义
	};//eZHU
	//构件：墙
	enum eJLQIANG
	{
		eJLQiang = 300,
		eQJL      = 310,
		eQ_1cjlq	= 311,					// 剪力墙（一次搭接）
		eQ_2cjlq	= 312,					// 剪力墙（二次搭接）
		eQ_Gjlq		= 313,					// 图形法剪力墙
		eQOTH     = 320,
		eQ_az		= 321,					// 暗柱	
		eQ_ll		= 322,					// 连梁
		eQ_qtjj		= 323,					// 砌体加筋
		eQ_qtq		= 324,					//砌体墙
		eQ_jfq		= 325,					//人防墙
		/*自定义构件*/
		eQ_zdy	 = 399						// 自定义
	};//eJLQIANG
	//构件：板
	enum eBAN
	{	
		eBan = 400,
		eB_TiBan = 408,						//梯板
		eBXJ  = 410,
		eB_ptb   = 411,						// 普通板
		eB_scsxb = 412,						// 双层双向板
		eB_bjlb  = 413,						// 板筋列表

		eB_zsbd = 414,						//柱上板带
		eB_kzbd = 415,						//跨中板带
		eB_jcbd_zxbd = 416,						//基础板带: 柱下板带
		eB_jcbd_kzbd = 417,						//基础板带: 跨中板带
		eB_cj_cj = 418,						//筏板撑脚：撑筋
		eB_cj_lj = 419,						//筏板撑脚：拉筋
		eB_bdong = 421,						//板洞
		eB_fdj_lb = 422,						//筏板底筋：梁板式筏基
		eB_fdj_pb = 423,						//筏板底筋：平板式筏基
		eB_fmj_lb = 424,						//筏板面筋：梁板式筏基
		eB_fmj_pb = 425,						//筏板面筋：平板式筏基
		eB_bjcj_cj = 426,						//板筋撑筋：撑筋
		eB_bjcj_lj = 427,						//板筋撑筋：拉筋

		eB_bj_fsj = 428,						//板筋：放射筋
		eB_fbj_fsj = 429,						//筏板筋：放射筋
		/*自定义构件*/
		eB_zdy   = 499						// 自定义	
	};//eBAN
	//构件：基础
	enum eJC
	{
		eJc	 = 500,
		eJCTX	= 510,
		eJC_ylstxjc	 = 511,					// 有梁式条形基础
		eJC_wlstxjc  = 512,					// 无梁式条形基础

		eJC_sl_ttj	 = 513,					//图形法砼条基

		eJCDL   = 520,
		eJC_xjzxdljc = 521,					// 现浇柱下独立基础		
		eJC_bxjc	 = 522,					// 杯形基础
		eJC_szptdljc = 523,					// 双柱普通独立基础

		eJC_G_dljc	 = 524,					//图形法独立基础
		eJCCT	= 530,
		eJC_jxct	 = 531,					// 矩形承台
		eJC_3zct	 = 532,					// 三桩承台
		eJC_5zct	 = 533,					// 五桩承台
		eJC_6bct	 = 534,					// 六边承台
		eJC_8bct	 = 535,					// 八边承台
		eJC_bzct	 = 536,					// 标准承台

		eJC_G_ct	 = 537,					//图形法承台
		eJC_G_bzct	 = 538,					//图形法标准承台

		eJCXJZ	= 540,
		eJC_gzz		 = 541,					// 灌注桩
		eJC_rgwkgzz  = 542,					// 人工挖孔灌注桩
		eJCYZZ	= 550,
		eJC_zz		 = 551,					// 整桩
		eJC_jz		 = 552,					// 接桩
		eJCFX	= 560,
		eJC_lbs		 = 561,					// 梁板式
		eJC_zxbds	 = 562,					// 柱下板带式
		eJC_fjgjlb	 = 563,					// 筏基钢筋表
		eJCMT	= 570,	
		eJC_mtjc	 = 571,					// 满堂基础
		eJCOTH	= 580,
		eJC_jsj		 = 581,					// 集水井
		eJC_dbhjd	 = 582,					// 底板后浇带
		eJC_dtjjc	 = 583,					// 电梯井基础	

		eJC_S_ZhuDun = 51201,				//上柱墩
		eJC_X_ZhuDun = 51202,					//下柱墩
		/*自定义构件*/
		eJC_zdy		 = 599					// 自定义
	};//eJC
	//构件：楼梯
	enum eLT
	{
		eLt = 600,
		eLTXJBS = 610,	
		eLT_lt		= 611,					// 梯梁
		eLT_ltpt	= 612,					// 楼梯平台
		eLT_AT_ET	= 613,					// AT-ET型楼梯(单跑)
		eLT_FT_LT	= 614,					// FT-LT型楼梯(双跑)
		eLTPT	= 620,
		eLT_ptlt	= 621,					// 普通楼梯
		/*自定义构件*/
		eLT_zdy		= 699					// 自定义
	};//eLT
	//构件：零星
	enum eLX
	{
		eLx  = 700,
		eLxgj  = 710,
		eLX_yt	  = 711,					// 阳台
		eLX_yp    = 712,					// 雨篷
		eLX_lb    = 713,					// 栏板
		eLX_yd    = 714,					// 压顶	
		eLX_yg    = 715,					// 檐沟
		eLX_wqxj  = 716,					// 外墙线脚
		eLX_neq	  = 717,					// 女儿墙
		eLX_qzljj = 718,					// 墙柱拉结筋
		eLX_pc    = 719,					// 飘窗
		eLX_hjd	  = 720,					// 后浇带
		eLX_jd	  = 721,					//外墙节点
		eLX_psg	  = 722,					//排水沟
		eLX_yading= 723,					//压顶
		eLX_tiaoyan=724,					//挑檐
		eLX_fsfk = 725,						//防水反坎
		/*自定义构件*/
		eLX_zdy	  = 799						// 自定义
	};//eLXGJ
	enum eMCD
	{
		eMCD = 800,
		eMCD_dkjj = 811,					//洞口加筋
		eMCD_m = 812,						//门
		eMCD_c = 813,						//窗
		eMCD_dong = 814,					//墙洞
		eMCD_ct = 815,                      //窗台
		eMCD_PC = 816,                      //飘窗
		eMCD_zjPC = 817,                    //转角飘窗
		eMCD_Md = 818,						//门垛
	};
	enum eOther//其他
	{
		eOther = 900,
		eOther_line = 901						//线构件
	};

	/*enum eKXLG
	{
	eKXLG = 1000,
	eKXLG  
	};*/
}


namespace pmdataservice
{
	/// 版本号，后续还需要扩展
	enum
	{
		eVersion_Err = -1 
		, eVersion_1 = 1 
		, eVersion_2 = 2 
		, eVersion_3 = 3 
		, eVersion_4 = 4 
		, eVersion_5 = 5 
		, eVersion_6 = 6
		, eVersion_7 = 7 
		, eVersion_8 = 8
		, eVersion_9 = 9 
		, eVersion_10 = 10
	} ;
}

