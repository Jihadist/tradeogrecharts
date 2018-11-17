#include "mainwindow.h"

QtCharts::QChartView *  MainWindow::create_xy_chart(QtCharts::QLineSeries * sell,QtCharts::QLineSeries * buy, const QString& x_title, const QString& y_title, const QString& main_title)
{
        QtCharts::QChart *chart = new QtCharts::QChart();

        chart->addSeries(sell);
        chart->addSeries(buy);
        chart->createDefaultAxes();
        sell->attachedAxes().first()->setTitleText(x_title);

        sell->attachedAxes().back()->setTitleText(y_title);

        /*qDebug()<<*/
        qDebug()<<buy->attachedAxes();
        //chart->legend()->hide();
        chart->setTitle(main_title);

        qDebug()<<"counter"<<sell->count();


        //QMargins margins=chart->margins();
        // Установка левого края из минимального значения цены покупки
        //margins.setLeft(buy->at(0).x());
        // Выводим это значение
        qDebug()<<buy->at(0).x();
        // Установка правого края из максимального значения цены продажи
        //margins.setRight(sell->at(sell->count()-1).x());
        // Выводим это значение
        qDebug()<<sell->at(sell->count()-1).x();
        // Устанавливаем края для графика
         //chart->setMargins(margins);



        //QSharedPointer<QtCharts::QChartView> chart_view;
        QtCharts::QChartView *chart_view = new QtCharts::QChartView(chart);
        chart_view->setRenderHint(QPainter::Antialiasing);
        //chartView->show();
        chart_view->resize(820,600);
        //w.setCentralWidget(chartView);
        //w.resize(820, 600);

        qDebug()<<"success";
        return chart_view;
}
