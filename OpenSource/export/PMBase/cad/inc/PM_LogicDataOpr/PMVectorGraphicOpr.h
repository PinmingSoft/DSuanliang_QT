#pragma once

#include "PMSolidVectorGraphicOpr.h"

typedef std::map<CString,CString> ParmsMapInfo_T;

//Vector信息点 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_Pt : public CObject
{
	DECLARE_SERIAL( CPMVectorEntityInfo_Pt )
public:
	CPMVectorEntityInfo_Pt();
	virtual ~CPMVectorEntityInfo_Pt();

	virtual void Serialize( CArchive& archive );

	//构造点信息的 对象
	BOOL BuildVectorPt(const CString & strPointInfo);

	BOOL BuildDataSetInfo(CString & strPointInfo) const;

	const CString & GetPtX() const {return m_strX;}
	void SetPtX(const CString & strX) {m_strX = strX;}

	const CString & GetPtY() const {return m_strY;}
	void SetPtY(const CString & strY) {m_strY = strY;}

	const CString & GetPtZ() const {return m_strZ;}
	void SetPtZ(const CString & strZ) {m_strZ = strZ;}

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

private:

	CString m_strX;
	CString m_strY;
	CString m_strZ;
};

typedef CArray<CPMVectorEntityInfo_Pt * ,CPMVectorEntityInfo_Pt*&>	CPMVectorEntityInfo_PtArr;

//Vector信息边 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_Bian : public CObject
{
	DECLARE_SERIAL( CPMVectorEntityInfo_Bian )
public:
	enum EntityInfoBianType
	{
		Bian_Null = 0,
		Bian_YuanHUan = 1,	//圆环
		Bian_Line = 2,		//线段
		Bian_Clrcie = 3,	//圆
		Bian_ArcYX = 4,		//圆弧 圆心的绘制方式
		Bian_ArcDD = 5,		//圆弧 三顶点 绘制方式
		Bian_XHN = 6		//循环连续边
	};

	CPMVectorEntityInfo_Bian();
	virtual ~CPMVectorEntityInfo_Bian();

	virtual void Serialize( CArchive& archive );

	EntityInfoBianType GetBianType() const { return m_BianType;}

	//必需重载函数
	virtual BOOL BuildBianInfo(const CString & strBianInfo)
	{
		return FALSE;
	}

	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const
	{
		return FALSE;
	}

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

protected:

	EntityInfoBianType m_BianType;
};

typedef CArray<CPMVectorEntityInfo_Bian * ,CPMVectorEntityInfo_Bian*&>	CPMVectorEntityInfo_BianArr;

//Vector信息圆环 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_YuanHuan : public CPMVectorEntityInfo_Bian
{
	DECLARE_SERIAL( CPMVectorEntityInfo_YuanHuan )
public:
	CPMVectorEntityInfo_YuanHuan();
	virtual ~CPMVectorEntityInfo_YuanHuan();

	virtual void Serialize( CArchive& archive );

	//必需重载函数
	virtual BOOL BuildBianInfo(const CString & strBianInfo);

	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt * GetPtCenter() const {return & m_PtCenter;}
	const CPMVectorEntityInfo_Pt * GetPtVer() const {return & m_PtVer;}

	CString GetRadioBig() const {return m_strRadioBig;}
	CString GetRadioSmall() const {return m_strRadioSmall;}

private:

	CPMVectorEntityInfo_Pt m_PtCenter;//圆环 圆心
	CPMVectorEntityInfo_Pt m_PtVer;//圆环 向量
	CString m_strRadioBig;			//圆环 半径大
	CString m_strRadioSmall;		//圆环 半径小
};

//Vector信息循环边 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_XHNBian : public CPMVectorEntityInfo_Bian
{
	DECLARE_SERIAL( CPMVectorEntityInfo_XHNBian )
public:
	CPMVectorEntityInfo_XHNBian();
	virtual ~CPMVectorEntityInfo_XHNBian();

	virtual void Serialize( CArchive& archive );

	//必需重载函数
	virtual BOOL BuildBianInfo(const CString & strBianInfo);
	
	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_PtArr * GetBianPtArr() const
	{
		return & m_BianPtArr;
	}

	const CArray<double,double &> * GetBianBugleArr()const
	{
		return & m_BianBugleArr;
	}

private:

	void FreeData();

	CPMVectorEntityInfo_PtArr m_BianPtArr;//循环边的 点队列
	CArray<double,double &> m_BianBugleArr;//循环边的 凸度队列
};

