#include "mainwindow.h"
//#include "friend.cpp"

//void json_to_series(QJsonObject &,QtCharts::QLineSeries *);

int MainWindow::Document2point(QByteArray array, QtCharts::QLineSeries * series_buy, QtCharts::QLineSeries * series_sell)
{
    //QByteArray array;
    //QFile file(R"(C:\..\Debug\LTC-TRTL_25684798.txt)");
    //QtCharts::QChart * xy;

    //QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    //QLineSeries *amount = new QLineSeries();

    //if (file.open(QIODevice::ReadOnly))
    //{
    //    array=file.readAll();
    //    file.close();
   // }
    qDebug()<<QString(array);
    QJsonDocument document=QJsonDocument::fromJson(array);
    qDebug()<<"/n"<<"hello";
    QJsonObject root=document.object();
    qDebug()<<root.keys().at(0); // Выводит название первого объекта(покупка)
    qDebug()<<root.keys().at(1); // Выводит название второго объекта(продажа)

    QJsonValue result=root.value("success");
    qDebug()<<result.toString();
    if (result=="false")
        return -1;
    if (root.value("buy").isObject())
    {
        QJsonObject buy_object=root.value("buy").toObject();
        json_to_series(buy_object,series_buy);
        series_buy->setColor(QColor(34, 168, 38, 255));
        // 168 34 38 for sell
        // 34 168 38 for buy
    }
    if (root.value("sell").isObject())
    {
        QJsonObject sell_object=root.value("sell").toObject();
        json_to_series(sell_object,series_sell);
        series_sell->setColor(QColor(168, 34, 38, 255));
    }
    return 1;

}







