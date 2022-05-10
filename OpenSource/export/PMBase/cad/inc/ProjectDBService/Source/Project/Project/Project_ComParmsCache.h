#pragma once

////#include "..\SysData\AccessSysData_ComParamsSet.h"
#include "AccessProject_ProjectInfoTable.h"
#include "AccessProject_ComponentsTable.h"
#include "PMVectorGraphicCtrl.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////
class PMProjectDBSERVICE CSubComtypeParms
{
public:
	//�洢������
	struct ParmData
	{
		friend CSubComtypeParms;

		//
		int m_nSubCotmype;
		CString m_strParmName;
		CString m_strParmValue;
		CString m_strDisplayName;

		//
		ParmData(const ParmData & data)
		{
			*this = data;
		}
		ParmData(int subcomtype,CString parmname,CString parmvalue,CString displayname,CString invalidmsg,BOOL bHide)
		{
			m_nUseAsBz = FALSE;
			m_bHide = bHide;
			m_nParmType = 0;

			//
			m_nSubCotmype = subcomtype;
			m_strParmName = parmname;
			m_strParmValue = parmvalue;
			m_strDisplayName = displayname;
			SetInvalidMsg(invalidmsg);
		}
		ParmData(int subcomtype,const CParm * pParm)
		{
			m_nUseAsBz = FALSE;
			m_bHide = FALSE;
			m_nParmType = 0;

			//
			m_nSubCotmype = subcomtype;
			m_strParmName = pParm->GetParmName();
			m_strParmValue = pParm->GetParmValue();
			m_strDisplayName = pParm->GetDes();
			SetInvalidMsg(pParm->GetInvalidMsg());
		}
		void operator=(const ParmData & data)
		{
			m_nUseAsBz = data.m_nUseAsBz;
			m_bHide = data.m_bHide;
			m_nSubCotmype = data.m_nSubCotmype;
			m_strParmName = data.m_strParmName;
			m_strParmValue = data.m_strParmValue;
			m_strDisplayName = data.m_strDisplayName;
			SetInvalidMsg(data.m_strInvalidMsg);
			m_nParmType = data.m_nParmType;
		}

		//���� parmType ����/��ȡ
		void SetParmType(int parmType)
		{
			m_nParmType = parmType;
		}
		int GetParmType() const {return m_nParmType;}

		//���� parmValue ����/��ȡ
		CString GetParmValue() const{return m_strParmValue;}
		void	SetParmValue(CString parmValue) {m_strParmValue = parmValue;}

		//��ȡ������
		CString GetParmName() const{return m_strParmName;}

		//��ȡsubcomtype
		int GetSubComtype() const{return m_nSubCotmype;}

		//���� invalidMsg ����/��ȡ
		CString GetInvalidMsg() const{return m_strInvalidMsg;}
		void	SetInvalidMsg(CString invalidMsg);

		//������������
		CString GetDisplayName() const{return m_strDisplayName;}

		/**
		* @brief   ���ò�����Ҫ����Ϊ��ע
		*
		*			nUsedAsBz 0 ��ʾ ������Ϊ��ע
							  1 ��ʾ ����Ϊ��ע
							  -1 ��ʾ ���� -----����״̬�����ڱ����г��֣����������ݼ���ѡʱ����
							  99(kUsedAsBz_Invalid) ��ʾ ��������ʾ ��ע����
		* @note  : �� 1ʱ ����IsUsedAsBz
		* @param : 
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [7/7/2020]
		*/
		BOOL IsUsedAsBz() const;
		int  GetUsedAsBz() const;
		//���ò�����ע---�����������ڳ�ʼ������Ϊ��ʼ������99�����ݴ��룬�����������-1,99����Чֵ
		void SetUsedAsBz(int nUsedAsBz);

		//�����Ƿ�����
		BOOL IsHide() const{return m_bHide;}
		void SetHide(BOOL bHide) {m_bHide = bHide;}

