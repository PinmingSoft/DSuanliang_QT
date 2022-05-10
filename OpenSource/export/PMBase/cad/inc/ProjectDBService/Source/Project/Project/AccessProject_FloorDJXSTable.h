#pragma once
//#include "..\accesstable.h"


class PMProjectDBSERVICE CAccessProject_FloorDJXSTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_FloorDJXSTable(void);

	virtual ~CAccessProject_FloorDJXSTable(void);

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

	BOOL GetDJXS_Buffer(int nComType, BOOL bSx ,LPVOID & pBuffer,ULONG & lBufferSize);

	BOOL GetDJXS_Str( const int iComType , const BOOL bSx , CString & strDjxs ) ;

	BOOL GetDJXS_Str_Gj( const int iComType , const BOOL bSx , CString & strDjxs ) ;


	NDataModelDataSet * GetDataSet( const int iComType , BOOL bSx = FALSE ) ;

	CSQLDataSet * GetEmptyDataSet();

	void	ClearTable() ; 

	/// ��������ȡ�����ʽ
	NDataModelDataSet * GetDataSet_Gj( const int iComType , BOOL bSx = FALSE ) ;

	static CString GetDJXSListDta();

	static CPM_StorageDataSet * GetMiniDataSet();

	BOOL GetDJXS_ZJValue( const int iFloorID, const int iComType,const CString & strZJ,CString & strDJValue);

public:
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
	CSQLDataSet * GetDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);
	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;



protected:

	CPM_StorageDataSet * GetJcData();
	CPM_StorageDataSet * GetQtData(int nComType);
	CPM_StorageDataSet * GetBanData();
	CPM_StorageDataSet * GetZhuData();
	CPM_StorageDataSet * GetQiangData(BOOL bSx);
	CPM_StorageDataSet * GetAnZhuData();

	CPM_StorageDataSet * GetDataSet(const CString & strColName);

public:
	//�̶���SQL ����
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 
	} ;

protected:
	//�̶���SQL ����
	static PmTString m_strSelectDJXS_SQL;//��ȡ comparm buffer��sql��


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

class PMProjectDBSERVICE CProjectFloorDjxsOpr
{
public:
	CProjectFloorDjxsOpr() ;
	~CProjectFloorDjxsOpr() ; 

public:
	static BOOL GetDJXS_ZJValue( const int iFloorID, const int iComType,const CString & strZJ,CString & strDJValue);

	static NDataModelDataSet * GetDataSet( const int iComType , BOOL bSx = FALSE ) ;
};
