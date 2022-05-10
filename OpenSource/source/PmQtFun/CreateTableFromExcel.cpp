// CreateTableFromExcel.cpp: implementation of the CCreateTableFromExcel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CreateTableFromExcel.h"
// #include "excel9.h"
#include <comdef.h>
#include "WPSTable.h"
#include "CApplication.h"
#include "CRange.h"
#include "CRanges.h"
#include "CWorkbook.h"
#include "CWorkbooks.h"
#include "CWorksheet.h"
#include "CWorksheets.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCreateTableFromExcel::CCreateTableFromExcel()
{

}

CCreateTableFromExcel::~CCreateTableFromExcel()
{

}

bool CCreateTableFromExcel::LoadFromExcelCellSelected(CArray<CStringArray *>& tag)
{
	CString strErrNoExcel = _T("请先运行Excel并选中需要转化的单元格!");
	CString strErrNoSel = _T("请先在Excel中选中需要转化的列!");

#ifdef _USE_OFFICE2003_
	Excel::_ApplicationPtr pApplication = NULL;
	HRESULT hr = pApplication.GetActiveObject("Excel.Application");
	if(FAILED(hr))
	{
		UIFunction::PMMessageBox(strErrNoExcel);
		return false;
	}

// 	_WorksheetPtr pThisWorksheet = pApplication->GetActiveSheet();

	Excel::WindowPtr wp = pApplication->GetActiveWindow();
	if(wp == NULL)	///Excel隐藏在后台
	{
		UIFunction::PMMessageBox(strErrNoExcel);
		return false;
	}
	
	Excel::RangePtr pThisRange = wp->GetRangeSelection();
	
	Excel::RangePtr cols = pThisRange->GetColumns();
	int colnum = cols->GetCount();
	Excel::RangePtr rows = pThisRange->GetRows();
	int rownum = rows->GetCount();

	if(colnum < 1)
	{
		UIFunction::PMMessageBox(strErrNoSel);
		return false;
	}
	if(rownum == 0)
	{
		return false;
	}

	_variant_t vt;
	CStringArray *pOneLine;
	CString str;
	for(int i=1; i<=rownum; i++)
	{
		pOneLine = PMNew(CStringArray);
		for(int j=1; j<=colnum; j++)
		{
			vt = pThisRange->GetItem(_variant_t((long)i), _variant_t((long)j));
			str = _bstr_t(vt).copy();
			pOneLine->Add(str);
		}
		tag.Add(pOneLine);
	}
#else

	_Application * pExcelApp = NULL;
	Range * pRg = NULL,* pColRg = NULL,*pRowRg = NULL;
	try
	{
		HRESULT hr = NOERROR;
		CLSID clsid;
		hr = ::CLSIDFromProgID(L"Excel.Application", &clsid);
		if (FAILED(hr))
		{
			UIFunction::PMMessageBox(strErrNoExcel + _T(":1"));
			return false;
		}

		LPUNKNOWN pUnk = NULL;
		if(::GetActiveObject(clsid, NULL, &pUnk) != S_OK)
		{
			UIFunction::PMMessageBox(strErrNoExcel + _T(":2"));
			return false;
		}

		LPDISPATCH pExcel = NULL;
		hr = pUnk->QueryInterface(IID_IDispatch, (LPVOID*) &pExcel);
		pUnk->Release();
		if (FAILED(hr))
		{
			UIFunction::PMMessageBox(strErrNoExcel + _T(":3"));
			return false;
		}

		// 	LPDISPATCH pExcel = NULL;
		// 	GetActiveObject("Excel.Application", pExcel);
		// 	if(pExcel == NULL)
		// 	{
		// 		UIFunction::PMMessageBox(strErrNoExcel);
		// 		return false;
		// 	}

		pExcelApp = PMNew_Parm(_Application,(pExcel));
		LPDISPATCH pSel = NULL;
		pSel = pExcelApp->GetSelection();
		if(pSel == NULL)
		{
			UIFunction::PMMessageBox(strErrNoExcel + _T(":4"));
			return false;
		}

		pRg = PMNew_Parm(Range,(pSel));
		long count = pRg->GetCount();
		if(count < 1)
		{
			UIFunction::PMMessageBox(strErrNoSel + _T(":5"));
			return false;
		}

		pColRg = PMNew_Parm(Range,(pRg->GetColumns()));
		pRowRg = PMNew_Parm(Range,(pRg->GetRows()));	
		int colnum = pColRg->GetCount();
		int rownum = pRowRg->GetCount();
		CString str;
		_variant_t vt;

		//通过行（选取5行）过滤列
		{
			CUIntArray iFillRowArr;
			iFillRowArr.Add(1);
			if(rownum > 10)
				iFillRowArr.Add(10);
			iFillRowArr.Add(rownum / 4);
			iFillRowArr.Add(rownum / 2);
			iFillRowArr.Add(rownum * 3 / 4);

			for (int i = colnum ;i > 1;i--)
			{
				BOOL bIsEmpty = TRUE;
				for (int j = 0;j < iFillRowArr.GetSize();j++)
				{
					vt = pRg->GetItem(_variant_t((long)iFillRowArr[j]), _variant_t((long)i));
					str = _bstr_t(vt).copy();
					if(str.GetLength() > 0)
					{
						bIsEmpty = FALSE;
						break;
					}
				}
				colnum = i;
				if(FALSE == bIsEmpty)
					break;
			}
		}

		CStringArray *pOneLine;

		//wjy 判断选取行是否需要截断，10行空行截断
		int iEmptyRow = 0;

		for(int i=1; i<=rownum; i++)
		{
			pOneLine = PMNew(CStringArray);

			BOOL bIsEmpty = TRUE;
			for(int j=1; j<=colnum; j++)
			{
				vt = pRg->GetItem(_variant_t((long)i), _variant_t((long)j));
				str = _bstr_t(vt).copy();
				if (str.Left(1) == _T("."))//小于1的时候的处理
				{
					str = _T("0")+str;
				}
				if (str.Left(2) == _T("-."))
				{
					str.Insert(1,_T("0"));
				}
				if(str.GetLength() > 0)
					bIsEmpty = FALSE;
				pOneLine->Add(str);
			}

			if(bIsEmpty)
			{
				iEmptyRow++;
				if(iEmptyRow > 10)
					break;
			}
			else
				iEmptyRow = 0;

			tag.Add(pOneLine);
		}

		//清除空行
		for(int i = 0;i < tag.GetSize();i++)
		{ 
			BOOL bIsEmpty = TRUE;
			CStringArray * pStringArr = tag[i];

			for (int j = 0;j < pStringArr->GetSize();j++)
			{
				if(pStringArr->GetAt(j).GetLength())
				{
					bIsEmpty = FALSE;
					break;
				}
			}
			if(FALSE == bIsEmpty)
				continue;

			PMDelete(pStringArr);
			tag.RemoveAt(i);
			i--;
		}
		
	}
	catch (CException* e)
	{
		UIFunction::PMMessageBox(strErrNoSel + _T(":100"));
	}

	if(pColRg)
	{
		pColRg->ReleaseDispatch();
		delete pColRg;
	}
	if(pRowRg)
	{
		pRowRg->ReleaseDispatch();
		delete pRowRg;
	}
	if(pRg)
	{
		pRg->ReleaseDispatch();
		delete pRg;
	}
	if(pExcelApp)
	{
		pExcelApp->ReleaseDispatch();
		delete pExcelApp;
	}
	
#endif
	return true;
}

