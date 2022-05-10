#pragma once

#include "PMSolidVectorGraphicOpr.h"

typedef std::map<CString,CString> ParmsMapInfo_T;

//Vector��Ϣ�� ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_Pt : public CObject
{
	DECLARE_SERIAL( CPMVectorEntityInfo_Pt )
public:
	CPMVectorEntityInfo_Pt();
	virtual ~CPMVectorEntityInfo_Pt();

	virtual void Serialize( CArchive& archive );

	//�������Ϣ�� ����
	BOOL BuildVectorPt(const CString & strPointInfo);

	BOOL BuildDataSetInfo(CString & strPointInfo) const;

	const CString & GetPtX() const {return m_strX;}
	void SetPtX(const CString & strX) {m_strX = strX;}

	const CString & GetPtY() const {return m_strY;}
	void SetPtY(const CString & strY) {m_strY = strY;}

	const CString & GetPtZ() const {return m_strZ;}
	void SetPtZ(const CString & strZ) {m_strZ = strZ;}

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

private:

	CString m_strX;
	CString m_strY;
	CString m_strZ;
};

typedef CArray<CPMVectorEntityInfo_Pt * ,CPMVectorEntityInfo_Pt*&>	CPMVectorEntityInfo_PtArr;

//Vector��Ϣ�� ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_Bian : public CObject
{
	DECLARE_SERIAL( CPMVectorEntityInfo_Bian )
public:
	enum EntityInfoBianType
	{
		Bian_Null = 0,
		Bian_YuanHUan = 1,	//Բ��
		Bian_Line = 2,		//�߶�
		Bian_Clrcie = 3,	//Բ
		Bian_ArcYX = 4,		//Բ�� Բ�ĵĻ��Ʒ�ʽ
		Bian_ArcDD = 5,		//Բ�� ������ ���Ʒ�ʽ
		Bian_XHN = 6		//ѭ��������
	};

	CPMVectorEntityInfo_Bian();
	virtual ~CPMVectorEntityInfo_Bian();

	virtual void Serialize( CArchive& archive );

	EntityInfoBianType GetBianType() const { return m_BianType;}

	//�������غ���
	virtual BOOL BuildBianInfo(const CString & strBianInfo)
	{
		return FALSE;
	}

	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const
	{
		return FALSE;
	}

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

protected:

	EntityInfoBianType m_BianType;
};

typedef CArray<CPMVectorEntityInfo_Bian * ,CPMVectorEntityInfo_Bian*&>	CPMVectorEntityInfo_BianArr;

//Vector��ϢԲ�� ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_YuanHuan : public CPMVectorEntityInfo_Bian
{
	DECLARE_SERIAL( CPMVectorEntityInfo_YuanHuan )
public:
	CPMVectorEntityInfo_YuanHuan();
	virtual ~CPMVectorEntityInfo_YuanHuan();

	virtual void Serialize( CArchive& archive );

	//�������غ���
	virtual BOOL BuildBianInfo(const CString & strBianInfo);

	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt * GetPtCenter() const {return & m_PtCenter;}
	const CPMVectorEntityInfo_Pt * GetPtVer() const {return & m_PtVer;}

	CString GetRadioBig() const {return m_strRadioBig;}
	CString GetRadioSmall() const {return m_strRadioSmall;}

private:

	CPMVectorEntityInfo_Pt m_PtCenter;//Բ�� Բ��
	CPMVectorEntityInfo_Pt m_PtVer;//Բ�� ����
	CString m_strRadioBig;			//Բ�� �뾶��
	CString m_strRadioSmall;		//Բ�� �뾶С
};

//Vector��Ϣѭ���� ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_XHNBian : public CPMVectorEntityInfo_Bian
{
	DECLARE_SERIAL( CPMVectorEntityInfo_XHNBian )
public:
	CPMVectorEntityInfo_XHNBian();
	virtual ~CPMVectorEntityInfo_XHNBian();

	virtual void Serialize( CArchive& archive );

	//�������غ���
	virtual BOOL BuildBianInfo(const CString & strBianInfo);
	
	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
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

	CPMVectorEntityInfo_PtArr m_BianPtArr;//ѭ���ߵ� �����
	CArray<double,double &> m_BianBugleArr;//ѭ���ߵ� ͹�ȶ���
};

