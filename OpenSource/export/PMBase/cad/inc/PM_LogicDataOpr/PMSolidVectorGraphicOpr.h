#pragma once

typedef std::map<CString,CString> ParmsMapInfo_T;

class CPMObjInfo;
class CPMVectorEntityInfo_SimEnt;
class PMLogicDataOprAPI CPMVectorInfo_Base
{
public:
	CPMVectorInfo_Base();
	virtual ~CPMVectorInfo_Base();

	enum VectorInfoMode
	{
		eNull = 0,
		eGJVectorInfo = 1,		//构件型 Vector信息
		eSolidVectorInfo = 2,	//实体型 Vector信息
	};

	VectorInfoMode GetVectorInfoMode() const
	{
		return m_VectorInfoMode;
	}

	/**
	* @brief 获取 Vector的长度  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorLength() const
	{
		return _T("");
	}

	/**
	* @brief  获取Vector的 宽度 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorWidth() const
	{
		return _T("");
	}

	/**
	* @brief  获取 Vector的 高度 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorHeight() const
	{
		return _T("");
	}

	/**
	* @brief  获取Vector 边信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorBianInfo() const
	{
		return _T("");
	}

	/**
	 * @brief  :获取Vector 边信息绘制顺序
	 *
	 * 详细描述
	 * @author zyj
	 * @version v1.0
	 * @date  2016/4/23 11:27
	 * @note  :
	 */
	virtual CString GetVectorBianOrderInfo() const
	{
		return _T("");
	}

	/**
	* @brief 获取 Vector的 特殊运算信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorSpecInfo() const
	{
		return _T("");
	}
	virtual void SetSpecVectorInfo(const CString & strSpecInfo)
	{
	}

	/**
	* @brief  进行参数替换 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap) = 0;

	/**
	* @brief  从Buffer中读取、写入数据 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL Serialize( CArchive& ar ) = 0;

	/**
	* @brief 从DataSet中读取数据  
	*
	*          
	* @note  : 只用于保存界面显示，Vector的绘制数据
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL ReadFromDataSet( const CString & strVectorInfo ) = 0;

	/**
	* @brief  将数据保存为DataSet 
	*
	*          
	* @note  : 只用于界面显示，Vector的绘制数据
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL WriteToDataSet( CString & strVectorInfo ) const = 0;

	//清除之前的数据
	virtual void FreeData() = 0;

	/**
	* @brief  获取 Vector的绘制方式 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual const CArray<CPMVectorEntityInfo_SimEnt * ,CPMVectorEntityInfo_SimEnt*&> * GetVectorDrawInfo()const
	{
		return NULL;
	}
	//获取参数
	virtual void GetParams(CArray<ParmsMapInfo_T> &ParamsMapArr)
	{
	}
	//改变参数值
	virtual BOOL ChangeParmValue(CString strParmName,CString strParmValue)
	{
		return FALSE;
	}
	//获取二维参数
	virtual BOOL Get2DPolyInfo(CString strPartName,ParmsMapInfo_T & comParmsMap) const
	{
		return FALSE;
	}
	virtual CPMObjInfo* GetObjInfo()
	{
		return NULL;
	}

protected:

	VectorInfoMode m_VectorInfoMode;
};

class PMLogicDataOprAPI CPMVectorEntityInfo
{
public:
	CPMVectorEntityInfo();
	virtual ~CPMVectorEntityInfo();

	/**
	* @brief 获取 Vector的长度  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorLength() const;

	/**
	* @brief  获取Vector的 宽度 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorWidth() const;

	/**
	* @brief  获取 Vector的 高度 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorHeight() const;

	/**
	* @brief  获取Vector 边信息 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorBianInfo() const;

	/**
	* @brief 获取 Vector的 特殊运算信息  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorSpecInfo() const;
	virtual void SetSpecVectorInfo(const CString & strSpecInfo);

	/**
	 * @brief  :获取Vector 边信息绘制顺序
	 *
	 * 详细描述
	 * @author zyj
	 * @version v1.0
	 * @date  2016/4/23 11:27
	 * @note  :
	 */
	virtual CString GetVectorBianOrderInfo() const;

	/**
	* @brief  进行参数替换 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	/**
	* @brief  从Buffer中读取数据 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL ReadFromBuffer( BYTE * pBuffer,long lBufferSize );

	/**
	* @brief 将数据写到Buffer中去  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL WriteToBuffer( BYTE *& pBuffer,long & lBufferSize );

	/**
	* @brief 从DataSet中读取数据  
	*
	*          
	* @note  : 只用于保存界面显示，Vector的绘制数据
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL ReadFromDataSet( const CString & strVectorInfo );

	/**
	* @brief  将数据保存为DataSet 
	*
	*          
	* @note  : 只用于界面显示，Vector的绘制数据
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/5/2012]
	*/
	virtual BOOL WriteToDataSet( CString & strVectorInfo ) const;

	const CArray<CPMVectorEntityInfo_SimEnt * ,CPMVectorEntityInfo_SimEnt*&> * GetVectorDrawInfo()const;

	//清除之前的数据
	virtual void FreeData();

	//获取参数
	void GetParams(CArray<ParmsMapInfo_T> &ParamsMapArr) const
	{
		m_pVectorInfoOpr->GetParams(ParamsMapArr);
	}

	//获取obj信息
	CPMObjInfo* GetObjInfo()
	{
		if(m_pVectorInfoOpr)
			return m_pVectorInfoOpr->GetObjInfo();
		else
			return NULL;
	}

	//改变指定名称参数值
	BOOL ChangeParmValue(CString strParmName,CString strParmValue);

	BOOL Get2DPolyInfo(CString strPartName,ParmsMapInfo_T & comParmsMap) const;

	//获取 截面图 对象
	CPMVectorInfo_Base * GetVectorInfoPtr() 
	{
		return m_pVectorInfoOpr;
	}

protected:

	CPMVectorInfo_Base * m_pVectorInfoOpr;
};


class CPMSolidVectorGraphicOpr
{
public:
	CPMSolidVectorGraphicOpr(void);
	~CPMSolidVectorGraphicOpr(void);
};


