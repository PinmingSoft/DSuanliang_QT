
#pragma once 


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
class PmSLGJDataServiceAPI CSysHjdface_InfoTable : public CSysDataTable
{
public:
	DECLARE_DYNCREATE(CSysHjdface_InfoTable)

	CSysHjdface_InfoTable();
	~CSysHjdface_InfoTable() ;

public:
	virtual int InitFieldStr();

public:
	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString BH ;			/// ���
		static const CString GJMC ;			/// �ֽ�����
		static const CString GJName ;		/// �ֽ�
		static const CString GJValue ;		/// �ֽ����ֵ
		static const CString SLValue ;		/// ����ֵ
		static const CString SLConst ;		/// ������Ҫ֧�ֵĳ���
		static const CString LenValue ;		/// ����ֵ
		static const CString LenConst ;		/// ������Ҫ֧�ֵĳ���
		static const CString CheckValue ;	/// ������ʽ,���Ƹֽ������
		static const CString SLHitInfo ;	/// ��������ʾ��Ϣ
		static const CString LenHitInfo ;	/// ���ȵ���ʾ��Ϣ

		static int BH_Idx ;			/// ���
		static int GJMC_Idx ;			/// �ֽ�����
		static int GJName_Idx ;		/// �ֽ�
		static int GJValue_Idx ;		/// �ֽ����ֵ
		static int SLValue_Idx ;		/// ����ֵ
		static int SLConst_Idx ;		/// ������Ҫ֧�ֵĳ���
		static int LenValue_Idx ;		/// ����ֵ
		static int LenConst_Idx ;		/// ������Ҫ֧�ֵĳ���
		static int CheckValue_Idx ;	/// ������ʽ,���Ƹֽ������
		static int SLHitInfo_Idx ;	/// ��������ʾ��Ϣ
		static int LenHitInfo_Idx ;	/// ���ȵ���ʾ��Ϣ


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

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/// at 2010��12��31��  14:04  by yxy
/// �� SysData �� ������һ�ű� �洢 27 ���ֽ�ĳ�ʼ��

struct PmSLGJDataServiceAPI CHjdFaceInfo 
{
	CString BH ;
	CString GJMC ; 
	CString GJName ; 
	CString GJValue ; 
	CString CheckValue ; 
	CString SLValue ; 
	CString SLConst ; 
	CString LenValue ; 
	CString LenConst ; 
	CString SLHitInfo ; 
	CString LenHitInfo ;
};


class PmSLGJDataServiceAPI CAccessSysData_Hjdface_InfoTable : public CAccessSysDataTable 
{
public:
	CAccessSysData_Hjdface_InfoTable(void);
	virtual ~CAccessSysData_Hjdface_InfoTable(void);

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

	/// 
	NDataModelDataSet * GetEmptyDataSet() ; 

	BOOL GetHjdFaceInfo( const CString & strGjName , CHjdFaceInfo & hjdfaceinfo ) ; 

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
		static const int m_iGetHjdFaceInfo  ;
		static PMTSTRING m_strGetHjdFaceInfo ; 
	} ;
};

///
/// �󽽴� �ֽ����õĽ���� �� DataSet �Ľṹ Ϊ:
///	pDataSet->AddField( FAName , ftBlob , 0 ) ;  ��������
///	pDataSet->AddField( FAContent , ftBlob , 0 ) ; ��������
///	pDataSet->AddField( MainFace , ftBlob , 0 ) ; �������DataSet
///	pDataSet->AddField( VectorID, ftBlob , 0 ) ; ͼ��ID 
///	pDataSet->AddField( VectorParm , ftBlob , 0 ) ; ͼ�ε�DataSet 
///
/// ���� MainFace ����һ�� DataSet ��ṹΪ:
/// pDataSet->AddField( BH , ftBlob , 0 ) ;     /// ���
///	pDataSet->AddField( GJMC , ftBlob , 0 ) ; /// �ֽ�����
///	pDataSet->AddField( GJName , ftBlob , 0 ) ; /// �ֽ�
///	pDataSet->AddField( GJValue , ftBlob , 0 ) ; /// �ֽ����ֵ
///	pDataSet->AddField( SLValue , ftBlob , 0 ) ; /// ����ֵ
///	pDataSet->AddField( LenValue , ftBlob , 0 ) ;/// ����ֵ
/// pDataSet->AddField( CheckValue, ftBlob , 0 ) ; /// ������ʽ,���Ƹֽ������
/// 
/// VectorParm Ҳ��һ�� DataSet ��ṹ �� CVectorParmsTable 
/// 

