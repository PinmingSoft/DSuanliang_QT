
#pragma  once 

/**
 * @brief 一些公共表结构的定义
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-13]
 * @note  
 */

//圈梁平法表格
struct PmSLGJDataServiceAPI CQL_GraphicDataSet
{
	static const CString id;//
	static const CString ZZK;//左支座宽
	static const CString YZK;//右支座宽
	static const CString Ln;//净跨长
	static const CString zdtype;//左端端部类型
	static const CString ydtype;//右端端部类型

//	static const CString SPAng;//水平角度
	static const CString ZDInfo;//折点信息

	static NDataModelDataSet * GetDataSet();
};

struct PmSLGJDataServiceAPI CLayerColorShowDataSet
{
	static const CString floorid ;
	static const CString comtype ; 
	static const CString layer ;
	static const CString comtypename ; 
	static const CString color ; 
	static const CString showcolor ; 
	static const CString iscolorchanged ; 
	static const CString isshowcolorchanged ; 
	static const CString colorshow ; 

	static NDataModelDataSet * GetDataSet() ; 
};

struct PmSLGJDataServiceAPI CJTParmDataSet
{
	static const CString parmname;
	static const int	parmname_Index;

	static const CString parmvalue;
	static const int	parmvalue_Index;

	static const CString parmdes ;
	static const int	parmdes_Index ;

	static CPM_TranStringDataSet * GetDataSet();

	/// 添加字段 : parmdes
	static CPM_TranStringDataSet * GetDataSetV2() ; 
};


struct PmSLGJDataServiceAPI CNameValue_Com
{
	static const CString name ; 
	static const CString value ; 

	static NDataModelDataSet * GetDataSet() ;
};



/// 构件显示控制
struct  PmSLGJDataServiceAPI CPMShowControl
{
	static const CString NameListData ;		/// 构件名称的下拉选项
	static const CString GjName ;			/// 构件名称
	static const CString GjMs ;				/// 构件描述
	static const CString GjNameMs ;			/// 构件名称和描述
	static const CString TC ;				/// 填充
	static const CString NTC ;				/// 非填充
	/// 读ini文件时用到
	static const CString GjShowControl ;	/// 构件显示控制
	static const CString banjinname ;		/// 板筋或筏板筋的名称显示
	static const CString goujianname ;		/// 构件通用的名称显示
	static const CString diaojinname ;		/// 吊筋的名称显示 
	static const CString mjtx ;				/// 满基的图形是否填充
	static const CString xjbtx ;			/// 现浇板的图形是否填充
	static const CString ltx;				/// 梁的图形是否填充
	static const CString qiang;				/// 墙的图形是否填充
	static const CString ttjtx;				/// 砼条基的图形是否填充

	static const CString kdtx;				/// 空挡图形是否填充
	static const CString xmtx;				/// 芯模图形是否填充
	static const CString tpldmtx;           /// 天棚楼地面图形是否填充
};

