#pragma once

////#include "..\SysData\AccessSysData_ComParamsSet.h"
#include "AccessProject_ProjectInfoTable.h"
#include "AccessProject_ComponentsTable.h"
#include "PMVectorGraphicCtrl.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////
class PMProjectDBSERVICE CSubComtypeParms
{
public:
	//存储行数据
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

		//参数 parmType 设置/获取
		void SetParmType(int parmType)
		{
			m_nParmType = parmType;
		}
		int GetParmType() const {return m_nParmType;}

		//参数 parmValue 设置/获取
		CString GetParmValue() const{return m_strParmValue;}
		void	SetParmValue(CString parmValue) {m_strParmValue = parmValue;}

		//获取参数名
		CString GetParmName() const{return m_strParmName;}

		//获取subcomtype
		int GetSubComtype() const{return m_nSubCotmype;}

		//参数 invalidMsg 设置/获取
		CString GetInvalidMsg() const{return m_strInvalidMsg;}
		void	SetInvalidMsg(CString invalidMsg);

		//参数中文描述
		CString GetDisplayName() const{return m_strDisplayName;}

		/**
		* @brief   设置参数需要附加为备注
		*
		*			nUsedAsBz 0 表示 不设置为备注
							  1 表示 设置为备注
							  -1 表示 多种 -----这种状态不会在本类中出现，仅会在数据集多选时出现
							  99(kUsedAsBz_Invalid) 表示 不允许显示 备注方框
		* @note  : 仅 1时 才是IsUsedAsBz
		* @param : 
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [7/7/2020]
		*/
		BOOL IsUsedAsBz() const;
		int  GetUsedAsBz() const;
		//设置参数备注---本函数不用于初始化，因为初始化会有99等数据传入，本函数会过滤-1,99等无效值
		void SetUsedAsBz(int nUsedAsBz);

		//参数是否隐藏
		BOOL IsHide() const{return m_bHide;}
		void SetHide(BOOL bHide) {m_bHide = bHide;}

		//转化字符串
		CString ToCStr() const
		{
			return m_strParmName + _T("<") + pmcommon::CStr(m_nUseAsBz) + _T(">:") + m_strParmValue;
		}

