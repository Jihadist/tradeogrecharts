#include "mainwindow.h"
#include "tradeogrechart.h"
#include "network.h"
#include <QApplication>
#include <QSharedPointer>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  QSharedPointer<TradeOgreChart> p =
      QSharedPointer<TradeOgreChart>(new TradeOgreChart, &QObject::deleteLater);

 // QObject::connect(&w.mngr, &QNetworkAccessManager::finished, p.get(),
   //                &TradeOgreChart::receiveResponseFromAnotherClass);

  /*QTimer t1;
  t1.setInterval(3);
  QTimer t2;
  t2.setInterval(9000);
  QObject::connect(&t1, &QTimer::timeout, &w,
                   &MainWindow::on_pushButton_clicked);
  QObject::connect(&t2, &QTimer::timeout, &t1, &QTimer::stop);
  t2.start();
  t1.start();*/
  w.on_pushButton_clicked();
  Network bilaxy;
  bilaxy.setUrl("https://api.bilaxy.com/v1/depth?symbol=117");
  Network tradeogre;
  QObject::connect(&tradeogre,&Network::responseFromTradeogre,
                   p.get(),&TradeOgreChart::receiveResponseFromAnotherClass);
  tradeogre.setUrl("https://tradeogre.com/api/v1/orders/LTC-TRTL");


  return QApplication::exec();

}
