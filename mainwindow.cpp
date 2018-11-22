#include "mainwindow.h"
#include "trogchart.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);
  // connect(&mngr, SIGNAL(finished(QNetworkReply *)), this,
  //      SLOT(getResponse(QNetworkReply *)));
}

<<<<<<< HEAD
void MainWindow::on_plainTextEdit_textChanged()
{

}


void MainWindow::getResponse(QNetworkReply *reply)
{
    //QByteArray answer=reply->readAll(); // Получение ответа
    //ui->plainTextEdit->setPlainText(reply->readAll()); // Вывод ответа на экран
    qDebug()<<"Response received";
    emit sendResponseToAnotherClass(reply->readAll()); // Посылаем сигнал, что ответ получен
=======
MainWindow::~MainWindow() { delete ui; }
>>>>>>> 9ab7596fa308c69f4010ac3855fc925636ee2c82

void MainWindow::on_pushButton_clicked() {
  auto test = mngr.get(request); // Отправка get запроса
  // test=mngr.get(request);                             // test->deleteLater();
  // if (test->isFinished()) {
  // qDebug() << "Reply is finished";
  // delete test;
  // delete_pointer(test);
  //}
}

void MainWindow::on_plainTextEdit_textChanged() {}

// void MainWindow::getResponse(QNetworkReply *reply) {
// QByteArray answer=reply->readAll(); // Получение ответа
// ui->plainTextEdit->setPlainText(answer); // Вывод ответа на экран
// qDebug() << "Response received";
// emit sendResponseToAnotherClass(
// reply->readAll()); // Посылаем сигнал, что ответ получен
//}
