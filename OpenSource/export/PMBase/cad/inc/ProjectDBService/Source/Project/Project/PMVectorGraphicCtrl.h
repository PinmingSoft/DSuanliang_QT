#pragma once

typedef std::map<CString,CString> ParmsMapInfo_T;

/**
* @brief  使用截面信息创建 可以绘制的 截面信息 的通用功能函数  
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: 王建业
* @date  : [17/11/2011]
*/
class PMProjectDBSERVICE CPMSLVectorGraphicCtrl
{
public:
	CPMSLVectorGraphicCtrl();
	~CPMSLVectorGraphicCtrl();

	/**
	* @brief  使用截面信息xml 生成可以 绘制信息 
	*
	*          
	* @note  : 
	* @param : const CString & strVectorInfo:绘制信息
	*			ParmsMapInfo_T * pParmMap：截面信息参数
	*			CString & strCalVectorInfo：生成的 绘制信息
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/11/2011]
	*/
	BOOL BuildVectorInfo(const CString & strVectorInfo,ParmsMapInfo_T * pParmMap,CString & strCalVectorInfo);

	/**
	* @brief   使用截面信息DataSet 生成可以 绘制信息 
	*
	*          
	* @note  : 
	* @param : NDataModelDataSet * pVectorInfoDataSet：绘制信息的 DataSet
	*			ParmsMapInfo_T * pParmMap：截面信息参数
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/11/2011]
	*/
	BOOL BuildVectorInfo(NDataModelDataSet * pVectorInfoDataSet,ParmsMapInfo_T * pParmMap);

	/**
	* @brief   使用 pComParmProps替换JMInfo中的信息（面信息）
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [25/11/2011]
	*/
	BOOL ReSumJMParmValue(const CString & strJMInfo, CString &strSumValue, ParmsMapInfo_T * pComParmProps);

	/**
	* @brief  使用 pComParmProps替换strPointInfo中的信息 (点信息)
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [25/11/2011]
	*/
	BOOL ReSumPointInfo(const CString & strPointInfo, CString &strSumValue, ParmsMapInfo_T * pComParmProps,BOOL bNoCal = TRUE);

	/**
	* @brief  进行参数理解 （在表达式strParm中 拆解出参数） 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [25/11/2011]
	*/
	static BOOL ReSumParmValue(const CString & strParm, CString &strParmValue, ParmsMapInfo_T * pComParmProps,BOOL bNoCal = TRUE);

	static CString GetVectorParmValue(const CString & strParmName, ParmsMapInfo_T * pComParmProps);

protected:


};
