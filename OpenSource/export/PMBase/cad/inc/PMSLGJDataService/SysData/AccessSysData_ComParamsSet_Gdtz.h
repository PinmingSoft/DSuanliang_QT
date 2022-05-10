
#pragma  once 



#include "AccessSysDataTable.h"

/**
 * @brief �߶ȵ��� ������
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CSysComParamsSet_GdtzTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysComParamsSet_GdtzTable)

	CSysComParamsSet_GdtzTable() ; 
	~CSysComParamsSet_GdtzTable() ;

	
public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString ParmID ;
		static		 int	 ParmID_Index;

		static const CString gangjin_mode ;
		static		 int	 gangjin_mode_Index;

		static const CString UpdateMode ;
		static		 int	 UpdateMode_Index;

		static const CString comtype ;
		static		 int	 comtype_Index;

		static const CString SubComType ;
		static		 int	 SubComType_Index;

		static const CString parmtype ;
		static		 int	 parmtype_Index;

		static const CString parmname ;
		static		 int	 parmname_Index;

		static const CString parmdisplayname ;
		static		 int	 parmdisplayname_Index;

		static const CString parmvalue ;
		static		 int	 parmvalue_Index;

		static const CString InputMode ;
		static		 int	 InputMode_Index;

		static const CString DataType ;
		static		 int	 DataType_Index;

		static const CString processType ;
		static		 int	 processType_Index;

		static const CString exp ;
		static		 int	 exp_Index;

		static const CString InvalidMsg ;
		static		 int	 InvalidMsg_Index;

		static const CString Hide ;
		static		 int	 Hide_Index;

		static const CString SortID ;
		static		 int	 SortID_Index;

		static const CString TreeNode ;
		static		int		TreeNode_Index;

		static const CString ListData ; 

		static const CString Mode ;
		static		int		Mode_Index ; 
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};
};

class PmSLGJDataServiceAPI CAccessSysData_ComParamsSet_GdtzTable :
	public CAccessSysDataTable
{
public:
	CAccessSysData_ComParamsSet_GdtzTable(void);
	virtual ~CAccessSysData_ComParamsSet_GdtzTable(void);

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

	/// 
	NDataModelDataSet * GetDataSet( const int iComType) ;

	NDataModelDataSet * GetShowDataSet( const int iComType) ;

	/// ��ȡ��� 
	/// nMode : 0 : nComID ��Ӧ��û�б��
	///			1 : nComID ��Ӧ��ֻ�С��ױ��
	///			2 : nComID ��Ӧ��ֻ�С������
	///			3 : nComID ��Ӧ���ױ�ߡ��͡�����ߡ�����
	/// dibgParam �ױ�� ����
	/// dbgParam  ����� ����
	/// 
	/// �����๹�� �� ���������� �ı���� ���Ա�� ��
	/// ���������� ��߶�����Ա��
protected:
	BOOL GetBg( const int  nComID , int & nMode , CParm & dibgParam, CParm & dbgParam );

	/**
	* @brief   
	*
	*          
	* @note  : nMode : 0 : nComID ��Ӧ��û�б��
	///			1 : nComID ��Ӧ��ֻ�С��ױ��
	///			2 : nComID ��Ӧ��ֻ�С������
	///			3 : nComID ��Ӧ���ױ�ߡ��͡�����ߡ�����
	/// dibgParam �ױ�� ����
	/// dbgParam  ����� ����
	///  ��ȡ���Ϊ ��Ա��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [24/8/2012]
	*/

protected:
	BOOL GetBg_XDValue( const int  nComID , int & nMode , double & dibg, double & dbg );

	/**
	* @brief ��ȡ���ģʽ  
	*
	*          
	* @note  : nMode : 0 : nComID ��Ӧ��û�б��
	///			1 : nComID ��Ӧ��ֻ�С��ױ��
	///			2 : nComID ��Ӧ��ֻ�С������
	///			3 : nComID ��Ӧ���ױ�ߡ��͡�����ߡ�����
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/8/2012]
	*/
	BOOL GetBgMode_ComID( const int  nComID , int & nMode);
protected:
	/**
	* @brief ��ȡ���ģʽ  
	*
	*          
	* @note  : nMode : 0 : nComID ��Ӧ��û�б��
	///			1 : nComID ��Ӧ��ֻ�С��ױ��
	///			2 : nComID ��Ӧ��ֻ�С������
	///			3 : nComID ��Ӧ���ױ�ߡ��͡�����ߡ�����
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/8/2012]
	*/
	BOOL GetBgMode_ComType( const int nComType, int & nMode);
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
	NDataModelDataSet * GetDataSet() ; 

	BOOL HasParm( const int iComType , const CString & strParmName ) ;


	/// 
	/// ��ʾ��DataSet��Ҫ disparmname �� iuputmode ��
	/// 
	NDataModelDataSet * GetShowDataset() ; 
private:
	/// 
	/// �� pSrcDataSet ת��Ϊ pDesDataSet 
	///
	/// pSrcDataSet �Ǳ�table�Ľṹ
	/// pDesDataSet ����ʾDataset�Ľṹ
	/// 
	void	ConvertDataSet( NDataModelDataSet * pSrcDataSet , NDataModelDataSet * pDesDataSet ) ; 

	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;


public:
	//�̶���SQL ����
	struct PmSLGJDataServiceAPI SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// GetDataSet( const int iComType) 
		static const int m_iGetDataSet1 ;
		static PMTSTRING m_strGetDataSet1 ; 

		/// �� m_iGetDataSet1 ������ֻ������ͬ
		static const int m_iGetDataSet2 ;
		static PMTSTRING m_strGetDataSet2 ; 
	} ;

};
