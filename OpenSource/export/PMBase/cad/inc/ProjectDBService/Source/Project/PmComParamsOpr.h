

#pragma once 

/**
 * @brief ��������Ĳ����� 
 *			����������õ� ComType ����FloorGJXX ��Ӧ�� ComType
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-19]
 * @note  
 */

class PMProjectDBSERVICE CPmComParamsOpr
{
public:
	CPmComParamsOpr() ;
	~CPmComParamsOpr() ; 

public:

	//ȥ�� �������� ����
	static BOOL RemoveJSSZParmValue_Component();

	//��������� �� Ĭ�ϲ�����
	//static void SaveComParmTable_DataSet(NDataModelDataSet *pData);

	/**
	* @brief  ���ù������� �� Ĭ��ֵ 
	*
	*          
	* @note  : 
	* @param : const int iComType����������
	*			const int iFloorID������¥��
	*			NDataModelDataSet * pComParmsSet ��Ҫ���õ�DataSet
	*			BOOL bIsGraphic���Ƿ���ͼ�η�
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [14/9/2012]
	*/
	static BOOL SetDefaultComParmValue(  const int iComType,const int iFloorID, NDataModelDataSet * pComParmsSet ,BOOL bIsGraphic);

	static BOOL GetFloorGjxxParmValue(int iComType,int iFloorID,const CString& strParmName,CString& strParmValue);

	static BOOL GetFloorGJXX_ParmValue(const int & nFloor, const int & nComType , const CString & strParmName ,CString & strValue,CPMSQLTableCtrl * pFloorGJXXTableCtrl  ) ;

	static BOOL Get03GFloorMGDJValue(int iFloorID,int iComType,const CString & strParmName,CString & strParmValue  );

	static BOOL Get11GFloorMGDJValue(int iFloorID,int iComType,const CString & strParmName,CString & strParmValue  );

	///  ���е������ ---- �ڹ����ղ����õ� 
	///  �ղع�����ʱ�� Ӧ�� ���ղصĹ����� ���еĲ���ֵ����������
	///  ��Ϊ ��֪��������Ӧ��, ������Ҫ �������еĲ���ֵ 
	static CString SaveComParm2Str_Full ( int nComID , NDataModelDataSet * pDataSet ) ; 

	//����Ĭ�� �����ܱ�� ������Ϸ�ʽ
	//static BOOL SetComParmGujinZhuhe();

	/**
	* @brief  ���չ������� ��ȡ �������� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [23/7/2012]
	*/
	static NDataModelDataSet * GetComParmsTable_Jssz(int nComType);

	/**
	* @brief   ���ò����ܱ��� ָ���������� ����ֵ
	*
	*          
	* @note  : 
	* @param : const CString & strParmName��Ҫ���õĲ�������
	*			const CString & strParmValue:Ҫ���õ� ����ֵ
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/11/2011]
	*/
//	static BOOL SetComParms_TotalTable_ParmValue(const CString & strParmName,const CString & strParmValue);

	static BOOL GetComParms_TotalTable_ParmValueList(const CString & strParmName,CString & strParmValue,CString & strParmList);

	static BOOL GetGJTZZ_Const(const CString & strGJBLFS,CString & strDoubleGJTZZ,CString & strSingleGJTZZ);

	static BOOL GetGJTZZ_ComParmSet(CString & strDoubleGJTZZ,CString & strSingleGJTZZ);

	/**
	* @brief   ��ȡ �������е� ָ���������Ƶ� ������ʽ
	*
	*          
	* @note  : 
	* @param : const int nComType ����������
	*			const CString & strParmName ����������
	*			CString  &strRegValue:����������ʽ
	*
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/11/2011]
	*/
	//private:
	static	BOOL GetComParmSetTable_CheckReg( const int nComType , const CString & strParmName , CString  &strRegValue);


	/**
	* @brief  ��ȡ03G�����ܱ��� ָ���������� ����ֵ  
	*
	*          
	* @note  : �˺��� ֻ��ȥ 03G�еĲ���
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/11/2011]
	*/
	static BOOL GetComParms_Total03GTable_ParmValue(const CString & strParmName,CString & strParmValue);

	/******************************************************************** 
	������������ȡ������������
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[27/3/2009]
	*********************************************************************/ 
	static NDataModelDataSet * GetComponentFullGJSX( const int iComID );

	/**
	* @brief  ���� �����޸ĵ����� 
	*
	*          ���ڲ����ڲ������ӵ�������������
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [25/7/2012]
	*/
	static void SetComAttributes_UI( int iComID , NDataModelDataSet * pDataSet ) ;

	/// ��������޸�---������ĺ����������ǣ������ж���ı����������
	static void SetComAttributes_UISimple( int iComID , NDataModelDataSet * pDataSet) ;

	//��������ר�õĲ�������
	static void SetComAttributes_JSSZ( int iComID , const NDataModelDataSet * pDataSet ) ;

public:
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// ��ȡ�����ĵĳ��� --- ����ʹ�õĽӿ� ����ʱ��ȡ�ļ���Ч��ƫ��
	/// 
	static CString	GetCheckReg(const int iComType , const CString & strParamName ,const CString & strSubComType = _T("0") ) ;
	static CString	GetListData( const int iComType , const CString & strParamName ,const CString & strSubComType  = _T("0") ) ;
	static CString	GetValidateExpr( const int iComType , const CString & strParamName , const CString & strSubComType  = _T("0") ) ;
	static CString	GetHitInfo( const int iComType , const CString & strParamName , const CString & strSubComType  = _T("0") ) ;

	static CString	GetCheckRegInt(const int iComType , const CString & strParamName ,const int  iSubComType = 0 ) ;
	static CString	GetListDataInt( const int iComType , const CString & strParamName ,const int  iSubComType = 0 ) ;
	static CString	GetValidateExprInt( const int iComType , const CString & strParamName , const int  iSubComType = 0 ) ;
	static CString	GetHitInfoInt( const int iComType , const CString & strParamName ,const int  iSubComType = 0 ) ;


private:
	static	CString	GetConfigPath() ; 
	static	BOOL	GetComParmConstValue( const CString & strAppName , const CString & strKeyName , CString & strKeyValue ) ;

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// ���������е�һЩ����ѡ���ֵ�ͳ���
public:
	static CString	Getlcxz()  ;
	
	static CString GetTQD() ;
	
	static CString GetZDJ() ;
	
	static CString GetSJDJ() ;
	
	static CString GetKZDJ() ;
	
	static CString GetGJLX() ;
	
	static CString Getbfl() ;
	
	static CString GetJDFF() ;
	
	static CString Getbhc() ;
	
	static CString GetCG();

	static CString GetDjxs() ;
	
	/*static CString GetLDZG();*/

private:
	static CString GetConstFilePath() ; 

	static BOOL		GetListData( const CString & strAppName , const CString & strKeyName , CString & strKeyValue ) ;
	
};