	private:
		//
		int m_nParmType;
		//参数是否隐藏
		int m_bHide;
		//是否用于参数附加
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
	* @brief   添加参数
	*
	*			如果参数已存在，则返回NULL
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/8/2020]
	*/

	ParmData * AddParm(int subcomtype,CString parmname,CString parmvalue,CString displayname,CString invalidmsg,int nUsedAsBz,BOOL bHide);
	ParmData * AddParm(int subcomtype,CString parmname,CString parmvalue,CString displayname,CString invalidmsg,BOOL bHide);
	const ParmData * GetParmData(int subcomtype,CString parmname) const;

	//设置参数，如果参数不存在，返回FALSE
	BOOL SetParm(int subcomtype,CString parmname,CString parmvalue,CString invalidmsg);
	BOOL SetParm(int subcomtype,CString parmname,CString parmvalue);

	//获取参数
	//CParm * GetParm(int subcomtype,CString parmname) const;

	//拷贝参数
	//void CopyParmTo(int componenttype,CParms * pParmDes,BOOL bAppend) const;

	//判断 componenttype 是否与 subcomtypeSrc 匹配
	static BOOL IsSubComtypeSuit(int componenttype,int subcomtypeSrc);

	//获取parmtype
	void SetParmType(int subcomtype,CString parmname,int parmType);
	int GetParmType(int subcomtype,CString parmname) const;

	/**
	* @brief   设置参数需要附加为备注
	*
	*			nUsedAsBz 0 表示 不设置为备注
						  1 表示 设置为备注
						  -1 表示 多种
						  99 表示 不允许显示 备注方框
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

	//获取当前component 与 subcomtype为-1 类别的参数值
	CString GetValue(const CString & parmname) const;
	BOOL GetValue(const CString & parmname, CString & parmvalue) const;
	const ParmData * GetParmData(const CString & parmname) const;
	const ParmData * GetParmDataConst(const CString & parmname) const;

	//设置当前component 与 subcomtype为-1 类别的参数值
	BOOL SetValue(const CString & parmname, const CString & parmvalue);
	BOOL SetValue(const CString & parmname, const CString & parmvalue, const CString & invalidMsg);

	//获取对应subcomtype的参数值
	BOOL GetValue(int subcomtype,const CString & parmname, CString & parmvalue) const;
	//设置对应subcomtype的参数值
	BOOL SetValue(int subcomtype,const CString & parmname, const CString & parmvalue);

	//通过componentType参数值去找对应的附属参数
	BOOL GetValueForComponentType(int componentType,const CString & parmname, CString & parmvalue) const;

	//清除内容
	void Clear();

	//获取需要设置为参数附加的参数
	void GetParmUsedAsBz(std::set<CString> & parms) const;
	BOOL IsParmUsedAsBz(const CString & parmname) const;

	//获取当前使用的所有参数
	void GetParmCurrent(std::map<CString,CString> & maps) const;
	void GetParmCurrentSorted(CArray<const CSubComtypeParms::ParmData *> & parms) const;

	//打印当前参数信息 
	CString GetParmCurrentInfo() const;

	//获取componentType
	int GetComponentType() const{return m_nComponentType;}

protected:
	CSubComtypeParms::ParmData * CloneParmTo(const ParmData * pParmSrc,CSubComtypeParms * pParmsDes) const;
	ParmData * GetParmData(int subcomtype,CString parmname);
	ParmData * GetParmData(CString parmname) ;

private:
	int m_nComponentType;

	//所有有序的参数,CParm 指针与 m_mapSubcomtype2Parms 一致
	CArray<const ParmData *> m_arrParms;

	//有序存储参数,key 值为 comtype|parmname 的匹配
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

		/// 初始化所有参数,没有初始化过参数，则下面关于Parm的设置或者获取都会失败
		void AttachParms(CSubComtypeParms * pParmsAll);

		/**
		* @brief    应用记录集到参数,如果没有初始化过参数，返回FALSE
		*
		*			注意：本函数可能导致多余参数----但不会有重复参数或者确实参数，主要发生在componenttype修改后导致的
		* @note  : 
		* @param : 
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [10/10/2019]
		*/
		BOOL ApplyDatasetToParms(NDataModelDataSet * pDatasetParms,int componenttype,BOOL appendNew);

		/// 获取/设置参数
		const CSubComtypeParms * GetXParms() const{return m_pParms;}
		void SetComParmValue(CString parmName,CString parmValue);
		void SetComParmValue(CString parmName,CString parmValue,CString invalidMsg);
		void SetComParmValue(int subcomtype,CString parmName,CString parmValue,CString invalidMsg,BOOL bUsedAsBz);
		void SetComParmValue(int subcomtype,CString parmName,CString parmValue,CString invalidMsg);

		/// 获取/设置参数额外属性
		void SetComParmUltraAttr(int subcomtype,CString parmName,BOOL bUsedAsBz);
		
		//不开放参数的指针获取，防止没有初始化参数而进行随便设置参数的情况发生
		//PMShared_Ptr<CParms> GetParmsPtr() const{return m_pParms;}
		//void SetParmsPtr(ParmsPtr parms){m_pParms = parms;}

		/// 获取/设置截面图参数
		const CParms * GetVectorParms() const{return m_pVectorParms.get();}
		PMShared_Ptr<CParms> GetVectorParmsPtr() const{return m_pVectorParms;}
		void SetVectorParmsPtr(PMShared_Ptr<CParms> parms){m_pVectorParms = parms;}
		void SetVectorParms(const CProject_VectorParmsTable * pVectorParms);
		BOOL GetVectorParmValue(CString parmName,CString & parmValue) const;
		//删除矢量图相关信息，其通常在更改了截面图时触发
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

		/// 获取 dataset指针，仅供设置不能删除
 		NDataModelDataSet * GetComParmSetPtr() const
 		{
 			return m_pComParmDataSet.get();
 		}

		PMShared_Ptr<NDataModelDataSet> GetComParmSet() const
		{
			return m_pComParmDataSet;
		}
		//参数设置
		void SetComParmSet(PMShared_Ptr<NDataModelDataSet> pComParmSet);

		//释放参数设置
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
		* @brief 获取配筋图绘制信息   
		*
		*          
		* @note  : 
		* @param : 
		* @defenc: 
		* @return: 
		* @author: 王建业
		* @date  : [9/7/2012]
		*/
		const CPMVectorEntityInfo * GetVectorEntityInfo()
		{
			return m_pVectorEntityInfo;
		}

		/**
		* @brief  设置配筋图 绘制信息 
		*
		*          
		* @note  : 
		* @param : 
		* @defenc: 
		* @return: 
		* @author: 王建业
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

		//获取/设置名称
		CString GetComName() const {return m_strComName;}
		void SetComName(const CString & strComName) {m_strComName = strComName;}

		//获取参数值
		BOOL GetParmValue(CString parmName,CString & parmValue) const;
		BOOL GetParmValueFromComponentType(int componentType,CString parmName,CString & parmValue) const;

		//获取/设置备注
		CString GetBz() const {return m_strBz;}
		void SetBz(const CString & bz) {m_strBz = bz;}

		//刷新备注信息
		void RefreshBz();

		//是否初始化了参数
		BOOL IsParmsHasInit() const {return m_pParms?TRUE:FALSE;}
		
		//设置参数的是否附加到 备注的信息
		void AppendParmBz(int subcomtype,const CString parmName,BOOL bUsedAsBz);
		void SetParmBz(int subComtype,const CString parmName,BOOL bUsedAsBz);

		/**
		* @brief   设置当前参数的备注信息（有些参数有多个同名参数，使用在不同subComtype下）
		*
		*			注意：非当前使用参数，不能使用本函数进行设置
		* @note  : 
		* @param : 
		* @return: TRUE/FALSE
		* @author: zfy
		* @date  : [9/23/2020]
		*/
		void SetParmBzCurrent(const CString parmName,BOOL bUsedAsBz);

		//清除类型备注
		void ClearParmBz();
		//初始化参数的是否附加到 备注的信息
		//void InitParmBz(const std::set<CString> & setParmsName);
		//获取需要附加到备注的参数名
		void GetParmHasBz(std::set<CString> & setParmsName) const;
		//是否参数被作为备注使用
		BOOL IsParmUsedAsBz(const CString parmName) const;

		//获取参数的备注
		CString GetParmBz() const{return m_strParmBz;}

		/// 获取备注被修改了的参数名
		void GetParmCurrentChangedBz(CArray<const CSubComtypeParms::ParmData *> & parms) const;
		
		//获取/设置公共构件
		BOOL IsPublicGj() const{return m_bPublicGj;}
		void SetPublicGj(BOOL bPublicGj){m_bPublicGj = bPublicGj;}


	private:
		//禁止被用于参数附加的参数判断
		BOOL IsParmUnPermitUsedAsBz(const CString parmName) const;

		//获取参数的显示值
		CString GetParmDisplayValue(CString parmName,CString parmValue) const;
		BOOL ChangeDisplayText(const CString & parmName, const CString & orignValue, int iComId , CString & displayValue) const;

	private:
		int m_iComid;
		int m_iComType;
		int m_iFloorID;
		CString m_strComName;
		BOOL m_bPublicGj;	//是否是公共构件
		CString m_strBz;	//备注信息
		CString m_strParmBz;//参数的备注信息

		//参数缓存
		CSubComtypeParms * m_pParms;

		//界面图参数缓存
		PMShared_Ptr<CParms> m_pVectorParms;

		// 参数指针，其为真正的dataset，非共享指针
		PMShared_Ptr<NDataModelDataSet>	m_pComParmDataSet;
		BOOL				m_bComParmHasChange;//参数表是否需要保存

		CPMVectorEntityInfo * m_pVectorEntityInfo;//配筋图缓存
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
	* @brief 获取 ComType 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [16/7/2012]
	*/
	BOOL GetComType(int iComID,int & iComType);
	int	 GetComType( const int iComId ) ; 

	/**
	* @brief   获取楼层id
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2012-7-16]
	*/
	BOOL	GetFloorId( const int iComID , int & iFloorID ) ;
	int		GetFloorId( const int iComId ) ;

	//获取构件名称
	BOOL	GetComName( const int iComId , CString & strComName ) ; 
	CString GetComName( const int iComId ) ;

	//设置构件名称
	BOOL SetComName(int iComId,const CString & strComName);

	//通过
	BOOL GetParmValue(int iComId,CString parmName,CString & parmValue) ;
	BOOL GetParmValue(int iComId,int componentType,CString parmName,CString & parmValue) ;

	//判断是否公共构件
	BOOL IsPublicGj(int iComId);

	//设置公共构件
	BOOL SetPublicGj(int iComId,BOOL bPublic);
	BOOL SetPublicGj(const CUIntArray & arrComId,BOOL bPublic);

	//原来方式下的备注,目前界面上使用的是parmbz，但报表等中可能使用原来的备注
	CString GetBz(int iComId);

	//设置参数是否可使用为备注，返回整体的备注信息
	CString SetParmBz(int iComId,CString parmName,BOOL bUsedAsBz);

	//判断某个参数是否是参数附加备注
	BOOL IsParmUsedAsBz(int iComId,CString parmName) ;
	//获取参数附加备注的总信息
	CString GetParmBz(int iComId);
	//清除参数备注
	void ClearParmBz(int iComId);

	/**
	* @brief  获取 构件 参数信息 
	*
	*          
	* @note  : 返回的DataSet ,其为 CPmComParmsDataSet ，为共享指针对象 ，共享 CComponentInfo::m_pComParmDataSet 指针对象.
	*			需要删除。即使删除它，也并不会删除 CComponentInfo::m_pComParmDataSet 指针
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [18/5/2012]
	*/
	BOOL GetComParmDataSet(int iComID,NDataModelDataSet *& pComParmSet);

	//从数据库获取构件参数的dataset，并把内存托管为智能指针
	PMShared_Ptr<NDataModelDataSet> CreateComParmDataSet(int iComID);

	/**
	* @brief  设置 构件 参数信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [18/5/2012]
	*/
	BOOL SetComParmDataSet(int iComID,NDataModelDataSet * pComParmSet);

	/**
	* @brief   参数拷贝
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
	* @brief  获取 构件的 配筋图信息 
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [19/7/2012]
	*/
	BOOL GetVectorParmDataSet(int iComID,CProject_VectorParmsTable *& pComParmSet);

	/**
	* @brief  设置配筋图DataSet信息 
	*
	*          
	* @note  : 需要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	BOOL SetVectorParmDataSet(int iComID,CProject_VectorParmsTable * pVectorDataSet);

	BOOL GetVectorParmValue(int iComID,const CString & strParmName,CString & strParmValue);

	/**
	* @brief 设置 指定ComID的 图参数  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [24/7/2012]
	*/
	BOOL SetVectorParm(int iComID,const CString & strParmName,const CString & strParmValue);

	/**
	* @brief 用于计算参数表 所占内存大小  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [21/5/2012]
	*/
	void CalComParmMemSize();

	/**
	* @brief   清除构件 所占内存
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [21/5/2012]
	*/
	void FreeComponentMem();

	void FreeComponentMem( const int iComId ) ;

	void FreeComponentMem_FloorId(const int floorid) ;

	void FreeComponentMem( const CUIntArray & aryComId ) ; 

	//刷新参数内存
	void FreeComponentParmMem();
	void FreeComponentParmMem(int comid);

	/**
	* @brief 修复Comid属性(在切换钢筋信息时,有些数据会被遗漏)
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王荣强
	* @date  : [2016-12-30]
	*/
	void Repair_ComponentInfo( const int iComId, NDataModelDataSet * pComParmSet);

	/**
	* @brief 获取当前工程的 钢筋模式  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [5/7/2012]
	*/
	ProjectInfoMacro::GangJinMode GetProjectGangJinMode();

	// 如果传入值不符要求则会取消设置  wrq [2017-2-10]
	void SetProjectGangJinMode(ProjectInfoMacro::GangJinMode gangjinMode);

	/// 添加辅助接口
	/// 方便外面调用 
	/// 因16G添加的关系,增加IsGreaterThan03G函数做判断
	BOOL	Is11G() ;

	/// 是否大于03G(不包含03G)
	BOOL	IsGreaterThan03G();

	/**
	* @brief 获取配筋图绘制信息   
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	const CPMVectorEntityInfo * GetVectorEntityInfo(int iComID);

	/**
	* @brief  设置配筋图 绘制信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	BOOL SetVectorEntityInfo(int iComID,NDataModelDataSet * pVectorDataSet);

	/**
	* @brief  获取构件信息
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/7/2012]
	*/
	const CComponentInfo * GetComponentInfo_const(int iComID);

	/**
	* @brief   获取 当前的 选中信息
	*
	*          
	* @note  : 返回当前选中的 ComID，与FloorID
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
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
	* @brief 设置当前的 ComID  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [16/7/2012]
	*/
	BOOL SetCurComID(int iCurComID);

	BOOL SetCurFloorID(int iCurFloorID);

	/**
	* @brief 尝试给 pComponentInfo添加 构件参数 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [16/7/2012]
	*/
	BOOL Try_InitComParmSetCache(int iComID,CSLComponentManager::CComponentInfo * pComponentInfo);

	/**
	* @brief  获取构件信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [18/5/2012]
	*/
	CComponentInfo * GetComponentInfo(int iComID);

	/// 获取所有ComponentInfo
	void GetComponentInfo(const CUIntArray & arrComid);
	void GetComponentInfoAll();

	/**
	* @brief   刷新构件信息，如果已存在，则不添加构件（如果参数不存在时，会进行参数的替换）；构件不存在时，进行构件信息的添加
	*
	*			qc:30360，工程设置点ok时可能触发
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [8/26/2020]
	*/
	void UpdateComponentInfoAll();

	void UpdateComParmsSet_Comid_before();
	void UpdateComParmsSet_Comid_after();

	/// 获取某个comtype下所有comid
	void GetComIdOnFloor(int floorid,int comtype,std::set<int> & setComid) const;

	/**
	* @brief  获取指定 构件类型的 参数表 (默认参数)
	*
	*          
	* @note  : 需要 删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/7/2012]
	*/
	BOOL GetComParmsDataSet_ComType(int iComType,NDataModelDataSet *& pComParmsDataSet);
	BOOL GetComParmsDataSet_ComType(int iComType,CUIntArray & iParmTypeArr,NDataModelDataSet *& pComParmsDataSet);

	/**
	* @brief  获取计算规则 DataSet
	*
	*          
	* @note  : 需要 删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [17/7/2012]
	*/
	NDataModelDataSet * GetJsgzDataSet();

	BOOL GetComParms_TotalTable_ParmValue(const CString & strParmName,CString & strParmValue);

	/**
	* @brief   
	*
	*          
	* @note  : 外部类 不用使用 这个函数
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [23/7/2012]
	*/
