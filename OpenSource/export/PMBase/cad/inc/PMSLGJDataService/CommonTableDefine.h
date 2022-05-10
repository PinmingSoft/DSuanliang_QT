
#pragma  once 

/**
 * @brief һЩ������ṹ�Ķ���
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2012-7-13]
 * @note  
 */

//Ȧ��ƽ�����
struct PmSLGJDataServiceAPI CQL_GraphicDataSet
{
	static const CString id;//
	static const CString ZZK;//��֧����
	static const CString YZK;//��֧����
	static const CString Ln;//���糤
	static const CString zdtype;//��˶˲�����
	static const CString ydtype;//�Ҷ˶˲�����

//	static const CString SPAng;//ˮƽ�Ƕ�
	static const CString ZDInfo;//�۵���Ϣ

	static NDataModelDataSet * GetDataSet();
};

struct PmSLGJDataServiceAPI CLayerColorShowDataSet
{
	static const CString floorid ;
	static const CString comtype ; 
	static const CString layer ;
	static const CString comtypename ; 
	static const CString color ; 
	static const CString showcolor ; 
	static const CString iscolorchanged ; 
	static const CString isshowcolorchanged ; 
	static const CString colorshow ; 

	static NDataModelDataSet * GetDataSet() ; 
};

struct PmSLGJDataServiceAPI CJTParmDataSet
{
	static const CString parmname;
	static const int	parmname_Index;

	static const CString parmvalue;
	static const int	parmvalue_Index;

	static const CString parmdes ;
	static const int	parmdes_Index ;

	static CPM_TranStringDataSet * GetDataSet();

	/// ����ֶ� : parmdes
	static CPM_TranStringDataSet * GetDataSetV2() ; 
};


struct PmSLGJDataServiceAPI CNameValue_Com
{
	static const CString name ; 
	static const CString value ; 

	static NDataModelDataSet * GetDataSet() ;
};



/// ������ʾ����
struct  PmSLGJDataServiceAPI CPMShowControl
{
	static const CString NameListData ;		/// �������Ƶ�����ѡ��
	static const CString GjName ;			/// ��������
	static const CString GjMs ;				/// ��������
	static const CString GjNameMs ;			/// �������ƺ�����
	static const CString TC ;				/// ���
	static const CString NTC ;				/// �����
	/// ��ini�ļ�ʱ�õ�
	static const CString GjShowControl ;	/// ������ʾ����
	static const CString banjinname ;		/// ���򷤰���������ʾ
	static const CString goujianname ;		/// ����ͨ�õ�������ʾ
	static const CString diaojinname ;		/// �����������ʾ 
	static const CString mjtx ;				/// ������ͼ���Ƿ����
	static const CString xjbtx ;			/// �ֽ����ͼ���Ƿ����
	static const CString ltx;				/// ����ͼ���Ƿ����
	static const CString qiang;				/// ǽ��ͼ���Ƿ����
	static const CString ttjtx;				/// ��������ͼ���Ƿ����

	static const CString kdtx;				/// �յ�ͼ���Ƿ����
	static const CString xmtx;				/// оģͼ���Ƿ����
	static const CString tpldmtx;           /// ����¥����ͼ���Ƿ����
};

