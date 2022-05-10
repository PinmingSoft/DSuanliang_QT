// GridFaceManager.h: interface for the CGridFaceManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRIDFACEMANAGER_H__902C76E7_6A42_47CD_BF7F_8A5395DDDE39__INCLUDED_)
#define AFX_GRIDFACEMANAGER_H__902C76E7_6A42_47CD_BF7F_8A5395DDDE39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

///用于管理显示的datagrid的显示样式
class PMLogicDataOprAPI CGridFaceManager  
{
public:
	static const CString OwnCommandDlg;
	static const CString GJVactorGraphManager;
	static const CString SL_AllComType;
	static const CString FloorManager;
	static const CString FloorGJXXInfo;
	static const CString ParmSetup;
	static const CString ParmValue;
	static const CString ParmValue70_50;
	static const CString ParmValue120_70;
	static const CString ParmValue120_120;
	static const CString ParmValue150_120 ;
	static const CString ParmValue150_200 ;
	static const CString ParmValue_ComInfo ;
	static const CString ComponentInfo;
	static const CString ComponentInfoMainUI;
	static const CString ComponentInfoMainUI_DrawerBar;
	static const CString QDDE;
	static const CString QDDE_m ;
	static const CString SwljsRules;
	static const CString GJTypeTree;
	static const CString SysDefRule;
	static const CString QDDE_FJCC;
	static const CString Swl_SysDefRule;
	static const CString Swl_QDDE_FJCC;
	static const CString SyzjkjRule;
	static const CString axis;
	static const CString axis_arc_yxj;

	static const CString axis_arc_radiusjs;
	static const CString GDTZ;
	static const CString VactorGraphManager;
	static const CString VectorInfo;
	static const CString ShowGJ;
	static const CString DarwBarControl;
	static const CString Result;
	static const CString DGJKSHXJ;
	static const CString DGJ_SWL;		//单构件实物量查量
	static const CString SearchInfo;
	static const CString SearchResult;
	static const CString EidtOtherItem_QD;

	static const CString EidtOtherItem_DE;
	static const CString CalItemNameListData;
	static const CString UnitListData;
	static const CString MJBJSZ;
	static const CString Select_YZB_Gj;
	static const CString QDDE_Control;
	
	static const CString CalMsgInfo;
	static const CString UniteResult;
	static const CString UniteProperty;
	static const CString FloorBGMode;
	static const CString CheckHFJCResult;
	static const CString CheckDZQResult;
	static const CString CT1_Zhe;
	static const CString CT2_Zhe;
	static const CString CT3_Zhe;	
	static const CString CT4_Zhe;
	static const CString CT51_Zhe;
	static const CString CT52_Zhe;
	static const CString CT6_Zhe;
	static const CString CT71_Zhe;
	static const CString CT72_Zhe;
	static const CString CT81_Zhe;
	static const CString CT82_Zhe;
	static const CString CT9_Zhe;
	
	static const CString CT1_Zhe_Gj;
	static const CString CT2_Zhe_Gj;
	static const CString CT3_Zhe_Gj;	
	static const CString CT4_Zhe_Gj;
	static const CString CT51_Zhe_Gj;
	static const CString CT52_Zhe_Gj;
	static const CString CT6_Zhe_Gj;
	static const CString CT71_Zhe_Gj;
	static const CString CT72_Zhe_Gj;
	static const CString CT81_Zhe_Gj;
	static const CString CT82_Zhe_Gj;
	static const CString CT9_Zhe_Gj;
	
	static const CString CT1_JiangSu;
	static const CString CT2_JiangSu;
	static const CString CT31Y_JiangSu;
	static const CString CT31F_JiangSu;
	static const CString CT32_JiangSu;
	static const CString CT4_JiangSu;
	static const CString CT51_JiangSu;
	static const CString CT52_JiangSu;
	static const CString CT6_JiangSu;
	static const CString CT71_JiangSu;
	static const CString CT72_JiangSu;
	static const CString CT81_JiangSu;
	static const CString CT82_JiangSu;
	static const CString CT9_JiangSu;

