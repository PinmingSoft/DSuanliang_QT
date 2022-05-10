// GjParam.h: interface for the CGjParam class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GJPARAM_H__2465A05E_4A40_4797_9B4C_0472192A87C8__INCLUDED_)
#define AFX_GJPARAM_H__2465A05E_4A40_4797_9B4C_0472192A87C8__INCLUDED_
// ***************************************************************
//  GjParam   version:  1.0   ? date: 11/21/2007
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2007 - All Rights Reserved
//  作者:clz
// ***************************************************************
// 文件说明:该文件包含所有构件数据库参数属性名
//请一致的使用这里的具名常量,而不是直接写常量字符串
// ***************************************************************
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// #ifdef PRJ_PMGJOPBASE
// 	#define PMDATASERVICEAPI __declspec(dllexport)
// #else
// 	#define PMDATASERVICEAPI __declspec(dllimport)
// 	#ifdef PM_FOR_R15
// 		#pragma comment(lib,"PmGjOpBase15.lib")
// 	#else
// 		#pragma comment(lib,"PmGjOpBase16.lib")
// 	#endif
// #endif

//构件关系
struct PmSLGJDataServiceAPI GJRelation
{
	BOOL bDD;//打断
	BOOL bChongDie;//重叠是否违例 TRUE：违例 FALSE：正常
	CString strDJInfo;//扣减
	CString strJSInfo;//寄生
};
struct PmSLGJDataServiceAPI GjParam  
{

	static const CString strLength;//构件长
	static const CString strWidth;//构件宽
	static const CString strHigh;//构件高
//梁参数
struct PmSLGJDataServiceAPI LiangParam 
{
	static const CString strTqd;//砼强度
	static const CString strDbg;//顶标高(mm)
	static const CString strJCLDbg;//基础梁顶标高（mm）
	static const CString strGzcd;//单边搁置长度
	static const CString strJDBG;//基础梁底标高
	static const CString strJCTQD;	//砼强度 ---基础梁
	static const CString strDCTQD;//垫层砼强度 --- 基础梁
	
	//钢筋
	static const CString strcomponenttype;//梁类型
	static const CString strjm;//截面（Bb*Hb）
	static const CString strkj;//箍筋
	static const CString strstcj;//上通长筋
	static const CString strxbtcj;//下通长筋
	static const CString strcmyj;//腰筋
	static const CString strcmlj;//侧面拉筋
	static const CString strqtgj;//其它箍筋

	static const CString strljpz;//拉筋配置
	static const CString strxtl;//悬挑梁类型选择
	static const CString strzljt;//折梁折角处是否设置角托
	
	static const CString strjdwdj; //下部筋在节点外搭接
	static const CString strldkjxs;//以梁为支座一侧的箍筋是否加密
	static const CString strdtlx; //梁纵筋在端支座处是否采用机械锚固
	static const CString strjmsz ;//梁端为柱、剪力墙时，箍筋是否加密

	static const CString strDJ;//吊筋
};
	
//柱
struct PmSLGJDataServiceAPI ZhuParam 
{
	static const CString strDbg;//顶标高(mm)
	static const CString strDibg;//底标高(mm)	
	static const CString strTqd;//砼强度
	static const CString strMaterial;//材质
	static const CString strSjdj;//砂浆等级
	static const CString strZdj;//砖等级
	
	static const CString strcomponenttype;//柱类型
	static const CString strjm;//截面尺寸（b*h或D）
	static const CString strqbzj;//全部纵筋
	static const CString strjj;//角筋
	static const CString strbzbj;//水平（B）边一侧中部筋
	static const CString strhzbj;//垂直（H）边一侧中部筋
	static const CString strkj;//箍筋
	static const CString strkjzh;//箍筋肢数
	static const CString strqtgj;//其它箍筋
	static const CString strjdygj; //节点域箍筋

