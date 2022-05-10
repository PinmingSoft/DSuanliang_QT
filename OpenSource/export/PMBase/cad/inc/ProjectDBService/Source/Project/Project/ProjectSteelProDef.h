

#pragma once 


/**
 * @brief �ֽ����Զ��� ������ �� �Ըֽ����ԵĻ��� 
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2013-5-27]
 * @note  
 */

typedef std::map< int , NDataModelDataSet * > PmInt2DataSetMap ; 
typedef PmInt2DataSetMap::iterator PmInt2DataSetMapIter ; 
typedef PmInt2DataSetMap::const_iterator PmInt2DataSetMapConIter ; 


class PMProjectDBSERVICE CProjectSteelProDefOpr
{
private:
	CProjectSteelProDefOpr() ; 

public:
	virtual ~CProjectSteelProDefOpr() ; 

	static CProjectSteelProDefOpr & Instance() ; 


public:
	/// �˳����Զ��壬��������
	void	Save() ; 


	void	Release() ;

public:

	///��ȡ�����Ĳ���(all)
	NDataModelDataSet * GetComParm( const int iComId )  ;

	/// 
	/// ��ȡ�ֽ���������ϵ����Զ��壬�������ߣ����ز���
	/// 
	NDataModelDataSet * GetSxdyDataSet( const int iComId ) ; 

	/// ����ȡ�ֽ����Զ���
	NDataModelDataSet * GetGJ_SxdyDataSet( const int iComId ) ;

	/// ����ȡ�������Զ���
	NDataModelDataSet * GetSL_SxdyDataSet( const int iComId ) ; 


	/// 
	/// �������Զ�������ݵ�����������
	/// 
	void		SetSxdyDataSet( const int iComId , NDataModelDataSet * pSxdyDataSet ) ;


	/// 
	NDataModelDataSet * GetJsszDataSet( const int iComId ) ; 

	/// 
	void		SetJsszDataSet( const int iComId , NDataModelDataSet * pJsszDataSet ) ;

	/// 
	int			GetComponentType( const int iComId ) ;

	/// 
	NDataModelDataSet * GetBaseSxDataSet( const int iComId ) ;

	void		SetBaseSxDataSet( const int iComId , NDataModelDataSet * pBaseSxDataSet ) ; 

	/// 
	NDataModelDataSet * GetDjxsDataSet( const int iComId ) ;

	void		SetDjxsDataSet( const int iComId , NDataModelDataSet * pDjxsDataSet ) ;

public:
	void		SetDataSet( const int iComId , const NDataModelDataSet * pDataSet ) ;


};


#define ProjectSteelProOpr CProjectSteelProDefOpr::Instance() 