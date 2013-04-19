#include "mypreview.h"
#include "ui_mypreview.h"
#include "mplot.h"

extern double *Image;
QImage *img;
mplot *m_p;

MyPreview::MyPreview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyPreview)
{
    ui->setupUi(this);
  //  ui->scrollArea->setWidget(ui->m_image);
    //ui->scrollArea->setupViewport(ui->m_image);
   // ui->m_image->update();
//setCentralWidget(ui->scrollArea);
   // SetScroll();
    QObject::connect(ui->m_image,SIGNAL(sendString(QString)),ui->label,SLOT(setText(QString)));
    QObject::connect(ui->m_image,SIGNAL(sendCoordinates(int,int)),this,SLOT(ShowCrissCross(int,int)));
    img=NULL;
    cris_cross=false;
    m_p = new mplot(0);
}

MyPreview::~MyPreview()
{
    delete img;
    delete ui;
    delete m_p;
}

void MyPreview::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
QImage* MyPreview::GetImage()
{
    return ui->m_image->m_img;
}
void MyPreview::SetImage(int x,int y)
{
    nx=x; ny=y;
    MakeImage();
    ui->m_image->m_img=img;
    ui->label->setText("");
}

void MyPreview::SetScroll()
{
    //ui->scrollArea->setWidget(ui->m_image);
}

void MyPreview::on_toolButton_clicked()
{

    //int nx=ui->m_image->m_img->width();
    //int ny=ui->m_image->m_img->height();
    int *t_im= new int[nx*ny];
    for(int i=0; i<nx; i++)
        for(int j=0; j<ny; j++)
        {
        t_im[ny*(nx-i-1)+j]=Image[nx*j+i];
        }
    for(int i=0; i<nx*ny; i++) Image[i]=t_im[i];
    delete[] t_im;
   // int nn=nx;
    //nx=ny; ny=nn;
    SetImage(ny,nx);
    //this->repaint();
   // ui->m_image->
    ui->m_image->repaint();



}
void MyPreview::MakeImage()
{
    delete img;
    uchar *pp;
    img= new QImage(nx,ny,QImage::Format_RGB32);
    int mn,mx;
    double xx;
    uchar px;

    mn=Image[0];
    mx=mn;
    for(int i=0; i<nx*ny; i++)
    {
        if(Image[i]>mx) mx=Image[i];
        if(Image[i]<mn) mn=Image[i];
    }
    double dd=mx-mn;
    if(dd<=0) dd=1.0;



    for(int j=0; j<ny; j++)
    {
        pp=img->scanLine(j);
        for(int i=0; i<nx; i++)
        {

           xx=(Image[nx*j+i]-mn)*1.0;
           xx/=dd;
           px = xx*255;
           pp[4*i]=px; pp[4*i+1]=px; pp[4*i+2]=px; pp[4*i+3]=0;
           //pp[4*i]=0; pp[4*i+1]=0; pp[4*i+2]=255; pp[4*i+3]=0;
        }
    }

    //m_prv->SetImage(img);
    //m_prv->show();


}

void MyPreview::on_toolButton_2_clicked()
{
    //int nx=ui->m_image->m_img->width();
    //int ny=ui->m_image->m_img->height();
    int *t_im= new int[nx*ny];
    for(int i=0; i<nx; i++)
        for(int j=0; j<ny; j++)
        {
        t_im[ny*i+ny-j-1]=Image[nx*j+i];
        }
    for(int i=0; i<nx*ny; i++) Image[i]=t_im[i];
    delete[] t_im;
   // int nn=nx;
    //nx=ny; ny=nn;
    SetImage(ny,nx);
    //this->repaint();
   // ui->m_image->
    ui->m_image->repaint();

}

void MyPreview::on_toolButton_3_clicked()
{
 if(cris_cross)
    {
        ui->toolButton_3->setChecked(false);
        cris_cross=false;
        ui->m_image->setCursor(Qt::ArrowCursor);
        ui->m_image->criss_cross=false;
        ui->m_image->repaint();
    }
 else
 {
     ui->toolButton_3->setChecked(true);
     cris_cross=true;
     ui->m_image->setCursor(Qt::CrossCursor);
     ui->m_image->criss_cross=true;
 }
}

void MyPreview::on_toolButton_3_pressed()
{
    //ui->toolButton_3->setChecked(true);
}

void MyPreview::ShowCrissCross(int x, int y)
{

           ui->toolButton_3->setChecked(false);
           cris_cross=false;
           ui->m_image->setCursor(Qt::ArrowCursor);
           ui->m_image->criss_cross=false;
           ui->m_image->repaint();

          // QMessageBox::information(0,"xx",QString::number(x));
           //QMessageBox::information(0,"yy",QString::number(y));

           m_p->showNormal();

                //   >show();
        //ui->toolButton_3->clicked(true);
}