bool CCreateTableFromExcel::LoadFromExcel(CString excelFile,std::map<CString,NDataModelDataSet *> & contents)
{
	//启动excel服务
	_Application app;
	LPDISPATCH lpDisp;
	COleVariant vResult;
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	COleException exp;
	if (!app.CreateDispatch(_T("Excel.Application"),&exp))
	{
		AfxMessageBox(_T("无法启动Excel服务器!!!"));
		return false;
	}
	lpDisp = app.GetApplication();
	if (NULL == lpDisp)
	{
		AfxMessageBox(_T("启动Excel服务器失败1"));
		return false;		
	}

	//加载进度条
	QProgressDialog progressDlg(QObject::tr("当前导入进度为："),QObject::tr("确定"),0,100);

	progressDlg.setWindowTitle(QObject::tr("正在导入，请等待")); //设置窗口标题
	progressDlg.resize(400,45);
	progressDlg.setWindowModality(Qt::WindowModal);//将对话框设置为模态
	progressDlg.show();


	//得到Workbook 
	Workbooks books;
	lpDisp = app.GetWorkbooks();
	if (NULL == lpDisp)
	{
		QMessageBox::about(NULL,"",QObject::tr("启动Excel服务器失败2"));
		return false;		
	}
	books.AttachDispatch(lpDisp);
	try
	{
		lpDisp = books.Open(excelFile,covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional,covOptional); 
	}
	catch (COleDispatchException* pException)
	{
		CString strErrorMsg;
		pException->GetErrorMessage(strErrorMsg.GetBuffer(256), 256);
		strErrorMsg.ReleaseBuffer();
		AfxMessageBox(strErrorMsg);

		//
		app.Quit(); // 退出 
		app.ReleaseDispatch();
		return false;
	}
	catch (...)
	{
		QMessageBox::about(NULL,"",QObject::tr("打开文件失败"));
		app.Quit(); // 退出 
		app.ReleaseDispatch();
		return false;
	}

	//
	_Workbook book;
	book.AttachDispatch(lpDisp);

	//得到Worksheet
	lpDisp = book.GetWorksheets();
	Worksheets sheets;
	sheets.AttachDispatch(lpDisp);

	//
	long nSheetCount = sheets.GetCount();
	try
	{
		for(int i = 1;i <= nSheetCount;i++)
		{
			_Worksheet sheet;
			Range range;
			sheet.AttachDispatch(sheets.GetItem(COleVariant((long)i)));
			range.AttachDispatch(sheet.GetCells(),TRUE);//加载所有单元格  
			int nColum = range.GetColumn();
			int nRow = range.GetRow();

			//
			CString strSheetName = sheet.GetName();

			//读取Excel表格内容
			NDataModelDataSet * pContent = ReadSheet(&range);
			contents.insert(std::make_pair(strSheetName,pContent));
			
			progressDlg.setValue((100.0/nSheetCount)* i);   //进度条的值
			QCoreApplication::processEvents(); //避免界面冻结
			//
			range.ReleaseDispatch();
			sheet.ReleaseDispatch();
		}
	}
	catch (...)
	{
		app.Quit(); // 退出 
		app.ReleaseDispatch();
		return false;
	}

	//
	books.Close();
	app.Quit(); // 退出 

	//释放对象 
	sheets.ReleaseDispatch();
	book.ReleaseDispatch();
	books.ReleaseDispatch();
	app.ReleaseDispatch();
	return true;
}

