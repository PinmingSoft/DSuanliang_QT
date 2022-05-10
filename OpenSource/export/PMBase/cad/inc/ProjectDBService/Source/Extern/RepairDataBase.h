#pragma once

#define floor2floorgjxxinfo 10  /// ¥�㵽¥����Ϣ�� �Ķ�Ӧ��ϵ  �� 1�� ��Ӧ 10 �� (2010-5-20)  

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//// ר������ �޸����ݿ�
class PMProjectDBSERVICE CRepairDataBase
{
private:
	CRepairDataBase();
	static CRepairDataBase * m_pInstance;
public:
	virtual ~CRepairDataBase();
	static CRepairDataBase *Instance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = PMNew(CRepairDataBase);
		}
		return m_pInstance;
	}
	static void Release()
	{
		if ( m_pInstance )
		{
			PMDelete(m_pInstance);
			m_pInstance = NULL;
		}
	}

	
public:
	/// ����������� �� �� 
	int Check( ) ; 
	/// �޸� 
	void Repair() ; 

	/// ��� floorgjxxinfo �Ƿ�������
	BOOL CheckFloorGjxxInfoTable() ; 

	/// �޸� floorgjxxinfo ��
	/// ����¥�ɱ�ȥ�ع�һ��  
	void RepairFloorGjxxInfoTable() ;

private:

//////////////////////////////////////////////////////////////////////////
/// common 
	BOOL Update_DataSet(NDataModelDataSet * pTemDataSet,NDataModelDataSet * pNewDataSet) ; 

};