		//ת���ַ���
		CString ToCStr() const
		{
			return m_strParmName + _T("<") + pmcommon::CStr(m_nUseAsBz) + _T(">:") + m_strParmValue;
		}

	private:
		//
		int m_nParmType;
		//�����Ƿ�����
		int m_bHide;
		//�Ƿ����ڲ�������
		int m_nUseAsBz;
		//
		CString m_strInvalidMsg;
	};

	typedef std::map<CString,ParmData *> ParmMap;

	//
	CSubComtypeParms();
	CSubComtypeParms(int subcomtype,const CParms & parms);
	CSubComtypeParms(int subcomtype,const CArray<const ParmData *> & parms);
	~CSubComtypeParms();

	//
	CSubComtypeParms * Clone() const;

	//
	void Append(const CSubComtypeParms * pParms);

	/**
	* @brief   ��Ӳ���
	*
	*			��������Ѵ��ڣ��򷵻�NULL
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/8/2020]
	*/

	ParmData * AddParm(int subcomtype,CString parmname,CString parmvalue,CString displayname,CString invalidmsg,int nUsedAsBz,BOOL bHide);
	ParmData * AddParm(int subcomtype,CString parmname,CString parmvalue,CString displayname,CString invalidmsg,BOOL bHide);
	const ParmData * GetParmData(int subcomtype,CString parmname) const;

	//���ò�����������������ڣ�����FALSE
	BOOL SetParm(int subcomtype,CString parmname,CString parmvalue,CString invalidmsg);
	BOOL SetParm(int subcomtype,CString parmname,CString parmvalue);

	//��ȡ����
	//CParm * GetParm(int subcomtype,CString parmname) const;

	//��������
	//void CopyParmTo(int componenttype,CParms * pParmDes,BOOL bAppend) const;

	//�ж� componenttype �Ƿ��� subcomtypeSrc ƥ��
	static BOOL IsSubComtypeSuit(int componenttype,int subcomtypeSrc);

	//��ȡparmtype
	void SetParmType(int subcomtype,CString parmname,int parmType);
	int GetParmType(int subcomtype,CString parmname) const;

	/**
	* @brief   ���ò�����Ҫ����Ϊ��ע
	*
	*			nUsedAsBz 0 ��ʾ ������Ϊ��ע
						  1 ��ʾ ����Ϊ��ע
						  -1 ��ʾ ����
						  99 ��ʾ ��������ʾ ��ע����
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/7/2020]
	*/
	BOOL SetUsedAsBz(CString parmname,int nUsedAsBz);
	BOOL SetUsedAsBz(int subcomtype,CString parmname,int bUsedAsBz);
	void ClearAllUsedAsBz();

	//
	BOOL SetHide(int subcomtype,CString parmname,BOOL bHide);

	//��ȡ��ǰcomponent �� subcomtypeΪ-1 ���Ĳ���ֵ
	CString GetValue(const CString & parmname) const;
	BOOL GetValue(const CString & parmname, CString & parmvalue) const;
	const ParmData * GetParmData(const CString & parmname) const;
	const ParmData * GetParmDataConst(const CString & parmname) const;

	//���õ�ǰcomponent �� subcomtypeΪ-1 ���Ĳ���ֵ
	BOOL SetValue(const CString & parmname, const CString & parmvalue);
	BOOL SetValue(const CString & parmname, const CString & parmvalue, const CString & invalidMsg);

	//��ȡ��Ӧsubcomtype�Ĳ���ֵ
	BOOL GetValue(int subcomtype,const CString & parmname, CString & parmvalue) const;
	//���ö�Ӧsubcomtype�Ĳ���ֵ
	BOOL SetValue(int subcomtype,const CString & parmname, const CString & parmvalue);

	//ͨ��componentType����ֵȥ�Ҷ�Ӧ�ĸ�������
	BOOL GetValueForComponentType(int componentType,const CString & parmname, CString & parmvalue) const;

	//�������
	void Clear();

