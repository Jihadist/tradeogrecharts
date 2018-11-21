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

  // QObject::connect(&w, SIGNAL(sendResponseToAnotherClass(QByteArray)),
  // p.get(),
  //               SLOT(receiveResponseFromAnotherClass(QByteArray)));
  QObject::connect(&w.mngr, SIGNAL(finished(QNetworkReply *)), p.get(),
                   SLOT(receiveResponseFromAnotherClass(QNetworkReply *)));
  // connect(&mngr, SIGNAL(finished(QNetworkReply *)), this,
  //      SLOT(getResponse(QNetworkReply *)));
  // for (auto i = 0; i < 20000000; i++)
  w.on_pushButton_clicked();
  // w.deleteLater();
  return QApplication::exec();
}