class PmSLGJDataServiceAPI CPMLiangInputDataSet : public CPM_StorageDataSet  
{
public:
	CPMLiangInputDataSet();
	virtual ~CPMLiangInputDataSet();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		const static CString id ;
		const static CString xh ;
		const static CString kh ;
		const static CString bg ;
		const static CString bgEnd ;
		const static CString a1 ;
		const static CString a2 ;
		const static CString a3 ;
		const static CString a4 ;
		const static CString kc ;
		const static CString jmlx ;
		const static CString jmlxnr ;
		const static CString jm ;
		const static CString leftwidth ;
		const static CString stcj ;
		const static CString sbzzzgj ;
		const static CString sbkzgj ;
		const static CString sbyzzgj ;
		const static CString xbtcj ;
		const static CString xbgj ;
		const static CString cmyj ;
		const static CString cmlj ;
		const static CString zkj;			//�󹿽�                 
		const static CString zkjjmcd;		//�󹿽���ܳ���
		const static CString kj;			//����         
		const static CString ykj;			//�ҹ���         
		const static CString ykjjmcd;		//�ҹ�����ܳ���
		const static CString cljj ;
		const static CString cljj2;				//ʶ����ĵ����еĸ��ӹ��� 
		const static CString dj ;
		const static CString dj2;				//ʶ��ĵ���
		const static CString gjjm ;
		const static CString yc;				//Ҹ��
		const static CString yg;				//Ҹ��
		const static CString yk;				//Ҹ��
		const static CString jygj ;				//��Ҹ�ֽ�
		const static CString jygj2 ;			//��Ҹ�ֽ��յ��
		const static CString jytype ;			//��Ҹ���� �������ˮƽ��
		const static CString jyside ;			//��Ҹ���������ң��ֽ���ʾˮƽ��Ҹ�������Ҹ���������ж�)
		const static CString yc2;			//Ҹ��
		const static CString yg2;
		const static CString yk2;			//Ҹ��
		const static CString jygj3;			//��Ҹ��
		const static CString jygj4;		//��Ҹ����յ��
		const static CString jytype2;			//��Ҹ���ͣ�ˮƽ��0����������1����
		const static CString jyside2;			//��Ҹ���������ң��ֽ���ʾˮƽ��Ҹ����0��1���������Ҹ���������жϣ�
		const static CString jytwoside;
		const static CString qtgj ;				//��������
		const static CString qtgjcontent ;		//�������������
		const static CString jd ;
		const static CString hc ;
		const static CString zdInfo ;			//�۵�
		const static CString zzzType;			//��֧������,0:��,1:ƽ��ǽ,2:��ƽ��ǽ,3:��ƽ����,4:��̨ 6:��ƽ������ 7��ƽ������ 8����֧������֧���� ����û��֧����
		const static CString yzzType;			//��֧������,0:��,1:ƽ��ǽ,2:��ƽ��ǽ,3:��ƽ����,4:��̨ 6:��ƽ������ 7��ƽ������ 8����֧������֧���� ����û��֧����
		const static CString zzzcomid;
		const static CString yzzcomid; 
		const static CString zzctjl;             //�����������˲������ͳ�̨�Ҷ˲�����ѡ��ڵ�������ˣ�
		const static CString yzctjl;             //�����������˲������ͳ�̨�Ҷ˲�����ѡ��ڵ������Ҷˣ�
		const static CString zzzk;               //�����������֧����(����������������Ŀ��)
		const static CString yzzk;               //���������ұ�֧����(����������������Ŀ��)
		const static CString MaxDia;				//���ֱ��
		const static CString lfg;				//������
	};
	virtual int InitFieldStr();
};

class PmSLGJDataServiceAPI CPMPf_ZhuDataSet : public CPM_StorageDataSet  
{
public:
	CPMPf_ZhuDataSet();
	virtual ~CPMPf_ZhuDataSet();

	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id ;
		static const CString xh ;
		static const CString cc ;
		static const CString dbg ;
		static const CString cg ;
		static const CString jdg ;
		static const CString tqd ;
		static const CString jmcc ;
		static const CString jj ;
		static const CString bbzbj ;
		static const CString hbzbj ;
		static const CString qbzj ;
		static const CString kj ;
		static const CString kjzh ;
		static const CString kjzhlx ;
		static const CString kjjmq ;
		static const CString bhc ;
		static const CString qtgj ;
		static const CString dibg ;
		static const CString bFillGjxx;
		static const CString bjmcz;
		static const CString bjmjcz;
		static const CString jdygj;
		static const CString cjgj;
		static const CString xbck;
		static const CString sbck;
	};
	virtual int InitFieldStr();
};


struct PmSLGJDataServiceAPI CPM_PfAnZhu
{
	static const CString id ;
	static const CString xh ;
	static const CString cc ;
	static const CString dbg ;
	static const CString cg ;
	static const CString jdg ;
	static const CString tqd ;
	static const CString jmcc ;
	static const CString qbzj ;
	static const CString VectorParms ;
	static const CString JMLX ;
	static const CString bhc ;
	static const CString qtgj ;

};


