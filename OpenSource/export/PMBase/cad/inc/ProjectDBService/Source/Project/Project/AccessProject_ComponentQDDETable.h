#pragma once

////#include "..\accesstable.h"

#define QDTable_IndexMode_Add	-1			//���

class PMProjectDBSERVICE CProject_QDDE_XMTZTable : public CSQLDataSet
{
public:
	CProject_QDDE_XMTZTable();
	virtual ~CProject_QDDE_XMTZTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString	id;
		static int				id_Index;

		static const CString	qdid;
		static int				qdid_Index;

		static const CString	parmdisplayname;
		static int				parmdisplayname_Index;

		static const CString	parmvalue ;
		static int				parmvalue_Index;

		static const CString	require;
		static int				require_Index;

		static const CString	output1 ;
		static int				output1_Index;
	};

	virtual int InitFieldStr();

};

class PMProjectDBSERVICE CProject_QDDE_InfoTable : public CSQLDataSet
{
public:
	CProject_QDDE_InfoTable();
	virtual ~CProject_QDDE_InfoTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString	id;
		static int				id_Index;

		static const CString	deid;			/* �嵥��������Ŀ¼����		
													������Ŀ(eItem) ����  Ϊ��
													�嵥 (eQd) ��ʾ �嵥id
													�Ӽ�����Ŀ  ��ʾ ��
													�����( eDe )���ʱ�� ����id 
												*/
		static int				deid_Index;

		static const CString	dename;			/* �嵥����������		
													������Ŀ(eItem) ����  Ϊ��
													�嵥 (eQd) ��ʾ �嵥����
													�Ӽ�����Ŀ  ��ʾ ��
													�����( eDe )���ʱ�� ��������
												*/
		static int				dename_Index;

		static const CString	unit;			//��λ							5
		static int				unit_Index;

		static const CString	quantity;		//�������						6
		static int				quantity_Index;

		static const CString	sections;		//�����ߴ�						7
		static int				sections_Index;

		static const CString	formulas;	//���������㹫ʽ				8
		static int				formulas_Index;

		static const CString	editmode;				//���浱ǰ�е��޸����
		static int				editmode_Index;