class PmSLGJDataServiceAPI CPMLiangInputDataSet : public CPM_StorageDataSet  
{
public:
	CPMLiangInputDataSet();
	virtual ~CPMLiangInputDataSet();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		const static CString id ;
		const static CString xh ;
		const static CString kh ;
		const static CString bg ;
		const static CString bgEnd ;
		const static CString a1 ;
		const static CString a2 ;
		const static CString a3 ;
		const static CString a4 ;
		const static CString kc ;
		const static CString jmlx ;
		const static CString jmlxnr ;
		const static CString jm ;
		const static CString leftwidth ;
		const static CString stcj ;
		const static CString sbzzzgj ;
		const static CString sbkzgj ;
		const static CString sbyzzgj ;
		const static CString xbtcj ;
		const static CString xbgj ;
		const static CString cmyj ;
		const static CString cmlj ;
		const static CString zkj;			//左箍筋                 
		const static CString zkjjmcd;		//左箍筋加密长度
		const static CString kj;			//箍筋         
		const static CString ykj;			//右箍筋         
		const static CString ykjjmcd;		//右箍筋加密长度
		const static CString cljj ;
		const static CString cljj2;				//识别出的吊筋中的附加箍筋 
		const static CString dj ;
		const static CString dj2;				//识别的吊筋
		const static CString gjjm ;
		const static CString yc;				//腋长
		const static CString yg;				//腋高
		const static CString yk;				//腋宽
		const static CString jygj ;				//加腋钢筋
		const static CString jygj2 ;			//加腋钢筋终点端
		const static CString jytype ;			//加腋类型 （竖向或水平）
		const static CString jyside ;			//加腋在梁的左右（现仅表示水平加腋，竖向加腋上下随梁判断)
		const static CString yc2;			//腋长
		const static CString yg2;
		const static CString yk2;			//腋高
		const static CString jygj3;			//加腋筋
		const static CString jygj4;		//加腋筋跨终点端
		const static CString jytype2;			//加腋类型（水平（0）还是竖向（1））
		const static CString jyside2;			//加腋在梁的左右（现仅表示水平加腋（左0右1），竖向加腋上下随梁判断）
		const static CString jytwoside;
		const static CString qtgj ;				//其他箍筋
		const static CString qtgjcontent ;		//其他箍筋的内容
		const static CString jd ;
		const static CString hc ;
		const static CString zdInfo ;			//折点
		const static CString zzzType;			//左支座类型,0:柱,1:平行墙,2:非平行墙,3:非平行梁,4:承台 6:非平行条基 7：平行条基 8：空支座（有支座点 但是没有支座）
		const static CString yzzType;			//右支座类型,0:柱,1:平行墙,2:非平行墙,3:非平行梁,4:承台 6:非平行条基 7：平行条基 8：空支座（有支座点 但是没有支座）
		const static CString zzzcomid;
		const static CString yzzcomid; 
		const static CString zzctjl;             //基础连梁当端部有柱和承台且端部构造选择节点三（左端）
		const static CString yzctjl;             //基础连梁当端部有柱和承台且端部构造选择节点三（右端）
		const static CString zzzk;               //基础连梁左边支座宽(有梁有柱情况下柱的宽度)
		const static CString yzzk;               //基础连梁右边支座宽(有梁有柱情况下柱的宽度)
		const static CString MaxDia;				//最大直径
		const static CString lfg;				//梁腹高
	};
	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CPMPf_ZhuDataSet : public CPM_StorageDataSet  
{
public:
	CPMPf_ZhuDataSet();
	virtual ~CPMPf_ZhuDataSet();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id ;
		static const CString xh ;
		static const CString cc ;
		static const CString dbg ;
		static const CString cg ;
		static const CString jdg ;
		static const CString tqd ;
		static const CString jmcc ;
		static const CString jj ;
		static const CString bbzbj ;
		static const CString hbzbj ;
		static const CString qbzj ;
		static const CString kj ;
		static const CString kjzh ;
		static const CString kjzhlx ;
		static const CString kjjmq ;
		static const CString bhc ;
		static const CString qtgj ;
		static const CString dibg ;
		static const CString bFillGjxx;
		static const CString bjmcz;
		static const CString bjmjcz;
		static const CString jdygj;
		static const CString cjgj;
		static const CString xbck;
		static const CString sbck;
	};
	virtual int InitFieldStr();
};


struct PmSLGJDataServiceAPI CPM_PfAnZhu
{
	static const CString id ;
	static const CString xh ;
	static const CString cc ;
	static const CString dbg ;
	static const CString cg ;
	static const CString jdg ;
	static const CString tqd ;
	static const CString jmcc ;
	static const CString qbzj ;
	static const CString VectorParms ;
	static const CString JMLX ;
	static const CString bhc ;
	static const CString qtgj ;

};


