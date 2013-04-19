#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget *d = QApplication::desktop();
   // int ps=d->primaryScreen();
    QRect pd=d->availableGeometry();

       int width = pd.width();   // returns screen width
       int height = pd.height();  // returns screen height
       int mw = w.width();
       int mh = w.height();
       int cw = (width/2) - (mw/2);
       int ch = (height/2) - (mh/2);
       w.move(cw,ch);
//Setup s_ttttttt;


   // w.move(QApplication::desktop()->screen(0)->rect().center() - w.centralWidget()->rect().center());
    w.show();
    return a.exec();
}
