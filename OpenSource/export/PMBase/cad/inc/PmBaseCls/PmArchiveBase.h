#pragma once
/**
 * @brief  :串化基类
 *
 *          认为数据是连续的，不连续的话，仅对第一段连续数据进行操作
 * @author :zfy
 * @version:v1.0
 * @date   :[7/17/2015]
 * @note   :[2016.07.17][zfy] 改进本类，使空间可以不释放状态下，接着从头开始使用，避免重复分配空间导致的速度慢
 */
class PMBASECLASSAPI CPmArchiveBase
{
public:
	CPmArchiveBase(void);
	/// 初始化逻辑长度及内存增长长度
	CPmArchiveBase(UINT nGrowLen);

	virtual ~CPmArchiveBase(void);

	class PMBASECLASSAPI CArchiveNode
	{
	public:
		friend class CPmArchiveBase;
		CArchiveNode(CPmArchiveBase * pArchiveBase,BOOL bNeedInit);
		virtual ~CArchiveNode();

		BYTE * GetBuffer() const;
		int GetUseSize() const{return m_iNodeUse;}
		void SetUseSize(int iUseSize){m_iNodeUse = iUseSize;}

		/// 重置内部数据为空，但不释放内存空间。本函数会递归调用子节点的ResetUseMem函数
		void ResetUseMem();

		void NodeSeekStep(UINT nPos);

		void AppendBuffer(LPCVOID pBuffer,int iBufferSize);

		/// 
		void	SetArchive( CPmArchiveBase * pArcBase ) ;

		/**
		* @brief  取消内存托管模式  
		*
		*          
		* @note  : 在存在下级节点是 进行 托管是 失败的
		* @param : 
		* @defenc: 
		* @return: 
		* @author: 王建业
		* @date  : [30/9/2013]
		*/
		BOOL Detach();

		bool ReadData(void* pData, UINT len) ;

		CArchiveNode * GetNextStringNode() const{return m_pNextArchiveNode;}
		void ClearNextStringNode()
		{
			m_pNextArchiveNode = NULL;
		}
	private:
		/**
		* @brief  内存托管模式  
		*
		* @note  : 在已经存在节点是 进行 托管是 失败的
		*			zfy note 2015.07.17，本函数要个要求iBufferSize与m_pArchiveBase->GetNodeSize();一致
		* @param : 
		* @defenc: 
		* @return: 
		* @author: 王建业
		* @date  : [30/9/2013]
		*/
		BOOL Attach(LPVOID pBuffer,int iBufferSize);

	protected:
		BYTE * m_pMem;
		int m_iNodeUse;
		CArchiveNode * m_pNextArchiveNode;

		CPmArchiveBase * m_pArchiveBase;
	};

	//获取节点 大小
	int GetNodeSize(){return m_iNodeSize;}

	/// 将数据附着到本类，pData内存由本类来管理
	void Attach(byte*& pData, UINT nLenth);

	/// 
	void Attach( const CPmArchiveBase & other ) ;

	//将数据脱离本类，内存不维护
	void Detach();

	/// 释放内存，同时设置数据长度及逻辑长度为0
	void Release();

	/// 重置内部数据为空，但不释放内存空间与节点
	void ResetUseMem();

	/******************************************************************** 
	功能描述 尝试加载 Gzip buf
	参数：  byte * pBuffer ,int iBufferSize
	返 回 值：
	算法：    
	注意事项：pBuffer 这个类 不维护
	作    者：王建业
	时    间：[2017:6:23]   
	*********************************************************************/ 
	bool TryLoadGZipBuf(byte * pBuffer,int iBufferSize);

	/******************************************************************** 
	功能描述 获取 串化Buf ，并进行 Gzip压缩
	参数：   byte *& pBuffer 合成后的buf 需要删除 ,int & iBufferSize
	返 回 值：
	算法：    
	注意事项：
	作    者：王建业
	时    间：[2017:6:23]   
	*********************************************************************/ 
	bool GetGZipBufData(byte *& pBuffer,int & iBufferSize);

	/**
	* @brief 获取 串化数据，注意这个内存需要删除  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [30/9/2013]
	*/
	byte* GetData() const;
	void* GetVoidData() const;

	/// 获取当前指针位置，可能出现负数，负数时，说明内部数据有问题
//	INT_PTR GetCurPos() const;

	/**
	* @brief   数据长度
	*
	*          仅到第一段连续数据的尾部长度
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [7/17/2015]
	*/
	int GetDataLen() const;

	/// 当前数据移动到开始，以读取数据
	void SeekToStart();

