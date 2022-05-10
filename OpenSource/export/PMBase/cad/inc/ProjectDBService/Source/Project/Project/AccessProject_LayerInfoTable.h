#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_LayerInfoTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_LayerInfoTable)

	CProject_LayerInfoTable();
	virtual ~CProject_LayerInfoTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;						//���
		static const CString floorid;					//¥��ID
		static const CString comtype;					//�������
		static const CString layer;					//������
		static const CString color;					//����ɫ
		static const CString showindex;				//����˳��
		static const CString showcolor;				//��ά��ʾ��ɫ
		static const CString layerinfo;				//����ʾ��Ϣ
		static const CString alllayername;			//���в���
		static const CString showsize;				//��ʾ��С
		static const CString controlmode;				//����ģʽ 1 ���Ʋ� 0 �����Ʋ�

		static const CString table_name;				//ͼ���
	};

	virtual int InitFieldStr();
};


class PMProjectDBSERVICE CAccessProject_LayerInfoTable :
	public CPMSLAccessTable
{
public:

	class PMProjectDBSERVICE CLayerInfo
	{
	public:
		CString m_strLayerInfo;
		int m_iComType;

	public:
		CLayerInfo()
		{
			m_iComType = -1 ; 
		}

		CLayerInfo( const CLayerInfo & other )
		{
			m_iComType = other.m_iComType ; 
			m_strLayerInfo = other.m_strLayerInfo ; 
		}

		~CLayerInfo()
		{

		}
	};

	/// 
	typedef std::map<CString ,CLayerInfo > PmStr2LayerInfoMap ; 
	typedef PmStr2LayerInfoMap::iterator PmStr2LayerInfoMapIter ; 
	typedef PmStr2LayerInfoMap::const_iterator PmStr2LayerInfoMapConIter ; 

	CAccessProject_LayerInfoTable(void);
	virtual ~CAccessProject_LayerInfoTable(void);

	virtual BOOL TryUpdateTableField();

	/// ������������
	virtual BOOL TryUpdateTableContent() ; 

	/**
	* @brief  ��ȡ��ά�� ����
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL Get3DLayerName(int iComType,CString & strLayerName);

	/**
	* @brief  ��ȡ��ȡ ��Ҫ��ʾ ComType�� ����
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL GetComTypeShowSizeArr(int iFloorID,CArray<int,int&> & iNeedShowComTypeArr);

	BOOL SetComTypeShowSize(int iFloorID, int iComType, BOOL bNeedShow);

	/**
	* @brief  ��ȡָ����� ��Ϣ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL GetLayerInfo(CString strLayerName,CAccessProject_LayerInfoTable::CLayerInfo & layerinfo);
	void GetLayerInfo(std::map<CString, CAccessProject_LayerInfoTable::CLayerInfo *> & layerInfos, const int floorId = -1000 );
	
	/// 
	BOOL GetLayerInfo( CAccessProject_LayerInfoTable::PmStr2LayerInfoMap & mapLayerName2Info , const int iFloorId = -1000 ) ; 

	/**
	* @brief  ��ȡָ���� ������ ����Ҫɾ�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	CSQLDataSet * GetFloorID_DataSet(int iFloorID);

	//��ȡ ¥��ID �� ��¼��
	BOOL GetTableCtrl_FloorID(int iFloorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief ��ȡ ���� IDֵ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL GetTable_MaxID(int & iMaxID);

	/**
	* @brief  ��ȡͼ����Ϣ 
	*
	*          
	* @note  : 
	* @param : int iComType:��������
	*			CString &strLayerName����������
	*			int &iColor����ά��ɫ
	*			int &iLayerInfo������Ϣ
	*			CString &strAllLayerName������ͼ������
	*			int &iControlMode����������
	*			int iFloorID����ȡ�Ĳ�ID��-1000��ȡ��ǰ�㣩
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	BOOL GetLayerInfo(int iComType, CString &strLayerName, int &iColor, int &iLayerInfo, CString &strAllLayerName, int &iControlMode,int iFloorID = TemFloor);

	////////////////////////////////////////////////////////////////
	/// at 2011��3��30��  14:38  by yxy
	/******************************************************************** 
	�ú�����ȡ һ�������µ����в���Ϣ �� 100 �µ����� 101,102,103 DL Ϊ�������д
	*********************************************************************/ 
	BOOL	GetLayerNameDL( const int  nFloorID , const int nComTypeDL , CStringArray & aryLayerName ) ; 

	BOOL	GetLayerName( const int iComType,CString & strLayerName,int iFloorID = TemFloor );

	/******************************************************************** 
	������������ȡ������ʾ��Ϣ
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[25/12/2007]
	*********************************************************************/ 
	BOOL GetGJShowInfo(  const int iComType, int & iLayerInfo, int iFloorID = TemFloor);

	BOOL SetGJShowInfo(  const int iComType, int iLayerInfo, int iFloorID = TemFloor);

	/**
	* @brief   ����ͼ�����ɫ,
	*
	*          
	* @note  : 
	* @param : pDataSet ��Ҫ������ comtype �� color�ֶ�
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-8-2]
	*/
	void	SetLayerColor( NDataModelDataSet * pDataSet ) ;

	void	SetLayerColor( const int iComType , const int iColor ) ;

	void	SetLayerShowColor( const int iComType , const int iShowColor ) ;

	/**
	* @brief ��� ͼ������ �Ƿ� ��Ʒ����
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL CheckLayer(const CString & strLayerName);

	BOOL GetTableCtrl_FloorComType(int iFloorID,int iComType,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief ��ȡ��ά ͼ�� ��ɫ
	*
	*          
	* @note  : 
	* @param :
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL GetShowColor(int iComType, int & iShowColor,int iFloorID = TemFloor);

	/**
	* @brief ��ȡ��ά ͼ�� ��ɫ
	*
	*          
	* @note  : 
	* @param :
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL Get3DColor( const int iComId , int & iShowColor ) ;

	/**
	* @brief ��ȡ��ά ͼ�� ��ɫ
	*
	*          
	* @note  : 
	* @param : iFloorID ���� ָ��
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL Get2DColor( const int iComType ,const int iFloorID,int & iColor);

	/**
	* @brief ��ȡ��ά ͼ�� ��ɫ
	*
	*          
	* @note  : 
	* @param : iFloorID ���� ָ��
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL Get3DColor( const int iComType ,const int iFloorID,int & iColor);

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	BOOL GetRowCount( int & iRowCount ) ;

	static PmTString GetSQL(const int iSQLIndex);

protected:
	BOOL	UpdateColor_ComType( const int iComType , const int iColor ) ;
	
	BOOL	UpdateShowColor_ComType( const int iComType , const int iShowColor ) ;

public:

	struct SQLInfo
	{
		static const int			m_iSelectLayerInfo_FloorComTypeSql;
		static const PmTString		m_strSelectLayerInfo_FloorComTypeSql;//ͨ��¥��ID comType ��ȡ���е�ͼ����Ϣ

		static const int			m_iGetLayerNameDL ;
		static const PMTSTRING		m_strGetLayerNameDL ;					/// ͨ��  nFloorID , nComTypeDL ��ȡͼ������

		static const int			m_iGetLayerName ;
		static const PMTSTRING		m_strGetLayerName ;						/// ͨ��  nFloorID , nComType  ��ȡͼ������

		static const int			m_iGetGjShowInfo ;
		static const PMTSTRING		m_strGetGjShowInfo ;					/// ��ȡ������ʾ��Ϣ 

		static const int			m_iSelectComType_LayerName;
		static const PMTSTRING		m_strSelectComType_LayerName;			//ͨ����ȡcomtype 

		static const int			m_iSelectAllInfo_FloorIDSql;
		static const PMTSTRING		m_strSelectAllInfo_FloorIDSql;

		//update LayerInfo set LayerInfo=? where floorid=? and comtype=? 
		static const int			m_iUpdateLayerInfo_FloorComTypeSql;
		static const PMTSTRING		m_strUpdateLayerInfo_FloorComTypeSql; //ͨ�� nFloorID nComType ���� LayerInfo(��ʾ״̬)

		/// 
		static const int			m_iUpdateColor_ComType ;
		static PMTSTRING			m_strUpdateColor_ComType ; 

		/// 
		static const int			m_iUpdateShowColor_ComType ; 
		static PMTSTRING			m_strUpdateShowColor_ComType ; 

		static const int			m_iSelectComType_LayerName_All;
		static const PMTSTRING		m_strSelectComType_LayerName_All;
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

class PMProjectDBSERVICE CProjectLayerInfoOpr
{
public:
	static CProjectLayerInfoOpr * GetInstance()
	{
		if (NULL == m_pInstance)
		{
			m_pInstance = PMNew(CProjectLayerInfoOpr);
		}
		return m_pInstance;
	}
	static void Release(){PMDelete(m_pInstance);}

	//ͼ����Ϣ
	class PMProjectDBSERVICE CGJLayerInfo
	{
	public:

		CGJLayerInfo();
		virtual ~CGJLayerInfo();

		int m_iComType;				//��������
		CString m_str2dLayerName;	//��άͼ������
		CString m_str3dLayerName;	//��άͼ������
		std::set<CString> m_setLayerAll;	//����ͼ��----��Ҫ�����������ж��ͼ��

		int m_i2DColor;				//��άͼ����ɫ
		int m_i3DColor;				//��άͼ����ɫ

		int m_nLayerInfo;			//layerInfo�ֶ�
	};

public:
	//��ȡ layerInfo��Ϣ
	BOOL	GetLayerInfo( const int iComType, int & iLayerInfo,  const int iFloorID = TemFloor) const;

	//��ȡ ��άͼ������
	BOOL	GetLayerName( const int iComType, CString & strLayerName, int iFloorID = TemFloor ) const;
	//��ȡ ��άͼ������
	BOOL	Get3DLayerName( const int iComType, CString & strLayerName, int iFloorID = TemFloor ) const;
	//��ȡ ��άͼ����ɫ
	BOOL	GetLayerColor( const int iComType, int & color, int iFloorID = TemFloor) const;
	//��ȡ ��άͼ����ɫ
	BOOL	Get3DLayerColor( const int iComType, int & color, int iFloorID = TemFloor) const;
	//ͨ��ͼ���������Ҷ�Ӧ��ͼ����Ϣ
	BOOL	GetLayerComtype(const CString & strLayerName,int & layerComtype) const;

	// ��ȡcomtype ��ͼ������ƥ��
	void	GetLayerName(std::map<int,CString> & mapComtype2LayerName) const;

	// ��ȡcomtype ��3Dͼ������ƥ��
	void	Get3DLayerName(std::map<int,CString> & mapComtype2LayerName) const;

	// ���ͼ���Ƿ����
	BOOL	CheckLayer(const CString & strLayerName) const;

	// ������������ͼ����ɫ��Ϣ
	void	SetLayerColor( NDataModelDataSet * pDataSet ) ;

	//���ö�άͼ����ɫ
	void	SetLayerColor( const int iComType , const int iColor ) ;

	// ������άͼ����ɫ
	void	SetLayerShowColor( const int iComType , const int iShowColor ) ;

	//���¶�ȡ����ͼ����Ϣ
	void LoadLayerAll();

protected:
	//���Һ����ͼ�㣬����Ҳ��������� TemFloor Ĭ��ͼ����Ϣ
	const CProjectLayerInfoOpr::CGJLayerInfo * FindLayerWithDefault(const int iComType, const int iFloorID) const;

	//����layerInfo����
	const CProjectLayerInfoOpr::CGJLayerInfo * CProjectLayerInfoOpr::FindLayer(const int iComType, const int iFloorID) const;
	CProjectLayerInfoOpr::CGJLayerInfo * CProjectLayerInfoOpr::FindLayer(const int iComType, const int iFloorID) ;

	//��ȡ����ֵfloorid)*10000
	int GetKey(int floorid,int comtype) const
	{
		return 10000*(floorid>0?floorid:-floorid)+comtype;
	}
	//ͨ����ֵ��ȡfloorid��comtype
	void GetFloorId(int nKey,int & floorid,int & comtype) const
	{
		floorid=nKey/10000;
		comtype=nKey%10000;
		floorid=(floorid==-TemFloor?TemFloor:floorid);
	}

private:
	static CProjectLayerInfoOpr * m_pInstance;

	//����¥��洢��ͼ������
	std::map<int ,CGJLayerInfo*> m_mapLayerInfoFloor;

	//-1000��¥��洢��ͼ������
	std::map<int ,CGJLayerInfo *> m_mapLayerInfoBase;

	//
	CProjectLayerInfoOpr() ;
	~CProjectLayerInfoOpr() ; 
};

class PMProjectDBSERVICE CProject_CheckLayerCache
{
public:
	CProject_CheckLayerCache();
	virtual ~CProject_CheckLayerCache();

	/**
	* @brief ��ȡ ͼ����Ϣ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL GetLayerInfo(const CString strLayerInfo,CAccessProject_LayerInfoTable::CLayerInfo & temLayerInfo);

protected:
	typedef std::map<CString,CAccessProject_LayerInfoTable::CLayerInfo *> LayerNameMapLayerInfo_T;
	LayerNameMapLayerInfo_T m_MapLayerInfo;
};