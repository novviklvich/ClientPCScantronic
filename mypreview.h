#ifndef MYPREVIEW_H
#define MYPREVIEW_H

#include <QWidget>


namespace Ui {
    class MyPreview;
}

class MyPreview : public QWidget {
    Q_OBJECT
public:
    MyPreview(QWidget *parent = 0);
    ~MyPreview();
    QImage* GetImage();
    void SetImage(int x,int y);
    void SetScroll();
    void MakeImage();
    int nx;
    int ny;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MyPreview *ui;
     bool cris_cross;

private slots:
    void on_toolButton_3_pressed();
    void on_toolButton_3_clicked();
    void on_toolButton_2_clicked();
    void on_toolButton_clicked();
public slots:
void ShowCrissCross(int x, int y);

};

#endif // MYPREVIEW_H
