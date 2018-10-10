#ifndef USER_H
#define USER_H

#include <QObject>
#include "baseapi.h"

class LoginAPI : public BaseAPI
{
    Q_OBJECT

public:
    LoginAPI();
signals:
    void loginStatus(bool);
protected:
    void requestFinished(QNetworkReply *reply, const QByteArray data, const int statusCode);

};


class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
public:
    explicit User(QObject *parent = nullptr);
    Q_INVOKABLE QString getUserName();
    Q_INVOKABLE void toLogin();

signals:
    void userNameChanged();
    void passwordChanged();
    void loginStatus(bool status);

public slots:
    QString userName();
    void setUserName(QString aUserName);
    QString password();
    void setPassword(QString aPassword);
//    void loginStatusSlot(bool status);
private:
    QString m_username;
    QString m_password;
    LoginAPI *loginApi;
};

#endif // USER_H