	static const CString strzdjqj;//柱底加强吊筋是否存在
	static const CString strdtlx;//顶层柱纵筋端头是否采用机械锚固
};

// 灌注桩
struct PmSLGJDataServiceAPI GZHParam 
{
	static const CString strDbg;//顶标高(mm)
	static const CString strDibg;//底标高(mm)	
	static const CString strTqd;//砼强度
	static const CString strMaterial;//材质
	static const CString strSjdj;//砂浆等级
	static const CString strZdj;//砖等级

	static const CString strcomponenttype;//柱类型
	//static const CString strjm;//截面尺寸（b*h或D）
	static const CString strd;//桩径
	static const CString strkccd1;//扩底端长度1
	static const CString strkccd2;//扩底端长度2
	static const CString strl;//桩长
	static const CString strhc1;//扩底端高度
	static const CString strhc2;//扩底端高度
	static const CString strhb;//扩底端高度锅底行矢高
	static const CString strtczj;//通长主筋
	static const CString strjqzj; //加强主筋

	static const CString strlxgj;//螺旋箍筋
	static const CString strjqgj;//加强箍筋
};



//墙体参数
struct PmSLGJDataServiceAPI WallParam 
{
	static const CString strQh; //墙厚
	static const CString strDbg;//顶标高(mm)
	static const CString strDibg;//底标高(mm)
	static const CString strMaterial;//材质
	static const CString strTqd;//砼强度
	static const CString strSjdj;//砂浆等级
	static const CString strZdj;//砖等级
	static const CString strCJGFJS;//撑筋是否自动布置
	static const CString strSjyrfqkj;  //剪力墙遇人防墙是否扣相交部位竖向钢筋
};


//板
struct PmSLGJDataServiceAPI Ban 
{
	static const CString strBh;//板厚(mm)
	static const CString strDbg;//顶标高(mm)
	static const CString strTqd;//砼强度
	static const CString strTjmc;//图集名称
};

//板筋
struct PmSLGJDataServiceAPI BanJin
{
	static const CString strBh;//板厚(mm)
	static const CString strDbg;//顶标高(mm)
	static const CString strTqd;//砼强度
	static const CString strBDGJ;//板带箍筋

	static const CString strGJMS;//钢筋类型
	static const CString strfbjms;//分布钢筋
	static const CString strzwz;//左标注(mm)
	static const CString strywz;//右标注(mm)
	static const CString strGJMSXD;//X向底筋
	static const CString strGJMSYD;//Y向底筋
	static const CString strGJMSXM;//X向面筋
	static const CString strGJMSYM;//Y向面筋
	
	static const CString strBZWZ;//跨板负筋在支座内的标注位置
	static const CString strBZWZ_BX;//跨板负筋在支座内的标注位置 标注至边线
	static const CString strBZWZ_ZX;//跨板负筋在支座内的标注位置 标注至中心
	static const CString strBZWZ_WB;//跨板负筋在支座内的标注位置 标注至外边
	static const CString strZBZWZ;//中间支座负筋在支座内的标注位置
	static const CString strZBZWZ_BX;//中间支座负筋在支座内的标注位置 标注至边线
	static const CString strZBZWZ_ZX;//中间支座负筋在支座内的标注位置 标注至中心
	static const CString strzzfjcd;//支座负筋下分布筋长度计算
	static const CString strzzfjcd_fjdj;//支座负筋下分布筋长度计算 与支座负筋搭接
	static const CString strzzfjcd_fjcd;//支座负筋下分布筋长度计算 按支座负筋的长度布置计算
	
