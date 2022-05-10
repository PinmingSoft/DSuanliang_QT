// CreateTableFromExcel.h: interface for the CCreateTableFromExcel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CREATETABLEFROMEXCEL_H__38304CD8_B2BB_41CA_A41F_BCB8204388A8__INCLUDED_)
#define AFX_CREATETABLEFROMEXCEL_H__38304CD8_B2BB_41CA_A41F_BCB8204388A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCreateTableFromExcel  
{
public:
	/// �ӿ�ѡ��excel����е�������
	static bool LoadFromExcelCellSelected(CArray<CStringArray *> & tag);

	/**
	* @brief   ��excel����wps��ȡ�������
	*
	*			
	* @note  : 
	* @param : 
	* @return: TRUE/FALSE
	* @author: zfy
	* @date  : [7/1/2019]
	*/
	static bool LoadFromExcel(CString excelFile,std::map<CString,NDataModelDataSet *> & sheets);
	/// ��wps��ȡ�ļ�
	static bool LoadFromWps(CString excelFile,std::map<CString,NDataModelDataSet *> & contents);
	static bool LoadFromWpsOld(CString excelFile,std::map<CString,NDataModelDataSet *> & contents);
#if PMVCCUR_VER >= PMVC2008_VER
	/// ͨ��NPOI ��ʽ��ȡ�ļ�
	static bool LoadFromNPOI(CString excelFile,std::map<CString,NDataModelDataSet *> & contents);
#endif

	//
	CCreateTableFromExcel();
	virtual ~CCreateTableFromExcel();

private:


	/// ��ȡexcel�������
	static NDataModelDataSet * ReadSheet(Range * pRange);

	/// ��ȡwps�������
	static NDataModelDataSet * ReadSheetWps(COleDispatchDriver * pRange);	//CRange * pRange;
	static NDataModelDataSet * ReadSheetWps(QObject * pWpsTable);
};

#endif // !defined(AFX_CREATETABLEFROMEXCEL_H__38304CD8_B2BB_41CA_A41F_BCB8204388A8__INCLUDED_)