// 	CComParmsCache * GetComParmsCacheCtrl()
// 	{
// 		return &m_ComParmsCache;
// 	}

	/**
	* @brief 获取默认的 参数总表  
	*
	*          
	* @note  : 主要进行一些特殊修改，不要删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [23/7/2012]
	*/
	BOOL GetDefComParmDataSet(NDataModelDataSet *& pComParmDataSet);

	//参数表 恢复默认
// 	BOOL ComParmsSetTable_Resume();
// 	BOOL ComParmsSet_TotalTable_Resume();

	BOOL DelComponent_ID( const int iComID);

	BOOL DelComponent_ID( const CUIntArray & aryComId );

	/**
	* @brief  针对目前缓存不太复杂，所有缓存保存放到 这个函数执行 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/7/2012]
	*/
	BOOL SaveProject();
	
	/**
	*  @brief : 把构件信息保存到数据库
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
	* @brief  保存用户工程的 参数总表 
	*
	*          
	* @note  : 目前只在工程设置中调用
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [2/8/2012]
	*/
	//BOOL SaveDefComParmsDataSet();

	/**
	* @brief 判断 装饰 构件 是否可以删除  
	*
	*          
	* @note  : 装饰构件，在被房间套用后，不能删除
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 杨兴耀
	* @date  : [2014年5月23日]
	*/
	BOOL CanZsDel( const int iComId ); 
