#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CPublic_Component_QDDETable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CPublic_Component_QDDETable)

	CPublic_Component_QDDETable();
	virtual ~CPublic_Component_QDDETable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString comid;					
		static const CString com_qdde;
		static const CString gangjin_mode;

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessPublicGj_Component_QDDETable :
	public CPMSLAccessTable
{
public:
	CAccessPublicGj_Component_QDDETable(void);

	virtual ~CAccessPublicGj_Component_QDDETable(void);

	virtual BOOL TryUpdateTableField();

	static PmTString GetSQL(const int iSQLIndex);

	/**
	* @brief  ��ȡ ָ��comID�� ֵ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	BOOL GetQDDE_ComID(int iComID, CString &strQDDE);
	BOOL GetQDDE_ComID(int iComID, int & iGangjinMode);

	/**
	* @brief ɾ�� ָ��ComID�� ��¼  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	BOOL DelSysComponent(int iSysComID);

	/**
	* @brief  ��� �嵥 ���� �Ƿ�һ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	BOOL CheckIsSameQDDE(int iComID);
	
	/**
	* @brief  ��� �ֽ�ģʽ �Ƿ�һ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zy
	* @date  : [4/1/2019]
	*/
	BOOL CheckIsSameGangjinMode(int iComID);

	/**
	* @brief  �����¼ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	BOOL InsertCom_QDDE(int iSysComID, CString strQDDE);
	BOOL InsertCom_QDDE(int iSysComID, CString strQDDE, int & iGangjinMode);

	BOOL InsertCom_QDDE(int iSysComID);

	struct PMProjectDBSERVICE SQLInfo
	{
		static const int		m_iSelectQDDE_ComID_Sql;
		static const PmTString	m_strSelectQDDE_ComID_Sql;//ʹ�� comID ���� qdde ��Ϣ

		static const int        m_iSelectGangjinMode_ComID_Sql;
		static const PmTString  m_strSelectGangjinMode_ComID_Sql;//ʹ�� comID ���� gangjinmode ��Ϣ

		static const int		m_iDeleteInfo_ComID_Sql;
		static const PmTString	m_strDeleteInfo_ComID_Sql;////ʹ�� comID ɾ�� qdde ��Ϣ

		static const int		m_iUpdataQDDE_ComID_Sql;
		static const PmTString	m_strUpdataQDDE_ComID_Sql;//���� ComID�� QDDE ��Ϣ
	};
};
