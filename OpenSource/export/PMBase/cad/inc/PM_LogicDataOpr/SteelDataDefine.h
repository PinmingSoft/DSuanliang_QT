

#pragma once 

/**
 * @brief 定义钢筋数据类
 *
 *        
 * @author 杨兴耀
 * @version v1.0
 * @date  [2013-5-10]
 * @note  
 */

#include "CommonDataTableDefine.h"


#define DYNAMIC_CREATE_STEELDATA( CLASS_NAME , STEELTYPE ) \
	virtual CSteelBaseA6d5 * Create() const; \
	virtual BOOL IsKindOf(const  int & type) const; \
	static int desc() \
	{ \
	return STEELTYPE ; \
	} \
	virtual	int	GetType( ) const \
	{\
	return STEELTYPE ; \
	}\
	virtual CString GetClassName() const \
	{ \
	return _T(#CLASS_NAME); \
	}

#define DYNAMIC_IMPLEMENT_STEELDATA(CLASS_NAME , STEELTYPE ) \
	CSteelBaseA6d5 * CLASS_NAME::Create() const{ \
	return PMNew(CLASS_NAME); \
	} \
	BOOL CLASS_NAME::IsKindOf(const int & type) const{ \
	if( STEELTYPE == type) \
	return TRUE; \
	else \
	return FALSE; \
	}

namespace parminfobase
{
	/// 
	/// 新增类型时，不能修改现有类型的值
	/// 因为类型可能会持久化的保存
	/// 
	enum CSteelType
	{
		/// 
		eTypeBaseA6d5 = 0 ,
		eType5A6d5 = 1 ,
		eTypeA6d5a100 = 2 , 
		eTypeA6d5a100g200 = 3 ,
		eType5A6d5a100 = 4 , 
		eType5A6d5a100g200 = 5 ,
		eTypeG5A6d5 = 11 , 
		eType5A6d5z4 = 12 , 
		eType5A6d5z400 = 13 , 
		eTypeA6d5a100z4 = 22 ,
		eTypeA6d5a100g200z4 = 32 , 
		eTypeA6d5a100z2g200z4 = 33 , 
		eTypeG5A6d5a100 = 41 , 
		eTypeG5A6d5a100z4 = 42 , 
		eTypeG5A6d5a100g200 = 51 , 
		eType5A6d5a100g200z4 = 52 ,
		eType11A6d5A6d5a100g200z4 = 53,
		eTypeA6d5g6d5a100 = 61 ,
		eTypeA6d5gA6d5a100 = 62 ,
		eType5A6d5g3g2 = 63 ,
		eType5A6d5g3g2add = 64 ,
		eType5A6d5gX2 = 65 ,
		eTypeA6d5g6d5a100z2 = 71 ,
		eTypeA6d5gA6d5a100z2 = 72 ,
	} ;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 钢筋基类
/// 级别+直径(A6.5)
/// 
class PMLogicDataOprAPI CSteelBaseA6d5 
{
public:
	DYNAMIC_CREATE_STEELDATA( CSteelBaseA6d5 , parminfobase::eTypeBaseA6d5  ) ; 

	CSteelBaseA6d5() ;
	virtual ~CSteelBaseA6d5() ; 


public:
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

protected:
	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetJb( const PmInt8 nJb ) ;
	PmInt8		GetJb() const ;

	void	SetDia( const PmInt16 nDia ) ;
	PmInt16		GetDia( ) const ;

private:
	/// 级别
	PmInt8		m_nJb  ;

	/// 直径
	PmInt16		m_nDia ; 

};

/// 
typedef	std::vector< CSteelBaseA6d5 * > CSteelDataList ;
typedef CSteelDataList::iterator CSteelDataListIter ; 
typedef CSteelDataList::const_iterator CSteelDataListConIter ;

/// 
typedef std::map< int , CSteelBaseA6d5 * > CInt2SteelMap ; 
typedef CInt2SteelMap::iterator	CInt2SteelMapIter ; 
typedef CInt2SteelMap::const_iterator CInt2SteelMapConIter ; 


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 根数+级别+直径(5A6.5)
/// 
class PMLogicDataOprAPI CSteelType5A6d5: public CSteelBaseA6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5 , parminfobase::eType5A6d5 ) ; 
	CSteelType5A6d5() ;
	virtual ~CSteelType5A6d5() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetGs( const PmInt16 nGs ) ; 
	PmInt16	GetGs() const ;

protected:

	/// 根数 
	PmInt16		m_nGs ; 

};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 构造类型+根数+级别+直径 (G5A6.5)
/// 
class PMLogicDataOprAPI CSteelTypeG5A6d5: public CSteelType5A6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeG5A6d5 , parminfobase::eTypeG5A6d5 ) ; 
	CSteelTypeG5A6d5() ;
	virtual ~CSteelTypeG5A6d5() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetGzlx( const PmInt8 nGzlx ) ; 
	PmInt8	GetGzlx() const ;