//Vector��Ϣ�� ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_Line : public CPMVectorEntityInfo_Bian
{
	DECLARE_SERIAL( CPMVectorEntityInfo_Line )
public:
	CPMVectorEntityInfo_Line();
	virtual ~CPMVectorEntityInfo_Line();

	virtual void Serialize( CArchive& archive );

	//�������غ���
	virtual BOOL BuildBianInfo(const CString & strBianInfo);

	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt * GetPtStart() const { return &m_PtStart;}
	const CPMVectorEntityInfo_Pt * GetPtEnd() const {return &m_PtEnd;}

private:

	CPMVectorEntityInfo_Pt m_PtStart;	//���
	CPMVectorEntityInfo_Pt m_PtEnd;		//�յ�
};

//Vector��Ϣ԰ ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_Clrcle : public CPMVectorEntityInfo_Bian
{
	DECLARE_SERIAL( CPMVectorEntityInfo_Clrcle )
public:
	CPMVectorEntityInfo_Clrcle();
	virtual ~CPMVectorEntityInfo_Clrcle();

	virtual void Serialize( CArchive& archive );

	//�������غ���
	virtual BOOL BuildBianInfo(const CString & strBianInfo);

	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt * GetPtCenter()const {return &m_PtCenter;}
	const CPMVectorEntityInfo_Pt * GetPtVer() const {return &m_PtVer;}

	CString GetRadio() const {return m_strRadio;}

private:

	CPMVectorEntityInfo_Pt m_PtCenter;//Բ�� Բ��
	CPMVectorEntityInfo_Pt m_PtVer;//Բ�� ����
	CString m_strRadio;			//Բ�� �뾶
};

//Vector��Ϣ Բ�� ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_ArcYX : public CPMVectorEntityInfo_Bian
{
	DECLARE_SERIAL( CPMVectorEntityInfo_ArcYX )
public:
	CPMVectorEntityInfo_ArcYX();
	virtual ~CPMVectorEntityInfo_ArcYX();

	virtual void Serialize( CArchive& archive );

	//�������غ���
	virtual BOOL BuildBianInfo(const CString & strBianInfo);

	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt* GetPtCenter() const {return &m_PtCenter;}
	const CPMVectorEntityInfo_Pt* GetPtStart() const {return &m_PtStart;}
	const CPMVectorEntityInfo_Pt* GetPtEnd() const {return &m_PtEnd;}

private:

	CPMVectorEntityInfo_Pt m_PtCenter;//Բ�� Բ��
	CPMVectorEntityInfo_Pt m_PtStart;//Բ�� ���
	CPMVectorEntityInfo_Pt m_PtEnd;//Բ�� �յ�
};

//Vector��Ϣ Բ�� ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_ArcDD : public CPMVectorEntityInfo_Bian
{
	DECLARE_SERIAL( CPMVectorEntityInfo_ArcDD )
public:
	CPMVectorEntityInfo_ArcDD();
	virtual ~CPMVectorEntityInfo_ArcDD();

	virtual void Serialize( CArchive& archive );

	//�������غ���
	virtual BOOL BuildBianInfo(const CString & strBianInfo);

	virtual BOOL BuildDataSetInfo(CString & strBianInfo) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt* GetPtHigh() const {return &m_PtHigh;}
	const CPMVectorEntityInfo_Pt* GetPtStart() const {return &m_PtStart;}
	const CPMVectorEntityInfo_Pt* GetPtEnd() const {return &m_PtEnd;}

private:

	CPMVectorEntityInfo_Pt m_PtHigh;//Բ�� ��ߵ�
	CPMVectorEntityInfo_Pt m_PtStart;//Բ�� ���
	CPMVectorEntityInfo_Pt m_PtEnd;//Բ�� �յ�
};

