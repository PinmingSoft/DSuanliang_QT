// PmSpecialDataSetOperate.h: interface for the CPmSpecialDataSetOperate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PMSPECIALDATASETOPR_H__14DF9551_37BC_4E5A_98D0_36B59FB02DF7__INCLUDED_)
#define AFX_PMSPECIALDATASETOPR_H__14DF9551_37BC_4E5A_98D0_36B59FB02DF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PmSLGJDataServiceAPI CPmSpecialDataSetOpr
{
public:
	CPmSpecialDataSetOpr();
	virtual ~CPmSpecialDataSetOpr();

	/**
	* @brief  ��ȡ���� ����ֵ 
	*
	*          
	* @note  : ͨ������ ���ͽ��п��ٹ���
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	static BOOL GetComParmSet_ParmValue(NDataModelDataSet * pComParmDataSet,int iParmType,const CString & strParmName,CString & strParmVaue);

	/**
	* @brief  ��DataSet��Field���Ƶ� ��һ��DataSet
	*
	*          
	* @note  : ע�� ���Ḵ�� �������
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/12/2011]
	*/
	static BOOL CopyDataSetField(CPM_StorageDataSet * pFromDataSet,CPM_StorageDataSet * pToDataSet);

	/******************************************************************** 
	�������������ڸ��ƹ������ԣ����ڼ����� �ڴ湲��DataSet��ֱ�ӵ�RowsCopy��Ӵ��ڴ� ���
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2010:12:14]   8:50
	*********************************************************************/ 
	static BOOL CopyComParmsDataSet(NDataModelDataSet * pFormComParmDataSet,NDataModelDataSet * pToComParmDataSet);

	/// �����ѯ
	static BOOL GetDataSetRowArray( 
		NDataModelDataSet * pDataSet ,
		const CStringArray & fieldnames ,
		const CStringArray & fieldvalues ,
		CUIntArray & rows ) ;

	/// �������
	/// ���ص��к� �Ǵ�С�����
	static BOOL GetDataSetRowArray( 
		NDataModelDataSet * pDataSet ,
		const CString sFieldValue ,
		const CString sFieldName ,
		CUIntArray &rows 
		) ; 
	
	// ***************************************************************
	//  ����ҫע��  ʱ��:2010��03��12��
	//  -------------------------------------------------------------
	//  ����: ������Դ pSrcDataSet ����һ�� (���е��п���)
	//  -------------------------------------------------------------
	//  ����ֵ:�������Ŀ������Դ
	//  -------------------------------------------------------------
	//  ����:pSrcDataSet ��Ҫ������������Դ 
	// ***************************************************************
	//  ע������: ���ص�����Դ ��new ������һ������Դ�����Ե��õĵط�
	//			  ��������ͷ�
	// ***************************************************************
	static NDataModelDataSet * RowsCopy(  NDataModelDataSet * pSrcDataSet ) ; 

	/// ���ص�DataSet Ϊ �� NDbDataSet new ������ ���б��� �� ����
	/// �ýӿڻ�ȡ��DataSet �ڵ��� update ��ʱ����Ը��µ� mdb �ļ��� 
	static NDataModelDataSet * GetNDbDataSet(  NDataModelDataSet * pSrcDataSet ) ; 
	// ***************************************************************
	//  ����ҫע��  ʱ��:2010��03��29��
	//  -------------------------------------------------------------
	//  ����:
	//  -------------------------------------------------------------
	//  ����ֵ:
	//  -------------------------------------------------------------
	//  ����:
	// ***************************************************************
	//  ע������:
	// ***************************************************************
	static void ExportDataSetToTxt( const CString & strFileName , NDataModelDataSet * pDataSet ) ; 

	// ***************************************************************
	//  ����ҫע��  ʱ��:2010��04��01��
	//  -------------------------------------------------------------
	//  ����:
	//  -------------------------------------------------------------
	//  ����ֵ:
	//  -------------------------------------------------------------
	//  ����:
	// ***************************************************************
	//  ע������:
	// ***************************************************************
	static void SetModify( NDataModelDataSet * pDataSet , const BOOL & bModify ) ;

	/// ��ȡ DataSet �� ����
	static void GetFieldArray( NDataModelDataSet * pDataSet , CStringArray & arr_fields ) ;
	/// ���� ���������� ����С
	/// ��ȡһ���µ�DataSet 
	static NDataModelDataSet * GetDataSet( 
		const CStringArray & arr_fields , 
		const CArray<FieldType , FieldType>& arr_fieldtypes ,
		const CUIntArray & arr_fieldsizes ) ;
	/// ΪftBlob �ֶ�дһ������һ���ӿ�
	static NDataModelDataSet * GetDataSet( 
		const CStringArray & arr_fields 
		) ;


};

#endif // !defined(AFX_PMSPECIALDATASETOPR_H__14DF9551_37BC_4E5A_98D0_36B59FB02DF7__INCLUDED_)
