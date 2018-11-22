#include "mainwindow.h"
#include "trogchart.h"
#include <QApplication>
#include <QSharedPointer>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  QSharedPointer<TrogChart> p =
      QSharedPointer<TrogChart>(new TrogChart, &QObject::deleteLater);
  // TrogChart t;
  // QObject::connect(&w, SIGNAL(sendResponseToAnotherClass(QByteArray)),
  // p.get(),
  //               SLOT(receiveResponseFromAnotherClass(QByteArray)));
  QObject::connect(&w.mngr, SIGNAL(finished(QNetworkReply *)), p.get(),
                   SLOT(receiveResponseFromAnotherClass(QNetworkReply *)));
  // QObject::connect(&w.mngr, SIGNAL(finished(QNetworkReply *)), &t,
  //               SLOT(receiveResponseFromAnotherClass(QNetworkReply *)));
  // connect(&mngr, SIGNAL(finished(QNetworkReply *)), this,
  //   SLOT(getResponse(QNetworkReply *)));
  // for (auto i = 0; i < 20000000; i++)
  QTimer t1;
  t1.setInterval(3);
  QTimer t2;
  t2.setInterval(9000);
  QObject::connect(&t1, &QTimer::timeout, &w,
                   &MainWindow::on_pushButton_clicked);
  QObject::connect(&t2, &QTimer::timeout, &t1, &QTimer::stop);
  t2.start();
  t1.start();
  w.on_pushButton_clicked();
  // w.deleteLater();
  return QApplication::exec();
}
