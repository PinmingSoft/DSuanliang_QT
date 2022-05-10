#pragma once
/**
 * @brief  :�������� ʩ������Ϣ ���߹���ǿ��ָ����ʩ������Ϣ
 *
 *          ����ֽ�ǰ�������÷�ָ���Ĺ����ĸֽ�ʩ����
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
	*  @brief : ���빹��ʩ������Ϣ��¼
	*
	*
	*  @note	iRuleId: �ֽ�ʩ���α���Ϊ9999;
						 ����ʩ���β���Ϊ9999;
	*  @param : bAssign ��ʾ�Ƿ���ָ����
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/6/29 16:27
	*/
	void InsertWorkSegInfo(const int iComid,const CString& strCadHandle,const int iRuleId,const int iWorkSegComId,const BOOL bAssign = 0);
	/**
	*  @brief : ���º�������ɾ������ָ���Ĺ���ʩ������Ϣ
	*
	*
	*  @note   iRuleId: �ֽ�ʩ���α���Ϊ9999;
						����ʩ���β���Ϊ9999;
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
	*  @brief : ���ù���ʩ����WorkSegComId
	*
	*
	*  @note	iRuleId: �ֽ�ʩ���α���Ϊ9999;
						 ����ʩ���β���Ϊ9999;
				��������Ѿ��м�¼,���޸ļ�¼;
				������в����ڼ�¼,����Ӽ�¼;
	*  @param : bAssign ��ʾ�Ƿ���ָ����
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/6/29 14:13
	*/
	void SetWorkSegComId(const int iComid,const CString& strCadHandle,const int iRuleId,const int iWorkSegComId,const BOOL bAssign = 0);
	void SetWorkSegComId(const int iComid,const CString& strCadHandle,const int iRuleId,const int iWorkSegComId,const int iWorkSegOrder,const BOOL bAssign);
	void SetWorkSegComId(const CArray<GJINFO *> & arrGJInfo);

	/**
	*  @brief : ��ȡ����ʩ������Ϣ
	*
	*
	*  @note	����������մ����mapRuleId2WorkSegComId
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/6/29 17:53
	*/
	void GetWorkSegInfo_SL(const int iComid,const CString& strCadHandle,std::map<int,int>& mapRuleId2WorkSegComId);
	/**
	*  @brief : ����ʩ����˳��
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
	*  @brief : ��ȡ�ֽ�ʩ������Ϣ
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: �����ȡʧ��,�򷵻�-1
	*  @author: yjc
	*  @date  : 2016/6/29 17:45
	*/
	int GetWorkSegInfo_GJ(const int iComid,const CString& strCadHandle);
	/**
	*  @brief : ��ȡ������Ӧ��ʩ�����Ƿ��Ǳ�ָ����
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: TRUE: ��Ӧ��ʩ����Ϊָ����; 
				FALSE:��Ӧ��ʩ���β���ָ����
	*  @author: yjc
	*  @date  : 2016/7/29 11:21
	*/
	BOOL HasAssignWorkSeg(const int iComid,const CString& strCadHandle,const int iRuleId);

	//key �� assign��ƥ��
	void GetAssign(std::map<CString,BOOL> & mapAssign);

	/**
	*  @brief : ������Ч��ʩ������Ϣ
	*
	*
	*  @note	ɾ����Щʩ���ι����Ѿ���ɾ���ļ�¼
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2016/7/29 17:10
	*/
	void ClearInvaildWorkSegInfo();
	/**
	*  @brief : ��ȡ�����¶�Ӧʩ���εĹ���
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
	// ��ȡ�ֽ��¶�Ӧʩ���εĹ���
	void GetGjFromWorkSeg_GJ(const int iWorkSegComid, std::vector<GJINFO>& vecGjInfo);
	/**
	*  @brief : ���ݸֽ������,����Ӧ��Ϲ�����ʩ������Ϣ�������
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
	CSqliteDataBase m_Db;	// procject���ݿ����
	CSqliteDBStmt m_Stmt;	// �������ݿ��������
};
