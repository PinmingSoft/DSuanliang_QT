#pragma once
////#include "..\accesstable.h"



class PMProjectDBSERVICE CAccessProject_SpecificGravityTable :
	public CPMSLAccessTable
{
public:
	enum Enum_Gjlx {
		gjlx_pt = 1 ,		/// 普通钢筋
		gjlx_lzdl = 5 ,		/// 冷轧带肋
		gjlx_lzkn = 6		/// 冷轧抗扭
	};

public:
	CAccessProject_SpecificGravityTable(void);
	CAccessProject_SpecificGravityTable(BOOL bTemplateDb);
	~CAccessProject_SpecificGravityTable(void);
	
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

	/// 
	CString			GetSpecificGravity( const int iGjlx , const int iDia ) ;

	/// 
	void	GetDiaArr( CUIntArray & aryDia ) ; 
	void	GetDiaArr( CUIntArray & aryDia,int gjlx);

	/// 
	CString	GetAfterDiameter( const CString & strCurDia ) ; 

	CString GetBeforDiameter( const CString & strCurDia ) ;

	BOOL	JugeDiameter( const CString & strCurDia ) ;

	//后一个钢筋直径(bOnlyComnSteel 表示是否仅普通钢筋，即排除冷轧抗扭，冷轧带肋)
	CString	GetAfterDiameter( const CString & strCurDia ,BOOL bOnlyComnSteel) ; 

	//前一个钢筋直径(bOnlyComnSteel 表示是否仅普通钢筋，即排除冷轧抗扭，冷轧带肋)
	CString GetBeforDiameter( const CString & strCurDia ,BOOL bOnlyComnSteel) ;

	//普通钢筋的直径判断(bOnlyComnSteel 表示是否仅普通钢筋，即排除冷轧抗扭，冷轧带肋)
	BOOL	JugeDiameter( const CString & strCurDia ,BOOL bOnlyComnSteel) ;

	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;


public:
	//固定的SQL 集合
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetSpecificGravity ;
		static PMTSTRING m_strGetSpecificGravity ; 
	} ;
};


/**
* @brief   封装一些临时对象的定义操作 (充当 新老Access的 适配器)
*
*          
* @note  : 不需要每一个用到的地方都去定义一个临时对象 ， 有一些参数类型的转化可以在该类中实现
*
* @author: 杨兴耀
* @date  : [2012-7-17]
*/

class PMProjectDBSERVICE CProjectSpecificGravityOpr
{
public:
	CProjectSpecificGravityOpr() ;
	~CProjectSpecificGravityOpr() ; 

public:

	static float GetSpecificGravity( const int gjlx, const float dia) ;

	static CString GetSpecificGravity( const CString & gjjb, const CString & strDia);


	/// 判断直径是否在该表中
	static BOOL	CheckDiameter( const int gjlx , const CString &diameter ) ; 
	static BOOL	CheckDiameter( const CString gjjb , const CString &diameter ) ; 
	static BOOL	CheckDiameter ( const CStringArray & aryJb , const CStringArray & aryZj ) ; 
};
