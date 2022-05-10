// ParmAccess.h: interface for the CParmAccess class.
//
//////////////////////////////////////////////////////////////////////

/**
 * @brief ���ļ��� SteelDataService �ƹ�����
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-18]
 * @note  
 */

#if !defined(AFX_PARMACCESS_H__A0149476_B72F_44A6_9AB5_7A2EB9FD0F21__INCLUDED_)
#define AFX_PARMACCESS_H__A0149476_B72F_44A6_9AB5_7A2EB9FD0F21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PMProjectDBSERVICE CParmAccess  
{
private:
	CParmAccess();
	virtual ~CParmAccess();

public:
//��Ŀ��������ô�ȡ
	//ȡ��ָ���������ļ�������,����������ȫ�ֶ����н���ȡ������ֵ
	//��Ҫɾ��
    static NDataModelDataSet * GetComCalSetupDataSetByType(int comType); 
	static NDataModelDataSet * GetComCalSetupDataSetByType(int comType,int parmType);
	static NDataModelDataSet * GetComCalSetupDataSetByType(int comType,int parmType,int hide);

	/**
	* @brief  ��ȡ ������������Ϣ�� CParms 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/9/2012]
	*/
	static CParms * GetComponentParms(const int iComId );

	/// 
	static CParm::ParmType MapDatatypeToParmtype(int datatype);


//������������ô洢
	//************************************
	// Method:  GetComSetupDataSet  
	// Access: public   
	// Returns:  ����ָ��ID����������DataSet
	// Qualifier: 
	// Parameter: comID �ؼ���id����
	// Remark: ������ȡ�ù���������������������������ȫ�����ú�
	//         �������õ���������кϲ�,����ԭ���ϱ�����ֻ��֧�ּ���
	//         �еĲ���ȡ��
	//			(wjy)����NDataModelDataSet��Ҫɾ��
	//************************************
    static NDataModelDataSet * GetComSetupDataSet(int comID);

	//************************************
	// Method:  GetComSetupDataSet  
	// Access:  public  
	// Qualifier: 
	// Parameter: comID����id parmType �������
	// Returns: ����ָ�����ָ�������������ñ�
	// Remark: ����������ȡ��ָ��������ָ���������������б�
	// ����������ж���Ӧ�Ĳ��������û�н������ã���������ȫ��������ȡ��
	// ���ں����������������ã����Ա�����ԭ�������ڽ����еĲ������á�
	// ���������ص�DataSet�ھ���ֵ���޸ĺ����Ϊ�洢���õĲ�������
	//			(wjy)����NDataModelDataSet��Ҫɾ��
	//************************************
    static NDataModelDataSet* GetComSetupDataSet(int comID,int parmType);

	static NDataModelDataSet* GetComSetupDataSet(int comID,int parmType,int hide);
	
	//NDataModelDataSet* GetComSetupDataSet(int comID);
	//����ָ��ID�Ĺ������ã��������������ڱ���ʱ���滻ԭ�еı����������
	//ͬʱ��������ָ�������Ĵ洢�ռ���
	static void	SetComSetupDataSet(int comID, NDataModelDataSet * pDataSet);

	/// ���ù������Ĳ������Ѿ����ڵĲ�����������
	/// û�е�����
	static void SetComSetupDataSet_V2( const int comID , NDataModelDataSet * pDataSet ) ; 

	/******************************************************************** 
	 �������������ַ����Ҷ�Ӧ��parmid��DataSet�����ڵ�����
	 ��    ����
	 �� �� ֵ��parmid��Ӧ��row,����-1��ʾû���ҵ���Ӧ��parmid
	 ��    ����
	 ע���������֮ǰ��pDataSetҪ��ParmId���򣨴Ӵ�С����
	 ��    �ߣ�zll
	 ʱ    �䣺8/7/2008   16:06
	*********************************************************************/ 
	static int	FindParmIdFromDS(NDataModelDataSet *pDataSet, const int &parmid);
	
	/******************************************************************** 
	 �������������ַ����Ҷ�Ӧ��parmid��DataSet�����ڵ�����
	 ��    ����row Ϊ��������������ҵ���parmid���л����parmid���������
	 �� �� ֵ���ҵ���Parmid�������棬��֮���ؼ�
	 ��    �����۰���ҷ�
	 ע�����������TRUE��rowΪҪ���У���֮��rowΪ���������
	 ��    �ߣ�zll
	 ʱ    �䣺14/7/2008   13:29
	*********************************************************************/ 
	static BOOL FindParmIdFromDS(NDataModelDataSet *pDataSet, const int &parmid, int &row);

	/**
	* @brief ��ȡ03G�� �����ܱ��� ָ���������� ParmID  
	*
	*          
	* @note  : Ŀǰ���� �ֽ���� ����ͼ�η� ��ʹ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/11/2011]
	*/
	static int GetComParms_Total03G_ParmID(const CString & strParmName);

private: 
	/******************************************************************** 
	 ����������GetComSetupDataSet
	 ��    ����
	 �� �� ֵ������ָ�����ָ�������������ñ�
	 ��    ����
	 ע�����������GetComSetupDataSet�������ã�
	 ��    �ߣ�zll
	 ʱ    �䣺10/7/2008   17:15
	*********************************************************************/ 
	static NDataModelDataSet * GetComSetupDataSet(int comID, int comType, NDataModelDataSet * pDataSetFromGlobe);

};

#endif // !defined(AFX_PARMACCESS_H__A0149476_B72F_44A6_9AB5_7A2EB9FD0F21__INCLUDED_)
