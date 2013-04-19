/********************************************************************************
** Form generated from reading UI file 'mypreview.ui'
**
** Created: Wed Apr 17 14:43:08 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPREVIEW_H
#define UI_MYPREVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "myimage.h"

QT_BEGIN_NAMESPACE

class Ui_MyPreview
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QScrollArea *scrollArea;
    myimage *m_image;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QFrame *line_2;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *MyPreview)
    {
        if (MyPreview->objectName().isEmpty())
            MyPreview->setObjectName(QString::fromUtf8("MyPreview"));
        MyPreview->setWindowModality(Qt::ApplicationModal);
        MyPreview->resize(792, 519);
        verticalLayout = new QVBoxLayout(MyPreview);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line = new QFrame(MyPreview);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        scrollArea = new QScrollArea(MyPreview);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setAutoFillBackground(false);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(false);
        m_image = new myimage();
        m_image->setObjectName(QString::fromUtf8("m_image"));
        m_image->setGeometry(QRect(0, 0, 533, 473));
        scrollArea->setWidget(m_image);

        verticalLayout->addWidget(scrollArea);

        label = new QLabel(MyPreview);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton = new QToolButton(MyPreview);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/Undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(MyPreview);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/Redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(toolButton_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        line_2 = new QFrame(MyPreview);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        toolButton_3 = new QToolButton(MyPreview);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(32, 32));
        toolButton_3->setCheckable(true);
        toolButton_3->setChecked(false);

        horizontalLayout_3->addWidget(toolButton_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(MyPreview);

        QMetaObject::connectSlotsByName(MyPreview);
    } // setupUi

    void retranslateUi(QWidget *MyPreview)
    {
        MyPreview->setWindowTitle(QApplication::translate("MyPreview", "Image Preview", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        toolButton->setText(QApplication::translate("MyPreview", "...", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("MyPreview", "...", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("MyPreview", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyPreview: public Ui_MyPreview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPREVIEW_H
