#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_FloorDJMGInfoTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_FloorDJMGInfoTable)

	CProject_FloorDJMGInfoTable();
	virtual ~CProject_FloorDJMGInfoTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;
		static const CString floorgjxxid;	
		static const CString gangjinmode;
		static const CString gjindex;	
		static const CString zjinfo;
		static const CString mgz;
		static const CString djz;

		static const CString table_name;
	};

	//�ֽ���ų���˵��
	struct PMProjectDBSERVICE CGJIndex
	{
		const static CString strA;
		const static CString strB;
		const static CString strC;
		const static CString strD;
		const static CString strE;
		const static CString strF;
		const static CString strG;
	};

	//�ֽ��˵��
	enum PMProjectDBSERVICE GJZJ
	{
		AllZJ = 0,
		low25ZJ = 20,
		high25ZJ = 30
	};

	virtual BOOL GetCreateIndexSQL(CStringArray & strFieldNameArr,CString & strIndexName);

	virtual int InitFieldStr();
};


class PMProjectDBSERVICE CAccessProject_FloorDJMGInfoTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_FloorDJMGInfoTable(void);

	virtual ~CAccessProject_FloorDJMGInfoTable(void);

	/**
	* @brief ��ȡ �ֽ� ֱ�� ��ʾ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [24/7/2012]
	*/
	static CString GetFloorDJMG_ChangeGJZJ(int iGJMode,int iGJZJ);

	/**
	* @brief  ��ȡ �ֽ���ʾ���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [24/7/2012]
	*/
	static CString GetFloorDJMG_ChangeGJName(int iGJMode,CString strGJName);

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
	CSQLDataSet * GetFloorGJXXID_DataSet(int iFloorGJXXID);

	CSQLDataSet * GetDataSet( const int iFloorGjxxId , const int iGangJinMode ) ;

	CSQLDataSet * GetDataSet();

	NDataModelDataSet * GetDataSet( const CUIntArray & aryFloorGjxxId , const int iGangJinMode ) ; 

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	//���� ê�̴����Ϣ  ֻ�� ��������ʹ��
	//03G 11G���ݸ�ʽ��ͬ����Ҫindex
	BOOL SaveMGDJDataSet(NDataModelDataSet * pMGDJDataSet,int index);

	/**
	* @brief ɾ��ָ�� FloorGJXXID�� ê�̴��ֵ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL DeleteInfo_FloorGJXX(int iFloorGJXXID);

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

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		const static PmTString m_strDelete_FloorGJXXID_Sql;//ͨ��FloorGJXX ɾ��ê�̴��
		const static int				m_iDelete_FloorGJXXID_Sql;

		///
		const static int		m_iGetDataSet_Gjxx_GjMode ;
		const static PMTSTRING	m_strGetDataSet_Gjxx_GjMode ;

		/// 
		const static int		m_iGetDataSet_ArrGjxx_GjMode ;
		static PMTSTRING	m_strGetDataSet_ArrGjxx_GjMode ;


	};
};
