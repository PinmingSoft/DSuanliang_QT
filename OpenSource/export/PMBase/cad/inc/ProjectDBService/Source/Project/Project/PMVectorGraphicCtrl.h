#pragma once

typedef std::map<CString,CString> ParmsMapInfo_T;

/**
* @brief  ʹ�ý�����Ϣ���� ���Ի��Ƶ� ������Ϣ ��ͨ�ù��ܺ���  
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: ����ҵ
* @date  : [17/11/2011]
*/
class PMProjectDBSERVICE CPMSLVectorGraphicCtrl
{
public:
	CPMSLVectorGraphicCtrl();
	~CPMSLVectorGraphicCtrl();

	/**
	* @brief  ʹ�ý�����Ϣxml ���ɿ��� ������Ϣ 
	*
	*          
	* @note  : 
	* @param : const CString & strVectorInfo:������Ϣ
	*			ParmsMapInfo_T * pParmMap��������Ϣ����
	*			CString & strCalVectorInfo�����ɵ� ������Ϣ
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/11/2011]
	*/
	BOOL BuildVectorInfo(const CString & strVectorInfo,ParmsMapInfo_T * pParmMap,CString & strCalVectorInfo);

	/**
	* @brief   ʹ�ý�����ϢDataSet ���ɿ��� ������Ϣ 
	*
	*          
	* @note  : 
	* @param : NDataModelDataSet * pVectorInfoDataSet��������Ϣ�� DataSet
	*			ParmsMapInfo_T * pParmMap��������Ϣ����
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/11/2011]
	*/
	BOOL BuildVectorInfo(NDataModelDataSet * pVectorInfoDataSet,ParmsMapInfo_T * pParmMap);

	/**
	* @brief   ʹ�� pComParmProps�滻JMInfo�е���Ϣ������Ϣ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [25/11/2011]
	*/
	BOOL ReSumJMParmValue(const CString & strJMInfo, CString &strSumValue, ParmsMapInfo_T * pComParmProps);

	/**
	* @brief  ʹ�� pComParmProps�滻strPointInfo�е���Ϣ (����Ϣ)
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [25/11/2011]
	*/
	BOOL ReSumPointInfo(const CString & strPointInfo, CString &strSumValue, ParmsMapInfo_T * pComParmProps,BOOL bNoCal = TRUE);

	/**
	* @brief  ���в������ ���ڱ��ʽstrParm�� ���������� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [25/11/2011]
	*/
	static BOOL ReSumParmValue(const CString & strParm, CString &strParmValue, ParmsMapInfo_T * pComParmProps,BOOL bNoCal = TRUE);

	static CString GetVectorParmValue(const CString & strParmName, ParmsMapInfo_T * pComParmProps);

protected:


};
