#include "baseapi.h"
#include <QUrl>


BaseAPI::BaseAPI()
{
//    httpRequest.setRawHeader("Accept", "*/*");
//    httpRequest.setRawHeader("User-Agent", "");
//    httpRequest.setRawHeader("X-XXX-API-Key", "");
//    httpRequest.setRawHeader("X-XXX-API-Secret", "");
//    httpRequest.setRawHeader("Accept-Encoding", "gzip, deflate");
    httpRequest.setRawHeader("Content-Type", "application/x-www-form-urlencoded");

//    settings = new QSettings();
//    settings->beginGroup("userInfo");
//    QString id = settings->value("user_id", "").toString();
//    QString token = settings->value("token", "").toString();
//    settings->endGroup();

//    if(!id.isEmpty()) {
//        httpRequest.setRawHeader("X-XXX-User-ID", id.toStdString().c_str());
//    }

//    if (!token.isEmpty()) {
//        httpRequest.setRawHeader("X-XXX-User-Token", token.toStdString().c_str());
//    }

//    qDebug() << "BaseAPI...id:" << id << " token:" + token;

    QObject::connect(&networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(serviceRequestFinished(QNetworkReply*)));
}

BaseAPI::~BaseAPI()
{
    networkAccessManager.disconnect();
    if (settings){
        delete settings;
        settings = nullptr;
    }
}

void BaseAPI::get(const QString url)
{
    httpRequest.setUrl(QUrl(url));
    networkAccessManager.get(httpRequest);
}

void BaseAPI::post(const QString url, const QByteArray &data)
{
    httpRequest.setUrl(QUrl(url));
    networkAccessManager.post(httpRequest, data);
    qDebug()<<"hello";
}

void BaseAPI::serviceRequestFinished(QNetworkReply *reply)
{
    qDebug()<<"hi";
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    qDebug() << "BaseAPI...serviceRequestFinished...statusCode:" << statusCode;

    if(reply->error() == QNetworkReply::NoError) {
        requestFinished(reply, reply->readAll(), statusCode);
    } else {
        requestFinished(reply, "", statusCode);
    }

    // At the end of that slot, we won't need it anymore
    reply->deleteLater();
}
