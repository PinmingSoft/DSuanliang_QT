#pragma once
typedef int(*InsertGJAllParm_T)(int iComType, int iFloorID, CString strName, int iVolume,int & iComID);

#include "Project_ComParmsCache.h"
class PMProjectDBSERVICE CComponentsContainer
{
public:
	CComponentsContainer(void);
	virtual ~CComponentsContainer(void);

	/**
	* @brief  ת��ComType��Ϣ����Ҫ���� ����ǽ ����ǽ����
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [28/12/2012]
	*/
	static BOOL TransComType2Arr(int iComType,CUIntArray & iComTypeArr);

	/**
	* @brief   ��ȡָ��ComID���е� ��Ϣ��
	*
	*          
	* @note  : ���ص�����DataSet����Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [25/9/2012]
	*/
	BOOL GetComponentInfoDataSetArr(CUIntArray & iComIDArr,CPM_StorageDataSet *& pComponentDataSet,\
		CPM_StorageDataSet *& pGraphicMapDataSet,CPM_StorageDataSet *& pVectorGraphicDataSet,\
		CPM_StorageDataSet *& pGJGraphicVectorDataSet,CPM_StorageDataSet *& pOwnGangJinDataSet);

	/**
	* @brief   ���е� ��Ϣ��
	*
	*          
	* @note  : 
	* @param : CPM_StorageDataSet * pComponentDataSet,������
	CPM_StorageDataSet * pGraphicMapDataSet,�Զ���ͼ�ζ�Ӧ��
	CPM_StorageDataSet * pVectorGraphicDataSet,ͼ����������ͼ��
	CPM_StorageDataSet * pGJGraphicVectorDataSet,ͼ�θֽ����ͼ��
	CPM_StorageDataSet * pOwnGangJinDataSet,�Զ���ֽ��
	CUIntArray & iOldComIDArr,��ComID����
	CUIntArray & iNewComIDArr����ComID���� 
	int iCoverMode��0  ������������
	1  ���ǹ������� ��������
	2	���ǹ������� ����������
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [25/9/2012]
	*/
	BOOL AppendComponentInfoDataSetArr(CPM_StorageDataSet * pComponentDataSet,\
		CPM_StorageDataSet * pGraphicMapDataSet,CPM_StorageDataSet * pVectorGraphicDataSet,\
		CPM_StorageDataSet * pGJGraphicVectorDataSet,CPM_StorageDataSet * pOwnGangJinDataSet,\
		CUIntArray & iOldComIDArr,CUIntArray & iNewComIDArr,int iCoverMode);

	/**
	* @brief :  ��ȡ��ǰ����鹹���й���������ͬ�Ĺ�������CStringArray�����鹹�������á�
	*
	* @note  : 
	* @param : 
	* @return: 
	* @author: κ����
	* @date  : [28/9/2012]
	*/
	BOOL GetSameComNameAry_Kgj(CPM_StorageDataSet * pComponentDataSet, CStringArray &aryComName, BOOL & bHasNotFind);

	/**
	* @brief  ͨ��ComID ˢ�·������� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [18/12/2012]
	*/
	static BOOL ReFreshFangJianComParms_ComID(int iComID);
	static BOOL ReFreshFangJianComParms_ComID(int iComID,const std::map<int,int> & mapOldComid2New);
	static BOOL ReFreshFangJianComParms_ComID(int iComID,NDataModelDataSet * pComParmsDataSet);
	static BOOL ReFreshFangJianComParms_ComID(int iComID,NDataModelDataSet * pComParmsDataSet,const std::map<int,int> & mapsComidOld2New);

	/**
	* @brief �жϹ��������Ƿ� ������ʾ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [24/7/2012]
	*/
	static BOOL CheckComType_ShowUpFloor(int iComType);

	/**
	* @brief �жϹ��������Ƿ� ������ʾ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: lbw
	* @date  : 2020/1/10
	*/
	static BOOL CheckComType_ShowUpFloorAddJC(int iComType);

	/**
	* @brief   ��ȡ 0Q ComID
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [24/7/2012]
	*/
	static BOOL GetOQComID(int &iComID);

	/**
	* @brief  ��ȡ ���̱�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [23/7/2012]
	*/
	static double GetGcbg( const int & nComID , const double & dLcbg ) ;

	/**
	* @brief  ��ȡ ���̱�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [23/7/2012]
	*/
	static double GetLcbg( const int & nComID , const double & dGcbg ) ;

