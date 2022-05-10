#pragma once
/**
 * @brief  :��¼PCǽ��Ϣ
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
	*  @brief : ����PCǽ��Ϣ��¼
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
	*  @brief : ���º�������ɾ��PCǽ��Ϣ
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
	CSqliteDataBase m_Db;	// procject���ݿ����
	CSqliteDBStmt m_Stmt;	// �������ݿ��������
};
