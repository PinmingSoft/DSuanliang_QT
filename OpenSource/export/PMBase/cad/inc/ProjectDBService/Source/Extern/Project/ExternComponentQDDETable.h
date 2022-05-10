#pragma once

#include "../ExternManager.h"

class PMProjectDBSERVICE CExternComponentQDDETable : public CExternTableBase
{
public:
	CExternComponentQDDETable(void);
	virtual ~CExternComponentQDDETable(void);

	BOOL GetComID_QDDEDataSet(int iComID,CProject_QDDE_UITable *& pQDDETable);

	BOOL Delete_QDDEDataSet(int iComID) ;


	BOOL SetComID_NewQDDEDataSet(int iComID,CProject_QDDE_UITable * pQDDETable);

	BOOL UpdateComID_QDDEDataSet(int iComID,CProject_QDDE_UITable * pQDDETable);


protected:

	BOOL GetQDDEDataSet_Info(int iInsertRow,CProject_QDDE_UITable * pQDDEDataSet,int iQDComIDTableID);

	BOOL GetQDDEDataSet_XMTZ(int iInsertRow,CProject_QDDE_UITable * pQDDEDataSet,int iQDComIDTableID);


	BOOL InsertQDInfo(BOOL bQDMode,int iComID,int iInsertRow,CProject_QDDE_UITable * pQDDEDataSet,\
		int & iMaxQDComTableID ,int & iMaxQDInfoTableID ,int & iMaxQDXMTZTableID);

	BOOL InsertQDInfo_ComID(BOOL bQDMode,int iInsertRow,int iComID,\
		CProject_QDDE_UITable * pQDDEDataSet,int iMaxQDComTableID);

	BOOL InsertQDInfo_XMTZ(int iInsertRow,int iComID,CProject_QDDE_UITable * pQDDEDataSet,\
		int iQDComIDTableID,int & iMaxQDXMTZTableID);

	BOOL InsertQDInfo_Info(int iInsertRow,int iComID,CProject_QDDE_UITable *pQDDEDataSet,\
		int iMaxQDComTableID, int iMaxQDInfoTableID);

	BOOL MdfQDInfo(BOOL bQDMode,int iComID,int iMdfRow,CProject_QDDE_UITable * pQDDEDataSet,\
		int & iMaxQDXMTZTableID);

	BOOL MdfQDInfo_ComID(BOOL bQDMode,int iMdfRow,CProject_QDDE_UITable * pQDDEDataSet);

	BOOL MdfQDInfo_Info(int iMdfRow,int iComID,CProject_QDDE_UITable *pQDDEDataSet);

	BOOL DeleteQDInfo_ComID(int iQDID);

	BOOL DeleteQDInfo_XMTZ(int iQDID);

	BOOL DeleteQDInfo_Info(int iQDInfoID);

};
