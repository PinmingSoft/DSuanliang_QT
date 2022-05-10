

#pragma  once 



#include "AccessSysDataTable.h"

/**
 * @brief 
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-4]
 * @note  
 */
class PmSLGJDataServiceAPI CSysSteelDiagramTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysSteelDiagramTable)

	CSysSteelDiagramTable();
	~CSysSteelDiagramTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString libid;
		static const CString formula ;
		static const CString defaultHeight ;
		static const CString diagram ;
		static const CString ScriptFormula;

		static int id_Idx ;
		static int libid_Idx ;
		static int formula_Idx ;
		static int defaultHeight_Idx ;
		static int diagram_Idx ;
		static int ScriptFormula_Idx ;

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


class PmSLGJDataServiceAPI CAccessSysData_SteelDiagramTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_SteelDiagramTable(void);
	virtual ~CAccessSysData_SteelDiagramTable(void);

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

	NDataModelDataSet * GetEmptyDataSet() ; 

	/**
	* @brief   ��ȡָ��VectorID�� ͼ��Ϣ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: wjy
	* @date  : [2012-7-12]
	*/
	BOOL GetSteeldiagram(int id, LPVOID & pbuff, long &buffSize) ;

	/**
	* @brief   ��ȡָ��VectorID�� ͼ��Ϣ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: wjy
	* @date  : [2012-7-12]
	*/
	BOOL GetDataSet_VectorID(int iVectorID,CSQLDataSet *& pSQLDataSet);

	/**
	* @brief ��ȡ ָ�� id�� ��¼�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	BOOL GetTablcCtrl_Id(int id,CPMSQLTableCtrl *& pSQLTableCtrl);

	BOOL SetSteeldiagram(int id, LPVOID pbuff, long buffSize) ;

	int GetLibid( const int id ) ; 

	BOOL IsGj( const CString & strth ) ;

	/**
	* @brief  ��ȡ �ֽ� ��ʽ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	CString GetFormula(int id);

	/**
	* @brief  ͨ�� ScriptFormula ��ȡ ��Ӧ�� ͼID
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	BOOL GetID_ScriptFormula(const CString & strScriptFormula,int & iID);

	/**
	* @brief  ��ȡ �ֽ� �ű���ʽ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	CString GetScriptFormula(int id);

	/**
	* @brief  ��ȡ �ֽ� ������ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	NDataModelDataSet* GetSteeldiagramDataSet(int libID);

	/**
	* @brief  ��ȡ�ֽ�ͼ ���򣬼�¼ 
	*
	*          
	* @note  :int iMinID �ǵ�����Сֵ ,int iMaxID  �ǵ������ֵ ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [26/7/2012]
	*/
	NDataModelDataSet * GetSteelDiagramDataSet_Range(int iMinID,int iMaxID);

	/**
	* @brief  ��ȡ�ֽ�ͼ ���򣬼�¼ ����
	*
	*          
	* @note  :
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [26/7/2012]
	*/
	NDataModelDataSet * GetSteelDiagramDataSet_Arr(CUIntArray & iIDArr);

	/**
	* @brief   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [26/7/2012]
	*/
	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief ��ȡͼ�źϳɼ��㹫ʽ ��Ӧ  ��ͼ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [4/9/2012]
	*/
	BOOL GetTableCtrl_ScriptFormula(const CString & strScriptFormula,CPMSQLTableCtrl *& pSQLTableCtrl);

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

		static const int m_iSelectDiagram_id_Sql;
		static const PMTSTRING m_strSelectDiagram_id_Sql;

		static const int m_iSelectAllInfo_id_Sql;
		static const PMTSTRING m_strSelectAllInfo_id_Sql;

		//select * from steeldiagram where id >= 123 and id <= 300
		static const int		m_iSelectAllInfo_idRange;
		static const PMTSTRING	m_strSelectAllInfo_idRange;

		//select * from steedldiagrm where scriptformula=?
		static const int		m_iSelectAllInfo_ScriptFormula;
		static const PMTSTRING	m_strSelectAllInfo_ScriptFormula;
	} ;
};