protected:

	/// 构造类型 
	PmInt8		m_nGzlx ; 

};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 根数+级别+直径(支数) (5A6.5(4))
/// 
class PMLogicDataOprAPI CSteelType5A6d5z4: public CSteelType5A6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5z4 , parminfobase::eType5A6d5z4 ) ; 
	CSteelType5A6d5z4() ;
	virtual ~CSteelType5A6d5z4() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:

	/// 支数 
	PmInt8		m_nZs ; 

};

/// 
/// 根数+级别+直径(伸入长度) (5A6.5(400))，原先 CSteelType5A6d5z4  由于肢数存为 int8 ，导致位数严重不足
/// 
class PMLogicDataOprAPI CSteelType5A6d5z400: public CSteelType5A6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5z400 , parminfobase::eType5A6d5z400 ) ; 
	CSteelType5A6d5z400() ;
	virtual ~CSteelType5A6d5z400() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs( const PmUInt32 nZs ) ; 
	PmUInt32	GetZs() const ;

protected:

	/// 支数 
	PmUInt32		m_nZs ; 
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 级别+直径+间距 (A6.5@100)
/// 
class PMLogicDataOprAPI CSteelTypeA6d5a100: public CSteelBaseA6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5a100 , parminfobase::eTypeA6d5a100 ) ; 
	CSteelTypeA6d5a100() ;
	virtual ~CSteelTypeA6d5a100() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetJmjj( const PmInt16 nJmjj ) ; 
	PmInt16	GetJmjj() const ;

protected:

	/// 支数 
	PmInt16		m_nJmjj ; 

};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 级别+直径+间距(支数) (A6.5@100(4))
/// 
class PMLogicDataOprAPI CSteelTypeA6d5a100z4: public CSteelTypeA6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5a100z4 , parminfobase::eTypeA6d5a100z4 ) ; 
	CSteelTypeA6d5a100z4() ;
	virtual ~CSteelTypeA6d5a100z4() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:

	/// 支数 
	PmInt8		m_nZs ; 

};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 级别+直径+间距(支数) (A6.5@100/200)
/// 
class PMLogicDataOprAPI CSteelTypeA6d5a100g200: public CSteelTypeA6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5a100g200 , parminfobase::eTypeA6d5a100g200 ) ; 
	CSteelTypeA6d5a100g200() ;
	virtual ~CSteelTypeA6d5a100g200() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetFjmjj( const PmInt16 nFjmjj ) ; 
	PmInt16	GetFjmjj() const ;

protected:

	/// 非加密间距 
	PmInt16		m_nFjmjj ; 

};



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 级别+直径+间距+非加密间距(支数) (A6.5@100/200(4))
/// 
class PMLogicDataOprAPI CSteelTypeA6d5a100g200z4: public CSteelTypeA6d5a100g200
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5a100g200z4 , parminfobase::eTypeA6d5a100g200z4 ) ; 
	CSteelTypeA6d5a100g200z4() ;
	virtual ~CSteelTypeA6d5a100g200z4() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:

	/// 支数 
	PmInt8		m_nZs ; 

};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 级别+直径+间距+非加密间距(支数) (A6.5@100/200(4))
/// 
class PMLogicDataOprAPI CSteelTypeA6d5a100z2g200z4: public CSteelTypeA6d5a100g200
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5a100z2g200z4 , parminfobase::eTypeA6d5a100z2g200z4 ) ; 
	CSteelTypeA6d5a100z2g200z4() ;
	virtual ~CSteelTypeA6d5a100z2g200z4() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs1( const PmInt8 nZs ) ; 
	PmInt8	GetZs1() const ;

	void	SetZs2( const PmInt8 nZs ) ; 
	PmInt8	GetZs2() const ;

