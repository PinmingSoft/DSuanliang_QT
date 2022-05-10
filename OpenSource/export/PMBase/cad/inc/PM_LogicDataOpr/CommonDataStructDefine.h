#pragma once

//#include "PmArchiveBase.h"

class CCommonDataStructDefine
{
public:
	CCommonDataStructDefine(void);
	virtual ~CCommonDataStructDefine(void);
};


/**
* @brief  �嵥 ���� ���ݽṹ���������� ��Ϣ���� 
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: ����ҵ
* @date  : [13/6/2013]
*/
class PMLogicDataOprAPI CProject_QDDE_DataInfo
{
public:

	CProject_QDDE_DataInfo();
	virtual ~CProject_QDDE_DataInfo();

	class PMLogicDataOprAPI CProject_QDDE_RowInfo
	{
	public:
		CProject_QDDE_RowInfo();
		virtual ~CProject_QDDE_RowInfo();

		void SetQDMode(BOOL bQDMode);
		BOOL GetQDMode() const;

		void SetCalItemIndex(const CString & strCalItemIndex);
		CString GetCalItemIndex() const;

		void SetCalItemName(const CString & strDEItemName);
		CString GetCalItemName() const;

		void SetCalItemID(const CString & strDEItemID);
		CString GetCalItemID() const;

		void SetCalItemQDCode(const CString & strQDCode);
		CString GetCalItemQDCode() const;

		void SetDEID(const CString & strDEID);
		CString GetDEID() const;

		void SetDEName(const CString & strDEName);
		CString GetDEName() const;

		void SetUnit(const CString & strUnit);
		CString GetUnit() const;

		void SetFormula(const CString & strFormula);
		CString GetFormula() const;

		void SetQuantity(const CString & strQuantity);
		CString GetQuantity() const;

		void SetFJCCInfo(const CString & strFJCCInfo);
		CString GetFJCCInfo() const;

		void SetRationRow(const CString & strRationRow);
		CString GetRationRow() const;

		void SetQDNodeID(const CString & strQDNodeID);
		CString GetQDNodeID() const;

		virtual BOOL SerializeFrom(const CPmArchiveBase & archive);
		virtual BOOL SerializeTo(CPmArchiveBase & archive);

	protected:

		BOOL m_bIsQDMode;//�Ƿ����嵥 
		CString m_strCalItemIndex;
		CString m_strCalItemName;//�������Name
		CString m_strCalItemID;//������� ���
		CString m_strDEID;//����� �嵥 ���嵥ID
		CString m_strCalItemQDCode;
		CString m_strDEName;//����� �嵥 ���嵥����
		CString m_strUnit;//��λ
		CString m_strFormula;//���㹫ʽ
		CString m_strQuantity;//�������
		CString m_strFJCC;//�����ߴ�

		CString		m_strRationRow;//�������й�ϵ
		CString m_strQDNodeID;//���嵥��Ӧ��ID��ţ�����ͳһʹ��m_iRationRow��
	};

	virtual BOOL SerializeFrom(const CPmArchiveBase & archive);
	virtual BOOL SerializeTo(CPmArchiveBase & archive) const;

	/**
	* @brief   ��� �嵥������Ϣ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/6/2013]
	*/
	void AddQDDERow(CProject_QDDE_RowInfo * pRowInfo);

	/**
	* @brief ��ȡָ���е� �嵥���� ��Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/6/2013]
	*/
	const CProject_QDDE_RowInfo * GetQDDERowInfo(int iRowIndex) const;

	/**
	* @brief  ��ȡ��¼���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/6/2013]
	*/
	int GetQDDERowCount() const;

	void SortQddeRows();


protected:

	typedef CArray<CProject_QDDE_RowInfo* ,CProject_QDDE_RowInfo*&>		CProject_QDDE_RowInfoArr;
	CProject_QDDE_RowInfoArr m_Project_QDDE_RowArr;
};