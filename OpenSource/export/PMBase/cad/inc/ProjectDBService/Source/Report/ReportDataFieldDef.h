

#pragma once 

/**
 * @brief 报表的数据列定义文件
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2015年3月26日]
 * @note  
 */

struct PMProjectDBSERVICE SReportDataField
{
	/// 表名常量
	static const CString reportlist ; 
	static const CString fcreportlist ; 
	static const CString projectinfo ;	/// 

	static const CString gjjbinfo ; 

	static const CString steelmxfloor ; /// 钢筋明细表，楼层表
	static const CString steelmxcomponents ; /// 钢筋明细表，构件表
	static const CString steelmxresult ; /// 钢筋明细表，结果表
	static const CString steelmxjtcontent ;		/// 钢筋简图的存储表

	static const CString steelgraphictjmx ; ///

	static const CString steelmxfc ;	/// 钢筋明细表 反查

	/// 
	static const CString id ;			/// id
	static const CString name ;			/// 名称
	static const CString show_name ;	/// 显示的名称
	static const CString value ;		/// 
	static const CString sort_id ;		/// 排序的id
	static const CString logic_id ;		/// 逻辑id
	static const CString check ;		/// 是否被选中
	static const CString volume ;		/// 数量
	static const CString floor_id ;		/// 楼层id
	static const CString comid_id ; 

	static const CString gjjb ;			/// 钢筋级别
	static const CString gjzj ;			/// 钢筋直径
	static const CString jt ;			/// 钢筋简图
	static const CString jsgs ;			/// 钢筋计算公式
	static const CString gs ;			/// 根数
	static const CString zgs ;			/// 总根数			
	static const CString cd ;			/// 长度
	static const CString zcd ;			/// 总长度
	static const CString zz ;			/// 总重
	static const CString wg ;			/// 弯钩
	static const CString dj ;			/// 搭接
	

	static const CString xh ;			/// 序号	
	static const CString gjzj_sort ;			/// 钢筋直径排序	
	static const CString dz ;			/// 单重	
	/// 
	static const CString mode ;			/// 模式
	static const CString parent	;		/// 父节点
	static const CString is_table ;		/// 是否是表	
	static const CString content;		/// 具体的报表内容

	static const CString caption ;		/// 
	static const CString level ;		/// 
	static const CString sortid ;		/// 
	static const CString isexpand ;		/// 是否展开
	static const CString lb ;			/// 
	static const CString sqlcontent ;	/// 
	static const CString fieldinfo ;
	static const CString logicname ;	/// 

	static const CString gjmc ;			/// 构件名称
	static const CString gjsl ;			/// 构件数量
	static const CString gjzz ;			/// 

	static const CString handle ;		/// 

	static const CString info ;			/// 

	static const CString gjjbcontent ;	/// 钢筋级别的图像

	static const CString jtcontent ; 

};