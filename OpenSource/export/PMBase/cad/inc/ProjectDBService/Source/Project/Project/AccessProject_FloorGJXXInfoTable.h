#pragma once
//#include "..\accesstable.h"
#include "AccessProject_FloorDJMGInfoTable.h"

class PMProjectDBSERVICE CProject_FloorGJXXInfoTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_FloorGJXXInfoTable)

	CProject_FloorGJXXInfoTable();
	virtual ~CProject_FloorGJXXInfoTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					//���
		static const CString floorid;				//¥���
		static const CString comtype;				//���������
		static const CString component;			//�����������
		static const CString tqd;					//��ǿ�ȵȼ�
		static const CString zdj;					//ש�ȼ�
		static const CString sjdj;				//ɰ���ȼ�
		static const CString jdff;				//��������
		static const CString ldzg;				//����ܸߣ�m��
		static const CString bhc;					//������
		static const CString kzdj;				//����ȼ�
		static const CString gjlx;				//�ֽ�����
		static const CString bfl;					//�ݽ��Ӱٷ���
		static const CString zdcmg;				//�Զ���ê��
		static const CString zdcdj;				//�Զ�����
		static const CString sel_rdgjxs;			//�Ƿ�Ҫʹ�� ���Ŷ��ֽ�ϵ��
		static const CString rdgjxs;				//���Ŷ��ֽ�ϵ��
		static const CString sel_bhchdxs;			//�Ƿ�Ҫʹ�� ê����������������ϵ��
		static const CString bhchdxs;				//ê����������������ϵ��

		static const CString table_name;
	};

	virtual BOOL GetCreateIndexSQL(CStringArray & strFieldNameArr,CString & strIndexName);

	virtual int InitFieldStr();
};


class PMProjectDBSERVICE CAccessProject_FloorGJXXInfoTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_FloorGJXXInfoTable(void);
	CAccessProject_FloorGJXXInfoTable(const CString &strPath);
	virtual ~CAccessProject_FloorGJXXInfoTable(void);

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	/**
	* @brief  ˢ�� ê�̴�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [15/10/2012]
	*/
	void ReFreshMGDJ() ;

	//��¥�� �������͸���
	void CopyFloorComTypeInfo( int nSrcFloorID , 
		const CUIntArray &nArrTargetFloor , 
		const CUIntArray &nArrTargetComType ) ;

	void SetColValue(const CString &strColName, CString strValue, int nFloorID , const CUIntArray &nArrFilterComType);

	void ReSetTQd( int nFloorID , CString strTqd , const CUIntArray &nArrFilterComType);

	void ReSetSjdj( int nFloorID , CString strSjdj , const CUIntArray &nArrFilterComType);

	void ReSetZdj( int nFloorID , CString strZdj , const CUIntArray &nArrFilterComType);

	/**
	* @brief ��ͼ�η��� ComType ת��Ϊ ¥�㹹����Ϣ��Ӧ�� ComType  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/7/2012]
	*/
	static int ConvertComType(int nComType);

	/**
	* @brief  ���������� ComType ת��Ϊ ¥�㹹����Ϣ��Ӧ�� ComType   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/7/2012]
	*/
	static int ConvertComType_Gj( int nComType );

	virtual BOOL TryUpdateTableField();

	/**
	* @brief  ��ȡê�̴�� ��Ϣ 
	*
	*          
	* @note  : iComType:ֻ���� ¥����Ϣ ��Ӧ�� ComType
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/7/2012]
	*/
	BOOL GetMG_DJInfo(int iFloorID,int iComType,const CString & strGJIndex,CProject_FloorDJMGInfoTable::GJZJ gjZJ,BOOL bIsMG,CString & strValue);

	/**
	* @brief   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [5/7/2012]
	*/
	BOOL GetFloorGJXXInfo(int iFloorID,int iComType,CPMSQLTableCtrl *& pFloorGJXXTableCtrl);

	//��ȡָ������ǿ��
	BOOL GetSpecifyTQD( int iFloorID, int nComType , CString& strTQD);
	///BOOL GetSpecifyTQD( int iFloorID, CString strComponent, CString& strTQD);
	
	//��ȡָ���� ����ܸ�
	BOOL GetSpecifyLDZG( int iFloorID, int nComType , CString & strLDZG);

	//��ȡָ����ש�ȼ�
	BOOL GetSpecifyZDJ( int iFloorID, int nComType , CString& strZDJ);

	//��ȡָ����ɰ���ȼ�
	BOOL GetSpecifySJDJ( int iFloorID, int nComType , CString& strSJDJ);

	//��ȡָ���Ľ�����ʽ
	BOOL GetSpecifyJDFF( int iFloorID, int nComType , CString& strJDFF);

	//��ȡָ���ı�������
	BOOL GetSpecifyBHC( int iFloorID, int nComType , int& iSJDJ);

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

	CSQLDataSet * GetEmptyDataSet() ;

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
	* @brief ��ȡ ¥�� �ֽ� ϵ�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL GetFloorGJXX_XZXS( const int iFloorID,const int iComType,double & dRDGJXS,double & dBHCHDXS);

	/**
	* @brief   ����floorid|convertcomtype ����ȡ��Ӧ��RDGJXS,BHCHDXSֵ
	*
	*			ע�⣺FloorComtype�е�comtype�������������ϵ�comtype,Ϊcovertcomtype����ת������
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [10/23/2019]
	*/
	BOOL GetFloorGJXX_XZXS(std::map<CString,CString> & mapFloorComtype2TQD ,
		std::map<CString,double> & mapFloorComtype2RDGJXS ,
		std::map<CString,double> & mapFloorComtype2BHCHDXS);

	/**
	* @brief  ��ȡ¥�� ������Ϣ�� ���ê��DataSet
	*
	*          
	* @note  : pFloorGJXXDataSet��pFloorMGDJDataSet����Ҫɾ����
	* @param : int nFloorID:¥��ID
	*			int nComType����������
	*			NDataModelDataSet *& pFloorGJXXDataSet��������Ϣ
	*			NDataModelDataSet *& pFloorMGDJDataSet���������ê��
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [1/12/2011]
	*/
	BOOL GetFloorGJXXInfoDataSet( 
		const int nFloorID,
		const int nComType,
		NDataModelDataSet *& pFloorGJXXDataSet,
		NDataModelDataSet *& pFloorMGDJDataSet
		);


	CSQLDataSet * GetDataSet( const int iFloorID , const int iComType ) ;

	/**
	* @brief ���� ����ȼ�  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [23/7/2012]
	*/
	void ChangeWithKzdj(const CString & strKzdj ) ;

	void ChangeWithTqd(CString strTqd, int nFloorID);

