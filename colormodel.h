#ifndef COLORMODEL_H
#define COLORMODEL_H

#include <QObject>

class ColorModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)

public:
    explicit ColorModel(QString name,QString color,QObject *parent = nullptr);

    QString name();
    void setName(QString name);
    QString color();
    void setColor(QString color);


signals:
   void nameChanged();
   void colorChanged();

private:
    QString m_name;
    QString m_color;
};

#endif // COLORMODEL_H
