/********************************************************************************
** Form generated from reading UI file 'DlgWbqd.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGWBQD_H
#define UI_DLGWBQD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTableView>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDlgWbqd
{
public:
    QHBoxLayout *horizontalLayoutMain;
    QFrame *frameMain;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonLoadExcel;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonRetract;
    QPushButton *pushButtonExpend;
    QPushButton *pushButtonMoveUp;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonUseQD;
    QFrame *frameWbqd;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QTreeView *treeViewWbqd;
    QTableView *tableViewXMTZ;

    void setupUi(QWidget *CDlgWbqd)
    {
        if (CDlgWbqd->objectName().isEmpty())
            CDlgWbqd->setObjectName(QString::fromUtf8("CDlgWbqd"));
        CDlgWbqd->resize(1025, 885);
        horizontalLayoutMain = new QHBoxLayout(CDlgWbqd);
        horizontalLayoutMain->setSpacing(0);
        horizontalLayoutMain->setContentsMargins(11, 11, 11, 11);
        horizontalLayoutMain->setObjectName(QString::fromUtf8("horizontalLayoutMain"));
        horizontalLayoutMain->setSizeConstraint(QLayout::SetDefaultConstraint);
        frameMain = new QFrame(CDlgWbqd);
        frameMain->setObjectName(QString::fromUtf8("frameMain"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameMain->sizePolicy().hasHeightForWidth());
        frameMain->setSizePolicy(sizePolicy);
        frameMain->setFrameShape(QFrame::StyledPanel);
        frameMain->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frameMain);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        frame = new QFrame(frameMain);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        pushButtonLoadExcel = new QPushButton(frame);
        pushButtonLoadExcel->setObjectName(QString::fromUtf8("pushButtonLoadExcel"));
        pushButtonLoadExcel->setMinimumSize(QSize(80, 30));
        pushButtonLoadExcel->setMaximumSize(QSize(80, 30));
        pushButtonLoadExcel->setLayoutDirection(Qt::LeftToRight);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/Resources/png/Form.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonLoadExcel->setIcon(icon);

        horizontalLayout->addWidget(pushButtonLoadExcel);

        pushButtonAdd = new QPushButton(frame);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setMinimumSize(QSize(80, 30));
        pushButtonAdd->setMaximumSize(QSize(80, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/png/Resources/png/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/png/Resources/png/Add.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButtonAdd->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonAdd);

        pushButtonDelete = new QPushButton(frame);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));
        pushButtonDelete->setMinimumSize(QSize(80, 30));
        pushButtonDelete->setMaximumSize(QSize(80, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/png/Resources/png/Erase.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDelete->setIcon(icon2);

        horizontalLayout->addWidget(pushButtonDelete);

        pushButtonRetract = new QPushButton(frame);
        pushButtonRetract->setObjectName(QString::fromUtf8("pushButtonRetract"));
        pushButtonRetract->setMinimumSize(QSize(80, 30));
        pushButtonRetract->setMaximumSize(QSize(80, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/png/Resources/png/Right.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRetract->setIcon(icon3);

        horizontalLayout->addWidget(pushButtonRetract);

        pushButtonExpend = new QPushButton(frame);
        pushButtonExpend->setObjectName(QString::fromUtf8("pushButtonExpend"));
        pushButtonExpend->setMinimumSize(QSize(80, 30));
        pushButtonExpend->setMaximumSize(QSize(80, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/png/Resources/png/Left.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExpend->setIcon(icon4);

        horizontalLayout->addWidget(pushButtonExpend);

        pushButtonMoveUp = new QPushButton(frame);
        pushButtonMoveUp->setObjectName(QString::fromUtf8("pushButtonMoveUp"));
        pushButtonMoveUp->setMinimumSize(QSize(80, 30));
        pushButtonMoveUp->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(pushButtonMoveUp);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButtonUseQD = new QPushButton(frame);
        pushButtonUseQD->setObjectName(QString::fromUtf8("pushButtonUseQD"));
        pushButtonUseQD->setMinimumSize(QSize(80, 30));
        pushButtonUseQD->setMaximumSize(QSize(80, 30));
        pushButtonUseQD->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(pushButtonUseQD);


        verticalLayout->addWidget(frame);

        frameWbqd = new QFrame(frameMain);
        frameWbqd->setObjectName(QString::fromUtf8("frameWbqd"));
        frameWbqd->setMinimumSize(QSize(0, 800));
        frameWbqd->setFrameShape(QFrame::StyledPanel);
        frameWbqd->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frameWbqd);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, 0, -1);
        splitter = new QSplitter(frameWbqd);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        treeViewWbqd = new QTreeView(splitter);
        treeViewWbqd->setObjectName(QString::fromUtf8("treeViewWbqd"));
        treeViewWbqd->setSizeIncrement(QSize(0, 0));
        treeViewWbqd->setBaseSize(QSize(0, 0));
        treeViewWbqd->setDragEnabled(false);
        treeViewWbqd->setDragDropMode(QAbstractItemView::NoDragDrop);
        splitter->addWidget(treeViewWbqd);
        tableViewXMTZ = new QTableView(splitter);
        tableViewXMTZ->setObjectName(QString::fromUtf8("tableViewXMTZ"));
        splitter->addWidget(tableViewXMTZ);

        verticalLayout_2->addWidget(splitter);


        verticalLayout->addWidget(frameWbqd);


        horizontalLayoutMain->addWidget(frameMain);


        retranslateUi(CDlgWbqd);
        QObject::connect(pushButtonLoadExcel, SIGNAL(clicked()), CDlgWbqd, SLOT(On_pushButtonLoadExcel_Clicked()));
        QObject::connect(pushButtonUseQD, SIGNAL(clicked()), CDlgWbqd, SLOT(On_pushButtonUseQD_Clicked()));
        QObject::connect(pushButtonAdd, SIGNAL(clicked()), CDlgWbqd, SLOT(On_pushButtonAdd_Clicked()));
        QObject::connect(pushButtonDelete, SIGNAL(clicked()), CDlgWbqd, SLOT(On_pushButtonDelete_Clicked()));
        QObject::connect(treeViewWbqd, SIGNAL(clicked(QModelIndex)), CDlgWbqd, SLOT(On_treeViewWbqd_Clicked(QModelIndex)));
        QObject::connect(pushButtonRetract, SIGNAL(clicked()), CDlgWbqd, SLOT(On_pushButtonRetract_Clicked()));
        QObject::connect(pushButtonExpend, SIGNAL(clicked()), CDlgWbqd, SLOT(On_pushButtonExpend_Clicked()));
        QObject::connect(pushButtonMoveUp, SIGNAL(clicked()), CDlgWbqd, SLOT(On_pushButtonMoveUp_Clicked()));
        QObject::connect(treeViewWbqd, SIGNAL(doubleClicked(QModelIndex)), CDlgWbqd, SLOT(On_treeViewWbqd_DoubleClicked(QModelIndex)));

        QMetaObject::connectSlotsByName(CDlgWbqd);
    } // setupUi

    void retranslateUi(QWidget *CDlgWbqd)
    {
        CDlgWbqd->setWindowTitle(QApplication::translate("CDlgWbqd", "\345\244\226\351\203\250\346\270\205\345\215\225", 0, QApplication::UnicodeUTF8));
        pushButtonLoadExcel->setText(QApplication::translate("CDlgWbqd", "\345\257\274\345\205\245Excel", 0, QApplication::UnicodeUTF8));
        pushButtonAdd->setText(QApplication::translate("CDlgWbqd", "\345\242\236\345\212\240", 0, QApplication::UnicodeUTF8));
        pushButtonDelete->setText(QApplication::translate("CDlgWbqd", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        pushButtonRetract->setText(QApplication::translate("CDlgWbqd", "\351\231\215\347\272\247", 0, QApplication::UnicodeUTF8));
        pushButtonExpend->setText(QApplication::translate("CDlgWbqd", "\345\215\207\347\272\247", 0, QApplication::UnicodeUTF8));
        pushButtonMoveUp->setText(QApplication::translate("CDlgWbqd", "\344\270\212\347\247\273", 0, QApplication::UnicodeUTF8));
        pushButtonUseQD->setText(QApplication::translate("CDlgWbqd", "\345\245\227\346\270\205\345\215\225>>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CDlgWbqd: public Ui_CDlgWbqd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGWBQD_H
