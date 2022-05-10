#pragma once

//#include "PMArchiveBase.h"
#include "ParmInfoBase.h"

namespace ProjectInfoMacro
{
	enum GangJinMode//�ֽ�ģʽ
	{
		GangjinDefault = -1,
		GangJin03G = 0,
		GangJin11G = 1,
		GangJin16G = 2
	};
}

namespace Steel3DInfo 
{
	//�乳����
	enum WGLX
	{
		eNoWg = 0	//û�乳
		,eWg90		//90���乳
		,eWg135		//135�乳
		,eWg180		//180���乳
	};
}



class PMLogicDataOprAPI CProject_CalRule_SgdLbTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_CalRule_SgdLbTable)

	CProject_CalRule_SgdLbTable();
	virtual ~CProject_CalRule_SgdLbTable();

	struct PMLogicDataOprAPI CFieldInfo
	{	
		static const CString comtype;					//����comtype
		static const CString parmid;					//��ӦSysDefRule.xml�е�parmid
		static const CString parmname;					//��ӦSysDefRule.xml�е�parmname
		static const CString sgdlb;						//ʩ�������

		static const CString table_name;				//����
		static const CString strSQL;					// SQL���
	};

	virtual int InitFieldStr();
	int InitFieldStr( NDataModelDataSet * pDataSet );
};

class PMLogicDataOprAPI CProject_QtgjTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_QtgjTable)

	CProject_QtgjTable();
	virtual ~CProject_QtgjTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id ;
		static const CString comtype ;
		static const CString showname ;
		static const CString qtgj ; 
	};


	struct PMLogicDataOprAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};


	virtual int InitFieldStr();

public:
	/// 
	/// �ýӿ������������
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};

class PMLogicDataOprAPI CProject_TtymjTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_TtymjTable)

	CProject_TtymjTable();
	virtual ~CProject_TtymjTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id ;
		static const CString comtype ;
		static const CString showname ;
		static const CString ttymj ; 
	};


	struct PMLogicDataOprAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};


	virtual int InitFieldStr();

public:
	/// 
	/// �ýӿ������������
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};

class PMLogicDataOprAPI CProject_FloorDJXSTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_FloorDJXSTable)

	CProject_FloorDJXSTable();
	virtual ~CProject_FloorDJXSTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;
		static int	 id_Index;

		static const CString zjfw;			//ֱ����Χ
		static int		zjfw_Index;

		static const CString jc;				//����
		static int			jc_Index;

		static const CString qsx;				//ǽ����
		static int			qsx_Index;

		static const CString qsp;				//ǽ����
		static int			qsp_Index;

		static const CString zhu;				//��
		static int			zhu_Index;

		static const CString kjl;				//�����	
		static int			kjl_Index;

		static const CString cl;				//����	
		static int			cl_Index;

		static const CString ban;				//��
		static int			ban_Index;

		static const CString qt;				//����
		static int			qt_Index;

		static const CString sp_value ;//ˮƽ�� ��� 
		static const CString sz_value ;//��ֱ�� ���

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

/**
 * @brief ��ӷ����������������ȵ�Grid�ֶ�
 *
 *        
 * @author ֣����
 * @version v1.0
 * @date  2016��3��18��   12:19
 * @note  
 */
class PMLogicDataOprAPI CProject_SlopeEarTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SlopeEarTable)

	CProject_SlopeEarTable();
	virtual ~CProject_SlopeEarTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;
		static int	 id_Index;

		static const CString jclx;			//��������
		static int		jclx_Index;

		static const CString parmname;		//��������
		static int parmname_Index;

		static const CString wtsd;			//�������
		static int			wtsd_Index;

		static const CString fptfzshd;		//��������������
		static int			fptfzshd_Index;


		static const CString table_name;
	};

	virtual int InitFieldStr();

	int	InitFieldStrV2( NDataModelDataSet * pDataSet ) ; 
};

/**
 * @brief  :ʵ�������������ݽṹ
 *
 *          
 * @author :zfy
 * @version:v1.0
 * @date   :[9/11/2017]
 * @note   :
 */
class PMLogicDataOprAPI CProject_SwlRule_ForCal : public CPM_StorageDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SwlRule_ForCal)

	CProject_SwlRule_ForCal();
	virtual ~CProject_SwlRule_ForCal();

	struct PMLogicDataOprAPI CFieldInfo
	{
		//id
		static const CString id;
		static const int	 id_Index;
		
		static const CString parmid;
		static const int	 parmid_Index;

		//����
		static const CString name;
		static const int name_Index;

		//comtype
		static const CString comtype;
		static const int	 comtype_Index;

		//��������
		static const CString mid_var_name;
		static const int	 mid_var_name_Index;

		//����ֵ
		static const CString mid_var_value;
		static const int	 mid_var_value_Index;

		//�Ƿ����
		static const CString output;
		static const int	 output_Index;

		//�����ֶΣ�������ͬparmid �ڲ����е�����
		static const CString sortid;
		static const int	 sortid_Index;

		//��λ
		static const CString unit;
		static const int unit_Index;

		//������Ŀ/�ۼ���Ŀ/������Ŀ
		static const CString quantity;
		static const int quantity_Index;

		//�����ߴ�
		static const CString sections;
		static const int sections_Index;

		//���㹫ʽ
		static const CString formulas;
		static const int formulas_Index;

		//�༭ģʽ
		static const CString editmode;
		static const int editmode_Index;

		//����
		static const CString table_name;
	};

	virtual int InitFieldStr();

	int	InitFieldStrV2( NDataModelDataSet * pDataSet ) ; 
};

class PMLogicDataOprAPI CProject_SpecificGravityTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SpecificGravityTable)

	CProject_SpecificGravityTable();
	virtual ~CProject_SpecificGravityTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;					
		static const CString xh;
		static const CString gjlx;
		static const CString diameter;
		static const CString sg;

		///static const CString table_name;
	};

	struct PMLogicDataOprAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

	virtual int InitFieldStr();
};

class PMLogicDataOprAPI CProject_ProjectCodeTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ProjectCodeTable)

	CProject_ProjectCodeTable();
	virtual ~CProject_ProjectCodeTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString parmname;
		static const CString parmvalue;

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

class PMLogicDataOprAPI CSysComParamsSetTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CSysComParamsSetTable)

	CSysComParamsSetTable();
	virtual ~CSysComParamsSetTable();

public:
	virtual int InitFieldStr();

public:
	struct PMLogicDataOprAPI CFieldInfo
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
		static const CString used_bz;

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
		static		 int	 used_bz_Index;

		/// idx �����ĸ�������
		/// idx ��Ҫ�ں��� InitFieldStr �� ����ʼ��Ϊ�������ֵ
		/// �Ҹ�ֵ��˳��Ӧ�ú� InitFieldStr����ӵ�˳��һ��
		static int idx_step ; 
	};

	struct PMLogicDataOprAPI CTableData 
	{
		static const CString table_name ;
		static const int cur_version ; 
	};

};



class PMLogicDataOprAPI CProject_VectorParmsTable : public CPM_StorageDataSet  
{
public:
	DECLARE_DYNCREATE(CProject_VectorParmsTable)

	CProject_VectorParmsTable();
	virtual ~CProject_VectorParmsTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString	parmid ;
		static int				parmid_Index;

		static const CString	vectorid ;
		static int				vectorid_Index;

		static const CString	parmmode ;
		static int				parmmode_Index;

		static const CString	datatype ;//1:�ֽ���Ϣ  2��������Ϣ
		static int				datatype_Index;

		static const CString	parmname ;
		static int				parmname_Index;

		static const CString	parmvalue ;
		static int				parmvalue_Index;

		static const CString	msgInfo;
		static int				msgInfo_Index;
	};

	virtual int InitFieldStr();

};

//////////////////////////////////////////////////////////////////////////
//
class PMLogicDataOprAPI CProject_QDDE_UITable : public NDbDataSet  
{
public:
	DECLARE_DYNCREATE(CProject_QDDE_UITable)

