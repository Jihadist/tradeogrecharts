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

class TradeOgreChart : public QWidget {
  Q_OBJECT

public:
  explicit TradeOgreChart(QWidget *parent = nullptr);
  // TrogChart()=default;
  TradeOgreChart(QtCharts::QChartView *cv, QtCharts::QLineSeries *b,
            QtCharts::QLineSeries *s)
      : chartView(cv), seriesBuy(b), seriesSell(s) {}

  void setPair(QString primary_coin = "LTC", QString secondary_coin = "TRTL") {
    axisxTitle.append(primary_coin);
    axisyTitle.append(secondary_coin);
  }
  int array2point(const QByteArray &); // Ненужная функция
  void
  jsonToSeries(QJsonObject &object); // Перевод из джейсона в линии графика
  void clear();
  TradeOgreChart *createChart();

private:
  QtCharts::QChartView chartView;   // Графика
  QtCharts::QLineSeries seriesBuy;  // Линия покупки
  QtCharts::QLineSeries seriesSell; // Линия продажи

  QString axisxTitle = "price ";  // Строка цены
  QString axisyTitle = "amount "; // Строка количества
  const QString mainTitle =
      "Tradeogre Orders Chart"; // Строка названия графика
signals:

public slots:
  void receiveResponseFromAnotherClass(QNetworkReply *);
  //int receiveJsonFromAnotherClass(QJsonDocument);
};

#endif // TROGCHART_H
