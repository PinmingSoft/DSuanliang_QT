
#pragma  once
/********************************************************************
created:	2015/03/27
author:		郑琪崇

purpose:	修改截面图中相应的参数，界面上的顶底标高联动
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
	author:		郑琪崇LinkageOfBg();

	purpose:	修改截面图中的插入点标高值，界面上的顶底标高需要联动
	*********************************************************************/
	void LinkageOfBg( const BOOL bChangeBg , const BOOL bDrawVector , const CString & strEditBG, const double dDisTop = 0.0 , const double dDisBottom = 0.0 );

	/********************************************************************
	created:	24:3:2015   10:48
	author:		郑琪崇

	purpose:	获取插入点到顶部或底部的高度值
	*********************************************************************/
	void GetInsertPt2TopOrBottom( const CString strTopH, double & dBgValue );
	static void GetInsertPt2TopOrBottom(int comid, const CString strTopH, double & dBgValue );

	/********************************************************************
	created:	24:3:2015   15:27
	author:		郑琪崇

	purpose:	获取插入点标高的msginfo值，并将其拆分为两部分
	*********************************************************************/
	BOOL GetMsgInfo( CStringArray & aryMsgInfo ,  CString & strMsgInfo );

	/********************************************************************
	created:	9:4:2015   10:32
	author:		郑琪崇

	purpose:	存在comid，获取插入点标高的msginfo值，并将其拆分为两部分
	*********************************************************************/
	static BOOL GetMsgInfo( const int iComId, CStringArray & aryMsgInfo , CString & strMsgInfo );
	/********************************************************************
	created:	24:3:2015   16:07
	author:		郑琪崇

	purpose:	修改H边信息，联动界面基准点标高
	*********************************************************************/
	void ModifyHInfo( CString strParmName, CString strParmValue );

	/********************************************************************
	created:	24:3:2015   16:47
	author:		郑琪崇

	purpose:	获取strPName对应的参数值strPValue
	*********************************************************************/
	void GetInsertPtBg( const CString strPName, CString & strPValue);

	/********************************************************************
	created:	24:3:2015   18:00
	author:		郑琪崇

	purpose:	获取修改后的H值(HInfo中包含修改的H值)
	*********************************************************************/
	void GetModifyValue( CString strHInfo, const CString strParmName, const CString strParmValue, double & dValBg );

	/********************************************************************
	created:	25:3:2015   9:38
	author:		郑琪崇

	purpose:	判断标高正负性
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
	author:		郑琪崇

	purpose:	获取插入点标高值
	*********************************************************************/
	BOOL GetInsertPtBG(int comid, double & dInsertBg) const;

	/********************************************************************
	created:	9:4:2015   10:29
	author:		郑琪崇

	purpose:	获取插入点到截面图顶部（dTopHBg）或者到底部距离（dBottomHBg）
	*********************************************************************/
	static BOOL GetHeightInfo( const int iComId, double & dInsert2Top, double & dInsert2Bottom ) ;

	/**
	* @brief 获取B边和H边的边长
	*
	*        
	* @author 郑琪崇
	* @version v1.0
	* @date  2015年12月26日   17:17
	* @note  
	*/
	BOOL GetSideInfo(const CString & strVectorInfo, int & iBSide, int & iHSide,NDataModelDataSet * pVectorParmDataSet );

	/**
	* @brief 将自定义截面图的B边和H边的长度写入数据库。即重写截面(Bb*Hb)的值
	*
	*        
	* @author 郑琪崇
	* @version v1.0
	* @date  2015年12月26日   17:13
	* @note  
	*/
	BOOL SetComParmDataSetJmInfo(const CString & strVectorInfo, NDataModelDataSet * pComParmDataSet,NDataModelDataSet * pVectorParmDataSet );
protected:
	//
	int m_iComID ;
	int m_iComType;
	CProject_VectorParmsTable * m_pVectorDataSet ;

	/// 构件的参数
	NDataModelDataSet * m_pComParmDataSet ; 
};