bool CCreateTableFromExcel::LoadFromWps(CString excelFile,std::map<CString,NDataModelDataSet *> & contents)
{
	//启动excel服务
	CApplication app;
	LPDISPATCH lpDisp;
	COleVariant vResult;
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	COleException exp;
	if (!app.CreateDispatch(_T("KET.Application"),&exp))
	{
		exp.ReportError();
		return false;
	}

	//加载进度条
	QProgressDialog progressDlg(QObject::tr("当前导入进度为："),QObject::tr("确定"),0,100);

	progressDlg.setWindowTitle(QObject::tr("正在导入，请等待")); //设置窗口标题
	progressDlg.resize(400,45);
	progressDlg.setWindowModality(Qt::WindowModal);//将对话框设置为模态
	progressDlg.show();


	//得到Workbook 
	CWorkbooks books;
	lpDisp = app.get_Workbooks();
	if (NULL == lpDisp)
	{
		QMessageBox::about(NULL,"",QObject::tr("启动Excel服务器失败2"));
		return false;		
	}
	books.AttachDispatch(lpDisp);
	try
	{
		lpDisp = books.Open(excelFile,covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional,covOptional); 
	}
	catch (COleDispatchException* pException)
	{
		CString strErrorMsg;
		pException->GetErrorMessage(strErrorMsg.GetBuffer(256), 256);
		strErrorMsg.ReleaseBuffer();
		AfxMessageBox(strErrorMsg);

		//
		app.Quit(); // 退出 
		app.ReleaseDispatch();
		return false;
	}
	catch (...)
	{
		QMessageBox::about(NULL,"",QObject::tr("打开文件失败"));
		app.Quit(); // 退出 
		app.ReleaseDispatch();
		return false;
	}

	//
	CWorkbook book;
	book.AttachDispatch(lpDisp);

	//得到Worksheet
	lpDisp = book.get_Worksheets();
	CWorksheets sheets;
	sheets.AttachDispatch(lpDisp);

	//
	long nSheetCount = sheets.get_Count();
	try
	{
		for(int i = 1;i <= nSheetCount;i++)
		{
			CWorksheet sheet;
			CRange range;
			sheet.AttachDispatch(sheets.get_Item(COleVariant((long)i)));
			range.AttachDispatch(sheet.get_Cells(),TRUE);//加载所有单元格  
			//int nColum = range.GetColumn();
			//int nRow = range.GetRow();

			//
			CString strSheetName = sheet.get_Name();

			//读取Excel表格内容
			NDataModelDataSet * pContent = ReadSheetWps(&range);
			contents.insert(std::make_pair(strSheetName,pContent));

			progressDlg.setValue((100.0/nSheetCount)* i);   //进度条的值
			QCoreApplication::processEvents(); //避免界面冻结
			//
			range.ReleaseDispatch();
			sheet.ReleaseDispatch();
		}
	}
	catch (...)
	{
		app.Quit(); // 退出 
		app.ReleaseDispatch();
		return false;
	}

	//
	books.Close();
	app.Quit(); // 退出 

	//释放对象 
	sheets.ReleaseDispatch();
	book.ReleaseDispatch();
	books.ReleaseDispatch();
	app.ReleaseDispatch();
	return true;
}