		static const CString	nodeid; /// �嵥���߼�id\���� ( �嵥���е�NodeID )
		static int				nodeid_Index;
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CProject_QDDE_ComIdTable : public CSQLDataSet
{
public:
	CProject_QDDE_ComIdTable();
	virtual ~CProject_QDDE_ComIdTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString	id;
		static int				id_Index;

		static const CString	comid;
		static int				comid_Index;

		static const CString	sortqdid;
		static int				sortqdid_Index;

		static const CString	rowtype;		/// �е�����
		static int				rowtype_Index;

		static const CString	name;
		static int				name_Index;

		static const CString	decalcode;				/* ���������� ����������ʹ��ʲô���㷽ʽ
													*/
		static int				decalcode_Index;

	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_ComponentQDDETable : public CPMSLAccessTable
{
public:
	CAccessProject_ComponentQDDETable(void);
	CAccessProject_ComponentQDDETable(BOOL bTemplateDb);
	virtual ~CAccessProject_ComponentQDDETable(void);

public:
	
	/// 
	CSQLDataSet * GetDataSetQdde();
	CSQLDataSet * GetEmptyDataSetQdde();

	/// 
	CSQLDataSet * GetDataSetQddeInfo();
	CSQLDataSet * GetEmptyDataSetInfo();

	/// 
	CSQLDataSet * GetDataSetXmtz();
	CSQLDataSet * GetEmptyDataSetXmtz();

	BOOL		GetTableCtrlQdde( const int iComId , CPMSQLTableCtrl *& pSqlTableCtrl  ) ;
	BOOL		GetTableCtrlQddeInfo( const int iId , CPMSQLTableCtrl *& pSqlTableCtrl  ) ;
	BOOL		GetTableCtrlQddeXmtz( const int iId , CPMSQLTableCtrl *& pSqlTableCtrl  ) ;



	/// 
	int			GetMaxIdQdde() ; 

	/// 
	int			GetMaxIdXmtz() ; 

	virtual BOOL TryUpdateTableField();

	/**
	* @brief ��ȡ�嵥 ���� ������Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/6/2013]
	*/
	BOOL GetQDDE_DataInfo(int iComID,CProject_QDDE_DataInfo *& pQDDE_DataInfo);
	void GetQDDE_DataInfo(std::map<int, CProject_QDDE_DataInfo*> & qdde_infos);

	//��ȡ��ȡ���嵥����Ĺ���comid������ȡ����д�� setComIdHasQDDE
	BOOL GetComIdHasQDDE(int comtype,std::set<int> & setComIdHasQdde);
	BOOL GetComidHasQDDEForComtypeList(const CUIntArray & comtypes,std::set<int> &setComIdHasQDDE);
	//�ж�ĳЩcomid�Ƿ���ȡ���嵥�������ȡ����д�� setComIdHasQDDE
	BOOL GetComidHasQDDEForComidList(const CUIntArray & arrComId,std::set<int> & setComIdHasQDDE);

	BOOL SetComID_NewQDDEDataSet(int iComID,CProject_QDDE_UITable * pQDDETable);

	BOOL SetComID_NewQDDEDataSet(const CUIntArray & arrComID,CProject_QDDE_UITable * pQDDETable);
	BOOL SetComID_NewQDDEDataSet(const CUIntArray & iFromComIDArray,const CUIntArray & i2ComIDArray,
		std::map<int, CProject_QDDE_UITable*> & mapQDDETables);
	
	// ���Ӻ�����һ���׶������滻�嵥��������ʱ��ʹ��
	BOOL SetComID_NewQDDEDataSet(int iComID,CProject_QDDE_UITable * pQDDETable, bool isNeedReplceDe, int iRow, CString strDEName);
	BOOL UpdateComID_QDDEDataSet(int iComID,CProject_QDDE_UITable * pQDDETable);

	BOOL GetComID_QDDEDataSet(int iComID,CProject_QDDE_UITable *& pQDDETable);
	BOOL GetComID_QDDEDataSet(std::map<int, CProject_QDDE_UITable*> & mapQDDETables);
	

	/**
	* @brief ��ȡ�����嵥 �����������Ϣ
	*
	*          
	* @note  : qc: 28202 ������˳��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: lbw
	* @date  : [19/4/2019]
	*/
	void GetComID_QDDEDataSet_Room(CUIntArray &iComIDArray, CProject_QDDE_UITable *& pQDDETableRoom, CUIntArray &iFJSOrderArray);
	/**
	* @brief �Է������ݽ�������
	*
	*          
	* @note  : qc: 28202 ������˳��
	* @param : iSize��Ϊ�˽����������ǽ�棬ש��ǽ���������ǽ�������
	* @defenc: 
	* @return: 
	* @author: lbw
	* @date  : [19/4/2019]
	*/
	void SortQdDe(NDataModelDataSet * pQdde, int & iSize);

	BOOL Delete_QDDEDataSet(int iComID);
	BOOL Delete_QDDEDataSet(const CUIntArray & iComID);
	
	//������ȡ�����嵥����
	BOOL GetAllQDDE_DataInfo(std::map<int, CProject_QDDE_DataInfo*> & qdde_infos);

	void Clear_QDDETable();

	struct PMProjectDBSERVICE TableInfo
	{
		static const CString m_Project_QDDE_XMTZTableName;
		static const CString m_Project_QDDE_InfoTableName;
		static const CString m_Project_QDDE_ComIDTableName;
	};

	static PmTString GetSQL(const int iSQLIndex);

	struct PMProjectDBSERVICE SQLInfo
	{
		///insert into compoent_QDDE_ComId (id,comid,sortqdid,rowtype,name) values (?,?,?,?,?)
		static const int m_iInsert_Component_QDDE_ComID ;
		static PMTSTRING m_strInsert_Component_QDDE_ComID ;

		/// insert into component_QDDE_info(id,deid,dename,decode,unit,quantity,sections,formulas,editmode,nodeid) values (?,?,?,?,?,?,?,?,?,?)
		static const int	m_iInsert_Component_QDDE_Info ;
		static PmTString	m_strInsert_Component_QDDE_Info ;

		// insert into component_qdde_xmtz (id,qdid,parmdisplayname,parmvalue,require,output1) values(?,?,?,?,?,?)
		static const int	m_iInsert_Component_QDDE_XMTZ ;
		static PmTString	m_strInsert_Component_QDDE_XMTZ ;

		//update compoent_QDDE_ComId set sortqdid=?, rowtype=?, name=? ,decalcode=? where id=?
		static const int	m_iMdf_Component_QDDE_ComID;
		static PmTString	m_strMdf_Component_QDDE_ComID;

		//update component_QDDE_info set deid=? , dename=?, unit=?,quantity=?,
		//			sections=?,formulas=?,editmode=?,nodeid=? where id=?
		static const int	m_iMdf_Component_QDDE_Info;
		static PmTString	m_strMdf_Component_QDDE_Info;

		//update component_QDDE_XMTZ set qdid=?,parmdisplayname=?,parmvalue=?,\
		//			require=?,output1=? where id=?
		static const int	m_iMdf_Component_QDDE_XMTZ;
		static PmTString	m_strMdf_Component_QDDE_XMTZ;

		///delete from component_QDDE_comid where id=?
		static const int	m_iDelete_Component_QDDE_ComID;
		static PmTString	m_strDelete_Component_QDDE_ComID;

		///delete from component_QDDE_info where id=?
		static const int	m_iDelete_Component_QDDE_Info;
		static PmTString	m_strDelete_Component_QDDE_Info;

		//delete from component_QDDE_xmtz where id=?
		static const int	m_iDelete_Component_QDDE_XMTZ;
		static PmTString	m_strDelete_Component_QDDE_XMTZ;

		//delete from component_QDDE_xmtz where qdid=?
		static const int	m_iDelete_Component_QDDE_XMTZ_QDID;
		static PmTString	m_strDelete_Component_QDDE_XMTZ_QDID;

		//select * from component_QDDE_comid where comid=? order by sortqdid 
		static const int	m_iSelect_Component_QDDE_ComID;
		static PmTString	m_strSelect_Component_QDDE_ComID;

		//select * from component_QDDE_comid order by comid, sortqdid 
		static const int	m_iSelect_Component_QDDE_ComID_All;
		static PmTString	m_strSelect_Component_QDDE_ComID_All;


		//select * from component_QDDE_info where id=?
		static const int	m_iSelect_Component_QDDE_Info_id;
		static PmTString	m_strSelect_Component_QDDE_Info_id;

		//select * from component_QDDE_XMTZ where qdid=?
		static const int	m_iSelect_Component_QDDE_XMTZ_qdid;
		static PmTString	m_strSelect_Component_QDDE_XMTZ_qdid;

		//delete from component_QDDE_comid where comid in (?)
		static const int	m_iDelete_Component_QDDE_ComID_Array;
		static PmTString	m_strDelete_Component_QDDE_ComID_Array;

		//delete from component_QDDE_info where id in(select id from Component_QDDE_ComID where comid in (?))
		static const int	m_iDelete_Component_QDDE_Info_Array;
		static PmTString	m_strDelete_Component_QDDE_Info_Array;

		//delete from component_QDDE_xmtz where qdid in(select id from Component_QDDE_ComID where comid in (?))
		static const int	m_iDelete_Component_QDDE_XMTZ_QDID_Array;
		static PmTString	m_strDelete_Component_QDDE_XMTZ_QDID_Array;
	};

protected:

	BOOL InsertQDInfo(BOOL bQDMode,int iComID,int iInsertRow,CProject_QDDE_UITable * pQDDEDataSet,\
		int & iMaxQDComTableID ,int & iMaxQDInfoTableID ,int & iMaxQDXMTZTableID);

	BOOL InsertQDInfo_ComID(BOOL bQDMode,int iInsertRow,int iComID,\
		CProject_QDDE_UITable * pQDDEDataSet,int iMaxQDComTableID);

	BOOL InsertQDInfo_XMTZ(int iInsertRow,int iComID,CProject_QDDE_UITable * pQDDEDataSet,\
		int iQDComIDTableID,int & iMaxQDXMTZTableID);

	BOOL InsertQDInfo_Info(int iInsertRow,int iComID,CProject_QDDE_UITable *pQDDEDataSet,\
		int iMaxQDComTableID, int iMaxQDInfoTableID);

	BOOL MdfQDInfo(BOOL bQDMode,int iComID,int iMdfRow,CProject_QDDE_UITable * pQDDEDataSet,\
		int & iMaxQDXMTZTableID);

	BOOL MdfQDInfo_ComID(BOOL bQDMode,int iMdfRow,CProject_QDDE_UITable * pQDDEDataSet);

	BOOL MdfQDInfo_Info(int iMdfRow,int iComID,CProject_QDDE_UITable *pQDDEDataSet);

	BOOL DeleteQDInfo_ComID(int iQDID);

	BOOL DeleteQDInfo_XMTZ(int iQDID);

	BOOL DeleteQDInfo_Info(int iQDInfoID);

	BOOL GetQDDEDataSet_Info(int iInsertRow,CProject_QDDE_UITable * pQDDEDataSet,int iQDComIDTableID);
	BOOL GetQDDEDataSet_Info(std::map<int, CProject_QDDE_UITable *> & mapQDDEDataSet);

	BOOL GetQDDEDataInfo_Info(CProject_QDDE_DataInfo::CProject_QDDE_RowInfo * pQDDERowInfo,int iQDComIDTableID);

	BOOL GetQDDEDataSet_XMTZ(int iInsertRow,CProject_QDDE_UITable * pQDDEDataSet,int iQDComIDTableID);
	BOOL GetQDDEDataSet_XMTZ(std::map<int, CProject_QDDE_UITable *> & mapQDDEDataSet);
};

//////////////////////////////////////////////////////////////////////////
//

class PMProjectDBSERVICE CProject_QDDE_HandleTable : public CSQLDataSet
{
public:
	CProject_QDDE_HandleTable();
	virtual ~CProject_QDDE_HandleTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString	id;
		static int				id_Index;

		static const CString	comid;
		static int				comid_Index;

		static const CString	handle;
		static int				handle_Index;

		static const CString	sortqdid;
		static int				sortqdid_Index;

		static const CString	rowtype;		/// �е�����
		static int				rowtype_Index;

		static const CString	name;
		static int				name_Index;

		static const CString	decalcode;				/* ���������� ����������ʹ��ʲô���㷽ʽ
													*/
		static int				decalcode_Index;

	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_ComponentQDDE_Handle : public CPMSLAccessTable
{
public:
	CAccessProject_ComponentQDDE_Handle(void);
	virtual ~CAccessProject_ComponentQDDE_Handle(void);

	virtual BOOL TryUpdateTableField();

	/// 
	CSQLDataSet * GetDataSetQdde();
	CSQLDataSet * GetEmptyDataSetQdde();

	/// 
	CSQLDataSet * GetDataSetQddeInfo();
	CSQLDataSet * GetEmptyDataSetInfo();

	/// 
	CSQLDataSet * GetDataSetXmtz();
	CSQLDataSet * GetEmptyDataSetXmtz();

	/// 
	/// 
	/// ר�ýӿ�
	/// 
	BOOL		GetTableCtrl( const int iFloorId ,  CPMSQLTableCtrl *& pTableCtrl ) ;

	/// 
	BOOL		Delete( const CUIntArray & aryQddeId ) ;

	/// 
	/// ��ȡ���ظ��� comid + handle 
	/// 
	BOOL		GetDistinctComIdHandle( CPMSQLTableCtrl *& pTableCtrl ) ;

	/// 
	/// ��ȡ��ͬcomid�²��ظ���handle 
	/// 
	BOOL GetDistinctHandleByComId(int iComId, CStringArray &aryHandle);

	/// 
	BOOL		GetTableCtrlQdde( const int iComId , CPMSQLTableCtrl *& pSqlTableCtrl  ) ;
	BOOL		GetTableCtrlQddeInfo( const int iId , CPMSQLTableCtrl *& pSqlTableCtrl  ) ;
	BOOL		GetTableCtrlQddeXmtz( const int iId , CPMSQLTableCtrl *& pSqlTableCtrl  ) ;

	void Clear_QDDETable();

	BOOL SetComID_NewQDDEDataSet(int iComID,const CString & strHandle,CProject_QDDE_UITable * pQDDETable);

	BOOL UpdataComID_QDDEDataSet(int iComID,const CString & strHandle,CProject_QDDE_UITable * pQDDETable);

	BOOL GetComID_QDDEDataSet(int iComID,const CString & strHandle,CProject_QDDE_UITable *& pQDDETable);

	BOOL Delete_QDDEDataSet(int iComID,const CString & strHandle);

	BOOL Delete_QDDEDataSet(int iComID);

	BOOL Delete_QDDEDataSet(const CUIntArray & iComID);

	BOOL GetQDDE_DataInfo(int iComID,const CString & strHandle,CProject_QDDE_DataInfo *& pQDDE_DataInfo);
	/// ��MAP�ǿգ��ǰ������Ѿ����ú�ȥʵ�ֵġ�
	void GetQDDE_DataInfo(std::map<std::pair<int, CString>, CProject_QDDE_DataInfo*> & qdde_infos);

	struct TableInfo
	{
		static const CString m_Project_QDDE_XMTZTableName;
		static const CString m_Project_QDDE_InfoTableName;
		static const CString m_Project_QDDE_HandleTableName;
	};

	static PmTString GetSQL(const int iSQLIndex);

	struct PMProjectDBSERVICE  SQLInfo
	{
		///insert into compoent_QDDE_handle (id,comid,handle,sortqdid,rowtype,name) values (?,?,?,?,?,?)
		static const int m_iInsert_Component_QDDE_Handle ;
		static PMTSTRING m_strInsert_Component_QDDE_Handle ;

		/// insert into component_QDDE_info(id,deid,dename,decode,unit,quantity,sections,formulas,editmode,nodeid) values (?,?,?,?,?,?,?,?,?,?)
		static const int	m_iInsert_Component_QDDE_Info ;
		static PmTString	m_strInsert_Component_QDDE_Info ;

		// insert into component_qdde_xmtz (id,qdid,parmdisplayname,parmvalue,require,output1) values(?,?,?,?,?,?)
		static const int	m_iInsert_Component_QDDE_XMTZ ;
		static PmTString	m_strInsert_Component_QDDE_XMTZ ;

		//update compoent_QDDE_Handle set sortqdid=?, rowtype=?, name=? ,decalcode=? where id=? and handle=?
		static const int	m_iMdf_Component_QDDE_Handle;
		static PmTString	m_strMdf_Component_QDDE_Handle;

		//update component_QDDE_info set deid=? , dename=?, unit=?,quantity=?,
		//			sections=?,formulas=?,editmode=?,nodeid=? where id=?
		static const int	m_iMdf_Component_QDDE_Info;
		static PmTString	m_strMdf_Component_QDDE_Info;

		//update component_QDDE_XMTZ set qdid=?,parmdisplayname=?,parmvalue=?,\
		//			require=?,output1=? where id=?
		static const int	m_iMdf_Component_QDDE_XMTZ;
		static PmTString	m_strMdf_Component_QDDE_XMTZ;

		///delete from component_QDDE_id where id=?
		static const int	m_iDelete_Component_QDDE_ID;
		static PmTString	m_strDelete_Component_QDDE_ID;

		///delete from component_QDDE_comid where comid=? and handle=?
		static const int	m_iDelete_Component_QDDE_Handle;
		static PmTString	m_strDelete_Component_QDDE_Handle;

		///delete from component_QDDE_info where id=?
		static const int	m_iDelete_Component_QDDE_Info;
		static PmTString	m_strDelete_Component_QDDE_Info;

		//delete from component_QDDE_xmtz where id=?
		static const int	m_iDelete_Component_QDDE_XMTZ;
		static PmTString	m_strDelete_Component_QDDE_XMTZ;

		//delete from component_QDDE_xmtz where qdid=?
		static const int	m_iDelete_Component_QDDE_XMTZ_QDID;
		static PmTString	m_strDelete_Component_QDDE_XMTZ_QDID;

		//select * from component_QDDE_comid where comid=? and handleid=? order by sortqdid 
		static const int	m_iSelect_Component_QDDE_Handle;
		static PmTString	m_strSelect_Component_QDDE_Handle;

		//select * from component_QDDE_comid where comid=? order by sortqdid 
		static const int	m_iSelect_Component_QDDE_ComID;
		static PmTString	m_strSelect_Component_QDDE_ComID;

		//select * from component_QDDE_info where id=?
		static const int	m_iSelect_Component_QDDE_Info_id;
		static PmTString	m_strSelect_Component_QDDE_Info_id;

		//select * from component_QDDE_XMTZ where qdid=?
		static const int	m_iSelect_Component_QDDE_XMTZ_qdid;
		static PmTString	m_strSelect_Component_QDDE_XMTZ_qdid;

		//select * from component_QDDE_comid order by sortqdid 
		static const int	m_iSelect_Component_QDDE_AllHandle;
		static PmTString	m_strSelect_Component_QDDE_AllHandle;
	};

protected:

	BOOL GetQDDEDataInfo_Info(CProject_QDDE_DataInfo::CProject_QDDE_RowInfo * pQDDERowInfo,int iQDComIDTableID);

	BOOL InsertQDInfo(BOOL bQDMode,int iComID,const CString & strHandle,int iInsertRow,CProject_QDDE_UITable * pQDDEDataSet,\
		int & iMaxQDComTableID ,int & iMaxQDInfoTableID ,int & iMaxQDXMTZTableID);

	BOOL InsertQDInfo_ComID(BOOL bQDMode,int iInsertRow,int iComID,const CString & strHandle,\
		CProject_QDDE_UITable * pQDDEDataSet,int iMaxQDComTableID);

	BOOL InsertQDInfo_XMTZ(int iInsertRow,int iComID,CProject_QDDE_UITable * pQDDEDataSet,\
		int iQDComIDTableID,int & iMaxQDXMTZTableID);

	BOOL InsertQDInfo_Info(int iInsertRow,int iComID,CProject_QDDE_UITable *pQDDEDataSet,\
		int iMaxQDComTableID, int iMaxQDInfoTableID);

	BOOL MdfQDInfo(BOOL bQDMode,int iComID,int iMdfRow,CProject_QDDE_UITable * pQDDEDataSet,\
		int & iMaxQDXMTZTableID);

	BOOL MdfQDInfo_ComID(BOOL bQDMode,int iMdfRow,CProject_QDDE_UITable * pQDDEDataSet);

	BOOL MdfQDInfo_Info(int iMdfRow,int iComID,CProject_QDDE_UITable *pQDDEDataSet);

	BOOL DeleteQDInfo_ComID(int iQDID);

	BOOL DeleteQDInfo_XMTZ(int iQDID);

	BOOL DeleteQDInfo_Info(int iQDInfoID);

	BOOL GetQDDEDataSet_Info(int iInsertRow,CProject_QDDE_UITable * pQDDEDataSet,int iQDComIDTableID);

	BOOL GetQDDEDataSet_XMTZ(int iInsertRow,CProject_QDDE_UITable * pQDDEDataSet,int iQDComIDTableID);
};