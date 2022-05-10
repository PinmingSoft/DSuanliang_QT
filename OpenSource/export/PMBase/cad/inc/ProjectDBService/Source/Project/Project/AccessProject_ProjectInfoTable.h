#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_ProjectInfoTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ProjectInfoTable)

	CProject_ProjectInfoTable();
	virtual ~CProject_ProjectInfoTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					//���
		static const CString parmtype;			//������ʾ
		static const CString parmname;			//��������
		static const CString disparmname;			//������ʾ����
		static const CString parmvalue;			//����ֵ
		static const CString inputmode;			//����ģʽ
		static const CString datatype;			//ֵ����
		static const CString listdata;			//ֵ�б�
		static const CString checkreg;				//��ʽ������ʽ

		static const CString table_name;			//����
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_ProjectInfoTable:
	public CPMSLAccessTable
{
public:
	CAccessProject_ProjectInfoTable(void);
	CAccessProject_ProjectInfoTable(BOOL bTemplate);
	virtual ~CAccessProject_ProjectInfoTable(void);

	//ʵ�����ֶ�
	static const CString kParm_SWLRule;

	/**
	* @brief   ���� ������ṹ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/6/2012]
	*/
	virtual BOOL TryUpdateTableField();

	/**
	* @brief  ��ȡ�������� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [20/7/2012]
	*/
	CString GetProjectName();

	/**
	* @brief  ��ȡ������ ָ���������� ��Ӧֵ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	BOOL GetProjectInfo_ParmValue(const CString & strParmName,CString & strParmValue);
	BOOL GetProjectInfo_ParmValueList(const CString & strParmName,CString & strParmValue,CString & strParmList);

	//��ȡ �û� �嵥 ���� ��Ϣ
	BOOL GetDefaultValueOfQDDE(BOOL &bQDMode,CString &strQDName,CString &strDEName);
	BOOL GetDefaultValueOfQDDE(CString &strQDName,
		CString &strDEName, CString &strDEDataList,
		CString &strCalRuleOfQD,CString &strCalRuleDataListOfQD,
		CString &strCalRuleOfDE,CString &strCalRuleDataListOfDE,
		CString &strCalRuleOfSWL);

	BOOL SetUserValueOfQDDE(BOOL bQDMode,const CString &strQDName,
		const CString &strDEName, const CString &strDEDataList,
		const CString &strCalRuleOfQD,const CString &strCalRuleDataListOfQD,
		const CString &strCalRuleOfDE,const CString &strCalRuleDataListOfDE,
		const CString &strCalRuleOfSWL);

	//���� ʵ�������� ��Ϣ
	BOOL SetUserValueOfSWLRule(const CString &strCalRuleOfSWL);

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	//��ȡ ������Ϣ DataSet
	CSQLDataSet * GetGcxxDataSet();

	//ͨ�� PramType ��ȡ DataSet
	CSQLDataSet * GetDataSet(CUIntArray & iParmTypeArr);

	///
	CSQLDataSet * GetGctzDataSet() ;

	/**
	* @brief �� ָ���������� ��Ӧֵ ���õ�����  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	BOOL SetProjectInfo_ParmValue(const CString & strParmName,const CString & strParmValue);

	/// 
	BOOL	SetProjectInfo_ListData( const CString & strParmName , const CString & strListData ) ;

	/**
	* @brief ��ȡ��ǰ��Ŀ�� �ֽ�ģʽ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	BOOL GetProject_GangJinMode(ProjectInfoMacro::GangJinMode & gangJinMode);

	//��ȡ ������Ƶ�ƺ���(m)(SWSJDPBG)
	BOOL GetProjectSWSJDPBG(CString &strSWSJDPBG);

	//�Ų���
	CString	GetMCL(); 
	
	//������
	CString	GetCCL(); 

	//¥�������
	CString	GetLDMCL();
	
	//ǽ��������
	CString	GetJCCL(); 
	
	/// ��ǽװ�β���
	CString	GetNQZSCL();

	//��ǽ��װ�β���
	CString	GetWQZSCL(); 

	//����װ�β���
	CString	GetZMZSCL(); 

	//����װ�β���
	CString	GetTPZSCL(); 

	//ש��������
	CString	GetZJCCL(); 

	//שĤ����
	CString	GetZMCL(); 

	//����ǽ���ϣ������ң�
	CString	GetDNQCL(); 
	
	//����װ�β���
	CString GetLZSCL();

	//������ǽ����
	CString	GetWQCL();

	//������ǽ����
	CString	GetNQCL(); 

	//�ϵ�����
	CString	GetSDCCL(); 

	//�е�����
	CString	GetZDCCL();

	//�µ�����
	CString	GetXDCCL();

	//ģ������
	CString	GetMBLX();

	//���˲���
	CString	GetLGCL();

	//�Ű��Ҫ��
	CString GetTBHYQ();

	//�������
	CString	GetTRLB();

	//����ӿ�����ʽ
	CString	GetKWTFS();

	//�Ӳۿ�����ʽ
	CString	GetWTFS();

	//��������
	CString GetYTJL();

	BOOL GetQbg(CString &strDisplayName , CString &strValue );

	BOOL SetQbg(const CString & strValue) ;

	///����׼�߶�(mm)
	BOOL GetZbg(CString &strDisplayName , CString &strValue ); 
	BOOL SetZbg(const CString & strValue) ;

	///����׼�߶�(mm)
	BOOL GetLbg(CString &strDisplayName , CString &strValue ) ;
	BOOL SetLbg(CString strValue) ;

	///���׼�߶�(mm)
	BOOL GetBbg(CString &strDisplayName , CString &strValue ) ;
	BOOL SetBbg(CString strValue) ;

	///����(m)
	BOOL GetCd(CString &strDisplayName , CString &strValue ) ;
	BOOL SetCd(CString strValue) ;

	///���(m3)
	BOOL GetTj(CString &strDisplayName , CString &strValue ) ;
	BOOL SetTj(CString strValue) ;

	///���(m2)
	BOOL GetMj(CString &strDisplayName , CString &strValue ) ;
	BOOL SetMj(CString strValue) ;

	//����(t)
	BOOL GetZl(CString &strDisplayName , CString &strValue ) ;
	BOOL SetZl(CString strValue);


	///����ˮλ
	BOOL GetDxsw(CString & strValue , CString &strReg ) ;
	BOOL SetDxsw(CString strValue ) ;

	///������Ƶ�ƺ���(m) 
	BOOL GetSwsjdpbg( CString &strValue , CString &strReg ) ;
	BOOL SetSwsjdpbg(CString strValue );

	///��Ȼ��Ƶ�ƺ���(m)ZRSJDPBG
	BOOL GetZrsjdpbg( CString &strValue , CString &strReg ) ;
	BOOL SetZrsjdpbg(CString  strValue ) ;

	///¥���������ʽ
	BOOL GetListMode(CString &strValue , CString& strListData ) ;
	BOOL SetListMode(CString strValue ) ;

	///�Ƿ�ʹ�õ���ˮλ
	BOOL GetDxswMode(CString &strValue , CString &strListData ) ;
	BOOL SetDxswMode(CString strValue ) ;

	//���ù��̵�����
	void SetProjectName( const CString & strGCMC );
	//���ñ�������
	void SetProjecBZRQ( const CString & strBZRQ );

	/// ������������ɫ
	CString	GetColorOfLockGj() ;
	void	SetColorOfLockGj( const CString & strColorOfLockGj ) ; 

	/// �ֽ�������ʾ����
	CString	GetInvisibleColumns() ; 
	void	SetInvisibleColumns( const CString & strInvisibleColumns ) ;

	/**
	* @brief  ��ȡ ��Ŀ �������������� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	BOOL GetProjectDERuleFileName(CString &strDERuleFileName);

	/**
	* @brief  ��ȡ ���� ������ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	BOOL GetProjectDEBaseName(CString &strDEBaseName);

	/**
	* @brief  ��ȡ �嵥���� ���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	BOOL GetProjectQDRuleFileName(CString &strQDRuleFileName);

	/**
	* @brief ��ȡ �嵥�� ����  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	BOOL GetProjectQDBaseName(CString & strQDBaseName);

	/**
	* @brief  ��ȡ �嵥ģʽ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/7/2012]
	*/
	BOOL GetProjectQDMode(BOOL &bQDMode);

	/**
	* @brief  ��ȡ ʵ�����������
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [13/9/2017]
	*/
	BOOL GetProjectSwlRuleFileName(CString &strSwlRuleFileName);


	/// 
	BOOL GetColorOfAxis(CString &strColorOfAxis) ;

	void SetColorOfAxis( const CString & strColorOfAxis ) ;
	/// ֧ģ��ʽ������ֵ
	BOOL					GetZmfs()  ; 

	/// ͳ�ƽ�������
	BOOL					GetTjjzcg() ; 

	BOOL	GetCgsz( CString & strCgsz ) ;

	/// ��ȡʩ�������
	void GetSGDLB(CString &strSGDLB);
	void GetSGDLB(CStringArray & arrSGDName);
	/// ����ʩ�������
	BOOL SetSGDLB(const CString &strSGDLB);
	BOOL SetSGDLB(const CStringArray & arrSGDName);

	/******************************************************************** 
	������������ȡ�����е���Ȼ��ƺ��
	������
	�� �� ֵ��
	�㷨��
	ע�������λ mm
	��    �ߣ�����ҵ
	ʱ    �䣺[27/3/2008]
	*********************************************************************/ 
	BOOL GetProjectZRDPG(double & dHeight);

	/// �е�����ʱ�����л���0�㡣����TRUE��ʾ�����л���0��
	BOOL GetProject_NoChange0Floor();
	void GetProject_NoChange0Floor_ParmValueList(CString & strParmValue,CString & strListData);
	void SetProject_NoChange0Floor(BOOL bNoChange0Floor);

	/**
	* @brief  �жϵ�ǰ�����Ƿ� ������ 
	*
	*          
	* @note  : ���û�����¥��ɾ��������ɾ�� �����������仯
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [15/7/2013]
	*/
	BOOL CheckProject_HasAxis();
	BOOL GetProject_FirstAxisFloorID(int & iFloorID);
	void SetProject_FirstAxisFloorID(int iFloorID);

	/// ��ȡ ָ������ ��Ӧ�� ��¼��
	BOOL GetTableCtrl_ParmName(const CString & strParmName,CPMSQLTableCtrl *& pSQLTableCtrl);

	//��ȡ��projectinfo �� ��� id�ֶ� ���޳�100000�ֶ�
	int GetMaxId(NDataModelDataSet * pProjectInfoDataSet) const;

	static PmTString GetSQL(const int iSQLIndex);

	static const int nParmType_Tfdy ;  /// ��������
	static const int nParmType_Clsz ;  /// ��������
	static const int nParmType_Zmsz ;  /// ֧ģ����

	static const double dSnbg_Init  ; /// ���ڱ�߳�ʼֵ

public:

	struct SQLInfo
	{
		static const PmTString m_strSelect_ParmValueSQL;//��ȡ����ֵ�� sql
		static const PmTString m_strUpdate_ParmValueSQL;//���ò���ֵ�� sql

		static const int m_iSelectAllInfo_ParmNameSQL;
		static const PmTString m_strSelectAllInfo_ParmNameSQL;//ͨ�������� ��ȡ������Ϣ �� sql
	};
};


