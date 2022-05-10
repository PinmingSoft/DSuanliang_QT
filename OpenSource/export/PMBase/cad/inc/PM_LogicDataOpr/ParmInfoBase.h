#pragma once



#define DYNAMIC_CREATE_PARMINFOBASE( CLASS_NAME , PARMTYPE ) \
	virtual CParmInfoBase * Create() const; \
	virtual BOOL IsKindOf(const  int & type) const; \
	static int desc() \
	{ \
	return PARMTYPE ; \
	} \
	virtual	int	GetType( ) const \
	{\
	return PARMTYPE ; \
	}\
	virtual CString GetClassName() const \
	{ \
	return _T(#CLASS_NAME); \
	}

#define DYNAMIC_IMPLEMENT_PARMINFOBASE(CLASS_NAME , PARMTYPE ) \
	CParmInfoBase * CLASS_NAME::Create() const{ \
	return PMNew(CLASS_NAME); \
	} \
	BOOL CLASS_NAME::IsKindOf(const int & type) const{ \
	if( PARMTYPE == type) \
	return TRUE; \
	else \
	return FALSE; \
	}


namespace parminfobase
{
	enum ParmType
	{
		eParmBase = 0 ,
		eParmSteelContainer = 1 ,
	} ;
}


class PMLogicDataOprAPI CParmInfoBase
{
public:
	DYNAMIC_CREATE_PARMINFOBASE( CParmInfoBase , parminfobase::eParmBase ) ; 

public:
	CParmInfoBase(void);
	virtual ~CParmInfoBase(void);

public:

	/// 只是为了统一接口，不需要实现
	virtual BOOL SerializeFrom(const CPmArchiveBase & archive);
	virtual BOOL SerializeTo(CPmArchiveBase & archive) const;

};


