#include "mainwindow.h"
#include "trogchart.h"


void json_to_series(QJsonObject & object,QtCharts::QLineSeries * ser)
{
    qDebug()<<"Object:"<<object;
    auto iter=object.begin();
    qDebug()<<&iter<<iter.value();
    while(iter!=object.end())
    {
        qDebug()<<iter.key().toDouble()<<iter.value().toString().toDouble();
        ser->append(iter.key().toDouble(),iter.value().toString().toDouble());
        //qDebug()<<iter.key();
        //qDebug()<<QString::number(iter.value().toString().toDouble(),'f',8);
        ++iter;
    }
}
