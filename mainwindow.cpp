#include "mainwindow.h"
//#include "tradeogrechart.h"
#include "ui_mainwindow.h"
#include "network.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);
//   connect(&mngr, SIGNAL(finished(QNetworkReply *)), this,
 //       SLOT(getResponse(QNetworkReply *)));
  //connect(&mngr,SIGNAL(finished(QNetworkReply *)), &Network::manager,)
}


//void MainWindow::getResponse(QNetworkReply *reply)
//{
//    //QByteArray answer=reply->readAll(); // Получение ответа
//    //ui->plainTextEdit->setPlainText(reply->readAll()); // Вывод ответа на экран
//    qDebug()<<"Response received";
//    emit sendResponseToAnotherClass(reply->readAll()); // Посылаем сигнал, что ответ получен

MainWindow::~MainWindow() { delete ui; }


void MainWindow::on_pushButton_clicked() {
  request=QNetworkRequest(QUrl("https://tradeogre.com/api/v1/orders/LTC-TRTL"));
  auto test1 = mngr.get(request); // Отправка get запроса
  request=QNetworkRequest(QUrl("https://api.bilaxy.com/v1/depth?symbol=117"));
  auto test2=mngr.get(request);




}

void MainWindow::on_plainTextEdit_textChanged() {}
