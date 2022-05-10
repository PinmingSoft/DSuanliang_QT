

#pragma once 

/**
 * @brief ���������У����ù���������ͳһ�Ŀ�����
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2013-5-22]
 * @note  
 */


typedef std::set<int> CPmIntSet ; 
typedef CPmIntSet::iterator	CPmIntSetIter ;
typedef CPmIntSet::const_iterator CPmIntSetConIter ; 


/// 
typedef std::map< int , int > CPmInt2IntMap ;
typedef CPmInt2IntMap::iterator CPmInt2IntMapIter ; 
typedef CPmInt2IntMap::const_iterator CPmInt2IntMapConIter ; 


typedef std::map< CString , int > CPmStr2IntMap ;
typedef CPmStr2IntMap::iterator CPmStr2IntMapIter ;
typedef CPmStr2IntMap::const_iterator CPmStr2IntMapConIter ;

class PMProjectDBSERVICE CProjectGlobleParmOpr
{

private:
	CProjectGlobleParmOpr() ; 

public:
	virtual ~CProjectGlobleParmOpr() ; 

	static CProjectGlobleParmOpr & Instance() ; 

public:
	void		Init() ; 

	void		Release() ;

	/// Ӧ�����еĲ����� ȫ�ֲ�������
	void		ApplyAllDataSet() ;

	/// ������������еĴ����ʽ
	void		DealJsszDjxs() ; 

	// �Ѽ������ñ��浽���ݿ��ļ���
	void SaveJsszToProject();

	void ApplyComParmsSet_ComIdTable();
	///	�ֽ�ģʽ���л� 03/11/16
	void		ChangeGangJinMode(ProjectInfoMacro::GangJinMode mode) ; 

	/// �жϼ��������Ƿ����޸�
	BOOL		IsGlobalParmModified() const
	{
		if(m_pParmBase)
			return m_pParmBase->GetModified();
		return FALSE;
	}

public:


	/// �������ûظ�Ĭ��
	void		ResumeJssz(const int iComType , NDataModelDataSet * pDefaultDataSet , const int iSubComtype = -1) ; 

	/// 
	NDataModelDataSet * GetJsszDataSet( const int iComType , const int iSubComtype = -1) ; 

	/// 
	void SetJsszDataSet( const int iComType , NDataModelDataSet * pJsszDataSet , const int iSubComtype = -1) ;

	/**
	* @brief �ṩComType��Ӧ������subComType
	*			arrValue��������
	*			arrName����������
	* @author ����ǿ
	* @version v1.0
	* @date  [2016-11-01]
	* @note  �ú�������մ�������;����ú���Ч�ʽϵ�
	*/
	void GetSubComtypeByComtype(const int iComType, CStringArray &arrValue, CStringArray &arrName);

public:
	void		ResumeJsgz( ) ;

public:

	void		ApplyDefaultComponents( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype 
		) ;

	/**
	* @brief   Ϊ�½����������ĺ������Ժ��������⴦��  ��������
	*
	*			
	* @note  : 
	* @param : 
	* @return: 
	* @author: wyz
	* @date  : [7/23/2021]
	*/
	void		ApplyDefaultComponentsNewProject( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype 
		) ;

	/// Ӧ�ü�������
	void		ApplyJsszToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

protected:
	/// 
	/// aryComType Ϊ����ҪӦ�ù�����comtype
	/// 
	/// 
	void		ApplyJsszToProjectComId( const CUIntArray & aryInComId , const CUIntArray & aryNotInComId , const CUIntArray & arr_graphcomtype ) ;

protected:
	/**
	* @brief ��sysdata���ݿ���comparmsset��comparmsset_XXG���滻project���ݿ���comparmsset_base��
	*
	*        
	* @author ����ǿ
	* @version v1.0
	* @date  [2016-11-01]
	* @note  
	*/
	void		CopySysUnionTable2ProTable(ProjectInfoMacro::GangJinMode mode);

	/**
	* @brief �߸ֽ�ģʽ��͵׸ֽ�ģʽת��
	*		 Ŀǰ��Ҫ�����滻16G����11G/03G�����ڵ���
	*        
	* @author ����ǿ
	* @version v1.0
	* @date  [2016-12-26]
	* @note  
	*/
	void		ConvertToLowVersion();

protected:
	void		GetHasSetComId( const CPmIntSet & setHasSetComId , CUIntArray & aryDesComId  ) ;

public:

	void		ApplyJsgzToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		)  ;

protected:
	void		ApplyJsgzToProject(
		const CUIntArray & aryInComId , 
		const CUIntArray & aryNotInComId ,
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		)  ;

public:

	void		ApplyGjsxToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

protected:
	void		ApplyGjsxToProject(
		const CUIntArray & aryInComId , 
		const CUIntArray & aryNotInComId ,
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

	
public:
	// �Ըֽ��������������ȫ������
	void ApplyALLGJ_Rule(const CString& strParmValue);
	void		ApplyDjxsToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

protected:
	void		ApplyDjxsToProject(
		const CUIntArray & aryInComId , 
		const CUIntArray & aryNotInComId ,
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ;

public:

	/// �������õĴ����ʽӦ��
	void		ApplyJsszDjxsToProject(
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		) ; 

protected:
	void	GetInComId( const CUIntArray & aryAllComId , const int iComType , CUIntArray & aryDesComId ) ;

public:

	void		ApplyGjxxToProject( 
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		)  ;

protected:
	void		ApplyGjxxToProject( 
		const CUIntArray & aryInComId , 
		const CUIntArray & aryNotInComId ,
		const CUIntArray & arr_floor ,
		const CUIntArray & arr_graphcomtype
		)  ;


protected:
	NDataModelDataSet * GetSpecialDataSet( const PmStrSet & setTotalParm ) ;

	void	GetInComId( const CUIntArray & aryAllComId , const int iFloorId , const int iComType , CUIntArray & aryDesComId ) ;

	//����parmbase ��ֵ-----���������ڲ�ʹ�ã������ж�row�ĺ�����
	void	SetFieldValue(const CString & fieldName, int row, const CString & fieldValue);

public:
	/// 
	void	SetComParm( const CString & strParmName,const CString & strParmValue);

	/// 
	BOOL	GetComParm( const CString & strParmName , CString & strParmValue ) ;

	/// 
	BOOL	GetComParmValueList(const CString & strParmName,CString & strParmValue,CString & strParmList )  ;

	/// 
	BOOL	GetGJTZZ_Const(const CString & strGJBLFS,CString & strDoubleGJTZZ,CString & strSingleGJTZZ);

	/// 
	BOOL	GetGJTZZ_ComParmSet(CString & strDoubleGJTZZ,CString & strSingleGJTZZ);

	/// 
protected:

	/// 
	void	InitParmBase() ;

	/// 
	void	FillParmBase() ; 

	/// 
protected:

	/// �� comparmsset_base ��һ�����ݣ� ����һ�� orgparmvalue 
	NDataModelDataSet * m_pParmBase ; 

	/// 
	static const CString	m_strOrgParmValue ; 
	static const CString	m_strOrgInvaidMsg ; 

};

#define ProjectGlobleParmOpr CProjectGlobleParmOpr::Instance() 