#ifndef DLGYJZH_H
#define DLGYJZH_H

#include <QDialog>
#include "ui_DlgYJZH.h"

class DlgYJZH : public QDialog
{
	Q_OBJECT

public:
	DlgYJZH(QWidget *parent = 0);
	~DlgYJZH();

	int GetSelected();

private slots:
	void On_rbBtnClicked();

private:
	Ui::DlgYJZH ui;

	int m_select;
};

#endif // DLGYJZH_H