//Vector��Ϣ ����ʵ����Ϣ ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_SimEnt : public CObject
{
	DECLARE_SERIAL( CPMVectorEntityInfo_SimEnt )
public:
	enum EntityType
	{
		Entity_Null = 0,	//��
		Entity_CFT = 1,		//������
		Entity_YZ = 2,		//Բ��
		Entity_QIU = 3,		//��
		Entity_ZHU = 4,		//����
		Entity_TAI = 5,		//̨��
		Entity_SpecTAI = 6,	//�����̨��
		Entity_ZUI = 7,		//׶��
		Entity_JM = 8,		//����
	};
	enum EntityRelation
	{
		Entity_Union = 1,	//ʵ�岢
		Entity_Sub = 2,		//ʵ��ۼ�
		Entity_Inter = 3	//ʵ��ȡ����
	};

	CPMVectorEntityInfo_SimEnt();
	virtual ~CPMVectorEntityInfo_SimEnt();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief ͨ����Ϣ���� ʵ����Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  ����DataSet�� ��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	EntityRelation GetEntRelation() const {return m_EntityRelation;}	//���ϵ

	CString GetGD() const{return m_strGD;}					//�߶�

	CString GetDTBL() const {return m_strDTBL;}					//���Ʊ��������� ѭ������
	
protected:

	/**
	* @brief  ��ֱ���Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	BOOL BuildJMEntInfo(const CString & strJMInfo,CPMVectorEntityInfo_BianArr & temEntityBianArr);

	/**
	* @brief �ϳɱ� DataSet ��Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [31/5/2012]
	*/
	BOOL BuildJMDataSetInfo(const CPMVectorEntityInfo_BianArr & temEntityBianArr,CString & strJMInfo) const;

	EntityRelation TranEntityRelation(int iEntityRelation);

	EntityType m_EntityType;			//�幹������

private:

	EntityRelation m_EntityRelation;	//���ϵ

	CString m_strGD;					//�߶�

	CString m_strDTBL;					//���Ʊ��������� ѭ������
};

typedef CArray<CPMVectorEntityInfo_SimEnt * ,CPMVectorEntityInfo_SimEnt*&>	CPMVectorEntityInfo_SimEntArr;

//Vector��Ϣ ������ ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_CFT : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_CFT )
public:

	CPMVectorEntityInfo_CFT();
	virtual ~CPMVectorEntityInfo_CFT();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief ͨ����Ϣ���� ʵ����Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  ����DataSet�� ��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
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

//Vector��Ϣ Բ�� ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_YZ : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_YZ )
public:

	CPMVectorEntityInfo_YZ();
	virtual ~CPMVectorEntityInfo_YZ();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief ͨ����Ϣ���� ʵ����Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  ����DataSet�� ��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt * GetPtCenter() const {return &m_PtCenter;}
	const CPMVectorEntityInfo_Pt * GetPtVer() const {return & m_PtVer;}

	CString GetRadio() const {return m_Radio;}

private:

	CPMVectorEntityInfo_Pt m_PtCenter;	//Բ��λ��
	CPMVectorEntityInfo_Pt m_PtVer;		//Բ��λ��
	CString m_Radio;					//�뾶
};

//Vector��Ϣ ������ ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_ZHU : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_ZHU )
public:

	CPMVectorEntityInfo_ZHU();
	virtual ~CPMVectorEntityInfo_ZHU();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief ͨ����Ϣ���� ʵ����Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  ����DataSet�� ��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
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

//Vector��Ϣ ׶ ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_ZUI : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_ZUI )
public:

	CPMVectorEntityInfo_ZUI();
	virtual ~CPMVectorEntityInfo_ZUI();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief ͨ����Ϣ���� ʵ����Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  ����DataSet�� ��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
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

//Vector��Ϣ ���� ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_JM : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_JM )
public:

	CPMVectorEntityInfo_JM();
	virtual ~CPMVectorEntityInfo_JM();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief ͨ����Ϣ���� ʵ����Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  ����DataSet�� ��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
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

//Vector��Ϣ ̨ ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_TAI : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_TAI )
public:

	CPMVectorEntityInfo_TAI();
	virtual ~CPMVectorEntityInfo_TAI();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief ͨ����Ϣ���� ʵ����Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  ����DataSet�� ��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
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

//Vector��Ϣ����̨ ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_SpecTAI : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_SpecTAI )
public:

	CPMVectorEntityInfo_SpecTAI();
	virtual ~CPMVectorEntityInfo_SpecTAI();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief ͨ����Ϣ���� ʵ����Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  ����DataSet�� ��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
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

