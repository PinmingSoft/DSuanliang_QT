#pragma once

//#include "..\accesstable.h"

////////////////////////////////////////////
/// ����ҵ [2013:7:3   11:20]
/// ˵��:
/// ѡ�� ������ ����ʵ��
/// int :��ǰ¥��ID int : ¥��ID double:��ʼ��Ա�ߣ�double:��ֹ��Ա��
typedef BOOL(*SelectRelation_Info_CheckKcEntityInfo)(int,int ,double ,double);

class PMProjectDBSERVICE CProject_KcEntityTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_KcEntityTable)

	CProject_KcEntityTable();
	virtual ~CProject_KcEntityTable();

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

		static const CString bottombg;				//��͵���
		static int			bottombg_Index;

		static const CString entitydata;				//ʵ����Ϣ	
		static int			entitydata_Index;

		static const CString subent;				//��ʵ����Ϣ	
		static int			subent_Index;

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_KcEntityTable : public CPMSLAccessTable
{
public:
	CAccessProject_KcEntityTable(void);
	~CAccessProject_KcEntityTable(void);


	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	/// ��ȡ����������entitydata �ж����Ƴ���
	CProject_KcEntityTable * GetDataSetWithEntityDataSize(CUIntArray & arrEntityDataSize) const;

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
		const double & dBottomBG,const LPVOID & pEntInfo,long lEntInfoSize,const LPVOID & pSubEntInfo,long lSubEntSize);

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
	BOOL SelectInfo(int iFloorID,int ihandlehigh,int ihandlelow,CProject_KcEntityTable *& pKcEntityTable);
	BOOL SelectInfo(int iFloorID,CProject_KcEntityTable *& pKcEntityTable);

	BOOL SelectRelation_Info(int iFloorID,CProject_KcEntityTable *& pKcEntityTable);

	BOOL SelectRelation_Info(int iFloorID,CProject_KcEntityTable *& pKcEntityTable,SelectRelation_Info_CheckKcEntityInfo pCheckFun);

	BOOL Modify_BG(int iFloorID,int iHandlehigh,int iHandleLow,const double & dTopBG,const double & dBottomBG);

	BOOL Modify_Info(int iFloorID,int iHandlehigh,int iHandleLow,const double & dTopBG,\
		const double & dBottomBG,const LPVOID & pEntInfo,long lEntInfoSize,const LPVOID & pSubEntInfo,long lSubEntSize);

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

	struct SQLInfo
	{
		/// insert into kcentity (floorid , handlelow,handlehigh,comtype,topbg,bottombg,entitydata,subent) values(? , ?,? , ?,? , ?,? , ?) 
		static const int m_iInsertKcEntityInfo;
		static PMTSTRING m_strInsertKcEntityInfo;

		///delete from kcentity where floorid=? and handlelow=? and handlehigh=?
		static const int m_iDelete_KcEntityInfo;
		static PMTSTRING m_strDelete_KcEntityInfo;

		//select * from kcentity where floorid=? and handlelow=? and handlehigh=?
		static const int m_iSelect_KcEntityInfo;
		static PMTSTRING m_strSelect_KcEntityInfo;

		//update kcentity set topbg=? , bottombg=? where floorid=? and handlelow=? and handlehigh=?
		static const int		m_iUpdate_KcEntityInfo_BG;
		static PmTString m_strUpdate_KcEntityInfo_BG;

		//update kcentity set topbg=? , bottombg=? , entInfo=?,subEntInfo=? where floorid=? and handlelow=? and handlehigh=?
		static const int		m_iUpdate_KcEntityInfo_Info;
		static PmTString m_strUpdate_KcEntityInfo_Info;
		
		//delete from table
		static const int		m_iDelete_AllKcEntityInfo;
		static PmTString	m_strDelete_AllKcEntityInfo;

		//delete from table where floorid=?
		static const int		m_iDelete_FloorKcEntityInfo;
		static PmTString	m_strDelete_FloorKcEntityInfo;
	};

protected:

	static BOOL TransDataSet2OutInfo(CProject_KcEntityTable * pKcEntityTable);
};