	/**
	* @brief  �ڲ������� ���� ָ�� �� ���� ֵ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	static CString			GetParmValue( NDataModelDataSet * pComParmsDataSet ,  const CString & strParmName ) ; 

	/**
	* @brief �����ͼ������ ��������  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [5/7/2013]
	*/
	static BOOL GetVectorParm_ParmValue( NDataModelDataSet * pVectorParmDataSet ,  const CString & strParmName ,CString & strParmValue) ;

	/**
	* @brief   �ڲ������� ���� ָ�� �� ����ֵ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	static BOOL			SetParmValue( NDataModelDataSet * pComParmsDataSet ,  const CString & strParmName ,CString  strParmValue ) ;

	/******************************************************************** 
	������������ȡ���й��� ��ʾ������
	������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[11/9/2009]
	*********************************************************************/ 
	static BOOL GetGJDisAllAttParm(int iComID, CParms & Attparms);

	//ע���ȡ��ע�� �����¹��� �����ɲ���
	static BOOL RegistInsertGJAllParmCallBack(InsertGJAllParm_T pCalBackFun);
	static BOOL UnRegistInsertGJAllParmCallBack();

	// hn 2016.10.08 ɾ��comid��Ϊ��ɾ���ļ�¼�����componentsdel���У����ڿ����ָ��������Ҳ���comid����
	static BOOL DelComponent_ID(int iComID);
	static BOOL DelComponent_IDNew(int iComID);

	static BOOL DelComponent_IDArr(const CUIntArray & iComIDArr);
	static BOOL DelComponent_IDArrNew(const CUIntArray & iComIDArr);


	/**
	* @brief  ��ȡָ������������  �ֽ� VectorID
	*
	*          
	* @note  : 
	* @param :
	*			
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/11/2011]
	*/
	static int GetComParms_VectorID_GJ(int iComID);

	//zfy note 2020.05.29,Ŀǰ�Ѱ��⺯����ͬ�� GetComParms_VectorID_GJ���Ա����ͨ���������������� GetComParms_VectorID_GJ �������������ȷ
	static int GetComParms_VectorID(int iComID);
	/**
	* @brief  ��ȡָ���������͵� ������ 
	*
	*          
	* @note  : 
	* @param :
	*			CUIntArray &iParmTypeArr ���������� ������������� �ֽ������
	*			NDataModelDataSet * pComParmDataSet����Ҫ���������͹��˵Ĳ���
	* @defenc: 
	* @return: ����DataSet��Ҫ ɾ��
	* @author: ����ҵ
	* @date  : [29/11/2011]
	*/
	static BOOL GetComParmsDataSet_ParmType(int iComID,CUIntArray &iParmTypeArr,NDataModelDataSet *& pComParmDataSet);

	/**
	* @brief  ����iComponentComType �����ò���hide�ı��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	static BOOL FillNoNeedParms(int iComID,int iComType,NDataModelDataSet * pComParmsDataSet);

	/**
	* @brief ����iComponentComType �����ò���hide�ı��
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: zfy
	* @date  : [12/11/2018]
	*/
	static void FiterParmsWithComponentComType(int iComID,int iComType,int iComponentComType,NDataModelDataSet * pComParmsDataSet);

	/**
	* @brief  	//���ڹ��̱�߻�¥����ģʽ�¼���
	*
	*          
	* @note  : 
	* @param : nChangeMode : 0 ��ʾ ������ߡ����ױ�� Ҫ��ȥһ��¥������ ������ʾ��ͨ�����ڽ�UI��dataset(���̱��)תΪ���ݴ洢��
							 1 ��ʾ ������ߡ����ױ�� ����ʵ�ʱ��ģʽ�����Ӽ��������������ߴ洢��datasetת������UI��dataset
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	static BOOL ReCalComponentBGExtend(int iComID,int iCalMode, int iComType,NDataModelDataSet *pDataSet);

	//�����ģʽ������ʾ��ߵ�������
	static BOOL ShowChNameDisplay_BG(int iComID,int nChangeMode, int iComType,NDataModelDataSet *pDataSet);

	/**
	* @brief   �����������
	*
	*			1.����ĳ��߸Ķ�������һ��߻��߲����������
	*			2.���ڽ�����ʾʱ�ĵĹ��̱������
	*			3.�������Ķ����޸�����Ϊ qc:26038
	* @note  : ������ �� ����ԭ�ȵ� ����д�ĵ� ReCalComponentBG ���������޸ġ����� ���������� ��������
	* @param : nChangeMode : 0 ��ʾ ������ߡ����ױ�� Ҫ��ȥһ��¥������ ������ʾ��ͨ�����ڽ�UI��dataset(���̱��)תΪ���ݴ洢��
							 1 ��ʾ ������ߡ����ױ�� ����ʵ�ʱ��ģʽ�����Ӽ��������������ߴ洢��datasetת������UI��dataset
							 2 ͨ�� ������ߡ����ױ�� �������������ױ�� ������¥�����ߵļӼ�,������߸���ʵ�ʱ��ģʽ�����Ӽ���������������dataset��ĸ���
	*
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/17/2018]
	*/
	static BOOL ReCalComponentBG(int iComID,int nChangeMode, int iComType,NDataModelDataSet *pDataSet);

