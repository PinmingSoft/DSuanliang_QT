#pragma once
//#include "..\accesstable.h"

class PMProjectDBSERVICE CAccessProject_FloorTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_FloorTable(void);
public:
	virtual ~CAccessProject_FloorTable(void);

public:
	/// 
	void	GetFloorIdAry( CUIntArray & aryFloorId ) ;

	/**
	* @brief  检测 是否有 基础层 
	*
	*          
	* @note  : 包括地下室
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [10/9/2012]
	*/
	BOOL CheckBaseFloor();

	/**
	* @brief 检查是否有 地下室  
	*
	*          
	* @note  : 0层 不属于地下室的 定义
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [10/9/2012]
	*/
	BOOL CheckUnderBaseFloor();

	/**
	* @brief  返回 floorid 与 lcmc的队列 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [27/7/2012]
	*/
	BOOL GetFloorInfo_FloorID_LCMC(CUIntArray & iFloorIDArr,CStringArray & strLCMCArr);

	/**
	* @brief   获取 floorid 与 dwg图纸的 filename 的匹配
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [11/13/2019]
	*/
	BOOL GetFloorInfo_FloorID_DwgFile(CUIntArray & iFloorIDArr,CStringArray & strDwgFileArr);

	/**
	* @brief  返回 floorid、lcmc、FloorComment 的队列 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zy
	* @date  : [13/4/2018]
	*/
	BOOL GetFloorInfo_FloorID_LCMC_Remark(CUIntArray & iFloorIDArr,CStringArray & strLCMCArr,CStringArray & strFloorCommentArr);


	/**
	* @brief  是否 是顶层 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [24/7/2012]
	*/
	BOOL IsTopFloor(int iFloorID);

	/**
	* @brief 获取 所有记录集  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [23/7/2012]
	*/
	BOOL GetAllInfo_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief 判断是否是全层 显示图纸  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [20/7/2012]
	*/
	BOOL CheckIsAllFloorDWG(CString strDWGFile);

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
	* @brief  获取最大的 FloorID 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	BOOL GetMaxFloorID(int & iMaxFloorID);

	BOOL GetRowCount( int & iRowCount ) ;

	/**
	* @brief  获取 楼层ID 指定的 DataSet信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 范围DataSet  需要删除
	* @author: 王建业
	* @date  : [11/7/2012]
	*/
	CSQLDataSet * GetFloorID_DataSet(int iFloorID);

	/**
	* @brief  获取当前楼层的 显示顺序 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	BOOL GetFloorShowID(int iFloorID,int & iShowID);
	
	/**
	* @brief 判断 当前楼层ID 是否是 基础层  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	BOOL IsUnderBaseFloor(int iFloorID);

	/**
	 * @brief 判斷當前層是否是地下室，0層以下都屬於地下室 
	 *
	 *        
	 * @author 郑琪崇
	 * @version v1.0
	 * @date  2015年12月31日   15:32
	 * @note  
	 */
	BOOL IsBaseMent(int iFloorID);
	/**
	* @brief 获取楼层名称  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	BOOL GetFloorLCMC(int iFloorID,CString &strLCMC);

	/**
	* @brief  获取图纸 名称 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	BOOL GetFloorDwgName(int iFloorID,CString & strFileName);

	/**
	* @brief  获取楼层ID
	*
	*          
	* @note  :		通过图纸名称来获取楼层ID
	* @param : 
	* @defenc: 
	* @return: 
	* @author: qf
	* @date  : [21/11/2013]
	*/

	BOOL	GetFloorIdByFloorDwg( int& iFloorID ,  const CString& strFileName );
	/**
	* @brief  获取楼地面标高 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	BOOL GetFloorLDMBG(int iFloorID,int & iLDMBG);

	/**
	* @brief   某个楼层的顶标高
	*
	*			
	* @note  : 
	* @param : nBgMode 0: 楼层标高 1：工程标高
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/3/2017]
	*/
	BOOL GetFloorDingBg(int iFloorID,int nBgMode,int &nFloorDingBG);

	/**
	* @brief   某个楼层的底标高
	*
	*			
	* @note  : 
	* @param : nBgMode 0: 楼层标高 1：工程标高
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/3/2017]
	*/
	BOOL GetFloorDiBg(int iFloorID,int nBgMode,int &nFloorDiBG);

	/**
	* @brief  获取层高
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	BOOL GetFloorCg(const int iFloorID,int & iCg);

	/// 获取板厚
	BOOL	GetFloorBh( const int iFloorID , int & iBh ) ;

	
	
	/**
	* @brief  获取Floor表 内容，DataSet需要删除 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [10/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	BOOL SaveDataSet(CSQLDataSet * pSQLDataSet);

	BOOL GetTableCtrl_FloorID(int iFloorID,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief  获取当前 楼层 ID的 层数 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [20/7/2012]
	*/
	BOOL GetFloorCS(int iFloorID,int & iCS);

	///获取以 ShowID 排序的 DataSet 
	CSQLDataSet * GetSortDataSet() ;

	//获取 所有地下室的 楼层ID 
	BOOL GetUnderFloors(CUIntArray & nArrFloors);

	BOOL	HasDxs() ; 

	//设置某一层的主体建筑面积
	void SetZtjzmj( const int nFloorID , const CString & strZtjzmj );
	//获取
	BOOL GetZtjzmj( const int nFloorID , CString &strZtjzmj);

	

	//设置某一层的阳台建筑面积
	void SetYtjzmj(const int nFloorID , const CString & strYtjzmj );
	//获取
	BOOL GetYtjzmj( const int nFloorID , CString & strYtjzmj);

	
	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;

