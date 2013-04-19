#include "setup.h"
#include "ui_setup.h"
//#include <QVariant>

Setup::Setup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setup),f_settings("NVL","Client Detline")
{
    ui->setupUi(this);

    f_settings.beginGroup("/Settings");
    reg=f_settings.value("/reg",27).toInt();
    freq=f_settings.value("/freq",20).toInt();
    s_shift=f_settings.value("/sshift",15).toInt();
    l_shift=f_settings.value("/lshift",10).toInt();
    d_range=f_settings.value("/drange",7).toInt();
    i_time=f_settings.value("/itime",35).toInt();
    n_scan=f_settings.value("/nscan",1000).toInt();
    //n_det=f_settings.value("/ndet",128).toInt();
    n_blocks=f_settings.value("/nblock",4).toInt();
    f_settings.endGroup();
    n_det=32*n_blocks;
 //   ui->spin1->setValue(reg);
    //ui->spin2->setValue(freq);
    //ui->spin3->setValue(s_shift);
    //ui->spin4->setValue(l_shift);
    //ui->spin5->setValue(d_range);
    //ui->spin6->setValue(i_time);



    val = new QIntValidator(1, 66, this);
    ui->e_det->setValidator(val);
    val1 = new QIntValidator(0, 50000, this);
    ui->e_scan->setValidator(val1);
    val2 = new QIntValidator(0, 255, this);
    val3 = new QIntValidator(1, 7, this);
    ui->spin1->setValidator(val2);
    ui->spin2->setValidator(val2);
    ui->spin3->setValidator(val2);
    ui->spin4->setValidator(val2);
    ui->spin5->setValidator(val3);
    ui->spin6->setValidator(val2);

    ui->e_det->setText(QString::number( n_blocks));
    ui->e_scan->setText(QString::number( n_scan));

    ui->spin1->setText(QString::number( reg));
    ui->spin2->setText(QString::number( freq));
    ui->spin3->setText(QString::number( s_shift));
    ui->spin4->setText(QString::number( l_shift));
    ui->spin5->setText(QString::number( d_range));
    ui->spin6->setText(QString::number( i_time));
}

Setup::~Setup()
{
    f_settings.beginGroup("/Settings");
    f_settings.setValue("/reg",reg);
    f_settings.setValue("/freq",freq);
    f_settings.setValue("/sshift",s_shift);
    f_settings.setValue("/lshift",l_shift);
    f_settings.setValue("/drange",d_range);
    f_settings.setValue("/itime",i_time);
    f_settings.setValue("/nblock",n_blocks);
    f_settings.setValue("/nscan",n_scan);
    f_settings.endGroup();

    delete val;
    delete val1;
    delete ui;
}

void Setup::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Setup::on_buttonBox_accepted()
{
   // reg=ui->spin1->value();
   // freq=ui->spin2->value();
    //s_shift=ui->spin3->value();
    //l_shift=ui->spin4->value();
    //d_range=ui->spin5->value();
    //i_time=ui->spin6->value();

    n_blocks=ui->e_det->text().toInt();
    n_scan=ui->e_scan->text().toInt();
    n_det=32*n_blocks;

    reg=ui->spin1->text().toInt();
    freq=ui->spin2->text().toInt();
    s_shift=ui->spin3->text().toInt();
    l_shift=ui->spin4->text().toInt();
    d_range=ui->spin5->text().toInt();
    i_time=ui->spin6->text().toInt();
}

void Setup::on_buttonBox_rejected()
{
   // ui->spin1->setValue(reg);
   // ui->spin2->setValue(freq);
   // ui->spin3->setValue(s_shift);
    //ui->spin4->setValue(l_shift);
   // ui->spin5->setValue(d_range);
    //ui->spin6->setValue(i_time);

    ui->e_det->setText(QString::number( n_blocks));
    ui->e_scan->setText(QString::number( n_scan));
    ui->spin1->setText(QString::number( reg));
    ui->spin2->setText(QString::number( freq));
    ui->spin3->setText(QString::number( s_shift));
    ui->spin4->setText(QString::number( l_shift));
    ui->spin5->setText(QString::number( d_range));
    ui->spin6->setText(QString::number( i_time));
}