public:
	//漫游的出生点
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
	 * @brief  :点的获取与设置
	 *
	 * 详细描述:hoops漫游功能应用
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
	* @brief  设置默认参数信息 
	*
	*          
	* @note  : 只用在添加 构件时
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
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

	//获取矢量图参数(包括具体值)
	BOOL BuildVectorParmStringMap(int iComID,ParmsMapInfo_T & comParmsMap);
	void BuildVectorParmStringMap(int iComID,const CParms * pVectorParms,ParmsMapInfo_T & comParmsMap);

	//获取属性参数
	void BuildComParmStringMap(int iComID,const NDataModelDataSet * pComParmDataSet,ParmsMapInfo_T & comParmsMap);
	void BuildComParmStringMap(int iComID,const CSubComtypeParms * pComParms,ParmsMapInfo_T & comParmsMap) const;

private:

	BOOL ChangeSpecVectorParm_RFQ(const CPMVectorEntityInfo * pNewVectorInfo,ParmsMapInfo_T & comParmsMap);
	static CSLComponentManager * m_pInstance;

	//CComParmsCache m_ComParmsCache;

	ComIDMapComponentInfo_T m_MapComponents;

	ProjectInfoMacro::GangJinMode m_gangjinMode;//当前的钢筋模式

	int m_iCurFloorID;//当前楼层ID
	int m_iCurComID;//当前的构件ID

	BornPt m_BornPt;
};