class PmSLGJDataServiceAPI CHjdDataSetOpr  
{
public:
	CHjdDataSetOpr() ;
	~CHjdDataSetOpr() ; 

public:
	struct PmSLGJDataServiceAPI constdata 
	{
		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		static const CString FAName ;		/// ��������
		static const CString FAContent ;	/// ��������
		static const CString MainFace ;		/// �������DataSet
		static const CString VectorID ;		/// ͼ��ID 
		static const CString VectorParm ; 	/// ͼ�ε�DataSet 
		//////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////
		/// at 2010��9��15��  16:24  by yxy
		/// ���ֽ����ƶ���Ϊ����

		/// ��
		static const CString HJD1;					/// ���ڼ�ǿ����						/// 1
		static const CString HJD2 ;					/// ���ں����ϲ���ǿ��					/// 2
		static const CString HJD3 ;					/// ���ں����²���ǿ��					/// 3

		/// ��
		static const CString HJD4 ;					/// �����ϲ������ǿ��					/// 4
		static const CString HJD5 ;					/// �����²������ǿ��					/// 5
		static const CString HJD6 ;					/// ���������ϲ��ֲ���					/// 6
		static const CString HJD7 ;					/// ���������²��ֲ���					/// 7

		/// ǽ
		static const CString HJD8 ;					/// ǽ�������ڲ��ǿ��					/// 8
		static const CString HJD9 ;					/// ǽ����������ǿ��					/// 9
		static const CString HJD10 ;				/// ǽ�����ڲ��ǿ��					/// 10 
		static const CString HJD11 ;				/// ǽ��������ǿ��					/// 11 


		/// ������
		static const CString HJD12 ;				/// ��������ǿ����						/// 12
		static const CString HJD13 ;				/// �����������ϲ���ǿ��				/// 13
		static const CString HJD14 ;				/// �����������²���ǿ��				/// 14


		/// ����
		static const CString HJD15 ;				/// �������ϲ������ǿ��				/// 15
		static const CString HJD16 ;				/// �������²������ǿ��				/// 16
		static const CString HJD17 ;				/// �������ϲ�����ֲ���				/// 17
		static const CString HJD18 ;				/// �������²�����ֲ���				/// 18
		static const CString HJD19 ;				/// �����ǿ���ϲ������ǿ��			/// 19 
		static const CString HJD20 ;				/// �����ǿ���²������ǿ��			/// 20 
		static const CString HJD21 ;				/// �����ǿ�������ϲ��ֲ���			/// 21  
		static const CString HJD22 ;				/// �����ǿ�������²��ֲ���			/// 22
		static const CString HJD23 ;				/// �����ǿ���²������ǿ��1			/// 23 
		static const CString HJD24 ;				/// �����ǿ���ڽظ߷�������1			/// 24
		static const CString HJD25 ;				/// �����ǿ���ڽظ߷�������2			/// 25 
		static const CString HJD26 ;				/// �����ǿ���������ϲ��ֲ���			/// 26
		static const CString HJD27 ;				/// �����ǿ���������²��ֲ���			/// 27
		static const CString HJD28 ;				/// �����ǿ���ڽظ߷�������3			/// 28
		
		static const CString HJD29 ;				/// �����ǿ�������ǿ��		
		static const CString HJD30 ;				/// �����ǿ�������ǿ��			
		static const CString HJD31 ;				/// �����ǿ���ڽظ߷�������			
		static const CString HJD32 ;				/// �����ǿ���ϲ������ǿ��			
		static const CString HJD33 ;				/// �����ǿ���²������ǿ��			
		static const CString HJD34 ;				/// �����ǿ�������ϲ��ֲ���			
		static const CString HJD35 ;				/// �����ǿ�������²��ֲ���				
		static const CString HJD36 ;				/// �����ǿ���ϲ������ǿ��			
		static const CString HJD37 ;				/// �����ǿ���²������ǿ��				
		static const CString HJD38 ;				/// �����ǿ�������ϲ��ֲ���			
		static const CString HJD39 ;				/// �����ǿ�������²��ֲ���				
		static const CString HJD40 ;				/// �����ǿ�������ǿ��1				
		static const CString HJD41 ;				/// �����ǿ�������ǿ��2				
		static const CString HJD42 ;				/// �����ǿ�������ǿ��	

