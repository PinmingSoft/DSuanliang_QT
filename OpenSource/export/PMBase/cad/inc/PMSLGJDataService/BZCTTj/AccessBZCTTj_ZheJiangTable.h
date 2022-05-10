#pragma once
#include "..\accesstable.h"

class PmSLGJDataServiceAPI CPMZheJiangTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CPMZheJiangTable)

	CPMZheJiangTable();
	virtual ~CPMZheJiangTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString ctbh;				//��̨���
		static const CString qddj;				//��̨������ǿ�ȵȼ�
		static const CString dzfl;				//��׮����(KN)
		static const CString zdbbc;				//���̱߱߳�(mm)a
		static const CString zdbbc2;				//���̱߱߳�(mm)b
		static const CString zjj;					//׮���S(mm)
		static const CString bp;					//bp(mm)
		static const CString l1;					//L1(mm)
		static const CString l2;					//L2(mm)
		static const CString h1;					//H(mm)
		static const CString h2;					//h(mm)
		static const CString gj1;					//�ٸֽ�
		static const CString gj2;					//�ڸֽ�
		static const CString gj3;					//�۸ֽ�
		static const CString gj4;					//�ֽܸ�
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CAccessBZCTTj_ZheJiangTable :
	public CPMSLAccessTable
{
public:
	CAccessBZCTTj_ZheJiangTable(void);

	~CAccessBZCTTj_ZheJiangTable(void);
	
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

class PmSLGJDataServiceAPI CBzcttjZheJiangOpr
{
public:
	CBzcttjZheJiangOpr() ;
	~CBzcttjZheJiangOpr() ; 

public:
	static NDataModelDataSet * GetDataSet() ;  
	static NDataModelDataSet * GetEmptyDataSet() ; 

};