	//��ȡ��Ҫ����Ϊ�������ӵĲ���
	void GetParmUsedAsBz(std::set<CString> & parms) const;
	BOOL IsParmUsedAsBz(const CString & parmname) const;

	//��ȡ��ǰʹ�õ����в���
	void GetParmCurrent(std::map<CString,CString> & maps) const;
	void GetParmCurrentSorted(CArray<const CSubComtypeParms::ParmData *> & parms) const;

	//��ӡ��ǰ������Ϣ 
	CString GetParmCurrentInfo() const;

	//��ȡcomponentType
	int GetComponentType() const{return m_nComponentType;}

protected:
	CSubComtypeParms::ParmData * CloneParmTo(const ParmData * pParmSrc,CSubComtypeParms * pParmsDes) const;
	ParmData * GetParmData(int subcomtype,CString parmname);
	ParmData * GetParmData(CString parmname) ;

private:
	int m_nComponentType;

	//��������Ĳ���,CParm ָ���� m_mapSubcomtype2Parms һ��
	CArray<const ParmData *> m_arrParms;

	//����洢����,key ֵΪ comtype|parmname ��ƥ��
	std::map<int,ParmMap *> m_mapSubcomtype2Parms;
};

typedef CArray<CSubComtypeParms::ParmData *> ParmDataArray;
typedef CArray<const CSubComtypeParms::ParmData *> ParmDataConstArray;

class PMProjectDBSERVICE CSLComponentManager
{
public:
	class PMProjectDBSERVICE CComponentInfo
	{
	public:
		CComponentInfo(int comid,int iComType,int iFloorID) : /*m_pComParmDataSet(NULL) */m_pVectorEntityInfo(NULL)
		{
			m_iComid = comid;
			m_iComType = iComType;
			m_iFloorID = iFloorID;
			m_bComParmHasChange = FALSE;
			m_bPublicGj = FALSE;
			m_pParms = NULL;
			m_pVectorParms.reset();
		}

		virtual ~CComponentInfo()
		{
			//if(NULL != m_pComParmDataSet)
			//{
			//	PMDelete(m_pComParmDataSet);
			//	m_pComParmDataSet = NULL ; 
			//}
			if(NULL != m_pVectorEntityInfo)
			{
				PMDelete(m_pVectorEntityInfo);
				m_pVectorEntityInfo = NULL ; 
			}
			//
			PMDelete(m_pParms);
			m_pVectorParms->RemoveAll();
		}

		/// ��ʼ�����в���,û�г�ʼ�������������������Parm�����û��߻�ȡ����ʧ��
		void AttachParms(CSubComtypeParms * pParmsAll);

		/**
		* @brief    Ӧ�ü�¼��������,���û�г�ʼ��������������FALSE
		*
		*			ע�⣺���������ܵ��¶������----���������ظ���������ȷʵ��������Ҫ������componenttype�޸ĺ��µ�
		* @note  : 
		* @param : 
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [10/10/2019]
		*/
		BOOL ApplyDatasetToParms(NDataModelDataSet * pDatasetParms,int componenttype,BOOL appendNew);

		/// ��ȡ/���ò���
		const CSubComtypeParms * GetXParms() const{return m_pParms;}
		void SetComParmValue(CString parmName,CString parmValue);
		void SetComParmValue(CString parmName,CString parmValue,CString invalidMsg);
		void SetComParmValue(int subcomtype,CString parmName,CString parmValue,CString invalidMsg,BOOL bUsedAsBz);
		void SetComParmValue(int subcomtype,CString parmName,CString parmValue,CString invalidMsg);

		/// ��ȡ/���ò�����������
		void SetComParmUltraAttr(int subcomtype,CString parmName,BOOL bUsedAsBz);
		
		//�����Ų�����ָ���ȡ����ֹû�г�ʼ������������������ò������������
		//PMShared_Ptr<CParms> GetParmsPtr() const{return m_pParms;}
		//void SetParmsPtr(ParmsPtr parms){m_pParms = parms;}

