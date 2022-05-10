
#pragma once 

/**
 * @brief �ֽ����ݵ�����
 *
 *        
 * @author ����ҫ
 * @version v1.0
 * @date  [2013-5-10]
 * @note  
 */

#include "SteelDataDefine.h"

#include "ParmInfoBase.h"

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// �ֽ����ݵ�����
class PMLogicDataOprAPI CSteelDataContainer : public CParmInfoBase
{
public:
	DYNAMIC_CREATE_PARMINFOBASE( CSteelDataContainer , parminfobase::eParmSteelContainer ) ; 
public:
	CSteelDataContainer() ; 
	virtual ~CSteelDataContainer() ; 

	/// ���ڲ���Ҫ�����ͷ�����
protected:

	void	ReleaseData() ; 

	/**
	* @brief   �����е����ݽ��д���������ʧ�ܷ���FALSE
	*
	*          ��ϸ����
	* @note  : 
	* @param : 
	* @return: ʧ�ܷ���FALSE
	* @author: ׯ����
	* @date  : [28/2/2013]
	*/
	BOOL GetData(CPmArchiveBase & arc) const;
	/**
	* @brief    �����е����ݽ��з�����������ʧ�ܷ���FALSE
	*
	*          ��ϸ����
	* @note  : 
	* @param : 
	* @return: ʧ�ܷ���FALSE
	* @author: ׯ����
	* @date  : [14/3/2013]
	*/
	BOOL SetData(const CPmArchiveBase & arc);

	/// 
public:
	void	AddSteelData(  CSteelBaseA6d5 * const pSteelData ) ;

	/// 
public:
	int		GetSize() ;

	const CSteelBaseA6d5 *		GetAt( const int iIndex )  ; 

	void	Clear() ; 

public:

	/// ֱ�ӷ���list 
	const CSteelDataList * GetListData() const  ; 

	/// 
protected:
	CSteelDataList	m_listSteelData ; 

	static const PmInt32 m_iBegin ; 
	static const PmInt32 m_iEnd ; 

};



//////////////////////////////////////////////////////////////////////////
/// ����
/// �ֽ����� �͡�
/// �ֽ�����ݽṹ
/// 
/// ������
/// �ڸֽ����ݵĴ����ͷ������õ�
/// 
class CSteelDataSwitch
{
private:
	CSteelDataSwitch() ; 
public:
	~CSteelDataSwitch() ; 

	static CSteelDataSwitch & Instance() ; 

public:
	/// 
	void	RegisterAll() ;
	void	UnRegisterAll() ; 

	//��ȡCSteelBaseA6d5
	CSteelBaseA6d5 * Create( const int iType ) const;

protected:

	void RegisterSteelData( const int iType ,  CSteelBaseA6d5 * const  pEntParm) ;

private:
	/// 
	/// �ֽ�ö�١��͡��ֽ����ݵĹ�����ָ��
	/// 
	CInt2SteelMap	m_mapType2SteelData ; 

	
};

#define PmSteelDataSwitch CSteelDataSwitch::Instance() 