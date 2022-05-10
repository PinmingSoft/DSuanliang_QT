/********************************************************************************
** Form generated from reading UI file 'DlgQDDE.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGQDDE_H
#define UI_DLGQDDE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgQDDE
{
public:
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabQD;
    QVBoxLayout *verticalLayout;
    QTreeView *treeView_QD_Top;
    QFrame *frame_QD;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonQD_QD;
    QRadioButton *radioButtonQD_DE;
    QComboBox *comboBox_QD;
    QPushButton *pushButton_Search_QD;
    QTreeView *treeView_QD_Bottom;
    QWidget *tabDE;
    QVBoxLayout *verticalLayout_2;
    QTreeView *treeView_DE_Top;
    QFrame *frame_DE;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButtonDE;
    QComboBox *comboBox_DE;
    QPushButton *pushButton_Search_DE;
    QListView *listView_DE_Bottom;

    void setupUi(QDialog *CDlgQDDE)
    {
        if (CDlgQDDE->objectName().isEmpty())
            CDlgQDDE->setObjectName(QString::fromUtf8("CDlgQDDE"));
        CDlgQDDE->resize(350, 874);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CDlgQDDE->sizePolicy().hasHeightForWidth());
        CDlgQDDE->setSizePolicy(sizePolicy);
        CDlgQDDE->setMinimumSize(QSize(350, 0));
        CDlgQDDE->setMaximumSize(QSize(350, 16777215));
        horizontalLayout_2 = new QHBoxLayout(CDlgQDDE);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget = new QTabWidget(CDlgQDDE);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabQD = new QWidget();
        tabQD->setObjectName(QString::fromUtf8("tabQD"));
        tabQD->setEnabled(true);
        verticalLayout = new QVBoxLayout(tabQD);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeView_QD_Top = new QTreeView(tabQD);
        treeView_QD_Top->setObjectName(QString::fromUtf8("treeView_QD_Top"));
        treeView_QD_Top->setIndentation(20);
        treeView_QD_Top->setUniformRowHeights(false);
        treeView_QD_Top->setSortingEnabled(false);
        treeView_QD_Top->setWordWrap(false);

        verticalLayout->addWidget(treeView_QD_Top);

        frame_QD = new QFrame(tabQD);
        frame_QD->setObjectName(QString::fromUtf8("frame_QD"));
        frame_QD->setFrameShape(QFrame::StyledPanel);
        frame_QD->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_QD);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButtonQD_QD = new QRadioButton(frame_QD);
        radioButtonQD_QD->setObjectName(QString::fromUtf8("radioButtonQD_QD"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(radioButtonQD_QD->sizePolicy().hasHeightForWidth());
        radioButtonQD_QD->setSizePolicy(sizePolicy1);
        radioButtonQD_QD->setChecked(true);

        horizontalLayout->addWidget(radioButtonQD_QD);

        radioButtonQD_DE = new QRadioButton(frame_QD);
        radioButtonQD_DE->setObjectName(QString::fromUtf8("radioButtonQD_DE"));
        sizePolicy1.setHeightForWidth(radioButtonQD_DE->sizePolicy().hasHeightForWidth());
        radioButtonQD_DE->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(radioButtonQD_DE);

        comboBox_QD = new QComboBox(frame_QD);
        comboBox_QD->setObjectName(QString::fromUtf8("comboBox_QD"));
        comboBox_QD->setEditable(false);

        horizontalLayout->addWidget(comboBox_QD);

        pushButton_Search_QD = new QPushButton(frame_QD);
        pushButton_Search_QD->setObjectName(QString::fromUtf8("pushButton_Search_QD"));
        sizePolicy1.setHeightForWidth(pushButton_Search_QD->sizePolicy().hasHeightForWidth());
        pushButton_Search_QD->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_Search_QD);


        verticalLayout->addWidget(frame_QD);

        treeView_QD_Bottom = new QTreeView(tabQD);
        treeView_QD_Bottom->setObjectName(QString::fromUtf8("treeView_QD_Bottom"));

        verticalLayout->addWidget(treeView_QD_Bottom);

        tabWidget->addTab(tabQD, QString());
        tabDE = new QWidget();
        tabDE->setObjectName(QString::fromUtf8("tabDE"));
        verticalLayout_2 = new QVBoxLayout(tabDE);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        treeView_DE_Top = new QTreeView(tabDE);
        treeView_DE_Top->setObjectName(QString::fromUtf8("treeView_DE_Top"));

        verticalLayout_2->addWidget(treeView_DE_Top);

        frame_DE = new QFrame(tabDE);
        frame_DE->setObjectName(QString::fromUtf8("frame_DE"));
        frame_DE->setFrameShape(QFrame::StyledPanel);
        frame_DE->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_DE);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioButtonDE = new QRadioButton(frame_DE);
        radioButtonDE->setObjectName(QString::fromUtf8("radioButtonDE"));
        sizePolicy1.setHeightForWidth(radioButtonDE->sizePolicy().hasHeightForWidth());
        radioButtonDE->setSizePolicy(sizePolicy1);
        radioButtonDE->setChecked(true);

        horizontalLayout_3->addWidget(radioButtonDE);

        comboBox_DE = new QComboBox(frame_DE);
        comboBox_DE->setObjectName(QString::fromUtf8("comboBox_DE"));
        comboBox_DE->setEditable(false);

        horizontalLayout_3->addWidget(comboBox_DE);

        pushButton_Search_DE = new QPushButton(frame_DE);
        pushButton_Search_DE->setObjectName(QString::fromUtf8("pushButton_Search_DE"));
        sizePolicy1.setHeightForWidth(pushButton_Search_DE->sizePolicy().hasHeightForWidth());
        pushButton_Search_DE->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(pushButton_Search_DE);


        verticalLayout_2->addWidget(frame_DE);

        listView_DE_Bottom = new QListView(tabDE);
        listView_DE_Bottom->setObjectName(QString::fromUtf8("listView_DE_Bottom"));

        verticalLayout_2->addWidget(listView_DE_Bottom);

        tabWidget->addTab(tabDE, QString());

        horizontalLayout_2->addWidget(tabWidget);


        retranslateUi(CDlgQDDE);
        QObject::connect(treeView_DE_Top, SIGNAL(clicked(QModelIndex)), CDlgQDDE, SLOT(On_ClickedTree_View_DE(QModelIndex)));
        QObject::connect(treeView_QD_Top, SIGNAL(clicked(QModelIndex)), CDlgQDDE, SLOT(On_ClickedTree_View_QD(QModelIndex)));
        QObject::connect(treeView_QD_Top, SIGNAL(doubleClicked(QModelIndex)), CDlgQDDE, SLOT(On_DoubleClickedTree_View_QD(QModelIndex)));
        QObject::connect(listView_DE_Bottom, SIGNAL(doubleClicked(QModelIndex)), CDlgQDDE, SLOT(On_DoubleClickedList_View_DE(QModelIndex)));
        QObject::connect(treeView_QD_Bottom, SIGNAL(doubleClicked(QModelIndex)), CDlgQDDE, SLOT(On_DoubleClickedList_View_QD(QModelIndex)));
        QObject::connect(pushButton_Search_QD, SIGNAL(clicked()), CDlgQDDE, SLOT(OnBtnQd()));
        QObject::connect(pushButton_Search_DE, SIGNAL(clicked()), CDlgQDDE, SLOT(OnBtnDe()));
        QObject::connect(radioButtonQD_QD, SIGNAL(clicked()), CDlgQDDE, SLOT(On_ClickedRadioButton_QD()));
        QObject::connect(radioButtonQD_DE, SIGNAL(clicked()), CDlgQDDE, SLOT(On_ClickedRadioButton_DE()));
        QObject::connect(treeView_QD_Bottom, SIGNAL(expanded(QModelIndex)), CDlgQDDE, SLOT(On_ClickedTree_Node()));
        QObject::connect(treeView_QD_Bottom, SIGNAL(collapsed(QModelIndex)), CDlgQDDE, SLOT(On_ClickedTree_Node()));
        QObject::connect(treeView_QD_Top, SIGNAL(collapsed(QModelIndex)), CDlgQDDE, SLOT(On_ClickedTree_Node()));
        QObject::connect(treeView_QD_Top, SIGNAL(expanded(QModelIndex)), CDlgQDDE, SLOT(On_ClickedTree_Node()));
        QObject::connect(comboBox_QD, SIGNAL(activated(QString)), CDlgQDDE, SLOT(On_ActiveComBox_QD()));
        QObject::connect(comboBox_DE, SIGNAL(activated(QString)), CDlgQDDE, SLOT(On_ActiveComBox_DE()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CDlgQDDE);
    } // setupUi

    void retranslateUi(QDialog *CDlgQDDE)
    {
        CDlgQDDE->setWindowTitle(QApplication::translate("CDlgQDDE", "\346\270\205\345\215\225\345\256\232\351\242\235", 0, QApplication::UnicodeUTF8));
        radioButtonQD_QD->setText(QApplication::translate("CDlgQDDE", "\346\270\205\345\215\225", 0, QApplication::UnicodeUTF8));
        radioButtonQD_DE->setText(QApplication::translate("CDlgQDDE", "\345\256\232\351\242\235", 0, QApplication::UnicodeUTF8));
        pushButton_Search_QD->setText(QApplication::translate("CDlgQDDE", "\346\220\234\347\264\242", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabQD), QApplication::translate("CDlgQDDE", "\346\270\205\345\215\225", 0, QApplication::UnicodeUTF8));
        radioButtonDE->setText(QApplication::translate("CDlgQDDE", "\345\256\232\351\242\235", 0, QApplication::UnicodeUTF8));
        pushButton_Search_DE->setText(QApplication::translate("CDlgQDDE", "\346\220\234\347\264\242", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabDE), QApplication::translate("CDlgQDDE", "\345\256\232\351\242\235", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CDlgQDDE: public Ui_CDlgQDDE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGQDDE_H
