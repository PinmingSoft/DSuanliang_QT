#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_FloorBGModeTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_FloorBGModeTable)

	CProject_FloorBGModeTable();
	virtual ~CProject_FloorBGModeTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;			
		static const CString floorid;						//¥��ID
		static const CString comtype;						//��������
		static const CString comname;						//��������
		static const CString bgmode;						//��ģʽ 0��¥���� 1�����̱��

		static const CString table_name;					//����
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_FloorBGModeTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_FloorBGModeTable(void);
	virtual ~CAccessProject_FloorBGModeTable(void);

	virtual BOOL TryUpdateTableField();

	virtual BOOL TryUpdateTableContent() ;

	/**
	* @brief  �������Ϣ ���浽 ������ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [24/7/2012]
	*/
	void SetFloorBGMode(int nFloorID, NDataModelDataSet *pDataSet);

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

	/******************************************************************** 
	 ������������ȡָ��¥�� �������� �ı��ģʽ
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����iBGMode�� 0 ¥���� 1 ���̱��
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[9/9/2008]
	*********************************************************************/ 
	BOOL GetFloor_ComTypeBGMode(int iFloorID, int iComType, int &iBGMode);

	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	BOOL GetRowCount( int & iRowCount ) ;

	static PMTSTRING GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		const static int		m_iSelectBGMode_FloorComType;
		const static PMTSTRING	m_strSelectBGMode_FloorComType;
	};
};