		// ������
		static const CString HJD43 ;				/// ��������ǿ���ϲ������ǿ��			
		static const CString HJD44 ;				/// ��������ǿ���²������ǿ��			
		static const CString HJD45 ;				/// ��������ǿ�������ϲ��ֲ���				
		static const CString HJD46 ;				/// ��������ǿ�������²��ֲ���			
		static const CString HJD47 ;				/// ��������ǿ���²������ǿ��				
		static const CString HJD48 ;				/// ��������ǿ���ڽظ߷�������1				
		static const CString HJD49 ;				/// ��������ǿ���ڽظ߷�������2			
		static const CString HJD50 ;				/// ��������ǿ���ڽظ߷�������3			
		static const CString HJD51 ;				/// ��������ǿ���������ϲ��ֲ���			
		static const CString HJD52 ;				/// ��������ǿ���������²��ֲ���
		static const CString HJD53 ;				/// ��������ǿ�������ǿ��
		static const CString HJD54 ;				/// ��������ǿ������ֲ���
		static const CString HJD55 ;				/// ��������ǿ���ڽظ߷�������
		static const CString HJD56 ;				/// ��������ǿ���ϲ������ǿ��
		static const CString HJD57 ;				/// ��������ǿ���²������ǿ��				
		static const CString HJD58 ;				/// ��������ǿ�������ϲ��ֲ���				
		static const CString HJD59 ;				/// ��������ǿ�������²��ֲ���			
		static const CString HJD60 ;				/// ��������ǿ�������ϲ��ֲ���				
		static const CString HJD61 ;				/// ��������ǿ�������²��ֲ���				
		static const CString HJD62 ;				/// ��������ǿ�������ϲ��ֲ���				
		static const CString HJD63 ;				/// ��������ǿ�������²��ֲ���				
		static const CString HJD64 ;				/// ��������ǿ�������ǿ��1				
		static const CString HJD65 ;				/// ��������ǿ�������ǿ��2
		static const CString HJD66 ;				/// ��������ǿ������ֲ���

		// ����ǽ
		static const CString HJD67 ;				/// ǽ��ǿ���ں����ڲ��ǿ��				
		static const CString HJD68 ;				/// ǽ��ǿ���ں�������ǿ��				
		static const CString HJD69 ;				/// ǽ��ǿ���������ڲ�ֲ���			
		static const CString HJD70 ;				/// ǽ��ǿ�����������ֲ���				
		static const CString HJD71 ;				/// ǽ��ǿ���ں�������ǿ��				
		static const CString HJD72 ;				/// ǽ��ǿ���ڽظ߷�������1				
		static const CString HJD73 ;				/// ǽ��ǿ���ڽظ߷�������2				
		static const CString HJD74 ;				/// ǽ��ǿ���ڽظ߷�������3
		static const CString HJD75 ;				/// ǽ��ǿ���������ڲ�ֲ���
		static const CString HJD76 ;				/// ǽ��ǿ�����������ֲ���
		static const CString HJD77 ;				/// ǽ��ǿ���ں����ǿ��
		static const CString HJD78 ;				/// ǽ��ǿ��������ֲ���
		static const CString HJD79 ;				/// ǽ��ǿ���ڽظ߷�������3				
		static const CString HJD80 ;				/// ǽ��ǿ���ں����ڲ��ǿ��				
		static const CString HJD81 ;				/// ǽ��ǿ���ں�������ǿ��			
		static const CString HJD82 ;				/// ǽ��ǿ���������ڲ�ֲ���				
		static const CString HJD83 ;				/// ǽ��ǿ�����������ֲ���				
		static const CString HJD84 ;				/// ǽ��ǿ���ں����ڲ��ǿ��				
		static const CString HJD85 ;				/// ǽ��ǿ���ں�������ǿ��				
		static const CString HJD86 ;				/// ǽ��ǿ���������ڲ�ֲ���				
		static const CString HJD87 ;				/// ǽ��ǿ�����������ֲ���
		static const CString HJD88 ;				/// ǽ��ǿ���ں����ǿ��1
		static const CString HJD89 ;				/// ǽ��ǿ���ں����ǿ��2
		static const CString HJD90 ;				/// ǽ��ǿ��������ֲ���

		static const  CString HJDFBqtgj ;		/// ����������ֽ�					/// 
		static const  CString HJDJLqtgj ;		/// �����������ֽ�					/// 
		static const  CString HJDLqtgj ;		/// �������ֽ�					/// 
		static const  CString HJDQqtgj ;		/// ǽ�����ֽ�					/// 
		static const  CString HJDBqtgj ;		/// �������ֽ�					/// 
		/// �����ʼ���Ľ���ͼ
		static const CString LiangVectorID  ; 
		static const CString JcLiangVectorID ; 
		static const CString BanVectorID ; 
		static const CString QiangVectorID ; 
		static const CString FaBanVectorID1 ; 
		static const CString FaBanVectorID2 ;
		static const CString FaBanVectorID3 ;
		static const CString FaBanVectorID4 ;
		static const CString FaBanVectorID5 ;
		static const CString FaBanVectorID6 ;
		static const CString FaBanVectorID7 ;
		static const CString QiangVectorID1 ; 
		static const CString QiangVectorID2 ;
		static const CString QiangVectorID3 ;
		static const CString QiangVectorID4 ;
		static const CString QiangVectorID5 ;
		static const CString QiangVectorID6 ;
		static const CString QiangVectorID7 ;
		static const CString JcLiangVectorID1 ; 
		static const CString JcLiangVectorID2 ;
		static const CString JcLiangVectorID3 ;
		static const CString JcLiangVectorID4 ;
		static const CString JcLiangVectorID5 ;
		static const CString JcLiangVectorID6 ;
		static const CString JcLiangVectorID7 ;

		static const CString FanName1 ;
		static const CString FanName2 ;
	};

	enum CType
	{
		eLiang  = 0,	/// ��
		eBan ,		/// ��
		eQiang ,	/// ǽ
		eQiang1 ,	/// ǽ1
		eQiang2 ,	/// ǽ2
		eQiang3 ,	/// ǽ3
		eQiang4 ,	/// ǽ4
		eQiang5 ,	/// ǽ5
		eQiang6 ,	/// ǽ6
		eQiang7 ,	/// ǽ7
		eQiangNq ,	/// ǽ
		eJcLiang ,	/// ������
		eJcLiang1 ,	/// ������1
		eJcLiang2 ,	/// ������2
		eJcLiang3 ,	/// ������3
		eJcLiang4 ,	/// ������4
		eJcLiang5 ,	/// ������5
		eJcLiang6 ,	/// ������6
		eJcLiang7 ,	/// ������7
		eFaban1,	/// ����1
		eFaBan2,	/// ����2
		eFaBan3,	/// ����3
		eFaBan4,	/// ����4
		eFaBan5,	/// ����5
		eFaBan6,	/// ����6
		eFaBan7		/// ����7
	};

public:
	/// 
	static NDataModelDataSet *				GetDataSet( CHjdDataSetOpr::CType type  ) ; 

	/// �ܵ�DataSet 
	static NDataModelDataSet *				GetTotalDataSet() ; 
	/// �������ϵ�DataSet
	static NDataModelDataSet *				GetMainFaceDataSet() ;

	////////////////////////////////////////////////////////////////
	/// at 2010��9��20��  16:40  by yxy
	/// pGridDataset �� pVectorDataSet ��������Ҫά��
	/// �ڼ���󽽴��ս��ʱ��
	/// ��ȡ�����ֽ��pGridDataset �� ͼ�ε�pVectorDataSet
	/// ǽ/��/���� ��������ӿ� 
	static BOOL							GetDataSet( 
		CString  strValue ,
		NDataModelDataSet * pGridDataset , 
		NDataModelDataSet * pVectorDataSet 
		) ;