/**
* @brief   ��װһЩ��ʱ����Ķ������
*
*          
* @note  : ����Ҫÿһ���õ��ĵط���ȥ����һ����ʱ���� �� ��һЩ�������͵�ת�������ڸ�����ʵ��
*
* @author: ����ҫ
* @date  : [2012-7-17]
*/

class PMProjectDBSERVICE CProjectInfoOpr
{
public:
	CProjectInfoOpr();
	~CProjectInfoOpr() ; 

public:
	static BOOL GetColorOfAxis(CString &strColorOfAxis) ;

	static  CString GetProjectName();
	
	static  BOOL GetProjectZRDPG(double & dHeight) ;

	static  BOOL GetProjectDXSW( double & dDxsw ) ;

	static  BOOL GetProjectSWSJDPBG(CString &strSWSJDPBG);

	static  BOOL GetProjectQDMode(BOOL &bQDMode);

	//���ù��̵�����
	static  void SetProjectName( const CString & strGCMC );
	//���ñ�������
	static  void SetProjecBZRQ( const CString & strBZRQ );

	static  int  GetGangJinMode() ; 

	static  BOOL GetZmfs() ;

	static	BOOL	GetCgsz( CString & strCgsz ) ;

	static  BOOL	 GetTjjzcg()  ;


