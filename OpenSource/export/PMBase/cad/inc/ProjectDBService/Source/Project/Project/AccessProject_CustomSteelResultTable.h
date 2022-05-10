#pragma once
//#include "..\accesstable.h"


class PMProjectDBSERVICE CProject_CustomSteelResultTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_CustomSteelResultTable)

	CProject_CustomSteelResultTable();
	virtual ~CProject_CustomSteelResultTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;					//�ñ���߼�id
		static const CString floorid;				//¥��
		static const CString comid;				//����
		static const CString gjlb;				//�ֽ����
		static const CString gjlx;				//�ֽ�����
		static const CString gjjb;				//�ֽ��
		static const CString zj;					//ֱ��
		static const CString gs;					//����
		static const CString th;					//ͼ��
		static const CString jt;					//��ͼ
		static const CString jsgs;				//���㹫ʽ
		static const CString wg;					//�乴
		static const CString tqd;					//��ǿ��
		static const CString dj;					//���
		static const CString cd;					//����
		static const CString jtgs;				//��ͷ����
		static const CString zz;					//����
		static const CString gsms;				//��ʽ����
		static const CString index0;				
		static const CString index1;				
		static const CString index2;				
		static const CString jtparms;				//��ͼ����
		static const CString sttype;				//�ֽ���� Ĭ��0ʱΪ�������ã�1ʱΪ�ֹ�����
		static const CString jtformula;			//��ͼ���㹫ʽ
		static const CString resulttype;			
		static const CString djxs;				
		static const CString errortype;			
		static const CString cc;				
		static const CString ccamount;			

		static const CString table_name;			//�ֽ��������
	};

	virtual int InitFieldStr();
};

class PMProjectDBSERVICE CAccessProject_CustomSteelResultTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_CustomSteelResultTable(void);

	virtual ~CAccessProject_CustomSteelResultTable(void);

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

	void SetResultDataSet( int nComID , CSQLDataSet * pDataSet ) ;

	void DeleteResnultDataSet( int nComID );

	CSQLDataSet * GetResultDataSet(int nComID );

	/// 
	CSQLDataSet * GetDataSet();

	/**
	* @brief ��ȡID�� ���ֵ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	BOOL GetMaxID(int & iMaxID);

	/// 
	BOOL GetTableCtrl( 
		const CString & strFloorIds , 
		const CString & strComTypes ,
		CPMSQLTableCtrl *& pTableCtrl 
		) ; 

public:

	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		//delete from customresult where comid=?
		const static int		m_iDeleteInfo_ComID;
		const static PmTString	m_strDeleteInfo_ComID;

		//select * from customresult where comid=?
		const static int		m_iSelectInfo_ComID;
		const static PmTString	m_strSelectInfo_ComID;

		/// 
		static const int		m_iGetTableCtrl ; 
		static const PMTSTRING	m_strGetTableCtrl ; 

		/// 
		static const int		m_iInsert_ComId ;
		static const PMTSTRING	m_strInsertComId ; 
	};
};