//Vector信息边 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_Line : public CPMVectorEntityInfo_Bian
{
	DECLARE_SERIAL( CPMVectorEntityInfo_Line )
public:
	CPMVectorEntityInfo_Line();
	virtual ~CPMVectorEntityInfo_Line();

	virtual void Serialize( CArchive& archive );

	//必需重载函数
	virtual BOOL BuildBianInfo(const CString & strBianInfo);

	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt * GetPtStart() const { return &m_PtStart;}
	const CPMVectorEntityInfo_Pt * GetPtEnd() const {return &m_PtEnd;}

private:

	CPMVectorEntityInfo_Pt m_PtStart;	//起点
	CPMVectorEntityInfo_Pt m_PtEnd;		//终点
};

//Vector信息园 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_Clrcle : public CPMVectorEntityInfo_Bian
{
	DECLARE_SERIAL( CPMVectorEntityInfo_Clrcle )
public:
	CPMVectorEntityInfo_Clrcle();
	virtual ~CPMVectorEntityInfo_Clrcle();

	virtual void Serialize( CArchive& archive );

	//必需重载函数
	virtual BOOL BuildBianInfo(const CString & strBianInfo);

	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt * GetPtCenter()const {return &m_PtCenter;}
	const CPMVectorEntityInfo_Pt * GetPtVer() const {return &m_PtVer;}

	CString GetRadio() const {return m_strRadio;}

private:

	CPMVectorEntityInfo_Pt m_PtCenter;//圆环 圆心
	CPMVectorEntityInfo_Pt m_PtVer;//圆环 向量
	CString m_strRadio;			//圆环 半径
};

//Vector信息 圆弧 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_ArcYX : public CPMVectorEntityInfo_Bian
{
	DECLARE_SERIAL( CPMVectorEntityInfo_ArcYX )
public:
	CPMVectorEntityInfo_ArcYX();
	virtual ~CPMVectorEntityInfo_ArcYX();

	virtual void Serialize( CArchive& archive );

	//必需重载函数
	virtual BOOL BuildBianInfo(const CString & strBianInfo);

	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt* GetPtCenter() const {return &m_PtCenter;}
	const CPMVectorEntityInfo_Pt* GetPtStart() const {return &m_PtStart;}
	const CPMVectorEntityInfo_Pt* GetPtEnd() const {return &m_PtEnd;}

private:

	CPMVectorEntityInfo_Pt m_PtCenter;//圆弧 圆心
	CPMVectorEntityInfo_Pt m_PtStart;//圆弧 起点
	CPMVectorEntityInfo_Pt m_PtEnd;//圆弧 终点
};

//Vector信息 圆弧 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_ArcDD : public CPMVectorEntityInfo_Bian
{
	DECLARE_SERIAL( CPMVectorEntityInfo_ArcDD )
public:
	CPMVectorEntityInfo_ArcDD();
	virtual ~CPMVectorEntityInfo_ArcDD();

	virtual void Serialize( CArchive& archive );

	//必需重载函数
	virtual BOOL BuildBianInfo(const CString & strBianInfo);

	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt* GetPtHigh() const {return &m_PtHigh;}
	const CPMVectorEntityInfo_Pt* GetPtStart() const {return &m_PtStart;}
	const CPMVectorEntityInfo_Pt* GetPtEnd() const {return &m_PtEnd;}

private:

	CPMVectorEntityInfo_Pt m_PtHigh;//圆环 最高点
	CPMVectorEntityInfo_Pt m_PtStart;//圆环 起点
	CPMVectorEntityInfo_Pt m_PtEnd;//圆环 终点
};