		/// ��ȡ/���ý���ͼ����
		const CParms * GetVectorParms() const{return m_pVectorParms.get();}
		PMShared_Ptr<CParms> GetVectorParmsPtr() const{return m_pVectorParms;}
		void SetVectorParmsPtr(PMShared_Ptr<CParms> parms){m_pVectorParms = parms;}
		void SetVectorParms(const CProject_VectorParmsTable * pVectorParms);
		BOOL GetVectorParmValue(CString parmName,CString & parmValue) const;
		//ɾ��ʸ��ͼ�����Ϣ����ͨ���ڸ����˽���ͼʱ����
		void ClearVectorInfo()
		{
			PMDelete(m_pVectorEntityInfo);
			m_pVectorParms->RemoveAll();
		}
		void ClearParms()
		{
			PMDelete(m_pParms);
			m_pVectorParms->RemoveAll();
		}

		/// ��ȡ datasetָ�룬�������ò���ɾ��
 		NDataModelDataSet * GetComParmSetPtr() const
 		{
 			return m_pComParmDataSet.get();
 		}

		PMShared_Ptr<NDataModelDataSet> GetComParmSet() const
		{
			return m_pComParmDataSet;
		}
		//��������
		void SetComParmSet(PMShared_Ptr<NDataModelDataSet> pComParmSet);

		//�ͷŲ�������
		void FreeComParmSet();

		BOOL CheckNeedSave()
		{
			return m_bComParmHasChange;
		}

		void SetComParm_SaveMode(BOOL bNeedSave)
		{
			m_bComParmHasChange = bNeedSave;
		}

		/**
		* @brief ��ȡ���ͼ������Ϣ   
		*
		*          
		* @note  : 
		* @param : 
		* @defenc: 
		* @return: 
		* @author: ����ҵ
		* @date  : [9/7/2012]
		*/
		const CPMVectorEntityInfo * GetVectorEntityInfo()
		{
			return m_pVectorEntityInfo;
		}

		/**
		* @brief  �������ͼ ������Ϣ 
		*
		*          
		* @note  : 
		* @param : 
		* @defenc: 
		* @return: 
		* @author: ����ҵ
		* @date  : [9/7/2012]
		*/
		void SetVectorEntityInfo(CPMVectorEntityInfo * pVectorDataSet)
		{
			m_pVectorEntityInfo = pVectorDataSet;
		}
		void FreeVectorEntityInfo()
		{
			PMDelete(m_pVectorEntityInfo);
			m_pVectorEntityInfo = NULL;
		}

		int GetComId() const {return m_iComid;}
		int GetComType() const {return m_iComType;}
		int GetFloorID() const {return m_iFloorID;}

		//��ȡ/��������
		CString GetComName() const {return m_strComName;}
		void SetComName(const CString & strComName) {m_strComName = strComName;}

		//��ȡ����ֵ
		BOOL GetParmValue(CString parmName,CString & parmValue) const;
		BOOL GetParmValueFromComponentType(int componentType,CString parmName,CString & parmValue) const;

		//��ȡ/���ñ�ע
		CString GetBz() const {return m_strBz;}
		void SetBz(const CString & bz) {m_strBz = bz;}

		//ˢ�±�ע��Ϣ
		void RefreshBz();

		//�Ƿ��ʼ���˲���
		BOOL IsParmsHasInit() const {return m_pParms?TRUE:FALSE;}
		
		//���ò������Ƿ񸽼ӵ� ��ע����Ϣ
		void AppendParmBz(int subcomtype,const CString parmName,BOOL bUsedAsBz);
		void SetParmBz(int subComtype,const CString parmName,BOOL bUsedAsBz);

		/**
		* @brief   ���õ�ǰ�����ı�ע��Ϣ����Щ�����ж��ͬ��������ʹ���ڲ�ͬsubComtype�£�
		*
		*			ע�⣺�ǵ�ǰʹ�ò���������ʹ�ñ�������������
		* @note  : 
		* @param : 
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [9/23/2020]
		*/
		void SetParmBzCurrent(const CString parmName,BOOL bUsedAsBz);

