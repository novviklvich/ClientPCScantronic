#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QtGui>

class myimage : public QWidget
{
Q_OBJECT
public:
    explicit myimage(QWidget *parent = 0);
    //myimage(QWidget *parent = 0);
      bool criss_cross;
      int xx,yy;
      bool lb;

     QImage *m_img;
protected:
    virtual void paintEvent(QPaintEvent* pe);
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent(QMouseEvent* pe);
     virtual void mouseReleaseEvent(QMouseEvent* pe);
signals:
    void sendString(const QString&);
    void sendCoordinates(const int&, const int&);
public slots:

};
#endif // MYIMAGE_H
