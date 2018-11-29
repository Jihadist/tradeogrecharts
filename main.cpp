#include "mainwindow.h"
#include "tradeogrechart.h"
#include "network.h"
#include "bilaxychart.h"
#include <QApplication>
#include <QSharedPointer>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  QSharedPointer<TradeOgreChart> p =
      QSharedPointer<TradeOgreChart>(new TradeOgreChart, &QObject::deleteLater);
  QSharedPointer<bilaxychart> b =
      QSharedPointer<bilaxychart>(new bilaxychart, &QObject::deleteLater);
  Network network;

  /*QTimer t1;
  t1.setInterval(3);
  QTimer t2;
  t2.setInterval(9000);
  QObject::connect(&t1, &QTimer::timeout, &w,
                   &MainWindow::on_pushButton_clicked);
  QObject::connect(&t2, &QTimer::timeout, &t1, &QTimer::stop);
  t2.start();
  t1.start();*/

  QObject::connect(&w.mngr,&QNetworkAccessManager::finished,&network,&Network::getResponse);
  QObject::connect(&network,&Network::responseFromBilaxy,
                   b.get(),&bilaxychart::receiveResponseFromAnotherClass);
  QObject::connect(&network,&Network::responseFromTradeogre,
                   p.get(),&TradeOgreChart::receiveResponseFromAnotherClass);
  w.on_pushButton_clicked();

  return QApplication::exec();

}