	//���� ��ע
	static BOOL ChangeWithBz( const int & nComID ,const CString &strBz );

	/**
	* @brief  ���㹹�� ��ע
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	static BOOL ReSumGJBz_VectorInfo(int iComID, CString &strVectorInfo);

	/**
	* @brief  ���㶥 �� ���
	*			
	*          qc:30186,�� pDataSetForDb ����Ϊ���ݿ�洢�õı�ߣ�ͳһΪ��Ա�� 
	* @note  : 
	* @param : pDataSet
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	static BOOL ReCalComponentDbg_Dibg(int iComID, CString strEditParmName, NDataModelDataSet * pDataSetForDb);

	/**
	* @brief  ���� ���� ����
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	static BOOL ReBuildJMParm(int iComID,int iComType,CString & strJM);

	//���һ�� ר���ж� ������� ����
	//nMode ����� ģʽ
	//1 : ����, 2 :Բ�� ,3 :����,4:��Բ��,5:Բ����,6:T��,7:ʮ����,8:Z����,9:L��,
	//10:����,11:��������,12:���˱���,13:������1,14:������2
	static BOOL CheckVectorMode_Zhu(int iComID, int &nMode);

	/******************************************************************** 
	����������������ͼ�Ƿ��Ǿ���
	������int iComID,BOOL & bMode TRUE������ FALSE������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[29/4/2008]
	*********************************************************************/ 
	static BOOL CheckVectorMode(int iComID, BOOL &bMode);

	/******************************************************************** 
	������������鵱ǰ���� ������ͼ�Ƿ��Ǿ���
	������int iComID,BOOL & bMode TRUE������ FALSE������
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[29/4/2008]
	*********************************************************************/ 
	static BOOL GetCurGjVectorMode(BOOL &bMode);

	/******************************************************************** 
	��������������ComType ��ȡ����� �ױ�ߵĲ�������
	������iComType���������ͣ�iBGMode��0 û�б�ߣ�1��ֻ�ж���ߣ�2��ֻ�еױ�� 3�����У�
	strDingParmName������߲����� strDiParmName���ױ�߲�����
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2010:12:29]   16:56
	*********************************************************************/ 
	static BOOL GetBGInfo_DingDiParmName(int iComType,int & iBGMode,CString & strDingParmName,CString & strDiParmName);