protected:

	/// 支数1 
	PmInt8		m_nZs1 ; 
	/// 支数2 
	PmInt8		m_nZs2 ; 
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 排数+级别+直径+间距 (5A6.5@100)
/// 
class PMLogicDataOprAPI CSteelType5A6d5a100: public CSteelTypeA6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5a100 , parminfobase::eType5A6d5a100 ) ; 
	CSteelType5A6d5a100() ;
	virtual ~CSteelType5A6d5a100() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetPs( const PmInt8 nPs ) ; 
	PmInt8	GetPs() const ;

protected:

	/// 排数
	PmInt8		m_nPs ; 

};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 构造类型+排数+级别+直径+间距 (G5A6.5@100)
/// 
class PMLogicDataOprAPI CSteelTypeG5A6d5a100: public CSteelType5A6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeG5A6d5a100 , parminfobase::eTypeG5A6d5a100 ) ; 
	CSteelTypeG5A6d5a100() ;
	virtual ~CSteelTypeG5A6d5a100() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetGzlx( const PmInt8 nGzlx ) ; 
	PmInt8	GetGzlx() const ;

protected:

	/// 构造类型 
	PmInt8		m_nGzlx ; 

};



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 排数+级别+直径+间距(支数) (5A6.5@100(4))
/// 
class PMLogicDataOprAPI CSteelTypeG5A6d5a100z4: public CSteelType5A6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeG5A6d5a100z4 , parminfobase::eTypeG5A6d5a100z4 ) ; 
	CSteelTypeG5A6d5a100z4() ;
	virtual ~CSteelTypeG5A6d5a100z4() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:

	/// 支数 
	PmInt8		m_nZs ; 

};



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 排数+级别+直径+间距+非加密间距 (5A6.5@100/200)
/// 
class PMLogicDataOprAPI CSteelType5A6d5a100g200: public CSteelTypeA6d5a100g200
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5a100g200 , parminfobase::eType5A6d5a100g200 ) ; 
	CSteelType5A6d5a100g200() ;
	virtual ~CSteelType5A6d5a100g200() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetPs( const PmInt8 nPs ) ; 
	PmInt8	GetPs() const ;

protected:

	/// 排数
	PmInt8		m_nPs ; 

};



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 构造类型+排数+级别+直径+间距+非加密间距 (G5A6.5@100/200)
/// 
class PMLogicDataOprAPI CSteelTypeG5A6d5a100g200: public CSteelType5A6d5a100g200
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeG5A6d5a100g200 , parminfobase::eTypeG5A6d5a100g200 ) ; 
	CSteelTypeG5A6d5a100g200() ;
	virtual ~CSteelTypeG5A6d5a100g200() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetGzlx( const PmInt8 nGzlx ) ; 
	PmInt8	GetGzlx() const ;

protected:

	/// 构造类型 
	PmInt8		m_nGzlx ; 

};



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 排数+级别+直径+间距 +非加密间距　(支数) (5A6.5@100/200(4))
/// 
class PMLogicDataOprAPI CSteelType5A6d5a100g200z4: public CSteelType5A6d5a100g200
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5a100g200z4 , parminfobase::eType5A6d5a100g200z4 ) ; 
	CSteelType5A6d5a100g200z4() ;
	virtual ~CSteelType5A6d5a100g200z4() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:

	/// 支数 
	PmInt8		m_nZs ; 

};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 排数+级别+直径+(级别+直径)+间距 +非加密间距　(支数) (11A6.5(A6.5)@100/200(2))
/// 
class PMLogicDataOprAPI CSteelType11A6d5A6d5a100g200z4: public CSteelType5A6d5a100g200z4
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType11A6d5A6d5a100g200z4 , parminfobase::eType11A6d5A6d5a100g200z4 ) ; 
	CSteelType11A6d5A6d5a100g200z4() ;
	virtual ~CSteelType11A6d5A6d5a100g200z4() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetJbInner( const PmInt8 nJb ) ;
	PmInt8		GetJbInner() const ;

	void	SetDiaInner( const PmInt16 nDia ) ;
	PmInt16		GetDiaInner( ) const ;

