// Parms.h: interface for the CParms class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARMS_H__A938BB79_C932_46FC_9FF2_C99E7C2C1F37__INCLUDED_)
#define AFX_PARMS_H__A938BB79_C932_46FC_9FF2_C99E7C2C1F37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/**
 * @brief  :���ڴ洢���������ݽṹ
 *
 *          ���õ�Ϊ�洢�������õ�����
 * @author :zfy
 * @version:v1.0
 * @date   :04/15/2010
 * @note   :
 */

#if defined(_DEBUG) && !defined(_FULLDEBUG_)
#define _DEBUG_CPARMS_DEFINED
#undef _DEBUG
#pragma message ("     Compiling vector header files in release mode.")
#endif

#include <afxcoll.h>
#include <vector>

#ifdef _DEBUG_CPARMS_DEFINED
#define _DEBUG
#undef _DEBUG_CPARMS_DEFINED
#endif



#ifdef  _DEBUG
	#define TraceParmsDebug(parms)	(parms).TraceParm() 
	#define TraceParmsPtr(ptr)		(ptr)->TraceParm()
#else
	#define TraceParmsDebug(parms)	((void)0)
	#define TraceParmsPtr(ptr)		((void)0)
#endif

#include "Param.h"

typedef CArray<CParm*,CParm *&> MacroParmArray;
class PMBASECLASSAPI CParms  
{
public:
	CParms();
	virtual ~CParms();

	/**
	* @brief   ���param,����Ѵ������滻
	*
	*          ��ӵ��Ⱥ�˳���������Ϣ���(GetParmMacro)���йص�
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [11/5/2012]
	*/
	void Add(const CParm &parm);

	///���param,����Ѵ������滻,�����������������˳��
	void Append(const CParm & parm);

	///���params,����Ѵ������滻,�����������������˳��
	void Append(const CParms & parms);

	///���params,����Ѵ�������ԭֵ
	void AppendNotReplace(CParms & parms);

	///�Ƴ�ĳ������
	void Remove(const CString & parmName);
	///�Ƴ����в���
	void RemoveAll();

	///��ȡ�������ܸ���
	int	GetCount() const;

	/**
	* @brief   ��ȡ������Ӧ��ֵ,�����ڷ���_T("")
	*
	*          ��ϸ����
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [11/5/2012]
	*/
	CString GetValue(const CString & parmName) const;

	///��ȡ������Ӧ��ֵ,���������ڻ��߲���תΪint �ķ���FALSE
	BOOL GetValueAsInt(const CString & parmName,int & value) const;
	///��ȡ������Ӧ��ֵ,��������Ҳ������߲��������򷵻�0
	int GetValueAsInt(const CString & parmName) const;

	///��ȡ������Ӧ��ֵ,���������ڻ��߲���תΪdouble�ķ���FALSE
	BOOL GetValueAsDouble(const CString & parmName,double & value) const;
	///��ȡ������Ӧ��ֵ,��������Ҳ������߲��������򷵻�0
	double GetValueAsDouble(const CString & parmName) const;

	/// �ж������������Ƿ�һ��
	BOOL IsSame(const CParms & parms) const;

	/**
	* @brief   ���ò�����ֵ��������������ڣ��򲻽�������
	*
	*          ��ϸ����
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [11/5/2012]
	*/
	BOOL SetValue(const CString & parmName,const CString & parmValue);
	BOOL SetValue(const CString & parmName,int parmValue);
	BOOL SetValue(const CString & parmName,double parmValue);

	/**
	* @brief   ��ȡ��������ָ�룬ʹ��ʱ��Ҫ�жϷ���ֵ����Ϊ�������õȲ���������Ŀ���࣬�����Ķ������·���ֵΪNULL
	*
	*          �Ƽ�ʹ�÷�ָ���������ȡ��������,ָ������ʹ����Ϊ��Ч��,���Ӵ��˲��ȶ���
	* @note  : 
	* @param : �Ҳ�����Ӧ�����򷵻�NULL
	* @return: 
	* @author: zfy
	* @date  : [11/5/2012]
	*/
	CParm * GetParm(const CString & name);
	const CParm * GetParm(const CString & name) const;
	BOOL GetParm(int idx,CParm & parm) const;				//�ú��������ڱ�����,����map���ǰ�˳���ģ�����idx���岻��
	BOOL GetParm(const CString & name,CParm & parm) const;

