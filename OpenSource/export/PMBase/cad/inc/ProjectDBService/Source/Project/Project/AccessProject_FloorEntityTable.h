#pragma once

//#include "..\accesstable.h"

////////////////////////////////////////////
/// ����ҵ [2013:7:3   11:20]
/// ˵��:
/// ѡ�� ������ ����ʵ��
/// int :��ǰ¥��ID int : ¥��ID double:��ʼ��Ա�ߣ�double:��ֹ��Ա��
typedef BOOL(*SelectRelation_Info_CheckKcEntityInfo)(int,int ,double ,double);

class PMProjectDBSERVICE CProject_FloorEntityTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_FloorEntityTable)

	CProject_FloorEntityTable();
	virtual ~CProject_FloorEntityTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString floorid;
		static int	 floorid_Index;

		static const CString handlelow;			//�����λ
		static int		handlelow_Index;

		static const CString handlehigh;		//�����λ
		static int			handlehigh_Index;

		static const CString comtype;			//��������
		static int			comtype_Index;

		static const CString topbg;				//��ߵ���
		static int			topbg_Index;

		static const CString bottombg;			//��͵���
		static int			bottombg_Index;

		static const CString entitydata;		//ʵ����Ϣ	
		static int			entitydata_Index;

		static const CString entitydata3D;		//ʵ��3D��Ϣ	
		static int			entitydata3D_Index;

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_FloorEntityTable : public CPMSLAccessTable
{
public:
	CAccessProject_FloorEntityTable(void);
	~CAccessProject_FloorEntityTable(void);


	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	/**
	* @brief ���� ��ǰ���� ���п�㹹����Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/9/2013]
	*/
	BOOL		GetTableCtrl(   CPMSQLTableCtrl *& pTableCtrl );

	/// 
	/// 
	/// 
	/// ר�ýӿ�
	/// 
	BOOL		GetTableCtrl( const int iFloorId ,  CPMSQLTableCtrl *& pTableCtrl ) ;

	/// 
	BOOL		Delete( const CUIntArray & aryQddeId ) ;

	/**
	* @brief  ������Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/5/2013]
	*/
	BOOL InsertInfo(int iFloorID,int ihandlehigh,int ihandlelow,int iComType,const double & dTopBg,\
		const double & dBottomBG,const LPVOID & pEntInfo,long lEntInfoSize);
	BOOL InsertInfo(int iFloorID,int ihandlehigh,int ihandlelow,int iComType,const double & dTopBg,\
		const double & dBottomBG,const LPVOID & pEntInfo,long lEntInfoSize,const LPVOID & pEnt3DInfo,long lEnt3DInfoSize);

	BOOL DeleteInfo(int iFloorID);
	BOOL DeleteInfo(int iFloorID,int ihandlehigh,int ihandlelow);

	/**
	* @brief ��ȡ����  
	*
	*          
	* @note  : ������� �ȽϺ�ʱ
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/5/2013]
	*/
	BOOL SelectInfo(int iFloorID,int ihandlehigh,int ihandlelow,CProject_FloorEntityTable *& pKcEntityTable);
	BOOL SelectInfo(int iFloorID,CProject_FloorEntityTable *& pKcEntityTable);

	BOOL SelectRelation_Info(int iFloorID,CProject_FloorEntityTable *& pKcEntityTable);

	BOOL SelectRelation_Info(int iFloorID,CProject_FloorEntityTable *& pKcEntityTable,SelectRelation_Info_CheckKcEntityInfo pCheckFun);

	BOOL Modify_BG(int iFloorID,int iHandlehigh,int iHandleLow,const double & dTopBG,const double & dBottomBG);

	BOOL Modify_Info(int iFloorID,int iHandlehigh,int iHandleLow,int comtype,const double & dTopBG,\
		const double & dBottomBG,const LPVOID & pEntInfo,long lEntInfoSize);

	BOOL	DeleteAllKcEntity();

	static PmTString GetSQL(const int iSQLIndex);

	/**
	* @brief  ��mm����Ϊ���ݱ���� ��� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/5/2013]
	*/
	static int Trans2SaveBG(const double & dBG);

	/**
	* @brief �������еı�� ���� ���룬��MM   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/5/2013]
	*/
	static double Trans2OutInfo(int iBG);

	struct PMProjectDBSERVICE SQLInfo
	{
		/// insert into kcentity (floorid , handlelow,handlehigh,comtype,topbg,bottombg,entitydata) values(? , ?,? , ?,? , ?,? , ?) 
		static const int m_iInsertKcEntityInfo;
		static PMTSTRING m_strInsertKcEntityInfo;

		///delete from kcentity where floorid=? and handlelow=? and handlehigh=?
		static const int m_iDelete_KcEntityInfo;
		static PMTSTRING m_strDelete_KcEntityInfo;

		//select * from kcentity where floorid=? and handlelow=? and handlehigh=?
		static const int m_iSelect_KcEntityInfo;
		static PMTSTRING m_strSelect_KcEntityInfo;

		//update kcentity set comtype=? , topbg=? , bottombg=? where floorid=? and handlelow=? and handlehigh=?
		static const int		m_iUpdate_KcEntityInfo_BG;
		static PmTString m_strUpdate_KcEntityInfo_BG;

		//update kcentity set comtype=?,topbg=? , bottombg=? , entitydata=? where floorid=? and handlelow=? and handlehigh=?
		static const int		m_iUpdate_KcEntityInfo_Info;
		static PmTString m_strUpdate_KcEntityInfo_Info;
		
		//update kcentity set comtype=?,topbg=? , bottombg=? , entitydata=? , entitydata3D=? where floorid=? and handlelow=? and handlehigh=?
		static const int		m_iUpdate_KcEntityInfo3D_Info;
		static PmTString m_strUpdate_KcEntityInfo3D_Info;

		//delete from table
		static const int		m_iDelete_AllKcEntityInfo;
		static PmTString	m_strDelete_AllKcEntityInfo;

		//delete from table where floorid=?
		static const int		m_iDelete_FloorKcEntityInfo;
		static PmTString	m_strDelete_FloorKcEntityInfo;

		static const int		m_iReplaceKcEntityInfo;
		static PmTString	m_strReplaceKcEntityInfo;
	};

protected:

	static BOOL TransDataSet2OutInfo(CProject_FloorEntityTable * pKcEntityTable);
};