protected:

	/// 级别
	PmInt8		m_nJbInner  ;

	/// 直径
	PmInt16		m_nDiaInner ; 
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 级别+直径+直径+间距 (A6.5/8@100)
/// 
class PMLogicDataOprAPI CSteelTypeA6d5g6d5a100: public CSteelTypeA6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5g6d5a100 , parminfobase::eTypeA6d5g6d5a100 ) ; 
	CSteelTypeA6d5g6d5a100() ;
	virtual ~CSteelTypeA6d5g6d5a100() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	// 操作直径2
	void	SetDia2( const PmInt16 nDia2 ) ; 
	PmInt16	GetDia2() const ;

protected:

	PmInt16	m_nDia2 ;  // 直径2

};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 级别+直径+直径+间距+肢数 (A6.5/8@100(2))
/// 
class PMLogicDataOprAPI CSteelTypeA6d5g6d5a100z2: public CSteelTypeA6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5g6d5a100z2 , parminfobase::eTypeA6d5g6d5a100z2 ) ; 
	CSteelTypeA6d5g6d5a100z2() ;
	virtual ~CSteelTypeA6d5g6d5a100z2() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	// 操作直径2
	void	SetDia2( const PmInt16 nDia2 ) ; 
	PmInt16	GetDia2() const ;

	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:

	PmInt16	m_nDia2 ;  // 直径2
	PmInt8		m_nZs ; // 肢数

};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 级别+直径+级别+直径+间距 (A6.5/C8@100)
/// 
class PMLogicDataOprAPI CSteelTypeA6d5gA6d5a100: public CSteelTypeA6d5g6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5gA6d5a100 , parminfobase::eTypeA6d5gA6d5a100 ) ; 
	CSteelTypeA6d5gA6d5a100() ;
	virtual ~CSteelTypeA6d5gA6d5a100() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);
public:
	void SetJb2(const PmInt8 nJb);
	PmInt8 GetJb2() const;

protected:
	PmInt8 m_nJb2;
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 级别+直径+级别+直径+间距+肢数 (A6.5/C8@100(2))
/// 
class PMLogicDataOprAPI CSteelTypeA6d5gA6d5a100z2: public CSteelTypeA6d5gA6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5gA6d5a100z2 , parminfobase::eTypeA6d5gA6d5a100z2 ) ; 
	CSteelTypeA6d5gA6d5a100z2() ;
	virtual ~CSteelTypeA6d5gA6d5a100z2() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);
public:
	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:
	PmInt8		m_nZs ; // 肢数
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 根数+级别+直径+上下排 (5A6.5 3/2)
/// 
class PMLogicDataOprAPI CSteelType5A6d5g3g2: public CSteelType5A6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5g3g2 , parminfobase::eType5A6d5g3g2 ) ; 
	CSteelType5A6d5g3g2() ;
	virtual ~CSteelType5A6d5g3g2() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);
public:

	/// 上排根数
	void	SetSbGs( const PmInt8 nSbGs ) ; 
	PmInt8	GetSbGs() const ;

	/// 下排根数
	void	SetXbGs( const PmInt8 nXbGs ) ; 
	PmInt8	GetXbGs() const ;

protected:
	PmInt8		m_nSbGs ;    /// 上排根数
	PmInt8		m_nXbGs ;    /// 下排根数
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 根数+级别+直径+上下排 (6A6.5 3/2/1)
/// 
class PMLogicDataOprAPI CSteelType5A6d5g3g2add: public CSteelType5A6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5g3g2add , parminfobase::eType5A6d5g3g2add ) ; 
	CSteelType5A6d5g3g2add() ;
	virtual ~CSteelType5A6d5g3g2add() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);
public:

	/// 上排根数
	int		GetSize() ;
	int		GetAt( const int iIdx ) ;

public:
	PmArray<PmInt8>	m_aryGsAdd ; 
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// 根数+级别+直径*N (6A6.5*2)
/// 
class PMLogicDataOprAPI CSteelType5A6d5gX2: public CSteelType5A6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5gX2 , parminfobase::eType5A6d5gX2 ) ; 
	CSteelType5A6d5gX2() ;
	virtual ~CSteelType5A6d5gX2() ; 

protected:

	//串化数据，子类需要派生
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetGs( const PmInt16 nGs ) ; 
	PmInt16	GetGs() const ;

	void	SetXs( const PmInt16 nXs ) ; 
	PmInt16	GetXs() const ;

protected:

	/// 根数 
	PmInt16		m_nGs ; 
	PmInt16		m_nXs ; // 系数
};