		//������ͱ�ע
		void ClearParmBz();
		//��ʼ���������Ƿ񸽼ӵ� ��ע����Ϣ
		//void InitParmBz(const std::set<CString> & setParmsName);
		//��ȡ��Ҫ���ӵ���ע�Ĳ�����
		void GetParmHasBz(std::set<CString> & setParmsName) const;
		//�Ƿ��������Ϊ��עʹ��
		BOOL IsParmUsedAsBz(const CString parmName) const;

		//��ȡ�����ı�ע
		CString GetParmBz() const{return m_strParmBz;}

		/// ��ȡ��ע���޸��˵Ĳ�����
		void GetParmCurrentChangedBz(CArray<const CSubComtypeParms::ParmData *> & parms) const;
		
		//��ȡ/���ù�������
		BOOL IsPublicGj() const{return m_bPublicGj;}
		void SetPublicGj(BOOL bPublicGj){m_bPublicGj = bPublicGj;}


	private:
		//��ֹ�����ڲ������ӵĲ����ж�
		BOOL IsParmUnPermitUsedAsBz(const CString parmName) const;

		//��ȡ��������ʾֵ
		CString GetParmDisplayValue(CString parmName,CString parmValue) const;
		BOOL ChangeDisplayText(const CString & parmName, const CString & orignValue, int iComId , CString & displayValue) const;

	private:
		int m_iComid;
		int m_iComType;
		int m_iFloorID;
		CString m_strComName;
		BOOL m_bPublicGj;	//�Ƿ��ǹ�������
		CString m_strBz;	//��ע��Ϣ
		CString m_strParmBz;//�����ı�ע��Ϣ

		//��������
		CSubComtypeParms * m_pParms;

		//����ͼ��������
		PMShared_Ptr<CParms> m_pVectorParms;

		// ����ָ�룬��Ϊ������dataset���ǹ���ָ��
		PMShared_Ptr<NDataModelDataSet>	m_pComParmDataSet;
		BOOL				m_bComParmHasChange;//�������Ƿ���Ҫ����

		CPMVectorEntityInfo * m_pVectorEntityInfo;//���ͼ����
	};

	typedef std::map<int,CComponentInfo*>	ComIDMapComponentInfo_T;
	typedef ComIDMapComponentInfo_T::iterator	ComIDMapComponentInfo_TIter ;

	static CSLComponentManager * Instance()
	{
		if(NULL == m_pInstance)
		{
			m_pInstance = PMNew(CSLComponentManager);
		}
		return m_pInstance;
	}

	static void Release()
	{
		if(NULL != m_pInstance)
		{
			PMDelete(m_pInstance);
		}
		m_pInstance = NULL;
	}

	

	/**
	* @brief ��ȡ ComType 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	BOOL GetComType(int iComID,int & iComType);
	int	 GetComType( const int iComId ) ; 

	/**
	* @brief   ��ȡ¥��id
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2012-7-16]
	*/
	BOOL	GetFloorId( const int iComID , int & iFloorID ) ;
	int		GetFloorId( const int iComId ) ;

	//��ȡ��������
	BOOL	GetComName( const int iComId , CString & strComName ) ; 
	CString GetComName( const int iComId ) ;

	//���ù�������
	BOOL SetComName(int iComId,const CString & strComName);

	//ͨ��
	BOOL GetParmValue(int iComId,CString parmName,CString & parmValue) ;
	BOOL GetParmValue(int iComId,int componentType,CString parmName,CString & parmValue) ;

	//�ж��Ƿ񹫹�����
	BOOL IsPublicGj(int iComId);

	//���ù�������
	BOOL SetPublicGj(int iComId,BOOL bPublic);
	BOOL SetPublicGj(const CUIntArray & arrComId,BOOL bPublic);

	//ԭ����ʽ�µı�ע,Ŀǰ������ʹ�õ���parmbz����������п���ʹ��ԭ���ı�ע
	CString GetBz(int iComId);

