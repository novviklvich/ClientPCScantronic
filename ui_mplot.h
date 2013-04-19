/********************************************************************************
** Form generated from reading UI file 'mplot.ui'
**
** Created: Wed Apr 17 14:43:08 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MPLOT_H
#define UI_MPLOT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_mplot
{
public:
    QVBoxLayout *verticalLayout;
    QwtPlot *qwtPlot_2;
    QwtPlot *qwtPlot;

    void setupUi(QWidget *mplot)
    {
        if (mplot->objectName().isEmpty())
            mplot->setObjectName(QString::fromUtf8("mplot"));
        mplot->setWindowModality(Qt::WindowModal);
        mplot->resize(724, 581);
        verticalLayout = new QVBoxLayout(mplot);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        qwtPlot_2 = new QwtPlot(mplot);
        qwtPlot_2->setObjectName(QString::fromUtf8("qwtPlot_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qwtPlot_2->sizePolicy().hasHeightForWidth());
        qwtPlot_2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(qwtPlot_2);

        qwtPlot = new QwtPlot(mplot);
        qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));
        sizePolicy.setHeightForWidth(qwtPlot->sizePolicy().hasHeightForWidth());
        qwtPlot->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(qwtPlot);


        retranslateUi(mplot);

        QMetaObject::connectSlotsByName(mplot);
    } // setupUi

    void retranslateUi(QWidget *mplot)
    {
        mplot->setWindowTitle(QApplication::translate("mplot", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mplot: public Ui_mplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MPLOT_H
