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

#include "network.h"

namespace Ui {
class MainWindow;
}

class TradeOgreChart;

class MainWindow : public QMainWindow {
  Q_OBJECT
  // void friend json_to_series(QJsonObject &,QtCharts::QLineSeries *);
    friend class Network;
public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void static json_to_series(QJsonObject &object, QtCharts::QLineSeries *ser);

  QNetworkAccessManager mngr;
  QNetworkRequest request;



signals:
  // void sendResponseToAnotherClass(const QByteArray &arg);
public slots:
  void on_pushButton_clicked();

private slots:

  // void getResponse(QNetworkReply *reply);
  //friend void Network::getResponse(QNetworkReply *reply);
  //friend void Network::setUrl(const QString& url);
  void on_plainTextEdit_textChanged();

private:
  Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