	/// 当前数据移动到指定位置，仅能在已使用空间内移动
	void SeekTo(UINT nPos) const;

	//获取当前 数据位置
	INT_PTR GetCurPos() const;

	//数据 移动指定步长
	void SeekStep(UINT nPos) const;

	//判断数据是否结束
	BOOL IsEnd() const;

	//获取 数据游标
	void GetSeekPos(CArchiveNode *& pCurNode,UINT & nPos) const;

	/// 添加数据
	virtual void AddData(const void* pData, UINT len);
	virtual void AddData(PmUInt8 var) ;
	virtual void AddData(PmUInt16 val);
	virtual void AddData(PmUInt32 val);
	virtual void AddData(PmUInt64 val);
	virtual void AddChar(char val ) ;
	virtual void AddData(PmInt8 val);
	virtual void AddData(PmInt16 val);
	virtual void AddData(PmInt32 val);
	virtual void AddData(double val);
	virtual void AddData(double val1,double val2);
	virtual void AddData(double val1,double val2,double val3);
	virtual void AddData(BOOL val);
	virtual void AddData(const CString& str);
	virtual void AddData(const CStringArray & val);
	virtual void AddData(const std::string& str);
	//virtual void AddData(const std::wstring & str);
	virtual void AddDataUTF8(const CString& str);
	template <class T> 
	void TAddData(const T & val)
	{
		AddData(&val, sizeof(T));
	}

	/// 读取数据
	virtual bool ReadData(void* pData, UINT len) const;
	virtual bool ReadData(PmUInt8& val) const ;
	virtual bool ReadData(PmUInt16& val) const;
	virtual bool ReadData(PmUInt32& val) const;
	virtual bool ReadData(PmUInt64& val) const;
	virtual bool ReadChar(char& val) const ;
	virtual bool ReadData(PmInt8& val) const ;
	virtual bool ReadData(PmInt16& val) const;
	virtual bool ReadData(PmInt32& val) const;
	virtual bool ReadData(double& val) const;
	virtual bool ReadData(double & val1,double & val2) const;
	virtual bool ReadData(double & val1,double & val2,double & val3) const;
	virtual bool ReadData(BOOL& val) const;
	virtual bool ReadData(CString& str) const;
	virtual bool ReadData(CStringArray & val) const;
	virtual bool ReadData(std::string& str) const;
	//virtual	bool ReadData(std::wstring& str) const;
	virtual bool ReadDataUTF8(CString& str) const;
	template <class T> 
	bool TReadData(T & val) const
	{
		return ReadData(&val, sizeof(T));
	}
	
	/**
	* @brief 获取串化根节点  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: 王建业
	* @date  : [9/10/2013]
	*/
	const CArchiveNode * GetArchiveRootNode() const
	{
		return m_pRootNode;
	}

private:
	/// 仅释放内存，不改变数据长度
	void ReleaseMemo();

	/// 当前数据移动到指定位置，允许移动到下个未使用空间
	void SeekTo(CArchiveNode * pCurNode,UINT nPos) ;

	/**
	* @brief   判断是否是数据结束的顶点
	*
	*          1、pNode为空，认为是尾部节点，本身使用长度为空，也认为是尾部节点
	*		   2、没有下个节点会认为是尾部
	*		   3、有下个节点，但下个节点被使用长度是空的，也认为是尾部
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [7/17/2015]
	*/
	BOOL IsEndNode(const CArchiveNode * pNode) const;
	
private:
	
	CArchiveNode * m_pRootNode;
	int				m_iNodeSize;
	
	mutable CArchiveNode * m_pCurNode;			//当前游标 所在节点
	mutable int				m_iCurNodePos;		//当前游标 所在节点位置
};

//写入保护器
class PMBASECLASSAPI CArchiveWriteProtector
{
public:
	CArchiveWriteProtector(CPmArchiveBase * pArchive);
	~CArchiveWriteProtector();

	bool StartArchive();

	bool FitStatus(bool bAutoJumper = true);

protected:

	UINT m_iStartPos;
	CPmArchiveBase::CArchiveNode * m_pCurNode;
	CPmArchiveBase * m_pArchive;
};


//读取保护器
class PMBASECLASSAPI CArchiveReadProtector
{
public:
	CArchiveReadProtector(const CPmArchiveBase * pArchive);
	~CArchiveReadProtector();

	bool StartArchive();

	bool FitStatus(bool bAutoJumper = true);

protected:

	int m_iStartPos;
	int m_iClassLen;
	const CPmArchiveBase * m_pArchive;
};