#include "myimage.h"
#include <QPoint>
#include <QPen>

extern double *Image;

myimage::myimage(QWidget *parent) :
    QWidget(parent)
{
    m_img=NULL;
    this->setMouseTracking(true);
    criss_cross=false;
    lb=false;
   //m_img = new QImage(10,10,QImage::Format_RGB32);


}
/*virtual*/ void myimage::paintEvent(QPaintEvent*)
{

    if(m_img==NULL) return;
    QPainter painter(this);

    QPoint ps(0,0);
  // setFixedHeight(m_img->height());
   //setFixedWidth(m_img->width());
    //this->resize(m_img->width(),m_img->height());
    resize(m_img->width(),m_img->height());
    painter.drawImage(ps, *m_img);
    if(criss_cross & lb)
    {
    //QPen qp
    painter.setPen(QPen(Qt::blue,1));
    painter.drawLine(QPoint(xx,0),QPoint(xx,m_img->height()));
    painter.drawLine(QPoint(0,yy),QPoint(m_img->width(),yy));
    }
}

 void myimage::mousePressEvent(QMouseEvent* pe)
 {
 }

 /*virtual*/ void myimage::mouseReleaseEvent(QMouseEvent* pe)
            {
                //if((pe->buttons() & Qt::LeftButton) & criss_cross)
                    if((pe->button() & Qt::LeftButton)&criss_cross)
                {
                    criss_cross=false;
                    lb=false;
                    repaint();
                    sendCoordinates(xx,yy);
                }
            }

void myimage::mouseMoveEvent(QMouseEvent* pe)
{
   if(m_img==NULL) return;

  // if(pe->buttons() & Qt::LeftButton)
    //   {
       QString s;// = QString::number
       QPoint p=QWidget::mapFromGlobal((pe->globalPos()));//  >globalX())+"  ,  "+QString::number(pe->globalY());
       xx=p.x();
       yy=p.y();
       int nx=m_img->width();
       if(xx>=0&&xx<=m_img->width()&&yy>=0&&yy<=m_img->height())
       {
       s=QString::number(p.x())+" , "+QString::number(p.y()) + " , I=" +QString::number(Image[nx*yy+xx]);
                  emit sendString(s);
              }// label->

       if(pe->buttons() & Qt::LeftButton) lb=true;
        if(criss_cross & (pe->buttons() & Qt::LeftButton))
            repaint();

      //  if(pe->button() )

      // }

 }