	/// �е�����
	enum RowType
	{
		eItem = 1 ,			/// ������Ŀ
		eQd = 2 ,			/// �嵥
		eSubItem = 3 ,		/// �嵥�µ�����Ŀ
		eDe = 4 			/// ����
	} ; 

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id ;
		static const CString ComType ;
		static const CString name ;
		static const CString subname ; /// ����Ŀ �� �嵥����Ŀ����
		static const CString DEID ;
		static const CString DEName ;
		static const CString DECode ;
		static const CString Unit ;
		static const CString Quantity ;
		static const CString Sections ;
		static const CString Formulas ;
		static const CString EditMode ;
		static const CString RationRow ;
		static const CString RowType ;   /// �е�����
		static const CString ItemCharacter ; 
		static const CString NodeID ; 
		static const CString Index_qdtable;//������嵥ComID ���ݿ� ����
//		static const CString Index_qdinfotable;//�����嵥��Ϣ ���ݿ� ����

		static int id_Index;
		static int ComType_Index ;
		static int name_Index ;
		static int subname_Index ; /// ����Ŀ �� �嵥����Ŀ����
		static int DEID_Index ;
		static int DEName_Index ;
		static int DECode_Index ;
		static int Unit_Index ;
		static int Quantity_Index ;
		static int Sections_Index ;
		static int Formulas_Index ;
		static int EditMode_Index ;
		static int RationRow_Index ;
		static int RowType_Index ;   /// �е�����
		static int ItemCharacter_Index ; 
		static int NodeID_Index ; 
		static int Index_qdtable_Index;
//		static int Index_qdinfotable_Index;
	};

	CProject_QDDE_UITable();
	virtual ~CProject_QDDE_UITable();
	virtual int InitFieldStr();

};


class PMLogicDataOprAPI CProject_VectorBuildInfoTable : public NDataModelDataSet  
{
public:
	DECLARE_DYNCREATE(CProject_VectorBuildInfoTable)
	CProject_VectorBuildInfoTable();
	virtual ~CProject_VectorBuildInfoTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id ;
		static const CString hzxx ;
		static const CString qdm ;
		static const CString zzm ;
		static const CString gd ;
		static const CString tgx ;
		static const CString dtbl ;
	};

	virtual int InitFieldStr() ;
};


struct PMLogicDataOprAPI CQDDE_JSGZ_Com
{
	static const CString id ;
	static int	id_Index;

	static const CString ParmID ;
	static int	ParmID_Index;

	static const CString ParmName ;
	static int	ParmName_Index;

	static const CString Value ;
	static int	Value_Index;

	static const CString DefValue ;
	static int	DefValue_Index;

	static const CString ListData ;
	static int	ListData_Index;

	static const CString IniType ;
	static int	IniType_Index;

	static const CString Desc ;
	static int	Desc_Index;

	static NDataModelDataSet * GetDataSet() ;
};

struct PMLogicDataOprAPI CQDDE_FJCC_Com
{
	static const CString id ;
	static int			id_Index;

	static const CString ComType ;
	static int			ComType_Index;

	static const CString parmdisplayname ;
	static int			parmdisplayname_Index;

	static const CString ParmValue ;
	static int			ParmValue_Index;

	static const CString ListData ;
	static int			ListData_Index;

	static const CString InputMode ;
	static int			InputMode_Index;

	static const CString CheckReg ;
	static int			CheckReg_Index;

	static NDataModelDataSet * GetDataSet() ;
};


class PMLogicDataOprAPI CProject_FloorTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_FloorTable)

	CProject_FloorTable();
	virtual ~CProject_FloorTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;							//¥���
		static const CString showid;						//����ʾ���
		static const CString lcmc;						//¥������
		static const CString lcxz;						//¥������
		static const CString cs;							//����
		static const CString cg;							//���(mm)
		static const CString ldmbg;						//¥������(mm)
		static const CString tqd;							//��ǿ��
		static const CString zdj;							//ש�ȼ�
		static const CString sjdj;						//ɰ���ȼ�
		static const CString filename;					//ͼ���ļ�����
		static const CString bz;							//��ע
		static const CString ztjzmj;						//���彨�����
		static const CString ytjzmj;						//��̨�������
		static const CString jss;							//���彨������ļ���ʽ
		static const CString bh;							//���(mm)
		static const CString dmj;							//���㽨�����(m2)

		static const CString table_name;					//����
	};

	virtual int InitFieldStr();
};


class PMLogicDataOprAPI CProject_ResultTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ResultTable)

	CProject_ResultTable();
	virtual ~CProject_ResultTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;							//����id
		static const CString comid;						//�������
		static const CString cadhandle;					//CADΨһ��ʶ���ַ���
		static const CString calitemid;					//��� QDData �� ��Ӧ�� id , �嵥�Ͷ���� ������ϵ ��������ֶ�
		static const CString calitemname;					//�����ʱ���� ������Ŀ����,�嵥��ʱ���� "�嵥" ������
		static const CString positions;					//��ƽ��ͼ�е�λ��
		static const CString topaxis;						//��
		static const CString buttonaxis;					//��
		static const CString rightaxis;					//��
		static const CString leftaxis;					//��
		static const CString rationrow;					//�����Ӧ�� Ration���ж�Ӧ�� �к�
		static const CString qddeid;						//�����ʱ���Ŷ������ ,�嵥��ʱ�����嵥ID .
		static const CString qddename;					//�����ʱ���Ŷ������� ,�嵥��ʱ�����嵥����.
		static const CString unit;						//��λ
		static const CString formula;						//���������㹫ʽ
		static const CString transformula;				//���������㹫ʽ(������ʾ)
		static const CString quantity;					//������
		static const CString mainmode;					//���� 1:�嵥  0:����
		static const CString fjhandle;					//����Handle
		static const CString gjmode;						//���������� 0������ 1����������
		static const CString nodeid ;
		static const CString calfloorid ;				/// �������ڵ�ʵ��¥��id, ��ʾ��㹹�����ڵ�ʵ��¥��
		static const CString CCInfo;//CC��Ϣ���� �� 2,3

		static const CString quantity_5D;					//������,5D��Ҫ�ĵ�������(��Ϊ��ͨ��,ÿ��������������,û�о���Aֵת����)

		/// һЩ�����Ķ��廹�Ƿ��ڸ����ж��壬��Ȼ�Ѿ������ڸñ�ṹ
		static const CString FloorID ;
		static const CString FloorShowID ;
		static const CString ComType ;
		static const CString ShowID ; 
		static const CString ComName ;
		

		static const CString table_name;

		static const int cur_version ; 
	};

	virtual int InitFieldStr();

public:
	/// 
	/// �ýӿ������������
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};


//ʵ����������Ҫ�Ķ���ֵ�洢
class PMLogicDataOprAPI CProject_SWLExtraValueTable  : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SWLExtraValueTable)

	CProject_SWLExtraValueTable();
	virtual ~CProject_SWLExtraValueTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;						//���
		static const CString cadhandle;				//�����ľ��
		static const CString comid;					//������id
		static const CString comtype;					//����������
		static const CString floorid;					//��������¥��
		static const CString parmname;			//������������
		static const CString parmvalue;			//��������ֵ
		static const CString parmenum;           //������Ӧ��ö��ֵ
		static const CString table_name;
	};

	virtual int InitFieldStr();
};