	//���ò����Ƿ��ʹ��Ϊ��ע����������ı�ע��Ϣ
	CString SetParmBz(int iComId,CString parmName,BOOL bUsedAsBz);

	//�ж�ĳ�������Ƿ��ǲ������ӱ�ע
	BOOL IsParmUsedAsBz(int iComId,CString parmName) ;
	//��ȡ�������ӱ�ע������Ϣ
	CString GetParmBz(int iComId);
	//���������ע
	void ClearParmBz(int iComId);

	/**
	* @brief  ��ȡ ���� ������Ϣ 
	*
	*          
	* @note  : ���ص�DataSet ,��Ϊ CPmComParmsDataSet ��Ϊ����ָ����� ������ CComponentInfo::m_pComParmDataSet ָ�����.
	*			��Ҫɾ������ʹɾ������Ҳ������ɾ�� CComponentInfo::m_pComParmDataSet ָ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [18/5/2012]
	*/
	BOOL GetComParmDataSet(int iComID,NDataModelDataSet *& pComParmSet);

	//�����ݿ��ȡ����������dataset�������ڴ��й�Ϊ����ָ��
	PMShared_Ptr<NDataModelDataSet> CreateComParmDataSet(int iComID);

	/**
	* @brief  ���� ���� ������Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [18/5/2012]
	*/
	BOOL SetComParmDataSet(int iComID,NDataModelDataSet * pComParmSet);

	/**
	* @brief   ��������
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/21/2020]
	*/
	BOOL CopyParm(int comidFrom,int comidTo);

	/**
	* @brief  ��ȡ ������ ���ͼ��Ϣ 
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [19/7/2012]
	*/
	BOOL GetVectorParmDataSet(int iComID,CProject_VectorParmsTable *& pComParmSet);

	/**
	* @brief  �������ͼDataSet��Ϣ 
	*
	*          
	* @note  : ��Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	BOOL SetVectorParmDataSet(int iComID,CProject_VectorParmsTable * pVectorDataSet);

	BOOL GetVectorParmValue(int iComID,const CString & strParmName,CString & strParmValue);

	/**
	* @brief ���� ָ��ComID�� ͼ����  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [24/7/2012]
	*/
	BOOL SetVectorParm(int iComID,const CString & strParmName,const CString & strParmValue);

	/**
	* @brief ���ڼ�������� ��ռ�ڴ��С  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [21/5/2012]
	*/
	void CalComParmMemSize();

	/**
	* @brief   ������� ��ռ�ڴ�
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [21/5/2012]
	*/
	void FreeComponentMem();

	void FreeComponentMem( const int iComId ) ;

	void FreeComponentMem_FloorId(const int floorid) ;

	void FreeComponentMem( const CUIntArray & aryComId ) ; 

	//ˢ�²����ڴ�
	void FreeComponentParmMem();
	void FreeComponentParmMem(int comid);

	/**
	* @brief �޸�Comid����(���л��ֽ���Ϣʱ,��Щ���ݻᱻ��©)
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ǿ
	* @date  : [2016-12-30]
	*/
	void Repair_ComponentInfo( const int iComId, NDataModelDataSet * pComParmSet);

	/**
	* @brief ��ȡ��ǰ���̵� �ֽ�ģʽ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [5/7/2012]
	*/
	ProjectInfoMacro::GangJinMode GetProjectGangJinMode();

	// �������ֵ����Ҫ�����ȡ������  wrq [2017-2-10]
	void SetProjectGangJinMode(ProjectInfoMacro::GangJinMode gangjinMode);

	/// ��Ӹ����ӿ�
	/// ����������� 
	/// ��16G��ӵĹ�ϵ,����IsGreaterThan03G�������ж�
	BOOL	Is11G() ;

	/// �Ƿ����03G(������03G)
	BOOL	IsGreaterThan03G();

