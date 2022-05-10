#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_Components_GJTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_Components_GJTable)

	CProject_Components_GJTable();
	virtual ~CProject_Components_GJTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					
		static const CString comname;				//��������	
		static const CString floorid;				//¥��ID
		static const CString folderid;			//������ID
		static const CString comtype;				//�������	
		static const CString volume;				//�˹���������
		static const CString comparms;			//��������
		static const CString inputdata;			//ƽ���������
		static const CString showid;				
		static const CString sumvolume;		

		static int id_Idx ;					
		static int comname_Idx ;				//��������	
		static int floorid_Idx ;				//¥��ID
		static int folderid_Idx ;			//������ID
		static int comtype_Idx ;				//�������	
		static int volume_Idx ;				//�˹���������
		static int comparms_Idx ;			//��������
		static int inputdata_Idx ;			//ƽ���������
		static int showid_Idx ;				
		static int sumvolume_Idx ;		

		/// idx �����ĸ�������
		/// idx ��Ҫ�ں��� InitFieldStr �� ����ʼ��Ϊ�������ֵ
		/// �Ҹ�ֵ��˳��Ӧ�ú� InitFieldStr����ӵ�˳��һ��
		static int idx_step ; 
	};

	struct PMProjectDBSERVICE CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_Components_GJTable :
	public CPMSLAccessTable
{
	typedef enum EComSortMode 
	{
		csm_Null     = 0,
		csm_ID       = 1,			//��ID������
		csm_ShowID   = csm_ID << 1,	//��showid������
		csm_FloorID  = csm_ID << 2,	//��FloorID������
		csm_FolderID = csm_ID << 3  //��FolderID������
	}ComSortMode;	

	typedef CArray<EComSortMode, EComSortMode> ComSortModeArr;

public:
	CAccessProject_Components_GJTable(void);

	virtual ~CAccessProject_Components_GJTable(void);

	void ModifyOneRow(int iComID,int iNewFloorID, const CString & strNewFoldID);

	int CopyOneRow(int nComID,int iFloorID, CString strFoldID);

	/// 
	BOOL GetMaxComId( int & iMaxComId ) ;

	/**
	* @brief  ��ȡ ָ�� ¥�� ������ ��Ӧ�� ComID 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [23/7/2012]
	*/
	void GetComID(const CUIntArray &arr_floor, 
		const CUIntArray &arr_comfolder, 
		CUIntArray &arr_comid );
	/**
	 * @brief ��ȡȫ����ComID
	 *
	 *        
	 * @author ֣����
	 * @version v1.0
	 * @date  2016��1��29��   19:02
	 * @note  
	 */
	void GetComID( CUIntArray &arr_comid );

	/**
	* @brief  ��ComID ��ȡ ��Ӧ�� ��¼��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [20/7/2012]
	*/
	BOOL GetTableCtrl_ComID(int iComID,CPMSQLTableCtrl *& pSQLTableCtrl);

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

	/// 
	void				DelOwnCom( const int iComId ) ;
	void				DelOwnCom( const CUIntArray & aryComId );
	void				DelOneFloor( const int iFloor);
	//�ڹ����б��в���һ��ָ�����Ĺ���
	int					Insert( const int comType);
	int					Insert( const int iFloorID,const CString & strFoldID, const CString & ComName, const int & iComType, const int iVolume ,const int iSumVolume);
	
	/**
	* @brief   ��ȡ DataSet
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/6/2012]
	*/
	BOOL GetDataSet_FloorComType(int iFloorID,int iComType,CSQLDataSet *& pComponentDataSet);

	/**
	* @brief   ��ȡ�汾��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-3]
	*/
	static	int	GetCurVersion() ;

	/**
	* @brief   ��ȡ��������ݣ����Ƽ�ʹ�ã�
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-12]
	*/
	NDataModelDataSet * GetDataSet() ; 


	////////////////////////////////////////////////////////////////
	/// at 2011��1��24��  18:32  by yxy
	/// ��Ϊ��̬���� 
	//ȡ�ù����������DataSet ����Ϊ������𣬱���������һ���յĿ��
	static NDataModelDataSet * GetInputDataSetByType(int comType);//���ص�ָ����Ҫdelete

	/// ��ȡ����Ĳ�����DataSet 
	static NDataModelDataSet * GetComParmsDataSet() ; 

	//ȡ���������ݵ�DataSet ������½��Ĺ����������Ȳ���һ����¼�Ժ����ȡ��
	NDataModelDataSet * GetInputDataSet(const int iComId );//���ص�ָ����Ҫdelete
	//ȡ�ü�������ֵ����ʽΪ DataSet���ݼ�
	NDataModelDataSet * GetCalResultDataSet(const int iComId );//���ص�ָ����Ҫdelete
	//ȡ�ô洢�ؼ����ò�����Ϣ�ı�
	NDataModelDataSet * GetComParmsDataSet(const int iComId );//���ص�ָ����Ҫdelete
//	CParms *             GetComponentParms(const int iComId );
	//�����������ݼ�����¼
	void				SetInputDataSet(const int iComId , NDataModelDataSet *pDataSet);
	//�������뵽������ļ�¼
	void				SetCalResultDataSet(const int iComId , NDataModelDataSet *pDataSet);
	//�������뵽�ؼ�������Ϣ�ļ�¼
	void				SetComParmsDataSet(const int iComId , NDataModelDataSet *pDataSet);

	//���� showid
	BOOL				SetShowID(const int iComId,int iShowID);

	//���� comname
	BOOL				SetComName(const int iComId,const CString & strComName);

	//���� comVolume
	BOOL				SetComVolume(const int iComId,float fComVolume);

	//���� comSumVolume
	BOOL				SetComSumVolume(const int iComId,float fComSumVolume);

	/// ����comtype
	BOOL				SetComType( const int iComId , const int iComType ) ; 

	/// ����ComFolder
	BOOL				SetComFolder( const int iComId , const int iComFolderId ) ;

	/// 
	BOOL			SetComParms( const int iComId , const LPVOID pBuffer , const LONG lSize ) ;
	BOOL			SetInputData( const int iComId , const LPVOID pBuffer , const LONG lSize ) ;

private:

	BOOL				GetComParms(const int iComId ,LPVOID & pBuffer,LONG & lSize);
	BOOL				GetInputData(const int iComId ,LPVOID & pBuffer,LONG & lSize);


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
	BOOL			GetTable_MaxID(int & iMaxID);

public:

	//ȡ�ù������
	int					GetComType( const int iComID );
	int					GetFloorID(const int iComID );
	int					GetComSumVolume(const int iComID );	
/// ��ϸ�Ķ��ϵĴ��뷢�־��ǻ�ȡ�������ƣ��������Σ�ʹ��GetComName ����
///	CString				GetComFoldName(const int iComID );
	CString				GetComVolume(const int iComID );
	CString				GetComName(const int iComID );
	CString				GetComFolderID(const int iComID );

	/**
	* @brief  ͨ������ ��ȡ DataSet 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [20/7/2012]
	*/
	NDataModelDataSet * GetDataSet(const CStringArray &strFieldArr, const CStringArray & strValueArr);

	/// ����ComID ��ȡDataset
	NDataModelDataSet * GetDataSet( const int iComId ) ; 

	/**
	* @brief  ��ȡ���� ��¼�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [20/7/2012]
	*/
	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetRowCount( int & iRowCount ) ;
	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;

private:

	/// ��ȡ�е�����
	CString			GetColAsString( const int iComId ,const CString & strColName ) ;
	
	/// 
	int				GetColAsInterger( const int iComId , const CString & strColName ) ;

	/// 
	BOOL			GetColAsBlob( const int iComId , const CString & strColName , LPVOID & pBuffer,LONG & lSize ) ;


	BOOL	SetColValue( const int iComId , const CString & strColName , const CString & strColValue ) ;


public:
	//�̶���SQL ����
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetDataSet1 ;
		static PMTSTRING m_strGetDataSet1 ; 

		/// 
		static const int m_iSetComParms ;
		static PMTSTRING m_strSetComParms ; 

		/// 
		static const int m_iInputData ;
		static PMTSTRING m_strInputData ; 

		/// 
		static const int m_iDelOwnCom ;
		static PMTSTRING m_strDelOwnCom ; 

		/// 
		static const int m_iDelOneFloor ;
		static PMTSTRING m_strDelOneFloor ; 

		/// 
		static const int m_iInsert ; 
		static PMTSTRING m_strInsert ; 

		/// 
		static const int m_iUpdateShowID_ComID ; 
		static PMTSTRING m_strUpdateShowID_ComID ; 

		/// 
		static const int m_iUpdateComName_ComID ; 
		static PMTSTRING m_strUpdateComName_ComID ; 

		/// 
		static const int m_iUpdateVolume_ComID ; 
		static PMTSTRING m_strUpdateVolume_ComID ;

		/// 
		static const int m_iUpdateSumVolume_ComID ; 
		static PMTSTRING m_strUpdateSumVolume_ComID ;

		/// 
		static const int m_iSetColValue ;
		static PMTSTRING m_strSetColValue ; 
	} ;
};


