
#pragma once


#include "AccessSysDataTable.h "
//#include "..\project\AccessProject_ProjectInfoTable.h"

/**
 * @brief ���������ܱ�
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CAccessSysData_ComParamsSetTable :
	public CAccessSysDataTable
{
public:
	CAccessSysData_ComParamsSetTable(void);
	virtual ~CAccessSysData_ComParamsSetTable(void);

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

	//BOOL GetParmValue_ComTypeSubComTypeParmName(int iComType,int iSubComType,\
	//	const CString & strParmName,\
	//	CString & strParmValue);

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
	* @brief   ��ȡ���в�����Ϣ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [3/7/2012]
	*/
	BOOL GetSQLDataSetTable(CPMSQLTableCtrl *& pTableCtrl);

	CString GetDisplayName( const int iComType , const CString & strParmName ) ;
	int GetInputMode( const int iComType , const CString & strParmName ) ;
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

	/**
	* @brief   ��ȡ������Ӧ�ֽ�mode��ȫ����������
	*		   ԭ������ȡComparmsset��������
	*		   �ֵ���Ϊ��Comparmsset_XXG�л�ȡ����
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ǿ
	* @date  : [2016-11-21]
	*/
	NDataModelDataSet * GetDataSet_JSSZ(ProjectInfoMacro::GangJinMode gangjinMode, const int iComType);

 	//NDataModelDataSet * GetDataSet_JSSZ(ProjectInfoMacro::GangJinMode gangjinMode,int iComType);
 
 	BOOL CheckValueHasChange(ProjectInfoMacro::GangJinMode gangjinMode,int iComType,int iSubComType,const CString & strParmName,const CString & strParmValue);

	/**
	* @brief   �жϼ��������Ƿ�Ķ�
	*		   ԭ������ȡComparmsset��������
	*		   �ֵ���Ϊ��Comparmsset��Comparmsset_XXG�л�ȡ����
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ǿ
	* @date  : [2016-12-26]
	*/
	BOOL CheckValueHasChangeNew(ProjectInfoMacro::GangJinMode gangjinMode,int iComType,int iSubComType,const CString & strParmName,const CString & strParmValue);
 
 	BOOL GetTableCtrl_ComTypeParmName(ProjectInfoMacro::GangJinMode gangjinMode,int iComType,\
 		int iSubComType,const CString & strParmName,CPMSQLTableCtrl *& pTableCtrl);
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
		static const int m_iGetDisplayName ; 
		static PMTSTRING m_strGetDisplayName ; 

		/// 
		static const int m_iGetInputMode ; 
		static PMTSTRING m_strGetInputMode ; 

		///select * from ComParmset where gangjinMode=? and comType =? and subcomtype=? and ParmName=?
		static const int m_iSelectAllInfo_GangJinModeComTypeSubComTypeParmName;
		static PMTSTRING m_strSelectAllInfo_GangJinModeComTypeSubComTypeParmName;

		///select * from ComParmSet where gangjinMode=? and comtype=? and parmType=?
		static const int m_iGetDataSet_ComTypeGangJinMode;
		static PMTSTRING m_strGetDataSet_ComTypeGangJinMode;
	} ;

private:
	
	/**
	* @brief   �ڵ�ǰ�����в���ֽ�ļ�������
	*
	* @note  : �����ԭ����
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ǿ
	* @date  : [2016-11-21]
	*/
	void AppendGangJinJssz(ProjectInfoMacro::GangJinMode gangjinMode, int iComType, NDataModelDataSet *pDataSet);
};


