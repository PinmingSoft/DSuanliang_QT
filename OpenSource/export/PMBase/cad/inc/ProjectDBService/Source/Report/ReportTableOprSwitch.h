

#pragma once 

/**
 * @brief ����� ������ �� �����࣬
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2015��4��7��]
 * @note  
 */

#include "AccessReportBase.h "

/// 
struct PMProjectDBSERVICE SReportTableName
{
	/// �ֽ���ϸ��(ͼ�η�) -- Ԥ��ģʽ
	static const CString steel_yl_mx_gjmx_tx ; 

	/// �ֽ���ϸ��(ͼ�η�) -- ����ģʽ
	static const CString steel_fc_mx_gjmx_tx ; 

	/// �ֽ�ͼ��ͳ����ϸ��
	static const CString steel_graphic_tj_mx ;
};

/// 
class PMProjectDBSERVICE CReportTableOprSwitch
{
public:
	CReportTableOprSwitch() ;
	virtual ~CReportTableOprSwitch() ; 

public:
	static CReportTableOprBase * GetReportOpr( const CString & strTableName ) ; 
};