	static const CString CT1_JiangSu_Gj;
	static const CString CT2_JiangSu_Gj;
	static const CString CT31Y_JiangSu_Gj;
	static const CString CT31F_JiangSu_Gj;
	static const CString CT32_JiangSu_Gj;
	static const CString CT4_JiangSu_Gj;
	static const CString CT51_JiangSu_Gj;
	static const CString CT52_JiangSu_Gj;
	static const CString CT6_JiangSu_Gj;
	static const CString CT71_JiangSu_Gj;
	static const CString CT72_JiangSu_Gj;
	static const CString CT81_JiangSu_Gj;
	static const CString CT82_JiangSu_Gj;
	static const CString CT9_JiangSu_Gj;
	static const CString Zfgcl;

	//////////////////////////////////////////////////////////////////////////
	///钢筋部分
	//////////////////////////////////////////////////////////////////////////
	static const CString GJ_CalMsgInfo;
	static const CString GJ_ShowGJ;
	static const CString GJ_DarwBarControl;
	static const CString GJ_GJTypeTree;
	static const CString GJ_SteelTypeTree;	//仅钢筋的类型树
	static const CString GjfTypeTree ;   ///note：构件法 杨兴耀 [2009年7月21日] 
	static const CString ShowDlgData;
	static const CString FloorDJXSInfo;
	static const CString SlopeEarInfo;   //add by 郑琪崇：2016年3月17日
	static const CString LiangInputInfo;
	static const CString GJ_JSSZXML;
	static const CString Djmg;
	static const CString GJJSGS;
	static const CString GJSetup03g;
	static const CString GJSetupZS;
	static const CString ComponentDJXS;
	static const CString ComponentDJXS_SPSZ;
	static const CString liangfaceXML;
	static const CString jcliangfaceXML;
	static const CString jclianliangfaceXML;
	static const CString dkliangfaceXML;
	static const CString SuanLiangMode;
	static const CString GJFormula;
	static const CString CalResult;
	static const CString CustomSteelResult ;
	static const CString CalResult_ZHU;
	static const CString SteelParmModify;
	static const CString CSFVectorInfoManager;
	static const CString CSFVectorInfoManager_Gj;
	static const CString Steeldiagram;
	static const CString CalResult_QTLJ;
	//柱表
	static const CString ZhuTable;
	//连梁表
	static const CString LianLiangTable;
	//灌注桩表
	static const CString GZHTable;
	
	static CString m_strFilePath;

	///注释：杨兴耀 [2009年11月9日]                                  
	///
	static const CString MidstVariable;

	///
	static const CString QiangTable ;
	static const CString DuLiJiChuTable ;
	
	/// 
	static const CString EditOterItem_Detail ;
	
	static const CString DEWH_Grid;
	
	static const CString XMTZ ; 

	static const CString QDWH_Grid ; 

	static const CString GjSelectTreeQiang;

	static const CString GjSelectTreeMCD;

	static const CString GjSelectTreeYaDing;

	/// 自动布置构造柱
	static const CString Grid_AutoGZZ;

	/// 自动布置板缝
	static const CString Grid_AutoBF;

	/// 自动布置圈梁
	static const CString Grid_AutoQL;

	/// 布置带植筋的砌体加筋
	static const CString Grid_Qtjj_Zj;

	/// 布置砌体连接
	static const CString Grid_Qtlj;



	/// 施工段类别设置
	static const CString Grid_SGDLB;

	///PC墙编号
	static const CString Grid_PCWall;

	/// 云检查结果
	static const CString Grid_CloudCheckResult;
	static const CString Grid_CloudCheckResultIgnore;
	static const CString Grid_CloudCheckModule;

	//系统设置
	static const CString Grid_SystemSet;

	//名称显示
	static const CString ShowNameTree;
	static const CString GJ_ShowNameTree;

	//砖胎膜厚度设置
	static const CString Grid_ZTMHD_Set;

	static CGridFaceManager *Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = PMNew(CGridFaceManager);
		}
		return m_pInstance;
	}

	static void Release()
	{
		if(m_pInstance != NULL)
		{
			PMDelete(m_pInstance);
			m_pInstance = NULL;
		}
	}

	CGridFaceManager();
	virtual ~CGridFaceManager();
// 	CString GetGridFace(XMLName xmlName);
    CString GetGridFace(CString key);
	BOOL File2CString(CString& buf, LPCTSTR filename);
protected:	
	CMapStringToString m_MapFaceNameToSetup;
	static CGridFaceManager * m_pInstance;
};

#endif // !defined(AFX_GRIDFACEMANAGER_H__902C76E7_6A42_47CD_BF7F_8A5395DDDE39__INCLUDED_)
