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
	* @brief  ��ȡ���̰汾�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	BOOL GetProjectVersion(int & iProjectVer);

	/**
	* @brief ���湤�̰汾��  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
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
		const static PmTString	m_strSelectProjectVer_Sql;//��ȡ�汾�� sql

		const static int		m_iUpdateProjectVer_Sql;
		const static PmTString	m_strUpdateProjectVer_Sql;//�޸İ汾�� sql
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
* @brief   ��װһЩ��ʱ����Ķ������ (�䵱 ����Access�� ������)
*
*          
* @note  : ����Ҫÿһ���õ��ĵط���ȥ����һ����ʱ���� �� ��һЩ�������͵�ת�������ڸ�����ʵ��
*
* @author: ����ҫ
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
