#pragma once

#include "AccessProject_ComponentsTable.h"



class PMProjectDBSERVICE CProject_ComponentsDelTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ComponentsDelTable)

	CProject_ComponentsDelTable();
	virtual ~CProject_ComponentsDelTable();

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

		static const CString table_name;				//����
	};

	virtual BOOL GetCreateIndexSQL(CStringArray & strFieldNameArr,CString & strIndexName);

	virtual int InitFieldStr();
};


class PMProjectDBSERVICE CAccessProject_ComponentsDelTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_ComponentsDelTable(void);
public:
	virtual ~CAccessProject_ComponentsDelTable(void);
	BOOL TryUpdateTableField();

	/**
	* @brief ����components�е�comid��¼��componentsdel�У�isExit��ʾcomponentsdel���Ƿ���ڴ�comid
	*
	*        
	* @author hn
	* @version v1.0
	* @date  10/8/2016
	* @note  
	*/
	BOOL SetDataSet_ComID( int iComID,CSQLDataSet *& pComponentDataSet, BOOL &isExsit );
	//�̶���SQL ����
	struct PMProjectDBSERVICE SQLInfo
	{
		static const int		m_iInsertInfo_SQL;
		static const PmTString m_strInsertInfo_SQL;//�����¼��

		static const int		m_iDeleteInfo_ComID;
		static const PmTString	m_strDeleteInfo_ComID;// ɾ����¼

		static const int		m_iUpdateVectorParmBuffer_SQL;
		static const PmTString m_strUpdateVectorParmBuffer_SQL;//����VectorParm Buffer��Sql

		static const int		m_iSelectVectorParmBuffer_SQL;
		static const PmTString m_strSelectVectorParmBuffer_SQL;//��ȡ vectorparm buffer��sql��
	};

	/**
	* @brief SQL���
	*
	*        
	* @author hn
	* @version v1.0
	* @date  9/29/2016
	* @note  
	*/
	static PmTString GetSQL(const int iSQLIndex);
	/**
	* @brief ��ȡ���COMID
	*
	*        
	* @author hn
	* @version v1.0
	* @date  9/29/2016
	* @note  
	*/
	BOOL GetTable_MaxID(int & iMaxID);
	/**
	* @brief ��ȡcomid��Ӧ����Ϣ���Ҳ���comidʱ����FALSE
	*
	*        
	* @author hn
	* @version v1.0
	* @date  10/8/2016
	* @note  
	*/
	BOOL GetDataSet_ComID(int iComID,CSQLDataSet *& pComponentdelDataSet);
	/**
	* @brief copy��Ϣ��components����
	*
	*        
	* @author hn
	* @version v1.0
	* @date  10/8/2016
	* @note  
	*/
	BOOL CopyComponentsdelComIdToComponents(int iComID);
	/**
	* @brief ��¼��
	*
	*        
	* @author hn
	* @version v1.0
	* @date  10/8/2016
	* @note  
	*/
	BOOL GetRowCount( int & iRowCount );
	/**
	* @brief ���ý���ͼ��Ϣ��componentsdel��
	*
	*        
	* @author hn
	* @version v1.0
	* @date  3/30/2017 
	* @note  
	*/
	BOOL SetVectorParm_Buffer(int iComID,void * pVectorParmBuffer,long lVectorParmBufferSize);
	/**
	* @brief ��ȡvector����
	*
	*        
	* @author hn
	* @version v1.0
	* @date  3/30/2017 
	* @note  
	*/
	BOOL GetVectorParmDataSet(int iComID,CProject_VectorParmsTable *& pVectorDataSet);
};