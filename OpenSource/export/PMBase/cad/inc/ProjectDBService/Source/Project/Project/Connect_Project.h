#pragma once

//#include "..\ConnectManager.h"


#define CheckTableIsLive_Marco(tablename,tableClass)	{\
	if ( !IsTableExsit( tablename ) )\
															{\
															tableClass temTableClass;\
															temTableClass.InitFieldStr();\
															temTableClass.SetTableName(tablename);\
															DoCreateSQLTable( &temTableClass ) ; \
															}\
														}

class PMProjectDBSERVICE CConnect_Project : public CConnect_sqlite
{
public:
	CConnect_Project(void);
	virtual ~CConnect_Project(void);

	virtual void CheckTableIsLive();
};


///////////////////////////////////////////////////////////////////////////
///
/// 链接报表的链接
///
class PMProjectDBSERVICE CConnect_Report : public CConnect_sqlite
{
public:
	CConnect_Report(void);
	virtual ~CConnect_Report(void);

	virtual void CheckTableIsLive();
};
