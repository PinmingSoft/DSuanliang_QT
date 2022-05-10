#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CAccessPublicGj_ComponentsTable :
	public CPMSLAccessTable
{
public:
	CAccessPublicGj_ComponentsTable(void);

	virtual ~CAccessPublicGj_ComponentsTable(void);

	virtual BOOL TryUpdateTableField();

	/**
	* @brief 获取 DataSet   
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	CSQLDataSet * GetDataSet();

	/**
	* @brief 获取所有 记录集   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [20/7/2012]
	*/
	BOOL GetAllRow_TableCtrl(CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief  将 工程中 指定comid 的构件 插入 公共记录中 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	BOOL Insert(int iComID , CString strComName , int &SysComID) ;
	BOOL Insert(int iComID, int &SysComID);
	/**
	* @brief   判断是否 有重名
	*          原采用Comid来判断并不合适,因为无法根据这种额外库中的comid获取对应的comtype
	*          现直接更改为用comtype进行判断 wrq [2017-2-16]
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	BOOL CheckHasSameName(int iComType , CString strComName);

	/**
	* @brief   该函数仅接受工程内的Comid,其他额外的Comid无法识别
	*          
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	BOOL CheckHasSameName(int iComID);

	/**
	* @brief  获取 ComType ComName 对应的记录集 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	BOOL GetTableCtrl_ComTypeComName(int iComType,const CString & strComName,CPMSQLTableCtrl *& pSQLTableCtrl);

	/**
	* @brief 获取 清单 DataSet  
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	NDataModelDataSet * GetQDDEDataSet(int iSysComID);

	/**
	* @brief  获取 VectorParm 
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	NDataModelDataSet * GetVectorParmDataSet(int iSysComID);

	/**
	* @brief  获取参数 总表 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	NDataModelDataSet * GetComParmsDataSet(int iSysComID);
	NDataModelDataSet * GetComParmsDataSet_UI(int iSysComID);

	/// 钢筋状态下的主界面参数
	NDataModelDataSet * GetComParmsDataSet_UI_GJ(int iSysComID);

	/// 获取计算设置参数
	NDataModelDataSet * GetComParmsDataSet_JSSZ(int iSysComID);

	/**
	* @brief   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	BOOL GetComType(int iSysComID,int & iComType);

	/**
	* @brief  删除 指定的 构件 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	BOOL DelSysComponent(int iSysComID);

	/**
	* @brief 设置 自定义钢筋   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	BOOL SetComponentOwnGanJinVector(int iComID,const LPVOID pBuffer,const int iBufferSize);

	BOOL GetComponentOwnGanJinVector(int iComID,LPVOID & pBuffer,long & iBufferSize);

	BOOL RemoveComponentOwnGanJinVector(int iComID);

	/**
	* @brief 通过 指定的 ComID 获取 记录集  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	BOOL GetTableCtrl_ComID(int iSysComID,CPMSQLTableCtrl *& pSQLTableCtrl);
private:
		/**
	*  @brief : 获取数据库中指定字段的逻辑最大值
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/6/17 14:36
	*/
	CString GetMaxColValue(const CString& strColName);
	/**
	*  @brief : 插入数据到PublicGj数据库中的customizesteeldiagram表
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/6/17 14:37
	*/
	CString InsertPublicCustomizeSteelDiagram(const CString& strTh);
	CSqliteDataBase m_PublicDb;		// publicgj 数据库
	CSqliteDataBase m_ProjectDb;	// project 数据库
};
