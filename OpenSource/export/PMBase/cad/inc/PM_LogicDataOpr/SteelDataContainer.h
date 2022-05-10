
#pragma once 

/**
 * @brief 钢筋数据的容器
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2013-5-10]
 * @note  
 */

#include "SteelDataDefine.h"

#include "ParmInfoBase.h"

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 钢筋数据的容器
class PMLogicDataOprAPI CSteelDataContainer : public CParmInfoBase
{
public:
	DYNAMIC_CREATE_PARMINFOBASE( CSteelDataContainer , parminfobase::eParmSteelContainer ) ; 
public:
	CSteelDataContainer() ; 
	virtual ~CSteelDataContainer() ; 

	/// 现在不需要串化和反串化
protected:

	void	ReleaseData() ; 

	/**
	* @brief   对类中的数据进行串化，串化失败返回FALSE
	*
	*          详细描述
	* @note  : 
	* @param : 
	* @return: 失败返回FALSE
	* @author: 庄峰毅
	* @date  : [28/2/2013]
	*/
	BOOL GetData(CPmArchiveBase & arc) const;
	/**
	* @brief    对类中的数据进行反串化，串化失败返回FALSE
	*
	*          详细描述
	* @note  : 
	* @param : 
	* @return: 失败返回FALSE
	* @author: 庄峰毅
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

	/// 直接返回list 
	const CSteelDataList * GetListData() const  ; 

	/// 
protected:
	CSteelDataList	m_listSteelData ; 

	static const PmInt32 m_iBegin ; 
	static const PmInt32 m_iEnd ; 

};



//////////////////////////////////////////////////////////////////////////
/// 关联
/// 钢筋名称 和　
/// 钢筋的数据结构
/// 
/// 单键类
/// 在钢筋数据的串化和反串化用到
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

	//获取CSteelBaseA6d5
	CSteelBaseA6d5 * Create( const int iType ) const;

protected:

	void RegisterSteelData( const int iType ,  CSteelBaseA6d5 * const  pEntParm) ;

private:
	/// 
	/// 钢筋枚举　和　钢筋数据的关联的指针
	/// 
	CInt2SteelMap	m_mapType2SteelData ; 

	
};

#define PmSteelDataSwitch CSteelDataSwitch::Instance() 