#ifndef TROGCHART_H
#define TROGCHART_H

#include <QApplication>
#include <QChartView>
#include <QColor>
#include <QDateTime>
#include <QDateTimeAxis>
#include <QLineSeries>
#include <QMainWindow>
#include <QMargins>
#include <QPen>
#include <QValueAxis>

#include <QByteArray>
#include <QString>
#include <QTextCodec>
#include <QTextStream>

#include <QProgressDialog>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <QDebug>
#include <QNetworkReply>

//#include "mainwindow.h"

class TrogChart : public QMainWindow {
  Q_OBJECT
  friend void json_to_series(QJsonObject &, QtCharts::QLineSeries *);

public:
  explicit TrogChart(QWidget *parent = nullptr);
  // TrogChart()=default;
  TrogChart(QtCharts::QChartView *cv, QtCharts::QLineSeries *b,
            QtCharts::QLineSeries *s)
      : chart_view(cv), series_buy(b), series_sell(s) {}

  void set_pair(QString primary_coin = "LTC", QString secondary_coin = "TRTL") {
    axisX_title.append(primary_coin);
    axisY_title.append(secondary_coin);
  }
  int array2point(const QByteArray &); // Ненужная функция
  void
  json_to_series(QJsonObject &object); // Перевод из джейсона в линии графика
  void clear();
  TrogChart *create_chart();

private:
  QtCharts::QChartView chart_view;   // Графика
  QtCharts::QLineSeries series_buy;  // Линия покупки
  QtCharts::QLineSeries series_sell; // Линия продажи

  QString axisX_title = "price ";  // Строка цены
  QString axisY_title = "amount "; // Строка количества
  const QString main_title =
      "Tradeogre Orders Chart"; // Строка названия графика
signals:

public slots:
  void receiveResponseFromAnotherClass(QNetworkReply *);
};

#endif // TROGCHART_H