#if PMVCCUR_VER >= PMVC2008_VER
bool CCreateTableFromExcel::LoadFromNPOI(CString excelFile,std::map<CString,NDataModelDataSet *> & contents)
{
	ExcelOpr::CNPOIExcel npoi;
	npoi.SetExcelFilePath(excelFile);

	//通过NPOI 方式读取EXCEL
	CStringArray arrSheetName;
	CArray<NDataModelDataSet *> arrDataset;
	bool bOk = npoi.ExportToDataSet(arrSheetName,arrDataset);
	if (bOk)
	{
		for (int i = 0;i < arrSheetName.GetSize();i++)
		{
			CString strSheetName = arrSheetName[i];
			NDataModelDataSet * pDs = arrDataset[i];
			contents.insert(std::make_pair(strSheetName,pDs));
		}
	}

	//
	return bOk;
}
#endif

bool CCreateTableFromExcel::LoadFromWpsOld(CString excelFile,std::map<CString,NDataModelDataSet *> & contents)
{
	PMTSTRING strTmp = excelFile;
	QString qstrExcelFile = QStringFrom(strTmp);

	//启动excel服务
	CWPSTable wpsTable(true,true);
	wpsTable.getOpenWorkBook(qstrExcelFile);

	//加载进度条
	QProgressDialog progressDlg(QObject::tr("当前导入进度为："),QObject::tr("确定"),0,100);

	progressDlg.setWindowTitle(QObject::tr("正在导入，请等待")); //设置窗口标题
	progressDlg.resize(400,45);
	progressDlg.setWindowModality(Qt::WindowModal);//将对话框设置为模态
	progressDlg.show();


	//得到Workbook 
	wpsTable.getSheets();

	//sheet.AttachDispatch(lpDisp);
	long nSheetCount = wpsTable.countSheets();
	for(int i = 1;i <= nSheetCount;i++)
	{
		wpsTable.getSheet(i);
		QString qstrSheetName = wpsTable.getSheetName();

		//获取页名
		PMTSTRING strTmp = QStringTo(qstrSheetName);
		CString strSheetName = strTmp.c_str();

		//读取Excel表格内容
		NDataModelDataSet * pContent = ReadSheetWps(&wpsTable);
		contents.insert(std::make_pair(strSheetName,pContent));

		progressDlg.setValue((100.0/nSheetCount)* i);   //进度条的值
		QCoreApplication::processEvents(); //避免界面冻结
	}

	//释放对象 
	return true;
}

NDataModelDataSet * CCreateTableFromExcel::ReadSheet(Range * pRange)
{
	int nRowCount = 10000;
	int nColCount = 20;

	//
	NDataModelDataSet * pDataset = PMNew(NDataModelDataSet);
	for (int i = 0;i < nColCount;i++)
	{
		CString strFieldName = pmcommon::CStr(i+1);
		pDataset->AddField(strFieldName,ftBlob,0);
	}

	//wjy 判断选取行是否需要截断，10行空行截断
	int iEmptyRow = 0;
	for(int row = 1; row <= nRowCount;row++)
	{
		BOOL bIsEmpty = TRUE;

		//获取每个单元格的内容
		CStringArray arrColValue;
		int col = 0;
		for(col = 1; col <= nColCount; col++)
		{
			VARIANT vt = pRange->GetItem(_variant_t((long)row), _variant_t((long)col));
			CString str = _bstr_t(vt).copy();
			if (str.Left(1) == _T("."))//小于1的时候的处理
			{
				str = _T("0")+str;
			}
			if (str.Left(2) == _T("-."))
			{
				str.Insert(1,_T("0"));
			}
			if(str.GetLength() > 0)
				bIsEmpty = FALSE;

			//
			arrColValue.Add(str);
		}

		//判断是否连续多行都是空的，如果都是空的，则退出。否则记录本行
		if(bIsEmpty)
		{
			iEmptyRow++;
			if(iEmptyRow > 10)
				break;
		}
		else
		{
			iEmptyRow = 0;
			int nRowNew = pDataset->InsertRow(0);
			for (col = 0; col < nColCount && col < arrColValue.GetSize(); col++)
			{
				pDataset->SetAsString(col,nRowNew,arrColValue[col]);
			}
		}
	}

	//
	return pDataset;
}

