#pragma once
////#include "..\accesstable.h"


class PMProjectDBSERVICE CProject_QDDE_XMAttTable : public CPM_StorageDataSet  
{
public:
	DECLARE_DYNCREATE(CProject_QDDE_XMAttTable)

	CProject_QDDE_XMAttTable();
	virtual ~CProject_QDDE_XMAttTable();
	virtual int InitFieldStr();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString ID ;
		static const CString QDNumber ;
		static const CString parmdisplayname ;
		static const CString ParmValue ;
		static const CString ListData ;
		static const CString CheckReg ;
		static const CString InputMode ;
		static const CString Output1 ; 
	};

	
};

class PMProjectDBSERVICE CProject_QDDE_FJCCTable : public CPM_StorageDataSet  
{
public:
	DECLARE_DYNCREATE(CProject_QDDE_FJCCTable)

	CProject_QDDE_FJCCTable();
	virtual ~CProject_QDDE_FJCCTable();
	virtual int InitFieldStr();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id ;
		static const CString ComType ;
		static const CString parmdisplayname ;
		static const CString ParmValue ;
		static const CString ListData ;
		static const CString InputMode ;
		static const CString CheckReg ;
	};
};

class PMProjectDBSERVICE CProject_ComponentsTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ComponentsTable)

	CProject_ComponentsTable();
	virtual ~CProject_ComponentsTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					
		static const CString comname;					
		static const CString floorid;				
		static const CString comtype;				
		static const CString volume;					//�˹���������
		static const CString comparms;				//��������
		static const CString qddedata;					//�嵥����
		static const CString vectorparms;				//���ͼ����
		static const CString showid;				
		static const CString bz;						//����
		static const CString editmode;				//�Ƿ��޸�
		static const CString publicGj;				//��������
//		static const CString inputdataset;			//ƽ���������

		static const CString table_name;				//����
	};

	struct PMProjectDBSERVICE CTableData
	{
		/// êͷ����ʹ�õ�һЩ����
		static const CString strJxmtfs ; /// ��еêͷ��ʽ

		static const CString strYcthmj ; /// ĩ��һ������ê��
		static const CString strYcthmj_Zhu ;
		static const CString strYcthmj_Liang ; 

		static const CString strLcthmj ; /// ĩ����������ê��
		static const CString strLcthmj_Zhu ;
		static const CString strLcthmj_Liang ; 

		static const CString strGbcksh ; /// ĩ����ְ崩������
		static const CString strGbcksh_Zhu ;
		static const CString strGbcksh_Liang ; 

		static const CString strDlsmt ; /// ĩ�˴���˨êͷ
		static const CString strDlsmt_Zhu ;
		static const CString strDlsmt_Liang ; 

	};

	virtual BOOL GetCreateIndexSQL(CStringArray & strFieldNameArr,CString & strIndexName);

	virtual int InitFieldStr();
};


class PMProjectDBSERVICE CAccessProject_ComponentsTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_ComponentsTable(void);

	//bTemplateDb ��ʾ�Ƿ���ģ�����ݿ�
	CAccessProject_ComponentsTable(BOOL bTemplateDb);

