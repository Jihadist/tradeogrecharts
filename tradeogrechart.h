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

  void JsonToMarkets(QJsonDocument &);
signals:
  void JsonToMarketsWasCompleted(QStringList &);
public slots:
  int receiveResponseFromAnotherClass(QNetworkReply *);
  //int receiveJsonFromAnotherClass(QJsonDocument);
  void setPair(QString pair="LTC-TRTL");
};

#endif // TROGCHART_H