class PMLogicDataOprAPI CProject_SgdResultTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SgdResultTable)

	CProject_SgdResultTable();
	virtual ~CProject_SgdResultTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;							//����id
		static const CString comid;						//�������
		static const CString cadhandle;					//CADΨһ��ʶ���ַ���
		static const CString calitemid;					//��� QDData �� ��Ӧ�� id , �嵥�Ͷ���� ������ϵ ��������ֶ�
		static const CString calitemname;					//�����ʱ���� ������Ŀ����,�嵥��ʱ���� "�嵥" ������
		static const CString positions;					//��ƽ��ͼ�е�λ��
		static const CString topaxis;						//��
		static const CString buttonaxis;					//��
		static const CString rightaxis;					//��
		static const CString leftaxis;					//��
		static const CString rationrow;					//�����Ӧ�� Ration���ж�Ӧ�� �к�
		static const CString qddeid;						//�����ʱ���Ŷ������ ,�嵥��ʱ�����嵥ID .
		static const CString qddename;					//�����ʱ���Ŷ������� ,�嵥��ʱ�����嵥����.
		static const CString unit;						//��λ
		static const CString formula;						//���������㹫ʽ
		static const CString transformula;				//���������㹫ʽ(������ʾ)
		static const CString quantity;					//������
		static const CString mainmode;					//���� 1:�嵥  0:����
		static const CString fjhandle;					//����Handle
		static const CString gjmode;						//���������� 0������ 1����������
		static const CString nodeid ;
		static const CString worksegcomid;				// ʩ����comid
		static const CString calfloorid ;				/// �������ڵ�ʵ��¥��id, ��ʾ��㹹�����ڵ�ʵ��¥��
		static const CString CCInfo;//CC��Ϣ���� �� 2,3

		static const CString quantity_5D;					//������,5D��Ҫ�ĵ�������(��Ϊ��ͨ��,ÿ��������������,û�о���Aֵת����)

		/// һЩ�����Ķ��廹�Ƿ��ڸ����ж��壬��Ȼ�Ѿ������ڸñ�ṹ
		static const CString FloorID ;
		static const CString FloorShowID ;
		static const CString ComType ;
		static const CString ShowID ; 
		static const CString ComName ;


		static const CString table_name;

		static const int cur_version ; 
	};

	virtual int InitFieldStr();

public:
	/// 
	/// �ýӿ������������
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};


class PMLogicDataOprAPI CProject_RoomTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_RoomTable)

	CProject_RoomTable();
	virtual ~CProject_RoomTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;				//�ñ���߼�ID,����.
		static const CString fjcomid;			//����ComID
		static const CString fjhandle;		//����ComID
		static const CString fjname;			//��������
		static const CString fjposition;		//����λ��
		static const CString floorid;			//¥��ID
		static const CString floorshowid;		//¥������ID
		static const CString nqmcomid;		//��ǽ��  ------����
		static const CString nqmhandle;		//��ǽ��Handle--����
		static const CString zmcomid;		//����  ------����
		static const CString zmhandle;		//����Handle--����
		static const CString ldmcomid;		//¥����
		static const CString ldmhandle;
		static const CString tpcomid;			//����
		static const CString tphandle;

		static const CString table_name;

		static const int cur_version ;
	};

	virtual int InitFieldStr();

public:
	/// 
	/// �ýӿ������������
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};


class PMLogicDataOprAPI CProject_GJJMInfoTable  : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_GJJMInfoTable)

	CProject_GJJMInfoTable();
	virtual ~CProject_GJJMInfoTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;						//���
		static const CString cadhandle;				//�����ľ��
		static const CString comid;					//������id
		static const CString comtype;					//����������
		static const CString floorid;					//��������¥��
		static const CString pathlength;				//�����Ļ��Ƴ���
		static const CString jminfo;					//�����Ľ�����Ϣ (B*H)
		static const CString jmarea;					//�����Ľ������
		static const CString width;					//�����ĺ��
		static const CString dingbg;					//�����Ķ����
		static const CString dibg;					//�����ĵױ��
		static const CString jmb;						//�����
		static const CString jmh;						//�����
		static const CString jmgirth;					//�����ܳ�
		static const CString pmxz;					//ƽ����״ 1 ���� 0 ֱ��
		static const CString extend;					//��չ��Ϣ ��ʽΪ : ��־|ֵ; ��־:1 б��, 2 �������, 3 ������ , 4 ������� , 5 ǽ�����

		static const CString table_name;
	};

	virtual int InitFieldStr();
};


class PMLogicDataOprAPI CProject_ParmValueTable : public CPM_StorageDataSet
{
public:
	DECLARE_DYNCREATE(CProject_ParmValueTable)

	CProject_ParmValueTable();
	virtual ~CProject_ParmValueTable();

	struct  PMLogicDataOprAPI CFieldInfo
	{
		static const CString SubComType;
		static		int		SubComType_Index;

		static const CString ParmName ;
		static		int		ParmName_Index;

		static const CString ParmValue ;
		static		int		ParmValue_Index;

		static const CString InvalidMsg;
		static		int		InvalidMsg_Index;
	};

	virtual int InitFieldStr();
};


class PMLogicDataOprAPI CProject_SwlResultTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SwlResultTable)

	CProject_SwlResultTable();
	virtual ~CProject_SwlResultTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;							//����id
		static const CString comid;						//�������
		static const CString cadhandle;					//CADΨһ��ʶ���ַ���
		static const CString calitemid;					//��� QDData �� ��Ӧ�� id , �嵥�Ͷ���� ������ϵ ��������ֶ�
		static const CString calitemname;					//�����ʱ���� ������Ŀ����,�嵥��ʱ���� "�嵥" ������
		static const CString positions;					//��ƽ��ͼ�е�λ��
		static const CString topaxis;						//��
		static const CString buttonaxis;					//��
		static const CString rightaxis;					//��
		static const CString leftaxis;					//��
		static const CString rationrow;					//�����Ӧ�� Ration���ж�Ӧ�� �к�
		static const CString qddeid;						//�����ʱ���Ŷ������ ,�嵥��ʱ�����嵥ID .
		static const CString qddename;					//�����ʱ���Ŷ������� ,�嵥��ʱ�����嵥����.
		static const CString unit;						//��λ
		static const CString formula;						//���������㹫ʽ
		static const CString transformula;				//���������㹫ʽ(������ʾ)
		static const CString quantity;					//������
		static const CString mainmode;					//���� 1:�嵥  0:����
		static const CString fjhandle;					//����Handle
		static const CString gjmode;						//���������� 0������ 1����������
		static const CString nodeid ;
		static const CString calfloorid ;
		static const CString CCInfo;//CC��Ϣ���� �� 2,3

		static const CString quantity_5D;					//������,5D��Ҫ�ĵ�������(��Ϊ��ͨ��,ÿ��������������,û�о���Aֵת����)

		/// һЩ�����Ķ��廹�Ƿ��ڸ����ж��壬��Ȼ�Ѿ������ڸñ�ṹ
		static const CString FloorID ;
		static const CString FloorShowID ;
		static const CString ComType ;
		static const CString ShowID ; 
		static const CString ComName ;

		static const CString table_name;

		static const int cur_version ; 
	};

	virtual int InitFieldStr();

public:
	/// 
	/// �ýӿ������������
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};

class PMLogicDataOprAPI CProject_SgdSwlResultTable: public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SgdSwlResultTable)

	CProject_SgdSwlResultTable();
	virtual ~CProject_SgdSwlResultTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;							//����id
		static const CString comid;						//�������
		static const CString cadhandle;					//CADΨһ��ʶ���ַ���
		static const CString calitemid;					//��� QDData �� ��Ӧ�� id , �嵥�Ͷ���� ������ϵ ��������ֶ�
		static const CString calitemname;					//�����ʱ���� ������Ŀ����,�嵥��ʱ���� "�嵥" ������
		static const CString positions;					//��ƽ��ͼ�е�λ��
		static const CString topaxis;						//��
		static const CString buttonaxis;					//��
		static const CString rightaxis;					//��
		static const CString leftaxis;					//��
		static const CString rationrow;					//�����Ӧ�� Ration���ж�Ӧ�� �к�
		static const CString qddeid;						//�����ʱ���Ŷ������ ,�嵥��ʱ�����嵥ID .
		static const CString qddename;					//�����ʱ���Ŷ������� ,�嵥��ʱ�����嵥����.
		static const CString unit;						//��λ
		static const CString formula;						//���������㹫ʽ
		static const CString transformula;				//���������㹫ʽ(������ʾ)
		static const CString quantity;					//������
		static const CString mainmode;					//���� 1:�嵥  0:����
		static const CString fjhandle;					//����Handle
		static const CString gjmode;						//���������� 0������ 1����������
		static const CString nodeid ;
		static const CString worksegcomid;					// ʩ����comid
		static const CString calfloorid ;
		static const CString CCInfo;//CC��Ϣ���� �� 2,3

		static const CString quantity_5D;					//������,5D��Ҫ�ĵ�������(��Ϊ��ͨ��,ÿ��������������,û�о���Aֵת����)


		/// һЩ�����Ķ��廹�Ƿ��ڸ����ж��壬��Ȼ�Ѿ������ڸñ�ṹ
		static const CString FloorID ;
		static const CString FloorShowID ;
		static const CString ComType ;
		static const CString ShowID ; 
		static const CString ComName ;

		static const CString table_name;

		static const int cur_version ; 
	};

	virtual int InitFieldStr();