NDataModelDataSet * CCreateTableFromExcel::ReadSheetWps(COleDispatchDriver * range)
{
	int nRowCount = 10000;
	int nColCount = 20;

	CRange * pRange = (CRange *)range;
	//
	NDataModelDataSet * pDataset = PMNew(NDataModelDataSet);
	for (int i = 0;i < nColCount;i++)
	{
		CString strFieldName = pmcommon::CStr(i+1);
		pDataset->AddField(strFieldName,ftBlob,0);
	}

	//wjy 判断选取行是否需要截断，10行空行截断
	int iEmptyRow = 0;
	for(int row = 1; row <= nRowCount;row++)
	{
		BOOL bIsEmpty = TRUE;

		//获取每个单元格的内容
		CStringArray arrColValue;
		int col = 0;
		for(col = 1; col <= nColCount; col++)
		{
			VARIANT vt = pRange->get_Item(_variant_t((long)row), _variant_t((long)col));
			CString str = _bstr_t(vt).copy();
			if (str.Left(1) == _T("."))//小于1的时候的处理
			{
				str = _T("0")+str;
			}
			if (str.Left(2) == _T("-."))
			{
				str.Insert(1,_T("0"));
			}
			if(str.GetLength() > 0)
				bIsEmpty = FALSE;

			//
			arrColValue.Add(str);
		}

		//判断是否连续多行都是空的，如果都是空的，则退出。否则记录本行
		if(bIsEmpty)
		{
			iEmptyRow++;
			if(iEmptyRow > 10)
				break;
		}
		else
		{
			iEmptyRow = 0;
			int nRowNew = pDataset->InsertRow(0);
			for (col = 0; col < nColCount && col < arrColValue.GetSize(); col++)
			{
				pDataset->SetAsString(col,nRowNew,arrColValue[col]);
			}
		}
	}

	//
	return pDataset;
}

NDataModelDataSet * CCreateTableFromExcel::ReadSheetWps(QObject * pWpsTable)
{
	int nRowCount = 10000;
	int nColCount = 20;

	//
	NDataModelDataSet * pDataset = PMNew(NDataModelDataSet);
	for (int i = 0;i < nColCount;i++)
	{
		CString strFieldName = pmcommon::CStr(i+1);
		pDataset->AddField(strFieldName,ftBlob,0);
	}

	//wjy 判断选取行是否需要截断，10行空行截断
	int iEmptyRow = 0;
	for(int row = 1; row <= nRowCount;row++)
	{
		BOOL bIsEmpty = TRUE;

		//获取每个单元格的内容
		CStringArray arrColValue;
		int col = 0;
		for(col = 1; col <= nColCount; col++)
		{
			QString qstrValue = ((CWPSTable *)pWpsTable)->getValue(row,col);
			PMTSTRING strTmp = QStringTo(qstrValue);
			CString str = strTmp.c_str();
			if (str.Left(1) == _T("."))//小于1的时候的处理
			{
				str = _T("0")+str;
			}
			if (str.Left(2) == _T("-."))
			{
				str.Insert(1,_T("0"));
			}
			if(str.GetLength() > 0)
				bIsEmpty = FALSE;

			//
			arrColValue.Add(str);
		}

		//判断是否连续多行都是空的，如果都是空的，则退出。否则记录本行
		if(bIsEmpty)
		{
			iEmptyRow++;
			if(iEmptyRow > 10)
				break;
		}
		else
		{
			iEmptyRow = 0;
			int nRowNew = pDataset->InsertRow(0);
			for (col = 0; col < nColCount && col < arrColValue.GetSize(); col++)
			{
				pDataset->SetAsString(col,nRowNew,arrColValue[col]);
			}
		}
	}

	//
	return pDataset;
}