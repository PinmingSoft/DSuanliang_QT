

#pragma once 





#include "AccessSysDataTable.h "
/**
 * @brief �������Ĳ����ܱ�
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-18]
 * @note  
 */
class PmSLGJDataServiceAPI CSysComParamsSet_GjTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysComParamsSet_GjTable)

	CSysComParamsSet_GjTable();
	virtual ~CSysComParamsSet_GjTable();

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString ParmID ;
		static int ParmID_idx;

		static const CString parentid ;
		static int parentid_idx;

		static const CString UpdateMode ;
		static int	UpdateMode_idx;

		static const CString comtype ;
		static int	comtype_idx;
 
		static const CString SubComType ;
		static int	SubComType_idx;

		static const CString parmtype ;
		static int	parmtype_idx;

		static const CString parmname ;
		static int	parmname_idx;

		static const CString parmdisplayname ;
		static int	parmdisplayname_idx;

		static const CString parmvalue ;
		static int	parmvalue_idx;

		static const CString InputMode ;
		static int	InputMode_idx;

		static const CString DataType ;
		static int	DataType_idx;

		static const CString ListData ;
		static int	ListData_idx;

		static const CString processType ;
		static int	processType_idx;

		static const CString exp ;
		static int	exp_idx;

		static const CString ValidateExpr ;
		static int	ValidateExpr_idx;

		static const CString CheckReg ;
		static int	CheckReg_idx;

		static const CString HitInfo ;
		static int	HitInfo_idx;

		static const CString InvalidMsg ;
		static int	InvalidMsg_idx;

		static const CString ReadOnly ;
		static int	ReadOnly_idx;

		static const CString Hide ;
		static int	Hide_idx;

		static const CString SortID ;
		static int	SortID_idx;

		static const CString TreeNode ;
		static int	TreeNode_idx;

// 		static		 int	 ParmID_Index;
// 		static		 int	 parentid_Index;
// 		static		 int	 UpdateMode_Index;
// 		static		 int	 comtype_Index;
// 		static		 int	 SubComType_Index;
// 		static		 int	 parmtype_Index;
// 		static		 int	 parmname_Index;
// 		static		 int	 parmdisplayname_Index;
// 		static		 int	 parmvalue_Index;
// 		static		 int	 InputMode_Index;
// 		static		 int	 DataType_Index;
// 		static		 int	 ListData_Index;
// 		static		 int	 processType_Index;
// 		static		 int	 exp_Index;
// 		static		 int	 ValidateExpr_Index;
// 		static		 int	 CheckReg_Index;
// 		static		 int	 HitInfo_Index;
// 		static		 int	 InvalidMsg_Index;
// 		static		 int	 ReadOnly_Index;
// 		static		 int	 Hide_Index;
// 		static		 int	 SortID_Index;
// 		static		int		TreeNode_Index;
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

};


class PmSLGJDataServiceAPI CAccessSysData_ComParamsSet_GjTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_ComParamsSet_GjTable(void);
	virtual ~CAccessSysData_ComParamsSet_GjTable(void);

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

protected:
	/// 
	NDataModelDataSet * GetDataSet(const int comType) ;

public:
	/// 
	NDataModelDataSet * GetDataSetComType(const int comType) ;

	
public:
	NDataModelDataSet * GetDataSet( const int comType,const int parmType);

	NDataModelDataSet * GetDataSet( const int comType,const int parmType , const int hide );

	NDataModelDataSet * GetDataSet( const CString & parmname,const int parmType);	

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

		/// 
		static const int m_iGetDataSet_ComTpye ; 
		static PMTSTRING m_strGetDataSet_ComTpye ; 

		/// 
		static const int m_iGetDataSet_ComTpye_ParmType ; 
		static PMTSTRING m_strGetDataSet_ComTpye_ParmType ; 

		/// 
		static const int m_iGetDataSet_ComTpye_ParmType_Hide ; 
		static PMTSTRING m_strGetDataSet_ComTpye_ParmType_Hide ; 

		/// 
		static const int m_iGetDataSet_ParmName_ParmType ; 
		static PMTSTRING m_strGetDataSet_ParmName_ParmType ; 

	} ;
};
