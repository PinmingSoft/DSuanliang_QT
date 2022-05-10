#pragma once
/**
 * @brief  :构件所属 施工段信息 或者构件强制指定的施工段信息
 *
 *          计算钢筋前，将重置非指定的构件的钢筋施工段
 * @author :yjc
 * @version:v1.0
 * @date   :[8/8/2016]
 * @note   :
 */
class PMProjectDBSERVICE CWorkSegInfo
{
public:
	CWorkSegInfo(void);
	~CWorkSegInfo(void);
	struct GJINFO
	{
		int iComId;
		CString strCadHandle;
		int m_iRuleId;
		int m_iComId_SGD;
		BOOL m_bAssign;
		GJINFO()
		{
			iComId = 0;
			m_iRuleId = 0;
			m_iComId_SGD = 0;
			m_bAssign = FALSE;
		}
	};
public:
	static CString GetKey(const int iComid,const CString& strCadHandle,const int iRuleId){return pmcommon::CStr(iComid)+_T("|")+strCadHandle+_T("|")+pmcommon::CStr(iRuleId);}
	/**
	*  @brief : 插入构件施工段信息记录
	*
	*
	*  @note	iRuleId: 钢筋施工段必须为9999;
						 算量施工段不能为9999;
	*  @param : bAssign 表示是否是指定的
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/6/29 16:27
	*/
	void InsertWorkSegInfo(const int iComid,const CString& strCadHandle,const int iRuleId,const int iWorkSegComId,const BOOL bAssign = 0);
	/**
	*  @brief : 以下函数用于删除参数指定的构件施工段信息
	*
	*
	*  @note   iRuleId: 钢筋施工段必须为9999;
						算量施工段不能为9999;
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/6/29 16:38
	*/
	void DeleteWorkSegInfo(const int iWorkSegComId);
	void DeleteWorkSegInfo(const int iComid,const CString& strCadHandle);
	void DeleteWorkSegInfo(const int iComid,const CString& strCadHandle,const int iRuleId);
	void DeleteWorkSegInfo_SL(const int iComid,const CString& strCadHandle);
	void DeleteWorkSegInfo_GJ(const int iComid,const CString& strCadHandle);
	void DeleteWorkSegInfo_NoAssign();

	/**
	*  @brief : 设置构件施工段WorkSegComId
	*
	*
	*  @note	iRuleId: 钢筋施工段必须为9999;
						 算量施工段不能为9999;
				如果表中已经有记录,则修改记录;
				如果表中不存在记录,则添加记录;
	*  @param : bAssign 表示是否是指定的
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/6/29 14:13
	*/
	void SetWorkSegComId(const int iComid,const CString& strCadHandle,const int iRuleId,const int iWorkSegComId,const BOOL bAssign = 0);
	void SetWorkSegComId(const int iComid,const CString& strCadHandle,const int iRuleId,const int iWorkSegComId,const int iWorkSegOrder,const BOOL bAssign);
	void SetWorkSegComId(const CArray<GJINFO *> & arrGJInfo);

	/**
	*  @brief : 获取算量施工段信息
	*
	*
	*  @note	函数会先清空传入的mapRuleId2WorkSegComId
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/6/29 17:53
	*/
	void GetWorkSegInfo_SL(const int iComid,const CString& strCadHandle,std::map<int,int>& mapRuleId2WorkSegComId);
	/**
	*  @brief : 更新施工段顺序
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/9/2 16:11
	*/
	void UpdateWorkSegOrder(const std::map<int,int>& mapComIdToSgdOrder);
	/**
	*  @brief : 获取钢筋施工段信息
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 如果获取失败,则返回-1
	*  @author: yjc
	*  @date  : 2016/6/29 17:45
	*/
	int GetWorkSegInfo_GJ(const int iComid,const CString& strCadHandle);
	/**
	*  @brief : 获取构件对应的施工段是否是被指定的
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: TRUE: 对应的施工段为指定的; 
				FALSE:对应的施工段不是指定的
	*  @author: yjc
	*  @date  : 2016/7/29 11:21
	*/
	BOOL HasAssignWorkSeg(const int iComid,const CString& strCadHandle,const int iRuleId);

	//key 与 assign的匹配
	void GetAssign(std::map<CString,BOOL> & mapAssign);

	/**
	*  @brief : 清理无效的施工段信息
	*
	*
	*  @note	删除那些施工段构件已经被删除的记录
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/7/29 17:10
	*/
	void ClearInvaildWorkSegInfo();
	/**
	*  @brief : 获取算量下对应施工段的构件
	*
	*
	*  @note	
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/7/29 17:10
	*/
	void GetGjFromWorkSeg_SL(const int iWorkSegComid, std::vector<GJINFO>& vecGjInfo);
	// 获取钢筋下对应施工段的构件
	void GetGjFromWorkSeg_GJ(const int iWorkSegComid, std::vector<GJINFO>& vecGjInfo);
	/**
	*  @brief : 根据钢筋计算结果,对相应组合构件的施工段信息进行添加
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/9/2 14:07
	*/
	void AppendCombWorkSegInfo();
private:
	CSqliteDataBase m_Db;	// procject数据库对象
	CSqliteDBStmt m_Stmt;	// 操作数据库的语句对象
};
