/********************************************************************************
** Form generated from reading UI file 'DlgYJZH.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGYJZH_H
#define UI_DLGYJZH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DlgYJZH
{
public:
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QGroupBox *groupBox;
    QRadioButton *rdBtnImp;
    QRadioButton *rdBtnCur;

    void setupUi(QDialog *DlgYJZH)
    {
        if (DlgYJZH->objectName().isEmpty())
            DlgYJZH->setObjectName(QString::fromUtf8("DlgYJZH"));
        DlgYJZH->resize(312, 214);
        btnOk = new QPushButton(DlgYJZH);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setGeometry(QRect(70, 170, 75, 23));
        btnCancel = new QPushButton(DlgYJZH);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(170, 170, 75, 23));
        groupBox = new QGroupBox(DlgYJZH);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(49, 30, 211, 111));
        rdBtnImp = new QRadioButton(groupBox);
        rdBtnImp->setObjectName(QString::fromUtf8("rdBtnImp"));
        rdBtnImp->setGeometry(QRect(50, 40, 89, 16));
        rdBtnImp->setChecked(true);
        rdBtnCur = new QRadioButton(groupBox);
        rdBtnCur->setObjectName(QString::fromUtf8("rdBtnCur"));
        rdBtnCur->setGeometry(QRect(50, 70, 101, 16));

        retranslateUi(DlgYJZH);
        QObject::connect(btnOk, SIGNAL(clicked()), DlgYJZH, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), DlgYJZH, SLOT(close()));

        QMetaObject::connectSlotsByName(DlgYJZH);
    } // setupUi

    void retranslateUi(QDialog *DlgYJZH)
    {
        DlgYJZH->setWindowTitle(QApplication::translate("DlgYJZH", "\344\270\200\351\224\256\350\275\254\345\214\226", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("DlgYJZH", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("DlgYJZH", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DlgYJZH", "\345\233\276\347\272\270\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        rdBtnImp->setText(QApplication::translate("DlgYJZH", "\345\257\274\345\205\245\345\233\276\347\272\270", 0, QApplication::UnicodeUTF8));
        rdBtnCur->setText(QApplication::translate("DlgYJZH", "\344\275\277\347\224\250\345\275\223\345\211\215\345\233\276\347\272\270", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgYJZH: public Ui_DlgYJZH {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGYJZH_H