public:
	/// 
	/// �ýӿ������������
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};

class PMLogicDataOprAPI CProject_SwlRoomTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SwlRoomTable)

	CProject_SwlRoomTable();
	virtual ~CProject_SwlRoomTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;				//�ñ���߼�ID,����.
		static const CString fjcomid;			//����ComID
		static const CString fjhandle;		//����ComID
		static const CString fjname;			//��������
		static const CString fjposition;		//����λ��
		static const CString floorid;			//¥��ID
		static const CString floorshowid;		//¥������ID
		static const CString nqmcomid;		//��ǽ��  ------����
		static const CString nqmhandle;		//��ǽ��Handle--����
		static const CString ldmcomid;		//¥����
		static const CString ldmhandle;
		static const CString tpcomid;			//����
		static const CString tphandle;

		static const CString table_name;

		static const int cur_version ; 
	};

	virtual int InitFieldStr();

public:
	/// 
	/// �ýӿ������������
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};


class PMLogicDataOprAPI CProject_SwlGJJMInfoTable  : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_SwlGJJMInfoTable)

	CProject_SwlGJJMInfoTable();
	virtual ~CProject_SwlGJJMInfoTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;						//���
		static const CString cadhandle;				//�����ľ��
		static const CString comid;					//������id
		static const CString comtype;					//����������
		static const CString floorid;					//��������¥��
		static const CString pathlength;				//�����Ļ��Ƴ���
		static const CString jminfo;					//�����Ľ�����Ϣ (B*H)
		static const CString jmarea;					//�����Ľ������
		static const CString width;					//�����ĺ��
		static const CString dingbg;					//�����Ķ����
		static const CString dibg;					//�����ĵױ��
		static const CString jmb;						//�����
		static const CString jmh;						//�����
		static const CString jmgirth;					//�����ܳ�
		static const CString pmxz;					//ƽ����״ 1 ���� 0 ֱ��
		static const CString extend;					//��չ��Ϣ ��ʽΪ : ��־|ֵ; ��־:1 б��, 2 �������, 3 ������ , 4 ������� , 5 ǽ�����

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

/**
 * @brief  :ʵ��������ά�������õ�dataset
 *
 *          
 * @author :zfy
 * @version:v1.0
 * @date   :[9/5/2017]
 * @note   :
 */
class PMLogicDataOprAPI CSwljsRulesTable  : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CSwljsRulesTable)

	CSwljsRulesTable();
	virtual ~CSwljsRulesTable();

	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString id;						//���
		static const CString parmid;					//ʵ����������� �� parmid
		static const CString name;						//����
		static const CString unit;						//��λ
		static const CString quantity;					//���㷽����������Ŀ���ۼ���Ŀ
		static const CString sections;					//�����ߴ�
		static const CString formulas;					//�Զ���ļ��㹫ʽ
		static const CString isOutput;					//�Ƿ����
		static const CString editmode;					//
		static const CString defaultValue;				//
		static const CString sortid;

		static const CString table_name;
	};

	virtual int InitFieldStr();
};

struct PMLogicDataOprAPI CDE_SWL_Com
{
	static const CString id ;
	static int	id_Index;

	static const CString ParmID ;
	static int	ParmID_Index;

	static const CString ParmName ;
	static int	ParmName_Index;

	static const CString OutPut;
	static int  OutPut_Index;

	static const CString Value ;
	static int	Value_Index;

	static const CString DefValue ;
	static int	DefValue_Index;

	static const CString ListData ;
	static int	ListData_Index;

	static const CString IniType ;
	static int	IniType_Index;

	static const CString Desc ;
	static int	Desc_Index;

	static NDataModelDataSet * GetDataSet() ;
};
 
 
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 /// �ֽ������
 class PMLogicDataOprAPI CProject_GraphicsResultTable: public CSQLDataSet
 {
 public:
 	DECLARE_DYNCREATE(CProject_GraphicsResultTable)
 
 	CProject_GraphicsResultTable();
 	virtual ~CProject_GraphicsResultTable();
 
 	struct PMLogicDataOprAPI CFieldInfo
 	{
 		static const CString id;					//�ñ���߼�id
 		static const CString floorid;				//¥��
 		static const CString comid;				//����
 		static const CString cadhandle;			//cad���
 		static const CString positions;			//��ƽ��ͼ�е�λ��
 		static const CString topaxis;				//��
 		static const CString buttonaxis;			//��
 		static const CString rightaxis;			//��
 		static const CString leftaxis;			//��
 		static const CString gjlb;				//�ֽ����
 		static const CString gjlx;				//�ֽ�����
 		static const CString gjjb;				//�ֽ��
 		static const CString zj;					//ֱ��
 		static const CString gs;					//����
 		static const CString th;					//ͼ��
 		static const CString jt;					//��ͼ
 		static const CString jsgs;				//���㹫ʽ
 		static const CString wg;					//�乴
 		static const CString tqd;					//��ǿ��
 		static const CString dj;					//���
 		static const CString cd;					//����
 		static const CString jtgs;				//��ͷ����
 		static const CString zz;					//����
 		static const CString gsms;				//��ʽ����
 		static const CString index0;				
 		static const CString index1;				
 		static const CString index2;				
 		static const CString jtparms;				//��ͼ����
 		static const CString sttype;				//�ֽ���� Ĭ��0ʱΪ�������ã�1ʱΪ�ֹ�����
 		static const CString jtformula;			//��ͼ���㹫ʽ
 		static const CString resulttype;			
 		static const CString djxs;				
 		static const CString errortype;			
 		static const CString cc;				
 		static const CString ccamount;		
 		static const CString jtdrawbuffer;
 		static const CString mtgs ;
 		static const CString mtxs ; 
 
 		static const CString table_name;			//�ֽ��������
 	};
 
 	virtual int InitFieldStr();
 
 public:
 	struct PMLogicDataOprAPI CTableData 
 	{
 		static const int cur_version ; 
 	};
 
 	/// 
 	/// �ýӿ������������
 	/// 
 	int		InitFieldStr( const int iVersion ) ; 
 };

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
class PMLogicDataOprAPI CProject_GraphicsResultV2Table : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_GraphicsResultV2Table)
public:
	CProject_GraphicsResultV2Table() ; 
	virtual ~CProject_GraphicsResultV2Table() ;

public:
	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString showindex ;		// ��ʾ��˳��
												//�ڽ������ʾ�����ڱ�������ʾ������������ֶ�

		static const CString id;				//�ñ���߼�id
		static const CString comid;				//����
		static const CString floorid ;			//¥��id
		static const CString cadhandle;			//cad���
		static const CString positions;			//��ƽ��ͼ�е�λ��
		static const CString gjlb;				//�ֽ����� 
		static const CString gjlx;				//�ֽ�����
		static const CString gjjb;				//�ֽ��
		static const CString zj;				//ֱ��
		static const CString gs;				//����
		static const CString th;				//ͼ��		
		static const CString wg;				//�乴
		static const CString dj;				//���
		static const CString djxs;				//�����ʽ
		static const CString jtgs;				//��ͷ����
		static const CString cd;				//����
		static const CString zz;				//����
		static const CString jsgs;				//���㹫ʽ	--- ���ȵ���������
		static const CString gsms;				//��ʽ���� --- ���ȵĹ�˾����
		static const CString count_des ;		//�����Ĺ�ʽ���� --- ��������
		static const CString sttype;			//�ֽ���� Ĭ��0ʱΪ�������ã�1ʱΪ�ֹ�����
		static const CString resulttype;		//�����������࣬ �����������		
		static const CString errortype;			//�������д�����Ҫ�����ʺ�	
		static const CString cc;				//¥��Ĳ���
		static const CString cc_count;			//¥��Ĳ���
		static const CString jtdrawbuffer;		//��ͼ��Ϣ����3ά��Ϣ
		static const CString tzz;				//�ֽ�����ߵȼ��㷽ʽ�����ĵ���ֵ

		/// 
		/// êͷ������êͷ��ʽ��
		/// �������������ʱ����Ҫ
		/// 
		static const CString mtgs ;				//
		static const CString mtxs ;				//

		static const CString table_name;			//�ֽ��������
	};

