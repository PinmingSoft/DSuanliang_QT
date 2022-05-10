#pragma once
class PMProjectDBSERVICE CCalComponentBG
{
public:
	CCalComponentBG(void);
	~CCalComponentBG(void);

	/// �ж��Ƿ��޸ĵ��Ǳ����ز���
	static BOOL IsChangeBG(int comtypeCur, const CString & parmChanged);

	/**
	* @brief   �����������,���ڻ�׼��߲��䣬���¼�������һ�����
	*			ע�⣺1���ؼ�������ĳ��dataset�����ı�ߴ��� kMultiValue����������Ϊ����ֵ
	*				  2���ڲ�����Ĳ����ǻ���CComponentInfo�л���ı�߲���������dataset������Ҫ�ǵ��ȱ���dataset�н����޸ĵĲ�����CComponentInfo������
	*				
	*			1.����ĳ��߸Ķ�������һ��߻��߲����������
	*			2.���ڽ�����ʾʱ�ĵĹ��̱������
	*			3.�������Ķ����޸�����Ϊ qc:26038
	* @note  : ������ �� ����ԭ�ȵ� ����д�ĵ� ReCalComponentBG ���������޸ġ����� ���������� ��������
	* @param : nChangeMode : 0 ��ʾ ������ߡ����ױ�� Ҫ��ȥһ��¥������ ������ʾ��ͨ�����ڽ�UI��dataset(���̱��)תΪ���ݴ洢��
							 1 ��ʾ ������ߡ����ױ�� ����ʵ�ʱ��ģʽ�����Ӽ��������������ߴ洢��datasetת������UI��dataset
							 2 ͨ�� ������ߡ����ױ�� �������������ױ�� ������¥�����ߵļӼ�,������߸���ʵ�ʱ��ģʽ�����Ӽ���������������dataset��ĸ���
	*
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/17/2018]
	*/
	static BOOL ReCalComponentBG_Base(int iComID,int nChangeMode, int iComType,NDataModelDataSet *pDataSet);

	/**
	* @brief  ���㶥 �� ���
	*			
	*          ע�⣺1��qc:30186,�� pDataSetForDb ����Ϊ���ݿ�洢�õı�ߣ�ͳһΪ��Ա�� ����������� �Ƿ��ı��磺kMultiValue
	*				 2���ڲ�����Ĳ����ǻ���CComponentInfo�л���ı�߲���������dataset������Ҫ�ǵ��ȱ���dataset�н����޸ĵĲ�����CComponentInfo������
	* @note  : 
	* @param : strEditParmName ��ʾ���༭������
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	static BOOL ReCalComponentDbg_Dibg(int iComID, CString strEditParmName, NDataModelDataSet * pDataSetForDb);
	static BOOL ReCalComponentDbg_Dibg(int iComID, CString strEditParmName);

	/**
	* @brief  	��dataset�еı�߽��й��̱�߻�¥���ߵ�ת������������д���$���ţ����ǲ�����ת������Ϊ���ֲ��������ǽ���ui��database���Ǳ��浽���ݿ��õ�dataset����һ��
	*			1���ؼ�������ĳ��dataset�����ı�ߴ��� kMultiValue����ʱͨ���� ui��dataset������������Ϊ����ֵ 
	*			2�����ת���ò����ǻ���pDataSet�ģ���Ҫ��pDataSet Ҫ�ȱ��浽 CComponentInfo������
	*          
	* @note  : 
	* @param : nChangeMode : 0 ��ʾ ������ߡ����ױ�� Ҫ��ȥһ��¥������ ������ʾ��ͨ�����ڽ�UI��dataset(���̱��)תΪ���ݴ洢��
							 1 ��ʾ �洢��datasetת������UI��dataset
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	static BOOL ChangeWithLCBG_GCBG(int iComID,int nChangeMode, int iComType,NDataModelDataSet *pDataSet);

private:
	/**
	* @brief  ���㶥 �� ���
	*			
	*          ע�⣺1��qc:30186,�� pDataSetForDb ����Ϊ���ݿ�洢�õı�ߣ�ͳһΪ��Ա�� ����������� �Ƿ��ı��磺kMultiValue
	*				 2���ڲ�����Ĳ����ǻ���CComponentInfo�л���ı�߲���������dataset������Ҫ�ǵ��ȱ���dataset�н����޸ĵĲ�����CComponentInfo������
	* @note  : 
	* @param : strEditParmName ��ʾ���༭������
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	static BOOL ReCalComponentDbg_DibgImp(int iComID, CString strEditParmName,CString & strMdfName, CString & strMdfValue);
};

