#include "network.h"

Network::Network(QObject *parent) : QObject(parent)
{
    domenList<<"tradeogre.com"<<"api.bilaxy.com";
    qDebug()<<domenList;
    QObject::connect(&manager, &QNetworkAccessManager::finished, this,
            &Network::getResponse);

}

void Network::setUrl(const QString& url)
{

    request.setUrl(QUrl(url));
    qDebug()<<"Url: "<<url;
    auto unusedthing=manager.get(request);
}


void Network::sendRequest()
{

}

 void Network::getResponse(QNetworkReply *reply)
{
    auto statusCode = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );
    if (!statusCode.isValid())
        return;
    auto status = statusCode.toInt();

    if ( status != 200 )
    {
        QString * reason = new QString(reply->attribute( QNetworkRequest::HttpReasonPhraseAttribute ).toString());
        qDebug() <<"Houston, we've had a problem. "<< reason;
        delete reason;
    }
    else
    {
        switch (domenList.indexOf(reply->url().host()))
        {
        case 0: qDebug()<<"Host is tradegore";
            emit responseFromTradeogre(reply);

            break;
        case 1: qDebug()<<"Host is bilaxy";
            emit responseFromBilaxy(reply);
            break;
        default: qDebug()<<"I don't know this host";
            reply->deleteLater();
            break;
        }
    }
}
