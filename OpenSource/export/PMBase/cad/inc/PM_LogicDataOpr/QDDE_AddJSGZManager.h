// QDDE_JSGZManager.h: interface for the CQDDE_AddJSGZManager class.
//
//////////////////////////////////////////////////////////////////////


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class PMLogicDataOprAPI CQDDE_AddJSGZManager  
{
public:
	NDataModelDataSet * m_pDataSetAddQDDEJSGZ;
	CQDDE_AddJSGZManager();
	virtual ~CQDDE_AddJSGZManager();
	BOOL LoadXML(CString sXMLName,CString strComName);
};
