
#pragma once 



#include "AccessSysDataTable.h"

#define CsfVectorSpecMsgSplit		_T("##")

/**
 * @brief 
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CSysCsfvectordiagramTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysCsfvectordiagramTable)

	CSysCsfvectordiagramTable() ;
	~CSysCsfvectordiagramTable() ;

public:

	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString comtype;
		static const CString parmName;
		static const CString gangjin_mode ;
		static const CString valuevectorid;
		static const CString csflibcode;
		static const CString viewtext;
		static const CString VectorGraph;
		static const CString Msg;

		static int id_Idx ;
		static int comtype_Idx ;
		static int parmName_Idx ;
		static int gangjin_mode_Idx ;
		static int valuevectorid_Idx ;
		static int csflibcode_Idx ;
		static int viewtext_Idx ;
		static int VectorGraph_Idx ;
		static int Msg_Idx ;

		/// idx �����ĸ�������
		/// idx ��Ҫ�ں��� InitFieldStr �� ����ʼ��Ϊ�������ֵ
		/// �Ҹ�ֵ��˳��Ӧ�ú� InitFieldStr����ӵ�˳��һ��
		static int idx_step ; 
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};
};

class PmSLGJDataServiceAPI CAccessSysData_CsfvectordiagramTable : public CAccessSysDataTable
{
public:
	CAccessSysData_CsfvectordiagramTable() ;
	~CAccessSysData_CsfvectordiagramTable() ;

public:

	struct VectorGraphInfo
	{
		LPVOID m_lpstr;
		int m_buffSize;
	};

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
	* @brief   ��ȡͼ������ , 
	*
	*          
	* @note  : ��ȡ��ָ����Ҫɾ����ɾ��ʱ��Ҫʹ�� delete [] 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-10]
	*/

protected:
	BOOL		GetVectorGraph_VectorID( const int iComType , const int iVectorID , LPVOID & lpstr,int & buffSize) ;
public:
	BOOL		GetVectorGraph_VectorID( const int iGangJinMode , const int iComType , const int iVectorID , LPVOID & lpstr,int & buffSize) ;
	BOOL		GetVectorGraph_VectorIDAll( const int iGangJinMode, std::map<int, std::map<int, VectorGraphInfo> *> & vectorGraphMaps) ;

	/**
	* @brief   ��ȡͼ�ε�����
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-10]
	*/
public:
	BOOL		GetVectorName( int comType,const int iGangJinMode , const int iVectorID , CString & strVectorName);

protected:
	BOOL		GetMsg( const int iVectorId , CString & strMsg ) ;
	
public:
	BOOL		GetMsg( const int iVectorId ,int iGangJinMode, CString & strMsg );

	/**
	* @brief   ����ͼ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: ���� id 
	* @author: ����ҫ
	* @date  : [2012-7-10]
	*/
	int			InsertCSFVector();

	/// ��ȡ�յ�DataSet 
	CSysCsfvectordiagramTable * GetEmptyDataSet();

	///
	/// 
	///  dataset ��Ҫ��Χά�� ������ʹ���е�index��������д����
	///  
protected:
	NDataModelDataSet * GetCSFVectorDiagramDataSet(  const int comType, const CString & parmName , const CString & libCode);
	
public:
	NDataModelDataSet * GetCSFVectorDiagramDataSet(  const int comType, const CString & parmName , const CString & libCode,int iGangjinMode);

	/**
	* @brief ���ݱ������ ��ȡ ͼ��Ϣ  
	*
	*          
	* @note  : ������� ������03G�� 11G������
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/8/2012]
	*/
	/// ��ȡ����
	BOOL GetVectorGraph( const int id, const int comtype,  const int iGangJinMode , BYTE*&pbuff, int &buffSize) ;
	
	BOOL GetVectorGraph( const int id, const int comtype, const int iGangJinMode , LPVOID &lpstr, int &buffSize) ;

protected:
	//BOOL GetVectorGraph(int id, LPVOID &lpstr, int &buffSize) ;

public:
	BOOL GetVectorGraph(int id, LPVOID &lpstr, int &buffSize,int iGangJinMode, int comtype = 0);
	
	BOOL GetVectorGraph(int iComType,int iVectorID,const CString & strlibcode ,LPVOID &lpstr, long &buffSize) ;

protected:
	///
	/// 
	///  dataset ��Ҫ��Χά�� ������ʹ���е�index��������д����
	/// 
	/// �ú����ľ���ҵ�����
	/// ��Ҫ���ݵ��õĵط�ȥ���
	/// 
	NDataModelDataSet * GetTermDiagramDataSet(
		const int iComType,
		const CString & strParmName, 
		const CString & strTerm
		) ;

public:
	NDataModelDataSet * GetTermDiagramDataSet(
		const int iGangJinMode ,
		const int iComType,
		const CString & strParmName, 
		const CString & strTerm
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
	NDataModelDataSet * GetDataSet() ; 

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

protected:

	/// ��ȡ����id
	int		GetMaxId() ;


public:
	static PMTSTRING	GetSql( const int iType ) ;

	//�̶���SQL ����
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 


		/// 
		static const int m_iGetVectorGraph_VectorId ;
		static PMTSTRING m_strGetVectorGraph_VectorId ;

		/// 
		static const int m_iGetVectorName ;
		static PMTSTRING m_strGetVectorName ;

		/// 
		static const int m_iGetMaxId ; 
		static PMTSTRING m_strGetMaxId ; 

		/// 
		static const int m_iInsertCSFVector ; 
		static PMTSTRING m_strInsertCSFVector ; 

		/// 
		static const int m_iGetCSFVectorDiagramDataSet ;
		static PMTSTRING m_strGetCSFVectorDiagramDataSet ; 

		/// 
		static const int m_iGetVectorGraph ; 
		static PMTSTRING m_strGetVectorGraph ; 

		/// 
		static const int m_iGetTermDiagramDataSet ;
		static PMTSTRING m_strGetTermDiagramDataSet ;

		/// 
		static const int m_iGetMsg ; 
		static PMTSTRING m_strGetMsg ; 
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

class PmSLGJDataServiceAPI CSysDataCsfvectordiagramOpr
{
public:
	CSysDataCsfvectordiagramOpr() ; 
	~CSysDataCsfvectordiagramOpr() ; 

public:

};