	/**
	* @brief  ��ȡָ��ComID�Ĳ������е� ����ֵ
	*
	*          
	* @note  : 
	//CComParmsSet_ParmName::Globel_ParmType = 1;ȫ�ֲ���
	//CComParmsSet_ParmName::SL_ParmType = 2;��������, �ֽ���ҲҪ���ֵ���������
	//CComParmsSet_ParmName::GJ_ParmType = 3;�ֽ����
	//CComParmsSet_ParmName::GJ_JSSZ_ParmType = 4;�������ò���
	//CComParmsSet_ParmName::SL_ParmType_OL = 5 ; �������вų��ֵ����Բ���
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	static BOOL GetComAttribute(int comID,int iParmType,const CString & sAttributeKey,CString &sValue);
	static BOOL GetComAttribute(int comID,const CString & sAttributeKey,CString &sValue);

	static BOOL GetComAttribute(NDataModelDataSet * pComParmsDataSet , int comID,int iParmType,const CString & sAttributeKey,CString &sValue);
	static BOOL GetComAttribute(NDataModelDataSet * pComParmsDataSet , int comID,const CString & sAttributeKey,CString &sValue);
	static BOOL GetComAttribute(NDataModelDataSet * pComParmsDataSet 
								,int comID
								,int iParmType
								,const CString & sAttributeKey
								,CString &sValue
								,CString &sValueNoTrans);
	static BOOL GetComAttribute(int comID,const CSubComtypeParms * pParms_SX,const CParms * pParms_Vector,const CString & sAttributeKey,CString & sValue,BOOL bTransComParms);
	static BOOL GetComAttribute(int comID
								,const CSubComtypeParms * pParms_SX
								,const CParms * pParms_Vector
								,const CString & sAttributeKey
								,CString & sValue
								,CString & sDisplayName
								,CString & sInvalidMsg
								,BOOL bTransComParms);

	static BOOL GetComAttribute_NotTrans(int comID,int iParmType,CString sAttributeKey,CString &sValue );
	static BOOL GetComAttribute_NotTrans(int comID,CString sAttributeKey,CString &sValue );
	static BOOL GetComAttribute_NotTrans(NDataModelDataSet * pComParmsDataSet,int comID,int iParmType,CString sAttributeKey,CString &sValue );
	static BOOL GetComAttribute_NotTrans(NDataModelDataSet * pComParmsDataSet,int comID,const CString & sAttributeKey,CString &sValue);
	/**
	* @brief  ���� ָ���Ĳ��� ��������
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [13/7/2012]
	*/
	static BOOL SetComAttribute(int comID,int iParmType,const CString & sAttributeKey,CString strValue);

	static BOOL SetComAttribute(int comID,const CString & sAttributeKey,CString strValue);

	static BOOL SetComAttributeForComponentType(int comID, int componentType, const CString & sAttributeKey,CString strValue);

	static BOOL SetComAttribute(NDataModelDataSet * pComParmDataSet ,int iParmType,const CString & sAttributeKey,CString strValue);

	static BOOL SetComAttribute(NDataModelDataSet * pComParmDataSet ,const CString & sAttributeKey,CString strValue);

	static BOOL SetComAttributeForComponentType(NDataModelDataSet * pComParmDataSet ,int componentType, const CString & sAttributeKey,CString strValue);

	/**
	* @brief  ͨ�� ComID parmtype����ȡ ָ����������Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [1/8/2012]
	*/
	static BOOL GetComParmInfo(int comID,int iParmType,const CString strParmName,CString & strDisParmName,CString & strParmValue,\
		CString & strInvalidMsg);

	static BOOL GetInvalidMsg( const int comID,const int iParmType,const CString & strParamName , CString &strInvalidMsg );
	static BOOL GetInvalidMsg( const int comID,const CString & strParamName, CString &strInvalidMsg  );

	static BOOL GetInvalidMsg( NDataModelDataSet * pComParmsDataSet , const int comID,const CString & strParamName, CString &strInvalidMsg  );

	static BOOL SetInvalidMsg( const int iComId , const CString & strParmName , const CString & strInvalidMsg ) ;

	//�Ƿ���ǲ�߻�����صı��ʽ
	static BOOL IsFloorExp(CString strParmValue);

	//�����߱��ʽ
	static double CalFloorExp(CString strParmValue,double dCg);
	//
	static BOOL IsExp(CString strParmValue,CString strParmName);

	//���ʽ�滻,strParmValue ����Ϊ $cg + 350,  strExpList��ʽΪ:  $cg=200|$sjswdp=-100|$zrsjdp=20
	static double CalExp(CString strParmValue,CString strExpList);

	/**
	* @brief   strParmValue ����Ϊ $cg + 350 ,strParmNameΪ$cg, dCg Ϊ $cg��ֵ
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [1/9/2018]
	*/
	static double CalExp(CString strParmValue,CString strParmName,double dCg);

