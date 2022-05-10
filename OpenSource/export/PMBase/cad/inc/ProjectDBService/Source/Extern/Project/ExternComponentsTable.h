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
	* @brief  获取自定义钢筋 Vector信息 
	*
	*          
	* @note  :返回 记录集 需要删除 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
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
	* @brief   获取 DataSet
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [29/6/2012]
	*/
	BOOL GetDataSet_FloorComType(int iFloorID,int iComType,CSQLDataSet *& pComponentDataSet);

	/**
	* @brief  获取指定 ComID的 记录集 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [18/8/2012]
	*/
	BOOL GetTableCtrl_ComID(int iComID,CPMSQLTableCtrl *& pSQLTableCtrl);
private:
	/**
	*  @brief : 获取customizesteeldiagram表中列的最大值
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
	*  @brief : 在customizesteeldiagram表中插入记录
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
	/// 刷新房间的属性
	void	ReFlashFj() ; 

protected:

	/// 新增加的comid
	CPmIntSet		m_setComId ; 

	/// src 到 des 对应的comid
	CPmInt2IntMap  m_mapSrc2DesComId ; 
};

#endif // !defined(AFX_EXTERNCOMPONENTSTABLE_H__1F2A8CAE_20C7_401F_8B1E_2BD5DF3D10F4__INCLUDED_)
