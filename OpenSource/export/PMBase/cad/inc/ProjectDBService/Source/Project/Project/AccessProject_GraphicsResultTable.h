#pragma once
////#include "..\accesstable.h"


class PMProjectDBSERVICE CAccessProject_GraphicsResultTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_GraphicsResultTable(void);

	virtual ~CAccessProject_GraphicsResultTable(void);

	BOOL DelResultFloor_Component(int iFloorID, int iComID,const CString & strCADHandle);

	BOOL DelResultCurFloor_Component(int iComID,const CString & strCADHandle);

	

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
	* @brief ��ȡ ������ ��¼��  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/7/2012]
	*/
	BOOL GetResult_ComIDFloorID_TableCtrl(int iComID,int iFloorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/// 
	BOOL	GetResult_ComType_FloorId_TableCtrl( const int iComType , const int iFloorId , CPMSQLTableCtrl *&pSqlTableCtrl ) ;

	/**
	* @brief  ��ȡ ������ ���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/7/2012]
	*/
	BOOL GetCalResult(int iComID, int iComType,const CString & strHandle, CString &strResult);

	BOOL GetResultSumWeight_GJ(int iFloorID, int iComID, CString strHandle, double &dWeight);

	BOOL DeleteResultInfo( const CUIntArray & iDelIdArr);

	/**
	* @brief  ɾ��ָ����¥�� �� �������͵ļ�¼ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [20/7/2012]
	*/
	BOOL DelResultFloor_ComType( const CUIntArray &iFloorIDArr, const  CUIntArray &iComTypeArr);

	BOOL DelResultFloor( const int iFloorId ) ;

	/**
	* @brief   ��ȡ��������ݣ����Ƽ�ʹ�ã�
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-12]
	*/
	NDataModelDataSet * GetDataSet() ; 

	CSQLDataSet * GetEmptyDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet * pResultDataSet);

	/// ��������id
	void SaveDataSetReCalId(CSQLDataSet * pResultDataSet);

	NDataModelDataSet * GetResultDataSet_DGJCL(int iFloorID,int iComID, CString strHandle,CString & strCurHandle);

	void InsertResult( const int iComId , NDataModelDataSet * pDataSet) ; 

	static PmTString GetSQL(const int iSQLIndex);

	BOOL SaveResult_SimCom(int iFloorID, int iComID, const CString & strHandle, NDataModelDataSet *pResultDataSet);


	/// 
	BOOL GetTableCtrl( 
		const CString & strFloorIds , 
		const CString & strComTypes ,
		CPMSQLTableCtrl *& pTableCtrl 
		) ; 

	/// 
	/// ������������ʱ����ã�ֻ��Ҫ��ȡ handle  һ���ֶ� ׷�� һ���ֶ�id
	///
	/// select id ,cadhandle from graphicsresult where floorid = ? 
	BOOL GetTableCtrl( 
		const int iFloorId ,
		CPMSQLTableCtrl *& pTableCtrl 
		) ; 

protected:
	/// 
	/// mapComId2HandleAry Ϊ����Ҫɾ���Ĺ�����handle
	/// 
	BOOL DelResult( const int iFloorId , const PmInt2StrSetMap & mapComId2HandleAry ) ;

	
	/// 
	/// setHandle Ϊ����Ҫɾ����handleset
	/// 
	/// aryResultId ����Ҫ���
	BOOL	GetResultId( const int iFloorId , const int iComId , const PmStrSet & setHandle , CUIntArray & aryResultId ) ;

public:

	/// ɾ��ָ�������� ������
	/// �ýӿ�ֻ�ڹ���ɾ����ʱ�����
	void				DelResult( const int iComId ) ; 

	/// 
	/// ����ɾ��������ʱ�򣬵��õĽӿ�
	/// 
	void				DelResult( const CUIntArray & aryComId ) ; 

	/// ���ݽ�������ж��Ƿ�����
	BOOL				IsLock( const int iResultType ) ;

	/// ��ȡԭʼ�Ľ������
	int					GetOrgResultType( const int iResultType ) ; 

	/// ��ȡ������Ľ������
	int					GetLockResultType( const int iResultType ) ; 

	/// ��ȡָ��id��DataSet
	CSQLDataSet	*		GetDataSet( const CUIntArray & aryResultId ) ;				

public:

	void				DeleteResult( const CUIntArray & aryResultId ) ;

protected:


protected:
	

	void				InsertDataSet( NDataModelDataSet * pDataSet ) ;

public:
	/// ȥ��û�й�����֮��Ӧ�Ľ��
	void				RemoveDirtyData() ; 

public:

	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		static const int		m_iSelectResult_ComIDFloorID;
		static const PmTString	m_strSelectResult_ComIDFloorID;//ͨ�� comID floorid ��ȡ ��¼��

		static const int		m_iDeleteResult_id;
		static const PmTString	m_strDeleteResult_id;

		static const int		m_iDeleteResult_FloorComType;
		static const PmTString	m_strDeleteResult_FloorComType;//��¥�� �������� ɾ��

		/// 
		static const int		m_iDelResult ;
		static const PMTSTRING	m_strDelResult ; 

		/// 
		static const int		m_iDelResult_IdArr ;
		static const PMTSTRING	m_strDelResult_IdArr ; 

		/// 
		static const int		m_iInsertDataSet ;
		static const PMTSTRING	m_strInsertDataSet ; 

		///delete from grahicgresult where comid=? and cadhandle=?
		static const int		m_iDeleteResult_ComIDHandle;
		static const PmTString	m_strDeleteResult_ComIDHandle;//��¥�� ���� ɾ��

		///// delete from graphicresult where floorid = ? and cadhandle = ? 
		static const int		m_iDeleteResult_FloorHandle ;
		static const PmTString	m_strDeleteResult_FloorHandle ;

		/// select cadhandle from graphicsresult where floorid = ? 
		static const int		m_iSelectResult_FloorId ;
		static const PMTSTRING	m_strSelectResult_FloorId ;

		/// ���� floorid �� comtype ��ȡ����¼��
		static const int		m_iGetComTypeFloorTableCtrl ; 
		static const PMTSTRING	m_strGetComTypeFloorTableCtrl ; 

	};
};



/**
* @brief   ��װһЩ��ʱ����Ķ������ (�䵱 ����Access�� ������)
*
*          
* @note  : ����Ҫÿһ���õ��ĵط���ȥ����һ����ʱ���� �� ��һЩ�������͵�ת�������ڸ�����ʵ��
*
* @author: ����ҫ
* @date  : [2012-7-17]
*/

class PMProjectDBSERVICE CProjectGraphicsResultOpr
{
public:
	CProjectGraphicsResultOpr() ;
	~CProjectGraphicsResultOpr() ; 

public:

	static NDataModelDataSet * GetDataSet() ; 
	static NDataModelDataSet * GetEmptyDataSet() ;
	static void InsertResult( const int iComId , NDataModelDataSet * pDataSet) ; 

	/// ���ݽ�������ж��Ƿ�����
	static BOOL				IsLock( const int iResultType ) ;

	/// ��ȡԭʼ�Ľ������
	static int					GetOrgResultType( const int iResultType ) ; 

	/// ��ȡ������Ľ������
	static int					GetLockResultType( const int iResultType ) ; 
};
