
#pragma  once
/********************************************************************
created:	2015/03/27
author:		֣����

purpose:	�޸Ľ���ͼ����Ӧ�Ĳ����������ϵĶ��ױ������
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///
#include "AccessProject_ComParmSet_Base.h"
class PMProjectDBSERVICE CVectorEditLinkageBg 
{
public:
	CVectorEditLinkageBg();
	~CVectorEditLinkageBg();

public:

	void SetComId( const int iComId );

	void SetComType( const int iComType );

	/********************************************************************
	created:	24:3:2015   10:22
	author:		֣����LinkageOfBg();

	purpose:	�޸Ľ���ͼ�еĲ������ֵ�������ϵĶ��ױ����Ҫ����
	*********************************************************************/
	void LinkageOfBg( const BOOL bChangeBg , const BOOL bDrawVector , const CString & strEditBG, const double dDisTop = 0.0 , const double dDisBottom = 0.0 );

	/********************************************************************
	created:	24:3:2015   10:48
	author:		֣����

	purpose:	��ȡ����㵽������ײ��ĸ߶�ֵ
	*********************************************************************/
	void GetInsertPt2TopOrBottom( const CString strTopH, double & dBgValue );
	static void GetInsertPt2TopOrBottom(int comid, const CString strTopH, double & dBgValue );

	/********************************************************************
	created:	24:3:2015   15:27
	author:		֣����

	purpose:	��ȡ������ߵ�msginfoֵ����������Ϊ������
	*********************************************************************/
	BOOL GetMsgInfo( CStringArray & aryMsgInfo ,  CString & strMsgInfo );

	/********************************************************************
	created:	9:4:2015   10:32
	author:		֣����

	purpose:	����comid����ȡ������ߵ�msginfoֵ����������Ϊ������
	*********************************************************************/
	static BOOL GetMsgInfo( const int iComId, CStringArray & aryMsgInfo , CString & strMsgInfo );
	/********************************************************************
	created:	24:3:2015   16:07
	author:		֣����

	purpose:	�޸�H����Ϣ�����������׼����
	*********************************************************************/
	void ModifyHInfo( CString strParmName, CString strParmValue );

	/********************************************************************
	created:	24:3:2015   16:47
	author:		֣����

	purpose:	��ȡstrPName��Ӧ�Ĳ���ֵstrPValue
	*********************************************************************/
	void GetInsertPtBg( const CString strPName, CString & strPValue);

	/********************************************************************
	created:	24:3:2015   18:00
	author:		֣����

	purpose:	��ȡ�޸ĺ��Hֵ(HInfo�а����޸ĵ�Hֵ)
	*********************************************************************/
	void GetModifyValue( CString strHInfo, const CString strParmName, const CString strParmValue, double & dValBg );

	/********************************************************************
	created:	25:3:2015   9:38
	author:		֣����

	purpose:	�жϱ��������
	*********************************************************************/
	void DetermineBg( const CString strPlaceBg, double & dValDbg, double & dValDibg );
	void CheckBotOfInserPt( const CString strLocationName, double & dDis2Border );
	void CheckTopOfInserPt( const CString strLocationName, double & dDis2Border );

	//
	void SetVectorDataSet( CProject_VectorParmsTable * pDataSet )
	{
		m_pVectorDataSet = pDataSet;
	}

	void	SetComParmDataSet( NDataModelDataSet * pComParmDataSet )
	{
		m_pComParmDataSet = pComParmDataSet ; 
	}
	/********************************************************************
	created:	7:4:2015   10:24
	author:		֣����

	purpose:	��ȡ�������ֵ
	*********************************************************************/
	BOOL GetInsertPtBG(int comid, double & dInsertBg) const;

	/********************************************************************
	created:	9:4:2015   10:29
	author:		֣����

	purpose:	��ȡ����㵽����ͼ������dTopHBg�����ߵ��ײ����루dBottomHBg��
	*********************************************************************/
	static BOOL GetHeightInfo( const int iComId, double & dInsert2Top, double & dInsert2Bottom ) ;

	/**
	* @brief ��ȡB�ߺ�H�ߵı߳�
	*
	*        
	* @author ֣����
	* @version v1.0
	* @date  2015��12��26��   17:17
	* @note  
	*/
	BOOL GetSideInfo(const CString & strVectorInfo, int & iBSide, int & iHSide,NDataModelDataSet * pVectorParmDataSet );

	/**
	* @brief ���Զ������ͼ��B�ߺ�H�ߵĳ���д�����ݿ⡣����д����(Bb*Hb)��ֵ
	*
	*        
	* @author ֣����
	* @version v1.0
	* @date  2015��12��26��   17:13
	* @note  
	*/
	BOOL SetComParmDataSetJmInfo(const CString & strVectorInfo, NDataModelDataSet * pComParmDataSet,NDataModelDataSet * pVectorParmDataSet );
protected:
	//
	int m_iComID ;
	int m_iComType;
	CProject_VectorParmsTable * m_pVectorDataSet ;

	/// �����Ĳ���
	NDataModelDataSet * m_pComParmDataSet ; 
};