// QDDE_JSGZManager.h: interface for the CQDDE_JSGZManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QDDE_JSGZMANAGER_H__35F989C5_3179_4D3D_B897_87B3A86FEE0D__INCLUDED_)
#define AFX_QDDE_JSGZMANAGER_H__35F989C5_3179_4D3D_B897_87B3A86FEE0D__INCLUDED_

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

class PMLogicDataOprAPI CQDDE_JSGZManager  
{
public:
	NDataModelDataSet * m_pDataSetQDDEJSGZ;
	CQDDE_JSGZManager();
	virtual ~CQDDE_JSGZManager();
	BOOL LoadXML(CString sXMLName,CString strComName);

	/******************************************************************** 
	 ������������ȡ������
	 ������
	 �� �� ֵ��
	 �㷨��
	 ע�����
	 ��    �ߣ�����ҵ
	 ʱ    �䣺[3/2/2009]
	*********************************************************************/ 
	CString GetSoftCode()
	{
		return m_strSoftCode;
	}
	
protected:
//	CString GetXmlNodeAttri(MSXML::IXMLDOMNodePtr ptr,CString sAttriName);
	
	CString m_strSoftCode;//���������� �������
};

#endif // !defined(AFX_QDDE_JSGZMANAGER_H__35F989C5_3179_4D3D_B897_87B3A86FEE0D__INCLUDED_)
