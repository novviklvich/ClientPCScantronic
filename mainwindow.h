#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTcpSocket>
 #include <QLabel>
 #include <QImage>
#include "setup.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool Connect();
    bool Disconnect();
    void SendSetUp();
   // void MakeImage();
   // int nx;
    //int ny;
    cv::Mat main_image;



protected:
    void changeEvent(QEvent *e);
    virtual void closeEvent ( QCloseEvent * event );

private:
    QTcpSocket* m_pTcpSocket;
    quint16     m_nNextBlockSize;
    Ui::MainWindow *ui;
    int nPort;
    QString strHost;
    QLabel *myinfo;
    QPalette pal;
    QString dir_app;
    QColor mycol;
    QBrush mybrush;
    QPixmap *c_red;
    QPixmap *c_green;
    bool read_ready;
    bool s_sinhro,s_detline,s_connect;


private slots:
    void on_m_start_2_clicked();
    void on_m_stop_3_clicked();
    void on_m_start_3_clicked();
    void on_m_stop_2_clicked();
    void on_actionSave_as_2_triggered();
    void on_actionSetup_parameters_triggered();
    void on_m_stop_clicked();
    void on_m_start_clicked();
    void on_actionExit_2_triggered();
};

#endif // MAINWINDOW_H