private:
	BOOL	SetColValue( const int iFloorId , const CString & strColName , const CString & strColValue ) ;


public:

	struct PMProjectDBSERVICE SQLInfo
	{
		static const PmTString m_selectShowID_SQL;//获取ShowID的 sql
		static const PmTString m_selectCG_SQL;//获取层高的 sql；
		static const PmTString m_selectLDMBG_SQL;//获取楼地面标高 sql；
		static const PmTString m_selectLCMC_SQL;//获取楼层名称 sql
		static const PmTString m_selectDWGFileName_SQL;//获取DWG文件名称的 sql
		static const PmTString m_selectFloorId_SQL;//获取楼层号的 sql
		static const int		m_iSelectAllInfo_FloorID;
		static const PmTString	m_strSelectAllInfo_FloorID;

		/// 
		static const int m_iGetSortDataSet ; 
		static PMTSTRING m_strGetSortDataSet ; 

		/// 
		static const int m_iSetColValue ;
		static PMTSTRING m_strSetColValue ; 
	};
};


/**
* @brief   封装一些临时对象的定义操作
*
*          
* @note  : 不需要每一个用到的地方都去定义一个临时对象 ， 有一些参数类型的转化可以在该类中实现
*
* @author: 杨兴耀
* @date  : [2012-7-17]
*/


class PMProjectDBSERVICE CProjectFloorOpr 
{
public:
	CProjectFloorOpr() ;
	~CProjectFloorOpr() ; 

public:
	static NDataModelDataSet * GetDataSet() ; 
	static NDataModelDataSet * GetSortDataSet() ;

	static BOOL GetFloorLDMBG(const int iFloorID,int & iLDMBG);
	static BOOL GetFloorLDMBG(const int iFloorID,double & dLDMBG);
	static BOOL GetFloorLDMBG(const int iFloorID,CString & strLDMBG);

	/// 单位为m
	static BOOL GetFloorTopBg(const int iFloorID,double & dTopBg);

	static BOOL GetFloorShowId( const int iFloorId , int & iShowId ) ;

	static BOOL GetFloorCg(const int iFloorID , int & iCg );
	static BOOL GetFloorCg( const int iFloorId , CString & strCg ) ;

	static BOOL GetFloorCS(const int iFloorID,int & iCS) ; 
	static int	GetFloorCs( const int iFloorId ) ;

	static BOOL GetFloorLCMC( const int iFloorID,CString &strLCMC); 

	static BOOL GetFloorDwgName(const int iFloorID,CString & strFileName);

	//获取 所有地下室的 楼层ID 
	static BOOL GetUnderFloors(CUIntArray & nArrFloors);

	static BOOL	HasDxs() ; 

	/// 
	static BOOL GetRowCount( int & iRowCount ) ;

	/// 
	static BOOL	GetFloorBh( const int iFloorID , int & iBh ) ; 


	//设置某一层的主体建筑面积
	static void SetZtjzmj( const int nFloorID , const CString & strZtjzmj );
	//获取
	static BOOL GetZtjzmj( const int nFloorID , CString &strZtjzmj);

	static CString GetJzmjFromResult( const int iFloorId ) ;


	//设置某一层的阳台建筑面积
	static void SetYtjzmj(const int nFloorID , const CString & strYtjzmj );
	//获取
	static BOOL GetYtjzmj( const int nFloorID , CString & strYtjzmj);

	static BOOL IsUnderBaseFloor( const int iFloorID);

	/// 取楼层表中的第一层的楼地面标高
	static double	GetSnbg() ;
};
