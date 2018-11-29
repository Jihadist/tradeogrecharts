#include "bilaxychart.h"

bilaxychart::bilaxychart(QWidget *parent) : QWidget(parent)
{

}

void bilaxychart::json_to_series(QJsonObject &object)
{
    unsigned int diveder=1;
    // here u can provide diveder which u want to use
    const unsigned char coin=7;
    switch (coin)
    {
    case 7:
        // satoshi
        diveder=10e7;
        if (seriesBuy.attachedAxes().empty())
            axisxTitle.append(" (Satoshi)");
        break;
    case 5:
        // mBTC
        diveder=10e5;
        if (seriesBuy.attachedAxes().empty())
            axisxTitle.append(" (mBTC)");
        break;
    case 2:
        // µBTC
        diveder=10e2;
        if (seriesBuy.attachedAxes().empty())
            axisxTitle.append(" (µBTC)");
        break;
    default:
        // btc
        if (seriesBuy.attachedAxes().empty())
            axisxTitle.append(" (BTC)");
        break;

    }
    //qDebug() << "Here is QJsonObject from bilaxychart::json_to_series:" << object;
    if (object.value("bids").isArray())
    {
      auto buyArray = QJsonArray(object.value("bids").toArray());
      qDebug() << "Buy array is transfering from json" << &seriesBuy;
      double *max=new double(buyArray.first().toArray().at(0).toDouble());
      qDebug()<<"First element(max): "<<max;
      delete max;
      qDebug()<<"Last element(min): "<<buyArray.last().toArray().at(0).toDouble();
      qDebug()<<"Counts"<<buyArray.count();
      int counter = 0;
      for (auto array:buyArray)
      {
          // Если элемент массива меньше 5*элемента минимума
          if (array.toArray().at(0).toDouble()>5*buyArray.last().toArray().at(0).toDouble())
          {
            seriesBuy.append(array.toArray().at(0).toDouble()*diveder,array.toArray().at(1).toDouble());
            ++counter;
          }
      }
      qDebug() << "Buy object was transfered from json";
            qDebug()<<"Counts from loop"<<counter;

      seriesBuy.setColor(QColor(70, 166, 86, 255));
      // 70 166 86 for buy
    }
    if (object.value("asks").isArray())
    {
      auto sellArray = QJsonArray(object.value("asks").toArray());
      qDebug() << "Sell array is transfering from json" << &seriesSell;
      double min=sellArray.first().toArray().at(0).toDouble();
      qDebug()<<"First element(min):"<<min;
      qDebug()<<"Last element(max): "<<sellArray.last().toArray().first().toDouble();
      qDebug()<<"Counts"<<sellArray.count();
      int counter = 0; // Счетчик количества элементов

      for (auto array:sellArray)
      {
          // Если элемент массива меньше 20 элемента массива
          if (array.toArray().at(0).toDouble()<sellArray.at(20).toArray().at(0).toDouble()/2)
         {
              //qDebug()<<array.toArray().at(0).toDouble();
             seriesSell.append(array.toArray().at(0).toDouble()*diveder,array.toArray().at(1).toDouble());
            counter++;
          }
      }
      qDebug() << "Sell array was transfered from json";
      qDebug()<<"Counts from loop"<<counter;

      seriesSell.setColor(QColor(255, 0, 0, 255));
      // 255 0 0 for sell
    }
}

bilaxychart *bilaxychart::createChart()
{
    if (chartView.chart()->series().isEmpty()) {
      chartView.chart()->addSeries(
          &seriesSell); // Добавим на график комплект продажи
      chartView.chart()->addSeries(
          &seriesBuy); // Добавим на график комплект покупки
    }
    qDebug() << "Attached axes: " << seriesBuy.attachedAxes().size();
    if (seriesBuy.attachedAxes().empty()) // Если нет прикрепленных осей, то создадим стандартные
    {
        chartView.chart()->createDefaultAxes(); // Создаем оси
        seriesSell.attachedAxes().first()->setTitleText(axisxTitle); // Задает имя по горизонтали
        seriesSell.attachedAxes().back()->setTitleText(axisyTitle); // Задает имя по вертикали

        qDebug() << "Attached axes: " << seriesBuy.attachedAxes().size();
        chartView.chart()->setTitle(mainTitle); // Задает имя графика
    }
    chartView.setRenderHint(QPainter::Antialiasing);
    chartView.resize(820, 600);
    qDebug() << "success";
    return this;
}

int bilaxychart::receiveResponseFromAnotherClass(QNetworkReply * arg)
{

    QJsonDocument document = QJsonDocument(QJsonDocument::fromJson(arg->readAll()));

    //qDebug() <<"Here is QJsonDocument from bilaxychart::receiveResponseFromAnotherClass"<<document;
    QJsonObject root = QJsonObject(document.object());

    qDebug() << root.keys().at(0); // Выводит название первого объекта(покупка)
    qDebug() << root.keys().at(1); // Выводит название второго объекта(продажа)

    auto result = QJsonValue(root.value("code")).toString().toInt();

    qDebug() << result;
    if (result != 200)
      return -1;
    seriesBuy.clear();
    seriesSell.clear();
    auto data=QJsonObject(root.value("data").toObject());
    json_to_series(data);

    createChart();
    qDebug() << "Creating chart was completed";

    if (chartView.isVisible())
      chartView.update();
    else
    {
      seriesBuy.setName("Buy");
      seriesSell.setName("Sell");
      dynamic_cast<QtCharts::QValueAxis *>(chartView.chart()->axisY())->setTickCount(20);
      dynamic_cast<QtCharts::QValueAxis *>(chartView.chart()->axisX())->setTickCount(20);
      chartView.show();
    }
    arg->deleteLater();
    return 1;
}
