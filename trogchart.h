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
   // TrogChart()=default;
    TrogChart(QtCharts::QChartView * cv,QtCharts::QLineSeries * b, QtCharts::QLineSeries * s):
        chart_view(cv),series_buy(b),series_sell(s){}

    void set_pair(QString primary_coin="LTC",QString secondary_coin="TRTL")
    {
        axisX_title.append(primary_coin);
        axisY_title.append(secondary_coin);
    }
    int array2point(const QByteArray&); //
    void json_to_series(QJsonObject & object); // Перевод из джейсона в линии графика
    void clear();
    TrogChart *create_chart();

private:
    QtCharts::QChartView  chart_view; // Графика
    QtCharts::QLineSeries  series_buy; // Линия покупки
    QtCharts::QLineSeries  series_sell; // Линия продажи

    QString axisX_title="price "; // Строка цены
    QString axisY_title="amount "; // Строка количества
    const QString main_title="Tradeogre Orders Chart"; // Строка названия графика
signals:

public slots:
    void receiveResponseFromAnotherClass(const QByteArray&);
};

#endif // TROGCHART_H