	/**
	* @brief ��ȡ���ͼ������Ϣ   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	const CPMVectorEntityInfo * GetVectorEntityInfo(int iComID);

	/**
	* @brief  �������ͼ ������Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	BOOL SetVectorEntityInfo(int iComID,NDataModelDataSet * pVectorDataSet);

	/**
	* @brief  ��ȡ������Ϣ
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/7/2012]
	*/
	const CComponentInfo * GetComponentInfo_const(int iComID);

	/**
	* @brief   ��ȡ ��ǰ�� ѡ����Ϣ
	*
	*          
	* @note  : ���ص�ǰѡ�е� ComID����FloorID
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	int GetCurFloorID()
	{
		return m_iCurFloorID;
	}

	int GetCurComID()
	{
		return m_iCurComID;
	}

	int GetCurComType()
	{
		return CSLComponentManager::Instance()->GetComType(m_iCurComID);
	}

	CString GetCurComName()
	{
		return CSLComponentManager::Instance()->GetComName(m_iCurComID);
	}
	

	/**
	* @brief ���õ�ǰ�� ComID  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	BOOL SetCurComID(int iCurComID);

	BOOL SetCurFloorID(int iCurFloorID);

	/**
	* @brief ���Ը� pComponentInfo��� �������� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [16/7/2012]
	*/
	BOOL Try_InitComParmSetCache(int iComID,CSLComponentManager::CComponentInfo * pComponentInfo);

	/**
	* @brief  ��ȡ������Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [18/5/2012]
	*/
	CComponentInfo * GetComponentInfo(int iComID);

	/// ��ȡ����ComponentInfo
	void GetComponentInfo(const CUIntArray & arrComid);
	void GetComponentInfoAll();

	/**
	* @brief   ˢ�¹�����Ϣ������Ѵ��ڣ�����ӹ������������������ʱ������в������滻��������������ʱ�����й�����Ϣ�����
	*
	*			qc:30360���������õ�okʱ���ܴ���
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/26/2020]
	*/
	void UpdateComponentInfoAll();

	void UpdateComParmsSet_Comid_before();
	void UpdateComParmsSet_Comid_after();

	/// ��ȡĳ��comtype������comid
	void GetComIdOnFloor(int floorid,int comtype,std::set<int> & setComid) const;

	/**
	* @brief  ��ȡָ�� �������͵� ������ (Ĭ�ϲ���)
	*
	*          
	* @note  : ��Ҫ ɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/7/2012]
	*/
	BOOL GetComParmsDataSet_ComType(int iComType,NDataModelDataSet *& pComParmsDataSet);
	BOOL GetComParmsDataSet_ComType(int iComType,CUIntArray & iParmTypeArr,NDataModelDataSet *& pComParmsDataSet);

	/**
	* @brief  ��ȡ������� DataSet
	*
	*          
	* @note  : ��Ҫ ɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [17/7/2012]
	*/
	NDataModelDataSet * GetJsgzDataSet();

	BOOL GetComParms_TotalTable_ParmValue(const CString & strParmName,CString & strParmValue);

	/**
	* @brief   
	*
	*          
	* @note  : �ⲿ�� ����ʹ�� �������
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [23/7/2012]
	*/
// 	CComParmsCache * GetComParmsCacheCtrl()
// 	{
// 		return &m_ComParmsCache;
// 	}

	/**
	* @brief ��ȡĬ�ϵ� �����ܱ�  
	*
	*          
	* @note  : ��Ҫ����һЩ�����޸ģ���Ҫɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [23/7/2012]
	*/
	BOOL GetDefComParmDataSet(NDataModelDataSet *& pComParmDataSet);

	//������ �ָ�Ĭ��
// 	BOOL ComParmsSetTable_Resume();
// 	BOOL ComParmsSet_TotalTable_Resume();

	BOOL DelComponent_ID( const int iComID);

	BOOL DelComponent_ID( const CUIntArray & aryComId );

	/**
	* @brief  ���Ŀǰ���治̫���ӣ����л��汣��ŵ� �������ִ�� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/7/2012]
	*/
	BOOL SaveProject();
	
