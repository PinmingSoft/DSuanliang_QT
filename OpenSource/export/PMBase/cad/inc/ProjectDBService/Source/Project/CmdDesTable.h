#pragma once

class PMProjectDBSERVICE CCmdDesDataset : public CSQLDataSet
{
public:
	DECLARE_DYNCREATE(CCmdDesDataset)

	CCmdDesDataset();
	virtual ~CCmdDesDataset(){};

	struct PMProjectDBSERVICE CFieldInfo
	{
		//����
		static const CString command;

		//��ϸ����
		static const CString detailname;

		//����
		static const CString name;

		//����
		static const CString undo;

		//�ظ����ģʽ
		static const CString checkRepeatMode;

		//��������
		static const CString zljs;

		//�Ƿ�Ʒ������
		static const CString pmgj;

		//�Ƿ���Ҫ������й�����û�����й���������
		static const CString checkGJ;

		//����
		static const CString table_name;
	};

	virtual int InitFieldStr();
	int	InitFieldStrV2( NDataModelDataSet * pDataSet );

	//��ȡӢ��������ϸ��������ƥ��
	void GetDetailNameMap(std::map<CString, CString> & mapCmdDetailName) const;

	//��ȡӢ���������ļ������ƥ��
	void GetNameMap(std::map<CString, CString> & mapCmdDes) const;

	//��ȡӢ���������״̬��ƥ��
	void GetUndoMap(std::map<CString, int> & mapCmdUndo) const;

	//��ȡӢ�������ظ����״̬��ƥ��
	void GetCheckRepeatModeMap(std::map<CString, int> & mapCmdCheckRepeatMode) const;

	//��ȡӢ���������������ƥ��
	void GetCheckZLJSMap(std::map<CString, int> & mapCmdZLJS) const;

	//��ȡӢ�������Ƿ����ƥ��
	void GetCheckGJMap(std::map<CString, int> & mapCmdCheckGJ) const;

	//��ȡӢ�������Ƿ�Ʒ�������ƥ��
	void GetPmCommand(std::map<CString, int> & mapCmdPM) const;
};

class PMProjectDBSERVICE CCmdDesTable
{
private:
	static BOOL m_bOwnCmdChange;
public:
	CCmdDesTable(void);
	~CCmdDesTable(void);

	//
	CCmdDesDataset * GetDataSet() const;

	//qc28054 �Զ��������Ƿ�ı�ı��
	static BOOL  GetOwnCmdChange();
	static void  SetOwnCmdChange(BOOL bOwnCmdChange);
};

class PMProjectDBSERVICE CCmdDesTableOpr
{
public:
	static CCmdDesTableOpr * Instance()
	{
		if (NULL == m_pInstance)
		{
			m_pInstance = PMNew(CCmdDesTableOpr);
		}
		return m_pInstance;
	}
	static void Release()
	{
		PMDelete(m_pInstance);
	}

	//
	BOOL IsCmdCheckGJ(CString cmd) const;

	BOOL IsPMCmd(CString cmd) const;

	//��ȡ�����Ӧ����������
	CString GetChCmdName(CString enCmdName) const;

private:
	CCmdDesTableOpr();
	~CCmdDesTableOpr();

	//
	static CCmdDesTableOpr * m_pInstance;
	CCmdDesDataset * m_pDataset;

	//�����Ƿ�Ҫ��⹹���Ѵ��ڣ��Ѵ��ڲſ�����Ӽ���ִ������
	std::map<CString,int> m_mapCmdCheckGJ;

	//���ָ��Ƿ���Ʒ��������
	std::map<CString,int> m_mapCmdPM;

	//����������������Ľ���
	std::map<CString,CString> m_mapCmdEn_Ch;
};