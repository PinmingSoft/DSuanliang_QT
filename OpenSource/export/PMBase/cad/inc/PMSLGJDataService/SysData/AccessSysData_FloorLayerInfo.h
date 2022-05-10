

#pragma once 


#include "AccessSysDataTable.h"

/**
 * @brief ���
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-9-5]
 * @note  
 */
class PmSLGJDataServiceAPI CSysLayerInfoTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysLayerInfoTable)

	CSysLayerInfoTable();
	virtual ~CSysLayerInfoTable();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;						//���
		static const CString floorid;					//¥��ID
		static const CString comtype;					//�������
		static const CString layer;					//������
		static const CString color;					//����ɫ
		static const CString showindex;				//����˳��
		static const CString showcolor;				//��ά��ʾ��ɫ
		static const CString layerinfo;				//����ʾ��Ϣ
		static const CString alllayername;			//���в���
		static const CString showsize;				//��ʾ��С
		static const CString controlmode;				//����ģʽ 1 ���Ʋ� 0 �����Ʋ�

		static const CString table_name;				//ͼ���
	};

	virtual int InitFieldStr();
};


class PmSLGJDataServiceAPI CAccessSysData_LayerInfoTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_LayerInfoTable(void);
	virtual ~CAccessSysData_LayerInfoTable(void);

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

	BOOL GetRowCount( int & iRowCount ) ;

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