public:
	virtual int InitFieldStr();

public:
	struct PMLogicDataOprAPI CTableData 
	{
		static const int cur_version ; 
	};

	/// 
	/// �ýӿ������������
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};

class PMLogicDataOprAPI CProject_TtymjResultTable : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CProject_TtymjResultTable)
public:
	CProject_TtymjResultTable() ; 
	virtual ~CProject_TtymjResultTable() ;

public:
	struct PMLogicDataOprAPI CFieldInfo
	{
		static const CString showindex ;		// ��ʾ��˳��
		//�ڽ������ʾ�����ڱ�������ʾ������������ֶ�

		static const CString id;				//�ñ���߼�id
		static const CString comid;				//����
		static const CString floorid ;			//¥��id
		static const CString cadhandle;			//cad���
		static const CString comtype;			//comtype
		static const CString bh;				//���
		static const CString lb;				//���
		static const CString gnmc;				//��������
		static const CString sl;				//����
		static const CString zj;				//ֱ��
		static const CString gg;				//���		
		static const CString bz;				//��ע
		static const CString table_name;		//��ͲԤ��������
	};

public:
	virtual int InitFieldStr();

public:
	struct PMLogicDataOprAPI CTableData 
	{
		static const int cur_version ; 
	};

	/// 
	/// �ýӿ������������
	/// 
	int		InitFieldStr( const int iVersion ) ; 
};
/// 
struct PMLogicDataOprAPI CComParmsSet_ParmName
{
	static const int Unkown_ParmType;
	static const int Globel_ParmType;	/// ȫ�ֵĲ��� (�ڹ������������õ�,��ͼ�η��͹������ж���Ҫ�����Բ���)
	static const int SL_ParmType;		/// �����Ĳ���(��������ͼ�η��ֽ��ж���Ҫ����Ҫ�е����Բ���)
	static const int GJ_ParmType;		/// �ֽ�Ĳ���( �ڸֽ��в���Ҫ�����Բ��� )
	static const int GJ_JSSZ_ParmType;	/// �ֽ�������õĲ��� (�ֽ��в���Ҫ)
	static const int SL_ParmType_OL ;   /// �����Ĳ��� ( ֻ���������в��е� ���Բ��� )
	static const int Vector_ParmType;

	static const CString d_length;
	static const CString H_length;
	static const CString ZDCDJ;
	static const CString ZDCMG;
	static const CString bfl;
	static const CString KZDJ;
	static const CString DJ1;
	static const CString DJB1 ;
	static const CString DJ2;
	static const CString DJB2 ;
	static const CString DJ3;
	static const CString DJB3 ;
	static const CString DJ4;
	static const CString DJB4;
	static const CString DJ5;
	static const CString DJ6;
	static const CString DJ7;
	static const CString MG1;
	static const CString MGB1 ;
	static const CString MG2;
	static const CString MGB2 ;
	static const CString MG3;
	static const CString MGB3 ;
	static const CString MG4;
	static const CString MGB4;
	static const CString MG5;
	static const CString MG6;
	static const CString MG7;
	static const CString ZJWG;
	static const CString DJXS;
	static const CString GJWG;
	static const CString GJTZZ;//�ֽ����ֵ
	static const CString GJJSFS;//�ֽ���㷽ʽ
	static const CString GJZS;
	static const CString wgjd;
	static const CString TQD;
	static const CString JCTQD;//������ǿ��
	static const CString DCTQD;//�����ǿ��
	static const CString GJLX;
	static const CString bhc;
	static const CString def1jt;
	static const CString GJ_rule;
	static const CString GJJSGZ;
	static const CString GJJSSZ_UI;
	static const CString kwgjd;

	static const CString component;

	static const CString componenttype;
	static const CString jm;
	static const CString loss_coefficient;//�����

	static const CString Length;	//��
	static const CString Width;		//��
	static const CString Height;	//��
	static const CString JMBian;	//������
	static const CString JMBianOrder;	//����߻���˳��

	static const CString Topbg;//�����
	static const CString Bottombg;//�ױ��

	static const CString VectorID;	//����ͼID 
	static const CString VectorID_Gj; //�ֽ����ͼID 

	static const CString JMMS;		//��������
	static const CString GJYS;		//������ɫ

	static const CString GJMS;      //qc:29805 �����ֽ�����
};

/**
* @brief ������ֻ��࣬���ڽ����Ӳ��� ��ֳɵ�һ���ݷ��㴦��  
*
*          
* @note  : Ŀǰ��ֻ��ΪCCalComParmsInfo ��parmvalue���в�ַ���
* @param : 
* @defenc: 
* @return: 
* @author: ����ҵ
* @date  : [8/1/2014]
*/
class PMLogicDataOprAPI CComParmSplitBase
{
public:
	CComParmSplitBase(){};
	virtual ~CComParmSplitBase(){};

	/**
	* @brief �ⲿ���ʲ����� ͳһ�ӿ�  
	*
	*          
	* @note  : 
	* @param : const CString & strParmName����������
				const CParmInfoBase *& pTemValueBase��������ֺ�Ľ��������ά������ָ��
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [8/1/2014]
	*/
	virtual BOOL GetComParmInfo(const CString & strParmName,const CParmInfoBase *& pTemValueBase) = 0;

protected:

	/**
	* @brief �ڻ�ȡ����������£�û�в�����ݣ�ʹ�ýӿڽ��в�ִ���  
	*
	*          
	* @note  : 
	* @param : const CString & strParmName:��������
				const CString & strParmValue������ֵ
				CParmInfoBase *& pTemValueBase��������ֺ�Ľ�����ⲿ��Ҫά�����ص��ڴ�
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [8/1/2014]
	*/
	virtual BOOL DoSplitComParm(const CString & strParmName,const CString & strParmValue,CParmInfoBase *& pTemValueBase) = 0;
};

class PMLogicDataOprAPI CComParmsInfoMap
{
public:

	CComParmsInfoMap();
	virtual ~CComParmsInfoMap();

	class PMLogicDataOprAPI CCalComParmsInfo
	{
	public:
		friend CComParmSplitBase;

		CCalComParmsInfo();
		virtual ~CCalComParmsInfo();

		void SetParmName(const CString & strParmName);
		CString GetParmName();

		void SetParmValue(const CString & strParmValue);
		CString GetParmValue();

		void SetInvalidMsg(const CString & strInvalidMsg);
		CString GetInvalidMsg();

		BOOL SerializeFrom(const CPmArchiveBase & archive);
		BOOL SerializeTo(CPmArchiveBase & archive) const;

		/// 
		CParmInfoBase * GetParmInfoBase();
		void SetParmInfoBase(CParmInfoBase * pTemParmInfoBase);

		/// 
		void	ReleaseParmInfoBase() ; 

	protected:
		CString m_strParmName;
		CString m_strParmValue;
		CString m_strInvalidMsg;
		CParmInfoBase * m_pParmValueBase;
	};

	void	AddSortParmName( const CString & strParmName ) ;

	BOOL	HasParm( const CString & strParmName ) ; 

