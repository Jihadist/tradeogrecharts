#include "mainwindow.h"
#include "trogchart.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    TrogChart b(nullptr,nullptr,nullptr);
    QObject::connect(&w,SIGNAL(sendResponseToAnotherClass(QByteArray)),&b,SLOT(receiveResponseFromAnotherClass(QByteArray)));
    //b.TrogChart::chart_view->show();

    return a.exec();
}
