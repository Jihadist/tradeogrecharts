#ifndef TROGCHART_H
#define TROGCHART_H

#include <QMainWindow>
#include <QApplication>
#include <QChartView>
#include <QLineSeries>
#include <QDateTime>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QPen>
#include <QColor>
#include <QMargins>

#include <QTextCodec>
#include <QTextStream>
#include <QString>
#include <QByteArray>

#include <QProgressDialog>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QDebug>

//#include "mainwindow.h"


class TrogChart : public QMainWindow
{
    Q_OBJECT
    friend void json_to_series(QJsonObject &,QtCharts::QLineSeries *);
public:
    explicit TrogChart(QWidget *parent = nullptr);
    TrogChart()=default;
    TrogChart(QtCharts::QChartView * cv,QtCharts::QLineSeries * b, QtCharts::QLineSeries * s):
        chart_view(cv),series_buy(b),series_sell(s){}
    //TrogChart(QtCharts::QChartView * cv):chart_view(cv){}
    //TrogChart(QtCharts::QChart *c):chart(c){}
    void set_pair(QString primary_coin="LTC",QString secondary_coin="TRTL")
    {
        axisX_title.append(primary_coin);
        axisY_title.append(secondary_coin);
    }
    int array2point(const QByteArray&);

    TrogChart *create_chart();

private:
    //QtCharts::QChart * chart;//=new QtCharts::QChart;
    QtCharts::QChartView * chart_view=new QtCharts::QChartView;
    QtCharts::QLineSeries * series_buy=new QtCharts::QLineSeries;
    QtCharts::QLineSeries * series_sell=new QtCharts::QLineSeries;

    QString axisX_title="price ";
    QString axisY_title="amount ";
    QString main_title="Tradeogre Orders Chart";
signals:

public slots:
    void receiveResponseFromAnotherClass(const QByteArray&);
};

#endif // TROGCHART_H