//Vector信息 单个实体信息 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_SimEnt : public CObject
{
	DECLARE_SERIAL( CPMVectorEntityInfo_SimEnt )
public:
	enum EntityType
	{
		Entity_Null = 0,	//空
		Entity_CFT = 1,		//长方体
		Entity_YZ = 2,		//圆柱
		Entity_QIU = 3,		//球
		Entity_ZHU = 4,		//柱体
		Entity_TAI = 5,		//台体
		Entity_SpecTAI = 6,	//特殊的台体
		Entity_ZUI = 7,		//锥体
		Entity_JM = 8,		//截面
	};
	enum EntityRelation
	{
		Entity_Union = 1,	//实体并
		Entity_Sub = 2,		//实体扣减
		Entity_Inter = 3	//实体取交集
	};

	CPMVectorEntityInfo_SimEnt();
	virtual ~CPMVectorEntityInfo_SimEnt();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief 通过信息构造 实体信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  建立DataSet的 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	EntityRelation GetEntRelation() const {return m_EntityRelation;}	//体关系

	CString GetGD() const{return m_strGD;}					//高度

	CString GetDTBL() const {return m_strDTBL;}					//递推变量（用于 循环处理）
	
protected:

	/**
	* @brief  拆分边信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	BOOL BuildJMEntInfo(const CString & strJMInfo,CPMVectorEntityInfo_BianArr & temEntityBianArr);

	/**
	* @brief 合成边 DataSet 信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [31/5/2012]
	*/
	BOOL BuildJMDataSetInfo(const CPMVectorEntityInfo_BianArr & temEntityBianArr,CString & strJMInfo) const;

	EntityRelation TranEntityRelation(int iEntityRelation);

	EntityType m_EntityType;			//体构件类型

private:

	EntityRelation m_EntityRelation;	//体关系

	CString m_strGD;					//高度

	CString m_strDTBL;					//递推变量（用于 循环处理）
};

typedef CArray<CPMVectorEntityInfo_SimEnt * ,CPMVectorEntityInfo_SimEnt*&>	CPMVectorEntityInfo_SimEntArr;

//Vector信息 正方体 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_CFT : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_CFT )
public:

	CPMVectorEntityInfo_CFT();
	virtual ~CPMVectorEntityInfo_CFT();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief 通过信息构造 实体信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  建立DataSet的 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);
	
	const CPMVectorEntityInfo_Pt * GetPt1() const {return &m_Pt1;}
	const CPMVectorEntityInfo_Pt * GetPt2() const {return &m_Pt2;}
	const CPMVectorEntityInfo_Pt * GetPt3() const {return &m_Pt3;}

private:

	CPMVectorEntityInfo_Pt m_Pt1;
	CPMVectorEntityInfo_Pt m_Pt2;
	CPMVectorEntityInfo_Pt m_Pt3;
};

//Vector信息 圆柱 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_YZ : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_YZ )
public:

	CPMVectorEntityInfo_YZ();
	virtual ~CPMVectorEntityInfo_YZ();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief 通过信息构造 实体信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  建立DataSet的 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt * GetPtCenter() const {return &m_PtCenter;}
	const CPMVectorEntityInfo_Pt * GetPtVer() const {return & m_PtVer;}

	CString GetRadio() const {return m_Radio;}

private:

	CPMVectorEntityInfo_Pt m_PtCenter;	//圆心位置
	CPMVectorEntityInfo_Pt m_PtVer;		//圆心位置
	CString m_Radio;					//半径
};

//Vector信息 异形柱 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_ZHU : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_ZHU )
public:

	CPMVectorEntityInfo_ZHU();
	virtual ~CPMVectorEntityInfo_ZHU();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief 通过信息构造 实体信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  建立DataSet的 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_BianArr * GetBianArr() const
	{
		return & m_entityBianArr;
	}

private:

	void FreeData();

	CPMVectorEntityInfo_BianArr m_entityBianArr;
};

//Vector信息 锥 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_ZUI : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_ZUI )
public:

	CPMVectorEntityInfo_ZUI();
	virtual ~CPMVectorEntityInfo_ZUI();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief 通过信息构造 实体信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  建立DataSet的 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_BianArr * GetBianArr() const
	{
		return & m_entityBianArr;
	}

	const CPMVectorEntityInfo_Pt * GetBeginPt() const
	{
		return & m_beginPt;
	}

private:

	void FreeData();

	CPMVectorEntityInfo_Pt m_beginPt;
	CPMVectorEntityInfo_BianArr m_entityBianArr;
};

//Vector信息 截面 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_JM : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_JM )
public:

	CPMVectorEntityInfo_JM();
	virtual ~CPMVectorEntityInfo_JM();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief 通过信息构造 实体信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  建立DataSet的 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_BianArr * GetBianArr() const
	{
		return & m_entityBianArr;
	}

private:

	void FreeData();

	CPMVectorEntityInfo_BianArr m_entityBianArr;
};

//Vector信息 台 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_TAI : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_TAI )
public:

	CPMVectorEntityInfo_TAI();
	virtual ~CPMVectorEntityInfo_TAI();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief 通过信息构造 实体信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  建立DataSet的 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_BianArr * GetStartBianArr() const
	{
		return & m_entityStartBianArr;
	}

	const CPMVectorEntityInfo_BianArr * GetEndBianArr() const
	{
		return & m_entityEndBianArr;
	}

