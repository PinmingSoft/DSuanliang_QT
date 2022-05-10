

#pragma  once 

#include "AccessSysDataTable.h"

/**
 * @brief 
 *
 *        
 * @author ����ҫ
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


class PmSLGJDataServiceAPI CAccessSysData_InitMgTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_InitMgTable(void);
	virtual ~CAccessSysData_InitMgTable(void);

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
protected:
	/******************************************************************** 
	�������������� ����ȼ� / �ֽ����� / �ֽ�����
	��ǿ�� / ��Ӱٷ��� / ֱ���Ƿ����25 
	����ȡ ê��ֵ �� ���ֵ
	������
	strKzdj : �ǿ���\0;һ��\1;����\2;����\3;�ļ�\4;

	11G��
	//strGjlx : ��ͨ�ֽ�\1;��θֽ�\2;�����ֽ�\3;ԤӦ���ֽ�\4;������֬Ϳ��ֽ�\7;
	//strGjzl : һ����\1;������\2;������\3;��������\4;������Ť\5;����\6;
	//strTqd  : C20 C25 C30 C35 C40 / �����ݿ���ֻ�����⼸�� 
	//Ҫ��С�� C20 ȡC20 
	//���� C40 ��ȡ  C40 

	gjlx:2��ʾ������֬Ϳ��ֽ�,1��ʾ��ͨ�ֽ�����������͸ֽ�,

	gjzl:1��ʾHPB300;2��ʾHRB335��HRBF335;3��ʾHRB400��HRBF400��RRB400;4��ʾHRB500��HRBF500;5��ʾ�������߸ֽ�;6��ʾ����Ť�ֽ�;7��ʾ����;

	tqd:C20,C25,C30,C35,C40,C45,C50,C55,C60
	����C60��C60ȡֵ,С��C20��C20ȡֵ

	03G��
	gjlx:2��ʾ������֬Ϳ��ֽ�,1��ʾ��ͨ�ֽ�����������͸ֽ�,
	gjzl:1��ʾһ����;2��ʾ������;3��ʾ������;4��ʾ�������߸ֽ�;5��ʾ����Ť�ֽ�;6��ʾ����;
	tqd:C20,C25,C30,C35,C40,
	����C40��C40ȡֵ,С��C20��C20ȡֵ

	strDjbfl : ��25%\1;50%\2;100%\3;

	str25 : ֱ�� <= 25 \1 ; ֱ�� >25 \0 ; 

	double dRDGJXS:�Ŷ��ֽ�ϵ��
	double dBHCHDXS���������� ϵ��
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҫ
	ʱ    �䣺[2009��7��2��]
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


	//ê��ֵ���Ӱٷ���
	CString GetDjValue(const CString & strMgz,const CString & strbfl);

	// �и���ֵ �����ݴ��淽ʽΪXX*d;XX*d;XX*d;
	//wrq [2017-1-16]
	CString SplitDjValueList(const CString & strDjzList,const CString & strbfl);

	/// ��ȡ���ê��
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
	//�̶���SQL ����
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

	/// ���ֵ��ѯҲͨ����
	/// �ɵĴ��ֵ���㷽��: ê��ֵ * ��Ӧϵ��
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