	BOOL AddComParmInfo(const CString & strName,CCalComParmsInfo * pComParmsInfo);
	BOOL GetComParmValue(const CString & strName,CString & strParmValue) const ;
	// qc:28671 ��ȡInvalidmsgֵ
	BOOL GetInvalidmsgValue(const CString & strName,CString & strInvalidmsgValue) const ;
	BOOL GetComParmInv(const CString & strName,CString & strParmValue) const ;
	CCalComParmsInfo * GetComParmInfo(const CString & strName) const ;

	/// 
	void	ReleaseParmInfoBase() ; 

	void	ReleaseParmInfoBase( const CString & strParmName ) ; 

	const CMapStringToPtr * GetMapPtr() const;

	BOOL SerializeFrom(const CPmArchiveBase & archive);
	BOOL SerializeTo(CPmArchiveBase & archive) const;

protected:

	CMapStringToPtr m_ComParmNameMap;

	/// 
	/// �ֽ���������,�ֽ������Ҫ�õ�.
	/// 
	PmStrList	m_listSortParmName ;

};

typedef CArray<CComParmsInfoMap::CCalComParmsInfo*,CComParmsInfoMap::CCalComParmsInfo*&>	CCalComParmsInfoArr;

struct PMLogicDataOprAPI CVariables 
{
	const static CString  A ;
	const static CString  L ;
	const static CString  W ;
	const static CString  D ;
	const static CString  H ;
	const static CString  S ;
	const static CString  Lq ;
	const static CString  ZTMLen;
	const static CString  Ln ;
};

namespace Graphic_ComType
{
	//��������
	enum eGjType_T
	{
		eError = -1,//����
		eLiang = 1,//��	
		ePole = 2,	//��
		eWall = 3,//ǽ
		eBan = 4,//��
		eJc = 5,//����
		eMcd = 6, //�Ŵ���
		eZs = 7,//װ��
		eLsgj = 8,//���ǹ���
		eOther = 9,//��������
	};

	enum ComType
	{
		Error = 0, // ������

		/***** ��ϵ�� *****/
		LIANG = 100, 
		LIANG_KL = 101,		//�����
		LIANG_CL = 102,		//����
		LIANG_DL = 103,		//������
		LIANG_JCL = 104,	//������
		LIANG_QL = 105,		//Ȧ��
		LIANG_GL = 106,		//����
		LIANG_JCLL = 107,	//��������
		LIANG_CTL = 108,	//��̨��
		LIANG_DJ = 109,		//����
		LIANG_ZZJ = 110,	//ת�ǽ�
		LIANG_LL  = 111,	//����
		LIANG_AL  = 112,	//����
		LIANG_DKL  = 113,	//�ؿ���
		LIANG_JCLJY = 114,	//��������Ҹ
		LIANG_BLH = 116,	//����������

		/***** ��ϵ�� *****/
		ZHU = 200,
		ZHU_KZ = 201,		//����
		ZHU_GZ = 202,		//������
		ZHU_AZ = 203,		//����
		ZHU_ZZ = 204,		//ש��
		ZHU_ZM = 205 ,		//��ñ

		/***** ǽϵ�� *****/
		QIANG = 300,
		QIANG_0Q  = 301,	//0ǽ
		QIANG_TWQ = 302,	//����ǽ
		QIANG_TNQ = 303,	//����ǽ
		QIANG_ZWQ = 304,	//ש��ǽ
		QIANG_ZNQ = 305,	//ש��ǽ
		QIANG_TCQ = 306,	//���ǽ
		QIANG_JBQ = 307,	//���ǽ
		QIANG_DTQ = 308,	//���ݾ�ǽ
		QIANG_MQ  = 309,	//Ļǽ
		QIANG_QTJJ= 312,	//����ӽ�
		QIANG_JLQ = 313,	//����ǽ
		QIANG_QTQ = 314,	//����ǽ

		QIANG_WQWBX = 315 , /// ��ǽ�����
		QIANG_MP	= 316 , /// ����
		QIANG_RFQ	= 317, //�˷�ǽ
		QIANG_JIAYE_QQ = 318,	//ǽǽ��Ҹ
		QIANG_JIAYE_QB = 319,	//ǽ���Ҹ
		QIANG_QTLJ = 320,		//��������

		/***** ��ϵ�� *****/
		BAN = 400,
		BAN_XB = 401,		//�ֽ���
		BAN_YB = 402,		//Ԥ�ư�
		BAN_LTB = 403,		//¥��
		BAN_GB = 404,		//���ΰ�
		BAN_QB = 405,		//���ΰ�
		BAN_LXB = 406,		//������
		BAN_BDONG = 407,	//�嶴
		BAN_TB = 408,		//�ݰ�
		BAN_WJX = 409,		//�ݼ���
		BAN_JIAYE = 410,	//�����Ҹ
		BAN_DONG = 1002,	//�嶴

		/***** ����ϵ�� *****/
		JICHU = 500,
		JICHU_TTJ = 501,	//������
		JICHU_ZSJ = 502,	//שʯ����
		JICHU_DLJ = 503,	//��������
		JICHU_CT = 504,		//��̨
		JICHU_RGZJ = 505,	//�˹��ڿ׹�ע׮
		JICHU_QTZJ = 506,	//����׮
		JICHU_MTJ = 507,	//���û���
		JICHU_JSJ = 508,	//��ˮ��
		JICHU_BZCT = 509,	//��׼��̨
		JICHU_JK = 510,		//����
		JICHU_STJSJ = 511,	//ʵ�弯ˮ��
		JICHU_ZD = 512,		//����
		JICHU_GZZJ = 513,	//��ע׮

		/***** �Ŵ�ϵ�� *****/	
		MC = 600,
		MC_M = 601,			//��
		MC_C = 602,			//��
		MC_D = 603,			//ǽ��
		MC_PC = 604,		//Ʈ��
		MC_ZPC = 605,		//ת��Ʈ��
		MC_LHC = 606,		//�ϻ���
		MC_BK = 607,		//����
		MC_CTB = 608,		//��̨
		MC_MD = 609 ,		// �Ŷ�
		MC_MCT = 610 ,		// �Ŵ���
		MC_PCD = 1004,		//Ʈ����
		MC_ZJPCD = 1005,	//ת��Ʈ����

		/***** װ��ϵ�� *****/
		ZS = 700,
		ZS_FJS = 701,		//����
		ZS_DMS = 702,		//¥����
		ZS_TJS = 703,		//�߽���
		ZS_NQS = 704,		//��ǽ��
		ZS_WQS = 705,		//��ǽ��
		ZS_QQS = 706,		//ǽȹ
		ZS_ZMS = 707,		//����
		ZS_ZQQS = 708,		//��ǽȹ
		ZS_ZTJS = 709,		//���߽�
		ZS_TPS = 710,		//����
		ZS_WMS = 711,		//����
		ZS_WMS_LKX = 1003,  //�����ֿ�����
		ZS_BWS = 712,		//���²�
		ZS_DLZS = 713 ,		// ����װ��
		ZS_DDS = 714,		//����

		/***** ����ϵ�� *****/
		LX = 800,
		LX_YT = 801,	    //��̨
		LX_YP = 802,		//����
		LX_LG = 803,		//����
		LX_SSLX = 804,		//ɢˮ
		LX_YG = 805,		//�ܹ�
		LX_TJ = 806,		//̨��
		LX_PD = 807,		//�µ�
		LX_PSG = 808,		//��ˮ��
		LX_HJD = 809,		//�󽽴�
		LX_TJING = 810,		//�쾮
		LX_JD = 811,		//��ǽ�ڵ�
		LX_AREA = 812,		//�������
		LX_YaDing = 813 ,	//ѹ��
		LX_LanBan = 814 ,		//����
		LX_YTYPZS = 815 ,   //��̨������ʵ
		LX_STTJ	= 816,		//ʵ��̨��
		LX_STPD = 817,		//ʵ���µ�
		LX_SGD = 818,      //ʩ����
		LX_FK = 819,		//��������

		/***** ����ϵ�� *****/
		QT = 900,
		QT_DST = 901,		//�㹹��
		QT_XST = 902,		//�߹���
		QT_MST = 903,		//�湹��
		QT_TST = 904,		//�幹��

