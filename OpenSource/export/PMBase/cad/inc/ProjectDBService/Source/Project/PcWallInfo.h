#pragma once
/**
 * @brief  :记录PC墙信息
 *
 *          
 * @author :yjc
 * @version:v1.0
 * @date   :[8/8/2016]
 * @note   :
 */
class PMProjectDBSERVICE CPcWallInfo
{
public:
	CPcWallInfo(void);
	~CPcWallInfo(void);
public:
	/**
	*  @brief : 插入PC墙信息记录
	*
	*
	*  @note
			
	*  @param :
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/6/29 16:27
	*/
	void InsertPcWallInfo(const int iFloorId,const CString& strShape,const void* graphbuffer,const int nByte,
							const CString& strThickness,const CString& strPosition);
	/**
	*  @brief : 以下函数用于删除PC墙信息
	*
	*
	*  @note   
				
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/6/29 16:38
	*/
	void DeletePcWallInfo();
	void DeletePcWallInfo(const int iFloorId);
private:
	CSqliteDataBase m_Db;	// procject数据库对象
	CSqliteDBStmt m_Stmt;	// 操作数据库的语句对象
};
