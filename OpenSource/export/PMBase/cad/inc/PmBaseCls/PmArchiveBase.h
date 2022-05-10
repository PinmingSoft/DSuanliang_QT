#pragma once
/**
 * @brief  :��������
 *
 *          ��Ϊ�����������ģ��������Ļ������Ե�һ���������ݽ��в���
 * @author :zfy
 * @version:v1.0
 * @date   :[7/17/2015]
 * @note   :[2016.07.17][zfy] �Ľ����࣬ʹ�ռ���Բ��ͷ�״̬�£����Ŵ�ͷ��ʼʹ�ã������ظ�����ռ䵼�µ��ٶ���
 */
class PMBASECLASSAPI CPmArchiveBase
{
public:
	CPmArchiveBase(void);
	/// ��ʼ���߼����ȼ��ڴ���������
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

		/// �����ڲ�����Ϊ�գ������ͷ��ڴ�ռ䡣��������ݹ�����ӽڵ��ResetUseMem����
		void ResetUseMem();

		void NodeSeekStep(UINT nPos);

		void AppendBuffer(LPCVOID pBuffer,int iBufferSize);

		/// 
		void	SetArchive( CPmArchiveBase * pArcBase ) ;

		/**
		* @brief  ȡ���ڴ��й�ģʽ  
		*
		*          
		* @note  : �ڴ����¼��ڵ��� ���� �й��� ʧ�ܵ�
		* @param : 
		* @defenc: 
		* @return: 
		* @author: ����ҵ
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
		* @brief  �ڴ��й�ģʽ  
		*
		* @note  : ���Ѿ����ڽڵ��� ���� �й��� ʧ�ܵ�
		*			zfy note 2015.07.17��������Ҫ��Ҫ��iBufferSize��m_pArchiveBase->GetNodeSize();һ��
		* @param : 
		* @defenc: 
		* @return: 
		* @author: ����ҵ
		* @date  : [30/9/2013]
		*/
		BOOL Attach(LPVOID pBuffer,int iBufferSize);

	protected:
		BYTE * m_pMem;
		int m_iNodeUse;
		CArchiveNode * m_pNextArchiveNode;

		CPmArchiveBase * m_pArchiveBase;
	};

	//��ȡ�ڵ� ��С
	int GetNodeSize(){return m_iNodeSize;}

	/// �����ݸ��ŵ����࣬pData�ڴ��ɱ���������
	void Attach(byte*& pData, UINT nLenth);

	/// 
	void Attach( const CPmArchiveBase & other ) ;

	//���������뱾�࣬�ڴ治ά��
	void Detach();

	/// �ͷ��ڴ棬ͬʱ�������ݳ��ȼ��߼�����Ϊ0
	void Release();

	/// �����ڲ�����Ϊ�գ������ͷ��ڴ�ռ���ڵ�
	void ResetUseMem();

	/******************************************************************** 
	�������� ���Լ��� Gzip buf
	������  byte * pBuffer ,int iBufferSize
	�� �� ֵ��
	�㷨��    
	ע�����pBuffer ����� ��ά��
	��    �ߣ�����ҵ
	ʱ    �䣺[2017:6:23]   
	*********************************************************************/ 
	bool TryLoadGZipBuf(byte * pBuffer,int iBufferSize);

	/******************************************************************** 
	�������� ��ȡ ����Buf �������� Gzipѹ��
	������   byte *& pBuffer �ϳɺ��buf ��Ҫɾ�� ,int & iBufferSize
	�� �� ֵ��
	�㷨��    
	ע�����
	��    �ߣ�����ҵ
	ʱ    �䣺[2017:6:23]   
	*********************************************************************/ 
	bool GetGZipBufData(byte *& pBuffer,int & iBufferSize);

	/**
	* @brief ��ȡ �������ݣ�ע������ڴ���Ҫɾ��  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [30/9/2013]
	*/
	byte* GetData() const;
	void* GetVoidData() const;

	/// ��ȡ��ǰָ��λ�ã����ܳ��ָ���������ʱ��˵���ڲ�����������
//	INT_PTR GetCurPos() const;

	/**
	* @brief   ���ݳ���
	*
	*          ������һ���������ݵ�β������
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [7/17/2015]
	*/
	int GetDataLen() const;

	/// ��ǰ�����ƶ�����ʼ���Զ�ȡ����
	void SeekToStart();

	/// ��ǰ�����ƶ���ָ��λ�ã���������ʹ�ÿռ����ƶ�
	void SeekTo(UINT nPos) const;

	//��ȡ��ǰ ����λ��
	INT_PTR GetCurPos() const;

	//���� �ƶ�ָ������
	void SeekStep(UINT nPos) const;

	//�ж������Ƿ����
	BOOL IsEnd() const;

	//��ȡ �����α�
	void GetSeekPos(CArchiveNode *& pCurNode,UINT & nPos) const;

	/// �������
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

	/// ��ȡ����
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
	* @brief ��ȡ�������ڵ�  
	*
	*          
	* @note  : 
	* @param : 
	* @defenc: 
	* @return: 
	* @author: ����ҵ
	* @date  : [9/10/2013]
	*/
	const CArchiveNode * GetArchiveRootNode() const
	{
		return m_pRootNode;
	}

private:
	/// ���ͷ��ڴ棬���ı����ݳ���
	void ReleaseMemo();

	/// ��ǰ�����ƶ���ָ��λ�ã������ƶ����¸�δʹ�ÿռ�
	void SeekTo(CArchiveNode * pCurNode,UINT nPos) ;

	/**
	* @brief   �ж��Ƿ������ݽ����Ķ���
	*
	*          1��pNodeΪ�գ���Ϊ��β���ڵ㣬����ʹ�ó���Ϊ�գ�Ҳ��Ϊ��β���ڵ�
	*		   2��û���¸��ڵ����Ϊ��β��
	*		   3�����¸��ڵ㣬���¸��ڵ㱻ʹ�ó����ǿյģ�Ҳ��Ϊ��β��
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
	
	mutable CArchiveNode * m_pCurNode;			//��ǰ�α� ���ڽڵ�
	mutable int				m_iCurNodePos;		//��ǰ�α� ���ڽڵ�λ��
};

//д�뱣����
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


//��ȡ������
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