private:

	void FreeData();

	CPMVectorEntityInfo_BianArr m_entityStartBianArr;
	CPMVectorEntityInfo_BianArr m_entityEndBianArr;
};

//Vector信息异形台 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_SpecTAI : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_SpecTAI )
public:

	CPMVectorEntityInfo_SpecTAI();
	virtual ~CPMVectorEntityInfo_SpecTAI();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief 通过信息构造 实体信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  建立DataSet的 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_BianArr * GetStartBianArr() const
	{
		return & m_entityStartBianArr;
	}

	const CPMVectorEntityInfo_BianArr * GetEndBianArr() const
	{
		return & m_entityEndBianArr;
	}

private:

	void FreeData();

	CPMVectorEntityInfo_BianArr m_entityStartBianArr;
	CPMVectorEntityInfo_BianArr m_entityEndBianArr;
};

//Vector信息 球 包装
class PMLogicDataOprAPI CPMVectorEntityInfo_QIU : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_QIU )
public:

	CPMVectorEntityInfo_QIU();
	virtual ~CPMVectorEntityInfo_QIU();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief 通过信息构造 实体信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  建立DataSet的 信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  替换Vector中的参数
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt * GetPtCenter() const {return &m_PtCenter;}

private:

	CPMVectorEntityInfo_Pt m_PtCenter;	//球心位置
};

//整体Vector信息 维持类
class PMLogicDataOprAPI CPMVectorGJEntityInfo : public CPMVectorInfo_Base
{
public:
	CPMVectorGJEntityInfo();
	virtual ~CPMVectorGJEntityInfo();

	/**
	* @brief 获取 Vector的长度  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorLength() const;

	/**
	* @brief  获取Vector的 宽度 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorWidth() const;

	/**
	* @brief  获取 Vector的 高度 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorHeight() const;

	/**
	* @brief  获取Vector 边信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorBianInfo() const;

	/**
	 * @brief  :获取Vector 边信息绘制顺序
	 *
	 * 详细描述
	 * @author zyj
	 * @version v1.0
	 * @date  2016/4/23 11:27
	 * @note  :
	 */
	virtual CString GetVectorBianOrderInfo() const;

	/**
	* @brief 获取 Vector的 特殊运算信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorSpecInfo() const;
	virtual void SetSpecVectorInfo(const CString & strSpecInfo);

	/**
	* @brief  获取 Vector的绘制方式 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	const CPMVectorEntityInfo_SimEntArr * GetVectorDrawInfo()const ;

	/**
	* @brief  进行参数替换 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	/**
	* @brief  从Buffer中读取数据 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL ReadFromBuffer( BYTE * pBuffer,long lBufferSize );

	/**
	* @brief 将数据写到Buffer中去  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL WriteToBuffer( BYTE *& pBuffer,long & lBufferSize );

	/**
	* @brief 从DataSet中读取数据  
	*
	*          
	* @note  : 只用于保存界面显示，Vector的绘制数据
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL ReadFromDataSet( const CString & strVectorInfo );

	/**
	* @brief  将数据保存为DataSet 
	*
	*          
	* @note  : 只用于界面显示，Vector的绘制数据
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL WriteToDataSet( CString & strVectorInfo ) const ;

	//清除之前的数据
	virtual void FreeData();

private:

	BOOL AnalyseFormDataSet(NDataModelDataSet * pVectorInfoDataSet);

	BOOL AnalyseToDataSet(NDataModelDataSet * pVectorInfoDataSet) const;

	BOOL Serialize(CArchive& ar);

	BOOL StoreData(CArchive& ar);

	BOOL ReadData(CArchive& ar);

	CString m_strLength;//长度
	CString m_strWidth;//宽度
	CString m_strHeight;//高度
	CString m_strParmNamePosX;
	CString m_strParmNamePosY;

	CString m_strBianInfo;//保存的是边信息

	CPMVectorEntityInfo_SimEntArr m_EntityInfoFaceArr;//构件的面信息

	CString m_strSpecInfo;//保存的是 特殊计算公式
	CString m_strBianOrderInfo;//保存的是边信息绘制顺序
};

class CPMVectorGraphicOpr
{
public:
	CPMVectorGraphicOpr(void);
	virtual ~CPMVectorGraphicOpr(void);
};