	/**
	* @brief   ��һ��˳��һ����ʽ�����ݼ����ú��ַ���
	*
	*          var ttt = 1; �����Ĵ������
	* @note  : 
	* @param : 
	* @return: 
	* @author: zfy
	* @date  : [11/5/2012]
	*/
	CString GetParmMacro(const CString & parmName) const;
	CString GetParmMacro() const;//ȡ�����еĲ���ת��Ϊ��
	BOOL GetParmMacro_String(PmTString & largeStringBuilder) const;
	
	/**
	* @brief   ��ȡ������Ϣ,������ʽΪ:  ����:ֵ(����)
	*
	*          ��ϸ����
	* @note  : 
	* @param : iStyle :0	����ʾ���� ; 1	��ʾ����
	* @return: 
	* @author: zfy
	* @date  : [5/19/2009]
	*/
	CString GetParmsInfo(int iStyle = 0) const;
	
	///��ӡ�ַ������������
	void TraceParm(std::vector <CParm*> & vect) const;
	CString TraceParm() const;

	///�������������ṹ,�ڴ�鱾������ⲿ����ɾ��
    void GetParmsArray(MacroParmArray &array) const;

	/// ���ఴ�������������,�ڴ�鱾������ⲿ����ɾ��
	void GetParmsSorted(MacroParmArray &array) const;

	///�Ѳ����ƶ����.GetParmMacro�������
	void MoveParmToLast(const CString & parmName);
	///�Ѳ����Ƶ�parmNameBeforeǰ,parmNameBefore���������Ƶ���ǰ��GetParmMacro�������
	void MoveParmToBegin(const CString & parmName, CString parmNameBefore = _T(""));


	/**
	* @brief   ʵ�ֶԲ����Ĳ�֣����ڰ����Ȳ���������
	*
	*          ��ϸ����
	* @note  : 
	* @param : 
	* @return: parmName���ڣ��򷵻�true��else false
	* @author: zll
	* @date  : 01/07/2009
	*/
	BOOL SplitParm(const CString &parmName,								 /*Ҫ������ֵĲ�����*/
				   const CString &parmRepName,							 /*�����Ҫ�滻������*/
				   const CString & parmDesc = _T(""),						 /*�µĲ������Ľ���*/
				   const CParm::ParmType &parmType = CParm::PTNotString, /*��ֺ��γ��µĲ�������������	*/				   
				   const int &size = 2									 /*Ҫ��ֵĲ����ĸ���*/
				   );

	/**
	* @brief   ����Add��������������������ظ�����
	*
	*          ��ϸ����
	* @note  : 
	* @param : 
	* @return: 
	* @author: zll
	* @date  : 01/07/2009
	*/
	inline void Add(const CString & parmName, const CString & parmValue, const CString & parmDesc, CParm::ParmType parmType)
	{	
		Add(CParm(parmName, parmValue, parmDesc, parmType));
	}	
	inline void Add(const CString & parmName, int parmValue, const CString & parmDesc, CParm::ParmType parmType)
	{	
		Add(CParm(parmName, parmValue, parmDesc, parmType));
	}
	inline void Add(const CString & parmName, double parmValue, const CString & parmDesc, CParm::ParmType parmType)
	{	
		Add(CParm(parmName, parmValue, parmDesc, parmType));
	}
	inline void Add(const CString & parmName, float parmValue, const CString & parmDesc, CParm::ParmType parmType)
	{	
		Add(CParm(parmName, parmValue, parmDesc, parmType));
	}
//////////////////////////////////////////////////////////////////////////
protected:
	int m_maxIndex;
	//�ӱ������Ƶ����������ӳ��
	CMapStringToPtr  m_mapStringToParm;
};


// �������� ����ֵ��Ӧ ��
class PMBASECLASSAPI CStringNumberList
{
public:
	CStringNumberList();
	~CStringNumberList();

	void AddParm(const CString & strParmName,const CString & strParmValue);

	void AddParm(const CString & strParmName,double dValue);

	// ��ȡLua�ű���Ҫ ������
	std::string GetParmInfo() const;

protected:
	PmArray<std::string> m_strNameArr;
	PmArray<std::string> m_strValueArr;
};


#endif // !defined(AFX_PARMS_H__A938BB79_C932_46FC_9FF2_C99E7C2C1F37__INCLUDED_)
