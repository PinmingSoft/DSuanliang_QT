// PmConfig.h: interface for the PmConfig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMCONFIG_H__D8BB66DC_0911_4AEF_A0A0_E05FA6ABEB1B__INCLUDED_)
#define AFX_PMCONFIG_H__D8BB66DC_0911_4AEF_A0A0_E05FA6ABEB1B__INCLUDED_
// ***************************************************************
//  PmConfig   version:  1.0   ? date: 07/15/2008
//  -------------------------------------------------------------
//  
//  -------------------------------------------------------------
//  Copyright (C) 2008 - All Rights Reserved
//  作者:clz
// ***************************************************************
// 文件说明:软件配置管理
// ***************************************************************
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//对应sysdata目录中的PmConfig.ini文件

class PMLogicDataOprAPI PmConfig  :public PmFile::CIniFile
{

PmConfig();
virtual ~PmConfig();

public:
	////////////////////////Entity自定义实体部分
	//段名:
	static CString KN_Entity;				//Entity段

	//关键字
	static CString VN_nNameTextSize;		//自定义实体中名称的文字大小


	////////////////////////墙体部分//////////////////////////////////////////////////
	//预先定义段:keyname
	static CString KN_Wall;//墙体  keyname

	
	//预定义的值名valuename
			static CString VN_bImmediately;//在墙体绘制中是否立即pushback
			static CString VN_dMinLess;//墙体的最小长度
			static CString VN_bAutoExternd;//是否启用自动延长
			static CString VN_bSaveWqwbxInfo;//是否在绘制中启用保留外墙外边线
			static CString VN_bInitZx;//是否启用中线初始化,目前只在轴网变墙中使用
			static CString VN_bOnlyAllowSameBx;//是否只允许选中相同类型的边线
			static CString VN_bOptimizeInZwbx;//是否使用轴网变墙的优化
			static CString VN_nDivisionNumForEllipseForWall;//椭圆的切割断数
			
			//随板调高打断容差,如果距离端点小于dSbtgBreak的话,过滤掉该打断点
			static CString VN_dSbtgBreak;
	////////////////////////////轴//////////////////////////////////////////////

			//段名称
			static CString KN_Axis;			//轴网

			//关键字
			static CString VN_bShowZhowFu;	//是否显示浮动轴符
			static CString VN_dAxisTolMax;	//轴网纠偏的误差，即纠偏前后点距离超过这个值，认为不适合纠偏
	
////////////////////////////梁//////////////////////////////////////////////
	static CString KN_Liang;//梁  模块

	static CString VN_nDivisionNumForEllipseForLiang;//椭圆的切割断数
	
	static CString VN_bSortGJSimple;				 //是否进行构件顺序调整
	
	static CString VN_iJZBZTextSize;				//集中标注字体大小

	static CString VN_iJZBZTextSpan;				//集中标注文字间距

	static CString VN_dJZBZTextDistXRate;			//集中标注离梁端部的距离与梁跨长度比

	static CString VN_iJZBZTextDistY;				//集中标注离梁的距离

	static CString VN_iJZBZTextClr;					//集中标注字体颜色

	static CString VN_iYWBZTextSize;				//原位标注字体大小
	
	static CString VN_iYWBZTextSpan;				//原位标注文字间距

	static CString VN_iYWBZTextDist;				//原位标注离梁的距离

	static CString VN_iYWBZTextClr;					//原位标注字体颜色
	
	static CString VN_iYWBZTOZZPT;					//原位标注到支座的水平距离
	
	static CString VN_bShowJZBZ;					//是否显示集中标注

	static CString VN_bShowYWBZ;					//是否显示原位标注
	
	static CString VN_bShowZZFH;					//是否显示支座符号
	

/////////////////////////////柱/////////////////////////////////////////////
	static CString KN_Pole;//柱
	static CString VN_bCheckInsertPtInAutoCreate;//在转化柱时是否检查插入点合法
	static CString VN_dMinZWallForZzz;//用于自动布置构造柱的砖墙最小长度
	static CString VN_dMinDWHWidth;//需要在两侧布置构造柱的最小门窗宽度
	static CString VN_bBasePointForGZZ;//在端点布置构造柱
	static CString VN_bCornerForGZZ;//在转弯处布置构造柱
	static CString VN_bTCrossForGZZ;//在T字型墙处布置构造柱
	static CString VN_bCrossForGZZ;//在十字型墙处布置构造柱

	//////////////////////////////////////////////////////////////////////////
	//调试
	static CString KN_Debug;//调试
	static CString VN_bVisibleForTagId;//合并用的标识实体是否可见
	static CString VN_bVisibleForNWTj;//内外条基运算是否可见
	static CString VN_bEraseTagId;//是否删除标识实体

	//读配置
	BOOL ReadConfig();
	BOOL WriteConfig();

	//added by jjj,2009.12.15
	/************************************************************************************
	*原先相关模块载入的顺序为PmDataBase、PmCustomEntBase、PmGjOpBase、PmGraphicGJOperator
	*目前要在模块PmCustomEntBase中使用PmGjOpBase载入的配置信息
	*由于PmCustomEntBase中只有绘图时会使用信息，此时其他模块已经载入，
	*因此可以在载入PmGraphicGJOperator模块时，将配置信息读取出来
	*为了统一，类似的配置信息统一被放到Database模块
	*
	*步骤：1、在PmConfig类中读取数据
	*      2、在PmGraphicGJOperator(也可以是其他的后载入模块)的InitApplication中将信息置入
	          PmDataBase的CProjectVar单件实体中
	*      3、在PmCustomEntBase中使用CProjectVar单件实体的信息
	*************************************************************************************/
	static PmConfig *Instance();
	static void Release();
	
private:
	
	static PmConfig*s_pPmConfig;
};


class PMLogicDataOprAPI CIniFileMap
{

public:
	CIniFileMap() {}
	virtual ~CIniFileMap() {}

public:
	//
	virtual BOOL ReadFile();
	virtual BOOL WriteFile();
	void Clear();

	//
	void SetPath(CString path);

	//
	CString GetValue(const CString & strAppName,const CString & strKeyName,const CString & defValue = _T(""));
	BOOL SetValue(const CString & strAppName, const CString & strKeyName, const CString & strKeyValue, BOOL const create = TRUE);

protected:
	CString m_filePath;
	std::map<CString, std::map<CString, CString> *> m_fileMap;//键值map
	std::map<int, CArray<CString, CString &> *> m_commentMap;//注释map
	CArray<CString, CString &> m_keyArray;
};

class PMLogicDataOprAPI ComParamsSet : public CIniFileMap
{
	ComParamsSet();
	virtual ~ComParamsSet();

public:
	//读配置
	BOOL ReadConfig();
	BOOL WriteConfig();

	static ComParamsSet *Instance();
	static void Release();

protected:
	static ComParamsSet * s_pComParamsSet;
};

#endif // !defined(AFX_PMCONFIG_H__D8BB66DC_0911_4AEF_A0A0_E05FA6ABEB1B__INCLUDED_)