//Vector��Ϣ �� ��װ
class PMLogicDataOprAPI CPMVectorEntityInfo_QIU : public CPMVectorEntityInfo_SimEnt
{
	DECLARE_SERIAL( CPMVectorEntityInfo_QIU )
public:

	CPMVectorEntityInfo_QIU();
	virtual ~CPMVectorEntityInfo_QIU();

	virtual void Serialize( CArchive& archive );

	/**
	* @brief ͨ����Ϣ���� ʵ����Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildEntInfo(const CString & strQDM,const CString & strZZM,const CString & strGD,const CString & strTGX,const CString & strDTBL);

	/**
	* @brief  ����DataSet�� ��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL BuildDataSetInfo(CString & strHZXX,CString & strQDM,CString & strZZM,CString & strGD,CString & strTGX,CString & strDTBL) const;

	/**
	* @brief  �滻Vector�еĲ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	const CPMVectorEntityInfo_Pt * GetPtCenter() const {return &m_PtCenter;}

private:

	CPMVectorEntityInfo_Pt m_PtCenter;	//����λ��
};

//����Vector��Ϣ ά����
class PMLogicDataOprAPI CPMVectorGJEntityInfo : public CPMVectorInfo_Base
{
public:
	CPMVectorGJEntityInfo();
	virtual ~CPMVectorGJEntityInfo();

	/**
	* @brief ��ȡ Vector�ĳ���  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorLength() const;

	/**
	* @brief  ��ȡVector�� ��� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorWidth() const;

	/**
	* @brief  ��ȡ Vector�� �߶� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorHeight() const;

	/**
	* @brief  ��ȡVector ����Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorBianInfo() const;

	/**
	 * @brief  :��ȡVector ����Ϣ����˳��
	 *
	 * ��ϸ����
	 * @author zyj
	 * @version v1.0
	 * @date  2016/4/23 11:27
	 * @note  :
	 */
	virtual CString GetVectorBianOrderInfo() const;

	/**
	* @brief ��ȡ Vector�� ����������Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorSpecInfo() const;
	virtual void SetSpecVectorInfo(const CString & strSpecInfo);

	/**
	* @brief  ��ȡ Vector�Ļ��Ʒ�ʽ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	const CPMVectorEntityInfo_SimEntArr * GetVectorDrawInfo()const ;

	/**
	* @brief  ���в����滻 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	/**
	* @brief  ��Buffer�ж�ȡ���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL ReadFromBuffer( BYTE * pBuffer,long lBufferSize );

	/**
	* @brief ������д��Buffer��ȥ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL WriteToBuffer( BYTE *& pBuffer,long & lBufferSize );

	/**
	* @brief ��DataSet�ж�ȡ����  
	*
	*          
	* @note  : ֻ���ڱ��������ʾ��Vector�Ļ�������
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL ReadFromDataSet( const CString & strVectorInfo );

	/**
	* @brief  �����ݱ���ΪDataSet 
	*
	*          
	* @note  : ֻ���ڽ�����ʾ��Vector�Ļ�������
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL WriteToDataSet( CString & strVectorInfo ) const ;

	//���֮ǰ������
	virtual void FreeData();

private:

	BOOL AnalyseFormDataSet(NDataModelDataSet * pVectorInfoDataSet);

	BOOL AnalyseToDataSet(NDataModelDataSet * pVectorInfoDataSet) const;

	BOOL Serialize(CArchive& ar);

	BOOL StoreData(CArchive& ar);

	BOOL ReadData(CArchive& ar);

	CString m_strLength;//����
	CString m_strWidth;//���
	CString m_strHeight;//�߶�
	CString m_strParmNamePosX;
	CString m_strParmNamePosY;

	CString m_strBianInfo;//������Ǳ���Ϣ

	CPMVectorEntityInfo_SimEntArr m_EntityInfoFaceArr;//����������Ϣ

	CString m_strSpecInfo;//������� ������㹫ʽ
	CString m_strBianOrderInfo;//������Ǳ���Ϣ����˳��
};

class CPMVectorGraphicOpr
{
public:
	CPMVectorGraphicOpr(void);
	virtual ~CPMVectorGraphicOpr(void);
};
