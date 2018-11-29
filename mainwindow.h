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
    friend class Network;
public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void static json_to_series(QJsonObject &object, QtCharts::QLineSeries *ser);

  QNetworkAccessManager mngr;
  QNetworkRequest request;



signals:
  void onComboboxCurrentTextchanged(const QString &);

public slots:
  void on_pushButton_clicked();
  void receiveJsonToMarkets(QStringList &);

private slots:


  void on_plainTextEdit_textChanged();

  void on_comboBox_currentTextChanged(const QString &arg1);

private:
  Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