struct PmSLGJDataServiceAPI CPM_PfFaJi
{
	static const CString nothing1 ;
	static const CString nothing2 ;
	static const CString nothing3 ;
	static const CString wzsm ;
	static const CString dbgz ;
	static const CString dbgzbh ;
	/// [6/8/2009] 杨兴耀
	static const CString dbgzbh2 ;
	static const CString bh ;
	static const CString gjlb ;
	static const CString gjxx ;
	static const CString bzjc ;
	static const CString zzk1 ;
	static const CString zzk2 ;
	static const CString fbfw ;
	static const CString gs ;
	static const CString index ;
	static const CString srcd1;
	static const CString srcd2;
	static const CString gc1;
	static const CString gc2;
	static const CString pd1;
	static const CString pd2;
	static const CString xlbh1;
	static const CString xlbh2;
	static const CString GJMode;//钢筋模式 eLineGJ = 0,eArcGJ = 1,eCircleGJ = 2

};


//备注by zhengwei 20110113 
//当计算柱上板带时，传入的参数bzjc为板带宽。板带净长由fbfw参数传入。
struct PmSLGJDataServiceAPI CPM_PfBan
{
	static const CString nothing1 ;
	static const CString nothing2 ;
	static const CString nothing3 ;
	static const CString gs ;
	static const CString wzsm ;
	static const CString gjlb ;
	static const CString gjxx ;
	static const CString zzlx ;
	static const CString yzlx ;
	static const CString zzk1 ;
	static const CString zzk2 ;
	static const CString bzjc ;
	static const CString bh ;
	static const CString bh1;
	static const CString fbfw ;
	static const CString index ;
	static const CString bh2;
	static const CString GJMode;//钢筋模式 eLineGJ = 0,eArcGJ = 1,eCircleGJ = 2
};
struct  PmSLGJDataServiceAPI CPM_PfTJ
{
	static const CString nothing1 ;
	static const CString nothing2 ;
	static const CString nothing3 ;
	static const CString gs ;
	static const CString tjk ;
	static const CString tjdlcd ;
	static const CString gjlb ;
	static const CString gjxx ;
	static const CString zzlx ;
	static const CString yzlx ;
	static const CString zzk1 ;
	static const CString zzk2 ;
	static const CString Ln ;
	static const CString fbfw ;
	static const CString index ;
};

///QTGJ 
struct PmSLGJDataServiceAPI CPM_QTGJ 
{
	static const CString index ;
	static const CString steel_name ;
	static const CString th ;
	static const CString gj;
	static const CString jt ;
	static const CString JTParms ;
	static const CString JTFormula ;
	static const CString xl ;
};

///TTYMJ 
struct PmSLGJDataServiceAPI CPM_TTYMJ 
{
	static const CString index ;
	static const CString bh ;
	static const CString lb ;
	static const CString gnmc;
	static const CString sl ;
	static const CString zj ;
	static const CString gg ;
	static const CString bz ;
};

struct PmSLGJDataServiceAPI CPM_GraphHJD
{
	static const CString gjlb ;
	static const CString gjxx ;
	static const CString bzjc ; 
	static const CString comtype;
	static const CString hjdk;
	static const CString Hc;
	static const CString Bc;
	static const CString gs;
};


struct PmSLGJDataServiceAPI CPM_GraphJSJ
{
	// 1 井坑x向钢筋         2 井坑y向钢筋       3 井壁水平筋
	// 4 实体集水井x向钢筋   5实体集水井y向钢筋  6斜向钢筋 
	static const CString  gjlb ;      
	static const CString  gjxx ;
	static const CString  Ln ;       //井坑底净长
	static const CString  h1;        //左端高度     当钢筋类型为6时,其值等于于文档中的Ln1
	static const CString  h2;        //右端高度     当钢筋类型为6时,其值等于于文档中的Ln2
	static const CString  pd1;       //左端坡度
	static const CString  pd2;       //右端坡度
	// 	static const CString  jkk;       //井坑宽        
	//  static const CString  jkzk;      //井坑纵向宽度
	static const CString  hd ;       //井坑底板厚
	static const CString  jpk1;      //左井坡宽     当钢筋类型为6时,其值等于于文档中的H
	static const CString  jpk2;      //右井坡宽
	static const CString  gjdd;      //钢筋打断 0 未打断 1 左端打断 2 右端打断
	static const CString  gs;        //根数
};

