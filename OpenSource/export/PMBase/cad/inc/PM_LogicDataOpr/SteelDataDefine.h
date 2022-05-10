

#pragma once 

/**
 * @brief ����ֽ�������
 *
 *        
 * @author ����ҫ
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
	/// ��������ʱ�������޸��������͵�ֵ
	/// ��Ϊ���Ϳ��ܻ�־û��ı���
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
/// �ֽ����
/// ����+ֱ��(A6.5)
/// 
class PMLogicDataOprAPI CSteelBaseA6d5 
{
public:
	DYNAMIC_CREATE_STEELDATA( CSteelBaseA6d5 , parminfobase::eTypeBaseA6d5  ) ; 

	CSteelBaseA6d5() ;
	virtual ~CSteelBaseA6d5() ; 


public:
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

protected:
	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetJb( const PmInt8 nJb ) ;
	PmInt8		GetJb() const ;

	void	SetDia( const PmInt16 nDia ) ;
	PmInt16		GetDia( ) const ;

private:
	/// ����
	PmInt8		m_nJb  ;

	/// ֱ��
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
/// ����+����+ֱ��(5A6.5)
/// 
class PMLogicDataOprAPI CSteelType5A6d5: public CSteelBaseA6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5 , parminfobase::eType5A6d5 ) ; 
	CSteelType5A6d5() ;
	virtual ~CSteelType5A6d5() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetGs( const PmInt16 nGs ) ; 
	PmInt16	GetGs() const ;

protected:

	/// ���� 
	PmInt16		m_nGs ; 

};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ��������+����+����+ֱ�� (G5A6.5)
/// 
class PMLogicDataOprAPI CSteelTypeG5A6d5: public CSteelType5A6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeG5A6d5 , parminfobase::eTypeG5A6d5 ) ; 
	CSteelTypeG5A6d5() ;
	virtual ~CSteelTypeG5A6d5() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetGzlx( const PmInt8 nGzlx ) ; 
	PmInt8	GetGzlx() const ;

protected:

	/// �������� 
	PmInt8		m_nGzlx ; 

};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+����+ֱ��(֧��) (5A6.5(4))
/// 
class PMLogicDataOprAPI CSteelType5A6d5z4: public CSteelType5A6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5z4 , parminfobase::eType5A6d5z4 ) ; 
	CSteelType5A6d5z4() ;
	virtual ~CSteelType5A6d5z4() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:

	/// ֧�� 
	PmInt8		m_nZs ; 

};

/// 
/// ����+����+ֱ��(���볤��) (5A6.5(400))��ԭ�� CSteelType5A6d5z4  ����֫����Ϊ int8 ������λ�����ز���
/// 
class PMLogicDataOprAPI CSteelType5A6d5z400: public CSteelType5A6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5z400 , parminfobase::eType5A6d5z400 ) ; 
	CSteelType5A6d5z400() ;
	virtual ~CSteelType5A6d5z400() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs( const PmUInt32 nZs ) ; 
	PmUInt32	GetZs() const ;

protected:

	/// ֧�� 
	PmUInt32		m_nZs ; 
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+ֱ��+��� (A6.5@100)
/// 
class PMLogicDataOprAPI CSteelTypeA6d5a100: public CSteelBaseA6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5a100 , parminfobase::eTypeA6d5a100 ) ; 
	CSteelTypeA6d5a100() ;
	virtual ~CSteelTypeA6d5a100() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetJmjj( const PmInt16 nJmjj ) ; 
	PmInt16	GetJmjj() const ;

protected:

	/// ֧�� 
	PmInt16		m_nJmjj ; 

};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+ֱ��+���(֧��) (A6.5@100(4))
/// 
class PMLogicDataOprAPI CSteelTypeA6d5a100z4: public CSteelTypeA6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5a100z4 , parminfobase::eTypeA6d5a100z4 ) ; 
	CSteelTypeA6d5a100z4() ;
	virtual ~CSteelTypeA6d5a100z4() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:

	/// ֧�� 
	PmInt8		m_nZs ; 

};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+ֱ��+���(֧��) (A6.5@100/200)
/// 
class PMLogicDataOprAPI CSteelTypeA6d5a100g200: public CSteelTypeA6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5a100g200 , parminfobase::eTypeA6d5a100g200 ) ; 
	CSteelTypeA6d5a100g200() ;
	virtual ~CSteelTypeA6d5a100g200() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetFjmjj( const PmInt16 nFjmjj ) ; 
	PmInt16	GetFjmjj() const ;

protected:

	/// �Ǽ��ܼ�� 
	PmInt16		m_nFjmjj ; 

};



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+ֱ��+���+�Ǽ��ܼ��(֧��) (A6.5@100/200(4))
/// 
class PMLogicDataOprAPI CSteelTypeA6d5a100g200z4: public CSteelTypeA6d5a100g200
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5a100g200z4 , parminfobase::eTypeA6d5a100g200z4 ) ; 
	CSteelTypeA6d5a100g200z4() ;
	virtual ~CSteelTypeA6d5a100g200z4() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:

	/// ֧�� 
	PmInt8		m_nZs ; 

};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+ֱ��+���+�Ǽ��ܼ��(֧��) (A6.5@100/200(4))
/// 
class PMLogicDataOprAPI CSteelTypeA6d5a100z2g200z4: public CSteelTypeA6d5a100g200
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5a100z2g200z4 , parminfobase::eTypeA6d5a100z2g200z4 ) ; 
	CSteelTypeA6d5a100z2g200z4() ;
	virtual ~CSteelTypeA6d5a100z2g200z4() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs1( const PmInt8 nZs ) ; 
	PmInt8	GetZs1() const ;

	void	SetZs2( const PmInt8 nZs ) ; 
	PmInt8	GetZs2() const ;

protected:

	/// ֧��1 
	PmInt8		m_nZs1 ; 
	/// ֧��2 
	PmInt8		m_nZs2 ; 
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+����+ֱ��+��� (5A6.5@100)
/// 
class PMLogicDataOprAPI CSteelType5A6d5a100: public CSteelTypeA6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5a100 , parminfobase::eType5A6d5a100 ) ; 
	CSteelType5A6d5a100() ;
	virtual ~CSteelType5A6d5a100() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetPs( const PmInt8 nPs ) ; 
	PmInt8	GetPs() const ;

protected:

	/// ����
	PmInt8		m_nPs ; 

};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ��������+����+����+ֱ��+��� (G5A6.5@100)
/// 
class PMLogicDataOprAPI CSteelTypeG5A6d5a100: public CSteelType5A6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeG5A6d5a100 , parminfobase::eTypeG5A6d5a100 ) ; 
	CSteelTypeG5A6d5a100() ;
	virtual ~CSteelTypeG5A6d5a100() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetGzlx( const PmInt8 nGzlx ) ; 
	PmInt8	GetGzlx() const ;

protected:

	/// �������� 
	PmInt8		m_nGzlx ; 

};



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+����+ֱ��+���(֧��) (5A6.5@100(4))
/// 
class PMLogicDataOprAPI CSteelTypeG5A6d5a100z4: public CSteelType5A6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeG5A6d5a100z4 , parminfobase::eTypeG5A6d5a100z4 ) ; 
	CSteelTypeG5A6d5a100z4() ;
	virtual ~CSteelTypeG5A6d5a100z4() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:

	/// ֧�� 
	PmInt8		m_nZs ; 

};



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+����+ֱ��+���+�Ǽ��ܼ�� (5A6.5@100/200)
/// 
class PMLogicDataOprAPI CSteelType5A6d5a100g200: public CSteelTypeA6d5a100g200
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5a100g200 , parminfobase::eType5A6d5a100g200 ) ; 
	CSteelType5A6d5a100g200() ;
	virtual ~CSteelType5A6d5a100g200() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetPs( const PmInt8 nPs ) ; 
	PmInt8	GetPs() const ;

protected:

	/// ����
	PmInt8		m_nPs ; 

};



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ��������+����+����+ֱ��+���+�Ǽ��ܼ�� (G5A6.5@100/200)
/// 
class PMLogicDataOprAPI CSteelTypeG5A6d5a100g200: public CSteelType5A6d5a100g200
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeG5A6d5a100g200 , parminfobase::eTypeG5A6d5a100g200 ) ; 
	CSteelTypeG5A6d5a100g200() ;
	virtual ~CSteelTypeG5A6d5a100g200() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetGzlx( const PmInt8 nGzlx ) ; 
	PmInt8	GetGzlx() const ;

protected:

	/// �������� 
	PmInt8		m_nGzlx ; 

};



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+����+ֱ��+��� +�Ǽ��ܼ�ࡡ(֧��) (5A6.5@100/200(4))
/// 
class PMLogicDataOprAPI CSteelType5A6d5a100g200z4: public CSteelType5A6d5a100g200
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5a100g200z4 , parminfobase::eType5A6d5a100g200z4 ) ; 
	CSteelType5A6d5a100g200z4() ;
	virtual ~CSteelType5A6d5a100g200z4() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:

	/// ֧�� 
	PmInt8		m_nZs ; 

};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+����+ֱ��+(����+ֱ��)+��� +�Ǽ��ܼ�ࡡ(֧��) (11A6.5(A6.5)@100/200(2))
/// 
class PMLogicDataOprAPI CSteelType11A6d5A6d5a100g200z4: public CSteelType5A6d5a100g200z4
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType11A6d5A6d5a100g200z4 , parminfobase::eType11A6d5A6d5a100g200z4 ) ; 
	CSteelType11A6d5A6d5a100g200z4() ;
	virtual ~CSteelType11A6d5A6d5a100g200z4() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetJbInner( const PmInt8 nJb ) ;
	PmInt8		GetJbInner() const ;

	void	SetDiaInner( const PmInt16 nDia ) ;
	PmInt16		GetDiaInner( ) const ;

protected:

	/// ����
	PmInt8		m_nJbInner  ;

	/// ֱ��
	PmInt16		m_nDiaInner ; 
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+ֱ��+ֱ��+��� (A6.5/8@100)
/// 
class PMLogicDataOprAPI CSteelTypeA6d5g6d5a100: public CSteelTypeA6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5g6d5a100 , parminfobase::eTypeA6d5g6d5a100 ) ; 
	CSteelTypeA6d5g6d5a100() ;
	virtual ~CSteelTypeA6d5g6d5a100() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	// ����ֱ��2
	void	SetDia2( const PmInt16 nDia2 ) ; 
	PmInt16	GetDia2() const ;

protected:

	PmInt16	m_nDia2 ;  // ֱ��2

};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+ֱ��+ֱ��+���+֫�� (A6.5/8@100(2))
/// 
class PMLogicDataOprAPI CSteelTypeA6d5g6d5a100z2: public CSteelTypeA6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5g6d5a100z2 , parminfobase::eTypeA6d5g6d5a100z2 ) ; 
	CSteelTypeA6d5g6d5a100z2() ;
	virtual ~CSteelTypeA6d5g6d5a100z2() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	// ����ֱ��2
	void	SetDia2( const PmInt16 nDia2 ) ; 
	PmInt16	GetDia2() const ;

	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:

	PmInt16	m_nDia2 ;  // ֱ��2
	PmInt8		m_nZs ; // ֫��

};


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+ֱ��+����+ֱ��+��� (A6.5/C8@100)
/// 
class PMLogicDataOprAPI CSteelTypeA6d5gA6d5a100: public CSteelTypeA6d5g6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5gA6d5a100 , parminfobase::eTypeA6d5gA6d5a100 ) ; 
	CSteelTypeA6d5gA6d5a100() ;
	virtual ~CSteelTypeA6d5gA6d5a100() ; 

protected:

	//�������ݣ�������Ҫ����
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
/// ����+ֱ��+����+ֱ��+���+֫�� (A6.5/C8@100(2))
/// 
class PMLogicDataOprAPI CSteelTypeA6d5gA6d5a100z2: public CSteelTypeA6d5gA6d5a100
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelTypeA6d5gA6d5a100z2 , parminfobase::eTypeA6d5gA6d5a100z2 ) ; 
	CSteelTypeA6d5gA6d5a100z2() ;
	virtual ~CSteelTypeA6d5gA6d5a100z2() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);
public:
	void	SetZs( const PmInt8 nZs ) ; 
	PmInt8	GetZs() const ;

protected:
	PmInt8		m_nZs ; // ֫��
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+����+ֱ��+������ (5A6.5 3/2)
/// 
class PMLogicDataOprAPI CSteelType5A6d5g3g2: public CSteelType5A6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5g3g2 , parminfobase::eType5A6d5g3g2 ) ; 
	CSteelType5A6d5g3g2() ;
	virtual ~CSteelType5A6d5g3g2() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);
public:

	/// ���Ÿ���
	void	SetSbGs( const PmInt8 nSbGs ) ; 
	PmInt8	GetSbGs() const ;

	/// ���Ÿ���
	void	SetXbGs( const PmInt8 nXbGs ) ; 
	PmInt8	GetXbGs() const ;

protected:
	PmInt8		m_nSbGs ;    /// ���Ÿ���
	PmInt8		m_nXbGs ;    /// ���Ÿ���
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+����+ֱ��+������ (6A6.5 3/2/1)
/// 
class PMLogicDataOprAPI CSteelType5A6d5g3g2add: public CSteelType5A6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5g3g2add , parminfobase::eType5A6d5g3g2add ) ; 
	CSteelType5A6d5g3g2add() ;
	virtual ~CSteelType5A6d5g3g2add() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);
public:

	/// ���Ÿ���
	int		GetSize() ;
	int		GetAt( const int iIdx ) ;

public:
	PmArray<PmInt8>	m_aryGsAdd ; 
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/// 
/// ����+����+ֱ��*N (6A6.5*2)
/// 
class PMLogicDataOprAPI CSteelType5A6d5gX2: public CSteelType5A6d5
{

public:
	DYNAMIC_CREATE_STEELDATA( CSteelType5A6d5gX2 , parminfobase::eType5A6d5gX2 ) ; 
	CSteelType5A6d5gX2() ;
	virtual ~CSteelType5A6d5gX2() ; 

protected:

	//�������ݣ�������Ҫ����
	virtual BOOL SerializeImp(CPmArchiveBase & arc) const;
	virtual BOOL DisSerializeImp(const CPmArchiveBase & arc);

public:
	void	SetGs( const PmInt16 nGs ) ; 
	PmInt16	GetGs() const ;

	void	SetXs( const PmInt16 nXs ) ; 
	PmInt16	GetXs() const ;

protected:

	/// ���� 
	PmInt16		m_nGs ; 
	PmInt16		m_nXs ; // ϵ��
};
