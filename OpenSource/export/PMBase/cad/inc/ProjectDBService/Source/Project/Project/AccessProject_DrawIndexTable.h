#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CProject_DrawIndexTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_DrawIndexTable)

	CProject_DrawIndexTable();
	virtual ~CProject_DrawIndexTable();

	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString id;							//���
		static const CString floorid;						//¥��ID
		static const CString comtype;						//��������
		static const CString name;						//��ʾ����
		static const CString showindex;					//��ʾ˳��

		static const CString table_name;					//����
	};

	virtual int InitFieldStr();
};


class PMProjectDBSERVICE CAccessProject_DrawIndexTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_DrawIndexTable(void);
public:
	virtual ~CAccessProject_DrawIndexTable(void);

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
	* @brief  ��ȡָ���� ������ ����Ҫɾ�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	CSQLDataSet * GetFloorID_DataSet(int iFloorID);

	/**
	* @brief   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [31/5/2013]
	*/
	BOOL SaveDataSet(CSQLDataSet * pDrawIndexDataSet);

	/**
	* @brief ��ȡ ���� IDֵ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [11/7/2012]
	*/
	BOOL GetTable_MaxID(int & iMaxID);


	/******************************************************************** 
	������������ȡָ���� �������͵Ļ���˳��
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[10/10/2009]
	*********************************************************************/ 
	BOOL GetDrawIndex_ComTypeArr( const int iFloorID,CUIntArray & iComTypeArr);

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
	void	Clear() ;
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
		static const int m_iGetDrawIndex_ComTypeArr ;
		static PMTSTRING m_strGetDrawIndex_ComTypeArr ; 
	} ;
};
