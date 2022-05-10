#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CAccessProject_FloorTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_FloorTable(void);
public:
	virtual ~CAccessProject_FloorTable(void);

public:
	/// 
	void	GetFloorIdAry( CUIntArray & aryFloorId ) ;

	/**
	* @brief  ��� �Ƿ��� ������ 
	*
	*          
	* @note  : ����������
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [10/9/2012]
	*/
	BOOL CheckBaseFloor();

	/**
	* @brief ����Ƿ��� ������  
	*
	*          
	* @note  : 0�� �����ڵ����ҵ� ����
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [10/9/2012]
	*/
	BOOL CheckUnderBaseFloor();

	/**
	* @brief  ���� floorid �� lcmc�Ķ��� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [27/7/2012]
	*/
	BOOL GetFloorInfo_FloorID_LCMC(CUIntArray & iFloorIDArr,CStringArray & strLCMCArr);

	/**
	* @brief   ��ȡ floorid �� dwgͼֽ�� filename ��ƥ��
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [11/13/2019]
	*/
	BOOL GetFloorInfo_FloorID_DwgFile(CUIntArray & iFloorIDArr,CStringArray & strDwgFileArr);

	/**
	* @brief  ���� floorid��lcmc��FloorComment �Ķ��� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zy
	* @date  : [13/4/2018]
	*/
	BOOL GetFloorInfo_FloorID_LCMC_Remark(CUIntArray & iFloorIDArr,CStringArray & strLCMCArr,CStringArray & strFloorCommentArr);


	/**
	* @brief  �Ƿ� �Ƕ��� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [24/7/2012]
	*/
	BOOL IsTopFloor(int iFloorID);

	/**
	* @brief ��ȡ ���м�¼��  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [23/7/2012]
	*/
	BOOL GetAllInfo_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief �ж��Ƿ���ȫ�� ��ʾͼֽ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [20/7/2012]
	*/
	BOOL CheckIsAllFloorDWG(CString strDWGFile);

	/**
	* @brief   ���� ������ṹ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/6/2012]
	*/
	virtual BOOL TryUpdateTableField();

	/**
	* @brief  ��ȡ���� FloorID 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL GetMaxFloorID(int & iMaxFloorID);

	BOOL GetRowCount( int & iRowCount ) ;

	/**
	* @brief  ��ȡ ¥��ID ָ���� DataSet��Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: ��ΧDataSet  ��Ҫɾ��
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	CSQLDataSet * GetFloorID_DataSet(int iFloorID);

	/**
	* @brief  ��ȡ��ǰ¥��� ��ʾ˳�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	BOOL GetFloorShowID(int iFloorID,int & iShowID);
	
	/**
	* @brief �ж� ��ǰ¥��ID �Ƿ��� ������  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	BOOL IsUnderBaseFloor(int iFloorID);

	/**
	 * @brief �Дஔǰ���Ƿ��ǵ����ң�0�����¶���춵����� 
	 *
	 *        
	 * @author ֣����
	 * @version v1.0
	 * @date  2015��12��31��   15:32
	 * @note  
	 */
	BOOL IsBaseMent(int iFloorID);
	/**
	* @brief ��ȡ¥������  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	BOOL GetFloorLCMC(int iFloorID,CString &strLCMC);

	/**
	* @brief  ��ȡͼֽ ���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	BOOL GetFloorDwgName(int iFloorID,CString & strFileName);

	/**
	* @brief  ��ȡ¥��ID
	*
	*          
	* @note  :		ͨ��ͼֽ��������ȡ¥��ID
	* @param : 
	* @defenc: 
	* @return: 
	* @author: qf
	* @date  : [21/11/2013]
	*/

	BOOL	GetFloorIdByFloorDwg( int& iFloorID ,  const CString& strFileName );
	/**
	* @brief  ��ȡ¥������ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	BOOL GetFloorLDMBG(int iFloorID,int & iLDMBG);

	/**
	* @brief   ĳ��¥��Ķ����
	*
	*			
	* @note  : 
	* @param : nBgMode 0: ¥���� 1�����̱��
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/3/2017]
	*/
	BOOL GetFloorDingBg(int iFloorID,int nBgMode,int &nFloorDingBG);

	/**
	* @brief   ĳ��¥��ĵױ��
	*
	*			
	* @note  : 
	* @param : nBgMode 0: ¥���� 1�����̱��
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/3/2017]
	*/
	BOOL GetFloorDiBg(int iFloorID,int nBgMode,int &nFloorDiBG);

	/**
	* @brief  ��ȡ���
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	BOOL GetFloorCg(const int iFloorID,int & iCg);

	/// ��ȡ���
	BOOL	GetFloorBh( const int iFloorID , int & iBh ) ;

	
	
	/**
	* @brief  ��ȡFloor�� ���ݣ�DataSet��Ҫɾ�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [10/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	BOOL GetTableCtrl_FloorID(int iFloorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief  ��ȡ��ǰ ¥�� ID�� ���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [20/7/2012]
	*/
	BOOL GetFloorCS(int iFloorID,int & iCS);

	///��ȡ�� ShowID ����� DataSet 
	CSQLDataSet * GetSortDataSet() ;

	//��ȡ ���е����ҵ� ¥��ID 
	BOOL GetUnderFloors(CUIntArray & nArrFloors);

	BOOL	HasDxs() ; 

	//����ĳһ������彨�����
	void SetZtjzmj( const int nFloorID , const CString & strZtjzmj );
	//��ȡ
	BOOL GetZtjzmj( const int nFloorID , CString &strZtjzmj);

	

	//����ĳһ�����̨�������
	void SetYtjzmj(const int nFloorID , const CString & strYtjzmj );
	//��ȡ
	BOOL GetYtjzmj( const int nFloorID , CString & strYtjzmj);

	
	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;