struct PmSLGJDataServiceAPI CPM_PfFaJi
{
	static const CString nothing1 ;
	static const CString nothing2 ;
	static const CString nothing3 ;
	static const CString wzsm ;
	static const CString dbgz ;
	static const CString dbgzbh ;
	/// [6/8/2009] ����ҫ
	static const CString dbgzbh2 ;
	static const CString bh ;
	static const CString gjlb ;
	static const CString gjxx ;
	static const CString bzjc ;
	static const CString zzk1 ;
	static const CString zzk2 ;
	static const CString fbfw ;
	static const CString gs ;
	static const CString index ;
	static const CString srcd1;
	static const CString srcd2;
	static const CString gc1;
	static const CString gc2;
	static const CString pd1;
	static const CString pd2;
	static const CString xlbh1;
	static const CString xlbh2;
	static const CString GJMode;//�ֽ�ģʽ eLineGJ = 0,eArcGJ = 1,eCircleGJ = 2

};


//��עby zhengwei 20110113 
//���������ϰ��ʱ������Ĳ���bzjcΪ��������������fbfw�������롣
struct PmSLGJDataServiceAPI CPM_PfBan
{
	static const CString nothing1 ;
	static const CString nothing2 ;
	static const CString nothing3 ;
	static const CString gs ;
	static const CString wzsm ;
	static const CString gjlb ;
	static const CString gjxx ;
	static const CString zzlx ;
	static const CString yzlx ;
	static const CString zzk1 ;
	static const CString zzk2 ;
	static const CString bzjc ;
	static const CString bh ;
	static const CString bh1;
	static const CString fbfw ;
	static const CString index ;
	static const CString bh2;
	static const CString GJMode;//�ֽ�ģʽ eLineGJ = 0,eArcGJ = 1,eCircleGJ = 2
};
struct  PmSLGJDataServiceAPI CPM_PfTJ
{
	static const CString nothing1 ;
	static const CString nothing2 ;
	static const CString nothing3 ;
	static const CString gs ;
	static const CString tjk ;
	static const CString tjdlcd ;
	static const CString gjlb ;
	static const CString gjxx ;
	static const CString zzlx ;
	static const CString yzlx ;
	static const CString zzk1 ;
	static const CString zzk2 ;
	static const CString Ln ;
	static const CString fbfw ;
	static const CString index ;
};

///QTGJ 
struct PmSLGJDataServiceAPI CPM_QTGJ 
{
	static const CString index ;
	static const CString steel_name ;
	static const CString th ;
	static const CString gj;
	static const CString jt ;
	static const CString JTParms ;
	static const CString JTFormula ;
	static const CString xl ;
};

///TTYMJ 
struct PmSLGJDataServiceAPI CPM_TTYMJ 
{
	static const CString index ;
	static const CString bh ;
	static const CString lb ;
	static const CString gnmc;
	static const CString sl ;
	static const CString zj ;
	static const CString gg ;
	static const CString bz ;
};

struct PmSLGJDataServiceAPI CPM_GraphHJD
{
	static const CString gjlb ;
	static const CString gjxx ;
	static const CString bzjc ; 
	static const CString comtype;
	static const CString hjdk;
	static const CString Hc;
	static const CString Bc;
	static const CString gs;
};


struct PmSLGJDataServiceAPI CPM_GraphJSJ
{
	// 1 ����x��ֽ�         2 ����y��ֽ�       3 ����ˮƽ��
	// 4 ʵ�弯ˮ��x��ֽ�   5ʵ�弯ˮ��y��ֽ�  6б��ֽ� 
	static const CString  gjlb ;      
	static const CString  gjxx ;
	static const CString  Ln ;       //���ӵ׾���
	static const CString  h1;        //��˸߶�     ���ֽ�����Ϊ6ʱ,��ֵ�������ĵ��е�Ln1
	static const CString  h2;        //�Ҷ˸߶�     ���ֽ�����Ϊ6ʱ,��ֵ�������ĵ��е�Ln2
	static const CString  pd1;       //����¶�
	static const CString  pd2;       //�Ҷ��¶�
	// 	static const CString  jkk;       //���ӿ�        
	//  static const CString  jkzk;      //����������
	static const CString  hd ;       //���ӵװ��
	static const CString  jpk1;      //���¿�     ���ֽ�����Ϊ6ʱ,��ֵ�������ĵ��е�H
	static const CString  jpk2;      //�Ҿ��¿�
	static const CString  gjdd;      //�ֽ��� 0 δ��� 1 ��˴�� 2 �Ҷ˴��
	static const CString  gs;        //����
};