	/**
	* @brief �Բ���Value�е�������� ���з���  
	*
	*          ע�⣺ȡ��߽�������Ϊ��ĸ߶�,ȡ��׽�������Ϊ0��ȡ��߱�����Ϊ¥��׵Ĺ��̱��
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	static CString TransComParms_ParmValue(int iComID,CString strParmValue);

	////////////////////////////////////////////
	/// ֣���� [2014��5��21��]
	/// ˵��:
	/// ����������汾2 �� 
	/// �����ֵ��ͨ��strTransValue ���ء�
	/// ��������ֵ��ʾ �����ֵ �ǹ��̱�ߵ�(TRUE)������¥���ߵ�(FALSE)
	/// һ�㶼��¥���ߵģ��ٲ���Ϊ ���̱�ߣ���$sjswdp /$zrsjdp
	static BOOL TransComParms_ParmValueV2( const int iComID, const CString & strParmValue , CString & strTransValue );

	/******************************************************************** 
	�����������ж�ĳ�������Ƿ���Ҫ����
	��    ����nComID : ����ID ; sAttributeKey : ��������; bHasTranslate �Ƿ���Ҫ���� 
	�� �� ֵ��ִ���Ƿ�ɹ�
	��    �����跭��ġ�ֵ�����ǡ�����'$' ��־��
	ע�����
	��    �ߣ�����ҫ
	ʱ    �䣺[27/5/2008]
	*********************************************************************/ 
	static BOOL ComParmNeedTranslate( const int  nComID , const  CString & sAttributeKey,BOOL &bNeedTranslate);

	/**
	* @brief  ���ݹ�����Ϣ ��ȡ DJXS 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [23/7/2012]
	*/
 	static BOOL GetComParm_DJXSDataSet(const int nComID,  NDataModelDataSet *& pDJXSDataSet);
// 
// 	static int GetComDjxs( const int iComId ,  const CString & strHandle , const double & dDia , const BOOL bVertical = FALSE ) ; 
// 	static int GetComDjxs( const int iComId ,  const CString & strHandle , const CString & strDia , const BOOL bVertical = FALSE ) ;


	/**
	* @brief   ��ȡ�����Ĵ����ʽ����CString�ķ���
	*
	*          
	* @note  : 
	* @param : bNeedSx �Ƿ���Ҫ������ 
	* @defenc: 
	* @return: ���ص�string����ʽ : /// m_strDJXS��ʽΪ 6-10$1;12-20$1;24-30$3	
									/// m_strDJXS��ʽΪ 3-10$1&1;12-14$1&1;16-22$4&4;25-50$8&8	
	* @author: ����ҫ
	* @date  : [2012-9-4]
	*/
	static CString	GetComParmDjxs( const int iComId  , const BOOL bNeedSx = FALSE ) ;

	/******************************************************************** 
	������������ȡָ��������sAttributeKey ����ʾ����
	������comID������ID sAttributeKey������������ sAttrDisName�����ص���ʾ����
	�� �� ֵ��
	�㷨��
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[23/4/2008]
	*********************************************************************/ 
	static BOOL GetComAttrDisParmName( const int comID, const CString & sAttributeKey,CString &sAttrDisName) ;

	/**
	* @brief  ���빹���� �ص��ӿ�
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [18/7/2012]
	*/
	static int InsertGJ_AllParm(int iComType, int iFloorID, CString strName, int iVolume,int & iComID);

	/**
	* @brief �������ʾ ֵ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [18/7/2012]
	*/
	static CString TransShowParmValue(int iComID,const CString & strParmName,const CString & strParmValue);

	static BOOL CheckComType_CanCalInGJ(int iComType);

	static BOOL CheckComType_CanCalInSL(int iComType);

	/**
	* @brief  �ж������������ �Ƿ������ʾ�� �ֽ����
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [10/10/2013]
	*/
	static BOOL CheckComType_CanShowInGJ(int iComType);

	/**
	* @brief  �ж������������ �Ƿ������ʾ�� ��������
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [10/10/2013]
	*/
	static BOOL CheckComType_CanShowInSL(int iComType);

	static int Get_GJComType( const int comID);

protected:

//	static int GetComDjxsTemp( const int iComId , const CString & strHandle ,  const double & dDia , const BOOL bVertical = FALSE ) ;

	static BOOL GetComponentInfoDataSetArr_VectorInfo(CUIntArray & iComIDArr,\
		CPM_StorageDataSet * pGraphicMapDataSet,\
		CPM_StorageDataSet * pVectorGraphicDataSet,\
		CPM_StorageDataSet * pGJGraphicVectorDataSet);
	
	//���������鹹������
	static void ReBuildGjName( CString& strTemComName );
	
	/**
	* @brief  ���¸�дװ�ε�ComId
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ֣����
	* @date  : [2015/07/10]
	*///
	void ReBuildComId_ZS(const CUIntArray & iNewComIDArr, const CUIntArray & arrComtype,const CUIntArray & iOldComIDArr );
	static InsertGJAllParm_T s_pInsertGJAllParmCalBackFun;
};
