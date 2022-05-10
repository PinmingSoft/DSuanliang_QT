

#pragma once 

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// ���̵ĸ߶ȵ���

class PMProjectDBSERVICE CProjectGdtz
{
public:
	CProjectGdtz() ; 
	virtual ~CProjectGdtz() ; 

public:

	/// 
	/// ��ʾ��DataSet��Ҫ disparmname �� iuputmode ��
	/// 
	static NDataModelDataSet * GetShowDataset( const int iComType ) ;

	/// 
	/// �� pSrcDataSet ת��Ϊ pDesDataSet 
	///
	/// pSrcDataSet �Ǳ�table�Ľṹ
	/// pDesDataSet ����ʾDataset�Ľṹ
	/// 
	static void	ConvertDataSet( NDataModelDataSet * pSrcDataSet , NDataModelDataSet * pDesDataSet ) ; 

	static BOOL GetBgMode_ComID( const int  nComID , int & nMode) ;

	static BOOL GetBg_XDValue( const int  nComID , int & nMode , double & dibg, double & dbg ) ;

	static BOOL GetBg( const int  nComID , int & nMode , CParm & dibgParam, CParm & dbgParam ) ;

	/* @brief ��ȡ���ģʽ  
		*
		*          
		* @note  : nMode : 0 : nComID ��Ӧ��û�б��
		///			1 : nComID ��Ӧ��ֻ�С��ױ��
		///			2 : nComID ��Ӧ��ֻ�С������
		///			3 : nComID ��Ӧ���ױ�ߡ��͡�����ߡ�����
		* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
		* @date  : [17/8/2012]
	*/
	static BOOL GetBgMode_ComType( const int nComType, int & nMode);

	/**
	* @brief   ��ȡ��׼��ߵĲ�����
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [5/11/2018]
	*/
	static BOOL GetBgParmName( const int nComType, int & nMode, CStringArray & arrParmName);

	/**
	* @brief   ��ȡ���б�߲���������ʱ��׼��߻��Ƿǻ�׼���������
	*
	*			���ڻ�������ͨ���� һ����׼��� ���һ���������
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/11/2020]
	*/
	static BOOL GetBgParmNameFull( const int nComType, int & nMode, CString & topBGParm,CString & bottomBGParm);
} ; 



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
class PMProjectDBSERVICE CSysDataComParmSet_ParmValueCache
{
public:
	CSysDataComParmSet_ParmValueCache();

	virtual ~CSysDataComParmSet_ParmValueCache();

	BOOL GetParmValue(int iComType,int iSubComType,CString strParmName,CString & strParmValue,CString & stInvalidMsg);

protected:

	NDataModelDataSet * m_pComParmSetDataSet;
	int m_GangJinMode;
	int m_DefGangJinMode;
	CStringArray  m_SortFieldArr;
};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
class PMProjectDBSERVICE CSysData_ComParamsSet_GjTable
{
public:
	CSysData_ComParamsSet_GjTable() ; 
	virtual ~CSysData_ComParamsSet_GjTable() ; 

public:
	static  NDataModelDataSet * GetDataSet(const int comType) ;
};