#pragma once
////#include "..\accesstable.h"


class PMProjectDBSERVICE CPMGangJinVectorListDataSet  : public CPM_StorageDataSet
{
public:
	CPMGangJinVectorListDataSet();
	virtual ~CPMGangJinVectorListDataSet();

	struct PMProjectDBSERVICE CFieldInfo
	{
	public:
		static const CString sID;
		static const CString sName;//�ֽ�ͼ����
		static const CString sGanJinVector;//�ֽ������Ϣ
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CPMSysOwnGangJinVectorTable : public CSQLDataSet
{
public:
	CPMSysOwnGangJinVectorTable();
	virtual ~CPMSysOwnGangJinVectorTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
	public:
		static const CString sID;
		static const CString sComType;//��������
		static const CString sVectorMode;//ͼ��ʽ
		static const CString sName;//��������
		static const CString sVectorGraph;//����ͼ ������Ϣ
		static const CString sVectorInfo;//����ͼ ������Ϣ
		static const CString sGanJinVectorList;//�Զ���ֽ���Ϣ Blob

		static const CString sTable_Name;
	};
	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessPublicGj_SysGangJinTable : public CPMSLAccessTable
{
public:
	CAccessPublicGj_SysGangJinTable(void);
	virtual ~CAccessPublicGj_SysGangJinTable(void);

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	int GetNewMaxID();

	BOOL GetTableCtrl_VectorID(int iVectorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL GetDataSet_VectorID(int iVectorID,CSQLDataSet *& pSQLDataSet);

	BOOL InsertVector2OwnGanJin(int iComType,int iSLVectorID,const CString & strGanJinName,const LPVOID pGanJinBuffer,const int iGanJinBufferSize);

	static PmTString GetSQL(const int iSQLIndex);

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	struct SQLInfo
	{
		//select * from owngangjinVector where VectorMode=?
		const static int		m_iSelectAllInfo_VectorMode;
		const static PmTString	m_strSelectAllInfo_VectorMode;
	};
};
