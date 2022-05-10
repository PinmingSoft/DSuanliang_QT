

#pragma once 

/**
 * @brief 报表的 操作类 的 管理类，
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2015年4月7日]
 * @note  
 */

#include "AccessReportBase.h "

/// 
struct PMProjectDBSERVICE SReportTableName
{
	/// 钢筋明细表(图形法) -- 预览模式
	static const CString steel_yl_mx_gjmx_tx ; 

	/// 钢筋明细表(图形法) -- 反查模式
	static const CString steel_fc_mx_gjmx_tx ; 

	/// 钢筋图形统计明细表
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