class PmSLGJDataServiceAPI CPmZhuTable : public NDbDataSet
{
public:
	CPmZhuTable();
	virtual ~CPmZhuTable();

	static const CString INDEX1;	//���ݹ�����������
	static const CString INDEX2;	//���ݱ������
	static const CString ZHUNAME;	//������ �����������򣡣�
	static const CString ComID;		//ComID
	static const CString BBG;		//�ױ��
	static const CString TBG;		//�����
	static const CString FloorID;	//¥��ID
	static const CString FLOORSHOWID; //¥��showid����������
	static const CString LCBH;		//¥����
	static const CString JMCC;		//����ߴ�
	static const CString QBZJ;		//ȫ���ݽ�
	static const CString JJ;		//�ǽ�
	static const CString BBZBJ;		//B���ݽ�
	static const CString HBZBJ;		//H���ݽ�
	static const CString KJ;		//����
	static const CString KJZH;		//�����������
	static const CString KJZHLX;		//�����������
	static const CString QTGJ;		//��������
	static const CString QTGJ_IM;	//��������ı��
	static const CString ISJZBZ;	//�Ƿ��Ǽ��б�ע�У�
	static const CString JDYGJ;    //�ڵ��򹿽�

	virtual int InitFieldStr();

};

/******************************************************************** 
������������ע׮��
������
�� �� ֵ��
�㷨��
ע�����
��    �ߣ�hn
ʱ    �䣺[31/10/2016]
*********************************************************************/ 
class PmSLGJDataServiceAPI CPmGZHTable : public NDbDataSet
{
public:
	CPmGZHTable();
	virtual ~CPmGZHTable();

	static const CString INDEX1;	//���ݹ�����������
	static const CString INDEX2;	//���ݱ������
	static const CString GZHNAME;	//������ �����������򣡣�
	static const CString ComID;		//ComID
	static const CString BBG;		//�ױ��
	static const CString TBG;		//�����
	static const CString FloorID;	//¥��ID
	static const CString FLOORSHOWID; //¥��showid����������
	static const CString LCBH;		//¥����
	static const CString JMCC;		//����ߴ�

	static const CString D;			//׮��
	static const CString L;			//׮��
	static const CString KCCD;		//׮����ͷ���
	static const CString HC1;		//���׶˸߶�1
	static const CString HC2;		//���׶˸߶�2
	static const CString HB;		//���׶˹�����ʸ��
	static const CString TCZJ;		//ͨ������
	static const CString JQZJ;		//��ǿ����
	static const CString LXGJ;		//��������
	static const CString JQGJ;		//��ǿ����
	static const CString ISJZBZ;	//�Ƿ��Ǽ��б�ע�У�

	virtual int InitFieldStr();

};




/******************************************************************** 
����������������
������
�� �� ֵ��
�㷨��
ע�����
��    �ߣ�����ҵ
ʱ    �䣺[22/9/2009]
*********************************************************************/ 
class PmSLGJDataServiceAPI CPmLianLiangTable : public NDbDataSet
{
public:
	CPmLianLiangTable();
	virtual ~CPmLianLiangTable();

	static const CString INDEX1;	//���ݹ�����������
	static const CString INDEX2;	//���ݱ������
	static const CString LIANGNAME;	//������ �����������򣡣�
	static const CString ComID;		//ComID
	//	static const CString BBG;		//�ױ��
	static const CString TBG;		//�����
	static const CString FloorID;	//¥��ID
	static const CString FLOORSHOWID; //¥��showid����������
	static const CString LCBH;		//¥����
	static const CString JMCC;		//����ߴ�
	static const CString SBZJ;		//�ϲ��ݽ�
	static const CString XBZJ;		//�²��ݽ�
	static const CString YJ;		//����
	static const CString KJ;		//����
	static const CString ISJZBZ;	//�Ƿ��Ǽ��б�ע�У�

	virtual int InitFieldStr();

};

///ע�ͣ�����ҫ [2009��11��25��]                                  
///����������
class PmSLGJDataServiceAPI CPmDuLiJiChuTable : public NDbDataSet
{
public:
	CPmDuLiJiChuTable()
	{

	}
	virtual ~CPmDuLiJiChuTable()
	{
	}

	static const CString INDEX1;	//���ݹ�����������
	static const CString INDEX2;	//���ݱ������
	static const CString DULIJICHUNAME;	//�������� �����������򣡣�
	static const CString DUJIJMType ;	/// ���������: ׶��/������
	static const CString ComID;		//ComID
	static const CString BBG;		//�����ױ��
	static const CString FloorID;	//¥��ID
	static const CString FLOORSHOWID; //¥��showid����������
	static const CString LCBH;		//¥����
	static const CString DJCC ;      ///�����ߴ�
	static const CString DJC ;      ///������L
	static const CString DJW ;      ///������B 
	static const CString DJH1 ;     ///�߶�h1
	static const CString DJH2 ;     ///�߶�h2
	static const CString DJH3;		//�߶�h3
	static const CString DJH4;		//�߶�h4
	static const CString JCHJ ;		///�������
	static const CString JCZJ ;		///�����ݽ�
	static const CString ISJZBZ;	//�Ƿ��Ǽ��б�ע�У�

	virtual int InitFieldStr();
};

///ע�ͣ�����ҫ [2009��11��25��]                                  
///ǽ��
class PmSLGJDataServiceAPI CPmQiangTable : public NDbDataSet
{
public:
	CPmQiangTable()
	{
	}
	virtual ~CPmQiangTable()
	{

	}

	static const CString INDEX1;	//���ݹ�����������
	static const CString INDEX2;	//���ݱ������
	static const CString QiangNAME;	//ǽ���� �����������򣡣�
	static const CString ComID;		//ComID
	static const CString ComType ;
	static const CString BGFW ;		/// ��߷�Χ
	static const CString DingBG;		//�����
	static const CString DiBG;		//�ױ��
	static const CString FloorID;	//¥��ID
	static const CString FLOORSHOWID; //¥��showid����������
	static const CString LCBH;		//¥����
	static const CString QH	; 		///ǽ��
	static const CString SPGJ ;		///ˮƽ�ֽ� �ڲ�
	static const CString SPGJ1 ;	/// ˮƽ�ֽ� ���
	static const CString SXGJ ;		///����ֽ� �ڲ�
	static const CString SXGJ1 ;	///����ֽ� ���
	static const CString LJJ ;		///�����
	static const CString ISJZBZ;	//�Ƿ��Ǽ��б�ע�У�
	static const CString ps ;		/// ����
	static const CString MaxDiaSpgj;//ˮƽ��������ֽ�ֱ�� QC7440 add by jqf
	virtual int InitFieldStr();
};


class PmSLGJDataServiceAPI CPMGridStyleTable : public CSQLDataSet  
{
public:
	CPMGridStyleTable();
	virtual ~CPMGridStyleTable();
	virtual int InitFieldStr();


	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString order ;
		static const CString comType ;
		static const CString parmName ;
		static const CString parmValue ;
		static const CString ListData ;
		static const CString InputMode ;
		static const CString groupid ;

		static const CString table_name;
	};
};

class PmSLGJDataServiceAPI CPMDrawBarInfoTable : public NDataModelDataSet
{
public:
	CPMDrawBarInfoTable();
	virtual ~CPMDrawBarInfoTable();
	virtual int InitFieldStr();


	struct PmSLGJDataServiceAPI CFieldInfo
	{
		static const CString id ;
		static const CString mode ;
		static const CString index ;
		static const CString name ;
		static const CString imageindex ;
		static const CString comtype ;
		static const CString disablecomtype ;
		static const CString command ;
		static const CString owncommand ;
		static const CString checkgj ;
	};
};

