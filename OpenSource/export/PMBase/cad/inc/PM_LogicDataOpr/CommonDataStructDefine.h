#pragma once

//#include "PmArchiveBase.h"

class CCommonDataStructDefine
{
public:
	CCommonDataStructDefine(void);
	virtual ~CCommonDataStructDefine(void);
};


/**
* @brief  清单 定额 数据结构，用于运算 信息传递 
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: 王建业
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

		BOOL m_bIsQDMode;//是否是清单 
		CString m_strCalItemIndex;
		CString m_strCalItemName;//计算规则Name
		CString m_strCalItemID;//计算规则 编号
		CString m_strDEID;//如果是 清单 是清单ID
		CString m_strCalItemQDCode;
		CString m_strDEName;//如果是 清单 是清单名称
		CString m_strUnit;//单位
		CString m_strFormula;//计算公式
		CString m_strQuantity;//计算规则
		CString m_strFJCC;//附件尺寸

		CString		m_strRationRow;//处理定额行关系
		CString m_strQDNodeID;//是清单对应的ID编号（后期统一使用m_iRationRow）
	};

	virtual BOOL SerializeFrom(const CPmArchiveBase & archive);
	virtual BOOL SerializeTo(CPmArchiveBase & archive) const;

	/**
	* @brief   添加 清单定额信息
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/6/2013]
	*/
	void AddQDDERow(CProject_QDDE_RowInfo * pRowInfo);

	/**
	* @brief 获取指定行的 清单定额 信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/6/2013]
	*/
	const CProject_QDDE_RowInfo * GetQDDERowInfo(int iRowIndex) const;

	/**
	* @brief  获取记录个数 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/6/2013]
	*/
	int GetQDDERowCount() const;

	void SortQddeRows();


protected:

	typedef CArray<CProject_QDDE_RowInfo* ,CProject_QDDE_RowInfo*&>		CProject_QDDE_RowInfoArr;
	CProject_QDDE_RowInfoArr m_Project_QDDE_RowArr;
};