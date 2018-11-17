//#include "mainwindow.h"
#include "trogchart.h"
//#include "friend.cpp"


TrogChart::TrogChart(QWidget *parent) : QMainWindow(parent)
{
}

void TrogChart::receiveResponseFromAnotherClass(const QByteArray& arg)
{
    array2point(arg);
    qDebug()<<"Array2point was completed";
    create_chart();
    qDebug()<<"Creating chart was completed";
    chart_view->show();
}

int TrogChart::array2point(const QByteArray& array)
{
    qDebug()<<QString(array);
    auto document=QJsonDocument::fromJson(array);
    qDebug()<<"/n"<<"hello";
    auto root=document.object();
    qDebug()<<root.keys().at(0); // Выводит название первого объекта(покупка)
    qDebug()<<root.keys().at(1); // Выводит название второго объекта(продажа)

    auto result=root.value("success");
    qDebug()<<result.toString();
    if (result=="false")
        return -1;
    if (root.value("buy").isObject())
    {
        auto buy_object=root.value("buy").toObject();
        qDebug()<<"Buy object is transfering from json"<<series_buy;
        json_to_series(buy_object,series_buy);
        qDebug()<<"Buy object was transfered from json";
        series_buy->setColor(QColor(34, 168, 38, 255));
        // 168 34 38 for sell
        // 34 168 38 for buy
    }
    if (root.value("sell").isObject())
    {
        auto sell_object=root.value("sell").toObject();
        qDebug()<<"Sell object is transfering from json";
        json_to_series(sell_object,series_sell);
        qDebug()<<"Sell object was transfered from json";
        series_sell->setColor(QColor(168, 34, 38, 255));
    }
    return 1;
}

TrogChart * TrogChart::create_chart()
{
    //QtCharts::QChart *chart = new QtCharts::QChart();
    //chart_view->chart()->addSeries()
    chart_view->chart()->addSeries(series_sell);
    chart_view->chart()->addSeries(series_buy);
    chart_view->chart()->createDefaultAxes();
    series_sell->attachedAxes().first()->setTitleText(axisX_title);
    series_sell->attachedAxes().back()->setTitleText(axisY_title);

    qDebug()<<"Attached axes: "<<series_buy->attachedAxes();
    //chart->legend()->hide();
    chart_view->chart()->setTitle(main_title);

    chart_view->setRenderHint(QPainter::Antialiasing);
    //chartView->show();
    chart_view->resize(820,600);
    //w.setCentralWidget(chartView);
    //w.resize(820, 600);
    //chart_view->chart()->show();
    qDebug()<<"success";
    return this;
}