protected:

	/**
	* @brief ͨ��ָ���� �� ��ȡ �Ŷ�ϵ��  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [23/7/2012]
	*/
	BOOL GetFloorGJXX_XZXS_Row(NDataModelDataSet * pFloorGJXXDataSet,int iFloorIDGJXXRow,double & dRDGJXS,double & dBHCHDXS);

	//�̶���SQL ����
	struct SQLInfo
	{
		static const PmTString m_strSelectFloorGJXXInfo_SQL;	//��ȡ��������
		static const PmTString m_strSelectFloorMGDJ_SQL;//��ȡ ê�̴�ӵ�sql��
		static const PmTString m_strSelectFloorGJXXInfo_FloorComType_SQL;//��ȡ ¥��ֽ�������Ϣsql��t
		//static const PmTString m_strSelectFloorTQD_SQL;//��ȡ ��ǿ�� sql
		//static const PmTString m_strSelectFloorLDZG_SQL;//��ȡ ����ܸ� sql
		//static const PmTString m_strSelectFloorZDJ_SQL;//��ȡ ש�ȼ� sql
		//static const PmTString m_strSelectFloorSJDJ_SQL;//��ȡ  ɰ���ȼ� sql
		//static const PmTString m_strSelectFloorJDFF_SQL;//��ȡ ������ʽ sql
		//static const PmTString m_strSelectFloorBHC_SQL;//��ȡ ������ sql
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

class PMProjectDBSERVICE CProjectFloorGjxxOpr
{
public:
	CProjectFloorGjxxOpr() ; 
	~CProjectFloorGjxxOpr() ; 

public:
	static BOOL GetFloorGJXX_XZXS( const int iFloorID,const int iComType,double & dRDGJXS,double & dBHCHDXS) ; 

	//��ȡָ������ǿ��
	static BOOL GetSpecifyTQD( const int iFloorID, const int nComType , CString& strTQD);
	///BOOL GetSpecifyTQD( int iFloorID, CString strComponent, CString& strTQD);

	//��ȡָ���� ����ܸ�
	static BOOL GetSpecifyLDZG( const int iFloorID, const int nComType , CString & strLDZG);

	//��ȡָ����ש�ȼ�
	static BOOL GetSpecifyZDJ( const int iFloorID, const int nComType , CString& strZDJ);

	//��ȡָ����ɰ���ȼ�
	static BOOL GetSpecifySJDJ( const int iFloorID, const int nComType , CString& strSJDJ);

	//��ȡָ���Ľ�����ʽ
	static BOOL GetSpecifyJDFF( const int iFloorID, const int nComType , CString& strJDFF);

	//��ȡָ���ı�������
	static BOOL GetSpecifyBHC( const int iFloorID, const int nComType , int& iBhc);
	static BOOL GetSpecifyBHC( const int iFloorID, const int nComType , CString & strBhc);
};
