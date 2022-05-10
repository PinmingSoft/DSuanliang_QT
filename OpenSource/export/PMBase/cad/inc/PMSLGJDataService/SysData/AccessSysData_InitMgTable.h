

#pragma  once 

#include "AccessSysDataTable.h"

/**
 * @brief 
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2012-7-4]
 * @note  
 */
class PmSLGJDataServiceAPI CSysInitMgTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysInitMgTable)

	CSysInitMgTable();
	~CSysInitMgTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id ;
		static const CString gangjin_mode ;
		static const CString kzdj ;
		static const CString gjlx ;
		static const CString gjzl ;
		static const CString tqd ;
		static const CString mgz1 ;
		static const CString mgz2 ;
		static const CString djz1 ;
		static const CString djz2 ;

		static int id_Idx ;
		static int gangjin_mode_Idx ;
		static int kzdj_Idx ;
		static int gjlx_Idx ;
		static int gjzl_Idx ;
		static int tqd_Idx ;
		static int mgz1_Idx ;
		static int mgz2_Idx ;
		static int djz1_Idx ;
		static int djz2_Idx ;

		/// idx 递增的辅助变量
		/// idx 需要在函数 InitFieldStr 外 ，初始化为有意义的值
		/// 且赋值的顺序应该和 InitFieldStr中添加的顺序一样
		static int idx_step ; 
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};
};


class PmSLGJDataServiceAPI CAccessSysData_InitMgTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_InitMgTable(void);
	virtual ~CAccessSysData_InitMgTable(void);

	/**
	* @brief   获取整表的数据，不推荐使用，
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-7-12]
	*/
	NDataModelDataSet * GetDataSet() ;

	/**
	* @brief   尝试 升级表结构
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/6/2012]
	*/
	virtual BOOL TryUpdateTableField();

	/**
	* @brief   获取版本号
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-7-3]
	*/
	static	int	GetCurVersion() ;
protected:
	/******************************************************************** 
	功能描述：根据 抗震等级 / 钢筋类型 / 钢筋种类
	砼强度 / 搭接百分率 / 直径是否大于25 
	来获取 锚固值 和 搭接值
	参数：
	strKzdj : 非抗震\0;一级\1;二级\2;三级\3;四级\4;

	11G：
	//strGjlx : 普通钢筋\1;冷拔钢筋\2;冷拉钢筋\3;预应力钢筋\4;环氧树脂涂层钢筋\7;
	//strGjzl : 一级钢\1;二级钢\2;三级钢\3;冷扎带肋\4;冷扎抗扭\5;其他\6;
	//strTqd  : C20 C25 C30 C35 C40 / 在数据库中只存在这几个 
	//要是小于 C20 取C20 
	//大于 C40 的取  C40 

	gjlx:2表示环氧树脂涂层钢筋,1表示普通钢筋及其它所有类型钢筋,

	gjzl:1表示HPB300;2表示HRB335、HRBF335;3表示HRB400、HRBF400、RRB400;4表示HRB500、HRBF500;5表示冷轧带肋钢筋;6表示冷轧扭钢筋;7表示其他;

	tqd:C20,C25,C30,C35,C40,C45,C50,C55,C60
	大于C60按C60取值,小于C20按C20取值

	03G：
	gjlx:2表示环氧树脂涂层钢筋,1表示普通钢筋及其它所有类型钢筋,
	gjzl:1表示一级钢;2表示二级钢;3表示三级钢;4表示冷轧带肋钢筋;5表示冷轧扭钢筋;6表示其他;
	tqd:C20,C25,C30,C35,C40,
	大于C40按C40取值,小于C20按C20取值

	strDjbfl : ≤25%\1;50%\2;100%\3;

	str25 : 直径 <= 25 \1 ; 直径 >25 \0 ; 

	double dRDGJXS:扰动钢筋系数
	double dBHCHDXS：保护层厚度 系数
	返 回 值：
	算法：
	注意事项：
	作    者：杨兴耀
	时    间：[2009年7月2日]
	*********************************************************************/ 	
	void GetMgDj(
		const CString & strKzdj , 
		const CString & strGjlx , 
		const CString & strGjzl ,
		const CString & strTqd , 
		const CString & strDjbfl, 
		const CString & str25 ,
		const double dRDGJXS,
		const double dBHCHDXS,
		CString & strMgz, 
		CString & strDjz , 
		const int iComType = -1 
		);

	void GetMgDj(
		const CString & strKzdj , 
		const CString & strGjlx , 
		const CString & strGjzl ,
		const CString & strTqd , 
		const CString & strDjbfl, 
		const CString & str25 ,
		const double dRDGJXS,
		const double dBHCHDXS,
		const int iGangJinMode ,
		CString & strMgz, 
		CString & strDjz , 
		const int iComType = -1 
		);


	//锚固值与搭接百分率
	CString GetDjValue(const CString & strMgz,const CString & strbfl);

	// 切割搭接值 该数据储存方式为XX*d;XX*d;XX*d;
	//wrq [2017-1-16]
	CString SplitDjValueList(const CString & strDjzList,const CString & strbfl);

	/// 获取搭接锚固
	CString GetDjValue( const CString & strValue ,const double dValue);
	CString GetMgValue( const CString & strValue ,const double dValue);
 
	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;


protected:
	/// 
	BOOL	GetRfqMg( 
		const int iComType , 
		const CString & strGjzl , 
		const CString & strTqd , 
		const CString & strbfl , 
		const CString & str25 ,
		CString & strMgz ,
		CString & strDjz );

public:
	//固定的SQL 集合
	struct PmSLGJDataServiceAPI SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetMgDj ;
		static PMTSTRING m_strGetMgDj ;  
	} ;

protected:

	/// 搭接值查询也通过表
	/// 旧的搭接值计算方法: 锚固值 * 对应系数
	void	GetMgDj( 
		const CString & strKzdj , 
		const CString & strGjlx , 
		const CString & strGjzl ,
		const CString & strTqd ,
		const int iGangJinMode ,
		CString & strMg1 ,
		CString & strMg2 ,
		CString & strDj1 ,
		CString & strDj2
		) ;   

};


