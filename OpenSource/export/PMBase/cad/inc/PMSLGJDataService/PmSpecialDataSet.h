// PmSpecialDataSet.h: interface for the CPmSpecialDataSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMSPECIALDATASET_H__FAB1A524_D27C_4045_A1F0_3346A89BD85A__INCLUDED_)
#define AFX_PMSPECIALDATASET_H__FAB1A524_D27C_4045_A1F0_3346A89BD85A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PmSLGJDataServiceAPI CPmSpecialDataSet  
{
public:

	CPmSpecialDataSet();
	virtual ~CPmSpecialDataSet();
	
	static NDataModelDataSet * GetDataSet(
		const int &comType , 
		const int &nGroupid);

	static NDataModelDataSet * GetPfliangDataSet();

	static NDataModelDataSet * GetPfZhuDataSet() ;
	static NDataModelDataSet * GetGrahpPfZhuDataSet();

	static NDataModelDataSet * GetPfAnZhuDataSet() ;

	static NDataModelDataSet * GetPfFajiDataSet() ;

	static NDataModelDataSet * GetPfBanDataSet() ;
	
	static NDataModelDataSet * GetPFTJDataSet() ;
	
	static NDataModelDataSet * GetTTYMJDataSet();

	static NDataModelDataSet * GetQTGJDataSet();
	
	static NDataModelDataSet * GetVectorGraphParms();

	static NDataModelDataSet * GetEditOtherItemDetailDataSet() ; 
	
	static NDataModelDataSet * GetGraphHJDDataSet();
	
	static NDataModelDataSet * GetGraphYaDingDataSet();
	
	static NDataModelDataSet * GetGraphLanBanDataSet();
	
	static NDataModelDataSet * GetGraphJSJDataSet();

	static CString GetDjxs(int nFloor, int nComType) ;

	static CPM_StorageDataSet * GetDjxsDataSet() ;

};

#endif // !defined(AFX_PMSPECIALDATASET_H__FAB1A524_D27C_4045_A1F0_3346A89BD85A__INCLUDED_)
