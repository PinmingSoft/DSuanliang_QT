

#pragma  once 


#include "AccessSysData_CsfvectordiagramTable.h"

/**
 * @brief 
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CSysCsfvectordiagram_GjTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysCsfvectordiagram_GjTable)

	CSysCsfvectordiagram_GjTable() ;
	~CSysCsfvectordiagram_GjTable() ;

public:
	virtual int InitFieldStr() ; 

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

class PmSLGJDataServiceAPI CAccessSysData_Csfvectordiagram_GjTable : public CAccessSysDataTable
{
public:
	CAccessSysData_Csfvectordiagram_GjTable() ;
	~CAccessSysData_Csfvectordiagram_GjTable() ;

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
	NDataModelDataSet * GetCSFVectorDiagramDataSet(  const int comType, const CString & parmName , const CString & libCode);

	/// ��ȡ����
	BOOL GetVectorGraph( const int id, const int comtype, BYTE*&pbuff, int &buffSize) ;

	BOOL GetVectorGraph( const int id, const int comtype, LPVOID &lpstr, int &buffSize) ;

	BOOL GetVectorGraph(int id, LPVOID &lpstr, int &buffSize) ;

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

class PmSLGJDataServiceAPI CSysDataCsfvectordiagramGjOpr
{
public:
	CSysDataCsfvectordiagramGjOpr() ; 
	~CSysDataCsfvectordiagramGjOpr() ; 

public:

	static NDataModelDataSet * GetTermDiagramDataSet(
		const int iComType,
		const CString & strParmName, 
		const CString & strTerm
		) ; 

	static NDataModelDataSet * GetCSFVectorDiagramDataSet(  const int comType, const CString & parmName , const CString & libCode);

	/// ��ȡ����
	static BOOL GetVectorGraph( const int id, const int comtype, BYTE*&pbuff, int &buffSize) ;

	static BOOL GetVectorGraph( const int id, const int comtype, LPVOID &lpstr, int &buffSize) ;

	static BOOL GetVectorGraph(int id, LPVOID &lpstr, int &buffSize) ;
};
