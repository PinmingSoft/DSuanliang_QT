#pragma once
////#include "..\accesstable.h"



class PMProjectDBSERVICE CAccessProject_SpecificGravityTable :
	public CPMSLAccessTable
{
public:
	enum Enum_Gjlx {
		gjlx_pt = 1 ,		/// ��ͨ�ֽ�
		gjlx_lzdl = 5 ,		/// ��������
		gjlx_lzkn = 6		/// ������Ť
	};

public:
	CAccessProject_SpecificGravityTable(void);
	CAccessProject_SpecificGravityTable(BOOL bTemplateDb);
	~CAccessProject_SpecificGravityTable(void);
	
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
	* @brief   ��ȡ�汾��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-3]
	*/
	static	int	GetCurVersion() ;

	/**
	* @brief   ��ȡ��������ݣ����Ƽ�ʹ�ã�
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
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

	//��һ���ֽ�ֱ��(bOnlyComnSteel ��ʾ�Ƿ����ͨ�ֽ���ų�������Ť����������)
	CString	GetAfterDiameter( const CString & strCurDia ,BOOL bOnlyComnSteel) ; 

	//ǰһ���ֽ�ֱ��(bOnlyComnSteel ��ʾ�Ƿ����ͨ�ֽ���ų�������Ť����������)
	CString GetBeforDiameter( const CString & strCurDia ,BOOL bOnlyComnSteel) ;

	//��ͨ�ֽ��ֱ���ж�(bOnlyComnSteel ��ʾ�Ƿ����ͨ�ֽ���ų�������Ť����������)
	BOOL	JugeDiameter( const CString & strCurDia ,BOOL bOnlyComnSteel) ;

	///	
public:
	static PMTSTRING	GetSql( const int iType ) ;


public:
	//�̶���SQL ����
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
* @brief   ��װһЩ��ʱ����Ķ������ (�䵱 ����Access�� ������)
*
*          
* @note  : ����Ҫÿһ���õ��ĵط���ȥ����һ����ʱ���� �� ��һЩ�������͵�ת�������ڸ�����ʵ��
*
* @author: ����ҫ
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


	/// �ж�ֱ���Ƿ��ڸñ���
	static BOOL	CheckDiameter( const int gjlx , const CString &diameter ) ; 
	static BOOL	CheckDiameter( const CString gjjb , const CString &diameter ) ; 
	static BOOL	CheckDiameter ( const CStringArray & aryJb , const CStringArray & aryZj ) ; 
};
