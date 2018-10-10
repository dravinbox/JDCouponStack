#include "user.h"
#include <QtDebug>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonDocument>

/*!
    LoginAPI类
*/

LoginAPI::LoginAPI(){

}

void LoginAPI::requestFinished(QNetworkReply* reply, const QByteArray data, const int statusCode)
{
    if (statusCode == 200) {
        QJsonParseError jsonError;
        QJsonDocument json_doc = QJsonDocument::fromJson(data, &jsonError);
        if(jsonError.error != QJsonParseError::NoError || json_doc.isNull()) {
            qDebug() << "json error";
            return ;
        }
        QJsonObject rootObj = json_doc.object();
        if(rootObj.value("code").toInt()==10000){
            emit loginStatus(true);

        }else{
            emit loginStatus(false);

        }
    }else{
        qDebug() <<"statusCode:" << statusCode << ", data:" << QString(data);
        emit loginStatus(false);

    }
}

/*!
    User类
*/

User::User(QObject *parent) : QObject(parent)
{
    loginApi = new LoginAPI();
    connect(loginApi,SIGNAL(loginStatus(bool)),this,SIGNAL(loginStatus(bool)));

}

QString User::getUserName(){
   qDebug() << "My name is "<<m_username<<endl;
   return m_username;
}

QString User::userName(){
    return this->m_username;
}

void User::setUserName(QString aUserName){
    if(aUserName==this->m_username) {
        return;
    }
    this->m_username = aUserName;
    emit userNameChanged();
}

QString User::password(){
    return m_password;
}

void User::setPassword(QString aPassword){
    if(m_password == aPassword){
        return;
    }
    m_password = aPassword;
    emit passwordChanged();
}

void User::toLogin(){
    QString url = "http://localhost:9090/user/login";
    QString str = QString("phone=%1&password=%2").arg(m_username).arg(m_password);
    QByteArray append_data = str.toUtf8();
//    qDebug() << url << append_data;

    loginApi->post(url,append_data);
//    loginApi->get(url);

}
//void User::loginStatusSlot(bool status){

//}

