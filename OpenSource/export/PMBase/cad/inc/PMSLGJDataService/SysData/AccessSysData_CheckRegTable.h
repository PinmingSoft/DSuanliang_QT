#pragma once
#include "AccessSysDataTable.h "

/**
 * @brief ���������ܱ�
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-3]
 * @note  
 */
class PmSLGJDataServiceAPI CSysCheckRegTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysCheckRegTable)

	CSysCheckRegTable();
	virtual ~CSysCheckRegTable();

	

public:

	virtual int InitFieldStr();

public:

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id;
		static const CString checkreg_name;
		static const CString type;
		static const CString checkreg_info;
		static const CString info;

		static int id_Idx ;
		static int checkreg_name_Idx ;
		static int type_Idx ;
		static int checkreg_info_Idx ;
		static int info_Idx ;

		/// idx �����ĸ�������
		/// idx ��Ҫ�ں��� InitFieldStr �� ����ʼ��Ϊ�������ֵ
		/// �Ҹ�ֵ��˳��Ӧ�ú� InitFieldStr����ӵ�˳��һ��
		static int idx_step ; 
	};

	struct PmSLGJDataServiceAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	
};

class PmSLGJDataServiceAPI CAccessSysData_CheckRegTable :
	public CAccessSysDataTable
{
public:
	CAccessSysData_CheckRegTable(void);
	virtual ~CAccessSysData_CheckRegTable(void);

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
	* @brief ͨ��������ʽ ��������ȡ������ʽ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [28/6/2012]
	*/
	BOOL GetRegInfo(const CString & strRegName,CString & strRegInfo);

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	/// ���֧���Ѿ����ڵĽӿ�
	/// 

	/******************************************************************** 
	����������������ʹ��������ʽ�������ƣ��õ�������ʽ
	������strName��������ʽ�������ƣ� strCheckRegInfo:������ʽ
	�� �� ֵ���Ƿ���ҳɹ�
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[28/11/2007]
	*********************************************************************/ 
	BOOL GetCheckRegInfo( const CString & strName,CString & strCheckRegInfo);

	/******************************************************************** 
	���������������������ƻ�ȡ������ʽ
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҫ
	ʱ    �䣺[2009��5��27��]
	*********************************************************************/ 
	CString GetRegValue( const CString & strIndex ) ;


protected:
	
	/// �ж��Ƿ��Ǹֽ��������ʽ
	/// gjReg Ϊ������ʽ
	/// Լ�� ������ʽ�а��� [A-G] �� [A-E] ����Ϊ�Ǹֽ��������ʽ
	BOOL	IsSteel( const CString & gjReg ) ; 

	/// ����11G�ֽ��������ʽ
	void	ReplaceJb(  CString & strValue ) ;

	/// ����������ʽ
	CString  GetCheckValue( const CString &strName ) ; 

	/// ����|
	PmTString	DealRegInfoXS( const CString & strName ) ; 

	/// ����б��
	PmTString	DealRegInfoXG( const CString & strName ) ; 

	/// ����Ӻ�
	PmTString	DealRegInfoAdd( const CString & strName ) ; 

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

public:
	static PMTSTRING	GetSql( const int iType ) ;

	//�̶���SQL ����
	struct SQLInfo
	{
		/// 
		static const int m_iGetDataSet ; 
		static PMTSTRING m_strGetDataSet ; 

		/// 
		static const int m_iGetRegSql ;
		static PMTSTRING m_strGetRegInfoSql ;
	};

public:

	/// ˽�еĳ���
	struct PmSLGJDataServiceAPI constdata  
	{
		static const CString Begin ;			/// ��ʼ
		static const CString Add ;				/// +�� 
		static const CString AddConst ;			/// �滻�Ӻŵ�����
		static const CString XG ;				/// б�� (/)
		static const CString XGConst ;			/// �滻б�ܵĳ���
		static const CString Left ;				/// ��ߵ�����
		static const CString Right ;			/// �ұߵ�����

		static const CString BF	;				/// ����ӵĸֽ��
		static const CString BFConst ;			/// ��H�滻BF 11G
		static const CString B ;				/// ��B�ỻBF	03G

		static const CString CF ;				/// ����ӵĸֽ��
		static const CString CFConst ;			/// ��I�滻CF 
		static const CString C ;				/// ��C �滻CF 03G

		static const CString EF ;				/// ����ӵĸֽ��
		static const CString EFConst ;			/// ��J�滻EF 11G
		static const CString E ;				/// ��E �滻 EF 03G �� 

		static const CString BE ;				/// ����ӵļ���
		static const CString BEConst ;			/// �� K �滻BE

		static const CString CE ;				/// ����ӵļ���
		static const CString CEConst ;			/// �� L �滻CE	

		static const CString EE ;				/// ����ӵļ���
		static const CString EEConst ;			/// �� M �滻EE	

		static const CString BFE ;				/// ����ӵļ���
		static const CString BFEConst ;			/// �� N �滻BEF

		static const CString CFE ;				/// ����ӵļ���
		static const CString CFEConst ;			/// �� O �滻CFE

		static const CString EFE ;				/// ����ӵļ���
		static const CString EFEConst ;			/// �� P �滻EFE

		static const CString JB ;				/// �ֽ��
		static const CString JB1 ;				/// �ֽ��
		static const CString JBConst ;			/// 11 G ʱ �ֽ��[A-G] �滻[A-J]
		//static const CString JBConst2 ;			/// 11 G ʱ �ֽ��[A-G] �滻[A-J]

		static const CString YaoJinReg ;		/// ����Ĺ����ȡ�����ֱ��ʱ�õ�
		static const CString GjReg;			/// �ֽ�ȡ�����ֱ��ʱ�õ�

	};
};
