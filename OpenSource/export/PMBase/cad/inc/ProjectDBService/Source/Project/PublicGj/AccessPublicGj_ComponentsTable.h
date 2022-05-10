#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CAccessPublicGj_ComponentsTable :
	public CPMSLAccessTable
{
public:
	CAccessPublicGj_ComponentsTable(void);

	virtual ~CAccessPublicGj_ComponentsTable(void);

	virtual BOOL TryUpdateTableField();

	/**
	* @brief ��ȡ DataSet   
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	/**
	* @brief ��ȡ���� ��¼��   
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

	/**
	* @brief  �� ������ ָ��comid �Ĺ��� ���� ������¼�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	BOOL Insert(int iComID , CString strComName , int &SysComID) ;
	BOOL Insert(int iComID, int &SysComID);
	/**
	* @brief   �ж��Ƿ� ������
	*          ԭ����Comid���жϲ�������,��Ϊ�޷��������ֶ�����е�comid��ȡ��Ӧ��comtype
	*          ��ֱ�Ӹ���Ϊ��comtype�����ж� wrq [2017-2-16]
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	BOOL CheckHasSameName(int iComType , CString strComName);

	/**
	* @brief   �ú��������ܹ����ڵ�Comid,���������Comid�޷�ʶ��
	*          
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	BOOL CheckHasSameName(int iComID);

	/**
	* @brief  ��ȡ ComType ComName ��Ӧ�ļ�¼�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	BOOL GetTableCtrl_ComTypeComName(int iComType,const CString & strComName,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief ��ȡ �嵥 DataSet  
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	NDataModelDataSet * GetQDDEDataSet(int iSysComID);

	/**
	* @brief  ��ȡ VectorParm 
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	NDataModelDataSet * GetVectorParmDataSet(int iSysComID);

	/**
	* @brief  ��ȡ���� �ܱ� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	NDataModelDataSet * GetComParmsDataSet(int iSysComID);
	NDataModelDataSet * GetComParmsDataSet_UI(int iSysComID);

	/// �ֽ�״̬�µ����������
	NDataModelDataSet * GetComParmsDataSet_UI_GJ(int iSysComID);

	/// ��ȡ�������ò���
	NDataModelDataSet * GetComParmsDataSet_JSSZ(int iSysComID);

	/**
	* @brief   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	BOOL GetComType(int iSysComID,int & iComType);

	/**
	* @brief  ɾ�� ָ���� ���� 
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
	* @brief ���� �Զ���ֽ�   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	BOOL SetComponentOwnGanJinVector(int iComID,const LPVOID pBuffer,const int iBufferSize);

	BOOL GetComponentOwnGanJinVector(int iComID,LPVOID & pBuffer,long & iBufferSize);

	BOOL RemoveComponentOwnGanJinVector(int iComID);

	/**
	* @brief ͨ�� ָ���� ComID ��ȡ ��¼��  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	BOOL GetTableCtrl_ComID(int iSysComID,CPMSQLTableCtrl *& pSQLTableCtrl);
private:
		/**
	*  @brief : ��ȡ���ݿ���ָ���ֶε��߼����ֵ
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/6/17 14:36
	*/
	CString GetMaxColValue(const CString& strColName);
	/**
	*  @brief : �������ݵ�PublicGj���ݿ��е�customizesteeldiagram��
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/6/17 14:37
	*/
	CString InsertPublicCustomizeSteelDiagram(const CString& strTh);
	CSqliteDataBase m_PublicDb;		// publicgj ���ݿ�
	CSqliteDataBase m_ProjectDb;	// project ���ݿ�
};