	static const CString strBDK;//板带宽(mm)
	static const CString strBDH;//板带厚(mm)
	static const CString strSBPJ;//上部受力筋
	static const CString strXBPJ;//下部受力筋
};

struct PmSLGJDataServiceAPI BanDong
{
	static const CString strBdjqj ;///板洞加强筋
};

////////////////////////////////////////////
/// 郑琪崇 [2014年5月14日]
/// 说明:土方大开挖
///  
struct PmSLGJDataServiceAPI Dkw
{
	static const CString strDbg;//顶标高(mm)
	static const CString strDibg;//底标高(mm)
	static const CString strGzmk;//工作面宽(mm)
	static const CString strFpxs;//放坡系数(mm)

};

////////////////////////////////////////////
/// 郑琪崇 [2014年5月20日]
/// 说明:土方 地下室范围
///  
struct PmSLGJDataServiceAPI Dxsfw
{
	static const CString strDbg;//顶标高(mm)
	static const CString strDibg;//底标高(mm)
};

//基础
struct PmSLGJDataServiceAPI Jc 
{
	static const CString strJdbg;//基础底绝对标高
	static const CString strJctqd;//基础砼强度
	static const CString strSjdj;//砂浆等级
	static const CString strZdj;//砖等级
	static const CString strDctqd;//垫层砼强度

//蔡绿洲修改[1/7/2008 10:28]//目的：
	static const CString strHd;//承台/满堂基础 厚度(mm)(废弃该字段，使用下面两个)
	static const CString strCTHd;//承台厚度 
	static const CString strMTJHd;//满堂基础 厚度 
//结束修改	[1/7/2008 10:28]

	static const CString strDingBg;//顶标高
};

//门窗洞
struct PmSLGJDataServiceAPI Mcd 
{
	static const CString strKh;//框厚(mm)
	static const CString strDibg;//底标高(mm)
	static const CString strTqd;//砼强度
	static const CString strBksd;//壁龛深度(mm)
	static const CString strLdgd;//离地高度(mm)

	///注释：杨兴耀 [2009年8月19日]                                  
	///钢筋中 要用到的 
	static const CString strDkjj ;
};

//装饰
struct PmSLGJDataServiceAPI Zs 
{
	static const CString strLdm;//楼地面
	static const CString strTjx;//踢脚线
	static const CString strNqm;//内墙面
	//添加 蔡绿洲 [21/5/2008]//作用：
	static const CString strTnqm;//内墙面(砼)
	static const CString strZnqm;//内墙面(砖)
	static const CString strQnqm;//内墙面(其它
	//添加 结束
	static const CString strZm;//柱面装饰
	static const CString strTp;//天棚
	static const CString strQq;//墙裙
	static const CString strDibg;//底标高(mm)
	static const CString strJdbg;//顶标高(mm)
	static const CString strScdibg;//首层底标高(mm)
	static const CString strDyfj;//对应房间
	static const CString strHigh;//高度(mm)/墙裙高(mm)
	static const CString strHd;//厚度(mm)
};


//零星构件
struct  PmSLGJDataServiceAPI Lxgj
{
	static const CString strCtbhd;//出挑板厚度(mm)
	static const CString strLbhd;//栏板厚度(mm)
	static const CString strLbgd;//栏板高度(mm)
	static const CString strDibg;//底标高(mm)
	static const CString strTqd;//砼强度
	static const CString strMaterial;//材质
	static const CString strLggd;//栏杆高度(mm)
	static const CString strJj;//间距(mm)
	static const CString strDctqd;//垫层砼强度
	static const CString strSjdj;//砂浆等级
	static const CString strZdj;//砖等级
	static const CString strJdbg;//顶标高(mm)
	static const CString strDbg; //顶标高(mm)//add by zll 2008.12.22 外墙节点
	
	static const CString strSx_wzcd;//栏板竖向钢筋顶部弯折长度
	static const CString strX_wzcd;//外墙节点端部弯折长度
};

//线构件
struct PmSLGJDataServiceAPI Qt
{
	static const CString strX_wzcd;//线构件端部弯折长度
};

//预制构件
struct PmSLGJDataServiceAPI Yzgj
{
	static const CString strYztqd;//预制砼强度
};

};//GjParam end

const int IN_VALIDE_COM_TYPE = -1;		
const int IN_VALID_COM_ID = -1;//无效comid


#endif // !defined(AFX_GJPARAM_H__2465A05E_4A40_4797_9B4C_0472192A87C8__INCLUDED_)
