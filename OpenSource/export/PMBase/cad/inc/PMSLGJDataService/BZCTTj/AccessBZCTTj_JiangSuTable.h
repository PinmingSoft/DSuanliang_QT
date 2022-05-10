#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CPMJiangSuTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CPMJiangSuTable)

	CPMJiangSuTable();
	virtual ~CPMJiangSuTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString ctbh;				//��̨���
		static const CString dzfl;				//��׮����(KN)
		static const CString qddj;				//��̨������ǿ�ȵȼ�
		static const CString fzbc;				//��׮�߳�D
		static const CString zxfzbc;				//��С��׮�߳�a
		static const CString zxfzbc2;				//��С��׮�߳�b
		static const CString a;
		static const CString a1;
		static const CString a2;
		static const CString b;
		static const CString c;
		static const CString c1;
		static const CString c2;
		static const CString h;
		static const CString h1;
		static const CString h2;
		static const CString gj1;					//�ٸֽ�
		static const CString gj2;					//�ڸֽ�
		static const CString gj3;					//�۸ֽ�

		static const CString table_name;
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CAccessBZCTTj_JiangSuTable :
	public CPMSLAccessTable
{
public:
	CAccessBZCTTj_JiangSuTable(void);

	~CAccessBZCTTj_JiangSuTable(void);

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

	NDataModelDataSet * GetEmptyDataSet() ;

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

class PmSLGJDataServiceAPI CBzcttjJiangSuOpr
{
public:
	CBzcttjJiangSuOpr() ;
	~CBzcttjJiangSuOpr() ; 

public:
	static NDataModelDataSet * GetDataSet() ;  
	static NDataModelDataSet * GetEmptyDataSet() ; 
};
