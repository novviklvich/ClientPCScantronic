#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
 #include <QMessageBox>
 //#include <QLabel>
//#include "imagepreview.h"
#include "myimage.h"
#include "mypreview.h"
//#include <QTest>
#include <sys/time.h>


#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))
#define SETBIT(ADDRESS,BIT) ( ADDRESS |=(1<<BIT))

Setup *s_t;
// ImagePreview *Imp;
//Preview *m_prv;
MyPreview *m_prv;
//QImage *img;
double *Image;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pTcpSocket=NULL;
    myinfo = new QLabel("No Connection!");
    ui->statusBar->addWidget(myinfo);
    //pal=ui->lcdNumber->palette();
    //pal.setColor(QPalette::Dark,Qt::red);
    //ui->lcdNumber->setPalette(pal);
    s_t = new Setup(this);
    dir_app=QCoreApplication::applicationDirPath ();
   // QMessageBox::information(0,"Directory Path",dir_app);
    //Imp=new ImagePreview(0);
    m_prv=new MyPreview(0);
    //img=NULL;
   // QString ss= dir_app+"/resources/";
    c_red=new QPixmap(":/resources/circle_red.png");
   // c_green=new QPixmap(dir_app+"/resources/circle_green.png");
    c_green=new QPixmap(":/resources/circle_green.png");
    ui->led1->setPixmap(*c_red);
    ui->led2->setPixmap(*c_red);
    ui->led3->setPixmap(*c_red);
    Image=NULL;
    read_ready=false;
    s_sinhro=false;
    s_detline=false;
    s_connect=false;
}

MainWindow::~MainWindow()
{
    //delete Imp;
    delete s_t;
    delete m_pTcpSocket;
    delete myinfo;
    delete m_prv;
   // delete img;
   // delete[] Image;

    delete ui;
}



void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


/*virtual*/ void MainWindow::closeEvent ( QCloseEvent * event )
            {
               // QByteArray command;
               // struct MyThread : public QThread { using QThread::msleep;};
                //command.resize(6);
                //command[0] = 1;
                //if(m_pTcpSocket!=NULL) {m_pTcpSocket->write(command);
                  //  m_pTcpSocket->waitForBytesWritten(1000);
                Disconnect();
                main_image.release();
            //}
                //sleep(10);
                //MyThread::msleep(3000);
                //if(m_pTcpSocket!=NULL)  Disconnect();

            }


void MainWindow::on_actionExit_2_triggered()
{
   // QByteArray command;
   // struct MyThread : public QThread { using QThread::msleep;};
    //command.resize(6);
    //command[0] = 1;
    //if(m_pTcpSocket!=NULL) m_pTcpSocket->write(command);
    //m_pTcpSocket->waitForBytesWritten(1000);
    //sleep(10);
    //MyThread::msleep(3000);
    //if(m_pTcpSocket!=NULL)  Disconnect();
    //m_pTcpSocket=NULL;
    close(); //ui->led1->setPixmap(*c_red);
}

bool MainWindow::Connect()
{
    m_pTcpSocket = new QTcpSocket(this);
    strHost="192.168.0.55";
   // strHost="127.0.0.1";
    nPort=5032;
    m_pTcpSocket->connectToHost(strHost, nPort);
    if(m_pTcpSocket->waitForConnected(1000))
    {
        return true;
    }
    else
    {
        m_pTcpSocket->disconnectFromHost();
        delete m_pTcpSocket;
        m_pTcpSocket=NULL;
        return false;
    }
}

bool MainWindow::Disconnect()
{
    delete m_pTcpSocket;
    m_pTcpSocket=NULL;
    return true;
}

void MainWindow::on_m_start_clicked()
{
    if(m_pTcpSocket!=NULL) return;
    ui->m_start->setEnabled(false);
    if(Connect())
    {
        myinfo->setText("Connection is Established!");
        ui->statusBar->addWidget(myinfo);
       // ui->lcdNumber->palette().setColor(QPalette::Dark,Qt::green);
       // pal=ui->lcdNumber->palette();
        //pal.setColor(QPalette::Dark,Qt::green);
        //ui->lcdNumber->setPalette(pal);
        //QBrush pu= ui->mdiArea->background();
        //mycol.setRgb(255,255,255,255);//   .setRed(255);
        //pu.setColor(mycol);// mybrush.setStyle(QMessageBox::information(0,"Directory Path",dir_appQt::SolidPattern);
        //ui->mdiArea->setBackground(pu);
        //ui->mdiArea->repaint();;
        ui->led1->setPixmap(*c_green);
        ui->m_start_2->setEnabled(true);
        ui->m_start_3->setEnabled(true);
        ui->m_stop_2->setEnabled(true);
        ui->m_stop_3->setEnabled(true);
        s_connect=true;
        //SendSetUp();
        //QMessageBox::information(0,"info","Command SetUp was sent! ");

       // ui->m_start->setEnabled(false);
    }
    else
    {
        myinfo->setText("No Connection!");
        ui->statusBar->addWidget(myinfo);
        //pal=ui->lcdNumber->palette();
        //pal.setColor(QPalette::Dark,Qt::red);
        //ui->lcdNumber->setPalette(pal);
        ui->m_start->setEnabled(true);
        //ui->lcdNumber->palette().setColor(QPalette::Dark,Qt::red);
        ui->led1->setPixmap(*c_red);
        ui->m_start_2->setEnabled(false);
        ui->m_start_3->setEnabled(false);
        ui->m_stop_2->setEnabled(false);
        ui->m_stop_3->setEnabled(false);
        s_connect=false;
    }
}

