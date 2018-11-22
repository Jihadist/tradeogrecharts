#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

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

#include <QtSql>

namespace Ui {
class MainWindow;
}

class TrogChart;

class MainWindow : public QMainWindow {
  Q_OBJECT
  // void friend json_to_series(QJsonObject &,QtCharts::QLineSeries *);
public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void static json_to_series(QJsonObject &object, QtCharts::QLineSeries *ser);

  QNetworkAccessManager mngr;
  QNetworkRequest request =
      QNetworkRequest(QUrl("https://tradeogre.com/api/v1/orders/LTC-TRTL"));
signals:
  // void sendResponseToAnotherClass(const QByteArray &arg);
public slots:
  void on_pushButton_clicked();

private slots:

  // void getResponse(QNetworkReply *reply);
  void on_plainTextEdit_textChanged();

private:
  Ui::MainWindow *ui;
  // int Document2point(QByteArray, QtCharts::QLineSeries * series_buy,
  // QtCharts::QLineSeries *series_sell);
  // void delete_pointer(QNetworkReply *arg) { arg->deleteLater(); }
  // QtCharts::QChartView * create_xy_chart(QtCharts::QLineSeries * sell,
  // QtCharts::QLineSeries *buy, const QString& x_title, const QString& y_title,
  // const QString& main_title);
};

#endif // MAINWINDOW_H
