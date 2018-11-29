#include "mainwindow.h"
//#include "tradeogrechart.h"
#include "ui_mainwindow.h"
#include "network.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);

  request=QNetworkRequest(QUrl("https://tradeogre.com/api/v1/markets"));
  auto test = mngr.get(request); // Отправка get запроса
  connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::onComboboxCurrentTextchanged);
}

MainWindow::~MainWindow() { delete ui; }


void MainWindow::on_pushButton_clicked() {

  request=QNetworkRequest(QUrl("https://tradeogre.com/api/v1/orders/LTC-TRTL"));
  auto test1 = mngr.get(request); // Отправка get запроса
  request=QNetworkRequest(QUrl("https://api.bilaxy.com/v1/depth?symbol=117"));
  auto test2=mngr.get(request);




}

void MainWindow::receiveJsonToMarkets(QStringList &markets)
{
 ui->comboBox->addItems(markets);
}

void MainWindow::on_plainTextEdit_textChanged() {}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    qDebug()<<arg1;
    //emit onComboboxCurrentTextchanged(arg1);
}
