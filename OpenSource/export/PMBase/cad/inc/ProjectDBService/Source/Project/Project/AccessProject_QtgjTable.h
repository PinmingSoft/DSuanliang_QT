

#pragma once 

////#include "..\accesstable.h"


class PMProjectDBSERVICE CAccessProject_QtgjTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_QtgjTable(void);

	~CAccessProject_QtgjTable(void);

public:
	virtual BOOL TryUpdateTableField();

	

	/**
	* @brief   ��ȡ�汾��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-3]
	*/
	static	int	GetCurVersion() ;

	NDataModelDataSet * GetEmptyDataSet() ;

	BOOL SaveDataSet( CSQLDataSet * pDataSet ) ;

	int Insert( 
		NDataModelDataSet * pDataSet ,
		const int iId ,
		const int nComType ,
		const CString & strShowName ,
		const CString & strQtgj 
		) ;

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

	int		GetMaxId() ;

	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;


public:
	//�̶���SQL ����
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 
	} ;

};
