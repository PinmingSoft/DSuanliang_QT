#include "StdAfx.h"
#include "PmQtExport.h"
#include "DlgWbqd.h"
#include "DlgQDDE.h"

QApplication * g_qtApp = NULL;
void PmQtExport::DoCommand_Wbqd()
{
	int iArgc = 0;
	if(NULL == g_qtApp)
	{
		g_qtApp = new QApplication(iArgc, NULL);
	}

	CDlgWbqd dlg;
	//CDlgQDDE dlg;
	dlg.exec();
} 

void PmQtExport::UnloadApplication()
{
	if (g_qtApp)
	{
		delete g_qtApp;
		g_qtApp = NULL;
	}
}