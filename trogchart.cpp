#include "trogchart.h"

TrogChart::TrogChart(QWidget *parent) : QMainWindow(parent)
{
}

void TrogChart::receiveResponseFromAnotherClass(const QByteArray& arg)
{

    chart_view.repaint(); //

    if (array2point(arg)) //
        qDebug()<<"Array2point was completed";
    else
        qDebug()<<"Something went wrong with TrogChart::array2point";
    create_chart();
    qDebug()<<"Creating chart was completed";
    chart_view.show();
}

int TrogChart::array2point(const QByteArray& array)
{
    qDebug()<<QString(array);
    QJsonDocument * document=new QJsonDocument(QJsonDocument::fromJson(array));

    qDebug()<<"/n"<<"hello";
    QJsonObject * root=new QJsonObject(document->object());

    qDebug()<<root->keys().at(0); // Выводит название первого объекта(покупка)
    qDebug()<<root->keys().at(1); // Выводит название второго объекта(продажа)

    QJsonValue * result=new QJsonValue(root->value("success"));

    qDebug()<<result->toString();
    if (*result=="false")
        return -1;
    series_buy.clear();
    series_sell.clear();
    json_to_series(*root);

    delete document;
    delete result;
    delete root;
    return 1;
}

TrogChart * TrogChart::create_chart()
{
    chart_view.chart()->addSeries(&series_sell); // Добавим на график комплект продажи
    chart_view.chart()->addSeries(&series_buy); // Добавим на график комплект покупки
    qDebug()<<"Attached axes: "<<series_buy.attachedAxes().size();
    if (series_buy.attachedAxes().empty()) // Если нет прикрепленных осей, то создадим стандартные
        chart_view.chart()->createDefaultAxes();
    series_sell.attachedAxes().first()->setTitleText(axisX_title); // Задает имя по горизонтали
    series_sell.attachedAxes().back()->setTitleText(axisY_title); // Задает имя по вертикали

    qDebug()<<"Attached axes: "<<series_buy.attachedAxes().size();
    chart_view.chart()->setTitle(main_title); // Задает имя графика

    chart_view.setRenderHint(QPainter::Antialiasing);
    chart_view.resize(820,600);
    qDebug()<<"success";
    return this;
}

void TrogChart::json_to_series(QJsonObject & object)
{
    qDebug()<<"Object:"<<object;
    if (object.value("buy").isObject())
    {
        QJsonObject * buy_object=new QJsonObject(object.value("buy").toObject());
        qDebug()<<"Buy object is transfering from json"<<&series_buy;
        QJsonObject::Iterator * iter=new QJsonObject::Iterator(buy_object->begin());
        while(*iter!=buy_object->end())
        {
            qDebug()<<iter->key().toDouble()<<iter->value().toString().toDouble();
            series_buy.append(iter->key().toDouble(),iter->value().toString().toDouble());
            ++*iter;
        }
        qDebug()<<"Buy object was transfered from json";
        series_buy.setColor(QColor(34, 168, 38, 255));
        // 34 168 38 for buy
        delete buy_object;
        delete iter;
    }
    if (object.value("sell").isObject())
    {
        auto sell_object=object.value("sell").toObject();
        qDebug()<<"Sell object is transfering from json";
        auto iter=sell_object.begin();
        while(iter!=sell_object.end())
        {
            qDebug()<<iter.key().toDouble()<<iter.value().toString().toDouble();
            series_sell.append(iter.key().toDouble(),iter.value().toString().toDouble());
            qDebug()<<"appended";
            ++iter;
        }
        //json_to_series(sell_object,series_sell);
        qDebug()<<"Sell object was transfered from json";
        series_sell.setColor(QColor(168, 34, 38, 255));
        // 168 34 38 for sell
    }

}

void TrogChart::clear()
{

}
