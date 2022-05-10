#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_ComFolderTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ComFolderTable)

	CProject_ComFolderTable();
	virtual ~CProject_ComFolderTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString comfolderid;					//�ļ���ID
		static const CString floorid;						//¥��ID
		static const CString allowownercom;				//�Ƿ�����ӵ�й���
		static const CString parentid;					//�������ļ���ID
		static const CString foldername;					//�����ļ�������
		static const CString imageindex;					//��ʾͼ��INdex
		static const CString selectedindex;				//ѡ��ͼ��Index
		static const CString comtype;						//��������
		static const CString allowadduserfolder;			//�Ƿ������Զ����ļ���
		static const CString initcreate;					//�Ƿ���ʾ
		static const CString volume;						//�˹����е�����
		static const CString showid;						//��ʾ˳��


		static const CString table_name;			//����
	};

	virtual int InitFieldStr();
};

//������ ������ ���ݿ����
class PMProjectDBSERVICE CAccessProject_ComFolderTable:
	public CPMSLAccessTable
{
public:
	CAccessProject_ComFolderTable(void);
	virtual ~CAccessProject_ComFolderTable(void);


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
	CSQLDataSet * GetFloorID_DataSet(int iFloorID);

	/**
	* @brief  ��ȡָ��ComFloder Folder ,�� Volume
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL GetComFolder_Volume(const CString & strComFolderID,int iFloorID,int & iVolume);

	/**
	* @brief  ��ȡָ��ComFloder Folder ,��Ӧ ��¼��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL GetTableCtrl_ComFolderFloorID(const CString & strComFolderID,int iFloorID,CPMSQLTableCtrl *& pSQLTableCtrl);
	BOOL GetDataSet_ComFolderFloorID(const CString & strComFolderID,int iFloorID,CSQLDataSet *& pSQLDataSet);

	/**
	* @brief  ɾ�� ָ��¥�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL DeleteFloor(int iFloorID);

	/**
	* @brief  ��ȡFolder�� DataSet 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	CSQLDataSet * GetEmptyDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	/******************************************************************** 
	������������ȡ���е� ������ ���ظ�(���ֲ�)
	������
	�� �� ֵ�����ص� DataSet ��Ҫɾ��
	�㷨��
	ע�����Repeat д���� 
	��    �ߣ�����ҫ
	ʱ    �䣺[2009��4��28��]
	*********************************************************************/ 
	NDataModelDataSet * GetNotNepeatDataSet();

	BOOL GetRowCount( int & iRowCount ) ;

	CString GetComFolderName( const CString & strComFolderID  ) ;


	int InsertOneRow(
		int nFloorID , 
		int nAllowOwnerCom , 
		int nParentID , 
		const CString & strFolderName , 
		int nImageIndex ,
		int nSelectedIndex , 
		int nComType ,
		int nAllowAddUserFolder , 
		int nInitCreate ,
		int nVolume
		);


	BOOL GetMaxComFolderID(int & iMaxComFolderID) ;

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		/// 
		const static int		m_iDelete_FloorIDSQL;
		const static PmTString m_strDelete_FloorIDSQL;//ͨ��¥��IDɾ��SQL

		/// 
		static const int		m_iGetNotNepeatDataSet ;
		static PMTSTRING		m_strGetNotNepeatDataSet ;

		/// 
		static const int		m_iSelectAllInfo_ComFolderFloor ;
		static PMTSTRING		m_strSelectAllInfo_ComFolderFloor ;

		/// 
		static const int		m_iGetComFoderName ; 
		static PMTSTRING		m_strGetComFolderName ; 
	};
};
