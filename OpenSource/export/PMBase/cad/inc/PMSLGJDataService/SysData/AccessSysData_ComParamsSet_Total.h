

#pragma once 



#include "AccessSysData_ComParamsSet.h"

/**
 * @brief comparamsset_total
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CSysComParamsSet_TotalTable : public CSysComParamsSetTable
{
public:
	DECLARE_DYNCREATE(CSysComParamsSet_TotalTable)

	CSysComParamsSet_TotalTable() ; 
	~CSysComParamsSet_TotalTable() ;

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CAccessSysData_ComParamsSet_TatalTable :
	public CAccessSysDataTable
{
public:

	CAccessSysData_ComParamsSet_TatalTable(void);
	virtual ~CAccessSysData_ComParamsSet_TatalTable(void);

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
	* @brief  ��ȡ ���� Total ��¼ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [5/7/2012]
	*/
	BOOL GetSQLDataSetTable(CPMSQLTableCtrl *& pTableCtrl);

	/**
	* @brief ��ȡê�� ��� ���в������� ����  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/11/2011]
	*/
	void GetMgDj( CStringArray & arr_mgdj ) ;

protected:

	/**
	* @brief   ��ȡê�� ��� ���в������� ���У������� �����Ϣ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/11/2011]
	*/
	void GetMgDj_NotIncludeDjxs( CStringArray & arr_mgdj ) ;

public:

	/// ��ȡ��˿��Ƭ��DataSet 
	NDataModelDataSet * GetWpDataSet() ; 
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

protected:

	/// �ڲ�������03G 11G 
	BOOL	GetTableCtrl(  CPMSQLTableCtrl *& pTableCtrl , const int iComType = -1 ) ;

// public:
// 	BOOL	GetTableCtrlGangJinMode(  CPMSQLTableCtrl *& pTableCtrl , const int iGangJinMode , const int iComType = -1 ) ;

public:
	BOOL	GetTableCtrlGangJinMode(  CPMSQLTableCtrl *& pTableCtrl , const int iGangJinMode , const int iComType = -1 ) ;

	/// 
	BOOL	GetTableCtrl_ParmName( const CString & strParmName , const int iGangJinMode , CPMSQLTableCtrl *& pTableCtrl ) ;

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

		/// 
		static const int m_iGetWpDataSet ; 
		static PMTSTRING m_strGetWpDataSet ; 

		static const int m_iSelectAllInfo_GangJinModeComTypeSubComTypeParmName;
		static PMTSTRING m_strSelectAllInfo_GangJinModeComTypeSubComTypeParmName;

		/// select * from comparmset_total where gangjinmode in (? , -1 ) and comtype = ? 
		static const int m_iGetTableCtrl ;
		static PMTSTRING m_strGetTableCtrl ; 

		/// select * from comparmset_total where gangjinmode in (? , -1 ) and parmname = ? 
		static const int m_iGetTableCtrl_ParmName ;
		static PMTSTRING m_strGetTableCtrl_ParmName ; 
	} ;
};
