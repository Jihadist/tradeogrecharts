#include "mainwindow.h"
#include "trogchart.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);
  // connect(&mngr, SIGNAL(finished(QNetworkReply *)), this,
  //      SLOT(getResponse(QNetworkReply *)));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  mngr.get(request); // Отправка get запроса
}

void MainWindow::on_plainTextEdit_textChanged() {}

// void MainWindow::getResponse(QNetworkReply *reply) {
// QByteArray answer=reply->readAll(); // Получение ответа
// ui->plainTextEdit->setPlainText(answer); // Вывод ответа на экран
// qDebug() << "Response received";
// emit sendResponseToAnotherClass(
// reply->readAll()); // Посылаем сигнал, что ответ получен
//}