void MainWindow::on_m_stop_clicked()
{
   if(m_pTcpSocket==NULL) return;
   Disconnect();
   myinfo->setText("No Connection!");
   ui->statusBar->addWidget(myinfo);
   //pal=ui->lcdNumber->palette();
   //pal.setColor(QPalette::Dark,Qt::red);
   //ui->lcdNumber->setPalette(pal);
   ui->m_start->setEnabled(true);
   ui->led1->setPixmap(*c_red);
   ui->m_start_2->setEnabled(false);
   ui->m_start_3->setEnabled(false);
   ui->m_stop_2->setEnabled(false);
   ui->m_stop_3->setEnabled(false);
   s_connect=false;

}
//#include <QWidget>
void MainWindow::on_actionSetup_parameters_triggered()
{
   if( s_t->exec()==QDialog::Accepted)
    {
       if(s_connect&&!s_detline&&!s_sinhro) { SendSetUp();QMessageBox::information(0,"info","Command SetUp was sent! ");}
       else QMessageBox::information(0,"info","Command SetUp was not sent!");
   }
       ;
  //s_t->show();//Qmessagebox
}

void MainWindow::on_actionSave_as_2_triggered()
{
    QString str = QFileDialog::getSaveFileName(0,"Save Dialog","","*.*");
}





void MainWindow::on_m_start_3_clicked()
{
    int nx,ny;
    int s_buf;

    struct timeval  start, stop;
    struct timezone t_zone;
    long delay;
    int *t_Image=new int[s_t->n_det*s_t->n_scan];
    int count_bytes=0;
    memset(t_Image,0,s_t->n_det*s_t->n_scan*sizeof(int));
    s_buf = s_t->n_det*s_t->n_scan*sizeof(int);
    char *pb=(char*)t_Image;
    QByteArray command;
    uchar scom=0;
    int n_scan=0;
    int sent_bytes;//delete m_pTcpSocket;
    int p=s_t->n_det;
    uchar *pp=(uchar*)&p;
   // m_pTcpSocket=NULL;
    command.resize(12);
    SETBIT(scom,7);
  //  QMessageBox::information(0,"Command=",QString::number( scom));
    command[0] = scom;
    command[1] = s_t->reg;
    command[2] = s_t->freq;
    command[3]=s_t->s_shift;
    command[4]=s_t->l_shift;
    command[5]=s_t->d_range;
    command[6] = s_t->i_time;

    command[8]=pp[0];
    command[9]=pp[1];
    command[10]=pp[2];
    command[11]=pp[3];
    Disconnect();
    Connect();

   // sent_bytes=m_pTcpSocket->bytesAvailable();
    //QMessageBox::information(0,"buffer=",QString::number( sent_bytes));

    ui->led3->setPixmap(*c_green);
    ui->m_start_3->setEnabled(false);
    sent_bytes=m_pTcpSocket->write(command);
    //QMessageBox::information(0,"Sent ",QString::number( sent_bytes));
    ui->progressBar->setMaximum(s_t->n_scan);
    read_ready=true;
    QByteArray q_t = m_pTcpSocket->readAll();
    q_t.clear();
    s_detline=true;
    gettimeofday (&start, &t_zone);
    while(read_ready)
    {
        //sleep(0);
        sent_bytes=m_pTcpSocket->bytesAvailable();
        if (sent_bytes)
        {
            //QMessageBox::information(0,"Bytes for reading ",QString::number( sent_bytes));
            if((count_bytes+sent_bytes)>s_buf)
            {
               sent_bytes=s_buf-count_bytes;
               read_ready=false;
            }
            m_pTcpSocket->read(pb,sent_bytes);
            count_bytes+=sent_bytes;
            pb+=sent_bytes;
            n_scan=count_bytes/(s_t->n_det*sizeof(int));
            //if(count_bytes>=s_t->n_det*s_t->n_scan*sizeof(int)) read_ready=false;
            if(n_scan%100==0) ui->progressBar->setValue(n_scan);
        }
        QCoreApplication::processEvents ();
    }
    gettimeofday (&stop, &t_zone);
    delay = (stop.tv_sec - start.tv_sec);// + 1000000L * (stop.tv_usec - start.tv_usec);
    s_detline=false;
    ui->progressBar->setValue(0);
   // QMessageBox::information(0,"delay=",QString::number( delay));
    ui->m_start_3->setEnabled(true);
    command[0] = 0;
    sent_bytes=m_pTcpSocket->write(command);
    ui->led3->setPixmap(*c_red);
    //m_pTcpSocket->abort();
   // sent_bytes=m_pTcpSocket->bytesAvailable();
   // QMessageBox::information(0,"buffer=",QString::number( sent_bytes));

   //  delete[] t_Image;
   //return;

    nx=s_t->n_det;
    ny=n_scan;

    main_image.create(ny,nx,CV_64F);
    double *t_m=(double*)main_image.data;
    Image=t_m;
   // delete[] Image;
   // Image=new int[nx*ny];
    for(int i=0; i<nx*ny; i++) t_m[i]=t_Image[i];
    //{Image[i]=t_Image[i]; t_m[i]=t_Image[i];};

    //t_m[10]=1024;

    //cv::namedWindow("Image");
    //cv::imshow("Image", main_image);

   // QMessageBox::information(0,"im=",QString::number( t_m[200]));


    QFile im_file(dir_app+"/Image.int");
    if(im_file.open(QIODevice::WriteOnly))
    {
        int nv=1;
              //FileWrite(iFileHandle, (char*)&nx,sizeof(nx));
              //FileWrite(iFileHandle, (char*)&ny,sizeof(ny));
              //FileWrite(iFileHandle, (char*)&nv,sizeof(nv));


              //for(int i=0; i<ny; i++)
              //FileWrite(iFileHandle, (char*)&Im[i*n_line],nx*sizeof(int));

              //FileClose(iFileHandle);


              im_file.write((char*)&nx,sizeof(nx));
              im_file.write((char*)&ny,sizeof(ny));
              im_file.write((char*)&nv,sizeof(nv));

              int tp=0;
              for(int i=0; i<13; i++)
              im_file.write((char*)&tp,sizeof(tp));

              for(int i=0; i<nx*ny; i++)
              im_file.write((char*)&t_Image[i],sizeof(int));

              im_file.close();
    }
    else QMessageBox::information(0,"Error opening file!","");
     delete[] t_Image;

    //MakeImage();

/*    delete img;
    uchar *pp;
    img= new QImage(nx,ny,QImage::Format_RGB32);
    for(int i=0; i<nx; i++)
    {
        pp=img->scanLine(i);
        for(int j=0; j<ny; j++)
        {
           pp[4*j]=0; pp[4*j+1]=0; pp[4*j+2]=255; pp[4*j+3]=0;
        }
    }*/

    m_prv->SetImage(nx,ny);
    m_prv->show();

}

