// QDDE_FJCCManager.h: interface for the CQDDE_FJCCManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QDDE_FJCCMANAGER_H__E7F52D0D_8117_4088_AE35_62B1DB3C1772__INCLUDED_)
#define AFX_QDDE_FJCCMANAGER_H__E7F52D0D_8117_4088_AE35_62B1DB3C1772__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// #ifdef PRJ_PMXML_DATASERVICE
// 	#define PMXMLDATASERVICEAPI __declspec(dllexport)
// #else
// 	#define PMXMLDATASERVICEAPI __declspec(dllimport)
// 	#ifdef PM_FOR_R15
// 		#pragma comment(lib,"PMXMLDataService15.lib")
// 	#else
// 		#pragma comment(lib,"PMXMLDataService16.lib")
// 	#endif
// #endif

class PMLogicDataOprAPI CQDDE_FJCCManager  
{
public:
	NDataModelDataSet * m_pDataSetQDDEFJCC;
	CQDDE_FJCCManager();
	virtual ~CQDDE_FJCCManager();
	BOOL LoadXML(CString sXMLName,CString strComName);

	// 从数据库中读取到数据集中去
	BOOL LoadDataSet(CString strPath);
	/******************************************************************** 
	 功能描述：获取软件编号
	 参数：
	 返 回 值：
	 算法：
	 注意事项：
	 作    者：王建业
	 时    间：[3/2/2009]
	*********************************************************************/ 
	CString GetSoftCode()
	{
		return m_strSoftCode;
	}

	////是否把正则表达式的枚举，改为表达式本身,比如 ：1 是实数，改为 $shishu$
	BOOL IsChangeRegEnum() const;
	void SetChangeRegEnum(BOOL bChangeRegEnum);

protected:
	
private:
	BOOL CheckSameName(NDataModelDataSet * pDataSet,CString strName);
	BOOL TestFunction();

	CString m_strSoftCode;//保存附件尺寸 软件编码

	//是否把正则表达式的枚举，改为表达式本身,比如 ：1 是实数，改为 $shishu$
	BOOL m_bChangeRegEnum;
};

#endif // !defined(AFX_QDDE_FJCCMANAGER_H__E7F52D0D_8117_4088_AE35_62B1DB3C1772__INCLUDED_)
