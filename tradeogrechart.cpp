#include "tradeogrechart.h"

TradeOgreChart::TradeOgreChart(QWidget *parent) : QWidget(parent) {}

void TradeOgreChart::receiveResponseFromAnotherClass(QNetworkReply *arg) {

  if (array2point(arg->readAll()))
    qDebug() << "Array2point was completed";
  else
    qDebug() << "Something went wrong with TrogChart::array2point";

  createChart();
  qDebug() << "Creating chart was completed";

  if (chartView.isVisible())
    chartView.update();
  else
  {
   chartView.show();
   seriesBuy.setName("Buy");
   seriesSell.setName("Sell");
   // Установка сетки
   dynamic_cast<QtCharts::QValueAxis *>(chartView.chart()->axisY())->setTickCount(20);
   dynamic_cast<QtCharts::QValueAxis *>(chartView.chart()->axisX())->setTickCount(20);

  }
  arg->deleteLater();

}

/*int TradeOgreChart::receiveJsonFromAnotherClass(QJsonDocument document)
{
    qDebug() <<"Here is QJsonDocument from array2point"<<document;
    QJsonObject root = QJsonObject(document.object());

    qDebug() << root.keys().at(0); // Выводит название первого объекта(покупка)
    qDebug() << root.keys().at(1); // Выводит название второго объекта(продажа)

    QJsonValue result = QJsonValue(root.value("success"));

    qDebug() << result.toString();
    if (result == "false")
      return -1;
    seriesBuy.clear();
    seriesSell.clear();
    jsonToSeries(root);
    createChart();
    qDebug() << "Creating chart was completed";

    if (chartView.isVisible())
      chartView.update();
    else
      //chart_view.show();// Disable for debug!!!!!!!!!!!!!!!!
    return 1;

}*/

int TradeOgreChart::array2point(const QByteArray &array) {
  //qDebug() << QString(array);
  QJsonDocument document = QJsonDocument(QJsonDocument::fromJson(array));

  //qDebug() <<"Here is QJsonDocument from array2point"<<document;
  QJsonObject root = QJsonObject(document.object());

  qDebug() << root.keys().at(0); // Выводит название первого объекта(покупка)
  qDebug() << root.keys().at(1); // Выводит название второго объекта(продажа)

  QJsonValue result = QJsonValue(root.value("success"));

  qDebug() << result.toString();
  if (result == "false")
    return -1;
  seriesBuy.clear();
  seriesSell.clear();
  jsonToSeries(root);
  return 1;
}

TradeOgreChart *TradeOgreChart::createChart() {
  //qDebug() << chart_view.chart()->series().count();
  if (chartView.chart()->series().isEmpty())
  {
    chartView.chart()->addSeries(&seriesSell); // Добавим на график комплект продажи
    chartView.chart()->addSeries( &seriesBuy); // Добавим на график комплект покупки
  }
  qDebug() << "Attached axes: " << seriesBuy.attachedAxes().size();
  if (seriesBuy.attachedAxes().empty()) // Если нет прикрепленных осей, то создадим стандартные
    chartView.chart()->createDefaultAxes();
  seriesSell.attachedAxes().first()->setTitleText(axisxTitle); // Задает имя по горизонтали
  seriesSell.attachedAxes().back()->setTitleText(axisyTitle); // Задает имя по вертикали


  qDebug() << "Attached axes: " << seriesBuy.attachedAxes().size();
  chartView.chart()->setTitle(mainTitle); // Задает имя графика

  chartView.setRenderHint(QPainter::Antialiasing);
  chartView.resize(820, 600);
  qDebug() << "success";
  return this;
}

void TradeOgreChart::jsonToSeries(QJsonObject &object) {
    unsigned int diveder=1;
    // here u can provide diveder which u want to use
    const unsigned char coin=7;
    switch (coin)
    {
    case 7:
        // Litoshi
        diveder=10e7;
        if (seriesBuy.attachedAxes().empty())
            axisxTitle.append(" (Litoshi)");
        break;
    case 5:
        // mLTC
        diveder=10e5;
        if (seriesBuy.attachedAxes().empty())
            axisxTitle.append(" (mLTC)");
        break;
    case 2:
        // µLTC
        diveder=10e2;
        if (seriesBuy.attachedAxes().empty())
            axisxTitle.append(" (µLTC)");
        break;
    default:
        // LTC
        if (seriesBuy.attachedAxes().empty())
            axisxTitle.append(" (LTC)");
        break;
    }
    // Если есть объект Покупка
  if (object.value("buy").isObject()) {
      // Создаем новый объект
    QJsonObject buy_object = QJsonObject(object.value("buy").toObject());
    qDebug() << "Buy object is transfering from json" << &seriesBuy;
    // Создаем итератор на первый элемент этого объекта
    QJsonObject::Iterator iter = QJsonObject::Iterator(buy_object.begin());
    // Пока не дойдем до последнего элемента объекта
    while (iter != buy_object.end()) {
      // qDebug() << iter.key().toDouble() <<
      // iter.value().toString().toDouble();
        // Вставляем в набор Покупка элемент Цена и элемент Количество
      seriesBuy.append(iter.key().toDouble()*diveder,
                        iter.value().toString().toDouble());
      ++iter;
    }
    qDebug() << "Buy object was transfered from json";
    // Устанавливаем цвет
    seriesBuy.setColor(QColor(34, 168, 38, 255));
    // 34 168 38 for buy
  }
  // Если есть объект продажа
  if (object.value("sell").isObject()) {
      // Создаем новый объект, извлекая из общего
    auto sell_object = object.value("sell").toObject();
    qDebug() << "Sell object is transfering from json";
    // Создаем указатель на первый элемент этого объекта
    auto iter = sell_object.begin();
    // Пока не дойдем до конца объекта
    while (iter != sell_object.end()) {
      // qDebug() << iter.key().toDouble() <<
      // iter.value().toString().toDouble();
        // Вставляем в набор Продажа элемент Цена и элемент Количество
      seriesSell.append(iter.key().toDouble()*diveder,
                         iter.value().toString().toDouble());
      //qDebug() << "appended";
      ++iter;
    }
    qDebug() << "Sell object was transfered from json";
    // Устанавливаем цвет для набора Продажа
    seriesSell.setColor(QColor(168, 34, 38, 255));
    // 168 34 38 for sell
  }
}

void TradeOgreChart::clear() {}
