#include "mplot.h"
#include "ui_mplot.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_marker.h>
#include <qwt_text.h>
#include <qwt_symbol.h>


mplot::mplot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mplot)
{
    ui->setupUi(this);
    Curve1=new QwtPlotCurve;
    //Marker1 = new QwtPlotMarker;
    //Marker1->attach(ui->qwtPlot);
    Curve1->setRenderHint(QwtPlotItem::RenderAntialiased);
    Curve1->setPen(QPen(Qt::red));
    Curve1->setSymbol(new QwtSymbol(QwtSymbol::Cross, Qt::darkBlue,
            QPen(Qt::black), QSize(8, 8) ) );

    Curve1->attach(ui->qwtPlot);
    //Curve1->setStyle();

    QString s = "123";
    QwtText vv(s,QwtText::AutoText);
    const int N = 20;
    double x[N+1];
    double sinFunData[N+1];

    Marker1 = new QwtPlotMarker* [N*sizeof(QwtPlotMarker *)];

    for (int i = 0; i <= N; ++i)
    {
        const double pi = 4.0 * atan(1.0);
        double L = 2;
        double h = L / N;
        Marker1[i] = new QwtPlotMarker;
        Marker1[i]->attach(ui->qwtPlot);
        x[i] = -L/2 + i * h;
        sinFunData[i] =  1000.0*sin(x[i] * pi);
        Marker1[i]->setXValue(x[i]);
        Marker1[i]->setYValue(sinFunData[i]);
        Marker1[i]->setLabelAlignment(Qt::AlignTop);
        //Marker1[i]->setItemAttribute();
        Marker1[i]->setLabel(QString::number( sinFunData[i],'f',2));
    }

    //ui->qwtPlot->setS
    Curve1->setSamples(x,sinFunData,N+1);

  //  for (int i = 0; i <= N; ++i)
   // {
      //  const double pi = 4.0 * atan(1.0);
      //  double L = 2;
       // double h = L / N;

       // x[i] = -L/2 + i * h;
       // sinFunData[i] =  sin(x[i] * pi);
     //   Marker1->setXValue(x[i]);
      //  Marker1->setYValue(sinFunData[i]);
       // Marker1->setLabel(vv);
    //}
    //Marker1->setXValue(x[10]);
    //Marker1->setYValue(sinFunData[10]);
 //Marker1->setLabel(vv);
 //Marker1->setXValue(x[20]);
 //Marker1->setYValue(sinFunData[20]);
//Marker1->setLabel(vv);

    //  >setLabel("123");

}

mplot::~mplot()
{
    delete Curve1;
    delete[] Marker1;
    //delete Curve2;
    delete ui;
}

void mplot::changeEvent(QEvent *e)
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