class PmSLGJDataServiceAPI CPmZhuTable : public NDbDataSet
{
public:
	CPmZhuTable();
	virtual ~CPmZhuTable();

	static const CString INDEX1;	//根据构件名称排序，
	static const CString INDEX2;	//根据标高排序！
	static const CString ZHUNAME;	//柱名称 ，会用于排序！！
	static const CString ComID;		//ComID
	static const CString BBG;		//底标高
	static const CString TBG;		//顶标高
	static const CString FloorID;	//楼层ID
	static const CString FLOORSHOWID; //楼层showid，用于排序
	static const CString LCBH;		//楼层编号
	static const CString JMCC;		//截面尺寸
	static const CString QBZJ;		//全部纵筋
	static const CString JJ;		//角筋
	static const CString BBZBJ;		//B边纵筋
	static const CString HBZBJ;		//H边纵筋
	static const CString KJ;		//箍筋
	static const CString KJZH;		//箍筋组合类型
	static const CString KJZHLX;		//箍筋组合类型
	static const CString QTGJ;		//其他箍筋
	static const CString QTGJ_IM;	//其他箍筋的编号
	static const CString ISJZBZ;	//是否是集中标注行；
	static const CString JDYGJ;    //节点域箍筋

	virtual int InitFieldStr();

};

/******************************************************************** 
功能描述：灌注桩表
参数：
返 回 值：
算法：
注意事项：
作    者：hn
时    间：[31/10/2016]
*********************************************************************/ 
class PmSLGJDataServiceAPI CPmGZHTable : public NDbDataSet
{
public:
	CPmGZHTable();
	virtual ~CPmGZHTable();

	static const CString INDEX1;	//根据构件名称排序，
	static const CString INDEX2;	//根据标高排序！
	static const CString GZHNAME;	//柱名称 ，会用于排序！！
	static const CString ComID;		//ComID
	static const CString BBG;		//底标高
	static const CString TBG;		//顶标高
	static const CString FloorID;	//楼层ID
	static const CString FLOORSHOWID; //楼层showid，用于排序
	static const CString LCBH;		//楼层编号
	static const CString JMCC;		//截面尺寸

	static const CString D;			//桩径
	static const CString L;			//桩长
	static const CString KCCD;		//桩底扩头宽度
	static const CString HC1;		//扩底端高度1
	static const CString HC2;		//扩底端高度2
	static const CString HB;		//扩底端锅底行矢高
	static const CString TCZJ;		//通长主筋
	static const CString JQZJ;		//加强主筋
	static const CString LXGJ;		//螺旋箍筋
	static const CString JQGJ;		//加强箍筋
	static const CString ISJZBZ;	//是否是集中标注行；

	virtual int InitFieldStr();

};




/******************************************************************** 
功能描述：连梁表
参数：
返 回 值：
算法：
注意事项：
作    者：王建业
时    间：[22/9/2009]
*********************************************************************/ 
class PmSLGJDataServiceAPI CPmLianLiangTable : public NDbDataSet
{
public:
	CPmLianLiangTable();
	virtual ~CPmLianLiangTable();

	static const CString INDEX1;	//根据构件名称排序，
	static const CString INDEX2;	//根据标高排序！
	static const CString LIANGNAME;	//柱名称 ，会用于排序！！
	static const CString ComID;		//ComID
	//	static const CString BBG;		//底标高
	static const CString TBG;		//顶标高
	static const CString FloorID;	//楼层ID
	static const CString FLOORSHOWID; //楼层showid，用于排序
	static const CString LCBH;		//楼层编号
	static const CString JMCC;		//截面尺寸
	static const CString SBZJ;		//上部纵筋
	static const CString XBZJ;		//下部纵筋
	static const CString YJ;		//腰筋
	static const CString KJ;		//箍筋
	static const CString ISJZBZ;	//是否是集中标注行；

