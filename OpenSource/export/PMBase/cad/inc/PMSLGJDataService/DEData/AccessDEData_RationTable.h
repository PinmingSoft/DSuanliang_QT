#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CDERationTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CDERationTable)

	CDERationTable();
	virtual ~CDERationTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString denumber;		//������Ŀ��
		static const CString subname;			//��Ŀ����
		static const CString extendflag;		//���䶨���־��
		static const CString unit;			//��λ���ִ�
		static const CString chapter;			//�½ڱ���

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CAccessDEData_RationTable :
	public CPMSLAccessTable
{
public:
	CAccessDEData_RationTable(void);

	virtual ~CAccessDEData_RationTable(void);

	virtual BOOL TryUpdateTableField();

	CSQLDataSet * GetDataSet();

	NDataModelDataSet * GetEmptyDataSet() ;

	BOOL SaveDataSet(CSQLDataSet * pRationTable);

	/**
	* @brief ��ȡ�����м�¼��  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [24/7/2012]
	*/
	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief  ͨ�� denumber ��ȡ ��¼�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/7/2012]
	*/
	BOOL GetTableCtrl_DeNumber(const CString & strDENUmber,CPMSQLTableCtrl *& pTemSQLTableCtrl);

	BOOL GetTableCtrl_ID(int iID,CPMSQLTableCtrl *& pTemSQLTableCtrl);

	BOOL GetID_DeNumber(const CString & strDENumber,int & iDEID);

	BOOL GetTableCtrl_DeNumber(const CStringArray & strDENumberArr,CPMSQLTableCtrl *& pTemSQLTableCtrl);

	BOOL GetTableCtrl_Chapter(const CString & strChapter,CPMSQLTableCtrl *& pTemSQLTableCtrl);

	BOOL SreachName_DeNum_TableCtrl(const CString strSreachInfo,CPMSQLTableCtrl *& pTemSQLTableCtrl);

	static PmTString GetSQL(const int iSQLIndex);

	struct PmSLGJDataServiceAPI SQLInfo
	{
		static const int		m_iSelectAllInfo_DENumber;
		static const PmTString	m_strSelectAllInfo_DENumber;//��ȡ������Ϣ ָ���Ķ�����

		static const int		m_iSelectAllInfo_nameOrdenum;
		static const PmTString	m_strSelectAllInfo_nameOrdenum;//��ȡ������Ϣ ģ������

		static const int		m_iSelectAllInfo_chapter;
		static const PmTString	m_strSelectAllInfo_chapter;//��ȡ������Ϣ �½ڱ��

		static const int		m_iSelectAllInfo_id;
		static const PmTString	m_strSelectAllInfo_id;//��ȡ������Ϣ �½ڱ��
	};
};
