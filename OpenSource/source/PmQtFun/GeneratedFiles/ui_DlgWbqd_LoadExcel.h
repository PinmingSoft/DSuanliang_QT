/********************************************************************************
** Form generated from reading UI file 'DlgWbqd_LoadExcel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGWBQD_LOADEXCEL_H
#define UI_DLGWBQD_LOADEXCEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgWbqd_LoadExcel
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBoxSheet;
    QSpacerItem *horizontalSpacer;
    QTableView *tableViewContent;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonCover;
    QRadioButton *radioButtonAppend;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *CDlgWbqd_LoadExcel)
    {
        if (CDlgWbqd_LoadExcel->objectName().isEmpty())
            CDlgWbqd_LoadExcel->setObjectName(QString::fromUtf8("CDlgWbqd_LoadExcel"));
        CDlgWbqd_LoadExcel->resize(916, 748);
        verticalLayout = new QVBoxLayout(CDlgWbqd_LoadExcel);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(CDlgWbqd_LoadExcel);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        comboBoxSheet = new QComboBox(frame);
        comboBoxSheet->setObjectName(QString::fromUtf8("comboBoxSheet"));
        sizePolicy.setHeightForWidth(comboBoxSheet->sizePolicy().hasHeightForWidth());
        comboBoxSheet->setSizePolicy(sizePolicy);
        comboBoxSheet->setMinimumSize(QSize(200, 25));
        comboBoxSheet->setMaximumSize(QSize(200, 25));

        horizontalLayout->addWidget(comboBoxSheet);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(frame);

        tableViewContent = new QTableView(CDlgWbqd_LoadExcel);
        tableViewContent->setObjectName(QString::fromUtf8("tableViewContent"));

        verticalLayout->addWidget(tableViewContent);

        frame_2 = new QFrame(CDlgWbqd_LoadExcel);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButtonCover = new QRadioButton(frame_2);
        radioButtonCover->setObjectName(QString::fromUtf8("radioButtonCover"));
        radioButtonCover->setMinimumSize(QSize(50, 30));
        radioButtonCover->setMaximumSize(QSize(50, 30));
        radioButtonCover->setChecked(true);

        horizontalLayout_2->addWidget(radioButtonCover);

        radioButtonAppend = new QRadioButton(frame_2);
        radioButtonAppend->setObjectName(QString::fromUtf8("radioButtonAppend"));
        radioButtonAppend->setMinimumSize(QSize(50, 30));
        radioButtonAppend->setMaximumSize(QSize(50, 30));

        horizontalLayout_2->addWidget(radioButtonAppend);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButtonSave = new QPushButton(frame_2);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setMinimumSize(QSize(100, 30));
        pushButtonSave->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(frame_2);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(100, 30));
        pushButtonCancel->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(pushButtonCancel);


        verticalLayout->addWidget(frame_2);


        retranslateUi(CDlgWbqd_LoadExcel);
        QObject::connect(comboBoxSheet, SIGNAL(currentIndexChanged(QString)), CDlgWbqd_LoadExcel, SLOT(On_ComboBoxSheet_CurrentIndexChanged(QString)));
        QObject::connect(pushButtonSave, SIGNAL(clicked()), CDlgWbqd_LoadExcel, SLOT(On_pushButtonSave_Clicked()));
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), CDlgWbqd_LoadExcel, SLOT(close()));

        QMetaObject::connectSlotsByName(CDlgWbqd_LoadExcel);
    } // setupUi

    void retranslateUi(QWidget *CDlgWbqd_LoadExcel)
    {
        CDlgWbqd_LoadExcel->setWindowTitle(QApplication::translate("CDlgWbqd_LoadExcel", "\345\257\274\345\205\245Excel\346\270\205\345\215\225", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CDlgWbqd_LoadExcel", "\351\200\211\346\213\251\345\267\245\344\275\234\350\241\250:", 0, QApplication::UnicodeUTF8));
        radioButtonCover->setText(QApplication::translate("CDlgWbqd_LoadExcel", "\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8));
        radioButtonAppend->setText(QApplication::translate("CDlgWbqd_LoadExcel", "\350\277\275\345\212\240", 0, QApplication::UnicodeUTF8));
        pushButtonSave->setText(QApplication::translate("CDlgWbqd_LoadExcel", "\345\257\274\345\205\245", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("CDlgWbqd_LoadExcel", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CDlgWbqd_LoadExcel: public Ui_CDlgWbqd_LoadExcel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGWBQD_LOADEXCEL_H