private:
	BOOL	SetColValue( const int iFloorId , const CString & strColName , const CString & strColValue ) ;


public:

	struct PMProjectDBSERVICE SQLInfo
	{
		static const PmTString m_selectShowID_SQL;//��ȡShowID�� sql
		static const PmTString m_selectCG_SQL;//��ȡ��ߵ� sql��
		static const PmTString m_selectLDMBG_SQL;//��ȡ¥������ sql��
		static const PmTString m_selectLCMC_SQL;//��ȡ¥������ sql
		static const PmTString m_selectDWGFileName_SQL;//��ȡDWG�ļ����Ƶ� sql
		static const PmTString m_selectFloorId_SQL;//��ȡ¥��ŵ� sql
		static const int		m_iSelectAllInfo_FloorID;
		static const PmTString	m_strSelectAllInfo_FloorID;

		/// 
		static const int m_iGetSortDataSet ; 
		static PMTSTRING m_strGetSortDataSet ; 

		/// 
		static const int m_iSetColValue ;
		static PMTSTRING m_strSetColValue ; 
	};
};


/**
* @brief   ��װһЩ��ʱ����Ķ������
*
*          
* @note  : ����Ҫÿһ���õ��ĵط���ȥ����һ����ʱ���� �� ��һЩ�������͵�ת�������ڸ�����ʵ��
*
* @author: ����ҫ
* @date  : [2012-7-17]
*/


class PMProjectDBSERVICE CProjectFloorOpr 
{
public:
	CProjectFloorOpr() ;
	~CProjectFloorOpr() ; 

public:
	static NDataModelDataSet * GetDataSet() ; 
	static NDataModelDataSet * GetSortDataSet() ;

	static BOOL GetFloorLDMBG(const int iFloorID,int & iLDMBG);
	static BOOL GetFloorLDMBG(const int iFloorID,double & dLDMBG);
	static BOOL GetFloorLDMBG(const int iFloorID,CString & strLDMBG);

	/// ��λΪm
	static BOOL GetFloorTopBg(const int iFloorID,double & dTopBg);

	static BOOL GetFloorShowId( const int iFloorId , int & iShowId ) ;

	static BOOL GetFloorCg(const int iFloorID , int & iCg );
	static BOOL GetFloorCg( const int iFloorId , CString & strCg ) ;

	static BOOL GetFloorCS(const int iFloorID,int & iCS) ; 
	static int	GetFloorCs( const int iFloorId ) ;

	static BOOL GetFloorLCMC( const int iFloorID,CString &strLCMC); 

	static BOOL GetFloorDwgName(const int iFloorID,CString & strFileName);

	//��ȡ ���е����ҵ� ¥��ID 
	static BOOL GetUnderFloors(CUIntArray & nArrFloors);

	static BOOL	HasDxs() ; 

	/// 
	static BOOL GetRowCount( int & iRowCount ) ;

	/// 
	static BOOL	GetFloorBh( const int iFloorID , int & iBh ) ; 


	//����ĳһ������彨�����
	static void SetZtjzmj( const int nFloorID , const CString & strZtjzmj );
	//��ȡ
	static BOOL GetZtjzmj( const int nFloorID , CString &strZtjzmj);

	static CString GetJzmjFromResult( const int iFloorId ) ;


	//����ĳһ�����̨�������
	static void SetYtjzmj(const int nFloorID , const CString & strYtjzmj );
	//��ȡ
	static BOOL GetYtjzmj( const int nFloorID , CString & strYtjzmj);

	static BOOL IsUnderBaseFloor( const int iFloorID);

	/// ȡ¥����еĵ�һ���¥������
	static double	GetSnbg() ;
};
