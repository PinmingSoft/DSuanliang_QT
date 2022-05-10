#pragma once

/**
* @brief 镜像指针 基类  
*
*          
* @note  : 只为让CNotifyPtr类，有可以实际操作类
* @param : 
* @defenc: 
* @return: 
* @author: 王建业
* @date  : [26/12/2013]
*/
class PMBASECLASSOPRAPI CPMMirrorPtr
{
public:
	CPMMirrorPtr();
	virtual ~CPMMirrorPtr();

	virtual void DoClearMirrorPtr() = 0;

protected:


};
typedef CArray<CPMMirrorPtr*,CPMMirrorPtr*&>	CPMMirrorPtrArr;

/**
* @brief 基类接口  
*
*          
* @note  : 镜像指针 控制接口
* @param : 
* @defenc: 
* @return: 
* @author: 王建业
* @date  : [23/12/2013]
*/
class PMBASECLASSOPRAPI CNotifyPtr
{
public:
	CNotifyPtr();
	virtual ~CNotifyPtr();

	/**
	* @brief 添加 镜像 通知指针  
	*
	*          
	* @note  : 
	* @param : CPMMirrorPtr * pTemMirrorBase:镜像实现类
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/12/2013]
	*/
	bool AddNotifyPtr(CPMMirrorPtr * pTemMirrorBase);

	/**
	* @brief 移除镜像 通知指针  
	*
	*          
	* @note  : 
	* @param :  CPMMirrorPtr * pTemMirrorBase:镜像实现类
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/12/2013]
	*/
	bool RemoveNotifyPtr(const CPMMirrorPtr * pTemMirrorBase);

	/**
	* @brief 清除 所有 镜像指针关联  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/12/2013]
	*/
	void DoClearMirrorPtr();

protected:

	CPMMirrorPtrArr m_MirrorPtrArr;
};

/**
* @brief 镜像指针 模版类  
*
*          
* @note  : 
* @param : 
* @defenc: 
* @return: 
* @author: 王建业
* @date  : [26/12/2013]
*/
template <class T>
class CPMTMirrorPtr : public CPMMirrorPtr
{
public:
	CPMTMirrorPtr(T * pCtrlPtr) : m_pCtrlPtr(pCtrlPtr)
	{
		if(m_pCtrlPtr)
		{
			m_pCtrlPtr->AddNotifyPtr(this);
		}
	}

	~CPMTMirrorPtr(void)
	{
		UnRegMirrorPtr();
	}

	//注册控制指针
	void RegMirrorPtr(T * pPtr)
	{
		if(m_pCtrlPtr == pPtr)
			return;
		UnRegMirrorPtr();
		m_pCtrlPtr = pPtr;
		if(m_pCtrlPtr)
		{
			m_pCtrlPtr->AddNotifyPtr(this);
		}
	}

	//卸载控制指针
	void UnRegMirrorPtr()
	{
		//退出控制
		if(m_pCtrlPtr)
		{
			CPMTMirrorPtr * pTemPtr = this;
			m_pCtrlPtr->RemoveNotifyPtr(pTemPtr);
		}
		m_pCtrlPtr = NULL;
	}

	/**
	* @brief 去除 镜像指针关联  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/12/2013]
	*/
	virtual void DoClearMirrorPtr()
	{
		m_pCtrlPtr = NULL;
	}

	/**
	* @brief 判断镜像指针 是否有效 
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [26/12/2013]
	*/
	BOOL CheckMirrorPtr_IsOK()
	{
		if(m_pCtrlPtr)
			return TRUE;
		return FALSE;
	}

	// Allow usage as a pointer
	T* operator->() {return m_pCtrlPtr;}

	// Allow usage as a pointer
	operator T*() {return m_pCtrlPtr;}


protected:

	T * m_pCtrlPtr;//模版对象
};

/**
 * @brief  :仅用于托管指针内存,使其在析构函数时能及时释放
 *
 *          
 * @author :zfy
 * @version:v1.0
 * @date   :[12/28/2017]
 * @note   :
 */
template <class T> class CPMSharePtr
{
public:
	CPMSharePtr(T * pCtrlPtr) : m_pCtrlPtr(pCtrlPtr)
	{
	}

	~CPMSharePtr(void)
	{
		PMDelete(m_pCtrlPtr);
	}

	//是否空的判断
	bool IsNull() const{m_pCtrlPtr==NULL?return true:false;}

	// Allow usage as a pointer
	T* operator->() {return m_pCtrlPtr;}

	// Allow usage as a pointer
	operator T*() {return m_pCtrlPtr;}


protected:

	T * m_pCtrlPtr;//模版对象

private:
	//禁止赋值\拷贝
	void operator=(const CPMSharePtr &rhs ){}
	CPMSharePtr(const CPMSharePtr &rhs ){}
};