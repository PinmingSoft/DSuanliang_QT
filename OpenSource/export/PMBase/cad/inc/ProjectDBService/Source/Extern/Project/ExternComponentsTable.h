// ExternComponentsTable.h: interface for the CExternComponentsTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXTERNCOMPONENTSTABLE_H__1F2A8CAE_20C7_401F_8B1E_2BD5DF3D10F4__INCLUDED_)
#define AFX_EXTERNCOMPONENTSTABLE_H__1F2A8CAE_20C7_401F_8B1E_2BD5DF3D10F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ExternManager.h"


typedef std::set<int> CPmIntSet ; 
typedef CPmIntSet::iterator	CPmIntSetIter ;
typedef CPmIntSet::const_iterator CPmIntSetConIter ; 


/// 
typedef std::map< int , int > CPmInt2IntMap ;
typedef CPmInt2IntMap::iterator CPmInt2IntMapIter ; 
typedef CPmInt2IntMap::const_iterator CPmInt2IntMapConIter ; 

class PMProjectDBSERVICE CExternOwnGanjinVectorTable : public CExternTableBase
{
public:
	CExternOwnGanjinVectorTable();
	virtual ~CExternOwnGanjinVectorTable();

	CSQLDataSet * GetDataSet();
};

class PMProjectDBSERVICE CExternCustomizeSteelDiagramTable : public CExternTableBase
{
public:
	CExternCustomizeSteelDiagramTable();
	virtual ~CExternCustomizeSteelDiagramTable();

	CSQLDataSet * GetDataSet();
};

class PMProjectDBSERVICE CExternComponentsTable : public CExternTableBase
{
protected:
	

public:

	CExternComponentsTable(const CString& strFromProjectDbPath = _T(":memory:"));
	virtual ~CExternComponentsTable();

	/**
	* @brief  ��ȡ�Զ���ֽ� Vector��Ϣ 
	*
	*          
	* @note  :���� ��¼�� ��Ҫɾ�� 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [22/5/2012]
	*/
	BOOL GetComponentOwnGanJinVector(int iComID,LPVOID & pBuffer,long & iBufferSize);
	
	BOOL GetFloorID(int iComID,int & iFloorID);

	BOOL GetComponentName(int iComID,CString & strComName);

	BOOL UpdateShowid(int iComID,int showid);

//	BOOL GetComponentComType(int iComID,int & iComType);

	BOOL ImportGJSX2Project_ComID(int iComID,BOOL bNeedCover);
	BOOL GetComName_ComType(int iComID,CString & strComName,int & iComType);
	int GetComType(int iComID);
	BOOL Import2Project_FloorID(int iFloorID);

	BOOL ImportGJSX2Project_ComType(int iYFloorID,int iMFloorID,CUIntArray &iComTypeArr, BOOL bNeedCover);
	BOOL ImportGJSX2Project_Row(CSQLDataSet * pExternComponentDataSet,int iRow, BOOL bNeedCover,int iMFloorID);
	BOOL ImportGJSX2Project_ComIDArr(CUIntArray & iComIDArr,BOOL bNeedCover);


	CSQLDataSet * GetDataSet();

	CSQLDataSet * GetEmptyDataSet();

	/**
	* @brief   ��ȡ DataSet
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [29/6/2012]
	*/
	BOOL GetDataSet_FloorComType(int iFloorID,int iComType,CSQLDataSet *& pComponentDataSet);

	/**
	* @brief  ��ȡָ�� ComID�� ��¼�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [18/8/2012]
	*/
	BOOL GetTableCtrl_ComID(int iComID,CPMSQLTableCtrl *& pSQLTableCtrl);
private:
	/**
	*  @brief : ��ȡcustomizesteeldiagram�����е����ֵ
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2017/1/3 10:58
	*/
	CString GetMaxColValue(const CString& strColName);
	/**
	*  @brief : ��customizesteeldiagram���в����¼
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2017/1/3 11:00
	*/
	CString InsertProjectCustomizeSteelDiagram(const CString& strTh);
private:
	CSqliteDataBase m_FromProjectDb;
	CSqliteDataBase m_ToProjectDb;
protected:
	/// ˢ�·��������
	void	ReFlashFj() ; 

protected:

	/// �����ӵ�comid
	CPmIntSet		m_setComId ; 

	/// src �� des ��Ӧ��comid
	CPmInt2IntMap  m_mapSrc2DesComId ; 
};

#endif // !defined(AFX_EXTERNCOMPONENTSTABLE_H__1F2A8CAE_20C7_401F_8B1E_2BD5DF3D10F4__INCLUDED_)