	/// ������������ɫ
	static CString	GetColorOfLockGj() ;
	static void	SetColorOfLockGj( const CString & strColorOfLockGj ) ; 

	/// �ֽ�������ʾ����
	static CString	GetInvisibleColumns() ; 
	static void	SetInvisibleColumns( const CString & strInvisibleColumns ) ;

};

/**
 * @brief ����comid�� ������ ��
���е�ҵ��ģ��� comid������������
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2015��5��12��]
 * @note  
 */
class PMProjectDBSERVICE CPmBimComIdOpr 
{
private:
	CPmBimComIdOpr() ; 

public:
	virtual ~CPmBimComIdOpr();
	static CPmBimComIdOpr & Instance() ; 

	enum eSpecialComid
	{
		eCustomComID = SpecComID-1,
	};
public:

	/**
	* @brief   ���ص� MaxComId �Ѿ������� 1 �����治��Ҫ��ȥ++
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2015��5��12��]
	*/
	int		GetMaxComId() ; 

	/// 
	void	SetMaxComId( const int iMaxComId ) ; 


	/**
	* @brief �� MaxComId ���浽  ProjectInfo  �У� id �̶�Ϊ 100000  
	*		 ������ʱ�Զ��½�һ����¼
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2015��5��12��]
	*/
	void	SaveMaxComId() ; 


	/// 
	void	InitMaxComId() ; 

protected:
	/// 
	BOOL	HasMaxComId() ; 

	/// 
	void	InsertMaxComId() ; 

protected:
	int		m_iMaxComId ; 

	CString		m_strMaxComIdName ;

};

#define PmBimComIdOpr CPmBimComIdOpr::Instance()
