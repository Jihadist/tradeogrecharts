#ifndef BILAXYCHART_H
#define BILAXYCHART_H

#include <QWidget>
#include <QtCharts>
#include <QValueAxis>

#include <QNetworkReply>

#include <QJsonArray>
#include <QJsonDocument>

#include <QPair>
class bilaxychart : public QWidget
{
    Q_OBJECT
public:
    explicit bilaxychart(QWidget *parent = nullptr);
    // TrogChart()=default;
    bilaxychart(QtCharts::QChartView *cv, QtCharts::QLineSeries *b,
              QtCharts::QLineSeries *s)
        : chartView(cv), seriesBuy(b), seriesSell(s) {}

    void set_pair(QString primaryCoin = "LTC", QString secondaryCoin = "TRTL") {
      axisxTitle.append(primaryCoin);
      axisyTitle.append(secondaryCoin);
    }
    int array2point(const QByteArray &); // Ненужная функция
    void
    json_to_series(QJsonObject &object); // Перевод из джейсона в линии графика
    bilaxychart *createChart();
private:
    QtCharts::QChartView chartView;   // Графика
    QtCharts::QLineSeries seriesBuy;  // Линия покупки
    QtCharts::QLineSeries seriesSell; // Линия продажи

    QString axisxTitle = "price ";  // Строка цены
    QString axisyTitle = "amount "; // Строка количества
    const QString mainTitle =
        "Bilaxy Orders Chart"; // Строка названия графика
    void chooseDivider(); //

signals:

public slots:
      int receiveResponseFromAnotherClass(QNetworkReply *);
};

#endif // BILAXYCHART_H
