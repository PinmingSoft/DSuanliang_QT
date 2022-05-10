#pragma once
////#include "..\accesstable.h"

class PMProjectDBSERVICE CAccessPublicGj_GraphMapTable :
	public CPMSLAccessTable
{
public:
	CAccessPublicGj_GraphMapTable(void);

	~CAccessPublicGj_GraphMapTable(void);

	virtual BOOL TryUpdateTableField();

	BOOL DelOneRow( int nVectorID,  int nGraphicsVectorID );

	BOOL Insert( int nVectorID,  int nGraphicsVecotID);
};
