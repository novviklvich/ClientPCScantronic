#ifndef MPLOT_H
#define MPLOT_H

#include <QWidget>
class QwtPlot;
class QwtPlotCurve;
class QwtPlotMarker;
namespace Ui {
    class mplot;
}

class mplot : public QWidget {
    Q_OBJECT
public:
    mplot(QWidget *parent = 0);
    ~mplot();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::mplot *ui;
    QwtPlotCurve *Curve1, *Curve2;
    QwtPlotMarker **Marker1;
};

#endif // MPLOT_H