/**
* @brief   ��װһЩ��ʱ����Ķ������ (�䵱 ����Access�� ������)
*
*          
* @note  : ����Ҫÿһ���õ��ĵط���ȥ����һ����ʱ���� �� ��һЩ�������͵�ת�������ڸ�����ʵ��
*
* @author: ����ҫ
* @date  : [2012-7-17]
*/

class PMProjectDBSERVICE CProjectComponentsGjOpr
{
public:
	CProjectComponentsGjOpr() ;
	~CProjectComponentsGjOpr() ;

public:
	static int					GetComType( const int iComID );
	static int					GetFloorID(const int iComID );
	static int					GetComSumVolume(const int iComID );	
	static CString				GetComVolume(const int iComID );
	static CString				GetComName(const int iComID );
	static CString				GetComFolderID(const int iComID );
	static CString				GetComFoldName(const int iComID );

	//ȡ���������ݵ�DataSet ������½��Ĺ����������Ȳ���һ����¼�Ժ����ȡ��
	static NDataModelDataSet * GetInputDataSet(const int iComId );//���ص�ָ����Ҫdelete
	//ȡ�ü�������ֵ����ʽΪ DataSet���ݼ�
	static NDataModelDataSet * GetCalResultDataSet(const int iComId );//���ص�ָ����Ҫdelete
	//ȡ�ô洢�ؼ����ò�����Ϣ�ı�
	static NDataModelDataSet * GetComParmsDataSet(const int iComId );//���ص�ָ����Ҫdelete
//	static CParms *             GetComponentParms(const int iComId );
	//�����������ݼ�����¼
	static void				SetInputDataSet(const int iComId , NDataModelDataSet *pDataSet);
	//�������뵽������ļ�¼
	static void				SetCalResultDataSet(const int iComId , NDataModelDataSet *pDataSet);
	//�������뵽�ؼ�������Ϣ�ļ�¼
	static void				SetComParmsDataSet(const int iComId , NDataModelDataSet *pDataSet);

	static void				DelOwnCom( const int iComId ) ;
	static void				DelOwnCom( const CUIntArray & aryComId );
	static void				DelOneFloor( const int iFloor);
	//�ڹ����б��в���һ��ָ�����Ĺ���
	static int					Insert( const int comType);
	static int					Insert( const int iFloorID,const CString & strFoldID, const CString & ComName, const int & iComType, const int iVolume ,const int iSumVolume);

	static BOOL GetRowCount( int & iRowCount ) ;

	static NDataModelDataSet * GetDataSet(const CStringArray &strFieldArr, const CStringArray & strValueArr) ;
	static NDataModelDataSet * GetDataSet() ; 


	/// ����comtype
	static BOOL				SetComType( const int iComId , const int iComType ) ; 

	/// ����ComFolder
	static BOOL				SetComFolder( const int iComId , const int iComFolderId ) ;

	//���� comname
	static BOOL				SetComName(const int iComId,const CString & strComName);


};
