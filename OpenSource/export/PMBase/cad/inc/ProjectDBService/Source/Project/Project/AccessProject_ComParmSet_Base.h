

#pragma once 

////#include "..\accesstable.h"

/**
 * @brief �����Ļ�����
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2013-5-20]
 * @note  
 */
class PMProjectDBSERVICE CProject_ComParmSet_BaseTable : public CSQLDataSet
{
	DECLARE_DYNCREATE(CProject_ComParmSet_BaseTable)

	CProject_ComParmSet_BaseTable();
	virtual ~CProject_ComParmSet_BaseTable();

public:
	//����
	static const CString kMultiValue ;
	//��Ч��usedAsBz ֵ�����ñ�ֵʱ�����治������ֱ�ע�ķ���
	static const int kUsedAsBz_Invalid;
	//usedAsBz �Ķ��ַ�ʽ
	static const int kMultiValue_UsedAsBz;

	//
	virtual int InitFieldStr();

public:
	struct PMProjectDBSERVICE CFieldInfo
	{
		static const CString ParmID ;
		static const CString gangjin_mode ;
		static const CString UpdateMode ;
		static const CString comtype ;
		static const CString SubComType ;
		static const CString parmtype ;
		static const CString parmname ;
		static const CString parmdisplayname ;
		static const CString parmvalue ;
		static const CString InputMode ;
		static const CString DataType ;
		static const CString processType ;
		static const CString exp ;
		static const CString InvalidMsg ;
		static const CString Hide ;
		static const CString SortID ;
		static const CString TreeNode ;
		static const CString Used_Bz ;

		static		 int	 ParmID_Index;
		static		 int	 gangjin_mode_Index;
		static		 int	 UpdateMode_Index;
		static		 int	 comtype_Index;
		static		 int	 SubComType_Index;
		static		 int	 parmtype_Index;
		static		 int	 parmname_Index;
		static		 int	 parmdisplayname_Index;
		static		 int	 parmvalue_Index;
		static		 int	 InputMode_Index;
		static		 int	 DataType_Index;
		static		 int	 processType_Index;
		static		 int	 exp_Index;
		static		 int	 InvalidMsg_Index;
		static		 int	 Hide_Index;
		static		 int	 SortID_Index;
		static		 int	 TreeNode_Index;
		static		 int	 Used_Bz_Index;

		/// idx �����ĸ�������
		/// idx ��Ҫ�ں��� InitFieldStr �� ����ʼ��Ϊ�������ֵ
		/// �Ҹ�ֵ��˳��Ӧ�ú� InitFieldStr����ӵ�˳��һ��
		static int idx_step ; 
	};

	struct PMProjectDBSERVICE CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};
};

//�������� ����
class PMProjectDBSERVICE CAccessProject_ComParmSet_BaseTable :
	public CPMSLAccessTable
{
public:
	CAccessProject_ComParmSet_BaseTable(void);
	virtual ~CAccessProject_ComParmSet_BaseTable(void);

public:

	/**
	* @brief   ���� ������ṹ
	*/
	virtual BOOL TryUpdateTableField();


	/// 
	CSQLDataSet * GetDataSet();

	/**
	* @brief  ��ȡ�յ� Dataset�������� ִ��sql������
	* @date  : [13/7/2012]
	*/
	CSQLDataSet * GetEmptyDataSet();

	/// 
	CSQLDataSet * GetComParm( const int iComType , const int iGangJinMode ) ; 

	/// 
	CSQLDataSet * GetComParm( const int iComType , const CUIntArray & aryParmType , const int iGangJinMode ) ; 

	/// 
	void	GetComTypeAry( CUIntArray & aryComType ) ;

	/// 
	BOOL	Delete() ; 
	// ���¸ֽ��������
	void UpDateGJGSRule(const CString & strParmValue,const CUIntArray & aryComType);
	/// ˢ��updatemode����
	BOOL	SetUpdateMode(int comtype,CString parmname,int updateMode);

	/**
	* @brief   c:28072 ��ȡ���ݿ��Invalidmsg���ԣ��˷�������ģ����base��Ѱ��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: lbw
	* @date  : [9/6/2019]
	*/
	void	GetBaseInvalidmsg(const int & iComType, const CString & strParmName, const CString & strParmValue, CString & strInvailMsgBase);

public:
	static PmTString GetSQL(const int iSQLIndex);

	struct SQLInfo
	{
		///delete from ComParmSet_Base
		static const int m_iDelete ;
		static PMTSTRING m_strDelete ;
	};
};