	virtual int InitFieldStr();

};

///注释：杨兴耀 [2009年11月25日]                                  
///独立基础表
class PmSLGJDataServiceAPI CPmDuLiJiChuTable : public NDbDataSet
{
public:
	CPmDuLiJiChuTable()
	{

	}
	virtual ~CPmDuLiJiChuTable()
	{
	}

	static const CString INDEX1;	//根据构件名称排序，
	static const CString INDEX2;	//根据标高排序！
	static const CString DULIJICHUNAME;	//独基名称 ，会用于排序！！
	static const CString DUJIJMType ;	/// 截面的类型: 锥形/阶梯形
	static const CString ComID;		//ComID
	static const CString BBG;		//独基底标高
	static const CString FloorID;	//楼层ID
	static const CString FLOORSHOWID; //楼层showid，用于排序
	static const CString LCBH;		//楼层编号
	static const CString DJCC ;      ///独基尺寸
	static const CString DJC ;      ///独基长L
	static const CString DJW ;      ///独基宽B 
	static const CString DJH1 ;     ///高度h1
	static const CString DJH2 ;     ///高度h2
	static const CString DJH3;		//高度h3
	static const CString DJH4;		//高度h4
	static const CString JCHJ ;		///基础横筋
	static const CString JCZJ ;		///基础纵筋
	static const CString ISJZBZ;	//是否是集中标注行；

	virtual int InitFieldStr();
};

///注释：杨兴耀 [2009年11月25日]                                  
///墙表
class PmSLGJDataServiceAPI CPmQiangTable : public NDbDataSet
{
public:
	CPmQiangTable()
	{
	}
	virtual ~CPmQiangTable()
	{

	}

	static const CString INDEX1;	//根据构件名称排序，
	static const CString INDEX2;	//根据标高排序！
	static const CString QiangNAME;	//墙名称 ，会用于排序！！
	static const CString ComID;		//ComID
	static const CString ComType ;
	static const CString BGFW ;		/// 标高范围
	static const CString DingBG;		//顶标高
	static const CString DiBG;		//底标高
	static const CString FloorID;	//楼层ID
	static const CString FLOORSHOWID; //楼层showid，用于排序
	static const CString LCBH;		//楼层编号
	static const CString QH	; 		///墙厚
	static const CString SPGJ ;		///水平钢筋 内侧
	static const CString SPGJ1 ;	/// 水平钢筋 外侧
	static const CString SXGJ ;		///竖向钢筋 内侧
	static const CString SXGJ1 ;	///竖向钢筋 外侧
	static const CString LJJ ;		///拉结筋
	static const CString ISJZBZ;	//是否是集中标注行；
	static const CString ps ;		/// 排数
	static const CString MaxDiaSpgj;//水平内外侧最大钢筋直径 QC7440 add by jqf
	virtual int InitFieldStr();
};


class PmSLGJDataServiceAPI CPMGridStyleTable : public CSQLDataSet  
{
public:
	CPMGridStyleTable();
	virtual ~CPMGridStyleTable();
	virtual int InitFieldStr();


	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString order ;
		static const CString comType ;
		static const CString parmName ;
		static const CString parmValue ;
		static const CString ListData ;
		static const CString InputMode ;
		static const CString groupid ;

		static const CString table_name;
	};
};

class PmSLGJDataServiceAPI CPMDrawBarInfoTable : public NDataModelDataSet
{
public:
	CPMDrawBarInfoTable();
	virtual ~CPMDrawBarInfoTable();
	virtual int InitFieldStr();


	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id ;
		static const CString mode ;
		static const CString index ;
		static const CString name ;
		static const CString imageindex ;
		static const CString comtype ;
		static const CString disablecomtype ;
		static const CString command ;
		static const CString owncommand ;
		static const CString checkgj ;
	};
};

