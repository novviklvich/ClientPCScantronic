/********************************************************************************
** Form generated from reading UI file 'setup.ui'
**
** Created: Wed Apr 17 14:43:08 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_H
#define UI_SETUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setup
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *e_det;
    QLabel *label_2;
    QLineEdit *e_scan;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *spin1;
    QLineEdit *spin2;
    QLineEdit *spin3;
    QLineEdit *spin4;
    QLineEdit *spin5;
    QLineEdit *spin6;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QDialog *Setup)
    {
        if (Setup->objectName().isEmpty())
            Setup->setObjectName(QString::fromUtf8("Setup"));
        Setup->setWindowModality(Qt::ApplicationModal);
        Setup->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Setup->sizePolicy().hasHeightForWidth());
        Setup->setSizePolicy(sizePolicy);
        Setup->setMinimumSize(QSize(400, 300));
        Setup->setMaximumSize(QSize(400, 300));
        buttonBox = new QDialogButtonBox(Setup);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(190, 220, 176, 27));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Setup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 108, 17));
        e_det = new QLineEdit(Setup);
        e_det->setObjectName(QString::fromUtf8("e_det"));
        e_det->setGeometry(QRect(230, 80, 113, 27));
        label_2 = new QLabel(Setup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 60, 141, 17));
        e_scan = new QLineEdit(Setup);
        e_scan->setObjectName(QString::fromUtf8("e_scan"));
        e_scan->setGeometry(QRect(230, 160, 113, 27));
        label_3 = new QLabel(Setup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 140, 141, 17));
        layoutWidget = new QWidget(Setup);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(79, 51, 61, 194));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        spin1 = new QLineEdit(layoutWidget);
        spin1->setObjectName(QString::fromUtf8("spin1"));

        verticalLayout->addWidget(spin1);

        spin2 = new QLineEdit(layoutWidget);
        spin2->setObjectName(QString::fromUtf8("spin2"));

        verticalLayout->addWidget(spin2);

        spin3 = new QLineEdit(layoutWidget);
        spin3->setObjectName(QString::fromUtf8("spin3"));

        verticalLayout->addWidget(spin3);

        spin4 = new QLineEdit(layoutWidget);
        spin4->setObjectName(QString::fromUtf8("spin4"));

        verticalLayout->addWidget(spin4);

        spin5 = new QLineEdit(layoutWidget);
        spin5->setObjectName(QString::fromUtf8("spin5"));

        verticalLayout->addWidget(spin5);

        spin6 = new QLineEdit(layoutWidget);
        spin6->setObjectName(QString::fromUtf8("spin6"));

        verticalLayout->addWidget(spin6);

        layoutWidget1 = new QWidget(Setup);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 50, 52, 181));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        layoutWidget->raise();
        buttonBox->raise();
        label->raise();
        e_det->raise();
        label_2->raise();
        e_scan->raise();
        label_3->raise();
        layoutWidget->raise();

        retranslateUi(Setup);
        QObject::connect(buttonBox, SIGNAL(accepted()), Setup, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Setup, SLOT(reject()));

        QMetaObject::connectSlotsByName(Setup);
    } // setupUi

    void retranslateUi(QDialog *Setup)
    {
        Setup->setWindowTitle(QApplication::translate("Setup", "Setup parameters", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Setup", "Command bytes", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Setup", "Number of blocks", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Setup", "Number of scans", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Setup", "regim", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Setup", "freq", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Setup", "i shift", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Setup", "l shift", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Setup", "d range", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Setup", "i time", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Setup: public Ui_Setup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_H
