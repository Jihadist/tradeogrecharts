#include "mainwindow.h"
#include "tradeogrechart.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);
  // connect(&mngr, SIGNAL(finished(QNetworkReply *)), this,
  //      SLOT(getResponse(QNetworkReply *)));
}


//void MainWindow::getResponse(QNetworkReply *reply)
//{
//    //QByteArray answer=reply->readAll(); // Получение ответа
//    //ui->plainTextEdit->setPlainText(reply->readAll()); // Вывод ответа на экран
//    qDebug()<<"Response received";
//    emit sendResponseToAnotherClass(reply->readAll()); // Посылаем сигнал, что ответ получен

MainWindow::~MainWindow() { delete ui; }


void MainWindow::on_pushButton_clicked() {
  auto test = mngr.get(request); // Отправка get запроса
  //while (!test->isFinished()) {
    //  qApp->processEvents();
  //}
  // test=mngr.get(request);                             // test->deleteLater();
  // if (test->isFinished()) {
  // qDebug() << "Reply is finished";
  // delete test;
  // delete_pointer(test);



}

void MainWindow::on_plainTextEdit_textChanged() {}

// void MainWindow::getResponse(QNetworkReply *reply) {
// QByteArray answer=reply->readAll(); // Получение ответа
// ui->plainTextEdit->setPlainText(answer); // Вывод ответа на экран
// qDebug() << "Response received";
// emit sendResponseToAnotherClass(
// reply->readAll()); // Посылаем сигнал, что ответ получен
//}
