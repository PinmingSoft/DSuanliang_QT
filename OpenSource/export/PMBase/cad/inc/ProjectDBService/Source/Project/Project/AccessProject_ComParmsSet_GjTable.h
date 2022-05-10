

#pragma once  


////#include "..\accesstable.h"


class PMProjectDBSERVICE CProject_ComParamsSet_GjTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ComParamsSet_GjTable)

	CProject_ComParamsSet_GjTable();
	virtual ~CProject_ComParamsSet_GjTable();

public:
	virtual int InitFieldStr();

public:
	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString ParmID ;                      
		static const CString comtype ;                     
		static const CString SubComType ;                          
		static const CString parmname ;                    
		static const CString parmvalue ;                   
		static const CString InvalidMsg ;
	};

	struct PMProjectDBSERVICE CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

};

/**
 * @brief �����������ܱ�
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-18]
 * @note  ���������ֻ����Ϊ �������ñ����ֵ ���������ȡ��DataSet����SysData�е�DataSet 
		  ���Ըñ�ֻ�豣�沿���ֶΡ�
 */
class PMProjectDBSERVICE CAccessProject_ComParamsSet_GjTable : public CPMSLAccessTable 
{
public:
	CAccessProject_ComParamsSet_GjTable(void);
	virtual ~CAccessProject_ComParamsSet_GjTable(void);

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

	NDataModelDataSet * GetDataSet( const int comType);

	NDataModelDataSet * GetDataSet( const int comType,const int parmType);

	NDataModelDataSet * GetDataSet( const int comType,const int parmType , const int hide ) ;

	NDataModelDataSet * GetEmptyDataSet() ; 

	/**
	* @brief  ʹ��SysData�е����� ��Project�еĲ���������滻 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/9/2012]
	*/
	BOOL InitProjectDataSet();

	/// ��������
	void	SaveDataSet( NDataModelDataSet * pDataSet ) ;
	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;

private:

	/**
	* @brief   ����Comtype��parmname��ȡ parmvalue �� invalidmsg 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-18]
	*/
	BOOL	GetValueAndInvalidMsg( 
		const int iComType , const CString & strParmName ,
		CString & strValue , CString & strInvalidMsg
		) ;

	/// ͬ��value �� invalidmsg 
	void	SynsValueAndInvalidMsg( NDataModelDataSet * pDataSet ) ;

public:
	//�̶���SQL ����
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetValueAndInvalidMsg ; 
		static PMTSTRING m_strGetValueAndInvalidMsg ; 
	} ;
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

class PMProjectDBSERVICE CProjectComParamsSetGjOpr
{
public:
	CProjectComParamsSetGjOpr() ;
	~CProjectComParamsSetGjOpr() ; 

public:

	static NDataModelDataSet * GetDataSet() ; 

	static NDataModelDataSet * GetDataSet( const int comType);

	static NDataModelDataSet * GetDataSet( const int comType,const int parmType);

	static NDataModelDataSet * GetDataSet( const int comType,const CUIntArray & aryParmType);

	static NDataModelDataSet * GetDataSet( const int comType,const int parmType , const int hide ) ;

	static NDataModelDataSet * GetEmptyDataSet() ; 

	static void	SaveDataSet( NDataModelDataSet * pDataSet ) ;


};
