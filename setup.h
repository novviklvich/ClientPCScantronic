#ifndef SETUP_H
#define SETUP_H

#include <QDialog>
#include <QSettings>
#include <QIntValidator>

namespace Ui {
    class Setup;
}

class Setup : public QDialog {
    Q_OBJECT
public:
    Setup(QWidget *parent = 0);
    ~Setup();
    uchar reg;
    uchar freq;
    uchar s_shift;
    uchar l_shift;
    uchar d_range;
    uchar i_time;

    int n_scan,n_det,n_blocks;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Setup *ui;
    QSettings f_settings;
    QValidator *val;
    QValidator *val1;
    QValidator *val2;
     QValidator *val3;

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
};
//static Setup *s_ttttttt;

#endif // SETUP_H
