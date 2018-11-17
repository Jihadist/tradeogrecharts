#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>

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

#include <QtSql>


namespace Ui {
class MainWindow;
}

class TrogChart;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    void friend json_to_series(QJsonObject &,QtCharts::QLineSeries *);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendResponseToAnotherClass(const QByteArray& arg);
public slots:

private slots:
    void on_pushButton_clicked();
    void getResponse(QNetworkReply *reply);
    void on_plainTextEdit_textChanged();


private:
    Ui::MainWindow *ui;
    int Document2point(QByteArray, QtCharts::QLineSeries * series_buy, QtCharts::QLineSeries *series_sell);

    QtCharts::QChartView * create_xy_chart(QtCharts::QLineSeries * sell, QtCharts::QLineSeries *buy, const QString& x_title, const QString& y_title, const QString& main_title);


};

#endif // MAINWINDOW_H
