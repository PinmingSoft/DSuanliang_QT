#include "StdAfx.h"
#include "PmQtCmd.h"
#include "DlgYJZH.h"

extern QApplication * g_qtApp;

int PmQtCmd::DoCommand_YJZH()
{
	int iArgc = 0;
	if(NULL == g_qtApp)
	{
		g_qtApp = new QApplication(iArgc, NULL);
	}

	DlgYJZH dlg;
	if (QDialog::Accepted == dlg.exec())
	{
		int sel = dlg.GetSelected();
		return sel;
	}

	return 0;
}