		OTHER = 1000,			//��������
		OTHER_ZW = 1001,		//����
		OTHER_GCSZ = 1002,		//��������
		OTHER_BB = 1003,		//����
		OTHER_CADZH = 1004,		//CADת��
		OTHER_SCLX = 1005,		//�ղ�����---���ڵ��������ղ����ͽڵ�
		OTHER_LIANGZZ = 1015 ,	//֧����comtype��ֻ���ڸֽ�����ʱ��ʹ��
		/***** ���ϵ�� *****/
		BANJIN = 1100,
		BANJIN_DJ = 1101,		//�׽�
		BANJIN_MJ = 1102,		//���
		BANJIN_ZBSLJ = 1103,	//��帺��
		BANJIN_SCSXGJ = 1104,	//˫��˫��ֽ�
		BANJIN_ZZFJ = 1105,		//֧������
		BANJIN_WDJ = 1106,		//�¶Ƚ�
		BANJIN_LCBD = 1107,		//¥����:���а�������ϰ��
		BANJIN_CJ = 1108,		//�Ž�
		BANJIN_BJQY = 1109,		//�������
		BANJIN_FSJ = 1110 ,		//�����

		/***** ����ϵ�� *****/
		FABANJIN = 1200,
		FABANJIN_FDJ = 1201,	//����׽�
		FABANJIN_FMJ = 1202,	//�������
		FABANJIN_FZBSLJ = 1203, //�緤���
		FABANJIN_ZJCJ = 1204,	//�в��
		FABANJIN_ZZGJ = 1205,	//���帺��
		FABANJIN_FBJ = 1206,	//U�η�߽�
		FABANJIN_JCBD = 1207,	//�������: ���а�������ϰ��
		FABANJIN_CJ = 1208,		//�Ž�
		FABANJIN_BJQY = 1209,	//���������
		FABANJIN_FSJ = 1210	,	//��������

		//
		TUFAN = 1300 ,			// ����
		TUFAN_DKW = 1301 ,		// ����
		TUFAN_DXSFW = 1302 ,	// �����ҷ�Χ
		TUFAN_FXHTT = 1303,		// ���Ļ�����
		
		//����¥��
		KXLG = 1400,			//����¥��
		KXLG_BAN = 1401,		//����¥�ǰ�
		KXLG_ZM = 1402,			//����¥����ñ
		KXLG_ZLL = 1403,		//������
		KXLG_CLL = 1404,		//������
		KXLG_XM = 1405,			//оģ
		KXLG_KD = 1406,			//�յ�
		KXLG_SLJ = 1407,		//����¥��������

		//װ��ʽ
		ZPS = 1500,
		ZPS_YZZ = 1501,			//Ԥ����
		ZPS_YZWQ = 1502,		//Ԥ����ǽ
		ZPS_YZNQ = 1503,		//Ԥ����ǽ
		ZPS_DHL = 1504,			//������
		ZPS_HJL = 1505,			//����
		ZPS_DHB = 1506,			//���ϰ�
		ZPS_HJB = 1507,			//�󽽰�
		ZPS_JF = 1508,			//���
		ZPS_DHBMJ = 1509,		//���ϰ����
		ZPS_KDHBJ = 1510,		//����ϰ��
		ZPS_DHBFJ = 1511,		//���ϰ帺��

		BIMSAFE_3D_MB = 5110,	//���
		BIMSAFE_3D_XL = 5111,	//С��
		BIMSAFE_3D_ZL = 5112,	//����
		BIMSAFE_3D_KOUJIAN = 5113,	//�ۼ�

		BIMSAFT_PQBZ = 5201,	//������ʵ��
		BIMSAFT_KXPQ = 5202,	//��ѡ����ʵ��
		BIMSAFT_BDBH = 5203,   //�嶴���ͼ
		BIMSAFT_QDBH = 5204,   //ǽ�����ͼ
		BIMSAFT_BDBG = 5205,   //�嶥���
	};
	
	/**
	* @brief   ��������comtype���ж�
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/1/2020]
	*/
	PMLogicDataOprAPI BOOL IsJichuComtype(int comtype);

	/**
	* @brief   ��ȡ����comtype
	*
	*			���ǰѻ������������������ؿ�������������Ҹ��Ϊ����
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/1/2020]
	*/
	PMLogicDataOprAPI int GetComtypeDL(int comtype);
};

//ʵ�����������
namespace SWL_EV
{
	enum SWL_EV_Name{
		JMCC = 1,						//����ߴ�(mm*mm)
		ZC=2,							//�ܳ�(m)
		GD=3,							//�߶�(m)
		JMMJ=4,						//�������(m2)
		GJMC=5,						//��������
		ISBJM=6,						//�Ƿ�����
		ZSGX=7,							//װ�ΰ󶨹�ϵ, ����comId�ַ�����ʽ
		QMJCCL=8,							//ǽ��������ϣ��ַ�����ʽ
		SWLBB = 9					//ʵ��������
	};
}

namespace DrawBar_UI
{

}

namespace GJ_ComType
{
	// Note: Comtype���������򣺷������֣���_��ǰΪ��Ӧö���μ�д,
	//		 ��Ϊͨ����Ӧ�Ĺ�������������ƴ���ĵ�һ����ĸ��������������;  
	// Date: [5/6/2008]
	//��������
	enum eLIANG
	{	
		eLiang = 100, 
		eLKJ    = 110,
		eL_lckjl  = 111,					// ¥������ 
		eL_wmkjl  = 112,					// ��������
		eL_kzl    = 113,					// ��֧��	
		eL_kjlzl  = 114,					// ���������	
		eL_hxkjl  = 115,					// ���ο����	
		eL_gxkjl  = 116,					// ���ο����				
		eLFKJ   = 120,
		eL_cl	  = 121,					// ����
		eL_hxfkjl = 122,					// ���ηǿ����
		eL_gxfkjl = 123,					// ���ηǿ����
		eL_fkjlzl = 124,					// �ǿ��������
		eL_jzl    = 125,					// ������
		eLJC    = 130,
		eL_jczl   = 131,					// ��������	
		eL_jccl	  = 132,					// ��������
		eL_jcjyl  = 133,					// ��������Ҹ
		eL_jcdkl  = 134,					// �ؿ���
		eLOTH   = 140,
		eL_ql	  = 141,					// Ȧ��
		eL_gl	  = 142,					// ����
		eL_ctl	  = 143,					// ��̨��
		eL_jcll   = 144,					// ��������
		eL_dj	  = 145,					//����
		eL_zzj	  = 146,					//ת�ǽ�
		eL_ll_g	  = 147,					//������ͼ�η���
		eL_al_g	  = 148,					//������ͼ�η���

		eL_ql_KJJG = 151,					//��ܽṹ
		eL_ql_ZHJG = 152,					//ש��ṹ

		eL_KBLIANG = 155,					//�����
		eL_TZZHLIANG = 156,					//����ת����
		eL_KJLLIANG = 157,					//�������
		eL_ZLL_KJLIANG	= 521, //¥��������//pmparms��������ֲ���
		eL_ZLL_WMLIANG	= 522, //����������
		eL_CLL_CILIANG	= 160, //������
		eL_DHL_kjl	= 161, //���Ͽ����
		eL_DHL_fkjl	= 162, //���Ϸǿ����

		eL_HJL_lckjl = 661,					//��¥������
		eL_HJL_wmkjl = 662,					//����������
		eL_HJL_kzl = 663,					//�󽽿�֧��
		eL_HJL_kjbl = 664,					//�󽽿�ܱ���
		eL_HJL_tzzhl = 665,					//������ת����
		eL_HJL_fkjl = 666,					//�󽽷ǿ����
		eL_HJL_jzl = 667,					//�󽽾�����
		eL_HJL_ptll = 668,					//����ͨ����
		eL_HJL_kjll = 669,					//�󽽿������

