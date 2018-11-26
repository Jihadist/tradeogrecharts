#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSslError>
#include <QUrl>

#include <QJsonDocument>



class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = nullptr);
    void setUrl(const QString&);
    QNetworkAccessManager manager;
    QNetworkRequest request;
private:
    QStringList domenList;

signals:
    void responseFromTradeogre(QNetworkReply *reply);
    void responseFromBilaxy(QNetworkReply *reply);
    //void jsonFromTradeogre(QJsonDocument);

public slots:
    void getResponse(QNetworkReply *reply);
    void sendRequest();
};

#endif // NETWORK_H
