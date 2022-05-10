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

	// �����ݿ��ж�ȡ�����ݼ���ȥ
	BOOL LoadDataSet(CString strPath);
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

	////�Ƿ��������ʽ��ö�٣���Ϊ���ʽ����,���� ��1 ��ʵ������Ϊ $shishu$
	BOOL IsChangeRegEnum() const;
	void SetChangeRegEnum(BOOL bChangeRegEnum);

protected:
	
private:
	BOOL CheckSameName(NDataModelDataSet * pDataSet,CString strName);
	BOOL TestFunction();

	CString m_strSoftCode;//���渽���ߴ� �������

	//�Ƿ��������ʽ��ö�٣���Ϊ���ʽ����,���� ��1 ��ʵ������Ϊ $shishu$
	BOOL m_bChangeRegEnum;
};

#endif // !defined(AFX_QDDE_FJCCMANAGER_H__E7F52D0D_8117_4088_AE35_62B1DB3C1772__INCLUDED_)