	/**
	*  @brief : �ѹ�����Ϣ���浽���ݿ�
	*
	*
	*  @note
	*  @param : 
	*  @defenc: 
	*  @return: 
	*  @author: yjc
	*  @date  : 2018/4/18 14:47
	*/
	void SaveComponentInfo();
	/**
	* @brief  �����û����̵� �����ܱ� 
	*
	*          
	* @note  : Ŀǰֻ�ڹ��������е���
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [2/8/2012]
	*/
	//BOOL SaveDefComParmsDataSet();

	/**
	* @brief �ж� װ�� ���� �Ƿ����ɾ��  
	*
	*          
	* @note  : װ�ι������ڱ��������ú󣬲���ɾ��
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҫ
	* @date  : [2014��5��23��]
	*/
	BOOL CanZsDel( const int iComId ); 
public:
	//���εĳ�����
	struct BornPt
	{
		double BornPt_X;
		double BornPt_Y;
		BornPt()
		{
			BornPt_X = 0.0;
			BornPt_Y = 0.0;
		}
		void operator =(const BornPt& pt)
		{
			BornPt_X = pt.BornPt_X;
			BornPt_Y = pt.BornPt_Y;
		}
	};
	/**
	 * @brief  :��Ļ�ȡ������
	 *
	 * ��ϸ����:hoops���ι���Ӧ��
	 * @author zyj
	 * @version v1.0
	 * @date  2015/5/6 14:54
	 * @note  :
	 */
	BornPt GetPtBorn();
	void SetPtBorn(const BornPt& pt);

protected:

	CSLComponentManager();
	virtual ~CSLComponentManager();

public:
	/**
	* @brief  ����Ĭ�ϲ�����Ϣ 
	*
	*          
	* @note  : ֻ������� ����ʱ
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [5/7/2012]
	*/
	BOOL SetDefaultComParmValue(int iComID,int iComType,int iFloorID,NDataModelDataSet * pComParmsSet);
	BOOL DelComponent_IDNew( const int iComID);
	BOOL DelComponent_IDNew( const CUIntArray & aryComId );

protected:

	BOOL GetFloorGJXX_ParmValue(const int & nFloor, const int & nComType , const CString & strParmName ,CString & strValue,CPMSQLTableCtrl * pFloorGJXXTableCtrl) ;

	BOOL Get03GFloorMGDJValue(int iFloorID,int iComType,const CString & strParmName,CString & strParmValue);

	BOOL Get11GFloorMGDJValue(int iFloorID,int iComType,const CString & strParmName,CString & strParmValue);

	//
	void CSLComponentManager::BuildVectorEntityInfoAll(const CUIntArray & arrComID);

	//��ȡʸ��ͼ����(��������ֵ)
	BOOL BuildVectorParmStringMap(int iComID,ParmsMapInfo_T & comParmsMap);
	void BuildVectorParmStringMap(int iComID,const CParms * pVectorParms,ParmsMapInfo_T & comParmsMap);

	//��ȡ���Բ���
	void BuildComParmStringMap(int iComID,const NDataModelDataSet * pComParmDataSet,ParmsMapInfo_T & comParmsMap);
	void BuildComParmStringMap(int iComID,const CSubComtypeParms * pComParms,ParmsMapInfo_T & comParmsMap) const;

private:

	BOOL ChangeSpecVectorParm_RFQ(const CPMVectorEntityInfo * pNewVectorInfo,ParmsMapInfo_T & comParmsMap);
	static CSLComponentManager * m_pInstance;

	//CComParmsCache m_ComParmsCache;

	ComIDMapComponentInfo_T m_MapComponents;

	ProjectInfoMacro::GangJinMode m_gangjinMode;//��ǰ�ĸֽ�ģʽ

	int m_iCurFloorID;//��ǰ¥��ID
	int m_iCurComID;//��ǰ�Ĺ���ID

	BornPt m_BornPt;
};
