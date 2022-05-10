#pragma once

#include <tuple>

class PMProjectDBSERVICE CProject_ComponentSWL_Handle : public CSQLDataSet  
{
public:
	DECLARE_DYNCREATE(CProject_ComponentSWL_Handle)

	CProject_ComponentSWL_Handle(){};
	virtual ~CProject_ComponentSWL_Handle(){};
	virtual int InitFieldStr();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id ;
		static const CString comid ;
		static const CString handle ;

		//����
		static const CString table_name;
	};
};

class PMProjectDBSERVICE CAccessProject_ComponentSWL_Handle:
	public CPMSLAccessTable
{
public:
	CAccessProject_ComponentSWL_Handle(void);
	CAccessProject_ComponentSWL_Handle(BOOL bExtern);
	virtual ~CAccessProject_ComponentSWL_Handle(void);

	//
	BOOL TryUpdateTableField()
	{
		return TRUE;
	}

	/**
	* @brief ��ѯ component_swl_handle ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [4/3/2019]
	*/
	CSQLDataSet * GetDataSet();
	CSQLDataSet * GetDataSet(int comid,CString handle);

	/**
	* @brief ��ѯ CPrivateSWL_UserDefDataset ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [4/3/2019]
	*/
	CPrivateSWL_UserDefDataset * GetDataSet_UserDef(int comid,CString handle) const;
	CPrivateSWL_UserDefDataset * GetDataSet_UserDef(const CUIntArray& arrComid,const CStringArray& arrHandle) const;

	/**
	* @brief ��ȡ������ʵ���������ݼ�
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [4/9/2019]
	*/
	CProject_SwlRule_ForCal * GetDataSet_SwlRuleForCal(CProject_SwlRule_ForCal * pDatasetForCalDefault
													,int comid
													,int comtype
													,CString handle) const;

	/// map�ǿգ���tuple���������ݷֱ���comid,comtype,handle
	void CAccessProject_ComponentSWL_Handle::GetDataSet_SwlRuleForCal(CProject_SwlRule_ForCal * pDatasetForCalDefault,
		                             std::map<std::tuple<int, int, CString>, CProject_SwlRule_ForCal*> & swlrule_sets);


	/**
	* @brief  ���»��߲������ component_swl_info_handle �ļ�¼,swlRuleMX_UserDef_handle�ļ�¼
	*
	*          
	* @note  : 
	* @param : pDs Ϊ CPrivateSWL_UserDefDataset
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [4/1/2019]
	*/
	void UpdateSWL_Info(int comid,CString handle,CSQLDataSet * pDs);
	BOOL UpdateSWL_Info(const CUIntArray & arrComid,CStringArray & arrHandle,CSQLDataSet * pDs);
	/// û�в�������ķ�ʽ�ļ�¼����----��Ҫ��Ϊ�ⲿ�����ݿ��������
	void UpdateSWL_Info_NoTransaction(int comid,CString handle,CSQLDataSet * pDs);

	//ɾ�� ��¼
	void Delete(int comid,CString handle);
	BOOL Delete(const CUIntArray & arrComid,const CStringArray & arrHandle);

private:
	BOOL m_bExtern;

	//��ȡ������� component_swl_handle �� �� id
	void GetId(const CUIntArray & arrComid,const CStringArray & arrHandle,CStringArray & arrId) const;

	/// û�в�������ķ�ʽ�ļ�¼����----��Ҫ��Ϊ�ⲿ�����ݿ��������
	BOOL UpdateSWL_Info_NoTransaction(const CUIntArray & arrComid,CStringArray & arrHandle,CSQLDataSet * pDs);
};