void MainWindow::on_m_stop_3_clicked()
{
    //QByteArray command;
    //int sent_bytes;

    read_ready=false;
    //command.resize(6);
    //command[0] = 0;
    //sent_bytes=m_pTcpSocket->write(command);
    //QMessageBox::information(0,"Sent ",QString::number( sent_bytes));





}



void MainWindow::on_m_start_2_clicked()
{

    QByteArray command;
    uchar scom=1;
    int p=s_t->n_det;
    uchar *pp=(uchar*)&p;
    //int n_scan=0;
    int sent_bytes;//delete m_pTcpSocket;
   // m_pTcpSocket=NULL;
    command.resize(12);
    SETBIT(scom,7);
  //  QMessageBox::information(0,"Command=",QString::number( scom));
    command[0] = scom;
    command[1] = s_t->reg;
    command[2] = s_t->freq;
    command[3]=s_t->s_shift;
    command[4]=s_t->l_shift;
    command[5]=s_t->d_range;
    command[6]=s_t->i_time;

    command[8]=pp[0];
    command[9]=pp[1];
    command[10]=pp[2];
    command[11]=pp[3];

    ui->led2->setPixmap(*c_green);
    sent_bytes=m_pTcpSocket->write(command);

    ui->m_start_2->setEnabled(false);
    s_sinhro=true;

}

void MainWindow::on_m_stop_2_clicked()
{
    QByteArray command;
    command.resize(12);
    command[0] = 1;
    m_pTcpSocket->write(command);
    ui->led2->setPixmap(*c_red);
    ui->m_start_2->setEnabled(true);
     s_sinhro=false;

}

void MainWindow::SendSetUp()
{

    QByteArray command;
    uchar scom=2;
    int p=s_t->n_det;
    uchar *pp=(uchar*)&p;
   // int n_scan=0;
    int sent_bytes;//delete m_pTcpSocket;
   // m_pTcpSocket=NULL;
    command.resize(12);
   // p=command[8];
    //SETBIT(scom,7);
  //  QMessageBox::information(0,"Command=",QString::number( scom));
    //p=s_t->n_det;
    command[0] = scom;
    command[1] = s_t->reg;
    command[2] = s_t->freq;
    command[3]=s_t->s_shift;
    command[4]=s_t->l_shift;
    command[5]=s_t->d_range;
    command[6]=s_t->i_time;

    command[8]=pp[0];
    command[9]=pp[1];
    command[10]=pp[2];
    command[11]=pp[3];
  //  QMessageBox::information(0,"Command=",QString::number( p));

    //QMessageBox::information(0,"Command=",QString::number( command[8]));
    // ui->led2->setPixmap(*c_green);
    sent_bytes=m_pTcpSocket->write(command);

    //ui->m_start_2->setEnabled(false);

}

