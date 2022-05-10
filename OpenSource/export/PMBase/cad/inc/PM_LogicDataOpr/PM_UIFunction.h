#pragma once

namespace UIFunction
{
	class PMLogicDataOprAPI PMMfc_ResourceOverride
	{
	public:
		PMMfc_ResourceOverride(HINSTANCE _dllhInstance)
		{
			m_OldInstance = AfxGetResourceHandle();
			AfxSetResourceHandle(_dllhInstance); 
		}
		~PMMfc_ResourceOverride()
		{
			AfxSetResourceHandle(m_OldInstance); 
		}
	protected:
		HINSTANCE m_OldInstance;
	};

	/******************************************************************** 
	 �������������˽���ID �Ƿ��ڻ״̬
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[12/3/2009]
	*********************************************************************/ 
	PMLogicDataOprAPI BOOL CheckProcessRunMode(DWORD dwProcessId);

	/**
	* @brief ��������Ϣ �� Rows  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [27/3/2013]
	*/
	PMLogicDataOprAPI CPM_StorageDataSet * RowsCopy(  NDataModelDataSet * pSrcDataSet  );

	/**
	* @brief  dataset��¡,Ҫ��T ֧��InitField ����
	*
	*          NDataModelDataSet::Clone() ��¡�����Ķ�����ԭ�ж���ֻ�ǽ������������Ӷ���
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [4/8/2019]
	*/
	template <class T> T * CloneDataSet(T * pSrcDataSet)
	{
		T * pDataSetNew = PMNew(T);
		pDataSetNew->InitFieldStr();
		pSrcDataSet->RowsCopy( 1 , pSrcDataSet->GetRowCount() , NDataModelDataSet::Primary , pDataSetNew ,1, NDataModelDataSet::Primary ) ;

		//
		return pDataSetNew;
	}
	/**
	* @brief ���� ���ṹ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [27/3/2013]
	*/
	PMLogicDataOprAPI BOOL CopyDataSetField(NDataModelDataSet * pFromDataSet,NDataModelDataSet * pToDataSet);

	/******************************************************************** 
	 ����������ʹ���۰���ҷ�������DataSet�в���int�����ز��ҵ�������
	 ������strFieldName��Ҫ���ҵ��ֶ�����iValue:���ҵ�ֵ
	 �� �� ֵ�������� ��-1��û���ҵ���
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[15/11/2007]
	*********************************************************************/ 	
	PMLogicDataOprAPI int FindInt_DataSet(NDataModelDataSet * pDataSet,CString strFieldName,int iValue);
	PMLogicDataOprAPI int FindInt_DataSet(NDataModelDataSet * pDataSet,CString strFieldName,int iValue,BOOL bNeedSort);
	PMLogicDataOprAPI int FindInt_DataSet(NDataModelDataSet * pDataSet,int iFieldIndex,int iValue,BOOL bNeedSort = TRUE);

	/******************************************************************** 
	 ����������ʹ���۰���ҷ�������DataSet�в���String�����ز��ҵ�������
	 ������strFieldName��Ҫ���ҵ��ֶ�����iValue:���ҵ�ֵ
	 �� �� ֵ�������� ��-1��û���ҵ���
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[15/11/2007]
	*********************************************************************/ 	
	PMLogicDataOprAPI int FindString_DataSet(NDataModelDataSet * pDataSet,CString strFieldName,CString strValue);
	PMLogicDataOprAPI int FindString_DataSet(NDataModelDataSet * pDataSet,CString strFieldName,CString strValue,BOOL bNeedSort);
	PMLogicDataOprAPI int FindString_DataSet(NDataModelDataSet * pDataSet,int iFieldIndex,CString strValue,BOOL bNeedSort = TRUE);

	/******************************************************************** 
	 ������������ȡDataSet�е� ParmValue
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[14/1/2010]
	*********************************************************************/ 
	PMLogicDataOprAPI BOOL GetComParmsDataSet_ParmValue(NDataModelDataSet * pComParmsDataSet,const CString & strParmName,CString & strParmValue,CString & strInvalidMsg);
	PMLogicDataOprAPI BOOL SetComParmsDataSet_ParmValue(NDataModelDataSet * pComParmsDataSet,const CString & strParmName,CString strParmValue,CString strInvalidMsg);

	/****************************************************************
	  ������������DataSet����� Txt�ļ���
		������
		�� �� ֵ��
		�㷨��
		ע�����
		��    �ߣ�����ҵ
		ʱ    �䣺[2011:5:12   10:24]
	*****************************************************************/
	PMLogicDataOprAPI BOOL TraceDataSet_Txt(NDataModelDataSet * pDataSet,CString strPrintFileName);

	/******************************************************************** 
	 ������������Html���DataSet
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[2/9/2008]
	*********************************************************************/ 
	PMLogicDataOprAPI BOOL TraceDataSet_HTML(NDataModelDataSet * pDataSet,CString strPrintFileName);

	// ָ����Ҫ��ӡ����
	PMLogicDataOprAPI BOOL TraceDataSet_HTML(
		NDataModelDataSet * pDataSet,
		const CStringArray & fieldnames , 
		const CString strPrintFileName
		);
	PMLogicDataOprAPI BOOL TraceDataSet_HTML(
		NDataModelDataSet * pDataSet,
		const CStringArray & fieldnames , 
		const CStringArray & fieldChNames , 
		const CString strPrintFileName
		);

	// ������������װ��AfxMessageBox
	PMLogicDataOprAPI int PMMessageBox(LPCTSTR pMsg ,LPCTSTR pCaption = _T(""),UINT uType = MB_OK );
	// ֧��ָ�������ھ��
	PMLogicDataOprAPI int PMMessageBox(HWND hWnd, LPCTSTR pMsg ,LPCTSTR pCaption = _T(""),UINT uType = MB_OK);

	/******************************************************************** 
	 ������������������ָ�����ַ����������ȡ��
	 ������strNameArray:����Ҫ��ֵ��ַ��� strCompos:��ֵı�־�ַ��� strValueArray����ֵĽ��
	 �� �� ֵ��
	 �㷨��
	 ע���������Ҫ��ֵ��ַ�������ֵı�־����һ��
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[29/10/2007]
	*********************************************************************/ 
	PMLogicDataOprAPI void StringCompositorArray(CStringArray & strNameArray,CString strCompos,CStringArray & strValueArray);//
};
