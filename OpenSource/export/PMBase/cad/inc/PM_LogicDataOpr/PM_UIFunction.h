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
	 功能描述：检查此进程ID 是否在活动状态
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[12/3/2009]
	*********************************************************************/ 
	PMLogicDataOprAPI BOOL CheckProcessRunMode(DWORD dwProcessId);

	/**
	* @brief 复制行信息 到 Rows  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [27/3/2013]
	*/
	PMLogicDataOprAPI CPM_StorageDataSet * RowsCopy(  NDataModelDataSet * pSrcDataSet  );

	/**
	* @brief  dataset克隆,要求T 支持InitField 函数
	*
	*          NDataModelDataSet::Clone() 克隆出来的对象不是原有对象，只是建立了数据链接而已
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
	* @brief 复制 表格结构  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [27/3/2013]
	*/
	PMLogicDataOprAPI BOOL CopyDataSetField(NDataModelDataSet * pFromDataSet,NDataModelDataSet * pToDataSet);

	/******************************************************************** 
	 功能描述：使用折半查找方法，在DataSet中查找int，返回查找的所在行
	 参数：strFieldName：要查找的字段名，iValue:查找的值
	 返 回 值：所在行 （-1：没有找到）
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[15/11/2007]
	*********************************************************************/ 	
	PMLogicDataOprAPI int FindInt_DataSet(NDataModelDataSet * pDataSet,CString strFieldName,int iValue);
	PMLogicDataOprAPI int FindInt_DataSet(NDataModelDataSet * pDataSet,CString strFieldName,int iValue,BOOL bNeedSort);
	PMLogicDataOprAPI int FindInt_DataSet(NDataModelDataSet * pDataSet,int iFieldIndex,int iValue,BOOL bNeedSort = TRUE);

	/******************************************************************** 
	 功能描述：使用折半查找方法，在DataSet中查找String，返回查找的所在行
	 参数：strFieldName：要查找的字段名，iValue:查找的值
	 返 回 值：所在行 （-1：没有找到）
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[15/11/2007]
	*********************************************************************/ 	
	PMLogicDataOprAPI int FindString_DataSet(NDataModelDataSet * pDataSet,CString strFieldName,CString strValue);
	PMLogicDataOprAPI int FindString_DataSet(NDataModelDataSet * pDataSet,CString strFieldName,CString strValue,BOOL bNeedSort);
	PMLogicDataOprAPI int FindString_DataSet(NDataModelDataSet * pDataSet,int iFieldIndex,CString strValue,BOOL bNeedSort = TRUE);

	/******************************************************************** 
	 功能描述：获取DataSet中的 ParmValue
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[14/1/2010]
	*********************************************************************/ 
	PMLogicDataOprAPI BOOL GetComParmsDataSet_ParmValue(NDataModelDataSet * pComParmsDataSet,const CString & strParmName,CString & strParmValue,CString & strInvalidMsg);
	PMLogicDataOprAPI BOOL SetComParmsDataSet_ParmValue(NDataModelDataSet * pComParmsDataSet,const CString & strParmName,CString strParmValue,CString strInvalidMsg);

	/****************************************************************
	  功能描述：将DataSet输出到 Txt文件中
		参数：
		返 回 值：
		算法：
		注意事项：
		作    者：王建业
		时    间：[2011:5:12   10:24]
	*****************************************************************/
	PMLogicDataOprAPI BOOL TraceDataSet_Txt(NDataModelDataSet * pDataSet,CString strPrintFileName);

	/******************************************************************** 
	 功能描述：以Html输出DataSet
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[2/9/2008]
	*********************************************************************/ 
	PMLogicDataOprAPI BOOL TraceDataSet_HTML(NDataModelDataSet * pDataSet,CString strPrintFileName);

	// 指定需要打印的列
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

	// 功能描述：包装的AfxMessageBox
	PMLogicDataOprAPI int PMMessageBox(LPCTSTR pMsg ,LPCTSTR pCaption = _T(""),UINT uType = MB_OK );
	// 支持指定父窗口句柄
	PMLogicDataOprAPI int PMMessageBox(HWND hWnd, LPCTSTR pMsg ,LPCTSTR pCaption = _T(""),UINT uType = MB_OK);

	/******************************************************************** 
	 功能描述：将名称中指定的字符串后的数字取出
	 参数：strNameArray:传入要拆分的字符串 strCompos:拆分的标志字符串 strValueArray：拆分的结果
	 返 回 值：
	 算法：
	 注意事项：传入要拆分的字符串，拆分的标志必须一致
	 作    者：王建业
	 时    间：[29/10/2007]
	*********************************************************************/ 
	PMLogicDataOprAPI void StringCompositorArray(CStringArray & strNameArray,CString strCompos,CStringArray & strValueArray);//
};
