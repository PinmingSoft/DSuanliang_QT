#pragma once

//
class CPmComParmsDataSet :public CPM_SharebufferDataSet
{
public:
	DECLARE_DYNCREATE(CPmComParmsDataSet) 
	CPmComParmsDataSet(void);
	//CPmComParmsDataSet(NDataModelDataSet * pPrimaryDataSet,PMShared_Ptr<CParms> parms);
	CPmComParmsDataSet(PMShared_Ptr<NDataModelDataSet> pPrimaryDataSet);
	~CPmComParmsDataSet(void);

	//
	virtual BOOL SetBlob(const CString & Column, int row ,void * ppBolb,long iSize);
	virtual BOOL SetBlob(int Column, int row ,void * ppBolb,long iSize);

	virtual BOOL SetAsString(const CString & Column, int row,const CString& val);
	virtual BOOL SetAsFloat(const CString & Column, int row, const double& val);
	virtual BOOL SetAsInteger(const CString & Column, int row,const int& val);
	virtual BOOL SetAsBool(const CString & Column, int row, const BOOL & val);

	virtual BOOL SetAsString(int Column, int row ,const CString& val);
	virtual BOOL SetAsFloat(int Column, int row ,const double& val);
	virtual BOOL SetAsInteger(int Column, int row ,const int& val);
	virtual BOOL SetAsBool(int Column, int row ,const BOOL & val);

	/**
	* @brief  检查 传入的DataSet是否是 主DataSet
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [3/8/2012]
	*/
	BOOL CheckIsPrimaryDataSet(NDataModelDataSet * pCheckDataSet);

protected:
	//从 dataset 创建一个parms
	void InitParm(int row,CParm::ParmType parmType,CParm & parm) const;

	//设置参数
	void SetParm(CString fielName,int row,CString val,CParm::ParmType parmType);

protected:
	PMShared_Ptr<CParms> m_pParms;
};
