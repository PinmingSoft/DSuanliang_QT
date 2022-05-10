#include "stdafx.h"
#include "DlgYJZH.h"

DlgYJZH::DlgYJZH(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
	ui.btnOk->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
	ui.btnCancel->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

	QObject::connect(ui.rdBtnImp, SIGNAL(clicked()), this, SLOT(On_rbBtnClicked()));
	QObject::connect(ui.rdBtnCur, SIGNAL(clicked()), this, SLOT(On_rbBtnClicked()));

	m_select = 1;
}

DlgYJZH::~DlgYJZH()
{

}

void DlgYJZH::On_rbBtnClicked()
{
	if (ui.rdBtnImp->isChecked())
	{
		m_select = 1;
	}
	else if (ui.rdBtnCur->isChecked())
	{
		m_select = 2;
	}
	else
	{
		m_select = 0;
	}
}

int DlgYJZH::GetSelected()
{
	return m_select;
}