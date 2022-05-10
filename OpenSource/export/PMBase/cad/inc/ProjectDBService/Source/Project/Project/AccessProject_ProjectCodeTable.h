#pragma once
//#include "..\accesstable.h"


class PMProjectDBSERVICE CAccessProject_ProjectCodeTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_ProjectCodeTable(void);
	virtual ~CAccessProject_ProjectCodeTable(void);

	BOOL CheckNeedUpDateTableField(int & iOldVersion);

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
	* @brief  获取工程版本号 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	BOOL GetProjectVersion(int & iProjectVer);

	/**
	* @brief 保存工程版本号  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [13/7/2012]
	*/
	BOOL SetProjectVersion(int iProjectVer);

	/// 
	BOOL SetProjectModeInfo( const CString & strCreateTime , const CString & strProjectCode ) ; 

	/// 
	BOOL GetProjectModeInfo( CString & strCreateTime , CString & strProjectCode ) ;

	/// 
	CString		GetRockInfo() ; 

	/// 
	void		SetRockInfo( const CString & strRockInfo ) ; 

protected:
	
	/// 
	CString		GetParmValue( const CString & strParmName ) ;

	/// 
	void		SetParmValue( const CString & strParmName , const CString & strParmValue ) ;


public:


	static PmTString GetSQL(const int & iSQLIndex);

	struct PMProjectDBSERVICE SQLInfo
	{
		const static int		m_iSelectProjectVer_Sql;
		const static PmTString	m_strSelectProjectVer_Sql;//获取版本号 sql

		const static int		m_iUpdateProjectVer_Sql;
		const static PmTString	m_strUpdateProjectVer_Sql;//修改版本号 sql
	};

	/// 
	/// 
	/// 
	static const CString m_strCreateTime ;
	static const CString m_strProjectMode ;
	static const CString m_strRockInfo ;
	static const CString m_strVersion ;
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

class PMProjectDBSERVICE CProjectCodeOpr
{
public:
	CProjectCodeOpr() ; 
	~CProjectCodeOpr() ; 

public:

	static BOOL GetProjectVersion(int & iProjectVer);
	static BOOL GetProjectVersion( CString & strProjectVer ) ;

	static BOOL SetProjectVersion( const int iProjectVer);
	static BOOL SetProjectVersion( const CString & strProjectVer);
};