public:
	virtual ~CAccessProject_ComponentsTable(void);

	/**
	* @brief   �������Ƶĺ����Լ��,������TRUE����������FALSE
	*
	*			Ŀǰ ������� �ַ�Ϊ ; | \ /
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [5/28/2020]
	*/
	static BOOL CheckComName(CString componentName,CString & errorInfo);

	/**
	* @brief   ��ȡ����Ĺ������ƣ�������ֲ������ַ��������滻Ϊ replaceSymbol���������ͺ����ͷ��ر���
	*
	*			Ŀǰ ������� �ַ�Ϊ ; | \ /
	* @note  : 
	* @param : 
	* @return: ���غ�������ƣ��������ͺ����ͷ��ر���
	* @author: zfy
	* @date  : [5/28/2020]
	*/
	static CString GetCorrentComName(CString componentName,CString replaceSymbol=_T("_"));

	/**
	* @brief ��ȡ �������� �б�  
	*
	*          
	* @note  : �����ʽ ComName\ComID;ComName\ComID;
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [18/7/2012]
	*/
	CString GetComsListData(int nFloorID,int nComType);

	/**
	* @brief ��ȡ �������� �б�  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [18/7/2012]
	*/
	BOOL GetComsListData(int nFloorID,int nComType,CUIntArray & iComIDArr,CStringArray & strComNameArr);

	/**
	* @brief   ��ȡ����ncomtype ��comid��comName
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/9/2016]
	*/
	BOOL GetComsListData(int nComType,CUIntArray & iComIDArr,CStringArray & strComNameArr);

	/**
	* @brief   �ж�ĳ��comid�Ƿ��ǹ�������
	*
	*			ʧ��Ҳ��Ϊ�Ƿǹ�������
	* @note  : 
	* @param : 
	* @return: TRUE : ����������FALSE���ǹ�������
	* @author: zfy
	* @date  : [8/14/2018]
	*/
	BOOL IsPublicGj(int iComID);

	/**
	* @brief   ����Ϊ��������
	*
	*			
	* @note  : 
	* @param : bPublicGj ΪTRUE,������Ϊ����������ΪFALSE,��ȡ����������
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/14/2018]
	*/
	BOOL SetPublicGj(int comid,BOOL bPublicGj);
	BOOL SetPublicGj(int comtype,CString comname,BOOL bPublicGj);
	BOOL SetPublicGj(const CUIntArray & arrComid,BOOL bPublicGj);

	/**
	* @brief   ��ȡĳ������ĳ�����Ƶ����в�Ĺ�������comid
	*
	*			
	* @note  : 
	* @param : nComType ��ʾ�ù�����������
	* @param : gjName ��ʾ�ù�����������
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/13/2018]
	*/
	BOOL GetPublicGj(int nComType,CString gjName,CUIntArray & iComIDArr);

	/**
	* @brief   ��ȡ���в�Ĺ�������comid,comtype,comname
	*
	*			
	* @note  : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/13/2018]
	*/
	BOOL GetPublicGj(CUIntArray & iComIDArr,CUIntArray & iComtypeArr,CStringArray & arrName);

	/**
	* @brief ͨ�� ComType  ���� ��ȡ ComIDArr 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [25/7/2012]
	*/
	BOOL GetComIDArr_ComTypeArr(CUIntArray & iComTypeArr,CUIntArray & iComIDArr);

	/**
	* @brief ���빹��  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [10/7/2012]
	*/
	BOOL InsertGJ(int iComType,int iFloorID,const CString & strComName,int & iNewComID);

	/**
	* @brief ����һ������  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: ���� ComID
	* @author: ����ҵ
	* @date  : [25/7/2012]
	*/
	int CopyRow(int iComID,int iComType,int iFloorID,CString & strComName);

	BOOL SaveDataSet(NDataModelDataSet *pDataSet, int iFloorID, int iComType);

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);


	/**
	* @brief  ��ȡFloorGJXX�� ���ݣ�DataSet��Ҫɾ�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [10/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	/**
	* @brief   ��comtype������ȡ���ݣ���Ҫ������״�ؼ���ʾ��
	*
	*			��Ϊ ��ǽ��שǽʱ������ʾ0ǽ
	*			��Ϊ ��������ʱ������ʾ �����ҷ�Χ
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [5/12/2020]
	*/
	CSQLDataSet * GetDataSetForGrid_ComtypeDL(int floorid,int comtypeDL);

	/**
	* @brief   ��comtypeС����ȡ���ݣ���Ҫ������״�ؼ���ʾ��
	*
	*			��Ϊ ��ǽ��שǽʱ������ʾ0ǽ
	*			��Ϊ ��������ʱ������ʾ �����ҷ�Χ
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [5/12/2020]
	*/
	CSQLDataSet * GetDataSetForGrid_Comtype(int floorid,int comtypeXL);

	/**
	* @brief  ��ȡ ָ��¥�� ָ��ComType ��Ӧ�� ComID���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [23/7/2012]
	*/
	BOOL GetComponent_ComIDArr(const CUIntArray & arr_floor ,const CUIntArray & arr_comtype ,CUIntArray & iComIDArr);

	BOOL GetComponentMapComidToComType(std::map<int,int> & mapComidToComType);

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
	* @brief ��ȡ �����Ļ�����Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/7/2012]
	*/
	BOOL GetComponentsBaseInfo(int iComID,int & iComType,int & iFloorID,CString & strComName,BOOL & bPublicGj,CString & strBz);
	BOOL GetAllComBaseInfo(CUIntArray & iComIDArr
		,CUIntArray & iComtypeArr
		,CUIntArray & iFlooridArr
		,CStringArray & arrName
		,CUIntArray & arrPublicGj
		,CStringArray & arrBz
		,CArray<CProject_VectorParmsTable *> & arrVectorParm);

	/**
	* @brief ��ȡ ������ buffer��Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/7/2012]
	*/
	BOOL GetComParmBuffer_Table(int iComID,CPMSQLTableCtrl *& pTableCtrl);

	BOOL SetComParmBuffer(int iComID,LPVOID pComParmBuffer,long lComParmBuffer);

	/**
	* @brief  ��ȡ���ͼDataSet��Ϣ 
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	BOOL GetVectorParmDataSet(int iComID,CProject_VectorParmsTable *& pVectorDataSet);
	/// MAP�ǿգ���������ȫ�����ú�ȥʵ�ֵ�
	void GetVectorParmDataSet(std::map<int, CProject_VectorParmsTable *>& vector_datasets);

	/**
	* @brief  ��ȡ���ͼDataSet ָ���� Value
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	BOOL GetVectorParmValue(int iComID,const CString & strParmName,CString & strParmValue);
	 
	/**
	* @brief  �������ͼ Buffer��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	BOOL SetVectorParm_Buffer(int iComID,void * pVectorParmBuffer,long lVectorParmBufferSize);

	/**
	* @brief  ��ȡSQL��� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	static PmTString GetSQL(const int iSQLIndex);

	/**
	* @brief   ��ȡָ���� ������ ����Ҫɾ�� 
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

	BOOL GetTable_MaxID(int & iMaxID);

	/**
	* @brief ɾ��ָ��¥��� ���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL DelComponentInfo_Floor(int iFloorID);

	/**
	* @brief ��ȡ���й����� ID ����   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL GetAllComIDArr(CUIntArray & iComIDArr);

	/**
	* @brief   ��ȡ����comtype
	*
	*			���޳��ظ�����û������
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [10/9/2018]
	*/
	BOOL GetAllComtypeArr(CUIntArray & iComtypeArr);

	/**
	* @brief  ���ع������� ���� ���ݣ���¼�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [12/7/2012]
	*/
	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	/******************************************************************** 
	 ����������ͨ�����������ҹ���ID
	 ������strComName����������iComType���������ͣ�iComID�����صĹ���ID��iFloorID��¥����
	 �� �� ֵ���Ƿ�ɹ�
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[28/1/2008]
	*********************************************************************/ 
	BOOL FindComponent_ComName(const CString & strComName, int iComType, int &iComID, int iFloorID);

	/**
	* @brief  ��ȡ ָ����ComID�� DataSet 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [14/7/2012]
	*/
	BOOL GetDataSet_ComID(int iComID,CSQLDataSet *& pComponentDataSet);

	/**
	* @brief  ��ȡ ָ����ComID�� ��¼�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [14/7/2012]
	*/
	BOOL GetTableCtrl_ComID(int iComID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief  ��ȡ ���� ��ע
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [14/7/2012]
	*/
	BOOL GetComponentBz(int iComID,CString & strBz);

	/**
	* @brief  ���� ���� ��ע
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [14/7/2012]
	*/
	BOOL SetComponentBz(int iComID,const CString & strBz);

	BOOL	GetShowId( const int iComId , int & iShowId ) ;
	int		GetShowId( const int iComId ) ;

	/**
	* @brief  ��ȡ DataSet
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [14/7/2012]
	*/
	BOOL GetDataSet_FloorComType(int iFloorID,int iComType,CSQLDataSet *& pComponentDataSet);

	/**
	* @brief ��ȡ  ¥��/�������� �еĵ�һ�������� 
	*
	*          
	* @note  : 
	* @param : iComId �ҵ��˷����ҵ���comid ��û�ҵ�����-1
	* @defenc: 
	* @return: û���ҵ���������FALSE. �ҵ��˷���TRUE
	* @author: ����ҫ
	* @date  : [2014��3��19��]
	*/
	BOOL GetComIdFloorComType( const int iFloorId , const int iComType , int & iComId ) ;
	/**
	* @brief ��ȡ ָ��FloorID ComType ,�¶�Ӧ�� ComName �б�  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/7/2012]
	*/
	BOOL GetComNameArr_FloorComType(int iFloorID,int iComType,CStringArray & strComNameArr);

	/**
	* @brief ��ȡ ָ��FloorID ComType ,�¶�Ӧ�ļ�¼��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/7/2012]
	*/
	BOOL GetTableCtrl_FloorComType(int iFloorID,int iComType,CPMSQLTableCtrl *& pComponentTableCtrl);

	BOOL GetTableCtrl_ComTypeArr(const CUIntArray & iComTypeArr,CPMSQLTableCtrl *& pComponentTableCtrl);

	/**
	* @brief   ��ȡ��������
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/14/2018]
	*/
	BOOL GetTableCtrl_PublicGj(CPMSQLTableCtrl *& pComponentTableCtrl);
	BOOL GetTableCtrl_PublicGj(const CUIntArray & iComTypeArr
		,CString gjName
		,CPMSQLTableCtrl *& pComponentTableCtrl);

	/**
	* @brief �ж� ��ǰ ¥�� �Ƿ��� ������Ƶ� ����
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/7/2012]
	*/

	BOOL HasSameName_Floor( const int iFloorID,const CString & strComName);

	BOOL HasSameName_Floor_ComType( const int iFloorId , const int iComType ,const CString & strComName);

	/**
	* @brief  ��ȡ �嵥 ����� DataSet
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [14/7/2012]
	*/
	BOOL GetQDDEDataSet(int iComID,NDataModelDataSet *& pQDDEDataSet);

	BOOL SetQDDEDataSet(int iComID,NDataModelDataSet * pQDDEDataSet);

	/**
	* @brief ɾ��ʱֻ�ǽ�comid��Ϣ�ƶ���componentsdel��
	*
	*        
	* @author hn
	* @version v1.0
	* @date  9/27/2016
	* @note  
	*/
	BOOL DelComponent_IDNew(int iComID);
	BOOL DelComponent_IDArrNew(const CUIntArray & iComIDArr);

	BOOL DelComponent_ID(int iComID);
	BOOL DelComponent_IDArr(const CUIntArray & iComIDArr);


	//��ȡ ��ͬ���� DataSet
	NDataModelDataSet * GetSameNameDataSet();

	BOOL GetRowCount( int & iRowCount ) ;

	/**
	* @brief   ��ȡ��еê�̵���ʽ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-8-20]
	*/
	BOOL	GetJxmgXs( const int iComId , CString & strJxmgxs ) ;

	BOOL	GetJxMgVectorId( const int iComId , CString & strVectorId ) ; 

	/**
		* @brief ��ȡ���ظ��Ĺ�������
		*
		*          
		* @note  : 
		* @param : 
		* @defenc: 
		* @return: 
		* @author: ����ҫ
		* @date  : 2013��8��2��   15:57
	*/
	BOOL	GetComType( CUIntArray & aryComType ) ; 
	
	
	//����ָ����������
	BOOL	SetComType( int iComID, int iComType );
	/**
	* @brief   ��ȡ��еê�̵ĳ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-8-20]
	*/
	BOOL	GetJxmgLen( const int iComId , CString & strJxmgLen ) ;
	/**
	* @brief ��ɾ���ļ�¼��copy��compoentsdel���б��棬Ȼ��ɾ��componentsdel������Ϣ
	*
	*        
	* @author hn
	* @version v1.0
	* @date  9/29/2016
	* @note  
	*/
	BOOL CopyDeleteComIdToComponentsdel(int iComID);
	/**
	* @brief ��componentsdel�е�comid�ļ�¼copy��components���У�isExit��ʾcomponentsdel���Ƿ���ڴ�comid
	*
	*        
	* @author hn
	* @version v1.0
	* @date  10/8/2016
	* @note  
	*/
	BOOL SetDataSet_ComID_del( int iComID,CSQLDataSet *& pComponentdelDataSet, BOOL &isExsit );
	//�̶���SQL ����
	struct PMProjectDBSERVICE SQLInfo
	{
		static const int		m_iSelectComParmBuffer_SQL;
		static const PmTString m_strSelectComParmBuffer_SQL;//��ȡ comparm buffer��sql��

		static const int		m_iSelectVectorParmBuffer_SQL;
		static const PmTString m_strSelectVectorParmBuffer_SQL;//��ȡ vectorparm buffer��sql��

		static const int		m_iSelectComponentInfoBuffer_SQL;
		static const PmTString m_strSelectComponentInfoBuffer_SQL;//��ȡ ����������Ϣ buffer��sql��

		static const int		m_iUpdateVectorParmBuffer_SQL;
		static const PmTString m_strUpdateVectorParmBuffer_SQL;//����VectorParm Buffer��Sql

		static const int		m_iInsertInfo_SQL;
		static const PmTString m_strInsertInfo_SQL;//�����¼ sql

		static const int		m_iDeleteFloorComponent_SQL;
		static const PmTString m_strDeleteFloorComponent_SQL;//ɾ��ָ��¥��Ĺ���

		static const int		m_iSelectAllTable_SQL;
		static const PmTString m_strSelectAllTable_SQL;//��ȡ ������������

		static const int		m_iSelectComID_ComTypeComNameFloor_Sql;
		static const PmTString	m_strSelectComID_ComTypeComNameFloor_Sql;//ͨ�� comtype comName floorid ����ComID_Sql

		static const int			m_iSelectAllInfo_ComID_Sql;
		static const PmTString	m_strSelectAllInfo_ComID_Sql;//ѡ��������Ϣ ͨ��comID sql

		static const int		m_iUpdateBz_ComID_Sql;
		static const PmTString	m_strUpdateBz_ComID_Sql;//ͨ��ComID ���� Bz

		static const int		m_iUpdatePublicGj_ComID_Sql;
		static const PmTString	m_strUpdatePublicGj_ComID_Sql;//ͨ��ComID ���� PublicGj

		static const int		m_iUpdateQDDEData_ComID_Sql;
		static const PmTString	m_strUpdateQDDEData_ComID_Sql;//ͨ��ComID ���� �嵥����

		static const int		m_iSelectAllInfo_FloorIDComName;
		static const PmTString	m_strSelectAllInfo_FloorIDComName;

		//select * from component where floorid = ? and comtype=? and comname=?
		static const int		m_iSelectAllInfo_Floor_ComType_ComName ;
		static const PmTString  m_strSelectAllInfo_Floor_ComType_ComName ;

		static const int		m_iDeleteInfo_ComID;
		static const PmTString	m_strDeleteInfo_ComID;

		//update components set comparm=? where id=?
		static const int		m_iUpdateComParmBuffer_SQL;
		static const PmTString m_strUpdateComParmBuffer_SQL;//����ComParm Buffer��Sql	

		static const int		m_iSelectVectorParmBuffer_ComID_All_SQL;
		static const PmTString  m_strSelectVectorParmBuffer_ComID_All_SQL;//��ȡ vectorparm buffer��sql��
	};
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

class PMProjectDBSERVICE CProjectComponentsOpr
{
public:
	CProjectComponentsOpr() ;
	~CProjectComponentsOpr() ;

public:
	static BOOL SetComponentBz(int iComID,const CString & strBz);

	static BOOL GetComponentBz(int iComID,CString & strBz);

	static BOOL GetVectorParmValue(int iComID,const CString & strParmName,CString & strParmValue);

	static BOOL GetVectorParmDataSet(int iComID,CProject_VectorParmsTable *& pVectorDataSet);

	//��ȡ���� "vectorid" ��תΪ�������ò�����9.9֮ǰ�汾ʹ�ã�֮��汾��vectorid �����Ѿ���Ч
	static int GetVectorID_SL( const int & nComID);

	//
	static int	GetVectorID_Gj( const int & nComID ) ;
	static void	SetVectorID_Gj( const int & nComID , const int & nVectorID_Gj ) ; 

	static BOOL GetQDDEDataSet(int iComID,NDataModelDataSet *& pQDDEDataSet);

	static BOOL SetQDDEDataSet(int iComID,NDataModelDataSet * pQDDEDataSet);

	static BOOL GetRowCount( int & iRowCount ) ;

	/// 
	static BOOL HasSameName_Floor( const int iFloorID,const CString & strComName);

	/// 
	static BOOL HasSameName_Floor_ComType( const int iFloorId , const int iComType , const CString & strComName ) ;

	static BOOL GetComponent_ComIDArr(const CUIntArray & arr_floor ,const CUIntArray & arr_comtype ,CUIntArray & iComIDArr);

	static BOOL GetComponent_ComIDArr(const int iFloorId ,const int iComType ,CUIntArray & iComIDArr);

	static BOOL	GetShowId( const int iComId , int & iShowId ) ;
	static int		GetShowId( const int iComId ) ;

	static BOOL	GetJxmgXs( const int iComId , CString & strJxmgxs ) ;

	static BOOL GetJxMgVectorId( const int iComId , CString & strVectorId ) ;

	static BOOL	GetJxmgLen( const int iComId , CString & strJxmgLen ) ; 

	/**
	* @brief ����Ƿ���   iFloorId ��iComType �еĹ����� aryComId  �С� û�еĻ����½�һ������
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: ���� �Ƿ�Ϊ�½��Ĺ���
	* @author: ����ҫ
	* @date  : [2014��4��30��]
	*/
	static BOOL	CheckHasComType( const CUIntArray & aryComId , const int iFloorId , const int iComType ,  int & iRetComId ) ; 

	static BOOL NeedInsert( const int iComType ) ;

	/**
	* @brief �ƶ�comtype�½�����ʱ�� ��������  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2014��4��30��]
	*/
	static CString GetComName( const int iComType ) ;

	/**
	* @brief һ��ֻ��һ�� �����ҷ�Χ ����   ,�ҵ��˷��� icomid û���ҵ����½�һ�������ҷ�Χ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2014��5��31��]
	*/
	static BOOL  CheckDxsfwCom( const int iFloorId , int & iComId ) ;
};