	/// ���ͻ�����������ӿ� 
	static BOOL							GetDataSet( 
		const int & nWidth , 
		const int &nHeight , 
		CString strValue ,
		NDataModelDataSet * pGridDataset , 
		NDataModelDataSet * pVectorDataSet 
		) ;

	/*****************************************************
	* ��ȡ�󽽴���Ϣ��"�����ֽ�"��ľ���ֵ
	* ����:
	*	strData:���������Ϣ���ַ�����,����󽽴�����fbhjd�е�InvalidMsg��
	*	type:�������ĺ󽽴�����,Ŀǰ��֧��eFaBan1
	* ����ֵ:
	*	ΪNULLʱ�����ȡʧ��
	* ע��:
	*	���ص�ָ����ʹ����Ϻ���Ҫɾ��,����ᵼ���ڴ�й©
	* wrq [2017-4-19]
	*****************************************************/
	static NDataModelDataSet* GetQtgjInfo(CString strData, CHjdDataSetOpr::CType type);

	/*****************************************************
	* v9.4����"�����ֽ�"������,�ɰ汾����������Ҫ�������
	* ��Ϊ��ṹ������Ϊ�鷳,���Բ�ֱ������,��Ϊ�ڴ����
	* ����ֵ:
	*	TRUE������ӳɹ�
	*	FALSE�����Ѵ��ڻ��߸����Ͳ����������ֽ�������
	* wrq [2017-4-20]
	*****************************************************/
	static BOOL AddQtgjInfo(NDataModelDataSet *pDataSet, CHjdDataSetOpr::CType type);

private:
	/// ��
	static NDataModelDataSet *				GetLiangDataSet() ;
	/// ������
	static NDataModelDataSet *				GetJcLiangDatSet() ; 
	/// ��
	static NDataModelDataSet *				GetBanDataSet() ; 
	/// ǽ
	static NDataModelDataSet *				GetQiangDataSet() ; 
	/// ����1
	static NDataModelDataSet *				GetFaBan1() ; 
	/// ����2
	static NDataModelDataSet *				GetFaBan2() ; 
	/// ����3
	static NDataModelDataSet *				GetFaBan3();
	/// ����4
	static NDataModelDataSet *				GetFaBan4();
	/// ����5
	static NDataModelDataSet *				GetFaBan5();
	/// ����6
	static NDataModelDataSet *				GetFaBan6();
	/// ����7
	static NDataModelDataSet *				GetFaBan7();

	/// ����ǽ1
	static NDataModelDataSet *				GetQiangDataSet1() ; 
	/// ����ǽ2
	static NDataModelDataSet *				GetQiangDataSet2() ; 
	/// ����ǽ3
	static NDataModelDataSet *				GetQiangDataSet3();
	/// ����ǽ4
	static NDataModelDataSet *				GetQiangDataSet4();
	/// ����ǽ5
	static NDataModelDataSet *				GetQiangDataSet5();
	/// ����ǽ6
	static NDataModelDataSet *				GetQiangDataSet6();
	/// ����ǽ7
	static NDataModelDataSet *				GetQiangDataSet7();
	/// ������1
	static NDataModelDataSet *				GetJcLiangDatSet1() ; 
	/// ������2
	static NDataModelDataSet *				GetJcLiangDatSet2() ; 
	/// ������3
	static NDataModelDataSet *				GetJcLiangDatSet3() ; 
	/// ������4
	static NDataModelDataSet *				GetJcLiangDatSet4() ; 
	/// ������5
	static NDataModelDataSet *				GetJcLiangDatSet5() ; 
	/// ������6
	static NDataModelDataSet *				GetJcLiangDatSet6() ; 
	/// ������7
	static NDataModelDataSet *				GetJcLiangDatSet7() ;
	
	/// ��ֱ��ʽ
	static void							GetMinMaxWidth( CString strValue , int &nMin , int &nMax , BOOL & bIsEqu ) ; 
	static void							GetMinMaxHeight( CString strValue , int &nMin , int &nMax,BOOL & hIsEqu) ; 
	///����
	static void                         GetOperator( const int iPos, CString strValue , int &nMin , int &nMax  , BOOL & bIsEqu );
	static void							InsertRow( NDataModelDataSet * pDataSet , 
		const CString & strGjName , 
		const CString & strBH = _T("-1") ) ; 
};