		/*�Զ��幹��*/
		eL_zdy	  = 199						// �Զ���
	};//eLIANG
	//��������
	enum eZHU
	{	
		eZhu = 200,
		eZKJ  = 210,
		eZ_kjz   = 211,						// �����
		eZ_lsz   = 212,						// ������
		eZ_qsz   = 213,						// ǽ����			
		eZ_kzz   = 214,						// ��֧��
		eZ_xz    = 215,						// о��				
		eZGZ  = 220,
		eZ_gzz   = 221,						// ������

		//modify by zhengwei 20111230
		eZ_kjjg  = 222,                     //��ܽṹ
		eZ_zhjg  = 223,                     //ש��ṹ

		eZ_qsgzz = 222,						// ǽ�Ϲ�����
		eZ_lsgzz = 223,						// ���Ϲ�����
		eZA   = 230,
		eZ_az	 = 231,						// ����	
		eZOTH = 240,
		eZ_ntz	 = 241,						// ţ��
		eZ_zm	 = 242,						//��ñ
		/*�Զ��幹��*/
		eZ_zdy	 = 299						// �Զ���
	};//eZHU
	//������ǽ
	enum eJLQIANG
	{
		eJLQiang = 300,
		eQJL      = 310,
		eQ_1cjlq	= 311,					// ����ǽ��һ�δ�ӣ�
		eQ_2cjlq	= 312,					// ����ǽ�����δ�ӣ�
		eQ_Gjlq		= 313,					// ͼ�η�����ǽ
		eQOTH     = 320,
		eQ_az		= 321,					// ����	
		eQ_ll		= 322,					// ����
		eQ_qtjj		= 323,					// ����ӽ�
		eQ_qtq		= 324,					//����ǽ
		eQ_jfq		= 325,					//�˷�ǽ
		/*�Զ��幹��*/
		eQ_zdy	 = 399						// �Զ���
	};//eJLQIANG
	//��������
	enum eBAN
	{	
		eBan = 400,
		eB_TiBan = 408,						//�ݰ�
		eBXJ  = 410,
		eB_ptb   = 411,						// ��ͨ��
		eB_scsxb = 412,						// ˫��˫���
		eB_bjlb  = 413,						// ����б�

		eB_zsbd = 414,						//���ϰ��
		eB_kzbd = 415,						//���а��
		eB_jcbd_zxbd = 416,						//�������: ���°��
		eB_jcbd_kzbd = 417,						//�������: ���а��
		eB_cj_cj = 418,						//����Žţ��Ž�
		eB_cj_lj = 419,						//����Žţ�����
		eB_bdong = 421,						//�嶴
		eB_fdj_lb = 422,						//����׽����ʽ����
		eB_fdj_pb = 423,						//����׽ƽ��ʽ����
		eB_fmj_lb = 424,						//����������ʽ����
		eB_fmj_pb = 425,						//������ƽ��ʽ����
		eB_bjcj_cj = 426,						//���Ž�Ž�
		eB_bjcj_lj = 427,						//���Ž����

		eB_bj_fsj = 428,						//�������
		eB_fbj_fsj = 429,						//���������
		/*�Զ��幹��*/
		eB_zdy   = 499						// �Զ���	
	};//eBAN
	//����������
	enum eJC
	{
		eJc	 = 500,
		eJCTX	= 510,
		eJC_ylstxjc	 = 511,					// ����ʽ���λ���
		eJC_wlstxjc  = 512,					// ����ʽ���λ���

		eJC_sl_ttj	 = 513,					//ͼ�η�������

		eJCDL   = 520,
		eJC_xjzxdljc = 521,					// �ֽ����¶�������		
		eJC_bxjc	 = 522,					// ���λ���
		eJC_szptdljc = 523,					// ˫����ͨ��������

		eJC_G_dljc	 = 524,					//ͼ�η���������
		eJCCT	= 530,
		eJC_jxct	 = 531,					// ���γ�̨
		eJC_3zct	 = 532,					// ��׮��̨
		eJC_5zct	 = 533,					// ��׮��̨
		eJC_6bct	 = 534,					// ���߳�̨
		eJC_8bct	 = 535,					// �˱߳�̨
		eJC_bzct	 = 536,					// ��׼��̨

		eJC_G_ct	 = 537,					//ͼ�η���̨
		eJC_G_bzct	 = 538,					//ͼ�η���׼��̨

		eJCXJZ	= 540,
		eJC_gzz		 = 541,					// ��ע׮
		eJC_rgwkgzz  = 542,					// �˹��ڿ׹�ע׮
		eJCYZZ	= 550,
		eJC_zz		 = 551,					// ��׮
		eJC_jz		 = 552,					// ��׮
		eJCFX	= 560,
		eJC_lbs		 = 561,					// ����ʽ
		eJC_zxbds	 = 562,					// ���°��ʽ
		eJC_fjgjlb	 = 563,					// �����ֽ��
		eJCMT	= 570,	
		eJC_mtjc	 = 571,					// ���û���
		eJCOTH	= 580,
		eJC_jsj		 = 581,					// ��ˮ��
		eJC_dbhjd	 = 582,					// �װ�󽽴�
		eJC_dtjjc	 = 583,					// ���ݾ�����	

		eJC_S_ZhuDun = 51201,				//������
		eJC_X_ZhuDun = 51202,					//������
		/*�Զ��幹��*/
		eJC_zdy		 = 599					// �Զ���
	};//eJC
	//������¥��
	enum eLT
	{
		eLt = 600,
		eLTXJBS = 610,	
		eLT_lt		= 611,					// ����
		eLT_ltpt	= 612,					// ¥��ƽ̨
		eLT_AT_ET	= 613,					// AT-ET��¥��(����)
		eLT_FT_LT	= 614,					// FT-LT��¥��(˫��)
		eLTPT	= 620,
		eLT_ptlt	= 621,					// ��ͨ¥��
		/*�Զ��幹��*/
		eLT_zdy		= 699					// �Զ���
	};//eLT
	//����������
	enum eLX
	{
		eLx  = 700,
		eLxgj  = 710,
		eLX_yt	  = 711,					// ��̨
		eLX_yp    = 712,					// ����
		eLX_lb    = 713,					// ����
		eLX_yd    = 714,					// ѹ��	
		eLX_yg    = 715,					// �ܹ�
		eLX_wqxj  = 716,					// ��ǽ�߽�
		eLX_neq	  = 717,					// Ů��ǽ
		eLX_qzljj = 718,					// ǽ�������
		eLX_pc    = 719,					// Ʈ��
		eLX_hjd	  = 720,					// �󽽴�
		eLX_jd	  = 721,					//��ǽ�ڵ�
		eLX_psg	  = 722,					//��ˮ��
		eLX_yading= 723,					//ѹ��
		eLX_tiaoyan=724,					//����
		eLX_fsfk = 725,						//��ˮ����
		/*�Զ��幹��*/
		eLX_zdy	  = 799						// �Զ���
	};//eLXGJ
	enum eMCD
	{
		eMCD = 800,
		eMCD_dkjj = 811,					//���ڼӽ�
		eMCD_m = 812,						//��
		eMCD_c = 813,						//��
		eMCD_dong = 814,					//ǽ��
		eMCD_ct = 815,                      //��̨
		eMCD_PC = 816,                      //Ʈ��
		eMCD_zjPC = 817,                    //ת��Ʈ��
		eMCD_Md = 818,						//�Ŷ�
	};
	enum eOther//����
	{
		eOther = 900,
		eOther_line = 901						//�߹���
	};

	/*enum eKXLG
	{
	eKXLG = 1000,
	eKXLG  
	};*/
}


namespace pmdataservice
{
	/// �汾�ţ���������Ҫ��չ
	enum
	{
		eVersion_Err = -1 
		, eVersion_1 = 1 
		, eVersion_2 = 2 
		, eVersion_3 = 3 
		, eVersion_4 = 4 
		, eVersion_5 = 5 
		, eVersion_6 = 6
		, eVersion_7 = 7 
		, eVersion_8 = 8
		, eVersion_9 = 9 
		, eVersion_10 = 10
	} ;
}

