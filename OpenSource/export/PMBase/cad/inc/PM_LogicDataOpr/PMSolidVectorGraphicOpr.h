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
		eGJVectorInfo = 1,		//������ Vector��Ϣ
		eSolidVectorInfo = 2,	//ʵ���� Vector��Ϣ
	};

	VectorInfoMode GetVectorInfoMode() const
	{
		return m_VectorInfoMode;
	}

	/**
	* @brief ��ȡ Vector�ĳ���  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorLength() const
	{
		return _T("");
	}

	/**
	* @brief  ��ȡVector�� ��� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorWidth() const
	{
		return _T("");
	}

	/**
	* @brief  ��ȡ Vector�� �߶� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorHeight() const
	{
		return _T("");
	}

	/**
	* @brief  ��ȡVector ����Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorBianInfo() const
	{
		return _T("");
	}

	/**
	 * @brief  :��ȡVector ����Ϣ����˳��
	 *
	 * ��ϸ����
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
	* @brief ��ȡ Vector�� ����������Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
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
	* @brief  ���в����滻 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap) = 0;

	/**
	* @brief  ��Buffer�ж�ȡ��д������ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL Serialize( CArchive& ar ) = 0;

	/**
	* @brief ��DataSet�ж�ȡ����  
	*
	*          
	* @note  : ֻ���ڱ��������ʾ��Vector�Ļ�������
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL ReadFromDataSet( const CString & strVectorInfo ) = 0;

	/**
	* @brief  �����ݱ���ΪDataSet 
	*
	*          
	* @note  : ֻ���ڽ�����ʾ��Vector�Ļ�������
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL WriteToDataSet( CString & strVectorInfo ) const = 0;

	//���֮ǰ������
	virtual void FreeData() = 0;

	/**
	* @brief  ��ȡ Vector�Ļ��Ʒ�ʽ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual const CArray<CPMVectorEntityInfo_SimEnt * ,CPMVectorEntityInfo_SimEnt*&> * GetVectorDrawInfo()const
	{
		return NULL;
	}
	//��ȡ����
	virtual void GetParams(CArray<ParmsMapInfo_T> &ParamsMapArr)
	{
	}
	//�ı����ֵ
	virtual BOOL ChangeParmValue(CString strParmName,CString strParmValue)
	{
		return FALSE;
	}
	//��ȡ��ά����
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
	* @brief ��ȡ Vector�ĳ���  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorLength() const;

	/**
	* @brief  ��ȡVector�� ��� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorWidth() const;

	/**
	* @brief  ��ȡ Vector�� �߶� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorHeight() const;

	/**
	* @brief  ��ȡVector ����Ϣ 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorBianInfo() const;

	/**
	* @brief ��ȡ Vector�� ����������Ϣ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual CString GetVectorSpecInfo() const;
	virtual void SetSpecVectorInfo(const CString & strSpecInfo);

	/**
	 * @brief  :��ȡVector ����Ϣ����˳��
	 *
	 * ��ϸ����
	 * @author zyj
	 * @version v1.0
	 * @date  2016/4/23 11:27
	 * @note  :
	 */
	virtual CString GetVectorBianOrderInfo() const;

	/**
	* @brief  ���в����滻 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [6/7/2012]
	*/
	virtual BOOL ReBuildVectorInfo(ParmsMapInfo_T & comParmsMap);

	/**
	* @brief  ��Buffer�ж�ȡ���� 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL ReadFromBuffer( BYTE * pBuffer,long lBufferSize );

	/**
	* @brief ������д��Buffer��ȥ  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL WriteToBuffer( BYTE *& pBuffer,long & lBufferSize );

	/**
	* @brief ��DataSet�ж�ȡ����  
	*
	*          
	* @note  : ֻ���ڱ��������ʾ��Vector�Ļ�������
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL ReadFromDataSet( const CString & strVectorInfo );

	/**
	* @brief  �����ݱ���ΪDataSet 
	*
	*          
	* @note  : ֻ���ڽ�����ʾ��Vector�Ļ�������
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/5/2012]
	*/
	virtual BOOL WriteToDataSet( CString & strVectorInfo ) const;

	const CArray<CPMVectorEntityInfo_SimEnt * ,CPMVectorEntityInfo_SimEnt*&> * GetVectorDrawInfo()const;

	//���֮ǰ������
	virtual void FreeData();

	//��ȡ����
	void GetParams(CArray<ParmsMapInfo_T> &ParamsMapArr) const
	{
		m_pVectorInfoOpr->GetParams(ParamsMapArr);
	}

	//��ȡobj��Ϣ
	CPMObjInfo* GetObjInfo()
	{
		if(m_pVectorInfoOpr)
			return m_pVectorInfoOpr->GetObjInfo();
		else
			return NULL;
	}

	//�ı�ָ�����Ʋ���ֵ
	BOOL ChangeParmValue(CString strParmName,CString strParmValue);

	BOOL Get2DPolyInfo(CString strPartName,ParmsMapInfo_T & comParmsMap) const;

	//��ȡ ����ͼ ����
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


