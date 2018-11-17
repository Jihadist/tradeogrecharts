#include "mainwindow.h"
#include "trogchart.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QNetworkRequest request(QUrl("https://tradeogre.com/api/v1/orders/LTC-TRTL"));
    QNetworkAccessManager *mngr = new QNetworkAccessManager(this);
    connect(mngr, SIGNAL(finished(QNetworkReply*)),this, SLOT(getResponse(QNetworkReply*)));
    mngr->get(request);
}

void MainWindow::on_plainTextEdit_textChanged()
{
}


void MainWindow::getResponse(QNetworkReply *reply)
{
    QByteArray answer=reply->readAll();
    ui->plainTextEdit->setPlainText(answer);
    qDebug()<<"Response received";
    emit sendResponseToAnotherClass(answer);

//    QtCharts::QLineSeries *points_for_sell = new QtCharts::QLineSeries();
//    QtCharts::QLineSeries *points_for_buy = new QtCharts::QLineSeries();
//    Document2point(answer,points_for_buy,points_for_sell);


//    QtCharts::QChartView *xy_chart_view=new QtCharts::QChartView();
//    xy_chart_view=create_xy_chart(points_for_sell,points_for_buy,"Price LTC","amount TRTL","Tradeogre Orders Chart");
//    xy_chart_view->show();
    //qDebug() << answer;
}


